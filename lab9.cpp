/*
Nathan Park
3/29/15
Exercise 9.1
*/

#include <iostream>
#include <curses.h>
//#include <limits>
using namespace std;

const int NUMCOLS = 70;
const int NUMROWS = 20;

void setup();

class Robot {
  int rowPos;
  int colPos;
public:
  void initpos(int, int);

  int checkRowPos();
  int checkColPos();

  void moveN();
  void moveS();
  void moveE();
  void moveW();
};
  
int main()
{
  bool breakout;
  char c;
  int botnum;
  WINDOW *wnd;
  Robot bot[4];
  wnd = initscr();

  clear();
  
  refresh();
  
  setup();
    
  bot[0].initpos(1, 1);
  bot[1].initpos(1, NUMCOLS-2);
  bot[2].initpos(NUMROWS-2, NUMCOLS-2);
  bot[3].initpos(NUMROWS-2, 1);

  refresh();
  
  while(1) {
    breakout = 0;
    cin >> botnum >> c;
    // cin.clear(); // if you put a char in the int on accident, the program locks up
    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // attempted to fix bug w/ this code, didn't work
    if (botnum < 0 || botnum > 4) {
      endwin();
      return 0;
    }
    
    switch(c) {
    case 'N':
      for(int i=0; i < 4; i++) {
	if(i != botnum) {
	  if(bot[botnum].checkRowPos() - 1 == bot[i].checkRowPos() && bot[botnum].checkColPos() == bot[i].checkColPos())
	    breakout = 1;
	}
      }
      
      if (bot[botnum].checkRowPos() - 1 == 0) break;   
      
      if (breakout) break;
      bot[botnum].moveN();
      break;
    case 'S': 
      for(int i=0; i < 4; i++) {
	if(i != botnum) {
	  if(bot[botnum].checkRowPos() + 1 == bot[i].checkRowPos() && bot[botnum].checkColPos() == bot[i].checkColPos())
	    breakout = 1;
	}
      }
      
      if ((bot[botnum].checkRowPos() + 2)  == NUMROWS) break;
      
      if (breakout) break;
      
      bot[botnum].moveS();
      break;
    case 'E':
      for(int i=0; i < 4; i++) {
	if(i != botnum) {
	  if(bot[botnum].checkRowPos() == bot[i].checkRowPos() && bot[botnum].checkColPos() + 1 == bot[i].checkColPos())
	    breakout = 1;
	}
      }
      
      if ((bot[botnum].checkColPos() + 2) == NUMCOLS) break;
      
      if (breakout) break;


      bot[botnum].moveE();
      break;
    case 'W':
      for(int i=0; i < 4; i++) {
	if(i != botnum) {
       	  if(bot[botnum].checkRowPos() == bot[i].checkRowPos() && bot[botnum].checkColPos() - 1 == bot[i].checkColPos())
	    breakout = 1;
	}
      }
      
      if ((bot[botnum].checkColPos() - 1) == 0) break;
      
      if (breakout) break;

      bot[botnum].moveW();
      break;
    default:
      cout << "Invalid command." << endl;
      endwin();
      return 0;
    }
  }
}

void setup()
{
  int i;
  
  for (i=0; i < NUMCOLS; i++) {
    move(0, i);
    delch();
    insch('-');
    move(NUMROWS-1, i);
    delch();
    insch('-');
  }

  for (i=0; i < NUMROWS; i++) {
    move(i,0);
    delch();
    insch('|');
    move(i, NUMCOLS-1);
    delch();
    insch('|');
  }
}

void Robot::initpos(int x, int y){
  rowPos = x;
  colPos = y;
  
  move(rowPos, colPos);
  delch();
  insch('R');
}

int Robot::checkColPos(){
  return colPos;
}

int Robot::checkRowPos(){
  return rowPos;
}

void Robot::moveN(){
  move(rowPos, colPos);
  delch();
  insch(' ');

  rowPos = rowPos - 1;
  move(rowPos, colPos);
  delch();
  insch('R');
  
  refresh();
}

void Robot::moveS(){
  move(rowPos,colPos);
  delch();
  insch(' ');

  rowPos = rowPos + 1;
  move(rowPos, colPos);
  delch();
  insch('R');
  
  refresh();
}

void Robot::moveE(){
  move(rowPos, colPos);
  delch();
  insch(' ');
 
  colPos = colPos + 1;
  move(rowPos, colPos);
  delch();
  insch('R');

  refresh();
}

void Robot::moveW(){
  move(rowPos, colPos);
  delch();
  insch(' ');
  
  colPos = colPos - 1;
  move(rowPos, colPos);
  delch();
  insch('R');
  refresh();
}
