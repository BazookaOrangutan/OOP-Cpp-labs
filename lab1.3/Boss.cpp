#include "Boss.h"

Boss::Boss(const std::string& n, int h, int p, int d) : Monster(n, h, p, d)
{
}

void Boss::attack(Entity& target)
{
    int damage = power - target.getDefense();
    if (damage > 0) {
        if (rand() % 100 < 50) {
            damage *= 3;
            std::cout << "Powerful attack";
        }
        target.setHealth(target.getHealth() - damage);
        std::cout << name << " attacks " << target.getName() << " for " << damage << " damage!\n";
    }
    else {
        std::cout << name << " attacks " << target.getName() << ", but it has no effect!\n";
    }
}

void Boss::displayInfo() const
{
    std::cout << "Boss: " << name << ", HP: " << health
        << ", Attack: " << power << ", Defense: " << defense << std::endl;
}
