#ifndef BATTLE_H
#define BATTLE_H


class Battle{
    private:
        bool in_battle;
        bool endFight;
        bool attacker;
        bool defender;
        int attacksFirst;
        bool startFight;

    public:
        void battle(Player & player, Enemy & enemy);
        void damageDealt(int damageAmount, Player & player, Enemy & enemy);
        int physicalDamangeDealt(int attack, int defense, Player & player, Enemy & enemy);
        int physicalDamageReceive(int attack, int defense, Player & player, Enemy & enemy);
        int magicDamageDealt(int magicAttack, int magicDefense, Player & player, Enemy & enemy);
        int magicDamageReceived(int magicAttack, int magicDefense, Player & player, Enemy & enemy);
        void randomEncounters();
        int numberOfEnemies(int enemyCount);
        bool canStartBattle(Player & player, Enemy & enemy, int Enemy.numberOfEnemies);
        bool inBattle();
        bool endOfBattle(Money & playerMOney);
        std::vector<battler>& getEnemies();
        void turnOrder();
};

#endif