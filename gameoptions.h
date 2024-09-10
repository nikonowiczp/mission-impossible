#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H

enum GameDifficulty{
    Easy = 0,
    Medium = 1,
    Hard = 2
};

///
/// \brief The GameOptions class is used to create and store all options used in game
///
class GameOptions
{
public:
    GameOptions(GameDifficulty);

    int GetHumanSpeed();
    int GetHumanSight();

    int GetMonsterSpeed();

    int GetMapWidth();
    int GetMapHeight();

    int GetHumanAmount();
    int GetTicksForNewHumans();
private:
    int humanSpeed;
    int humanSight;

    int monsterSpeed;

    int mapWidth;
    int mapHeight;

    int ticksForNewHumans;
    int humanAmount;
};

#endif // GAMEOPTIONS_H
