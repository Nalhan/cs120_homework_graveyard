//InVal.cpp
#include "InVal.h"

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

InVal::InVal() {
	input = "";
	base10 = 0;
	output = "";
}

void InVal::PrintAsBase(int base) {

int base10val = base10;
output = "";

	for(; base10val > 0;) {
		int digitval = base10val % base;

		//this seems bad but oh well
		char digit;
		switch (digitval) {
			case 10: 
				digit = 'A';
				break;
			case 11:
				digit = 'B';
				break;
			case 12:
				digit = 'C';
				break;
			case 13:
				digit = 'D';
				break;
			case 14:
				digit = 'E';
				break;
			case 15:
				digit = 'F';
				break;
			default:
				digit = digitval + 48;
				break;
		}
		base10val = ((base10val-(base10val%base)) / base);
		output.insert(output.begin(),1,digit);

	}
	cout << "    " << output << " (base " << base << ")" << endl;
}

void InVal::InputNum(string input, int base) {
	base10 = 0;
	int length = input.length();
	for(int i = 0; 0 < length; i++) {
		int digit = input.at(--length) - 48;

		base10 += pow(base, i)*digit;
	}
}		