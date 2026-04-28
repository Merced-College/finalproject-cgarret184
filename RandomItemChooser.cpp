#include "RandomItemChooser.h"

RandomItemChooser::RandomItemChooser() {
    std::random_device rd;
    generator = std::mt19937(rd());
}

std::string RandomItemChooser::getItemByRarity(const std::vector<std::string>& commonItems,
                                               const std::vector<std::string>& uncommonItems,
                                               const std::vector<std::string>& rareItems) {
    std::uniform_int_distribution<int> rarityRoll(1, 100);
    int randomNumber = rarityRoll(generator);

    std::string selectedItem;
    std::string rarity;

    if (randomNumber > 30) {
        selectedItem = getRandomItem(commonItems);
        rarity = "Common";
    }
    else if (randomNumber > 10) {
        selectedItem = getRandomItem(uncommonItems);
        rarity = "Uncommon";
    }
    else {
        selectedItem = getRandomItem(rareItems);
        rarity = "Rare";
    }

    return selectedItem + " (" + rarity + ")";
}

std::string RandomItemChooser::getRandomItem(const std::vector<std::string>& items) {
    std::uniform_int_distribution<int> itemRoll(0, static_cast<int>(items.size()) - 1);
    return items[itemRoll(generator)];
}
