#include "Item.h"

Item::Item(const std::string& name, ItemType type, int value)
    : name(name), type(type), value(value) {}

std::string Item::getName() const { return name; }
ItemType Item::getType() const { return type; }
int Item::getValue() const { return value; }
