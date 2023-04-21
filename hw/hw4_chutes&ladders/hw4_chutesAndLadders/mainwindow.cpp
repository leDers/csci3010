#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "setupdialog.h"
#include "tile.h"            // tile class
#include "player.h"          // player class
#include "chute.h"

#include <QGraphicsRectItem>
#include <QFile>
#include <algorithm>
#include <QDir>

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

    // player jail
    // the QGraphicsView is the UI element that contains the
    // scene that we will actually get to draw on.
    view2 = ui->graphicsView_2;
    view2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create the QGraphicsScene and set it to the graphicsView
    scene2 = new QGraphicsScene(this);
    view2->setScene(scene2);
    view2->setSceneRect(0,0,view2->frameSize().width(),view2->frameSize().height());
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
    p->useRoll();

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

void MainWindow::on_butt_roll_clicked()
{
    if (setupDone_ == true && hasRoll_ ){
        ui->label_currPlayer->setText("Current Player: " + currPlayer_->getName());
        ui->label_undoCount->setText("Undo Count: "+ QString::number(currPlayer_->getUndoCount()));
        ui->label_rerollCount->setText("Reroll Count: "+ QString::number(currPlayer_->getRerollCount()));

        // will need to be current player check

        // Roll a 12-sided die
        srand(time(0)); // Seed the random number generator
//        int result = 6; // Generate a random number between 1 and 12
        int result = rand() % 12 + 1; // Generate a random number between 1 and 12
        ui->label_rollValue->setText(QString::number(result));

        qDebug() << "roll result: " << result;


        // if 6 or more, jail break
        if (result == 6 && !currPlayer_->getOnboard_()) {
            currPlayer_->setOnBoard();

            // draw to board
            scene2->removeItem(currPlayer_);
            currPlayer_->setX(tile_WH/4);
            currPlayer_->setY(view->frameSize().height()-3*tile_WH/4);
            scene->addItem(currPlayer_);
        }

        hasRoll_ = false;
        hasUndo_ = true;
        hasReroll_ = true;

        if (currPlayer_->getCurrValue() + result <= 100 && currPlayer_->getOnboard_()){
            // Update the result label

            // move player
            movePlayer(currPlayer_, result);
            hasUndo_ = true;
            hasReroll_ = true;

            ui->label_currPlayer->setText("Current Player: " + currPlayer_->getName());
            ui->label_undoCount->setText("Undo Count: "+ QString::number(currPlayer_->getUndoCount()));
            ui->label_rerollCount->setText("Reroll Count: "+ QString::number(currPlayer_->getRerollCount()));

        }
        else if (currPlayer_->getOnboard_()){
            QMessageBox::information(this, "Title", "Can't Move!");
            // change to next player
            currPlayer_index_ = (currPlayer_index_ +1) % getNumPlayers();
            setCurrPlayer(player_v_[currPlayer_index_]);

            ui->label_currPlayer->setText("Current Player: " + currPlayer_->getName());
            ui->label_undoCount->setText("Undo Count: "+ QString::number(currPlayer_->getUndoCount()));
            ui->label_rerollCount->setText("Reroll Count: "+ QString::number(currPlayer_->getRerollCount()));

            hasRoll_ = true;
            hasUndo_ = false;
            hasReroll_ = false;

        }
    }

    if(currPlayer_->getCurrValue() >= 100){
        QMessageBox::information(this, "Title", "Game Over!");

        gameOver();

        qApp->quit();

    }
}

