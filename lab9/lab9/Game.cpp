#include "Game.h"
#include "Goblin.h"
#include "Dragon.h"
#include "Skeleton.h"
#include "Logger.h"
#include <fstream>
#include <iostream>
#include <sstream>


Game::Game(const std::string& playerName) : player(playerName) {

}

void Game::start() {
    loadGame("save.txt");
    chooseAndFight();
    saveGame("save.txt");

}

void Game::showMonsterMenu() {
    std::cout << "\nChoose a monster to fight:\n";
    for (size_t i = 0; i < monsters.size(); ++i) {
        std::cout << i + 1 << ". " << monsters[i]->getName() << " (HP: " << monsters[i]->getHP()
            << ", ATK: " << monsters[i]->getAttack() << ", DEF: " << monsters[i]->getDefense() << ")\n";
    }
    std::cout << "0. Exit\n";
    std::cout << "Your stats: HP=" << player.getHP()
        << ", ATK=" << player.getAttack()
        << ", DEF=" << player.getDefense()
        << ", LVL=" << player.getLevel() << "\n";
}


void Game::chooseAndFight() {
    int choice;
    while (true) {
        saveGame("save.txt");
        showMonsterMenu();
        std::cin >> choice;
        if (choice == 0) break;
        if (choice < 1 || choice > static_cast<int>(monsters.size())) {
            std::cout << "Invalid choice.\n";
            continue;
        }
        Monster& selected = *monsters[choice - 1];
        try {
            fight(selected);
            if (selected.getHP() <= 0) {
                monsterDefeatCount[selected.getName()]++;
                int boost = monsterDefeatCount[selected.getName()];
                Logger<std::string>::log(selected.getName() + " has been replaced with a stronger version!");
                monsters[choice - 1] = selected.clone(boost);
            }
        }
        catch (const std::exception& e) {
            std::cout << "Battle ended: " << e.what() << "\n";
            if (player.getHP() <= 0) {

                std::ofstream saveOut("save.txt");
                if (saveOut) {
                    Character fresh = Character::getDefaultCharacter(player.getName());
                    saveOut << fresh.getName() << " "
                        << fresh.getHP() << " "
                        << fresh.getAttack() << " "
                        << fresh.getDefense() << " "
                        << fresh.getLevel() << " "
                        << fresh.getExperience() << "\n";
                }
                std::ofstream monsterOut("monster_data.txt");
                if (monsterOut) {
                    for (const auto& monster : monsters) {
                        monsterOut << monster->getName() << " " << 0 << "\n";
                    }
                }

                throw std::runtime_error(e.what());
            }
            if (selected.getHP() <= 0) {
                monsterDefeatCount[selected.getName()]++;
                int boost = monsterDefeatCount[selected.getName()];
                Logger<std::string>::log(selected.getName() + " has been replaced with a stronger version!");
                monsters[choice - 1] = selected.clone(boost);
                if (rand() % 2 == 0) {
                    Item drop = getRandomItem();
                    inventory.addItem(drop);
                    Logger<std::string>::log("Item dropped: " + drop.getName());
                    inventory.applyItemEffects(player);
                }
                
            }

        }
        player.gainExperience(50);
    }
}

void Game::fight(Monster& monster) {
    std::cout << "\nA wild " << monster.getName() << " appears!\n";
    while (player.getHP() > 0 && monster.getHP() > 0) {
        int preHP = monster.getHP();
        player.attack(monster);
        int damageToMonster = preHP - monster.getHP();

        Logger<std::string>::log(player.getName() + " hits " + monster.getName() +
            " for " + std::to_string(damageToMonster) + " damage");

        if (monster.getHP() <= 0) {
            Logger<std::string>::log(monster.getName() + " has been defeated by " + player.getName());

            if (rand() % 2 == 0) {
                Item drop = getRandomItem();
                inventory.addItem(drop);
                Logger<std::string>::log("Item dropped: " + drop.getName());
                inventory.applyItemEffects(player);
            }
            
            break;
        }

        preHP = player.getHP();
        monster.attack(player);
        int damageToPlayer = preHP - player.getHP();

        Logger<std::string>::log(monster.getName() + " hits " + player.getName() +
            " for " + std::to_string(damageToPlayer) + " damage");

        if (player.getHP() <= 0) {
            Logger<std::string>::log(player.getName() + " was defeated by " + monster.getName());
            std::ofstream saveOut("save.txt");
            if (saveOut) {
                Character fresh = Character::getDefaultCharacter(player.getName());
                saveOut << fresh.getName() << " "
                    << fresh.getHP() << " "
                    << fresh.getAttack() << " "
                    << fresh.getDefense() << " "
                    << fresh.getLevel() << " "
                    << fresh.getExperience() << "\n";
            }
            std::ofstream monsterOut("monster_data.txt");
            if (monsterOut) {
                for (const auto& monster : monsters) {
                    monsterOut << monster->getName() << " " << 0 << "\n";
                }
            }

            throw std::runtime_error("You died!");
        }
    }
}


void Game::saveGame(const std::string& filename) {
    std::ofstream out(filename);
    if (out) {
        out << player.getName() << " "
            << player.getHP() << " "
            << player.getAttack() << " "
            << player.getDefense() << " "
            << player.getLevel() << " "
            << player.getExperience() << "\n";
        inventory.save(out);
    }

    std::ofstream monsterOut("monster_data.txt");
    if (monsterOut) {
        for (const auto& monster : monsters) {
            monsterOut << monster->getName() << " " << monsterDefeatCount[monster->getName()] << "\n";
        }
    }
}

void Game::loadGame(const std::string& filename) {
    std::ifstream in(filename);
    if (in) {
        std::string name;
        int hp, attack, defense, level, exp;
        in >> name >> hp >> attack >> defense >> level >> exp;
        player = Character(name, hp, attack, defense, level, exp);
        inventory.load(in);
        std::cout << "Game loaded for " << name << " (HP: " << hp << ", Level: " << level << ")\n";
    }
    else {
        std::cout << "No save found. Starting new game.\n";
        saveGame(filename);
    }

    std::ifstream monsterIn("monster_data.txt");
    if (monsterIn) {
        monsters.clear();  

        std::string mname;
        int level;
        while (monsterIn >> mname >> level) {
            monsterDefeatCount[mname] = level;
            if (mname == "Goblin") {
                monsters.push_back(Goblin().clone(level));
            }
            else if (mname == "Dragon") {
                monsters.push_back(Dragon().clone(level));
            }
            else if (mname == "Skeleton") {
                monsters.push_back(Skeleton().clone(level));
            }
        }
    }
    else {
        monsters.push_back(std::make_unique<Goblin>());
        monsters.push_back(std::make_unique<Dragon>());
        monsters.push_back(std::make_unique<Skeleton>());
    }
}

Item Game::getRandomItem() {
    int roll = rand() % 3;
    switch (roll) {
    case 0: return Item("Potion", ItemType::HP, 20);
    case 1: return Item("Sword", ItemType::ATK, 5);
    case 2: return Item("Shield", ItemType::DEF, 5);
    }
    return Item("Unknown", ItemType::HP, 0);
}
