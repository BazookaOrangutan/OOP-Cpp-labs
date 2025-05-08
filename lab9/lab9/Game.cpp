#include "Game.h"
#include "Goblin.h"
#include "Dragon.h"
#include "Skeleton.h"
#include "Logger.h"
#include <fstream>
#include <iostream>

Game::Game(const std::string& playerName) : player(playerName) {}

void Game::start() {
    monsters.push_back(std::make_unique<Goblin>());
    monsters.push_back(std::make_unique<Dragon>());
    monsters.push_back(std::make_unique<Skeleton>());

    for (auto& monster : monsters) {
        try {
            fight(*monster);
        }
        catch (const std::exception& e) {
            std::cout << "Battle ended: " << e.what() << "\n";
            break;
        }
    }
}

void Game::fight(Monster& monster) {
    std::cout << "A wild " << monster.getName() << " appears!\n";
    while (player.getHP() > 0 && monster.getHP() > 0) {
        player.attack(monster);
        monster.attack(player);
        Logger<std::string>::log("Fight with " + monster.getName());
    }
    player.gainExperience(50);
}

void Game::saveGame(const std::string& filename) {
    std::ofstream out(filename);
    if (out) {
        out << "Game save not implemented in detail.\n";
    }
}

void Game::loadGame(const std::string& filename) {
    std::ifstream in(filename);
    if (in) {
        std::string line;
        while (std::getline(in, line)) {
            std::cout << "Loaded: " << line << "\n";
        }
    }
}
