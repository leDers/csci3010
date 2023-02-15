/**
 * @file Game.cpp
 * @author Leif Anders 
 * @brief CSCI 3010 -- Hw1. 
 *        CPP file for game object
 * @version 0.1
 * @date 2023-02-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Game.h"

// SquareType  --- --- --- --- --- --- --- ---

/**
 * @brief this function takes an enumerated squareType and returns it as a string
 * 
 * @param sq -- the enum class of Square type to be stringified
 * @return std::string -- the string equivalent of the square type
 */
std::string SquareTypeStringify(SquareType sq){
    switch (sq){
        case SquareType::Wall: return "\U0001F7E6"; break;            // blue square
        case SquareType::Dots: return "\U0001F7E1"; break;            // yellow circle
        case SquareType::Pacman: return "\U0001F604"; break;          // smiley face 
        case SquareType::Treasure: return "\U0001F344"; break;        // mushroom
        case SquareType::Enemies: return "\U0001F47E"; break;         // alien
        case SquareType::Empty: return "\U000026AA"; break;             // white circle small
        case SquareType::PowerfulPacman: return "\U0001F608"; break;  // steamy nose face 
        case SquareType::Trap: return "\U0001F525"; break;            // fire
        case SquareType::EnemySpecialTreasure: return "\U0001F480"; break; // skull
        default: return "bad tile";      
    } 
}

/**
 * @brief converts int array into squaretype array
 * 
 */
SquareType intToSquare(int x){
    SquareType sq;
    switch(x){
        case 0: sq = SquareType::Wall;  break;
        case 1: sq = SquareType::Dots;  break;
        case 2: sq = SquareType::Pacman;    break;
        case 3: sq = SquareType::Treasure;  break;
        case 4: sq = SquareType::Enemies;   break;
        case 5: sq = SquareType::Empty; break;
        case 6: sq = SquareType::PowerfulPacman;    break;
        case 7: sq = SquareType::Trap;  break;
        case 8: sq = SquareType::EnemySpecialTreasure;  break;
        default: sq = SquareType::Empty; break;     // incase weird stuf just make it empty
    }

    return sq;
}

// Board --- --- --- --- --- --- --- ---

/**
 * @brief Construct a new Board:: Board object
 * 
 */
Board::Board(){
    std::ifstream in_file("board1.txt");
    srand(time(0));
    // create int board
    if (in_file){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){

                in_file >> this->arr2_[i][j];
            }
        }
    }
    else if (!in_file){
        std::cout << "invalid board.txt" << std::endl;
    }

    // convert int board into squareType board
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            
            // fill in array
            int r = rand()%9;   // 10% chance for treasure on non-wall
            if ((this->arr2_[i][j] ==1)  && (r==0)) {   
                this->arr_[i][j] = intToSquare(3); 
            }
            else { 
                this->arr_[i][j] = intToSquare(this->arr2_[i][j]);
            }
        }
    }
}

/**
 * @brief Get the square value object
 * 
 * @param pos -- the position on board to retreive value
 * @return SquareType -- the squretpe that is returned
 */
SquareType Board::get_square_value(Position pos) const{
    return this->arr_[pos.row][pos.col];
}

/**
 * @brief Set the Square Value object at the given position
 * 
 * @param pos -- the position of square that is to be changed
 * @param value -- the valuse to change a square to
 */
void Board::SetSquareValue(Position pos, SquareType value){
    this->arr_[pos.row][pos.col] = value;
}

/**
 * @brief Get the the possible moves that the player obj. can move to
 * 
 * @param p -- pointer for player object
 * @return std::vector<Position> -- the possible positions a player/enemy could move to
 */
