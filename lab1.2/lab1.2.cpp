#include "Player.h"
#include "Boss.h"

int main() {
    // Создаем объекты игрока и врага
    Player hero("Hero", 100, 0);
    Enemy monster("Goblin", 50, "Goblin");

    // Выводим информацию о персонажах
    hero.displayInfo();
    monster.displayInfo();

    Boss boss("Boss Goblin", 1000, "Goblin", "High HP");
    boss.displayInfo();
}

