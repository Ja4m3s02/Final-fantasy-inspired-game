#ifndef WORLD_H
#define WORLD_H

class World {
    private:
        bool open_world;
        bool cutscene;
        bool fightscene;
        
    public:
        void enter_open_world();
        void leaving_open_world();
        void enter_cutscene();
        void leaving_custscene();
        void enter_fightscene();
        void leaving_fightscene();
};

#endif