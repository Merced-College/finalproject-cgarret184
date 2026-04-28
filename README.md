Project Title: Item Rolling Rarity Game

Description: This is a simple game I created where the user will try their luck rolling for new items of varying rarities. The user will have to make decisions on what to keep or discard, as you can only hold a limited amount! Controls on how to play the game are outputted to the user once you start. 

Compiling / Running Program: To compile this C++ gacha game, use the command g++ -std=c++17 main.cpp Inventory.cpp InventoryActions.cpp PickupTracker.cpp RandomItemChooser.cpp RandomItemList.cpp -o gacha_game in your terminal, which links all source files into an executable named gacha_game. Once compiled, run the program by typing ./gacha_game in the terminal, and follow the on-screen prompts to roll for items, view inventory, check recent pickups, or display rarity counts. If using VS Code, you can also use the pre-configured build task (Ctrl+Shift+B) and debugger (F5) for a streamlined experience.

Program Features: 
• An item rolling system, controlled by the user
• Inventory system that keeps a limited amount of items for the player 
• Item history tracker, showing the user the total items and rarities they've rolled (in total). 

Data Structures: 
1. `std::vector`
Files used in: `Inventory.h`, `Inventory.cpp`, `RandomItemList.h`, `RandomItemList.cpp`
The project uses `std::vector` to store the player's inventory and the different item rarity lists, such as common, uncommon, and rare items. A vector is useful here because items can be added, removed, accessed by index, and displayed in order.

2. `std::queue`
Files used in: `PickupTracker.h`, `PickupTracker.cpp`
The project uses `std::queue` to track the player's most recent item pickups. This works well because a queue follows FIFO order, meaning the oldest pickup is removed first when the recent pickup history reaches its limit.

3. `std::map` or `std::unordered_map`
Files used in: `PickupTracker.h`, `PickupTracker.cpp`
The project uses a map structure to keep track of how many times each rarity has been rolled, such as Common, Uncommon, and Rare. This is useful because each rarity name can be stored as a key, while the number of times it has appeared is stored as the value.

Algorithms Used: 

1. Random Rarity Selection Algorithm
Files used in: `RandomItemChooser.h`, `RandomItemChooser.cpp`
The project uses a random number from 1 to 100 to decide the rarity of the item the player receives. The number is checked against probability ranges so that Common items are most likely, Uncommon items are less likely, and Rare items are the hardest to roll.

2. Random Item Selection Algorithm
Files used in: `RandomItemChooser.h`, `RandomItemChooser.cpp`, `RandomItemList.h`, `RandomItemList.cpp`
After the rarity is chosen, the program randomly selects one item from the matching item list. This allows the game to choose a different item each time from the Common, Uncommon, or Rare item pools.

3. Inventory Capacity and Removal Algorithm
Files used in: `Inventory.h`, `Inventory.cpp`, `InventoryActions.h`, `InventoryActions.cpp`
The program checks whether the inventory has reached its maximum size before adding a new item. If the inventory is full, the user is given the option to remove an existing item by index before the new item is added.

4. Recent Pickup Tracking Algorithm
Files used in: `PickupTracker.h`, `PickupTracker.cpp`
The project tracks the player’s most recent pickups using first-in, first-out logic. When the recent pickup history reaches its limit, the oldest item is removed before the newest item is added.

5. Rarity Count Tracking Algorithm
Files used in: `PickupTracker.h`, `PickupTracker.cpp`
The program checks the rarity of each successfully added item and updates a count for that rarity. This allows the player to view how many Common, Uncommon, and Rare items they have rolled during the game.

Name of Contributors: Garret Clark 