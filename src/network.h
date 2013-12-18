#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale>

//socket
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define CON_PORT 5454

using namespace std;

class Network{
	public:
		void parseRcv(string s, int client_sock);
		void make_server();
		void connect_to_server(const char* ip);
};