/**
 * @brief The Inventory class manages the player's collection of items.
 *
 * This class provides functionality to add items to the inventory, remove items by index,
 * display the current inventory, check if the inventory is full, and get the current size.
 * The inventory has a maximum capacity of 10 items.
 */
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>

class Inventory {
private:
    std::vector<std::string> items;
    static const int MAX_SIZE = 10;

public:
    bool addItem(const std::string& item);
    void displayInventory() const;
    bool removeItem(int index);
    int size() const;
    bool isFull() const;
};

#endif
