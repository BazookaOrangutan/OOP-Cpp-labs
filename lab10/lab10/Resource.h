#pragma once

#include <string>
#include "User.h"

class Resource {
private:
    int id;
    std::string name;
    int requiredAccessLevel;
    static int nextId;

public:
    Resource(const std::string& name, int requiredAccessLevel);
    std::string getName() const;
    int getId() const;
    int getRequiredAccessLevel() const;
    bool checkAccess(const User& user) const;
    static void setNextId(int id);
};




