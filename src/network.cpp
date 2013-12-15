#include "network.h"
#include "game_functions.h"

Game_functions gfd;

char delimiter = '|';
string letterRecv, numberRecv, mRecv, previousMessage, letter, number, se;
int newNumber, previousNumber;
char game_message[1024], previousLetter;
bool hello;
string waterMessage = "Water! you missed.";
string boomMessage = "Boom! you hit.";
string helloMessage = "Hello";

void Network::make_server(){
	int socket_desc, client_sock, c, read_size;
	struct sockaddr_in server, client;

	//Creating Socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc ==  -1){
		cout << "ERROR: Cannot create socket";
		exit(1);
	} 

	puts("Server is now running");

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(CON_PORT);

	if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server))<0){
		perror("bind failed. Error");
	}
	listen(socket_desc, 3);
	puts("Waiting for player two...");
	c = sizeof(struct sockaddr_in);

	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock<0) perror("accept failed");

	puts("Player two connected");
	gfd.showBoard();

	while(true){

		if ( (read_size = recv(client_sock, game_message, 1024-1, 0)) > 0 ){
			game_message[read_size] = '\0';
			stringstream ss;
			string s;
			ss << game_message;
			ss >> s;			
			parseRcv(s,client_sock);
			gfd.showBoard();
			cout << "Turn is for player two" << endl;
			}
	}
}

void Network::connect_to_server(const char* ip){
    int sock, read_size;
    struct sockaddr_in server;
   
    sock = socket(AF_INET , SOCK_STREAM , 0);
    
    if (sock == -1){
    	cout << "Connection problem";
    	exit(1);
    } 

    puts("Connecting to server...");
     
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(CON_PORT);
 
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0){
	    perror("Error connecting to server");
	    exit(1);
    } 
    
    puts("Connected\n");
    if( send(sock, "HELLO_SERVER_IM_CLIENT", sizeof("HELLO_SERVER_IM_CLIENT"), 0) < 0) puts("Send failed");

    while(true){
		if((read_size = recv(sock, game_message, 1024-1, 0))>0){
			game_message[read_size] = '\0';
			stringstream ss;
			string s;
			ss << game_message;
			ss >> s;
			parseRcv(s,sock);
			gfd.showBoard();
			cout << "Turn is for player one" << endl;
		} else {
			cout << "Player has been disconnected" << endl;
		}
    }
     
    close(sock);
}


void Network::parseRcv(string s, int client_sock){
	if (s.find("|")){ // It's game coordinates
		if (s[0]=='G'){
			cout << "You win!" << endl;
			exit(0); 
		}

		if (gfd.countShips(client_sock)==0){
			cout << "You lose" << endl;
			if (send(client_sock, "G-O\0", strlen("G-O\0"), 0)<0) puts("Fail (send)");
			exit(0);
		}

		mRecv = s.substr(4, s.find(delimiter));
		letterRecv = s.substr(0, s.find(delimiter));
		numberRecv = s.substr(2, 2);
		newNumber = atoi(numberRecv.c_str());

		if (mRecv=="B"){
			cout << boomMessage << endl;
		} else if(mRecv=="O_SERVER_IM_CLIENT" || mRecv=="H") {
			cout << helloMessage << endl;
			hello = true;
		} else {
			cout << waterMessage << endl;
		}

		if (gfd.checkPos(newNumber,letterRecv.c_str())==1){
			previousMessage = boomMessage;
			gfd.killShip(letterRecv.c_str()[0], newNumber);
		} else if (hello){
			previousMessage = helloMessage;
		} else {
			previousMessage = waterMessage;
		}

		cout << "Try with a letter:";
		cin >> letter;
		cout << "Try with a number:";
		cin >> number;

		se = letter+"|"+number+"|"+previousMessage+"\0";

		previousNumber = atoi(number.c_str());
		previousLetter = letter[0];
		if (send(client_sock, se.c_str(), strlen(se.c_str()), 0)<0) puts("Fail (send)");
		hello = false;
	}
}
