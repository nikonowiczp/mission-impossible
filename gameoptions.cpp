#include "gameoptions.h"

GameOptions::GameOptions(GameDifficulty difficulty) {
    switch(difficulty){
    case Easy:{
        this->HumanSpeed = 4;
        this->HumanSight = 20;
        this->MonsterSpeed = 8;
        break;
    };
    case Medium:{
        this->HumanSpeed = 5;
        this->HumanSight = 25;
        this->MonsterSpeed = 8;
        break;
    };
    case Hard:{
        this->HumanSpeed = 6;
        this->HumanSight = 30;
        this->MonsterSpeed = 8;
        break;
    }
    }
}

int GameOptions::GetHumanSpeed()
{
    return HumanSpeed;
}

int GameOptions::GetHumanSight()
{
    return HumanSight;
}

int GameOptions::GetMonsterSpeed()
{
    return MonsterSpeed;
}
