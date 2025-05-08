#include "Game.h"
#include <iostream>

int main() {
    Game game("Hero");
    game.start();

    game.saveGame("save.txt");
    game.loadGame("save.txt");

}
