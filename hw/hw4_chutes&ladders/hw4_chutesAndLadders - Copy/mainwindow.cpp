#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "setupdialog.h"
#include "tile.h"            // tile class
#include "player.h"          // player class
#include "chute.h"

#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // setup --------------------------------------------------------------------------
    ui->setupUi(this);

    // the QGraphicsView is the UI element that contains the
    // scene that we will actually get to draw on.
    view = ui->graphicsView;
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create the QGraphicsScene and set it to the graphicsView
    scene = new QGraphicsScene(this);
    view->setScene(scene);
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
    // ---------------------------------------------------------------------------------


//    // tiles --------------------------------------------------------------------------
////    Tile *tile_arr[10][10];
    tile_WH = view->frameSize().height() / 10;
    int gridSize = 10;
    int value = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            y = i * tile_WH;
            x = j * tile_WH;

            if (i%2!=0){
                value = (gridSize-1-i)*gridSize +j+1;
            }
            else{
                value = (gridSize-1-i)*gridSize +(gridSize-1-j)+1;
            }

            tileArr_[i][j] = new Tile(value, x, y, tile_WH);
            scene->addItem(tileArr_[i][j]);
        }
    }
//    // ---------------------------------------------------------------------------------

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCurrPlayer(Player *p){
    currPlayer_ = p;
}

void MainWindow::movePlayer(Player *p, int roll){
    // set values
    p->setPrevValue(p->getCurrValue());
    p->setCurrValue(p->getCurrValue()+roll);

    qDebug() << "prev: "<< p->getPrevValue() << "\tcurr: "<< p->getCurrValue();

    // chage cooridnates
    // check for tile that has matching current value, and set players x,y to that tiles x,y
    int newX = 0;
    int newY = 0;

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if(tileArr_[i][j]->getValue() == p->getCurrValue()){

                newX = tileArr_[i][j]->getX();
                newY = tileArr_[i][j]->getY();

//                qDebug() << "before newY: "<< newY;
//                qDebug() << "before newX: "<< newX;

                // check if tile has chute
                if(tileArr_[i][j]->checkChute()){
                    qDebug() << "Tile: "<< tileArr_[i][j]->getValue() << " has chute";

                    // set newX and newY to end of chute's location
                    Chute *temp = tileArr_[i][j]->getChute();
                    int endPoint = temp->getEnd();

                    if (endPoint > p->getCurrValue()){
                        QMessageBox::information(this, "Title", "Ladder :)!");
                    }
                    if (endPoint < p->getCurrValue()){
                        QMessageBox::information(this, "Title", "Chute :(!");
                    }

                    for (int k = 0; k<10; k++){
                        for (int l=0; l<10; l++){
                            if (tileArr_[k][l]->getValue() == endPoint){
                                newX = tileArr_[k][l]->getX();
                                newY = tileArr_[k][l]->getY();

                                p->setCurrValue(tileArr_[k][l]->getValue());
                            }
                        }
                    }
                }

//                qDebug() << "after newY: "<< newY;
//                qDebug() << "after newX: "<< newX;

                p->setX(newX);
                p->setY(newY);
            }
        }
    }

    update();
}

