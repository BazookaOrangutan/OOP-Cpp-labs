#include "Monster.h"

Monster::Monster(const std::string& n, int h, int p, int d) : Entity(n, h, p, d)
{
}

void Monster::attack(Entity& target)
{
    int damage = power - target.getDefense();
    if (damage > 0) {
        // Шанс на ядовитую атаку (30%)
        if (rand() % 100 < 30) {
            damage += 5; // Дополнительный урон от яда
            std::cout << "Poisonous attack! ";
        }
        target.setHealth(target.getHealth() - damage);
        std::cout << name << " attacks " << target.getName() << " for " << damage << " damage!\n";
    }
    else {
        std::cout << name << " attacks " << target.getName() << ", but it has no effect!\n";
    }
}

void Monster::displayInfo() const
{
    std::cout << "Monster: " << name << ", HP: " << health
        << ", Attack: " << power << ", Defense: " << defense << std::endl;

}



