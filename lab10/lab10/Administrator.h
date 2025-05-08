#pragma once

#include "User.h"

class Administrator : public User {
public:
    Administrator(const std::string& name, int id, int accessLevel);
    void displayInfo() const override;
};
