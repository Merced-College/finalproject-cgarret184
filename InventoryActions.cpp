/**
 * @brief Implementation of the InventoryActions class.
 *
 * This file contains the definitions for the static methods of InventoryActions,
 * providing utility functions to display and modify inventory contents.
 */

#include "InventoryActions.h"

void InventoryActions::displayInventory(const Inventory& inventory) {
    // Delegate the display logic to the Inventory class's displayInventory method.
    inventory.displayInventory();
}

bool InventoryActions::removeInventoryItem(Inventory& inventory, int index) {
    // Delegate the removal logic to the Inventory class's removeItem method.
    return inventory.removeItem(index);
}
