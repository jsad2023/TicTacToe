#include <iostream>
#include "Player.hpp"
#include "Board.hpp"


int main()
{
    Player p1('X', 1);
    Player p2('O', 2);
    Board B;
    std::cout << "TIC-TAC-TOE\nPlayer 1: X\nPlayer 2: O\nInstructions: Type in a number between 1-9 for 'X' or 'O' placement:\n\n";
    while(true)
    {
        //Player 1 Turn
        B.display();
        int choice = p1.play();
        B.UpdateBoard(choice, p1);
        if(B.CheckForWin(p1) || B.BoardIsFull()) break;

        //Player 2 Turn
        B.display();
        choice = p2.play();
        B.UpdateBoard(choice, p2);
        if(B.CheckForWin(p2) || B.BoardIsFull()) break;
    }

    B.display();
    if(p1.hasWon())
    {
        std::cout << p1.getName() << " Wins!!!" << std::endl;
    }
    else if(p2.hasWon())
    {
        std::cout << p2.getName() << " Wins!!!" << std::endl;
    }
    else
    {
        std::cout << "Tie Game!!!" << std::endl;
    }

    std::cout << "Thanks for Playing!" << std::endl;
    return 0;
}
