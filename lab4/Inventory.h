#pragma once
#include <iostream>

class Inventory
{
	std::unique_ptr<std::string[]> items;
	int size = 0;

public:

	void addItem(const std::string& item);

	void displayInventory();
};

