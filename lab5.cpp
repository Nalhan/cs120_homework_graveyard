/*
Nathan Park
2/17/2015
Exercise 5.1
*/

#include <iostream>

using namespace std;

// all functions print customer data, then return customer's computed total to main
double getResidentialCharge(double);
double getSCommercialCharge(double, double);
double getLCommercialCharge(double, double, char);
double getIndustrialCharge(double, double, char);
int main() {
	int customerNumber = 0, scheduleNumber = 0;
	double kwhUsage = 0, kwDemand = 0, totalCharge = 0, currTotal = 0;
	char voltDiscount;
	
	do {
		customerNumber = 0, scheduleNumber = 0;
		kwhUsage = 0, kwDemand = 0, currTotal = 0;
		cin >> customerNumber >> scheduleNumber >> kwhUsage >> kwDemand >> voltDiscount;
		
		switch (scheduleNumber) {
			case 1: 
				cout << customerNumber << "	" << scheduleNumber << "	" << kwhUsage << endl;
				currTotal = getResidentialCharge(kwhUsage);
				totalCharge = totalCharge + currTotal;
				cout << "Customer " << customerNumber << "'s total is " << currTotal << endl;
				break;
			case 11:
				cout << customerNumber << "	" << scheduleNumber << "	" << kwhUsage << "	" << kwDemand << endl;
				currTotal = getSCommercialCharge(kwhUsage, kwDemand);
				totalCharge = totalCharge + currTotal;
				cout << "Customer " << customerNumber << "'s total is " << currTotal << endl;
				break;
			case 12:
				cout << customerNumber << "	" << scheduleNumber << "	" << kwhUsage << "	" << kwDemand << "	" << voltDiscount << endl;
				currTotal = getLCommercialCharge(kwhUsage, kwDemand, voltDiscount);
				totalCharge = totalCharge + currTotal;
				cout << "Customer " << customerNumber << "'s total is " << currTotal << endl;
				break;
			case 21:
				cout << customerNumber << "	" << scheduleNumber << "	" << kwhUsage << "	" << kwDemand << "	" << voltDiscount << endl;
				currTotal = getIndustrialCharge(kwhUsage, kwDemand, voltDiscount);
				totalCharge = totalCharge + currTotal;
				cout << "Customer " << customerNumber << "'s total is " << currTotal << endl;
				break;
		}
		
		if (customerNumber == 000000) break;	
	} while (true);
	
	cout << "The total charge amount is: " << totalCharge << endl;
	return 0;
}

double getResidentialCharge(double kwhUsage) {
	double customerCharge;
	double first600;
	double over600;
	
	if (kwhUsage > 600) {
		first600 = 600 * (0.05255);
		over600 = (kwhUsage - 600) * (0.06156);
	}
	else {
		first600 = kwhUsage * (0.05255);
		over600 = 0;
	}
	
	customerCharge = 4 + first600 + over600;
	
	return customerCharge;
}

double getSCommercialCharge(double kwhUsage, double kwDemand) {
	double customerCharge;
	
	if (kwDemand > 20) {
		customerCharge = 6 + (kwhUsage * .07971) + ((kwDemand - 20) * 3.5);
	}
	
	else {
		customerCharge = 6 + (kwhUsage * .07971);
	}

	return customerCharge;
}

double getLCommercialCharge(double kwhUsage, double kwDemand, char voltDiscount) {
	double customerCharge;
	double demandRate = 3.0;
	
	if (voltDiscount == 'Y') {
		demandRate = demandRate * .2;
	}

	if (kwhUsage > 20) {
		customerCharge = 6 + (kwhUsage * .07719) + ((kwDemand - 20) * demandRate);
	}
	else {
		customerCharge = 6 + (kwhUsage * .07719);
	}

	return customerCharge;
}

double getIndustrialCharge(double kwhUsage, double kwDemand, char voltDiscount) {
	double customerCharge;
	double demandRateUnder50;
	double demandRateOver50;
	
	if (voltDiscount = 'Y') {
		demandRateUnder50 = demandRateUnder50 * .2;
		demandRateOver50 = demandRateOver50 * .2;
	}

	if (kwDemand > 50) {
		customerCharge = (kwhUsage * .05022) + demandRateUnder50 + (demandRateOver50 * (kwDemand - 50));
	}
	else { 
		customerCharge = (kwhUsage * .05022) + demandRateUnder50;
	}
	
	return customerCharge;
}
