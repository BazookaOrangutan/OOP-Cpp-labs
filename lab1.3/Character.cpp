#include "Character.h"

Character::Character(const std::string& n, int h, int p, int d) : Entity(n, h, p, d) {}

void Character::attack(Entity& target)
{
    int damage = power - target.getDefense();
    if (damage > 0) {
        if (rand() % 100 < 20) {
            damage *= 2;
            std::cout << "Critical hit! ";
        }
        target.setHealth(target.getHealth() - damage);
        std::cout << name << " attacks " << target.getName() << " for " << damage << " damage!\n";
    }
    else {
        std::cout << name << " attacks " << target.getName() << ", but it has no effect!\n";
    }

}

void Character::heal(int amount)
{
    health += amount;
    std::cout << name << " heal " << amount << "HP" << std::endl;
}

void Character::displayInfo() const
{
    std::cout << "Character: " << name << ", HP: " << health
        << ", Attack: " << power << ", Defense: " << defense << std::endl;
}
