#include <iostream>   
#include <string>     
#include <random>
#include <ranges>
using namespace std;
#ifndef WEAPONS_H
#define WEAPONS_H

struct weaponStats{
    int damage;
    int magicDamage;
    int defense;
    int magicDefense;
};

class Weapon {
    private:
        std::string items[25] = {};
        int weapon_count = 0;
        std::string name;
        weaponStats stats;
        //each weapon needs to have their own stats and abilities

    public:
        Weapon(std::string weaponName, int damage, int magicDamage, int defense, int magicDefense){
            name = weaponName;
            stats.damage = damage;
            stats.magicDamage = magicDamage;
            stats.defense = defense;
            stats.magicDefense = magicDefense;
        }

        void addWeapon(const std::string & weaponName) {
            if (weapon_count < 25) {
                items[weapon_count] = weaponName;
                weapon_count++;
            } else {
                std::cout << "Inventory full!\n";
            }
        }

        bool hasWeapon(const std::string & weaponName) {
            for (int i = 0; i < weapon_count; i++) {
                if (items[i] == weaponName) {
                    return true;
                    std::cout << "You already have " << weaponName << "\n";
                }
            }
            return false;
        }
};

#endif