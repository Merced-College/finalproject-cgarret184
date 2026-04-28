/**
 * @brief The RandomItemChooser class handles random item selection based on rarity.
 *
 * This class uses a Mersenne Twister random number generator to select items from
 * provided lists of common, uncommon, and rare items, with weighted probabilities
 * (70% common, 20% uncommon, 10% rare). It appends the rarity to the selected item name.
 */
#ifndef RANDOM_ITEM_CHOOSER_H
#define RANDOM_ITEM_CHOOSER_H

#include <random>
#include <string>
#include <vector>

class RandomItemChooser {
private:
    std::mt19937 generator;

    std::string getRandomItem(const std::vector<std::string>& items);

public:
    RandomItemChooser();
    std::string getItemByRarity(const std::vector<std::string>& commonItems,
                                const std::vector<std::string>& uncommonItems,
                                const std::vector<std::string>& rareItems);
};

#endif
