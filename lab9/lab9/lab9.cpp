#include "Game.h"

int main() {
    srand(time(NULL));
    try {
        Game game("Hero");
        game.start();
    }
    catch (...) {
        std::cout << "Exiting game.\n";
    }
    return 0;
}
