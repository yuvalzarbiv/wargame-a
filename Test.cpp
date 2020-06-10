// #include <string>
// #include <iostream>
// #include "doctest.h"
// #include "Board.hpp"
// #include "FootCommander.hpp"
// #include "SniperCommander.hpp"
// #include "ParamedicCommander.hpp"

// using namespace std;
// using namespace WarGame;


	 //
	// Created by amichai hadad on 28/04/2020.
	//
	#include "doctest.h"
	#include <iostream>
	#include <stdexcept>

	#include "DemoGame.hpp"
	#include "FootSoldier.hpp"
	#include "FootCommander.hpp"
	#include "Sniper.hpp"
	#include "SniperCommander.hpp"
	#include "Paramedic.hpp"
	#include "ParamedicCommander.hpp"
	#include <cassert>

	using namespace WarGame;



// TEST_CASE("Foot soldiers") 
// {

//      Board board(8,8);
    

//     CHECK(!board.has_soldiers(1));
//     board[{0,0}] = new FootSoldier(1);
//     CHECK(board.has_soldiers(1));
//     CHECK(!board.has_soldiers(2));
//     board[{7,0}] = new FootSoldier(2);
//     CHECK(board.has_soldiers(2));

//     board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
//     board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
//     board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
//     board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
//     board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
//     board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
//     board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
//     board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
//     board.move(1, {0,0}, Board::MoveDIR::Up);  // move to {1,0} and shoot; damage 10
//     board.move(1, {1,0}, Board::MoveDIR::Down);  // move back to {0,0} and shoot; damage 10 
//     CHECK(!board.has_soldiers(2));
   
// }

