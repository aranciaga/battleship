CC=g++
PF=/usr
BIN=battleship
battleship:
	$(CC) src/main.cpp src/game_functions.cpp src/network.cpp -o $(BIN)
install: battleship
	install -m 0755 $(BIN) $(PF)/bin
uninstall: battleship
	rm -f $(PF)/bin/$(BIN)
