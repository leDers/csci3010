/********************************************************************************
** Form generated from reading UI file 'plotwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTWINDOW_H
#define UI_PLOTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlotWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *plotGraphicsView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *yLabel;
    QLineEdit *xCoord;
    QLabel *xLabel;
    QLineEdit *yCoord;
    QPushButton *addButton;
    QPushButton *deletePoints;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *point1Label;
    QLabel *point2Label;
    QLabel *distanceLabel;
    QPushButton *randomButton;
    QMenuBar *menuBar;
    QMenu *menuPoint_Grapher;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PlotWindow)
    {
        if (PlotWindow->objectName().isEmpty())
            PlotWindow->setObjectName("PlotWindow");
        PlotWindow->resize(586, 469);
        centralWidget = new QWidget(PlotWindow);
        centralWidget->setObjectName("centralWidget");
        plotGraphicsView = new QGraphicsView(centralWidget);
        plotGraphicsView->setObjectName("plotGraphicsView");
        plotGraphicsView->setGeometry(QRect(160, 50, 401, 341));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 561, 35));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        yLabel = new QLabel(layoutWidget);
        yLabel->setObjectName("yLabel");

        horizontalLayout->addWidget(yLabel);

        xCoord = new QLineEdit(layoutWidget);
        xCoord->setObjectName("xCoord");

        horizontalLayout->addWidget(xCoord);

        xLabel = new QLabel(layoutWidget);
        xLabel->setObjectName("xLabel");

        horizontalLayout->addWidget(xLabel);

        yCoord = new QLineEdit(layoutWidget);
        yCoord->setObjectName("yCoord");

        horizontalLayout->addWidget(yCoord);


        horizontalLayout_2->addLayout(horizontalLayout);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName("addButton");

        horizontalLayout_2->addWidget(addButton);

        deletePoints = new QPushButton(layoutWidget);
        deletePoints->setObjectName("deletePoints");

        horizontalLayout_2->addWidget(deletePoints);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 60, 141, 66));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        point1Label = new QLabel(layoutWidget1);
        point1Label->setObjectName("point1Label");

        verticalLayout->addWidget(point1Label);

        point2Label = new QLabel(layoutWidget1);
        point2Label->setObjectName("point2Label");

        verticalLayout->addWidget(point2Label);

        distanceLabel = new QLabel(layoutWidget1);
        distanceLabel->setObjectName("distanceLabel");

        verticalLayout->addWidget(distanceLabel);

        randomButton = new QPushButton(centralWidget);
        randomButton->setObjectName("randomButton");
        randomButton->setGeometry(QRect(10, 290, 137, 25));
        PlotWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PlotWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 586, 22));
        menuPoint_Grapher = new QMenu(menuBar);
        menuPoint_Grapher->setObjectName("menuPoint_Grapher");
        PlotWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PlotWindow);
        mainToolBar->setObjectName("mainToolBar");
        PlotWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PlotWindow);
        statusBar->setObjectName("statusBar");
        PlotWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPoint_Grapher->menuAction());

        retranslateUi(PlotWindow);

        QMetaObject::connectSlotsByName(PlotWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlotWindow)
    {
        PlotWindow->setWindowTitle(QCoreApplication::translate("PlotWindow", "PlotWindow", nullptr));
        yLabel->setText(QCoreApplication::translate("PlotWindow", "x:", nullptr));
        xLabel->setText(QCoreApplication::translate("PlotWindow", "y:", nullptr));
        addButton->setText(QCoreApplication::translate("PlotWindow", "Add Point", nullptr));
        deletePoints->setText(QCoreApplication::translate("PlotWindow", "Delete Points", nullptr));
        point1Label->setText(QCoreApplication::translate("PlotWindow", "Point 1:", nullptr));
        point2Label->setText(QCoreApplication::translate("PlotWindow", "Point 2:", nullptr));
        distanceLabel->setText(QCoreApplication::translate("PlotWindow", "Distance:", nullptr));
        randomButton->setText(QCoreApplication::translate("PlotWindow", "Random Button", nullptr));
        menuPoint_Grapher->setTitle(QCoreApplication::translate("PlotWindow", "Point Grapher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlotWindow: public Ui_PlotWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTWINDOW_H
