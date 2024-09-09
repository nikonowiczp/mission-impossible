#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "objects/positionable.h"
#include <QGraphicsView>

class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    GameView(QWidget *_parent = nullptr);
    void ClearGame();
    void StartGame(std::vector<std::shared_ptr<Positionable>>);
    void Move(std::vector<std::shared_ptr<Positionable>>);
private:

};

#endif // GAMEVIEW_H
