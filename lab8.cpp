/*
Nathan Park
3/23/2015
Exercise 8.1
*/

#include <curses.h> // include the curses library

using namespace std;

const int MAXX = 40; // maximum size of the ’room’
const int MAXY = 20;

void setup( char[MAXX][MAXY], int x, int y ); // room setup
void print(char[MAXX][MAXY]);

int main()
{
    char c; // new
    WINDOW *wnd;
    char room[MAXX][MAXY]; // stores the room
    int x = MAXX/2, y = MAXY/2; // robot’s initial location

    wnd = initscr(); // ’initializes’ the window
    clear(); // clears the window
    refresh(); // reprints the window

    setup(room,x,y); // setup the room with the robot

    print(room); // write this function!!

    while ((c = getch()) != 'q'); // new

    endwin(); // frees the screen for normal use
}

void setup(char r[MAXX][MAXY], int x, int y)
{
  for (int i = 0; i < MAXX; i++)
    {
      for (int j = 0; j < MAXY; j++)
	{
	  r[i][j] = ' '; // empty the room
	}
    }

  for (int i = 0; i < MAXY; i++){
      r[0][i] = '-'; // top wall
      r[MAXX-1][i] = '-'; // bottom wall
  }

  for (int i = 0; i < MAXX; i++) {
    r[i][0] = '|'; // left wall
    r[i][MAXY-1] = '|'; // right wall
  }

  r[x][y] = 'R'; // place the robot
}

void print(char r[MAXX][MAXY]) 
{
  for (int i = 0; i < MAXX; i++)
    {
      for (int j = 0; j < MAXY; j++)
		{
		move(i, j);
		insch(r[i][j]);
		}
    }
}

It looks like this: 
	
|------------------|
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|         R        |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|                  |
|------------------|