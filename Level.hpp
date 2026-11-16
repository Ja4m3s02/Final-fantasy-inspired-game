#ifndef LEVEL_H
#define LEVEL_H

class Level {
    private:
        int CharacterLevel;
        int EXP;
        int EnemyLevel;
        const int maxLevel = 100;
        int EXPneeded;
        
    public:
        void AddEXP(int amount, int EXP);
        int getEXP();
        void fromFights();
        void LevelUP();
};

#endif