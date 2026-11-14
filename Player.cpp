#include <iostream>
#include <string>
#include <random>
#include <ranges>
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H

struct CharacterStats {
    int health;
    int maxHealth;
    int attack;
    int defense;
    int speed;
    int elementalAttack;
    int elementalDefense;
};

class Player {
    private:
        CharacterStats stats;
        std::string name;
        std::string characterClass;
        std::string gender;

        int age;
        int weaponEfficiency;

        

    public:
        Player(std::string playerName, std::string playerClass, int maxHealth, int attack, int defense, int speed,
            int elementalAttack, int elementalDefense) {
            name = playerName;
            characterClass = playerClass;
            stats.maxHealth = maxHealth;
            stats.health = maxHealth;
            stats.attack = attack;
            stats.defense = defense;
            stats.speed = speed;
            stats.elementalAttack = elementalAttack;
            stats.elementalDefense = elementalDefense;
        }

        void setName(std::string player_name) {
            name = player_name;
        }

        std::string getName() {
            return name;
        }

        void setAge(int player_age) {
            age = player_age;
        }

        int getAge() {
            return age;
        }

        void setGender() {
            std::string input;
            bool valid = false;

            while (!valid) {
                std::cout << "Are you male or female? ";
                std::cin >> input;

                if (input == "male" || input == "female") {
                    gender = input;
                    valid = true;
                } else {
                    std::cout << "Please enter a valid input.\n";
                }
            }
        }

        std::string getGender() {
            return gender;
        }

        void displayPlayerStatus() const {
            std::cout << "=== " << name << " (" << characterClass << ") ===\n";
            std::cout << "HP: " << stats.health << "/" << stats.maxHealth << "\n";
            std::cout << "ATK: " << stats.attack << "\n";
            std::cout << "DEF: " << stats.defense << "\n";
            std::cout << "MATK: " << stats.elementalAttack << "\n";
            std::cout << "MDEF: " << stats.elementalDefense << "\n\n";
        }
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