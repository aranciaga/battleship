#include "network.h"
#include "game_functions.h"

char abc[24] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X'};

char aircraft_letter, aircraft_pos, battleship1_pos, battleship1_letter, battleship2_pos, battleship2_letter, cruiser_pos, cruiser_letter, frigate1_pos, frigate1_letter, submarine_letter, submarine_pos;
int aircraft_number, battleship1_number, battleship2_number, cruiser_number, frigate1_number, submarine_number;
enum { Aircraft, Submarine, Battleship, Cruiser, Frigate};
string player_name;
int filas[25] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
char grid[25][25] ={
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
};

Network nett;


void Game_functions::setShip(int type, char pos, char letter, int number){
	char ShipLetter;
	switch(type){
		case Aircraft:
			ShipLetter = 'A';
			if (pos=='v'){
				grid[number][getLetter(letter)] = ShipLetter;
				grid[number+1][getLetter(letter)] = ShipLetter;
				grid[number-1][getLetter(letter)] = ShipLetter;
				grid[number+2][getLetter(letter)] = ShipLetter;
				grid[number-2][getLetter(letter)] = ShipLetter;
			} else if (pos=='h'){
				grid[number][getLetter(letter)] = ShipLetter;
				grid[number][getLetter(letter)+1] = ShipLetter;
				grid[number][getLetter(letter)-1] = ShipLetter;
				grid[number][getLetter(letter)+2] = ShipLetter;
				grid[number][getLetter(letter)-2] = ShipLetter;
			}		
			break;
		case Submarine:
			ShipLetter = 'S';
			if (pos=='v'){
				grid[number][getLetter(letter)] = ShipLetter;
				grid[number+1][getLetter(letter)] = ShipLetter;
				grid[number-1][getLetter(letter)] = ShipLetter;
				grid[number+2][getLetter(letter)] = ShipLetter;
			} else if (pos=='h'){
				grid[number][getLetter(letter)] = ShipLetter;
				grid[number][getLetter(letter)+1] = ShipLetter;
				grid[number][getLetter(letter)-1] = ShipLetter;
				grid[number][getLetter(letter)+2] = ShipLetter;
			}
			break;		
		case Frigate:
			ShipLetter = 'F';
			if (pos=='v'){
				grid[number][getLetter(letter)] = ShipLetter;
				grid[number+1][getLetter(letter)] = ShipLetter;
			} else if (pos=='h'){
				grid[number][getLetter(letter)] = ShipLetter;
				grid[number][getLetter(letter)+1] = ShipLetter;
			}
			break;
		case Battleship:
			ShipLetter = 'B';
			if (pos=='v'){
				grid[number][getLetter(letter)] = ShipLetter;
				grid[number+1][getLetter(letter)] = ShipLetter;
				grid[number-1][getLetter(letter)] = ShipLetter;
				grid[number+2][getLetter(letter)] = ShipLetter;
			} else if (pos=='h'){
				grid[number][getLetter(letter)] = ShipLetter;
				grid[number][getLetter(letter)+1] = ShipLetter;
				grid[number][getLetter(letter)-1] = ShipLetter;
				grid[number][getLetter(letter)+2] = ShipLetter;
			}
			break;
		case Cruiser:
			ShipLetter = 'C';
			if (pos=='v'){
				grid[number][getLetter(letter)] = ShipLetter;
				grid[number+1][getLetter(letter)] = ShipLetter;
				grid[number-1][getLetter(letter)] = ShipLetter;
			} else if (pos=='h'){
				grid[number][getLetter(letter)] = ShipLetter;
				grid[number][getLetter(letter)+1] = ShipLetter;
				grid[number][getLetter(letter)-1] = ShipLetter;
			}
		break;
	}
}



void Game_functions::clear_screen(){
	#ifdef __linux__
		system("clear");
	#elif _WIN32
		system("cls");
	#else
		cout << "ERROR: Your Operative System don't support 'clean_screen()' function";
	#endif
}

