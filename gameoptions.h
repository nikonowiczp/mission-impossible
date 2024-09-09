#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H

enum GameDifficulty{
    Easy = 0,
    Medium = 1,
    Hard = 2
};

class GameOptions
{
public:
    GameOptions(GameDifficulty);

    int GetHumanSpeed();
    int GetHumanSight();

    int GetMonsterSpeed();
private:
    int HumanSpeed;
    int HumanSight;

    int MonsterSpeed;

};

#endif // GAMEOPTIONS_H
