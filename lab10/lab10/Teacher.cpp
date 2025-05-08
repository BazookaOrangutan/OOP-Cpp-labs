#include "Teacher.h"
#include <iostream>

Teacher::Teacher(const std::string& name, int id, int accessLevel, const std::string& department)
    : User(name, id, accessLevel), department(department) {}

void Teacher::displayInfo() const {
    std::cout << "[Teacher] Name: " << name << ", ID: " << id
        << ", Department: " << department << ", Access Level: " << accessLevel << '\n';
}
