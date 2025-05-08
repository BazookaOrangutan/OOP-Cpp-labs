#pragma once
#include <string>

enum class ItemType { HP, ATK, DEF };

class Item {
    std::string name;
    ItemType type;
    int value;
public:
    Item(const std::string& name, ItemType type, int value);

    std::string getName() const;
    ItemType getType() const;
    int getValue() const;
};
