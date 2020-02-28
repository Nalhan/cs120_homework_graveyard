/*
Nathan Park
5/4/15
Exercise 13.1
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

class Robot {
private:
	int RobotNumber;
	char RobotType;
	char RobotManufacturer[64];
	int deploynum;
	int quadrant;	// if 0 not deployed
public:
	Robot();
	Robot(int, char, char[64]);
	int getRobotNum(void) {return RobotNumber;}
	int getQuadrant(void) {return quadrant;} // if 0 not deployed
	void changeQuadrant(int);
	void deploynumIncrement(void) {deploynum++;}
	void print(void);
};

Robot::Robot(int botnum, char bottype, char botman[64]) {
	RobotNumber = botnum;
	RobotType = bottype;
	strcpy(RobotManufacturer, botman);
}

void Robot::changeQuadrant(int quad) {
	quadrant = quad;
	return;
}


void Robot::print() {
	cout << "Robot " << RobotNumber << endl;
	cout << "	" << "type: " << RobotType << endl;
	if(quadrant == 0 && RobotType == 'S')
		cout << "	" << "status: In scout holding bay" << endl;
	if(quadrant == 0 && RobotType == 'M')
		cout << "	" << "status: In miner holding bay" << endl;
	if(quadrant != 0)
		cout << "	" << "status: Deployed in quadrant " << quadrant << endl;
	cout << "	" << "num-deployments: " << deploynum << endl;
	cout << "	" << "manufacturer: " << RobotManufacturer << endl;
	return;
}

class node {
private:
	node *next;
	Robot *data;
public:
	node();
	void set_next(node *n) {next = n;}
	void set_data(Robot *d) {data = d;}
	node *get_next() {return next;}
	Robot *get_data() {return data;}
	//int remove(int);
	//void remove_data() {delete data;}
	Robot* getDispatchableRobot(void);
	Robot* getRobot(int);
};

node::node() {
	next = NULL;
	data = NULL;
}

// remove is unused so not including it
/* 
int node::remove(int n) {
	if (next != NULL) {
		if((next -> data) -> getRobotNum() == n) {
			if((next -> data) -> getQuadrant() == 0) holdingSub();
			else deploySub();
			node *temp;
			temp = next;
			next = next -> next;
			temp -> remove_data();
			delete temp;
			return(1);
		}
		else {
			return(next->remove(n));
		}
	}
	return 0;
}
 */
	


class linkedlist {
private:
	int count;
	int deployed;
	int holding;
	node *head;
	
public:
	linkedlist();
	void insert(Robot *);
	//void remove(int);
	Robot* getRobot(int);
	Robot* getDispatchableRobot(void);
	void deployAdd(void) {deployed++;}
	void deploySub(void) {deployed--;}
	void holdingAdd(void) {holding++;}
	void holdingSub(void) {holding--;}
	int getDeployed(void) {return deployed;}
	int getHolding(void) {return holding;}

};

linkedlist::linkedlist(){
	head = NULL;
	count = 0;
	holding = 0;
	deployed = 0;
}

void linkedlist::insert(Robot *rp) {
	node *n;
	n = new node;
	n -> set_data(rp);
	n -> set_next(head);
	head = n;
	count++;
	holdingAdd();
}

// remove is unused so not including it
/* 
void linkedlist::remove(int n) {
	if(head == NULL)
		return;
	if((head -> get_data()) -> getRobotNum() == n) {
		if((head ->get_data()) -> getQuadrant() == 0) holdingSub();
		else deploySub();
		node *temp;
		temp = head;
		head = head->get_next();
		temp -> remove_data();
	}
	else {
		if(head ->remove(n) == 1)
			count--;
	}
}
 */
 
Robot* linkedlist::getDispatchableRobot(void) {
	node* curr = head;
	
	while(curr != NULL) {
		if((curr -> get_data()) -> getQuadrant() == 0)
			return (curr -> get_data());
		curr = curr -> get_next();
	}
	
	return NULL;
}

Robot* linkedlist::getRobot(int botnum) {
	node* curr = head;
	
	while(curr != NULL) {
		if((curr -> get_data()) -> getRobotNum() == botnum)
			return (curr -> get_data());
		curr = curr -> get_next();
	}
	
	return NULL;
}



