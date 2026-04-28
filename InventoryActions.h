#ifndef INVENTORY_ACTIONS_H
#define INVENTORY_ACTIONS_H

#include "Inventory.h"

class InventoryActions {
public:
    static void displayInventory(const Inventory& inventory);
    static bool removeInventoryItem(Inventory& inventory, int index);
};

#endif