void MainWindow::on_butt_Undo_clicked()
{
    if (setupDone_ == true && hasUndo_ && currPlayer_->getOnboard_()){
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
    // draw to jail
    for (int p=0; p<size; p++){
        Player* temp = new Player(tile_WH/4 + p*tile_WH, view2->frameSize().height()-3*tile_WH/4, 1, tile_WH/2, playerNames_.at(p), p);
//        Player* temp = new Player(tile_WH/4, view->frameSize().height()-3*tile_WH/4, 1, tile_WH/2, playerNames_.at(p), p);

        player_v_.append(temp);
    }

    qDebug() << "drawing player...";
    for (Player *p: player_v_){
        scene2->addItem(p);
//        scene->addItem(p);
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

//    int maxChutes = 13; // change to 13
    int chute_count = 0;
    int ladder_count = 0;
//    Chute *chute_arr[maxChutes];
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

void MainWindow::on_butt_endGame_clicked()
{
    QMessageBox::information(this, "Title", "Ending Game!");
    gameOver();
    qApp->quit();
}

void MainWindow::on_butt_Reroll_clicked()
{
    if (setupDone_ == true && hasReroll_ && currPlayer_->getOnboard_()){
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

void MainWindow::on_butt_quitGame_clicked()
{
    QMessageBox::information(this, "Title", "Quiting..\nThanks For Playing"+ currPlayer_->getName()+"!");

    if(currPlayer_->getOnboard_()){
        scene->removeItem(currPlayer_);
    }
    else {
        scene2->removeItem(currPlayer_);
    }

    player_v_.remove(currPlayer_index_);

//    currPlayer_index_ = (currPlayer_index_ +1) % getNumPlayers();
    setCurrPlayer(player_v_[currPlayer_index_]);

    ui->label_rollValue->setText("");
    ui->label_currPlayer->setText("Current Player: " + currPlayer_->getName());
    ui->label_undoCount->setText("Undo Count: "+ QString::number(currPlayer_->getUndoCount()));
    ui->label_rerollCount->setText("Reroll Count: "+ QString::number(currPlayer_->getRerollCount()));

    hasRoll_ = true;
    hasReroll_ = false;
    hasUndo_ = false;

    if (player_v_.size() < 2){
        QMessageBox::information(this, "Title", "Too few players...\n" + currPlayer_->getName() + " wins!");

        // write to leader boards

        // close game
        gameOver();
        QMessageBox::information(this, "Title", "Closing Game.\nThanks for Playing :)");
        qApp->quit();
    }

}

void MainWindow::gameOver(){
    // write to leader board
    qDebug() << "in game over...";

    QFile file("leaderboard.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream stream(&file);
    stream << currPlayer_->getName() << "," << currPlayer_->getRollCount() << "\n";
    file.close();

    // sort the leader board for up to ten players
    // pull leader board
    qDebug() << "pulling leaders...";
    QVector<Player*> leaderboard;
//    file("leaderboard.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "fileopen...";

        QTextStream in(&file);
        QString header = in.readLine();
        while (!in.atEnd()) {

            QString line = in.readLine();
                       qDebug() << "0";
            QStringList fields = line.split(",");
                       qDebug() << "1";
            Player *obj = new Player();
                       qDebug() << "2";
            obj->setName(fields[0]);
                       qDebug() << "3";
            obj->setRollCount(fields[1].toInt());
                       qDebug() << "4";
            leaderboard.append(obj);
        }
        file.close();
    }

    // sort
    qDebug() << "sorting leaders";
    std::sort(leaderboard.begin(), leaderboard.end(), []( Player* a,  Player* b) {
        return a->getRollCount() < b->getRollCount();
    });

    for (long long var = 0; var < leaderboard.size(); ++var) {
        qDebug() << leaderboard[var]->getName() << "," << leaderboard[var]->getRollCount() << "\n";
    }

    //rewrite the top ten players
    qDebug() << "rewriting leaders...";
//    QFile file("leaderboard.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << "Name,Number_Of_Rolls\n";
//    for (Player* obj : leaderboard) {
//        out << obj->getName() << "," << obj->getRollCount()<<"\n";
//    }
    // only ten players
    for (int i =0; i <10; i++){
        out << leaderboard[i]->getName() << "," << leaderboard[i]->getRollCount() << "\n";
    }
    file.close();

}

void MainWindow::gameOverTest(){
    // write to leader board
    qDebug() << "in game over test";

    // remmber to set your working directory!!
    QFile file("leaderboard.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream(&file);
    stream << "Name,Number_Of_Rolls\n";
    stream << currPlayer_->getName() << "," << currPlayer_->getRollCount() << "\n";
    file.close();

}

void MainWindow::saveGame(){
    //save tiles
    saveTiles();
    //save chutes
    saveChutes();
    //save players
    savePlayers();

    QMessageBox::information(this, "Title", "Game Saved!");
}

void MainWindow::saveTiles(){
//    QFile file("tileState.txt");
//    file.open(QIODevice::WriteOnly | QIODevice::Text);
//    QTextStream out(&file);
//    out << "start,end,\n";
//    for (int i=0; i<10; i++){
//        for (int j=0;j<10;j++){

//        }
//    }
}

void MainWindow::saveChutes(){
    QFile file("chuteState.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << "start,end\n";
    for (Chute* obj : chute_arr) {
        out << obj->getStart() << "," << obj->getEnd() << "\n";
    }
    out << "\n";
}

void MainWindow::savePlayers(){
    QFile file("playerState.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << "x,y,prevValue,currValue,diameter,color,undoCount,rerollCount,rollCount,name,onBoard\n";
    for (Player* obj : player_v_) {
        out << obj->getX() << ","
            << obj->getY() << ","
            << obj->getPrevValue() << ","
            << obj->getCurrValue() << ","
            << obj->getDiameter() << ","
            << obj->getColor() << ","
            << obj->getUndoCount() << ","
            << obj->getRerollCount() << ","
            << obj->getRollCount() << ","
            << obj->getName() << ","
            << obj->getOnboard_() << "\n";
    }

    file.close();
}

void MainWindow::on_butt_Save_clicked()
{
    saveGame();
}


void MainWindow::on_pushButton_clicked()
{
    loadGame();
}

void MainWindow::loadGame(){
    loadPlayers();
    loadChutes();

    // draw
    // players
    for (auto p: player_v_){
        if (p->getOnboard_()){
            scene->addItem(p);
        }
        else{
            scene2->addItem(p);
        }
    }
    setCurrPlayer(player_v_[0]);

    // chutes

    for(int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            QPen pen; // Creates a QPen object with a red color
            int sX = 0;
            int sY = 0;
            int eX = 0;
            int eY = 0;
            for (int k=0; k<maxChutes; k++){
                if (tileArr_[i][j]->getValue() == chute_arr[k]->getStart()){
                    tileArr_[i][j]->setChute(chute_arr[k]);

                    if (chute_arr[k]->getStart() > chute_arr[k]->getEnd()){
                        pen.setColor(Qt::red);
                    }
                    if (chute_arr[k]->getEnd() > chute_arr[k]->getStart() ){
                        pen.setColor(Qt::green);
                    }

                    sX = tileArr_[i][j]->getX() +tile_WH/2;
                    sY = tileArr_[i][j]->getY() +tile_WH/2;

                }

                if (tileArr_[i][j]->getValue() == chute_arr[k]->getEnd()){
                    eX = tileArr_[i][j]->getX() +tile_WH/2;
                    eY = tileArr_[i][j]->getY() +tile_WH/2;
                }

                pen.setWidth(5);
                scene->addLine(sX,sY,eX,eY,pen);
            }
        }
    }
}

void MainWindow::loadPlayers(){
    player_v_.clear();
    QString filename = "playerState.txt";
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString header = in.readLine();

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() != 11) {
                qDebug() << "Invalid line: " << line;
                continue;
            }
            qDebug() << "parsing player";
            Player* p = new Player();
            p->setX(fields[0].toInt());
            p->setY(fields[1].toInt());
            p->setPrevValue(fields[2].toInt());
            p->setCurrValue(fields[3].toInt());
            p->setDiameter(fields[4].toInt());
            p->setColor(fields[5].toInt());
            p->setUndo(fields[6].toInt());
            p->setReroll(fields[7].toInt());
            p->setRollCount(fields[8].toInt());
            p->setName(fields[9]);
            p->writeOnBoard(fields[10].toInt());

            // Do something with the person object
            qDebug() << "player appending...";
            player_v_.append(p);
            qDebug() << "player appended";
        }
        file.close();
    } else {
        qDebug() << "Error opening file" << filename << ":" << file.errorString();
    }

}

void MainWindow::loadChutes(){

    for (int i = 0; i < 10; i++) {
        chute_arr[i] = nullptr;
    }

    QString filename = "chuteState.txt";
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString header = in.readLine();

        while (!in.atEnd()) {

            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() != 2) {
                qDebug() << "Invalid line: " << line;
                continue;
            }

            for (int i=0; i<maxChutes; i++){
                Chute* c = new Chute();
                c->setStart(fields[0].toInt());
                c->setEnd(fields[1].toInt());

                chute_arr[i] = c;
            }
        }
        file.close();
    } else {
        qDebug() << "Error opening file" << filename << ":" << file.errorString();
    }
}

