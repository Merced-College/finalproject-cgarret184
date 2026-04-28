#include "InventoryActions.h"

void InventoryActions::displayInventory(const Inventory& inventory) {
    inventory.displayInventory();
}

bool InventoryActions::removeInventoryItem(Inventory& inventory, int index) {
    return inventory.removeItem(index);
}
