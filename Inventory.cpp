#include <iostream>   
#include <string>     
#include <random>
#include <ranges>
using namespace std;
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"


class Inventory {
    private:
        std::string items[25] = {};
        int item_count = 0;

    public:
        void addItem(std::string item) {
            if (item_count < 25) {
                items[item_count] = item;
                item_count++;
            } else {
                std::cout << "Inventory full!\n";
            }
        }

        void removeItem(std::string item){
            items[item_count] = item;
            item_count--;
        }

        bool hasItem(std::string item) {
            for (int i = 0; i < item_count; i++) {
                if (items[i] == item) {
                    return true;
                }
            }
            return false;
        }

        void displayInventoryStatus() const{
            std::cout << "===" itemName "===\n";
        }

        void Inventory::removeItem(std::string item){
            for (int i = 0; i < item_count; i++){
                if (items[i] == item){
                    items[i] = items[item_count - 1];
                    items[item_count - 1] = " "
                    item_count --;
                    return;
                }
            }
        }
};

#endif