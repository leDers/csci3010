#include "mainwindow.h"
#include "point.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // set view -------------------------
    ui->setupUi(this);
    QGraphicsView *view = ui->graphicsView;

    // set scene ------------------------
    scene = new QGraphicsScene();
    view->setScene(scene);
    // to remove scoll bars... give bottom right and bottom left setscenerect

    // add lines for plot ---------------
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
    // ^^^ lines are bad!!

    // conect button code ----------------
    // connect(ui->Btn, &QAbstractButton::pressed, this, &MainWindow::SlotTest);

    // adding point(s) to ui ----------------
    int x_adj = 0 + view->frameSize().width()/2 - Point::get_width()/2;
    int y_adj = -1 + view->frameSize().height()/2 - Point::get_width()/2;

    QColor color1(255,0,255);
    Point* p1 = new Point(color1,0,0);

    QColor color2(0,255,255);
    Point* p2 = new Point(color2,x_adj,y_adj);

    scene->addItem(p1);
    scene->addItem(p2);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_push_add_clicked()
{
    qDebug()<<"addPoint button clicked";
    // ----------------

    int x_adj = 0 + ui->graphicsView->frameSize().width()/2 - Point::get_width()/2;
    int y_adj = -1 + ui->graphicsView->frameSize().height()/2 - Point::get_width()/2;

    int p_x = ui->input_x->text().toInt();
    int p_y = ui->input_x->text().toInt();

    QColor color_t(125,125,125);
    Point* temp = new Point(color_t, x_adj+p_x, y_adj+p_y);
}


void MainWindow::on_push_add_pressed()
{
    qDebug()<<"addPoint button pressed";

}

