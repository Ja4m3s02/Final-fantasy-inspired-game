#include "Shop.h"
#include <algorithm>
#include <iostream>

// Returns a pointer to the item with this name, or nullptr if the shop doesn't sell it
const Item* Shop::findItem(const std::string& itemName) const {
    for (const Item& item : stock) {
        if (item.getName() == itemName) {
            return &item;
        }
    }
    return nullptr;
}

void Shop::addStock(const Item& item) {
    stock.push_back(item);
    // TODO: what should happen if the shop already stocks an item with this name?
    // TODO: your old quantity idea could live here (how many of each item are left?)
}

// ---------------------------------------------------------------- Cart

bool Shop::addToCart(const std::string& itemName) {
    if (findItem(itemName) == nullptr) {
        std::cout << itemName << " is not available\n";
        return false;
    }

    if (std::find(cart.begin(), cart.end(), itemName) != cart.end()) {
        std::cout << "Item is already in cart\n";
        return false;
    }

    cart.push_back(itemName);
    std::cout << itemName << " added to cart\n";
    return true;
    // TODO: add removeFromCart(itemName) using std::find and cart.erase(...)
}

// This replaces your empty cart() function
void Shop::viewCart() const {
    std::cout << "=== Shopping Cart ===\n";
    if (cart.empty()) {
        std::cout << "(empty)\n";
        return;
    }
    for (const std::string& itemName : cart) {
        std::cout << "- " << itemName << " (" << findItem(itemName)->getBuyingPrice() << " gold)\n";
    }
    std::cout << "Total: " << cartTotal() << " gold\n";
    // TODO: what if an item in the cart is no longer in stock?
}

int Shop::cartTotal() const {
    int total = 0;
    for (const std::string& itemName : cart) {
        const Item* item = findItem(itemName);
        if (item != nullptr) {
            total += item->getBuyingPrice();
        }
    }
    return total;
}

// ------------------------------------------------------ Buying / selling

bool Shop::buyItem(const std::string& itemName, Money& money, Inventory& inventory) {
    const Item* item = findItem(itemName);
    if (item == nullptr) {
        std::cout << itemName << " is not available\n";
        return false;
    }

    // Money::buying checks the player can afford it and adds it to the inventory
    return money.buying(item->getBuyingPrice(), itemName, inventory);
    // TODO: what if the inventory is full? Money would take the gold anyway
}

// Checks the whole cart can be afforded first, so it's all or nothing
bool Shop::buyFromCart(Money& money, Inventory& inventory) {
    if (cart.empty()) {
        std::cout << "Your cart is empty\n";
        return false;
    }

    int total = cartTotal();
    if (money.getGold() < total) {
        std::cout << "Insufficient Funds (need " << total << ")\n";
        return false;
    }

    for (const std::string& itemName : cart) {
        buyItem(itemName, money, inventory);
    }

    cart.clear();
    return true;
}

bool Shop::sellItem(const std::string& itemName, Money& money, Inventory& inventory) {
    const Item* item = findItem(itemName);
    if (item == nullptr) {
        std::cout << "This shop doesn't buy " << itemName << "\n";
        return false;
    }

    // Money::selling checks the player owns it, removes it and pays them
    return money.selling(item->getSellingPrice(), itemName, inventory);
    // TODO: should the shop only buy items it already stocks?
}