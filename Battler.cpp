#include <string>
#include <random>
#include "Character.hpp"
#ifndef BATTLER_H
#define BATTLER_H
#include "Enemy.hpp"
#include <vector>
#include <random>
using namespace std;

struct battlerStats{
    std::string name;
    int hp;
    int attack;
    std::string characterElement;
    std::string attackElement;
    int defense;
    int elementalAttack;
    int elementalDefense;
    int speed;
};


class battler{
    private:
        battlerStats stats;
        int numberOfCombatanants;
        bool poisoned;
        bool paralyzed;
        bool burned;
        bool canAttack;

    public:
        battler(std::string battlerName, int hp, int attack, std::string characterElement,
            std::string attackElement, int defense, int elementalAttack, int elementalDefense, int speed){
                stats.name = battlerName;
                stats.hp = hp;
                stats.attack = attack;
                stats.characterElement = characterElement;
                stats.attackElement = attackElement;
                stats.defense = defense;
                stats.elementalAttack = elementalAttack;
                stats.elementalDefense = elementalDefense;
                stats.speed = speed;
            }
        
        std::string getName() const{
            return stats.name;
        }

        int getSpeed() const{
            return stats.speed;
        }

        int getDefense() const{
            return stats.defense;
        }

        void takeDamage(int damageAmount, Player & player){
            int actualDamage = damageAmount - stats.defense;
            if(actualDamage < 0) {
                actualDamage = 0;
            }

            stats.health -= actualDamage;
            if(stats.health < 0){
                Player.stats.health = 0;
            }

            std::cout << getname() << " takes " << actualDamage << " damage!\n";
        }
        
        
        bool withPrecondition(){
            if(battler == paralyzed){
                stats.speed = stats.speed/2
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> distrib(0, 1);

                paralyzed = distrib(gen);

                if(paralyzed == 1){
                    battler.canAttack() = false;
                } else {
                    battler.canAttack() = true;
                }
            }

            if(battler == burned){
                stats.attack = stats.attack/2
            }

            if(battler == poisoned){
                stats.elementalAttack = stats.elementalAttack/2
            }
        }

        void withApplicability(){

        }

        
};

/*
inline void battleOrder(){
            std::vector<battler> combatants = { hero, enemy1, enemy2 };

            std::sort(combatants.begin(), combatants.end(),[](battler& a, battler& b) {
                    return a.getSpeed() > b.getSpeed();
                });

            std::cout << "Turn order:\n";
            for (battler& b : combatants) {
                std::cout << b.getName() << " (Speed: " << b.getSpeed() << ")\n";
            }
        }

*/
#endif