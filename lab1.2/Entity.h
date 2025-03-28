#pragma once
#include <iostream>

class Entity
{
protected:
    std::string name;
    int health;      

public:
    Entity(const std::string& n, int h);

    virtual void displayInfo() const;

    virtual ~Entity();

};

