/**
 * @brief Main entry point for the Inventory Item Rolling Game.
 *
 * This program implements a simple gacha-style game where players can roll for random items
 * of varying rarities (Common, Uncommon, Rare). It manages inventory, tracks recent pickups,
 * and provides statistics on rarity rolls. The game loop handles user input for rolling,
 * viewing inventory, checking history, and displaying rarity counts.
 */

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
              << "To quit, type 'Q'.\n"
              << "To show how many times you've rolled each rarity, type 'L'.\n";

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

    // Main game loop: continue until the player chooses to quit.
    while (userInput != "Q" && userInput != "q") {
        userInput = defaultMessage();

        if (userInput == "R" || userInput == "r") {
            std::cout << "\nRolling for a new item...\n";

            // Call RandomItemChooser to select an item based on rarity, using lists from RandomItemList.
            std::string newItem = itemChooser.getItemByRarity(
                itemList.getCommonItems(),
                itemList.getUncommonItems(),
                itemList.getRareItems()
            );

            // Check if the inventory is at maximum capacity using Inventory class method.
            if (inventory.isFull()) {
                std::cout << "Your inventory is full. Would you like to remove an item? Y/N\n";
                std::string choice;
                std::cin >> choice;

                if (choice == "Y" || choice == "y") {
                    // Call InventoryActions to display inventory and handle user selection for removal.
                    InventoryActions::displayInventory(inventory);
                    std::cout << "Enter index of item to remove: ";

                    int index;
                    std::cin >> index;

                    // Call InventoryActions to remove the selected item from inventory.
                    InventoryActions::removeInventoryItem(inventory, index);
                }
                else {
                    std::cout << "Item not added.\n";
                    continue;
                }
            }

            // Attempt to add the new item to the inventory via Inventory class.
            bool added = inventory.addItem(newItem);

            if (added) {
                // If added successfully, track the pickup in PickupTracker for history and stats.
                pickupTracker.addPickup(newItem);
            }
        }
        else if (userInput == "I" || userInput == "i") {
            // Call InventoryActions to display the current inventory contents.
            InventoryActions::displayInventory(inventory);
        }
        else if (userInput == "H" || userInput == "h") {
            // Call PickupTracker to display recent pickups and rarity statistics.
            pickupTracker.displayRecentPickups();
        }
        else if (userInput == "L" || userInput == "l") {
            // Call PickupTracker to display the count of each rarity rolled.
            pickupTracker.displayRarityCounts();
        }
        else if (userInput != "Q" && userInput != "q") {
            std::cout << "Unknown command.\n";
        }
    }

    std::cout << "Thanks for playing!\n";

    return 0;
}
