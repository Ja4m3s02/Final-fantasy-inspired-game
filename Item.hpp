#ifndef ITEM_H
#define ITEM_H

class Item {
    public:
        Item::item(std::string itemName, int buyPrice, int sellPrice,
           int damage, int magicDamage, int defense, int magicDefense);
        std::string Item::getName() const;
        int Item::getBuyingPrice() const;
        int Item::getSellingPrice() const;
        itemStats Item::getStats() const;
};

#endif