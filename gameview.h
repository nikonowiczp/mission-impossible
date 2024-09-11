#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "objects/positionable.h"
#include "sprites/customgraphicsitem.h"
#include <map>
#include <QGraphicsView>
#include <QKeyEvent>
#include <memory>

class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    GameView(QWidget *_parent = nullptr);
    void ClearGame();
    void StartGame(std::vector<Positionable *>, Monster*, int, int);
    void DoTick(std::vector<Positionable *>, Monster*);
    int GetKeysState();
signals:
    void EscPressed();
protected:
    void keyPressEvent(QKeyEvent *_event) override;
    void keyReleaseEvent(QKeyEvent *_event) override;
private:
    void addObject(Positionable *);
    void addObject(std::string, int, int, int, int);
    void addMonster(Monster*);
    int keysState = 0;
    int playerId = 0;
    std::map<int, CustomGraphicsItem*> objects = {};
    std::string humanAssetPath = ":/assets/person.png";
    std::string monsterAssetPath = ":/assets/monster.png";
    std::vector<std::string> obstaclePaths = {
        ":/assets/rock1.png",
        ":/assets/rock2.png",
        ":/assets/rock3.png",
        ":/assets/rock4.png",
    };
};

#endif // GAMEVIEW_H
