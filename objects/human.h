#ifndef HUMAN_H
#define HUMAN_H

#include "movable.h"
#include <cmath>

class Human: public Movable
{
public:
    Human(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point>, int);

    // BaseObject interface
public:
    void OnGameTick();
private:
    enum State{
        Scouting = 0,
        PursuingFar,
        PursuingClose
    };
    State currentState = Scouting;
    int currentScoutingAngle = 1* M_PI;

    void doScouting(const std::vector<Positionable*>&);
    void doPursueFar(const std::vector<Positionable*>&);
    void doPursueClose(const std::vector<Positionable*>&);

};

#endif // HUMAN_H
