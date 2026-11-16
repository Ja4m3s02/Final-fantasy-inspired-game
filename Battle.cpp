#include <iostream>   
#include <string>     
#include <random>
//#include <ranges>
#include <vector>
#include <queue>
using namespace std;
#ifndef BATTLE_H
#define BATTLE_H
#include "Player.hpp"
#include "Enemy.hpp"
#include "World.hpp"

class Battle{
    private:
        bool in_battle;
        bool endFight;
        bool attacker;
        bool defender;
        int attacksFirst;
        bool startFight;
        

    public:

        //this function is the battle itself
        void battle(Player & player, Enemy & enemy){

        }

        //these are functions that deal with dealing and receiving damage and whether or not if the damage was dealt from a physical attack like a sword or a magic attack

        //deals damage
        void damageDealt(int damageAmount, Player & player, Enemy & enemy){
            int actualDamange = damageAmount - enemy.stats.defense;
            if(actualDamange < 0){
                actualDamange = 0;
            }

            if(enemyStats.health < 0){
                enemyStats.health = 0;
            } 
        }

        //physical damage function that involves the damage dealt function
        int physicalDamageDealt(int attack, int defense, Player & player, Enemy & enemy){

        }

        //same as damage dealt but receiving the damage itself
        int physicalDamageReceived(int attack, int defense, Player & player, Enemy & enemy){
            takeDamage();
        }

        int magicDamageDelt(int magicAttack, int magicDefense, Player & player, Enemy & enemy){
            damageDealt();
        }

        int magicDamageReceived(int magicAttack, int magicDefense, Player & player, Enemy & enemy){
            takeDamage();
        }

        void randomEncounters(){
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> distrib(0,1);

            int encounter = distrib(gen);

            if(encounter = 1){
                canStartBattle();
                turnOrder();
                endOfBattle();
            }
        }

        int numberOfEnemies(){
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> distrib(1, 4);

            int numberOfEnemies = distrib(gen);

            for (int i = 0; i < numberOfEnemies; i++) {
                // placeholder stats until you have real enemy templates
                enemies.push_back(battler("Goblin", 30, 8, "None", "None", 3, 0, 0, 5));
            }

            std::cout << numberOfEnemies << " enemies appeared!\n";
        }

        bool canStartBattle(Player.player, Enemy.enemy, int Enemy.numberOfEnemies) {
            numberOfEnemies();

            if(numberOfEnemies() >= 1){
                startFight = true;
                World.enter_fightscene();
                inBattle();
            } 

            return numberOfEnemies.size() > 1;
        }

        bool inBattle(){
            if(startFight = true){
                in_battle = true;
            }else {
                in_battle = false;
            }
        }

        bool endOfBattle(Money& playerMoney, EXP& playerEXP){
            if(numberOfEnemies == 0) {
                cout << "The enemies have been defeated!" << endl;
                in_battle = false;
                playerMoney.fromFights();
                playerFight.addEXP();
                World.leaving_fightScene();
            }

            if(player.stats.hp == 0){
                cout << player.name << " has fainted!" << endl;
                in_battle = false;
                World.leaving_fightScene();
            }
        }

        std::vector<battler>& getEnemies() {
            return Enemies;
        }

        void turnOrder(Player & player, Enemy & enemy){
            std::queue<string> turnOrder;
            
            Player.stat.speed();
            Enemy.stat.speed();

            turnOrder.push(Player);

            while (true){
                if(Player.stat.speed = Enenmy.stat.speed){
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::bernoulli_distribution dist(0.5);
                    bool random_bool = dist(gen);
                    std::cout << std::boolalpha << random_bool << std::endl;

                    //return 0;

                }else if(Player.stat.speed < Enemy.stat.speed){
                    turnOrder.pop();
                    turnOrder.push(Player.player);
                }else {
                    turnOrder.pop();
                    turnOrder.push(Enenmy.enemy);
                }
            }
            
        }

        
};
#endif