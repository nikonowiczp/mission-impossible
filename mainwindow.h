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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::unique_ptr<GameManager>, std::unique_ptr<ILogHandler>, QWidget *_parent = nullptr);
    ~MainWindow();
public slots:
    void DoTick();
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
