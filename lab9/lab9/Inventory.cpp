#include "Inventory.h"
#include <algorithm>

void Inventory::addItem(const std::string& item) {
    items.push_back(item);
}

void Inventory::removeItem(const std::string& item) {
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

void Inventory::showInventory() const {
    std::cout << "Inventory:\n";
    for (const auto& item : items)
        std::cout << "- " << item << "\n";
}
