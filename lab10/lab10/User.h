#pragma once

#include <string>

class User {
protected:
    std::string name;
    int id;
    int accessLevel;

public:
    User(const std::string& name, int id, int accessLevel);
    virtual ~User() = default;

    std::string getName() const;
    int getId() const;
    int getAccessLevel() const;

    void setName(const std::string& name);
    void setId(int id);
    void setAccessLevel(int accessLevel);

    virtual void displayInfo() const = 0;
};

