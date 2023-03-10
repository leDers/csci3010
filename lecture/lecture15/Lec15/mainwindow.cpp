#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // set view
    ui->setupUi(this);
    QGraphicsView *view = ui->graphicsView;

    // set scene
    scene = new QGraphicsScene();
    view->setScene(scene);


    // add lines for plot
    int y_mid = view->height()/2;
    qDebug()<<y_mid << "\n";
    int y_max = view->height();
    qDebug()<<y_max << "\n";
    int x_mid = view->width()/2;
    qDebug()<<x_mid << "\n";
    int x_max = view->width();
    qDebug() << x_max << "\n";
    view->setSceneRect(0,0, x_max, y_max);
    scene->addLine(0, y_mid, x_max, y_mid);
    scene->addLine(x_mid, 0, x_mid, y_max);
    // lines are bad!!
}

MainWindow::~MainWindow()
{
    delete ui;
}

