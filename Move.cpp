#include <string>
using namespace std;
#ifndef MONEY_H
#define MONEY_H

struct MoveStats {
    std::string name;
    int attackDamage;
    int accuracy;
    bool attempt;
};

class Move {
    private:
        MoveStats stats;

    public:
        Move(std::string moveName, int attackDamage, int accuracy) {
            stats.name = moveName;
            stats.attackDamage = attackDamage;
            stats.accuracy = accuracy;
            stats.attempt = false; // starts false — set true during battle resolution
        }

        std::string getName() {
            return stats.name;
        }

        int getAttackDamage() {
            return stats.attackDamage;
        }

        int getAccuracy() {
            return stats.accuracy;
        }

        bool getAttempt() {
            return stats.attempt;
        }

        void setAttempt(bool value) {
            stats.attempt = value;
        }

};

#endif