#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>

#include "setupdialog.h"
#include "tile.h"
#include "player.h"
#include "chute.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void setupFinished();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setCurrPlayer(Player *p);
    void movePlayer(Player *p, int roll);
    void addPlayerHelper();

    int getNumPlayers(){
        return static_cast<int>(player_v_.size());
    }

    void addChuteHelper();

private slots:
    void on_butt_roll_released();
    void on_butt_newGame_clicked();
    void on_butt_quitGame_clicked();
    void on_butt_Undo_clicked();
    void on_butt_Reroll_clicked();
    void on_butt_acceptMove_clicked();

private:
    Ui::MainWindow *ui;           // pointer to ui
    SetupDialog *setupdialog;     // pointer to dialog UI
    QGraphicsScene *scene;        // pointer to graphics scene
    QGraphicsView *view;

    Tile *tileArr_[10][10];
    int tile_WH;

    QVector<Player*> player_v_;
    QVector<QString> playerNames_;
    Player *currPlayer_;
    int currPlayer_index_;

    bool hasRoll_ = true;
    bool hasUndo_ = false;
    bool hasReroll_ = false;
    bool setupDone_ = false;
};
#endif // MAINWINDOW_H
