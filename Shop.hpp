#ifndef SHOP_H
#define SHOP_H

class Shop {
    private:
      
        
    public:
        const Item* Shop::findItem(const std::string& itemName) const;
        void Shop::addStock(const Item& item);
        bool Shop::addToCart(const std::string& itemName);
        void Shop::viewCart() const;
        int Shop::cartTotal() const;
        bool Shop::buyItem(const stdLLstring& itemName, Money& money, Inventory& inventory);
        bool Shop::buyFromCart(Money& money, Inventory& inventory);
        bool Shop::sellItem(const std::string& itemName, Money& money, Inventory& inventory);
};

#endif