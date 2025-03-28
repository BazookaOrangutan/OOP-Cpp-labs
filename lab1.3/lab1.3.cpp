#include "Character.h"
#include "Boss.h"

int main()
{
    srand(static_cast<unsigned>(time(0))); 

    // Создание объектов
    Character hero("Hero", 100, 20, 10);
    Monster goblin("Goblin", 50, 15, 5);
    Monster dragon("Dragon", 150, 25, 20);
    Boss boss("Boss dragon", 1000, 70, 100);

    // Массив указателей на базовый класс
    Entity* entities[] = { &hero, &goblin, &dragon, &boss };

    // Полиморфное поведение
    for (auto& entity : entities) {
        entity->displayInfo(); // Вывод информации о сущности
    }

    // Бой между персонажем и монстрами
    hero.attack(goblin);
    goblin.attack(hero);
    dragon.attack(hero);
    boss.attack(hero);
    
    hero.displayInfo();

    hero.heal(40);

    hero.displayInfo();
}
