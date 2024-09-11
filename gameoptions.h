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

    int GetHumanSpeed() const;
    int GetHumanSight() const;

    int GetMonsterSpeed() const;

    int GetMapWidth() const;
    int GetMapHeight() const;

    int GetHumanAmount() const;
    int GetObstacleAmount() const;

    int GetTicksForNewHumans() const;
private:
    int humanSpeed;
    int humanSight;

    int monsterSpeed;

    int mapWidth;
    int mapHeight;

    int humanAmount;
    int obstacleAmount;

    int ticksForNewHumans;
};

#endif // GAMEOPTIONS_H
