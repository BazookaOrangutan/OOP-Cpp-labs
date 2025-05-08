#pragma once

#include "User.h"
#include <string>

class Student : public User {
private:
    std::string group;

public:
    Student(const std::string& name, int id, int accessLevel, const std::string& group);
    void displayInfo() const override;
};


