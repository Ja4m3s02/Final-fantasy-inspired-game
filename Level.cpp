#include <iostream>
#include <string>
using namespace std;
#ifndef LEVEL_H
#define LEVEL_H

class Level{
    private:
        int CharacterLevel;
        int EXP;
        int EnemyLevel;
        const int maxLevel = 100;
        int EXPneeded;

    public:
        void AddEXP(int amount,int EXP){
            EXP += amount;
            std::cout << "You gained " << amount << " EXP \n";
        }

        int getEXP(){
            return EXP;
        }

        void FromFights(){

        }

        void LevelUP(){
            if(EXP == 0){
                EXP = EXP - getEXP();
                CharacterLevel +=1;
            }
            
        }

        
        
};
#endif