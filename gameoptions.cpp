#include "gameoptions.h"
#include <cassert>

GameOptions::GameOptions(GameDifficulty difficulty) {
    switch(difficulty){
    case Easy:{
        this->humanSpeed = 12;
        this->humanSight = 300;
        this->monsterSpeed = 20;
        this->mapHeight = 2000;
        this->mapWidth = 2000;
        this->ticksForNewHumans = 1000;
        this->humanAmount = 5;
        this->obstacleAmount = 5;
        break;
    };
    case Medium:{
        this->humanSpeed = 15;
        this->humanSight = 400;
        this->monsterSpeed = 20;
        this->mapHeight = 1500;
        this->mapWidth = 1500;
        this->ticksForNewHumans = 800;
        this->humanAmount = 8;
        this->obstacleAmount = 10;
        break;
    };
    case Hard:{
        this->humanSpeed = 18;
        this->humanSight = 500;
        this->monsterSpeed = 20;
        this->mapHeight = 1000;
        this->mapWidth = 1000;
        this->ticksForNewHumans = 600;
        this->humanAmount = 12;
        this->obstacleAmount = 20;
        break;
    }
    }

    assert(humanSpeed > 0);
    assert(humanSight > 0);
    assert(monsterSpeed > 0);
    assert(mapHeight > 0);
    assert(mapWidth > 0);
    assert(ticksForNewHumans > 0);
    assert(obstacleAmount > 0);
    assert(humanAmount > 0);

}

int GameOptions::GetHumanSpeed() const
{
    return humanSpeed;
}

int GameOptions::GetHumanSight() const
{
    return humanSight;
}

int GameOptions::GetHumanCatch() const
{
    return 80;
}

int GameOptions::GetMonsterSpeed() const
{
    return monsterSpeed;
}

int GameOptions::GetMonsterSight() const
{
    return 200;
}

int GameOptions::GetMapWidth() const
{
    return mapWidth;
}

int GameOptions::GetMapHeight() const
{
    return mapHeight;
}

int GameOptions::GetHumanAmount() const
{
    return humanAmount;
}

int GameOptions::GetObstacleAmount() const
{
    return obstacleAmount;
}

int GameOptions::GetTicksForNewHumans() const
{
    return ticksForNewHumans;
}
