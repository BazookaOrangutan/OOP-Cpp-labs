#include "User.h"
#include <stdexcept>

User::User(const std::string& name, int id, int accessLevel)
    : name(name), id(id), accessLevel(accessLevel) {
    if (name.empty()) throw std::invalid_argument("Name cannot be empty.");
    if (accessLevel < 0) throw std::invalid_argument("Access level must be non-negative.");
}

std::string User::getName() const { return name; }
int User::getId() const { return id; }
int User::getAccessLevel() const { return accessLevel; }

void User::setName(const std::string& name) {
    if (name.empty()) throw std::invalid_argument("Name cannot be empty.");
    this->name = name;
}

void User::setId(int id) {
    this->id = id;
}

void User::setAccessLevel(int accessLevel) {
    if (accessLevel < 0) throw std::invalid_argument("Access level must be non-negative.");
    this->accessLevel = accessLevel;
}
