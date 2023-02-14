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
#include "Player.h"
#include "Game.h"

bool run_game = true;
char selection = ' ';

int main(){
    Game g = Game();       // create game (board within)
    std::vector<Player*> el;    // enemy list
    Player *p;                  // create player
    int ec;

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
            while( !g.IsGameOver(p) ){
                std::cout << "##############################" << std::endl;
                std::cout << "#######   GAME BOARD   #######" << std::endl;
                std::cout << "##############################" << std::endl;
                std::cout << *g.getBoard();
                std::cout << "##############################" << std::endl;
                std::cout << p->Stringify() << std::endl;
                std::cout << "##############################" << std::endl;
                std::cout << "MOVES:                 ( key )" << g.printMoves(p)<< std::endl;
                std::cout << "##############################" << std::endl;

                // player take turn
                g.TakeTurn(p, el);
                // enemy ake turn
                g.TakeTurnEnemy(p);
            }

            std::cout << "##############################" << std::endl;
            std::cout << "#######   GAME  OVER   #######" << std::endl;
            std::cout << "##############################" << std::endl << std::endl;            
        }

    }while ( toupper(selection) != 'Q' );

    std::cout << "Thanks For Playing!" << std::endl;
    return 0;   // end game
}