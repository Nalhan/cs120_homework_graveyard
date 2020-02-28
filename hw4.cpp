/*
Nathan Park
3/25/15
Homework 4
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class hive {
private:
  int workerNum, foragerNum, nurseNum, guardNum;
  double pollen;
  double nectar;
  double water;
  double propolis;

public:
  hive() : workerNum(8), foragerNum(8), nurseNum(0), guardNum(0)
	 ,pollen(0.0), nectar(0.05), water(0.0), propolis(0.0) {} // initialize variables
  void addWorkers(int);
  int subWorkers(int);
  void printResources(void);
  void printWorkerAssignment(void);
  int simDay(void);
  void assignWorkers(void);

};


int main(){
  int day = 1;
  hive simHive;
  string command;
  
  cout << ")8( The Hundred-Acre Apiary Hive Simulator )8(" << endl;
  
  while (true)
    {
      simHive.assignWorkers();

      cout << "Enter Command: ";
      cin >> command;
      
      switch(command[0])
	{
	case '?':
	  switch (command[1])
	    {
	    case 'F':
	      simHive.printResources();
	      break;
	    case 'T':
	      cout << "It is sim-day " << day << "." << endl;
	      break;
	    case 'W':
	      simHive.printWorkerAssignment();
	      break;
	    case 0:
	      cout << "Error: ? command requires 1 operand." << endl;
	      break;
	    default:
	      cout << "Error: Operand to ? must be one of (FTW)." << endl; 
	      break;
	    }
	  break;
	  
	case 'W':
	  switch (command[1])


	    {
	    case '+':
	      if (command[2] == 0) cout << "Error: W command requires 2 operands." << endl;
	      
	      else {
		string commandNum = command.substr(2); 
		int num = 0;
		
		num = atoi(commandNum.c_str());
		
		if (num < 0 || num > 1000000) {
		  cout << "Error: Operand to W command must be greater than 0 and less than 1000001." << endl;
		}

		else {
		  simHive.addWorkers(num);
		}
	      }
	      break;
	    case '-':
	      if (command[2] == 0) cout << "Error: W command requires 2 operands." << endl;

	      else {
		string commandNum = command.substr(2); 
		int num = 0;
		
		num = atoi(commandNum.c_str());
		
		if (num < 0 || num > 1000000) {
		  cout << "Error: Operand to W command must be greater than 0 and less than 1000001." << endl;
		}
		
		else {
		  if (simHive.subWorkers(num)) { 
		    cout << "The hive has perished on sim-day " << day << "." << endl;
		    simHive.printResources();
		    return 0;
		  }
		}
		
	      }
	      break;
	      
	    case 0:
	      cout << "Error: W command requires 2 operands." << endl;
	      break;
	    default: 
	      cout << "Error: Operand to W command must be greater than 0 and less than 1000001." << endl;
	      break;
	    }
	  break;
	  
	case 'T':
	  if (simHive.simDay()) {
	    cout << "The hive has perished on sim-day " << day << "." << endl;
	    simHive.printResources();
	    return 0;
	  }
	  day++;
	  break;
	  
	case 'X':
	  return 0;
	  
	default:
	  cout << "Error: Unrecognized command." << endl;
	  break;
	} 
    }
}


void hive::addWorkers(int num) {
  workerNum += num;
  cout << workerNum << endl;
}

int hive::subWorkers(int num) {
  workerNum -= num;
  cout << workerNum << endl;
  
  if (workerNum <= 0) {
    return 1; // signal to end program
  }
  
  return 0;
}

int hive::simDay(void) {
  for (int i = 0; i < foragerNum; i++) {
    pollen += 0.1;
    nectar += 0.05;
    water += 0.2;
    propolis += 0.03;
  }

  // daily consumption
  pollen -= 0.4;
  nectar -= (0.03*workerNum + 0.18); // .18 is queen consumption
  water -= (0.1*workerNum + 0.2); // .2 is queen consumption
  propolis -= 0.06;
  
  if (pollen < 0) pollen = 0;
  if (nectar < 0) nectar = 0;
  if (water < 0) water = 0;
  if (propolis < 0) propolis = 0;

  if (pollen == 0 || nectar == 0 || water == 0 || propolis ==0) {
    return 1; // signal to end program
  }
  return 0;

}

void hive::printResources(void){
  cout << "Pollen: " << pollen << " micrograms" << endl;
  cout << "Nectar: " << nectar << " micrograms" << endl;
  cout << "Water: " << water << " microlitres" << endl;
  cout << "Propolis: " << propolis << " microlitres" << endl;
}

void hive::printWorkerAssignment(void){
  cout << "#Workers: " << workerNum << endl;
  cout << "#Foragers: " << foragerNum << endl;
  cout << "#Nurses: " << nurseNum << endl;
  cout << "#Guards: " << guardNum << endl;
}

void hive::assignWorkers(void){
  foragerNum = workerNum * .65;
  nurseNum = workerNum * .35;
  guardNum = workerNum - foragerNum - nurseNum;
  
  if (foragerNum < 8) {
    foragerNum = workerNum;
    nurseNum = 0;
    guardNum = 0;
  }  
}
