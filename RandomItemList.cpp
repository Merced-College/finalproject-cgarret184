/**
 * @brief Implementation of the RandomItemList class.
 *
 * This file contains the constructor for RandomItemList, which initializes
 * the vectors of common, uncommon, and rare items, and provides getter methods.
 */

#include "RandomItemList.h"

RandomItemList::RandomItemList() {
    commonItems = {
        "Apple",
        "Rusty Sword",
        "Wooden Bow",
        "Copper Ingot",
        "Leather Armor",
        "Cobwebs",
        "Bread Loaf",
        "Stone Arrow",
        "Old Bandage",
        "Frog Leg"
    };

    uncommonItems = {
        "Cooked Meat",
        "Iron Longsword",
        "Iron Crossbow",
        "Gold Ingot",
        "Iron Plate Armor",
        "Coin Purse",
        "Field Rations",
        "Iron Bolt",
        "Medkit",
        "Health Potion"
    };

    rareItems = {
        "Cake",
        "Lightsaber",
        "Sniper Rifle",
        "Valyrian Ingot",
        "Stormtrooper Armor",
        "Magic Carpet",
        "Unicorn Horn",
        "Bullet",
        "Surgical Kit",
        "Ferrari"
    };
}

const std::vector<std::string>& RandomItemList::getCommonItems() const {
    return commonItems;
}

const std::vector<std::string>& RandomItemList::getUncommonItems() const {
    return uncommonItems;
}

const std::vector<std::string>& RandomItemList::getRareItems() const {
    return rareItems;
}