TEST_CASE("Snipers And Paramedics")
 {

     Board board(10,10);
   
    //-----Player 1 soldiers-------//
    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new Paramedic(1);
    CHECK(typeid(board[{0,0}]) == typeid(Paramedic)); //Checks if  a placement of a soldier has occurred
    CHECK(board.has_soldiers(1));
    board[{0,1}] = new Sniper(1);
    CHECK(typeid(board[{0,1}]) == typeid(Sniper)); 
    board[{0,2}] = new Sniper(1);
    CHECK(typeid(board[{0,2}]) == typeid(Sniper)); 
    board[{0,3}] = new SniperCommander(1);
    CHECK(typeid(board[{0,3}]) == typeid(SniperCommander)); 
    board[{0,4}] = new Paramedic(1);
    CHECK(typeid(board[{0,4}]) == typeid(Paramedic)); 
    board[{0,5}] = new FootSoldier(1);
    CHECK(typeid(board[{0,5}]) == typeid(FootSoldier)); 
    CHECK(board.has_soldiers(1));
    board[{0,6}] = new FootSoldier(1);
    CHECK(typeid(board[{0,5}]) == typeid(FootSoldier)); 
    CHECK(board.has_soldiers(1));
    board[{0,7}] = new FootSoldier(1);
    CHECK(typeid(board[{0,5}]) == typeid(FootSoldier)); 
    CHECK(board.has_soldiers(1));
    board[{0,8}] = new FootSoldier(1);
    CHECK(typeid(board[{0,5}]) == typeid(FootSoldier)); 
    CHECK(board.has_soldiers(1));
    board[{0,9}] = new ParamedicCommander(1);
    CHECK(typeid(board[{0,5}]) == typeid(ParamedicCommander)); 
    CHECK(board.has_soldiers(1));

    //-----Player 2 soldiers-------//
    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new Paramedic(1);
    CHECK(typeid(board[{9,0}]) == typeid(Paramedic)); 
    CHECK(board.has_soldiers(1));
    board[{0,1}] = new Sniper(1);
    CHECK(typeid(board[{9,1}]) == typeid(Sniper)); 
    board[{0,2}] = new Sniper(1);
    CHECK(typeid(board[{9,2}]) == typeid(Sniper));
    board[{0,3}] = new SniperCommander(1);
    CHECK(typeid(board[{9,3}]) == typeid(SniperCommander)); 
    board[{0,4}] = new Paramedic(1);
    CHECK(typeid(board[{9,4}]) == typeid(Paramedic)); 
    board[{0,5}] = new FootSoldier(1);
    CHECK(typeid(board[{9,5}]) == typeid(FootSoldier)); 
    CHECK(board.has_soldiers(1));
    board[{0,6}] = new FootSoldier(1);
    CHECK(typeid(board[{9,6}]) == typeid(FootSoldier)); 
    CHECK(board.has_soldiers(1));
    board[{0,7}] = new FootSoldier(1);
    CHECK(typeid(board[{9,7}]) == typeid(FootSoldier)); 
    CHECK(board.has_soldiers(1));
    board[{0,8}] = new FootSoldier(1);
    CHECK(typeid(board[{9,8}]) == typeid(FootSoldier)); 
    CHECK(board.has_soldiers(1));
    board[{0,9}] = new ParamedicCommander(1);
    CHECK(typeid(board[{9,9}]) == typeid(ParamedicCommander)); 
    CHECK(board.has_soldiers(1));

////////////////////////////////////////////////////////////////////////////////////////////////

    CHECK_NOTHROW(board.move(1, {0,2}, Board::MoveDIR::Up));  /// move players 1 soldier to {1,3} and shoot
    CHECK(board[{0,2}]== nullptr); ///Checks that the soldier's old position now holds nullptr
    CHECK(typeid(board[ {1,2}]) == typeid(SniperCommander)); ///Checks that the soldier's new position now holds soldier

    CHECK_NOTHROW(board.move(2, {9,8}, Board::MoveDIR::Up));  /// move players 2 soldier to {9,2} and shoot
    CHECK(board[{9,8}]== nullptr); ///Checks that the soldier's old position now holds nullptr
    CHECK(typeid(board[ {8,8}]) == typeid(SniperCommander)); ///Checks that the soldier's new position now holds soldier

    CHECK_NOTHROW(board.move(1, {0,9}, Board::MoveDIR::Up));  
    CHECK(board[{0,9}]== nullptr); 
    CHECK(typeid(board[ {1,9}]) == typeid(Sniper)); 

    CHECK_NOTHROW(board.move(2, {9,0}, Board::MoveDIR::Down));  
    CHECK(board[{9,0}]== nullptr); 
    CHECK(typeid(board[ {8,0}]) == typeid(Sniper));

    CHECK_NOTHROW(board.move(1, {1,2}, Board::MoveDIR::Up));  
    CHECK(board[{1,2}]== nullptr); 
    CHECK(typeid(board[ {2,2}]) == typeid(SniperCommander)); 

    CHECK_NOTHROW(board.move(2, {9,3}, Board::MoveDIR::Down));  
    CHECK(board[{9,3}]== nullptr); 
    CHECK(typeid(board[ {8,3}]) == typeid(Sniper));

    CHECK_NOTHROW(board.move(1, {0,4}, Board::MoveDIR::Up));  
    CHECK(board[{0,4}]== nullptr); 
    CHECK(typeid(board[ {1,4}]) == typeid(Paramedic)); 

    CHECK_NOTHROW(board.move(2, {8,3}, Board::MoveDIR::Down)); 
    CHECK(board[{8,3}]== nullptr); 
    CHECK(typeid(board[ {7,3}]) == typeid(Sniper));

    CHECK_NOTHROW(board.move(1, {0,7}, Board::MoveDIR::Up));  
    CHECK(board[{0,7}]== nullptr); 
    CHECK(typeid(board[ {1,7}]) == typeid(Sniper)); 

    CHECK_NOTHROW(board.move(2, {9,1}, Board::MoveDIR::Down));  
    CHECK(board[{9,1}]== nullptr); 
    CHECK(typeid(board[ {8,1}]) == typeid(Paramedic));

    CHECK_NOTHROW(board.move(1, {0,1}, Board::MoveDIR::Up));  
    CHECK(board[{0,1}]== nullptr); 
    CHECK(typeid(board[ {1,1}]) == typeid(SniperCommander)); 

    CHECK_NOTHROW(board.move(2, {9,5}, Board::MoveDIR::Down));  
    CHECK(board[{9,5}]== nullptr); 
    CHECK(typeid(board[ {8,5}]) == typeid(SniperCommander)); 

    CHECK_NOTHROW(board.move(1, {2,2}, Board::MoveDIR::Right));  
    CHECK(board[{2,2}]== nullptr); 
    CHECK(typeid(board[ {2,3}]) == typeid(Sniper)); 

    CHECK_NOTHROW(board.move(2, {9,9}, Board::MoveDIR::Down));  
    CHECK(board[{9,9}]== nullptr); 
    CHECK(typeid(board[ {8,9}]) == typeid(Sniper));

    CHECK_NOTHROW(board.move(1, {1,7}, Board::MoveDIR::Up));  
    CHECK(board[{1,7}]== nullptr); 
    CHECK(typeid(board[ {2,7}]) == typeid(SniperCommander)); 

    CHECK_NOTHROW(board.move(2, {7,3}, Board::MoveDIR::Left));  
    CHECK(board[{7,3}]== nullptr); 
    CHECK(typeid(board[ {7,2}]) == typeid(Sniper));

    CHECK_NOTHROW(board.move(1, {1,4}, Board::MoveDIR::Up));  
    CHECK(board[{1,4}]== nullptr); 
    CHECK(typeid(board[ {2,4}]) == typeid(Paramedic)); 

    CHECK_NOTHROW(board.move(2, {8,5}, Board::MoveDIR::Down)); 
    CHECK(board[{8,5}]== nullptr); 
    CHECK(typeid(board[ {7,5}]) == typeid(Sniper));

    CHECK_NOTHROW(board.move(1, {0,0}, Board::MoveDIR::Up));  
    CHECK(board[{0,0}]== nullptr); 
    CHECK(typeid(board[ {1,0}]) == typeid(Sniper)); 

    CHECK_NOTHROW(board.move(2, {8,1}, Board::MoveDIR::Down));  
    CHECK(board[{8,1}]== nullptr); 
    CHECK(typeid(board[ {7,1}]) == typeid(Paramedic));
    
    CHECK_NOTHROW(board.move(2, {2,4}, Board::MoveDIR::Up));  
    CHECK(board[{2,4}]== nullptr); 
    CHECK(typeid(board[ {3,4}]) == typeid(Paramedic));

    CHECK_NOTHROW(board.move(2, {7,5}, Board::MoveDIR::Down));  
    CHECK(board[{7,5}]== nullptr); 
    CHECK(typeid(board[ {6,5}]) == typeid(FootSoldier));

    CHECK_NOTHROW(board.move(2, {2,3}, Board::MoveDIR::Up));  
    CHECK(board[{2,3}]== nullptr); 
    CHECK(typeid(board[ {3,3}]) == typeid(Sniper));

    CHECK_NOTHROW(board.move(2, {7,2}, Board::MoveDIR::Down));  
    CHECK(board[{7,2}]== nullptr); 
    CHECK(typeid(board[ {6,2}]) == typeid(SniperCommander));
}



