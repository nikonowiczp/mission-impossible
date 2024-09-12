#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "iloghandler.h"
#include "gameview.h"
#include "gamemanager.h"
#include "enums/gamemode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

///
/// \brief The MainWindow class derived from QMainWindow class, handling the main window.
///
/// The MainWindow class is used to generate all the UI in the app using QT 6 framework.
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    ///
    /// MainWindow constructor.
    /// @param _manager     Unique pointer to GameManager class, used to manage the logic.
    /// @param _logHandler  Unique pointer to ILogHandler class, used to generate and read logs.
    /// @param _parent      Pointer to the QWidget class, parent of the current widget.
    MainWindow(std::unique_ptr<GameManager> _manager, std::unique_ptr<ILogHandler> _logHandler, QWidget *_parent = nullptr);

    ///
    /// Basic MainWindow destructor.
    ~MainWindow();
public slots:

    ///
    /// Public slot used to handle the ticks when the game is on.
    void DoTick();

    ///
    /// Public slot used to handle esc key click during the game.
    void OnEscDuringGame();
private slots:

    void on_StartButton_clicked();

    void on_RankingButton_clicked();

    void on_ExitButton_clicked();

    void on_DifficultiesBackButton_clicked();

    void on_RankingBackButton_clicked();

    void on_GameOverBackButton_clicked();

    void on_EasyButton_clicked();

    void on_MediumButton_clicked();

    void on_HardButton_clicked();

    void on_GameExitButton_clicked();

    void on_ResumeButton_clicked();

    void on_RestartButton_clicked();

private:
    void startGame(GameMode);
    void gameOver();
    void pause();
    void resume();
    void resizeEvent(QResizeEvent *_event) override;
    Ui::MainWindow *ui;
    GameView *gameView;
    std::unique_ptr<ILogHandler> logHandler;
    std::unique_ptr<GameManager> gameManager;
    QTimer *timer;
    int timeoutCounter = 0;
    uint timeoutDuration = 100;
    GameMode gameMode;
};
#endif // MAINWINDOW_H
