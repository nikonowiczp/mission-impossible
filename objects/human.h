#ifndef HUMAN_H
#define HUMAN_H

#include "movable.h"
#include <cmath>

///
/// \brief The Human class is a class Derived from Movable class.
/// 
/// The Human class is used to represent the human in the game
/// The human is an object that will move around the map and try to find the monster.
class Human: public Movable
{
public:
    ///
    /// Human constructor.
    /// @param mediator  Shared pointer to GameStateMediator class, the mediator of the game.
    /// @param location  Unique pointer to Point class, the starting location of the human.
    /// @param id        Integer, the id of the human.
    Human(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point>, int);

    /// OnGameTick is a function that is called every game tick.
    /// It is responsible for moving the human around the map. 
    void OnGameTick() override;
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

    int ticksFromLastEvent = 0;
    int skew = 0;
    std::unique_ptr<Point> currentGoal;
};

#endif // HUMAN_H
