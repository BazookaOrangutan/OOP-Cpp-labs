#pragma once

#include <string>

class User {
protected:
    std::string name;
    int id;
    int accessLevel;
    static int nextId;

public:
    User(const std::string& name, int accessLevel);
    virtual ~User() = default;

    std::string getName() const;
    int getId() const;
    int getAccessLevel() const;

    void setName(const std::string& name);
    void setId(int id);
    void setAccessLevel(int accessLevel);
    static void setNextId(int id);

    virtual void displayInfo() const = 0;
};

