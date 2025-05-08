#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <ostream>

void Inventory::addItem(const Item& item) {
    items.push_back(item);
    std::cout << "Item added: " << item.getName() << "\n";
}

void Inventory::showInventory() const {
    std::cout << "\nInventory:\n";
    for (const auto& item : items) {
        std::cout << "- " << item.getName() << " (+" << item.getValue() << " ";
        switch (item.getType()) {
        case ItemType::HP: std::cout << "HP"; break;
        case ItemType::ATK: std::cout << "ATK"; break;
        case ItemType::DEF: std::cout << "DEF"; break;
        }
        std::cout << ")\n";
    }
}

void Inventory::applyItemEffects(Character& character) {
    for (const auto& item : items) {
        switch (item.getType()) {
        case ItemType::HP:
            character.heal(item.getValue());
            break;
        case ItemType::ATK:
            character.buffAttack(item.getValue());
            break;
        case ItemType::DEF:
            character.buffDefense(item.getValue());
            break;
        }
    }
    std::cout << "All item effects applied to " << character.getName() << ".\n";
}

void Inventory::save(std::ofstream& out) const {
    out << items.size() << "\n";
    for (const auto& item : items) {
        out << item.getName() << " "
            << static_cast<int>(item.getType()) << " "
            << item.getValue() << "\n";
    }
}

void Inventory::load(std::ifstream& in) {
    items.clear();
    size_t count;
    if (!(in >> count)) return;
    for (size_t i = 0; i < count; ++i) {
        std::string name;
        int typeInt, value;
        in >> name >> typeInt >> value;
        items.emplace_back(name, static_cast<ItemType>(typeInt), value);
    }
}