#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "objects/positionable.h"
#include <QGraphicsView>
#include <QKeyEvent>

class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    GameView(QWidget *_parent = nullptr);
    void ClearGame();
    void StartGame(std::vector<std::shared_ptr<Positionable>>);
    void Move(std::vector<std::shared_ptr<Positionable>>);
    int GetKeysState();
signals:
    void EscPressed();
protected:
    void keyPressEvent(QKeyEvent *_event) override;
    void keyReleaseEvent(QKeyEvent *_event) override;
private:
    int keysState = 0;
};

#endif // GAMEVIEW_H