std::vector<Position> Board::GetMoves(Player *p){
    std::vector<Position> out;
    Position k = p->get_position(); 
    int i = k.row;
    int j = k.col;

    SquareType x;

    // up
    Position z = {i-1, j};
    x = get_square_value(z);
    if ((x == SquareType::Dots)  || (x == SquareType::Enemies) ||
        (x == SquareType::Empty) ||
        (x == SquareType::Treasure) ) {
            out.push_back(z);
    }

    // right
    z = {i, j+1};
    x = get_square_value(z);
    if ((x == SquareType::Dots)  || (x == SquareType::Enemies) ||
        (x == SquareType::Empty) ||
        (x == SquareType::Treasure) ) {
            out.push_back(z);
    }

    // down
    z = {i+1, j};
    x = get_square_value(z);
    if ((x == SquareType::Dots)  || (x == SquareType::Enemies) ||
        (x == SquareType::Empty) ||
        (x == SquareType::Treasure) ) {
            out.push_back(z);
    }

    // left
    z = {i, j-1};
    x = get_square_value(z);
    if ((x == SquareType::Dots)  || (x == SquareType::Enemies) ||
        (x == SquareType::Empty) ||
        (x == SquareType::Treasure) ) {
            out.push_back(z);
    }
    
    return out;
}

/**
 * @brief Move a player to a new position
 * 
 * @param p -- pointer for the player object
 * @param pos -- new position to move player too
 * @param enemylist -- vector of enemy player pointers
 * @return true -- if move was successful
 * @return false -- if move was failed
 */
bool Board::MovePlayer(Player *p, Position pos, std::vector<Player*> enemylist){
    
    int score_pellet = 1;       // pellet score value
    int score_treasure = 100;   // treasure point value
    int nearby_enemy_index=0;   // determine neaby enemies from list
    for (unsigned long int i=0; i<enemylist.size(); i++){
        if (pos == enemylist[i]->get_position()){
            nearby_enemy_index = i;
        }
    }

    // wall
    if(this->get_square_value(pos) == SquareType::Wall){
        p->incrementMoves();
        return false;
    }

    // Enemy
    if (this->get_square_value(pos) == SquareType::Enemies){    // check for enemy
       if (p->hasTreasure()) {          // if player has trasure and enmy @ pos, enemy dies
            enemylist[nearby_enemy_index]->setIsDead(true);     // kill enemy
            // Player* p = new Player("", false);                  // respawn enemy extra credit
            // enemylist.push_back(p);    
            p->setHasTreasure();                                // lose treasure
       }
       else{
            p->setLives();              // player loses life
            if (p->getLives() == 0){    // if lives are gone, set to dead
                p->setIsDead(true);     // set dead value
            }
        }
    }
    // Trap TODO:

    // Treasure
    if (this->get_square_value(pos) == SquareType::Treasure){   // check for treasure
        p->ChangePoints(score_treasure);                        // modify score
        if (!p->hasTreasure()) { p->setHasTreasure(); }         // set treasure bool
    }

    // Pellet
    if (this->get_square_value(pos) == SquareType::Dots){       // check for pellets
        p->ChangePoints(score_pellet);                          // modify score
    }
    
    // anything else
    this->SetSquareValue(p->get_position(), SquareType::Empty); // set players current tile to empty
    p->SetPosition(pos);                                        // set new pos to player
    
    if (p->hasTreasure()) { this->SetSquareValue(pos, SquareType::PowerfulPacman); }  // set tile @ p.pos_
    else { this->SetSquareValue(pos, SquareType::Pacman); }
    
    // increment moves
    p->incrementMoves();

    return true;

}

/**
 * @brief Move any enemy toa new location
 * 
 * @param p -- pointer for the player object
 * @param pos -- the position to move the enemy to
 * @return true -- if move was successful
 * @return false -- if move was failure
 */
bool Board::MoveEnemy(Player *p, Position pos){

    // check next spot
    if(this->get_square_value(pos) == SquareType::Wall){
        return false;
    }

    if ( this->get_square_value(p->get_position()) == SquareType::Pacman){
        this->SetSquareValue(p->get_position(), SquareType::Pacman); // ghost poops dots
        p->SetPosition(pos);
        return true; 
    }

    if ( this->get_square_value(p->get_position()) == SquareType::PowerfulPacman){
        this->SetSquareValue(p->get_position(), SquareType::PowerfulPacman); // ghost poops dots
        p->SetPosition(pos); 
        return true;
    }

    // leaving
    this->SetSquareValue(p->get_position(), SquareType::Empty); // ghost poops dots
    p->SetPosition(pos);                                       //set position fo ghost
    this->SetSquareValue(pos, SquareType::Enemies);            // change image to ghost

    return true;

}

