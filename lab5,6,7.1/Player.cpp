#include "Player.h"

Player::Player() : Entity("", 0), experience(0)
{
}

Player::Player(const std::string& n, int h, int exp) : Entity(n, h), experience(exp) {}

void Player::displayInfo() const
{
	Entity::displayInfo();
	std::cout << "Experience: " << experience << std::endl;
}

std::string Player::serialize() const
{
	return "Player," + name + "," + std::to_string(health) + "," + std::to_string(experience);
}

void Player::deserialize(const std::string& data)
{
    int pos = data.find(',');

    int next_pos = data.find(',', pos + 1);
    name = data.substr(pos + 1, next_pos - pos - 1);

    pos = next_pos;
    next_pos = data.find(',', pos + 1);
    health = std::stoi(data.substr(pos + 1, next_pos - pos - 1));

    pos = next_pos;
    experience = std::stoi(data.substr(pos + 1));
}

