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