// Game --- --- --- --- --- --- --- ---

/**
 * @brief Construct a new Game::Game object
 * 
 */
Game::Game(){
    this->board_ = new Board();
    std::vector<Player *> players_;
    this->turn_count_ = 0;
    this->dots_count_ = 0;
    this->GameOver = false;
}

/**
 * @brief Create a new game
 * 
 * @param human -- pointer to human player
 * @param enemylist -- list of enemy players
 * @param enemies   -- number of enemies 
 */
void Game::NewGame(Player *human,std::vector<Player*> &enemylist, const int enemies){
    
    this->players_.push_back(human);    // add human to g->players_
    
    for (int i = 0; i<enemies; i ++){   // add enemies to g->players_
        const std::string name = "enemy_"+std::to_string(i);
        Player* p = new Player(name, false);                  // init enemys
        enemylist.push_back(p);    
        this->board_->SetSquareValue( (enemylist[i]->get_position()), SquareType::Enemies);    // set board value to enemy
    }

   
}

/**
 * @brief Sequence for human player's turn
 * 
 * @param p -- pointer to human player
 * @param enemylist -- vector list of enemy players
 */
void Game::TakeTurn(Player *p, std::vector<Player*> &enemylist){
    //TODO:
    // ask for moves
    
    if (p->hasTreasure()){
        this->getBoard()->SetSquareValue(p->get_position(), SquareType::PowerfulPacman);
    }
    else {
        this->getBoard()->SetSquareValue(p->get_position(), SquareType::Pacman);
    }

    char input = ' ';
    int i = p->get_position().row;
    int j = p->get_position().col;
    Position tp;
    do{
        std::cout << "Enter your move:" << std::endl;
        std::cin >> input;
        input = toupper(input);
        if ( input == 'W' ||
             input == 'D' ||
             input == 'S' ||
             input == 'A') {

            // make move
            if (input == 'W') {
                i =i -1;
                if (i<0){i=0;}
            }
            if (input == 'D') {
                j =j +1;
                if (j>9){j=9;}
            }
            if (input == 'S') {
                i =i +1;
                if (i>9){i=9;}
            }
            if (input == 'A') {
                j =j -1;
                if (j<0){j=0;}
            }

            tp = {i,j};
            // this->setBoard(p,tp, enemylist);
            this->getBoard()->MovePlayer(p, tp, enemylist);
        }
        else{
            std::cout << "Select a valid move" << std::endl;
        }
    } while (   toupper(input) != 'W' &&
                toupper(input) != 'D' &&
                toupper(input) != 'S' &&
                toupper(input) != 'A'
    );
}

/**
 * @brief Sequence for enemy players turn
 * 
 * @param p  -- pointer to enemy player
 */
void Game::TakeTurnEnemy(Player *p, std::vector<Player*> &enemylist){
    srand(time(0));
    int r = rand()%4;

    int i = p->get_position().row;
    int j = p->get_position().col;
    Position tp = {i,j};

    if (r == 0) {
        i =i -1;
        if (i<0){i=0;}
    }
    if (r == 1) {
        j =j +1;
        if (j>9){j=9;}
    }
    if (r == 2) {
        i =i +1;
        if (i>9){i=9;}
    }
    if (r == 3) {
        j =j -1;
        if (j<0){j=0;}
    }
    tp = {i,j};
    this->getBoard()->MoveEnemy(p,tp);

}

/**
 * @brief Checks human players isDead_ status to see if game is over
 * 
 * @param p -- pointer to human player
 * @return true -- if human player isDead_ == true
 * @return false -- if human player isDead == false
 */
bool Game::IsGameOver(Player *p){
    return p->isDead();
}

/**
 * @brief Checks if all pellets are gone from board
 * 
 * @return true -- if all pellets are gone
 * @return false -- if any number of pellets remain
 */
bool Game::CheckifdotsOver(){
    return (this->dots_count_ == 0);
}

