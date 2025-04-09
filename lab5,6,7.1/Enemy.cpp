#include "Enemy.h"

Enemy::Enemy(const std::string& n, int h, const std::string& t) : Entity(n, h), type(t) {}

void Enemy::displayInfo() const
{
	Entity::displayInfo();
	std::cout << "Type: " << type << std::endl;

}

std::string Enemy::serialize() const
{
	return "Enemy," + name + "," + std::to_string(health) + "," + type;
}

void Enemy::deserialize(const std::string& data)
{
    int pos = data.find(',');

    int next_pos = data.find(',', pos + 1);
    name = data.substr(pos + 1, next_pos - pos - 1);

    pos = next_pos;
    next_pos = data.find(',', pos + 1);
    health = std::stoi(data.substr(pos + 1, next_pos - pos - 1));

    pos = next_pos;
    type = data.substr(pos + 1);
}


