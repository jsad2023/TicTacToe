#ifndef BOARD_HPP
#define BOARD_HPP 

#include "Player.hpp"
#include <array>

class Board
{
	private:
		std::array<char, 9> arr;
		bool complete = false;
	public:
		Board();
		void display();
		bool win(Player);
		void UpdateBoard(int, Player);
		bool BoardIsFull();
		bool CheckForWin(Player& );
};

#endif /* BOARD_HPP */
