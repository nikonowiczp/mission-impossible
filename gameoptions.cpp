#include "gameoptions.h"
#include <cassert>

GameOptions::GameOptions(GameDifficulty difficulty) {
    switch(difficulty){
    case Easy:{
        this->humanSpeed = 5;
        this->humanSight = 20;
        this->monsterSpeed = 8;
        this->mapHeight = 500;
        this->mapWidth = 500;
        this->ticksForNewHumans = 1000;
        break;
    };
    case Medium:{
        this->humanSpeed = 6;
        this->humanSight = 25;
        this->monsterSpeed = 8;
        this->mapHeight = 400;
        this->mapWidth = 400;
        this->ticksForNewHumans = 800;
        break;
    };
    case Hard:{
        this->humanSpeed = 7;
        this->humanSight = 30;
        this->monsterSpeed = 8;
        this->mapHeight = 300;
        this->mapWidth = 300;
        this->ticksForNewHumans = 600;
        break;
    }
    }

    assert(humanSpeed > 0);
    assert(humanSight > 0);
    assert(monsterSpeed > 0);
    assert(mapHeight > 0);
    assert(mapWidth > 0);
    assert(ticksForNewHumans > 0);
    assert(humanAmount > 0);

}

int GameOptions::GetHumanSpeed()
{
    return humanSpeed;
}

int GameOptions::GetHumanSight()
{
    return humanSight;
}

int GameOptions::GetMonsterSpeed()
{
    return monsterSpeed;
}

int GameOptions::GetMapWidth()
{
    return mapWidth;
}

int GameOptions::GetMapHeight()
{
    return mapHeight;
}

int GameOptions::GetHumanAmount()
{
    return humanAmount;
}

int GameOptions::GetTicksForNewHumans()
{
    return ticksForNewHumans;
}
