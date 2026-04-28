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
