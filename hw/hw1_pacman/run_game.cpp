/**
 * @file run_game.cpp
 * @author Leif Anders
 * @brief CSCI 3010 -- HW1
 *        main program for pacman game
 * @version 0.1
 * @date 2023-02-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */


// STEP 2
// Improving the game:
// Once the enemy is destroyed by the player, spawn a new enemy at a random
// location on the board.



#include "Player.h"
#include "Game.h"

bool run_game = true;
char selection = ' ';

int main(){
    Game g = Game();       // create game (board within)
    std::vector<Player*> el;    // enemy list
    Player *p;                  // create player
    int ec;
    bool menu_flag = false;

    do{
        // main menu
        std::cout << "##############################" << std::endl;        
        std::cout << "#######    Welcome     #######" << std::endl;
        std::cout << "#######       to       #######" << std::endl;
        std::cout << "#######     PukMan     #######" << std::endl;
        std::cout << "##############################" << std::endl;        
        std::cout << "Play      P" << std::endl;
        std::cout << "Quit      Q" << std::endl;
        std::cin >> selection;

        // PLay game
        if ( toupper(selection) =='P' ){
            p = g.userCreatePlayer();  // create player
            ec = g.numberOfEnemies();  // enemy count
            g.NewGame(p, el, ec);      // create new game

            // game loop time
            while( !g.IsGameOver(p) && (g.checkPellets() != 0) ){

                if (menu_flag){
                    // player take turn
                    g.TakeTurn(p, el);
                    g.checkKill(p,el);
                    // enemy ake turn
                    for (long unsigned int i=0; i<el.size(); i++){
                        g.TakeTurnEnemy(el[i],el);    
                    }
                    g.checkPellets();
                }

                std::cout << "##############################" << std::endl;
                std::cout << "#######   GAME BOARD   #######" << std::endl;
                std::cout << "##############################" << std::endl;
                std::cout << *g.getBoard();
                std::cout << "##############################" << std::endl;
                std::cout << p->Stringify() << std::endl;
                std::cout << "##############################" << std::endl;
                std::cout << "MOVES:                 ( key )" << g.printMoves(p)<< std::endl;
                std::cout << "##############################" << std::endl;

                menu_flag = true;
            }

            if (g.IsGameOver(p)){
                std::cout << "##############################" << std::endl;
                std::cout << "#######   GAME  OVER   #######" << std::endl;
                std::cout << "##############################" << std::endl << std::endl;
            }

            if (g.CheckifdotsOver()){
                std::cout << "##############################" << std::endl;
                std::cout << "#######    YOU  WIN    #######" << std::endl;
                std::cout << "##############################" << std::endl; 
                std::cout << "         Game  Report         " << std::endl;
                std::cout << p->Stringify() <<std::endl;
                std::cout << "##############################" << std::endl;
            }
            g = Game(); // reset game
            menu_flag = false;
            
        }

    }while ( toupper(selection) != 'Q' );

    std::cout << "Thanks For Playing!" << std::endl;
    return 0;   // end game
}