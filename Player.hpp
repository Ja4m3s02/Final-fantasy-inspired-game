#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player{
    private:
        CharacterStats stats;
        std::string name;
        std::string characterClass;
        std::string gender;
        int age;
        int weaponEfficiency;

    public:
        Player(std::string playerName, std::string playerClass, int maxHealth, int attack, int defense, int speed,
            int elementalAttack, int elementalDefense);
        std::string setName(std::string player_name);
        std::string getName();
        int setAge(int player_age);
        int getAge();
        void setGender();
        std::string getGender();
        void displayPlayerStatus();
};

class Warrior : public Player {
    public:
        Warrior(std::string playerName, int maxHealth, int attack, int defense,
                int elementalAttack, int elementalDefense)
            : Player(playerName, "Warrior", maxHealth, attack, defense, elementalAttack, elementalDefense) {
        }
};

class Mage : public Player {
    public:
        Mage(std::string playerName, int maxHealth, int attack, int defense,
             int elementalAttack, int elementalDefense)
            : Player(playerName, "Mage", maxHealth, attack, defense, elementalAttack, elementalDefense) {
        }
};

#endif