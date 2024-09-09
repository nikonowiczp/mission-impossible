#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>

class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    GameView(QWidget *_parent = nullptr);
    void ClearGame();
    void StartGame();
private:

};

#endif // GAMEVIEW_H
