#include "Entity.h"

Entity::Entity(const std::string& n, int h) : name(n), health(h) {}

int Entity::getHealth() const
{
	return health;
}

void Entity::displayInfo() const
{
	std::cout << "Name: " << name << ", HP: " << health << std::endl;
}

Entity::~Entity()
{
}

std::string Entity::serialize() const
{
	return "Entity," + name + "," + std::to_string(health);
}

void Entity::deserialize(const std::string& data)
{
    int pos = data.find(',');

    int next_pos = data.find(',', pos + 1);
    name = data.substr(pos + 1, next_pos - pos - 1);

    pos = next_pos;
    next_pos = data.find(',', pos + 1);
    health = std::stoi(data.substr(pos + 1, next_pos - pos - 1));
}

