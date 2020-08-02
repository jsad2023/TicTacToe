#include <iostream>
#include <string>
#include "Board.hpp"
/*Player Functions
 */

Player::Player(char aSymbol, int aPlayerNum)
{
	symbol = aSymbol;
	playerNum = aPlayerNum;
	std::cout << "Player " << playerNum << ", Enter your name: ";
	getline(std::cin, name);
	winner = false;
}

char Player::getSymbol() { return symbol;}
int Player::getNum() {return playerNum;}
std::string Player::getName() {return name;}
bool Player::hasWon() {return winner;}
void Player::DeclareWinner() { this->winner = true;}

//Return the number choice for placement 
int Player::play()
{
	int choice;
	std::cout << name << ", Enter a number between 1-9: ";
	std::cin >> choice;
	std::cin.ignore();
	if(std::cin.fail() || choice < 1 || choice > 9)
	{
		std::cout << "Invalid Choice...." << std::endl;
		return this->play();
	}
	else
	{
		//Number needs to be between 0-8
		return choice - 1;
	}
}


