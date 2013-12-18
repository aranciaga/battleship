#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale>

using namespace std;

class Game_functions{
	public:
		int getLetter(char letter);
		void showBoard();
		void killShip(char letter, int number);
		int countShips(int client_sock);
		int checkPos(int number, string letter);
		void clear_screen();
		void setShip(int type, char pos, char letter, int number);
		void ship_menu(string type, string IP_ADDR);
		bool verPos(char ch);
		bool canSetShip(int pX, int pY, int type, char pos);
		bool checkCollide(int pX, int pY, int type, char pos);
};