#ifndef CHEST_H
#define CHEST_H
#include <string>
#include <iostream>
using namespace std;
#include "Inventory.h"

class Chest {
    private:
        bool is_chest_open = false;
        bool is_chest_locked = false;
        bool chest_has_items = false;
        std::string item_name = " ";

    public:
        void open() {
            is_chest_open = true;
            std::cout << "The chest creaks open.\n";
        }

        void close() {
            is_chest_open = false;
            std::cout << "The chest slams shut.\n";
        }

        bool isOpen() {
            return is_chest_open;
        }

        void lock() {
            is_chest_locked = true;
            std::cout << "The chest is locked\n";
        }

        bool isLocked() {
            return is_chest_locked;
        }

        // Lets main() stock the chest with loot before the player finds it
        void setLoot(std::string item) {
            chest_has_items = true;
            item_name = item;
        }

        bool hasItems() {
            return chest_has_items;
        }

        std::string getItemName() {
            return item_name;
        }

        // Caller checks the inventory and passes in the result
        bool tryUnlock(bool hasKey, Inventory & inventory, string item_name) {
            if (is_chest_locked && hasKey) {
                is_chest_locked = false;
                std::cout << "The chest unlocked\n";

                if(chest_has_item){      
                    addItem(item_name);            
                    std::cout << item_name + " has been added\n";
                    return true;
                }

            } else if (is_chest_locked) {
                std::cout << "The chest is locked. You need a key.\n";
            }
    }
};
#endif