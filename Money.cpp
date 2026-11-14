#ifndef MONEY_H
#define MONEY_H
#include <iostream>
#include <string>
#include <random>
#include "Inventory.h"

class Money {
    private:
        static const int MAX_GOLD = 100000000;
        int gold = 0;

    public:
        void addGold(int amount) {
            gold += amount;
            if (gold > MAX_GOLD) {
                gold = MAX_GOLD;
                std::cout << "Gold full!\n";
            }
            std::cout << "You gained " << amount << " gold! Total: " << gold << "\n";
        }

        int getGold() const {
            return gold;
        }

        bool buying(int item_buying_price, std::string item, Inventory& inventory) {
            if (gold >= item_buying_price) {
                gold -= item_buying_price;
                inventory.addItem(item);
                return true;
            }
            std::cout << "Insufficient Funds\n";
            return false;
        }

        bool selling(int item_selling_price, std::string item, Inventory& inventory) {
            if (!inventory.hasItem(item)) {
                std::cout << "You don't have that item\n";
                return false;
            }
            inventory.removeItem(item);
            addGold(item_selling_price);
            return true;
        }

        // Call once the fight is over: rolls 100-1000 gold and adds it
        int fromFights() {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> distrib(100, 1000);

            int randomValue = distrib(gen);
            addGold(randomValue);
            return randomValue;
        }
};

#endif