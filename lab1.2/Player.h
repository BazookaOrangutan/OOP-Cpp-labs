#pragma once
#include "Entity.h"

class Player : public Entity
{
    int experience; 

public:

    Player(const std::string& n, int h, int exp);

    void displayInfo() const override;

};