/**
 * @brief Generates a report of game statistics
 * 
 * @param p -- pointer to human player
 * @return std::string -- sting info about the game's conditions after it is over
 */
std::string Game::GenerateReport(Player *p){
    //TODO: ALL
    return "Implement repoert generation";
}

/**
 * @brief Has the player create their personalized player obj
 * 
 * @return Player -- user generated player pointer
 */
Player* Game::userCreatePlayer(){
    std::string name;
    std::cout<< "Please Enter Your Name" << std::endl;
    std::cin >> name;
    Player *p = new Player(name, true); // T*t = &T();
    return p;
}

/**
 * @brief get number of enemies
 * 
 * @return int -- user generated enemy count
 */
int Game::numberOfEnemies(){
    int num;
    std::string num_input;
    char selection = ' ';
    bool is_num = true;


    do {
        std::cout<< "Number of Enemies (Between 2 and 10):" << std::endl;
        std::cin >> num_input;

        // input validation
        for (long unsigned int i = 0; i < num_input.length(); i++){
            if (!isdigit(num_input[i])) { is_num = false; }
            else {
                is_num = true;
                num = stoi(num_input);    
            }
        }

        if ((num >= 2) && (num <= 10) && (is_num)) {
            std::cout << "You want to play against \""<< num << "\" enemies?" << std::endl;
            std::cout<< "Yes        Y" << std::endl;
            std::cout<< "No         N" << std::endl;   
            std::cin >> selection;
        }
        else{
            std::cout << "Please enter a valid number" << std::endl;
        }

    }while( toupper(selection) != 'Y');

    return num;
}

/**
 * @brief this function returns the 
 *        pointer board object from this->board_
 * 
 * @return Board* 
 */
Board* Game::getBoard(){
    return this->board_;
}

/**
 * @brief sets board after move
 * 
 * @param p -- pointer to player object
 * @param pos  -- position on board to set
 * @param enemylist -- enemylist
 */
void Game::setBoard(Player *p, Position pos, std::vector<Player*> &enemylist){
    if (p->is_human()) {this->board_->MovePlayer(p,pos,enemylist); }
    else { this->board_->MoveEnemy(p,pos); }
}

/**
 * @brief this function returns a 
 *        player object from teh players_ vector
 * 
 * @param i -- the index of player to recover from
 *             players_[i]
 * @return Player* 
 */
Player* Game::getPlayer(int i){
    return this->players_[i];
}

/**
 * @brief addds an enemy to the enemylist
 * 
 * @param enemy -- enemy to be added
 */
void Game::addToEnemyList(Player* enemy){
	this->players_.push_back(enemy);
}

/**
 * @brief -- this function checks the position of player to 
 *           realtion to enemies to see if a ghost was killed
 * 
 * @param p -- a pointer to the human player
 * @param el -- the list of enemies
 */
void Game::checkKill(Player* p, std::vector<Player*> el){
    for (long unsigned int i=0; i < el.size(); i++){
        if (p->get_position() == el[i]->get_position()){
            this->getBoard()->SetSquareValue(p->get_position(), SquareType::Pacman);     
        }
    }
    
}


/**
 * @brief this function helps print out all the players possible moves
 * 
 * @param p -- the player whose moves we are printing
 * @return std::string -- the ourput string
 */
std::string Game::printMoves(Player *p){
    std::vector<Position> v = this->getBoard()->GetMoves(p);
    std::string out = "";
    long unsigned int x = 4 - v.size();
    for (long unsigned int i = 0; i < v.size(); i++){
        out += "\n" + p->ToRelativePosition(v[i]);
    }
    for(long unsigned int y = 0; y<x; y++){
        out += "\n";
    }

    return out;
}

/**
 * @brief this helper will coun the remaing pellets on the board
 * 
 */
int Game::checkPellets(){
    int pelletCount = 0;
    Position t;

    // iterate all positions
    for (int x=0; x<10; x++){
        for (int y=0; y<10; y++){
            t = {x,y};
            if (this->getBoard()->get_square_value(t) == SquareType::Dots){ 
                pelletCount +=1;
            }
        }
    }

    return pelletCount;
}
