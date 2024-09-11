#ifndef MONSTER_H
#define MONSTER_H

#include "movable.h"
class Monster: public Movable
{
public:
    Monster(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point>, int);


    void OnGameTick(int _userInput);
    // BaseObject interface

    // BaseObject interface
public:
    void OnGameTick() override;
};

#endif // MONSTER_H
