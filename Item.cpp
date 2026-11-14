#include "Item.hpp"

class Item{
    public:
        Item::Item(std::string itemName, int buyPrice, int sellPrice,
           int damage, int magicDamage, int defense, int magicDefense) {
            name = itemName;
            buyingPrice = buyPrice;
            sellingPrice = sellPrice;
            stats.damage = damage;
            stats.magicDamage = magicDamage;
            stats.defense = defense;
            stats.magicDefense = magicDefense;
        }

        std::string Item::getName() const {
            return name;
        }

        int Item::getBuyingPrice() const {
            return buyingPrice;
        }

        int Item::getSellingPrice() const {
            return sellingPrice;
        }

        itemStats Item::getStats() const {
            return stats;
        }
};