void dispatchScout(int);
void dispatchMiner(int);
void retrieveScout(int);
void retrieveMiner(int);
void printInfo(int);

linkedlist minelist;
linkedlist scoutlist;


int main() {
	ifstream infile;
	
	int botnum, arg;
	char bottype, command;
	char botman[64];
	Robot *pBot;
	infile.open("robots.txt");
	
	while(!infile.eof()) {
		infile >> botnum >> bottype >> botman;
		pBot = new Robot(botnum,bottype,botman);
		if(bottype == 'S') {
			scoutlist.insert(pBot);
		}
		
		if(bottype == 'M') {
			minelist.insert(pBot);
		}
	}

	while(1) {
		cout << "Input command: ";
		cin >> command;
		switch(command) {
			case 'D':
				cin >> arg;
				dispatchScout(arg);
				break;
			case 'd':
				cin >> arg;
				dispatchMiner(arg);
				break;
			case 'R':
				cin >> arg;
				retrieveScout(arg);
				break;
			case 'r':
				cin >> arg;
				retrieveMiner(arg);
				break;
			case '?':
				cin >> arg;
				printInfo(arg);
				break;
			case 's':
				cout << "Scouts deployed: " << scoutlist.getDeployed() << endl;
				break;
			case 'S':
				cout << "Scouts in holding bay: " << scoutlist.getHolding() << endl;
				break;
			case 'm':
				cout << "Miners deployed: " << minelist.getDeployed() << endl;
				break;
			case 'M':
				cout << "Miners in holding bay: " << minelist.getHolding() << endl;
				break;
			case 'q':
				return 0;
			default:
				break;
		}
	}
}

void dispatchScout(int dispatchquad) {
	if(dispatchquad < 1 || dispatchquad > 4) {
		cout << "Invalid quadrant" << endl;
		return;
	}
	
	Robot* rp = scoutlist.getDispatchableRobot();
	
	if(rp == NULL) {
		cout << "No deployable robots" << endl;
		return;
	}
	
	rp -> changeQuadrant(dispatchquad);
	rp -> deploynumIncrement();
	scoutlist.deployAdd();
	scoutlist.holdingSub();
	cout << "Robot " << rp -> getRobotNum() << " deployed to quadrant " << dispatchquad << endl;
}

void dispatchMiner(int dispatchquad) {
	if(dispatchquad < 1 || dispatchquad > 4) {
		cout << "Invalid quadrant" << endl;
		return;
	}
	
	Robot* rp = minelist.getDispatchableRobot();
	
	if(rp == NULL) {
		cout << "No deployable robots" << endl;
		return;
	}
	
	rp -> changeQuadrant(dispatchquad);
	rp -> deploynumIncrement();
	minelist.deployAdd();
	minelist.holdingSub();
	cout << "Robot " << rp -> getRobotNum() << " deployed to quadrant " << dispatchquad << endl;
}

void retrieveScout(int botnum) {
	Robot* rp = scoutlist.getRobot(botnum);
	
	if(rp == NULL) {
		cout << "Not a valid robot" << endl;
		return;
	}
	int oldquad = rp -> getQuadrant();
	rp -> changeQuadrant(0);
	scoutlist.deploySub();
	scoutlist.holdingAdd();
	cout << "Robot " << rp -> getRobotNum() << " retrieved from quadrant " << oldquad << endl;
}

void retrieveMiner(int botnum) {
	Robot* rp = minelist.getRobot(botnum);
	
	if(rp == NULL) {
		cout << "Not a valid robot" << endl;
		return;
	}
	int oldquad = rp -> getQuadrant();
	rp -> changeQuadrant(0);
	minelist.deploySub();
	scoutlist.holdingAdd();
	cout << "Robot " << rp -> getRobotNum() << " retrieved from quadrant " << oldquad << endl;
}

void printInfo(int botnum) {
	Robot* rpScout = scoutlist.getRobot(botnum);
	Robot* rpMiner = minelist.getRobot(botnum);
	
	if(rpScout != NULL) {
		rpScout -> print();
		return;
	}
	
	if(rpMiner != NULL) {
		rpMiner -> print();
		return;
	}
	
	cout << "Not a valid robot" << endl;
	return;
}

