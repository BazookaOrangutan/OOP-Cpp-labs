#include "Administrator.h"
#include <iostream>

Administrator::Administrator(const std::string& name, int accessLevel)
    : User(name, accessLevel) {}

void Administrator::displayInfo() const {
    std::cout << "[Admin]\t  ID: " << id << ", Name: " << name
        << ", Access Level: " << accessLevel << '\n';
}
