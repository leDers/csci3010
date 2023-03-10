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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *input_x;
    QTextEdit *input_y;
    QPushButton *push_add;
    QPushButton *push_delete;
    QPushButton *push_change;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QLabel *lab_p1xy;
    QLabel *lab_p2xy;
    QLabel *lab_distance;
    QMenuBar *menubar;
    QMenu *menulec15_demo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 5, 631, 342));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        input_x = new QTextEdit(verticalLayoutWidget_2);
        input_x->setObjectName("input_x");

        verticalLayout->addWidget(input_x);

        input_y = new QTextEdit(verticalLayoutWidget_2);
        input_y->setObjectName("input_y");

        verticalLayout->addWidget(input_y);

        push_add = new QPushButton(verticalLayoutWidget_2);
        push_add->setObjectName("push_add");

        verticalLayout->addWidget(push_add);

        push_delete = new QPushButton(verticalLayoutWidget_2);
        push_delete->setObjectName("push_delete");

        verticalLayout->addWidget(push_delete);

        push_change = new QPushButton(verticalLayoutWidget_2);
        push_change->setObjectName("push_change");

        verticalLayout->addWidget(push_change);


        horizontalLayout_2->addLayout(verticalLayout);

        graphicsView = new QGraphicsView(verticalLayoutWidget_2);
        graphicsView->setObjectName("graphicsView");

        horizontalLayout_2->addWidget(graphicsView);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lab_p1xy = new QLabel(verticalLayoutWidget_2);
        lab_p1xy->setObjectName("lab_p1xy");

        horizontalLayout->addWidget(lab_p1xy);

        lab_p2xy = new QLabel(verticalLayoutWidget_2);
        lab_p2xy->setObjectName("lab_p2xy");

        horizontalLayout->addWidget(lab_p2xy);

        lab_distance = new QLabel(verticalLayoutWidget_2);
        lab_distance->setObjectName("lab_distance");

        horizontalLayout->addWidget(lab_distance);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menulec15_demo = new QMenu(menubar);
        menulec15_demo->setObjectName("menulec15_demo");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menulec15_demo->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        input_x->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">x-coordinate</p></body></html>", nullptr));
        input_y->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">y-coordinate</p></body></html>", nullptr));
        push_add->setText(QCoreApplication::translate("MainWindow", "addPoint", nullptr));
        push_delete->setText(QCoreApplication::translate("MainWindow", "deletePoint", nullptr));
        push_change->setText(QCoreApplication::translate("MainWindow", "changeColor", nullptr));
        lab_p1xy->setText(QCoreApplication::translate("MainWindow", "point1 coordinate:", nullptr));
        lab_p2xy->setText(QCoreApplication::translate("MainWindow", "point2 coordinate:", nullptr));
        lab_distance->setText(QCoreApplication::translate("MainWindow", "distance between: ", nullptr));
        menulec15_demo->setTitle(QCoreApplication::translate("MainWindow", "lec15 demo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
