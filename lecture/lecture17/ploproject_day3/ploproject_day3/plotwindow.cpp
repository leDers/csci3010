#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QTime>

#include "plotwindow.h"
#include "ui_plotwindow.h"
#include "point.h"

// Name:
//
//

PlotWindow::PlotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotWindow)
{
    // we need to set up the ui before we draw on our scene
    ui->setupUi(this);

    // the QGraphicsView is the UI element that contains the
    // scene that we will actually get to draw on.
    QGraphicsView * view = ui->plotGraphicsView;

    // scene is a QGraphicsScene pointer field of the PlotWindow class
    // this makes our lives easier by letting us easily access it
    // from other functions in this class.
    scene = new QGraphicsScene;
    view->setScene(scene);
    // make the scene the same size as the view containing it
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());

    // we'll want to generate random numbers later so we're
    // going to seed our random number generator once
    srand(static_cast<unsigned>(QTime::currentTime().msec()));


    qDebug() << "Here's an example debugging statement";

    // Calculate the mid points
    int x_mid = view->frameSize().height() / 2;
    int y_mid = view->frameSize().width() / 2;
    // draw the axes
    // this is the horizontal line
    scene->addLine(0, x_mid, view->frameSize().width(), x_mid);
    // this is the vertical line
    scene->addLine(y_mid, 0, y_mid, view->frameSize().height());

    connect(ui->randomButton, &QAbstractButton::pressed, this, &PlotWindow::SlotTest);

    // equations to calculate adjusted coordinates
    //int x_adj = x + (ui->plotGraphicsView->frameSize().width() / 2);
    //int y_adj = (-1 * y + (ui->plotGraphicsView->frameSize().height() / 2));


    // Slots & signals
    // 1) default signal + default slot (on_randomButton_clicked)
    // 2) default signal + custom slot (SlotTest)
    //      make sure to connect the signal to the slot
    // 3) custom signal + custom slot
    //      define the signal & the slot (matching parameters)
    //      emit the signal
    //      connect the signal to the slot
    // the sender is a point, so wherever you are instantiating points (not within the Point constructor)
    // is where you want to call connect

    // instantiate a color and a point
    QColor color(255,0,0);
    Point * p = new Point(color, 10, 20);
    // add it to the scene
    scene->addItem(p);
    // connect the custom signal to the custom slot
    connect(p, &Point::PointSelected, this, &PlotWindow::PointSelectedSlot);

    // instantiate a color and a point
    QColor color2(255,0,255);
    // adjust for the width as well to make it appear at the origin
    int x_adj = 0 + (ui->plotGraphicsView->frameSize().width() / 2) - (Point::get_width() / 2);
    int y_adj = (-1 * 0 + (ui->plotGraphicsView->frameSize().height() / 2)) - (Point::get_width() / 2);
    Point * p2 = new Point(color2, x_adj, y_adj);
    // add it to the scene
    scene->addItem(p2);
    // connect the custom signal to the custom slot
    connect(p2, &Point::PointSelected, this, &PlotWindow::PointSelectedSlot);

    // needs to be "clicked" and not "click" to be a signal!
    connect(ui->addButton, &QAbstractButton::clicked, this, &PlotWindow::AddPoint);
}

void PlotWindow::AddHelper() {
   bool safe = false;
   int x = ui->xCoord->text().toInt(&safe);
   if (!safe) {
       return;
   }
   // do the same thing for the y coordinate
   int y = ui->yCoord->text().toInt(&safe);
   if (!safe) {
       return;
   }

   // then create your point and add it to the scene!
   QColor c(0, 0, 155);
   int x_adj = x + (ui->plotGraphicsView->frameSize().width() / 2);
   // account for the width of the point
   x_adj = x_adj - Point::get_width() / 2;
   int y_adj = (-1 * y + (ui->plotGraphicsView->frameSize().height() / 2));
   // account for the height of the point (which is the same as the width because it's a circle)
   y_adj = y_adj - Point::get_width() / 2;
   Point * p = new Point(c, x_adj, y_adj);
   scene->addItem(p);
}

// (option 1, default slot)
//void PlotWindow::on_addButton_clicked() {
//    this->AddHelper();
//}

// (option 2, custom slot) -> you can see the connect statement in the constructor
void PlotWindow::AddPoint() {
    this->AddHelper();
}

void PlotWindow::SlotTest() {
    qDebug() << "random button pressed custom slot!";
}



PlotWindow::~PlotWindow()
{
    delete ui;
}

void PlotWindow::on_randomButton_clicked()
{
    qDebug() << "random button clicked default slot!";
}

// Day 3, task 2, step 2
// Modify this slot to display the coordinates under the Point 1 Label when the user right-clicks on the point
// you can use the setText() method for labels that takes in QString as a parameter

// Day 3, task 2, step 3
// Now display the coordinates under the Point 2 label and then display the distance in the distance label
// You may need to track some information across calls to this slot.
// Hint: Using additional field(s) may help you accomplish this task
//void PlotWindow::PointSelectedSlot(int x, int y) {
//    qDebug() << x << ":" << y;
//}

void PlotWindow::PointSelectedSlot(Point * p) {
    // point info
    qDebug() << p->get_x() << ":" << p->get_y();

    // point pointers;
    prev_point_ = curr_point_;
    curr_point_ = p;

    // point 1
    if (curr_point_ != nullptr){
        std::string s1 = "Point 1: (" + std::to_string(curr_point_->get_x()) + ", " + std::to_string(curr_point_->get_y()) + ")";
        QString qs1(s1.c_str());
        ui->point1Label->setText(qs1);
        this->update();
    }

    // point 2
    if (prev_point_ != nullptr){
        std::string s2 = "Point 2: (" + std::to_string(prev_point_->get_x()) + ", " + std::to_string(prev_point_->get_y()) + ")";
        QString qs2(s2.c_str());
        ui->point2Label->setText(qs2);
        this->update();
    }

    // distance
    if (curr_point_ && prev_point_){
        std::string s3 = std::to_string(curr_point_->Distance(*prev_point_));
        QString qs3(s3.c_str());
        ui->distanceLabel->setText(qs3);
        this->update();
    }

}

// Day 3, Task 3, Step 2
// In the slot (default or custom) add code to flip the value in the delete_mode_ boolean
// Add code to change the cursor when the user is in delete_mode_
    // you can use ui->centralWidget->setCursor() method for this
// Remember to change it back when the user is no longer in delete mode
