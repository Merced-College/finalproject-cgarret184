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
