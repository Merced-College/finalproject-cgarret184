/**
 * @brief The PickupTracker class tracks recent item pickups and rarity statistics.
 *
 * This class maintains a queue of the most recent pickups (up to 5 items) and a map
 * counting the number of items rolled for each rarity level (Common, Uncommon, Rare).
 * It provides methods to add pickups and display both recent items and rarity counts.
 */
#ifndef PICKUP_TRACKER_H
#define PICKUP_TRACKER_H

#include <map>
#include <queue>
#include <string>

class PickupTracker {
private:
    static const int MAX_HISTORY = 5;
    std::queue<std::string> recentItems;
    std::map<std::string, int> rarityCounts;

    std::string extractRarity(const std::string& item) const;

public:
    void addPickup(const std::string& item);
    void displayRecentPickups() const;
    void displayRarityCounts() const;
};

#endif
