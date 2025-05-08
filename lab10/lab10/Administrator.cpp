#include "Administrator.h"
#include <iostream>

Administrator::Administrator(const std::string& name, int id, int accessLevel)
    : User(name, id, accessLevel) {}

void Administrator::displayInfo() const {
    std::cout << "[Admin] Name: " << name << ", ID: " << id
        << ", Access Level: " << accessLevel << '\n';
}
