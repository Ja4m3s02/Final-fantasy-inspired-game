#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>

class Inventory {
    private:
        std::string items[25] = {};
        int item_count = 0;

    public:
        void addItem(std::string item);
        bool hasItem(std::string item);
        void removeItem(std::string item);
};

#endif