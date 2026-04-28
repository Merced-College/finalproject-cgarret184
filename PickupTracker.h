#ifndef PICKUP_TRACKER_H
#define PICKUP_TRACKER_H

#include <queue>
#include <string>

class PickupTracker {
private:
    static const int MAX_HISTORY = 5;
    std::queue<std::string> recentItems;

public:
    void addPickup(const std::string& item);
    void displayRecentPickups() const;
};

#endif
