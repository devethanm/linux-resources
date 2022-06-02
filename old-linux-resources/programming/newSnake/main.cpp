#include <iostream>
#include <cstring> // used for strlen() fuction
#include <ncurses.h>
#include "snake.h"
using namespace std;

int row, col; // used to store the # of rows & columns of the screen

void initScreen() {
	initscr(); // init the curses system
	raw(); // make it so that characters are availible as soon as they are pressed
	noecho(); // do not echo characters the user presses to the screen
	keypad(stdscr, TRUE); // enable arrow keys
	getmaxyx(stdscr, row, col); // store the # of rows & columns in the row and col variables
	curs_set(0); // hide the cursor

	char msg1[]="SNAKE";
	char msg2[]="PRESS Q TO QUIT";
	mvaddstr(1, col/2 - (strlen(msg1) / 2), msg1);
	mvaddstr(2, col/2 - (strlen(msg2) / 2), msg2);
	refresh();
}

void initGame() {
/* CREATING THE GAME WINDOW */
	WINDOW* game_win;
	game_win = newwin(row - 3, col, 3, 0);
	box(game_win, 0, 0);
	wrefresh(game_win);
}

void gameLoop() {
	bool gameOver = false;
	while(!gameOver) {
		int ch = getch();
		if(ch == 'q' || ch == 'Q') // press q to break the gameloop
			gameOver = true;
		refresh();
	}
}

int main() {
	Snake snake;
	initScreen(); 
	initGame();
	gameLoop(); // start the game loop

	endwin();
	return 0;	
}
