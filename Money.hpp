#ifndef MONEY_H
#define MONEY_H

class Money{
    private:
        static const int MAX_GOLD;
        int gold;

    public:
        void addGold(int amount);
        int getGold() const;
        bool buying(int item_buying_price, std::string item, Inventory& inventory);
        bool selling(int item_selling_price, std::string item, Inventory& inventory);
        int fromFights();
}

#endif