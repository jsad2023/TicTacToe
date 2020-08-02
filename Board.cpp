#include <array>
#include <iostream>
#include "Board.hpp"

Board::Board()
{
	char c;
	for(int i = 0; i < 9; i++)
	{
		c = '1' + i;
		arr[i] = c;
	}
}


void Board::display()
{
    std::cout << std::endl;
    std::string line = "===========";
    std::cout << " " << arr[0] << " | " << arr[1] << " | " << arr[2] << " " 
	    << std::endl;
    std::cout << line << std::endl;
    std::cout << " " << arr[3] << " | " << arr[4] << " | " << arr[5] << " " 
	    << std::endl;
    std::cout << line << std::endl;
    std::cout << " " << arr[6] << " | " << arr[7] << " | " << arr[8] 
	    << " \n";
    std::cout << std::endl;
}

//Choice will be between 1-9
void Board::UpdateBoard(int choice, Player p)
{
	while(arr[choice] == 'X' || arr[choice] == 'O')
	{
		std::cout << "Slot is not available..." << std::endl;
		choice = p.play();	
	}
	arr[choice] = p.getSymbol();
}

bool Board::BoardIsFull()
{
	bool isFull = true;
	for(int i = 0; i < 9; i++)
	{
		if(arr[i] == ((char) '1' + i))
		{
			isFull = false;
			break;
		}
	}
	complete = isFull;
	return isFull;
}

bool Board::CheckForWin(Player& p)
{
    char symb = p.getSymbol();

    //row check
    for(int i = 0; i < 7; i+=3) {
        if (arr[i] == symb && arr[i] == arr [i+1] && 
			arr[i] == arr[i+2] ){
            complete =  true;
        }
    }
    //Column check
    for(int i = 0; i < 3; i++) {
        if(arr[i] == symb && arr[i] == arr[i+3] &&
			arr[i] == arr[i+6]) {
            complete =  true;
        }
    }
    // Left diagonal check
    if (arr[0] == arr[4] && arr[0] == arr[8] && arr[0] == symb) {
        complete =  true;
    }
    //Right diagonal check
    if (arr[2] == arr[4] && arr[2] == arr[6] && arr[2] == symb) {
        complete =  true;
    }
    
    if(complete) p.DeclareWinner();
    return complete;
}