void MainWindow::on_butt_roll_released()
{
    if (setupDone_ == true && hasRoll_ ){
        ui->label_currPlayer->setText("Current Player: " + currPlayer_->getName());
        ui->label_undoCount->setText("Undo Count: "+ QString::number(currPlayer_->getUndoCount()));
        ui->label_rerollCount->setText("Reroll Count: "+ QString::number(currPlayer_->getRerollCount()));

        // will need to be current player check

        // Roll a 12-sided die
        srand(time(0)); // Seed the random number generator
//        int result = 1; // Generate a random number between 1 and 12
        int result = rand() % 12 + 1; // Generate a random number between 1 and 12
        ui->label_rollValue->setText(QString::number(result));

        qDebug() << "roll result: " << result;
        if (currPlayer_->getCurrValue() + result <= 100){
            // Update the result label

            // move player
            movePlayer(currPlayer_, result);
            hasUndo_ = true;
            hasReroll_ = true;

            ui->label_currPlayer->setText("Current Player: " + currPlayer_->getName());
            ui->label_undoCount->setText("Undo Count: "+ QString::number(currPlayer_->getUndoCount()));
            ui->label_rerollCount->setText("Reroll Count: "+ QString::number(currPlayer_->getRerollCount()));

        }
        else{
            QMessageBox::information(this, "Title", "Can't Move!");
            // change to next player
            currPlayer_index_ = (currPlayer_index_ +1) % getNumPlayers();
            setCurrPlayer(player_v_[currPlayer_index_]);

            ui->label_currPlayer->setText("Current Player: " + currPlayer_->getName());
            ui->label_undoCount->setText("Undo Count: "+ QString::number(currPlayer_->getUndoCount()));
            ui->label_rerollCount->setText("Reroll Count: "+ QString::number(currPlayer_->getRerollCount()));

        }

        hasRoll_ = false;
        hasUndo_ = true;
        hasReroll_ = true;
    }

    if(currPlayer_->getCurrValue() == 100){
        QMessageBox::information(this, "Title", "Game Over!");

    }
}


void MainWindow::on_butt_Undo_clicked()
{
    if (setupDone_ == true && hasUndo_){
        if (currPlayer_->getUndoCount() > 0){
            currPlayer_->useUndo();

            ui->label_undoCount->setText("Undo Count: "+ QString::number(currPlayer_->getUndoCount()));
            ui->label_rerollCount->setText("Reroll Count: "+ QString::number(currPlayer_->getRerollCount()));

            int v = ui->label_rollValue->text().toInt();
            qDebug() << "undo: " << v;
            movePlayer(currPlayer_, -v);
            ui->label_rollValue->setText("undone");

        }

        hasUndo_ = false;
        hasReroll_ = !hasReroll_;
        hasRoll_ = !hasRoll_;
    }
}


void MainWindow::on_butt_newGame_clicked()
{
    setupdialog = new SetupDialog(this);
    setupdialog->show();
    setupDone_ = true;

    int result = setupdialog->exec();

    if (result == QDialog::Accepted){
        qDebug() << "accepted";

        addChuteHelper();
        addPlayerHelper();

        ui->label_currPlayer->setText("Current Player: " + currPlayer_->getName());
        ui->label_undoCount->setText("Undo Count: "+ QString::number(currPlayer_->getUndoCount()));
        ui->label_rerollCount->setText("Reroll Count: "+ QString::number(currPlayer_->getRerollCount()));

    }
}

void MainWindow::addPlayerHelper(){

    qDebug() << "in add player helper";

    qDebug() << "adding player names...";
    for (const QString& string : setupdialog->getPNames()) {
        qDebug() << "player name: "<< string;
        playerNames_.append(string);
    }

    qDebug() << "adding to player vector...";
    int size = static_cast<int>(playerNames_.size());
    for (int p=0; p<size; p++){
        Player* temp = new Player(tile_WH/4, view->frameSize().height()-3*tile_WH/4, 1, tile_WH/2, playerNames_.at(p), p);
        player_v_.append(temp);
    }

    qDebug() << "drawing player...";
    for (Player *p: player_v_){
        scene->addItem(p);
    }

    qDebug() << "setting curr player...";
    setCurrPlayer(player_v_.at(0));
    currPlayer_index_ = 0;
}

