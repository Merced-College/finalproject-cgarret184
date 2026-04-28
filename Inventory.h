#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>

class Inventory {
private:
    std::vector<std::string> items;
    static const int MAX_SIZE = 10;

public:
    bool addItem(const std::string& item);
    void displayInventory() const;
    bool removeItem(int index);
    int size() const;
    bool isFull() const;
};

#endif
