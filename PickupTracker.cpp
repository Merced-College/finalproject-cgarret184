/**
 * @brief Implementation of the PickupTracker class.
 *
 * This file contains the definitions for PickupTracker methods, handling the addition
 * of pickups, extraction of rarity from items, and display of recent pickups and rarity counts.
 */

#include "PickupTracker.h"
#include <iostream>
#include <vector>

void PickupTracker::addPickup(const std::string& item) {
    // Keep only the most recent MAX_HISTORY pickups by removing the oldest entry when needed.
    if (static_cast<int>(recentItems.size()) >= MAX_HISTORY) {
        recentItems.pop();
    }

    recentItems.push(item);
    // Extract the rarity from the item string using the private helper method.
    std::string rarity = extractRarity(item);
    rarityCounts[rarity]++;
}

std::string PickupTracker::extractRarity(const std::string& item) const {
    const std::string delimiter = " (";
    size_t start = item.rfind(delimiter);
    if (start == std::string::npos) {
        return "Unknown";
    }

    size_t end = item.rfind(')');
    if (end == std::string::npos || end <= start + delimiter.size()) {
        return "Unknown";
    }

    // Extract the rarity substring from the formatted item string.
    return item.substr(start + delimiter.size(), end - (start + delimiter.size()));
}

void PickupTracker::displayRarityCounts() const {
    if (rarityCounts.empty()) {
        std::cout << "No rarity data available yet.\n";
        return;
    }

    std::vector<std::string> order = {"Common", "Uncommon", "Rare", "Unknown"};
    std::cout << "Rarity roll counts:\n";
    // Display rarity counts in a consistent order for readability.
    for (const auto& rarity : order) {
        auto it = rarityCounts.find(rarity);
        if (it != rarityCounts.end()) {
            std::cout << "  " << rarity << ": " << it->second << "\n";
        }
    }
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

    // Iterate through the copied queue to display the recent pickup history in order.
    while (!temp.empty()) {
        std::cout << i << ": " << temp.front() << "\n";
        temp.pop();
        ++i;
    }

    std::cout << "\n";
    // Call the private method to display rarity counts after showing recent pickups.
    displayRarityCounts();
}
