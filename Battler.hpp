#ifndef BATTLER_H
#define BATTLER_H

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
            std::string attackElement, int defense, int elementalAttack, int elementalDefense, int speed);
        
        std::string getName() const;
        int getSpeed() const;
        int getDefense() const;
        void takeDamage(int damageAmount, Player & player);
        bool withPrecondition();
        void withApplicability();
};

#endif