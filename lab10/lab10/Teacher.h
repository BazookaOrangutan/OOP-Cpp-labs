#pragma once

#include "User.h"
#include <string>

class Teacher : public User {
private:
    std::string department;

public:
    Teacher(const std::string& name, int id, int accessLevel, const std::string& department);
    void displayInfo() const override;
};


