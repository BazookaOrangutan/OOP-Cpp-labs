#pragma once
#include "Entity.h"

class Player : public Entity
{
    int experience ;

public:

    Player();

    Player(const std::string& n, int h, int exp);

    void displayInfo() const override;
    
    std::string serialize() const override;

    void deserialize(const std::string& data) override;
};

