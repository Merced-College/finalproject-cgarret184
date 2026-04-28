#include "Inventory.h"
#include <iostream>

bool Inventory::addItem(const std::string& item) {
    if (isFull()) {
        std::cout << "Your inventory is full. Item was not added.\n";
        return false;
    }

    items.push_back(item);
    std::cout << item << " has been added to your inventory.\n";
    return true;
}

void Inventory::displayInventory() const {
    if (items.empty()) {
        std::cout << "Your inventory is empty.\n";
        return;
    }

    for (int i = 0; i < static_cast<int>(items.size()); ++i) {
        std::cout << i << ": " << items[i] << "\n";
    }
}

bool Inventory::removeItem(int index) {
    if (index >= 0 && index < static_cast<int>(items.size())) {
        items.erase(items.begin() + index);
        std::cout << "\nItem removed.\n";
        return true;
    }

    std::cout << "\nInvalid index.\n";
    return false;
}

int Inventory::size() const {
    return static_cast<int>(items.size());
}

bool Inventory::isFull() const {
    return size() >= MAX_SIZE;
}
