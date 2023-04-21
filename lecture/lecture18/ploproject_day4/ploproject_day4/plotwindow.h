#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "point.h"

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlotWindow(QWidget *parent = 0);
    ~PlotWindow();


private slots:
    // default slot that reacts to random button being clicked
    void on_randomButton_clicked();

    // Day 2, Task 2, option 1 (default slot)
//    void on_addButton_clicked();
    // Day 2, Task 2, option 2 (custom slot)
    void AddPoint();


    // Day 1, Task 5
    // custom slot that we have to connect to a signal
    void SlotTest();

    // Day 2, Task 3
    // the parameters match the parameters of the signal
    void PointSelectedSlot(Point *p);

    // slot for delete btoon clicked
    void on_deletePoints_clicked();

    // slot for deletePoint signal
    void DeletePointSlot(Point *p);

    // drawline Slot
    void DrawLineSlot(Point *p);

private:
    void AddHelper();

    Ui::PlotWindow *ui;

    QGraphicsScene *scene;

    Point *first_point_;

    //Day 3, Task 3, Step 1
    // Add boolean delete_mode_
    // initialize in the constructor of the class
    // add appropriate getters and setters
    bool delete_mode_;
};

#endif // PLOTWINDOW_H