void MainWindow::addChuteHelper(){
    qDebug() << "in add chute helper";
    // chutes&ladders ------------------------------------------------------------------
    QVector<int> start_v; // 1 means available
    for (int i = 2; i <= 99; i++) {
        start_v.append(i);
    }

    srand(time(0));

    int maxChutes = 13; // change to 13
    int chute_count = 0;
    int ladder_count = 0;
    Chute *chute_arr[maxChutes];
    for (int i = 0; i < maxChutes; i++){

        int i_index = 0;
        int j_index = 0;

        int start = 1 +rand() % 95;
        int sX = 0;
        int sY = 0;

        int end = 1 +rand() % 95;
        int eX = 0;
        int eY = 0;

        if (ladder_count < chute_count){
            if (start > end){
                int t = start;
                start = end;
                end = t;
            }
        }
        if (ladder_count > chute_count){
            if (start < end){
                int t = start;
                start = end;
                end = t;
            }
        }

        // start is available
//        qDebug() << "1.start: " << start;

        if (start_v.contains(start)){
//            qDebug() << "in IF after 1.start: " << start;
            start_v.replace(start_v.indexOf(start),0);
        }
        // start is not available
        else{
//            qDebug() << "in ELSE after 1.start: " << start;
            while (!start_v.contains(start)){
                start = (start +1) % 95;
//                qDebug() << "re.start: " << start;

            }
            start_v.replace(start_v.indexOf(start),0);
        }

        for (int i = 0; i<10; i++){
            for (int j=0; j <10; j++){
                    if (tileArr_[i][j]->getValue() == start){
                        sX = tileArr_[i][j]->getX() +tile_WH/2;
                        sY = tileArr_[i][j]->getY() +tile_WH/2;

                        i_index = i;
                        j_index = j;
                    }
                    if (tileArr_[i][j]->getValue() == end){
                        eX = tileArr_[i][j]->getX() +tile_WH/2;
                        eY = tileArr_[i][j]->getY() +tile_WH/2;
                    }
            }
        }

        chute_arr[i] = new Chute(start, end);
        tileArr_[i_index][j_index]->setChute(chute_arr[i]);

        if (end < start){
            qDebug() << "chute: " << i;
        }
        if ( start < end ){
            qDebug() << "ladder: " << i;
        }
        qDebug() << "\tstart: " << chute_arr[i]->getStart();
        qDebug() << "\tend: " << chute_arr[i]->getEnd();


        QPen pen; // Creates a QPen object with a red color
        if (start > end){
            pen.setColor(Qt::red);
            chute_count++;
        }
        if (end > start ){
            pen.setColor(Qt::green);
            ladder_count++;
        }
        pen.setWidth(5);
        scene->addLine(sX,sY,eX,eY,pen);
    }
    // ---------------------------------------------------------------------------------
}


void MainWindow::on_butt_quitGame_clicked()
{
    qApp->quit();
}


void MainWindow::on_butt_Reroll_clicked()
{
    if (setupDone_ == true && hasReroll_){
        if (currPlayer_->getRerollCount() > 0){
            currPlayer_->useReroll();

            int v = currPlayer_->getCurrValue() - currPlayer_->getPrevValue();
            movePlayer(currPlayer_, -v);

            srand(time(0)); // Seed the random number generator
            int result = rand() % 12 + 1; // Generate a random number between 1 and 12

            // Update the result label
            ui->label_rollValue->setText(QString::number(result));
            ui->label_undoCount->setText("Undo Count: "+ QString::number(currPlayer_->getUndoCount()));
            ui->label_rerollCount->setText("Reroll Count: "+ QString::number(currPlayer_->getRerollCount()));

            // move player
            movePlayer(currPlayer_, result);
            hasUndo_ = true;
        }
        else{
            hasReroll_= false;
        }

        hasUndo_ = true;
        hasRoll_ = false;
    }
}

void MainWindow::on_butt_acceptMove_clicked()
{
    if (!hasRoll_){
        // change to next player
        currPlayer_index_ = (currPlayer_index_ +1) % getNumPlayers();
        setCurrPlayer(player_v_[currPlayer_index_]);
        ui->label_rollValue->setText("");
        ui->label_currPlayer->setText("Current Player: " + currPlayer_->getName());
        ui->label_undoCount->setText("Undo Count: "+ QString::number(currPlayer_->getUndoCount()));
        ui->label_rerollCount->setText("Reroll Count: "+ QString::number(currPlayer_->getRerollCount()));

        hasRoll_ = true;
        hasReroll_ = false;
        hasUndo_ = false;
    }

}