int Game_functions::checkPos(int number, string letter){
	char newLetter;
	newLetter = letter[0];
	if (grid[number][getLetter(newLetter)]=='.'){
		return 0;
	} else {
		return 1;
	}
}


int Game_functions::countShips(int client_sock){
	int count = 0;

	for (int i=0; i<24; i++){
		for(int j=0; j<24; j++){
			if (grid[i][j]!='.' && grid[i][j]!='X'){
				count+=1;
			}
		}
	}
	return count;
}

void Game_functions::killShip(char letter, int number){
	grid[number][getLetter(letter)] = 'X';
}

void Game_functions::showBoard(){
	clear_screen();
	cout << "    A B C D E F G H I J K L M N O P Q R S T U V W X Y"  << endl;
	for (int i=0; i<25; i++){
		if (i<10){
			cout << filas[i] << ")  ";
		} else {
			cout << filas[i] << ") ";
		}
		for(int j=0; j<25; j++){
			cout << grid[i][j] << " ";			
		}
		cout << endl;	
	}
}

int Game_functions::getLetter(char letter){
	for (int i=0; i<24; i++){
		if (toupper(letter)==abc[i]){
			return i; 
		}
	}
}



void Game_functions::ship_menu(){
	cout << "Hi, What's your name?:";
	cin >> player_name;
	cout << "Nice to meet you " << player_name << endl;
	showBoard();
	cout << "Choose the position for your ships" << endl;
	cout << "#1 Aircraft" << endl;
	cout << "Letter: ";
	cin >> aircraft_letter;
	cout << "Number: ";
	cin >> aircraft_number;
	cout << "Pos (v for vertical, h for horizontal):";
	cin >> aircraft_pos;
	setShip(Aircraft, aircraft_pos, aircraft_letter, aircraft_number);
	showBoard();

	cout << "#1 Battleship" << endl;
	cout << "Letter: ";
	cin >> battleship1_letter;
	cout << "Number: ";
	cin >> battleship1_number;
	cout << "Pos (v for vertical, h for horizontal):";
	cin >> battleship1_pos;
	setShip(Battleship, battleship1_pos, battleship1_letter, battleship1_number);
	showBoard();

	cout << "#2 Battleship" << endl;
	cout << "Letter: ";
	cin >> battleship2_letter;
	cout << "Number: ";
	cin >> battleship2_number;
	cout << "Pos (v for vertical, h for horizontal):";
	cin >> battleship2_pos;
	setShip(Battleship, battleship2_pos, battleship2_letter, battleship2_number);
	showBoard();

	cout << "#1 Cruiser" << endl;
	cout << "Letter: ";
	cin >> cruiser_letter;
	cout << "Number: ";
	cin >> cruiser_number;
	cout << "Pos (v for vertical, h for horizontal):";
	cin >> cruiser_pos;
	setShip(Cruiser, cruiser_pos, cruiser_letter, cruiser_number);
	showBoard();

	cout << "#1 Frigate" << endl;
	cout << "Letter: ";
	cin >> frigate1_letter;
	cout << "Number: ";
	cin >> frigate1_number;
	cout << "Pos (v for vertical, h for horizontal):";
	cin >> frigate1_pos;
	setShip(Frigate, frigate1_pos, frigate1_letter, frigate1_number);
	showBoard();

	cout << "#1 Submarine" << endl;
	cout << "Letter: ";
	cin >> submarine_letter;
	cout << "Number: ";
	cin >> submarine_number;
	cout << "Pos (v for vertical, h for horizontal):";
	cin >> submarine_pos;
	setShip(Submarine, submarine_pos, submarine_letter, submarine_number);
	clear_screen();
	cout << "Let's start the game..." << endl;
	
/*
	if (type=="server"){
		net.make_server();
	} else if(type=="client"){
		net.connect_to_server(IP_ADDR.c_str());
	}
*/

}
