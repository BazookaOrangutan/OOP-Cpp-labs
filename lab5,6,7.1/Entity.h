#pragma once
#include <iostream>
#include <string>

class Entity
{
protected:
    std::string name;
    int health;

public:
    Entity(const std::string& n, int h);

    int getHealth() const;

    virtual void displayInfo() const;

    virtual ~Entity();

    virtual std::string serialize() const;

    virtual void deserialize(const std::string& data);

};

