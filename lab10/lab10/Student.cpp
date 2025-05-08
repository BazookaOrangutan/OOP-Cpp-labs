#include "Student.h"
#include <iostream>

Student::Student(const std::string& name, int id, int accessLevel, const std::string& group)
    : User(name, id, accessLevel), group(group) {}

void Student::displayInfo() const {
    std::cout << "[Student] Name: " << name << ", ID: " << id
        << ", Group: " << group << ", Access Level: " << accessLevel << '\n';
}
