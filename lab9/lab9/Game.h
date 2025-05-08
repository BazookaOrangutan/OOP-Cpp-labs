#pragma once

#include "Character.h"
#include "Monster.h"
#include <memory>
#include <vector>

class Game {
private:
    Character player;
    std::vector<std::unique_ptr<Monster>> monsters;
    void fight(Monster& monster);

public:
    Game(const std::string& playerName);
    void start();
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);
};

