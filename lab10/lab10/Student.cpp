#include "Student.h"
#include <iostream>

Student::Student(const std::string& name, int accessLevel, const std::string& group)
    : User(name, accessLevel), group(group) {}

void Student::displayInfo() const {
    std::cout << "[Student] ID: " << id << ", Name: " << name
        << ", Group: " << group << ", Access Level: " << accessLevel << '\n';
}

std::string Student::getGroup() const
{
    return group;
}
