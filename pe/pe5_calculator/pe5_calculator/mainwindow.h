#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void operandPressed();      // numbers
    void operatorPressed();     // math
    void equalPressed();        // equal sign
    void signChangePressed();   // sign change
    void cPressed();
    void cePressed();
    void squarePressed();
    void rootPressed();
    void recipricolPressed();
    void percentPressed();
    void backPressed();
    void decimalPressed();
};
#endif // MAINWINDOW_H
