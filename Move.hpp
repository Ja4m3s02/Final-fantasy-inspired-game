#ifndef MOVE_H
#define MOVE_H

struct MoveStats{
    std::string name;
    int attackDamage;
    int accuracy;
    bool attempt;
};

class Move {
    private:
        MoveStats name;
        
    public:
        Move(std::string moveName, int attackDamage, int accuracy);
        std::string getName();
        int getAttackDamage();
        int getAccuracy();
        bool getAttempt();
        void setAttempt();
};

#endif