#include "Entity.h"

Entity::Entity(const std::string& n, int h): name(n), health(h){}

void Entity::displayInfo() const
{
	std::cout << "Name: " << name << ", HP: " << health << std::endl;
}

Entity::~Entity()
{
}

