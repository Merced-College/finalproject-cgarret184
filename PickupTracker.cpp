#include "PickupTracker.h"
#include <iostream>

void PickupTracker::addPickup(const std::string& item) {
    if (static_cast<int>(recentItems.size()) >= MAX_HISTORY) {
        recentItems.pop();
    }

    recentItems.push(item);
}

void PickupTracker::displayRecentPickups() const {
    if (recentItems.empty()) {
        std::cout << "No recent pickups.\n";
        return;
    }

    std::cout << "Recent pickups:\n";

    // Copy the queue so we can display it without modifying the original.
    std::queue<std::string> temp = recentItems;
    int i = 1;

    while (!temp.empty()) {
        std::cout << i << ": " << temp.front() << "\n";
        temp.pop();
        ++i;
    }
}
