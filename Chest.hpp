#ifndef CHEST_H
#define CHEST_H
using namespace std;

class Chest {
    private:
      bool is_chest_open;
      bool is_chest_locked;
      bool chest_has_items;
      std::string item_name;

    public:
        void open();
        void close();
        bool isOpen();
        void lock();
        bool isLocked();
        void setLook(std::string);
        bool hasItems();
        std::string getItemNames();
        bool tryUnlock(bool hasKey, Inventory & inventory, string item_name)
};

#endif