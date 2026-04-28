/**
 * @brief Implementation of the RandomItemChooser class.
 *
 * This file contains the definitions for RandomItemChooser methods, including
 * initialization of the random generator and selection of items based on rarity.
 */

#include "RandomItemChooser.h"

RandomItemChooser::RandomItemChooser() {
    std::random_device rd;
    generator = std::mt19937(rd());
}

std::string RandomItemChooser::getItemByRarity(const std::vector<std::string>& commonItems,
                                               const std::vector<std::string>& uncommonItems,
                                               const std::vector<std::string>& rareItems) {
    // Roll a random number to determine item rarity with weighted probabilities.
    std::uniform_int_distribution<int> rarityRoll(1, 100);
    int randomNumber = rarityRoll(generator);

    std::string selectedItem;
    std::string rarity;

    if (randomNumber > 30) {
        // Select a random item from the common items list using the private helper method.
        selectedItem = getRandomItem(commonItems);
        rarity = "Common";
    }
    else if (randomNumber > 10) {
        // Select a random item from the uncommon items list using the private helper method.
        selectedItem = getRandomItem(uncommonItems);
        rarity = "Uncommon";
    }
    else {
        // Select a random item from the rare items list using the private helper method.
        selectedItem = getRandomItem(rareItems);
        rarity = "Rare";
    }

    return selectedItem + " (" + rarity + ")";
}

std::string RandomItemChooser::getRandomItem(const std::vector<std::string>& items) {
    // Choose a random item index from the given list.
    std::uniform_int_distribution<int> itemRoll(0, static_cast<int>(items.size()) - 1);
    return items[itemRoll(generator)];
}
