/*
Nathan Park
4/7/15
Exercise 11.1
*/

//lab11.cpp

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "InVal.h"
using namespace std;

int main(){
  int inbase; // val between 2-16
  int outbase[128];
  InVal number;
  string input;
  int i;
  while(1) {
    
    cin >> inbase;
    if (inbase < 2 || inbase > 16) {
      cout << "error: invalid inbase " << inbase << ", terminating" << endl;
      return 0;
    }

    cin >> input;
	
	number.InputNum(input, inbase);
	
    i = 0;
    
    do{
      cin >> outbase[i];
	  if (outbase[i] < 2 || outbase[i] > 16) break;
      i++;
    } while(1);
	
    cout << input << " (base " << inbase << ") is..." << endl;

	for(int j = 0; j < i; j++) {
		number.PrintAsBase(outbase[j]);
	}
	
  }
}
