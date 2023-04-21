/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *butt_newGame;
    QPushButton *butt_endGame;
    QPushButton *butt_Save;
    QPushButton *butt_quitGame;
    QPushButton *butt_Undo;
    QPushButton *butt_Reroll;
    QPushButton *butt_roll;
    QLabel *label_rollValue;
    QLabel *label_currPlayer;
    QLabel *label_timeLeft;
    QLabel *label_rollValue_2;
    QLabel *label_undoCount;
    QLabel *label_rerollCount;
    QPushButton *butt_acceptMove;
    QGraphicsView *graphicsView_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(510, 462);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(25, 21, 350, 350));
        butt_newGame = new QPushButton(centralwidget);
        butt_newGame->setObjectName("butt_newGame");
        butt_newGame->setGeometry(QRect(390, 20, 80, 24));
        butt_endGame = new QPushButton(centralwidget);
        butt_endGame->setObjectName("butt_endGame");
        butt_endGame->setGeometry(QRect(390, 50, 80, 24));
        butt_Save = new QPushButton(centralwidget);
        butt_Save->setObjectName("butt_Save");
        butt_Save->setGeometry(QRect(390, 80, 80, 24));
        butt_quitGame = new QPushButton(centralwidget);
        butt_quitGame->setObjectName("butt_quitGame");
        butt_quitGame->setGeometry(QRect(390, 380, 80, 24));
        butt_Undo = new QPushButton(centralwidget);
        butt_Undo->setObjectName("butt_Undo");
        butt_Undo->setGeometry(QRect(390, 160, 80, 24));
        butt_Reroll = new QPushButton(centralwidget);
        butt_Reroll->setObjectName("butt_Reroll");
        butt_Reroll->setGeometry(QRect(390, 190, 80, 24));
        butt_roll = new QPushButton(centralwidget);
        butt_roll->setObjectName("butt_roll");
        butt_roll->setGeometry(QRect(390, 220, 80, 24));
        label_rollValue = new QLabel(centralwidget);
        label_rollValue->setObjectName("label_rollValue");
        label_rollValue->setGeometry(QRect(470, 290, 81, 16));
        label_currPlayer = new QLabel(centralwidget);
        label_currPlayer->setObjectName("label_currPlayer");
        label_currPlayer->setGeometry(QRect(390, 110, 101, 16));
        label_timeLeft = new QLabel(centralwidget);
        label_timeLeft->setObjectName("label_timeLeft");
        label_timeLeft->setGeometry(QRect(390, 130, 91, 16));
        label_rollValue_2 = new QLabel(centralwidget);
        label_rollValue_2->setObjectName("label_rollValue_2");
        label_rollValue_2->setGeometry(QRect(390, 300, 81, 16));
        label_undoCount = new QLabel(centralwidget);
        label_undoCount->setObjectName("label_undoCount");
        label_undoCount->setGeometry(QRect(390, 320, 111, 16));
        label_rerollCount = new QLabel(centralwidget);
        label_rerollCount->setObjectName("label_rerollCount");
        label_rerollCount->setGeometry(QRect(390, 340, 111, 16));
        butt_acceptMove = new QPushButton(centralwidget);
        butt_acceptMove->setObjectName("butt_acceptMove");
        butt_acceptMove->setGeometry(QRect(390, 250, 80, 24));
        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName("graphicsView_2");
        graphicsView_2->setGeometry(QRect(25, 380, 151, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 510, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        butt_newGame->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        butt_endGame->setText(QCoreApplication::translate("MainWindow", "End Game", nullptr));
        butt_Save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        butt_quitGame->setText(QCoreApplication::translate("MainWindow", "Quit Game", nullptr));
        butt_Undo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        butt_Reroll->setText(QCoreApplication::translate("MainWindow", "Re-roll", nullptr));
        butt_roll->setText(QCoreApplication::translate("MainWindow", "Roll", nullptr));
        label_rollValue->setText(QString());
        label_currPlayer->setText(QCoreApplication::translate("MainWindow", "Current Player: ", nullptr));
        label_timeLeft->setText(QCoreApplication::translate("MainWindow", "Time Left: ", nullptr));
        label_rollValue_2->setText(QCoreApplication::translate("MainWindow", "Roll Value:", nullptr));
        label_undoCount->setText(QCoreApplication::translate("MainWindow", "Undos Left: ", nullptr));
        label_rerollCount->setText(QCoreApplication::translate("MainWindow", "Rerolls Left: ", nullptr));
        butt_acceptMove->setText(QCoreApplication::translate("MainWindow", "Accept Move", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
