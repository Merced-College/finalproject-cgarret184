#include <iostream>
#include <string>

#include "Inventory.h"
#include "InventoryActions.h"
#include "PickupTracker.h"
#include "RandomItemChooser.h"
#include "RandomItemList.h"

std::string defaultMessage() {
    std::string userInput;

    std::cout << "\nTo roll for a new item, type 'R'. "
              << "To display inventory, type 'I'. "
              << "To show recent pickups, type 'H'. "
              << "To quit, type 'Q'.\n";

    std::cin >> userInput;
    return userInput;
}

int main() {
    std::cout << "Welcome to the Inventory Item Rolling Game!\n";

    Inventory inventory;
    PickupTracker pickupTracker;
    RandomItemChooser itemChooser;
    RandomItemList itemList;

    std::string userInput = "";

    while (userInput != "Q" && userInput != "q") {
        userInput = defaultMessage();

        if (userInput == "R" || userInput == "r") {
            std::cout << "\nRolling for a new item...\n";

            std::string newItem = itemChooser.getItemByRarity(
                itemList.getCommonItems(),
                itemList.getUncommonItems(),
                itemList.getRareItems()
            );

            if (inventory.isFull()) {
                std::cout << "Your inventory is full. Would you like to remove an item? Y/N\n";
                std::string choice;
                std::cin >> choice;

                if (choice == "Y" || choice == "y") {
                    InventoryActions::displayInventory(inventory);
                    std::cout << "Enter index of item to remove: ";

                    int index;
                    std::cin >> index;

                    InventoryActions::removeInventoryItem(inventory, index);
                }
                else {
                    std::cout << "Item not added.\n";
                    continue;
                }
            }

            bool added = inventory.addItem(newItem);

            if (added) {
                pickupTracker.addPickup(newItem);
            }
        }
        else if (userInput == "I" || userInput == "i") {
            InventoryActions::displayInventory(inventory);
        }
        else if (userInput == "H" || userInput == "h") {
            pickupTracker.displayRecentPickups();
        }
        else if (userInput != "Q" && userInput != "q") {
            std::cout << "Unknown command.\n";
        }
    }

    std::cout << "Thanks for playing!\n";

    return 0;
}
