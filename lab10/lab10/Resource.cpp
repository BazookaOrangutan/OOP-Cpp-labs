#include "Resource.h"
#include <stdexcept>

Resource::Resource(const std::string& name, int requiredAccessLevel)
    : name(name), requiredAccessLevel(requiredAccessLevel) {
    if (requiredAccessLevel < 0) throw std::invalid_argument("Invalid access level.");
}

std::string Resource::getName() const { return name; }
int Resource::getRequiredAccessLevel() const { return requiredAccessLevel; }

bool Resource::checkAccess(const User& user) const {
    return user.getAccessLevel() >= requiredAccessLevel;
}
