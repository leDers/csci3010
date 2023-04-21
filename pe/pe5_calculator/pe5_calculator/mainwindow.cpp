#include "mainwindow.h"
#include "ui_mainwindow.h"

// track current value
double curr_val = 0.0;

// triggers for operator press
bool divTrig = false;
bool multTrig = false;
bool addTrig = false;
bool subTrig = false;

// constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set init display value
    ui->display->setText(QString::number(curr_val));

    // assign signal and slot for buttons
    QPushButton *numButtons[10];
    for (int i = 0; i < 10; ++i){
        QString buttName = "butt_" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(buttName);
        connect(numButtons[i], &QPushButton::released, this, &MainWindow::operandPressed);
    }

    // connect signals and slots for operators
    connect(ui->butt_add, &QPushButton::released, this, &MainWindow::operatorPressed);          // addition
    connect(ui->butt_sub, &QPushButton::released, this, &MainWindow::operatorPressed);          // subtraction
    connect(ui->butt_mult, &QPushButton::released, this, &MainWindow::operatorPressed);         // multiplication
    connect(ui->butt_div, &QPushButton::released, this, &MainWindow::operatorPressed);          // division
    connect(ui->butt_eq, &QPushButton::released, this, &MainWindow::equalPressed);              // equals
    connect(ui->butt_sign, &QPushButton::released, this, &MainWindow::signChangePressed);       // sign change
    connect(ui->butt_clear, &QPushButton::released, this, &MainWindow::cPressed);               // connect C
    connect(ui->butt_CE, &QPushButton::released, this, &MainWindow::cePressed);                 // connect CE
    connect(ui->butt_square, &QPushButton::released, this, &MainWindow::squarePressed);         // square
    connect(ui->butt_sqrt, &QPushButton::released, this, &MainWindow::rootPressed);             // root
    connect(ui->butt_recipricol, &QPushButton::released, this, &MainWindow::recipricolPressed); // recipricol
    connect(ui->butt_percent, &QPushButton::released, this, &MainWindow::percentPressed);       // percent
    connect(ui->butt_backspace, &QPushButton::released, this, &MainWindow::backPressed);        // backspace
    connect(ui->butt_dec, &QPushButton::released, this, &MainWindow::decimalPressed);           // decimal
}

// deconstructor
MainWindow::~MainWindow()
{
    delete ui;
}

// operandPress()
void MainWindow::operandPressed(){
    QPushButton *button = (QPushButton*)sender();   // gives pointer to button pressed
    QString butt_val = button->text();              // get value of button pressed
    QString disp_val = ui->display->text();         // get display value

    //check if curr_val is zero or not
    if ((disp_val.toDouble() == 0) ||  (disp_val.toDouble() == 0.0) || (disp_val == QString("0."))){
        ui->display->setText(butt_val);
        if ( (disp_val == QString("0.")) ){
            ui->display->setText(disp_val+butt_val);
        }
    }
    else{
        QString new_val = disp_val + butt_val;
        double dbl_new = new_val.toDouble();
        ui->display->setText(QString::number(dbl_new, 'g', 16));    // set number of digits before exponents
    }

}

// operatorPressed()
void MainWindow::operatorPressed(){
    // reset triggers
    divTrig = false;
    multTrig = false;
    addTrig = false;
    subTrig = false;

    QString disp_val = ui->display->text(); // get display text value
    curr_val = disp_val.toDouble();         // set current value

    QPushButton *button = (QPushButton*)sender();   // gives pointer to button pressed
    QString butt_val = button->text();              // get value of button pressed

    // check operator type
    if(QString::compare(butt_val, "/", Qt::CaseInsensitive) == 0){
        divTrig = true;
    }
    else if(QString::compare(butt_val, "*", Qt::CaseInsensitive) == 0){
        multTrig = true;
    }
    else if(QString::compare(butt_val, "+", Qt::CaseInsensitive) == 0){
        addTrig = true;
    }
    else {
        subTrig = true;
    }

    // clear display
    ui->display->setText("");
}

// equalPressed()
void MainWindow::equalPressed(){
    double solution = 0.0;

    // get display value
    QString disp_val = ui->display->text();
    double dbl_val = disp_val.toDouble();

    // perform operation
    if (divTrig || multTrig || addTrig || subTrig ){
        if (divTrig){
            solution = curr_val / dbl_val;
            curr_val = solution;
        }
        else if(multTrig){
            solution = curr_val * dbl_val;
            curr_val = solution;
        }
        else if(addTrig){
            solution = curr_val + dbl_val;
            curr_val = solution;
        }
        else {
            solution = curr_val - dbl_val;
            curr_val = solution;
        }
        // update display
        ui->display->setText(QString::number(solution));
    }
    else {
        ui->display->setText(QString::number(dbl_val));
    }
}

// signChangePressed()
void MainWindow::signChangePressed(){
    double solution = 0.0;

    // get display value
    QString disp_val = ui->display->text();
    double dbl_val = disp_val.toDouble();

    // modify
    solution = -1 * dbl_val;

    // update display
    ui->display->setText(QString::number(solution));

}

// cePressed()
void MainWindow::cePressed(){
    // update display
    ui->display->setText(QString(""));
}

// cPressed()
void MainWindow::cPressed(){
    // clear vurr_val
    curr_val = 0.0;

    // update display
    ui->display->setText(QString::number(curr_val));
}

// squarePressed()
void MainWindow::squarePressed(){
    double solution = 0.0;

    // get display value
    QString disp_val = ui->display->text();
    double dbl_val = disp_val.toDouble();

    // modify
    solution = dbl_val * dbl_val;

    // update display
    ui->display->setText(QString::number(solution));
}

// rootPressed()
void MainWindow::rootPressed(){
    double solution = 0.0;

    // get display value
    QString disp_val = ui->display->text();
    double dbl_val = disp_val.toDouble();

    // modify
    solution = sqrt(dbl_val);

    // update display
    ui->display->setText(QString::number(solution));
}

// recipricolPressed()
void MainWindow::recipricolPressed(){
    double solution = 0.0;

    // get display value
    QString disp_val = ui->display->text();
    double dbl_val = disp_val.toDouble();

    // modify
    // if non-zero denom
    if (dbl_val != 0 && dbl_val != 0.0){
        solution = 1 / dbl_val;

        // update display
        ui->display->setText(QString::number(solution));
    }
    // if zero denom
    else {
        QString error = QString("ERROR. Cannot divide by zero!");
        ui->display->setText(error);

    }
}

// percentPressed()
void MainWindow::percentPressed(){
    double solution = 0.0;

    // get display value
    QString disp_val = ui->display->text();
    double dbl_val = disp_val.toDouble();

    // modify
    solution = dbl_val / 100;

    // update display
    ui->display->setText(QString::number(solution));
}

void MainWindow::backPressed(){

    // get display value
    QString disp_val = ui->display->text();
    disp_val.chop(1);

    // update display
    ui->display->setText(disp_val);
}

// decimalPressed()
void MainWindow::decimalPressed(){
    // get display value
    QString disp_val = ui->display->text();

    // update display
    if (disp_val.contains(".", Qt::CaseInsensitive) == false){
        ui->display->setText(disp_val + QString("."));
    }

    if (disp_val == "0" || disp_val == "0.0"){
        ui->display->setText("0.");
    }
}

