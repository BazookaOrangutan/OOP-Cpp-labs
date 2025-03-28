#include "Character.h"

int main() {

    Character hero("Hero", 100, 20, 10, 100);
    Character monster("Goblin", 50, 15, 5, 50);

    hero.displayInfo();
    monster.displayInfo();

    hero.attackEnemy(monster);
    monster.displayInfo();

    hero.takeDamage(50);
    hero.displayInfo();

    hero.heal(60);
    hero.displayInfo();

    hero.takeDamage(110);
    hero.displayInfo();

    return 0;
}
