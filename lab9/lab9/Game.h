#pragma once

#include "Character.h"
#include "Monster.h"
#include <memory>
#include <vector>
#include <map>
#include "Inventory.h"

class Game {
private:
    Character player;
    std::vector<std::unique_ptr<Monster>> monsters;
    void fight(Monster& monster);
    std::map<std::string, int> monsterDefeatCount;
    Inventory inventory;

public:
    Game(const std::string& playerName);
    void start();
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);
    void showMonsterMenu();
    void chooseAndFight();
    Item getRandomItem();

};

