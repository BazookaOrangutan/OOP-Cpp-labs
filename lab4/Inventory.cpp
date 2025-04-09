#include "Inventory.h"

void Inventory::addItem(const std::string& item)
{
	std::unique_ptr<std::string[]> buf = std::make_unique<std::string[]>(size + 1);

	for (int i = 0; i < size; ++i) {
		buf[i] = items[i];
	}

	buf[size++] = item;
	items = std::move(buf);

}

void Inventory::displayInventory()
{
	std::cout << "Inventory: ";
	for (int i = 0; i < size; ++i) {
		std::cout << items[i] << ", ";
	}
	std::cout << std::endl;
}
