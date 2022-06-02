#include <iostream>
#include <cstring> // used for strlen() fuction
#include <ncurses.h>
#include "snake.hpp"
#include "food.hpp"

// TODO:

int row, col; // used to store the # of rows & columns of the screen
WINDOW* game_win; // window for the game to take place

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
/* SETTING UP THE GAME WINDOW */
	game_win = newwin(row - 3, col, 3, 0);
	box(game_win, 0, 0);
	wrefresh(game_win);
}

void gameLoop() {
	int ch; // used to read user input
	bool gameOver = false;
	Snake snake(5, 5);
	
	/*
	 * the mv (move) part of mvaddch works as follows:
	 * move(row, col)
	 * therefore, we actually want to use our snake y value for the row,
	 * and the snake x value for the column.
	*/
	mvwaddch(game_win, snake.getYIndex(0), snake.getXIndex(0), '@');
	wrefresh(game_win);

	// the second part of this while condition is where we get user input
	while(!gameOver && (ch = getch()) != 'q' && ch != 'Q') {
		switch(ch) {
			case KEY_LEFT:
				snake.updateBlock(0, snake.getXIndex(0) - 1, snake.getYIndex(0));
			case KEY_UP:
				snake.updateBlock(0, snake.getXIndex(0), snake.getYIndex(0) - 1);
			case KEY_RIGHT:
				exit(0);
				snake.updateBlock(0, snake.getXIndex(0) + 1, snake.getYIndex(0));
			case KEY_DOWN:
				snake.updateBlock(0, snake.getXIndex(0), snake.getYIndex(0) + 1);
		}
		mvwaddch(game_win, snake.getYIndex(0), snake.getXIndex(0), '@');
		wrefresh(game_win);
	}
}

int main() {
	initScreen(); 
	initGame();
	gameLoop(); // start the game loop

	endwin();
	return 0;	
}
