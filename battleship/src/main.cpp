#include "network.h"
#include "game_functions.h"

using namespace std;

string type;
string IP_ADDR;

Network net;
Game_functions gf;

int how_to_play(){
	gf.clear_screen();
	string d;
	cout << "How to play: " << endl;
	cout << "1. Choose a position for every ship" << endl;
	cout << "The positions of the ship are represented by numbers and letters, like coordinates." << endl;
	cout << "You need to type the letter and after type the number to set the position. Example: A 6" << endl;
	cout << "2.I will ask you a possible position for the enemy board. If you hit, a part of the ship will be destroyed, or completely." << endl;
	cout << "Principally, you need to destroy all ships of the enemy, the first who can do it, win." << endl;
	cout << "¡The force may be with you!" << endl;
	cout << "Type anything to continue" << endl;
	cin >> d;
	return 1;
}


void main_menu(){
const char* logo[] = {
"			         ",
"	           _",
"		  ) (",
"	         )   (",
"    	        )     (", 
"               )___|___(   ",
"|\\_________________|_________/|",
"\\  O  O  O  O  O  O  O  O    /",
" \\__________________________/",
"  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
"Battleship v1.0 @ by Rainbow",
};


	int option;
	bool choosing = true;
	while(choosing){
		switch(option){
			case 1:
				choosing = false;
				type = "server";
				break;
			case 2:
				choosing = false;
				type = "client";
				cout << "Type the IP Address:" << endl;
				cout << "Connect to> ";
				cin >> IP_ADDR;
				break;
			case 3:
				if(how_to_play()==1){
					option=24; // random number to bucle
				}
				break;
			default:
				do{
					gf.clear_screen();
					for (int i=0; i<11; i++){
						cout << logo[i] << endl;
					}
					cout << "Choose your option:" << endl;
					cout << "[1] Create server" << endl;
					cout << "[2] Connect to host" << endl;
					cout << "[3] How to play" << endl;
					cout << "> ";
					cin >> option;
					cin.clear();
					cin.ignore(256, '\n');
				} while(!cin);
				break;
		}
	}
}
int main(){
	main_menu();
	gf.ship_menu(type, IP_ADDR);

	return 0;
}
