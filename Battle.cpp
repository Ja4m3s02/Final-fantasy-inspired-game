#include <iostream>   
#include <string>     
#include <random>
#include <ranges>
#include <vector>
#include <queue>
using namespace std;
#ifndef BATTLE_H
#define BATTLE_H
#include "Player.h"

class Battle{
    private:
        bool not_in_battle;
        bool endFight;
        bool attacker;
        bool defender;
        int attacksFirst;

    public:
        void damageDealt(int damageAmount, Player & player, Enemy & enemy){
            int actualDamange = damageAmount - enemy.stats.defense;
            if(actualDamange < 0){
                actualDamange = 0;
            }

            if(enemyStats.health < 0){
                enemyStats.health = 0;
            } 
        }

        void physicalDamageDealt(int attack, int defense, Player & player, Enemy & enemy){

        }

        void physicalDamageReceived(int attack, int defense, Player & player, Enemy & enemy){
            takeDamage();
        }

        void magicDamageReceived(int magicAttack, int magicDefense, Player & player, Enemy & enemy){
            takeDamage();
        }

        void endOfBattle(Money& playerMoney){
            if (enemies.empty()) {
                in_battle = false;
                playerMoney.fromFights();
            }
        }

        void numberOfEnemies(){
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> distrib(1, 4);

            int enemyCount = distrib(gen);

            for (int i = 0; i < enemyCount; i++) {
                // placeholder stats until you have real enemy templates
                enemies.push_back(battler("Goblin", 30, 8, "None", "None", 3, 0, 0, 5));
            }

            std::cout << enemyCount << " enemies appeared!\n";
        }

        bool canStartBattle() {
            return numberOfEnemies.size() > 1;
        }

        std::vector<battler>& getEnemies() {
            return enemies;
        }

        void turnOrder(){
            std::queue<string> turnOrder;
            
            getPlayer.stat.speed()
            getEnemy.stat.speed()

            turnOrder.push(Player);
            while true{
                if(Player.stat.speed = Enenmy.stat.speed){
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::bernoulli_distribution dist(0.5);
                    bool random_bool = dist(gen);
                    std::cout << std::boolalpha << random_bool << std::endl;
                    return 0;

                }else if(Player.stat.speed < Enemy.stat.speed){
                    turnOrder.pop();
                    turnOrder.push(Player.player)
                }else{

                }
            }
            
        }
};
#endif