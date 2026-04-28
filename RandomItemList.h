/**
 * @brief The RandomItemList class stores predefined item lists by rarity.
 *
 * This class initializes and provides access to vectors of items categorized as
 * common, uncommon, and rare. These lists are used by the RandomItemChooser
 * for random item selection in the gacha game.
 */
#ifndef RANDOM_ITEM_LIST_H
#define RANDOM_ITEM_LIST_H

#include <string>
#include <vector>

class RandomItemList {
private:
    std::vector<std::string> commonItems;
    std::vector<std::string> uncommonItems;
    std::vector<std::string> rareItems;

public:
    RandomItemList();

    const std::vector<std::string>& getCommonItems() const;
    const std::vector<std::string>& getUncommonItems() const;
    const std::vector<std::string>& getRareItems() const;
};

#endif
