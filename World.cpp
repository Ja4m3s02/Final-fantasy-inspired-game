#include <iostream>   // Required for input and output operations
#include <string>     // Required to use the string data type
#include <random>
#include <ranges>
using namespace std;
#ifndef WORLD_H
#define WORLD_H

class World {
    // TODO: build this out later
    private:
        bool open_world = false;
        bool cutscene = false;
        bool fightscene = false;

    public:
        void enter_open_world(){
            open_world = true;
            cout << "You are in open world \n";
        }

        void leaving_open_world(){
            open_world = false;
            cout <<"You are leaving open world \n";
        }

        void enter_cutscene(){
            cutscene = true;
            cout << "You are in a cutscene \n";
        }

        void leaving_cutscene(){
            cutscene = false;
            cout << "You are leaving a cutscene \n";
        }

        void enter_fightscene(){
            fightscene = true;
            startOfBattle();
            cout << "You are starting a fight \n";
        }

        void leaving_fightscene(){
            fightscene = false;
            endOfBattle()
            cout << "you are leaving a fight \n";
        }
};
#endif