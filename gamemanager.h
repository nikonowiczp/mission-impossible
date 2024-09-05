#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <QObject>

struct StartGameParameters{
    int userSpeed = 1;
    int amountHumans = 0;

};

///
/// \brief The GameManager class will create all of the necessary objects to start a game. It will also generate game ticks and be the adapter between ui and game itself
///
class GameManager: public QObject
{
    Q_OBJECT
public:
    GameManager(QObject* parent = nullptr);
    void StartGame(StartGameParameters);
    void EndGame();

};

#endif // GAMEMANAGER_H
