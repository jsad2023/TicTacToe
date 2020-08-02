#ifndef PLAYER_HPP
#define PLAYER_HPP 

class Player
{
	private:
		std::string name;
		char symbol;
		bool winner;
		int playerNum;
	public:
		Player(char, int);
		int play();
		std::string getName();
		char getSymbol();
		bool hasWon();
		int getNum();
		void DeclareWinner();
};

#endif /* PLAYER_HPP */
