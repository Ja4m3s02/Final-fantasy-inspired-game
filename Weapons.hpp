#ifndef WEAPONS_H
#define WEAPONS_H

struct weaponStats{
    int damange;
    int magicDamage;
    int defense;
    int magicDefense;
};

class Weapons {
    private:
        const std::string items[25];
        int weapon_count;
        std::string name;
        weaponStats stats;

    public:
        Weapon(std::string weaponName, int damage, int magicDamage, int defense, int magicDefense);
        void addWeapon(const std::string & weaponName);
        void hasWeapon(const std::string & weaponName);
};

#endif