/**
 * @brief The InventoryActions class provides static utility functions for inventory management.
 *
 * This class offers methods to display the contents of an inventory and remove items by index,
 * serving as a bridge between the Inventory class and user interactions.
 */
#ifndef INVENTORY_ACTIONS_H
#define INVENTORY_ACTIONS_H

#include "Inventory.h"

class InventoryActions {
public:
    static void displayInventory(const Inventory& inventory);
    static bool removeInventoryItem(Inventory& inventory, int index);
};

#endif
