#include "Character.h"
#include "Monster.h"
#include "Weapon.h"

int main()
{
    Weapon sword("Sword", 50, 2);
    Monster goblin("Goblin", 50, 20, 1);
    Character hero("Hero", 100, 30, 50);

    sword.displayInfo();
    goblin.displayInfo();
    hero.displayInfo();

}