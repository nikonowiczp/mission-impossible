#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "objects/positionable.h"
#include "sprites/customgraphicsitem.h"
#include <map>
#include <QGraphicsView>
#include <QKeyEvent>
#include <memory>

///
/// \brief The GameView class used to show the game view.
///
/// The GameView class derives from QGraphicsView class and is used to render the map in the game.
class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    ///
    /// Basic GameView constructor.
    /// @param _parent  Pointer to QWidget parent.
    GameView(QWidget *_parent = nullptr);

    ///
    /// Member used to clear the view after the game is over.
    void ClearGame();

    ///
    /// Member used to render the initial state of the map.
    /// @param _objects Objects to be rendered on the map.
    /// @param _monster Player object to be rendered on the map.
    /// @param _width   Width of the scene.
    /// @param _height  Height of the scene.
    void StartGame(std::vector<Positionable *> _objects, Monster* _monster, int _width, int _height);

    ///
    /// Member used to render the map on every QTimer tick.
    /// @param _objects Objects to be rendered on the map.
    /// @param _monster Player object to be rendered on the map.
    void DoTick(std::vector<Positionable *> _objects, Monster* _monster);

    ///
    /// Member used to get the state of the keys that are currently clicked.
    /// 1000 - W clicked
    /// 0100 - A clicked
    /// 0010 - S clicked
    /// 0001 - D clicked
    /// @return Keys State as an int that can be mapped to binary.
    int GetKeysState();

signals:
    ///
    /// Public signal emitted when the Esc button is pressed.
    void EscPressed();
protected:
    ///
    /// Protected signal emitted when any key is pressed. Overriden from the QGraphicsView object.
    /// @param _event   Event emitted when the key is pressed as a pointer.
    void keyPressEvent(QKeyEvent *_event) override;

    ///
    /// Protected signal emitted when any key is released. Overriden from the QGraphicsView object.
    /// @param _event   Event emitted when the key is released as a pointer.
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
