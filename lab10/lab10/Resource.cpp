#include "Resource.h"
#include <stdexcept>

int Resource::nextId = 1;

Resource::Resource(const std::string& name, int requiredAccessLevel) : name(name), requiredAccessLevel(requiredAccessLevel)
{
    if (requiredAccessLevel < 0) throw std::invalid_argument("Invalid access level.");
    id = nextId++;
}

std::string Resource::getName() const { return name; }
int Resource::getId() const { return id; }
int Resource::getRequiredAccessLevel() const { return requiredAccessLevel; }

bool Resource::checkAccess(const User& user) const {
    return user.getAccessLevel() >= requiredAccessLevel;
}

void Resource::setNextId(int id)
{
    nextId = id;
}
