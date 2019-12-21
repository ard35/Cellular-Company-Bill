/*
CellularCompanyRates.cpp
Author : Andre Da Silva
Class : ECET 344 - 001
Date : 10 / 10 / 19
Description : This program will calculate and print the bill for a tellphone company given set rates of regular and premium accounts.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {

	const double regBase = 10.00, premBase = 25.00, regCharge = 0.20, premChargeDay = 0.10, premChargeNight = 0.05;
	const int regBaseTime = 50, premBaseDayTime = 75, premBaseNightTime = 100;
	double regAmount, premAmount;
	double totalAmountDue;
	double regMinutes, premDayMinutes, premNightMinutes;
	int accountNumber;

	char type;

	cout << "Enter Account Number: ";
	cin >> accountNumber;

	cout << "Enter Service Type: ";
	cin >> type;

	if (type == 'r' || type == 'R') {
		cout << "Enter minutes used: ";
		cin >> regMinutes;

		switch (regMinutes <= 50) {
		case 1:
			regAmount = regBase;
			totalAmountDue = regAmount;

			cout << fixed << showpoint << setprecision(2);
			cout << endl;
			cout << left << "Account Number: " << setw(36) << setfill('.') << right  << " " << accountNumber << endl;
			cout << left << "Service Type: " << setw(45) << setfill('.') << right << " Regular" << endl;
			cout << left << "Minutes Service Used: " << setw(30) << setfill('.') << right << " " << regMinutes << endl;
			cout << left << "Account Due: " << setw(40) << setfill('.') << right << " $" << totalAmountDue << endl;

			break;
		case 0:
			regAmount = regBase + ((regMinutes - regBaseTime)*(regCharge));
			totalAmountDue = regAmount;

			cout << fixed << showpoint << setprecision(2);
			cout << endl;
			cout << left << "Account Number: " << setw(36) << setfill('.') << right << " " << accountNumber << endl;
			cout << left << "Service Type: " << setw(45) << setfill('.') << right << " Regular" << endl;
			cout << left << "Minutes Service Used: " << setw(30) << setfill('.') << right << " " << regMinutes << endl;
			cout << left << "Account Due: " << setw(40) << setfill('.') << right << " $" << totalAmountDue << endl;

			break;

		}
	}
	else if (type == 'p' || type == 'P') {
		cout << "Enter day minutes used: ";
		cin >> premDayMinutes;
		cout << "Enter night minutes used: ";
		cin >> premNightMinutes;

		switch (premDayMinutes <= 75) {
		case 1:
			switch (premNightMinutes <= 100) {
			case 1:
				premAmount = premBase;
				totalAmountDue = premAmount;

				cout << fixed << showpoint << setprecision(2);
				cout << endl;
				cout << left << "Account Number: " << setw(36) << setfill('.') << right << " " << accountNumber << endl;
				cout << left << "Service Type: " << setw(45) << setfill('.') << right << " Premium" << endl;
				cout << left << "Day Minutes Service Used: " << setw(26) << setfill('.') << right << " " << premDayMinutes << endl;
				cout << left << "Night Minutes Service Used: " << setw(24) << setfill('.') << right << " " << premNightMinutes << endl;
				cout << left << "Account Due: " << setw(40) << setfill('.') << right << " $" << totalAmountDue << endl;

				break;
			case 0:
				premAmount = premBase + ((premNightMinutes - premBaseNightTime)*(premChargeNight));
				totalAmountDue = premAmount;

				cout << fixed << showpoint << setprecision(2);
				cout << endl;
				cout << left << "Account Number: " << setw(36) << setfill('.') << right << " " << accountNumber << endl;
				cout << left << "Service Type: " << setw(45) << setfill('.') << right << " Premium" << endl;
				cout << left << "Day Minutes Service Used: " << setw(26) << setfill('.') << right << " " << premDayMinutes << endl;
				cout << left << "Night Minutes Service Used: " << setw(24) << setfill('.') << right << " " << premNightMinutes << endl;
				cout << left << "Account Due: " << setw(40) << setfill('.') << right << " $" << totalAmountDue << endl;

				break;
			}
			
			break;

		case 0:
			switch (premNightMinutes <= 100) {
			case 1:
				premAmount = premBase + ((premDayMinutes - premBaseDayTime)*(premChargeDay));
				totalAmountDue = premAmount;

				cout << fixed << showpoint << setprecision(2);
				cout << endl;
				cout << left << "Account Number: " << setw(36) << setfill('.') << right << " " << accountNumber << endl;
				cout << left << "Service Type: " << setw(45) << setfill('.') << right << " Premium" << endl;
				cout << left << "Day Minutes Service Used: " << setw(26) << setfill('.') << right << " " << premDayMinutes << endl;
				cout << left << "Night Minutes Service Used: " << setw(24) << setfill('.') << right << " " << premNightMinutes << endl;
				cout << left << "Account Due: " << setw(40) << setfill('.') << right << " $" << totalAmountDue << endl;

				break;

			case 0:
				premAmount = premBase + ((premDayMinutes - premBaseDayTime)*(premChargeDay)+(premNightMinutes - premBaseNightTime)*(premChargeNight));
				totalAmountDue = premAmount;

				cout << fixed << showpoint << setprecision(2);
				cout << endl;
				cout << left << "Account Number: " << setw(36) << setfill('.') << right << " " << accountNumber << endl;
				cout << left << "Service Type: " << setw(45) << setfill('.') << right << " Premium" << endl;
				cout << left << "Day Minutes Service Used: " << setw(26) << setfill('.') << right << " " << premDayMinutes << endl;
				cout << left << "Night Minutes Service Used: " << setw(24) << setfill('.') << right << " " << premNightMinutes << endl;
				cout << left << "Account Due: " << setw(40) << setfill('.') << right << " $" << totalAmountDue << endl;

				break;
			}

			break;
		}
	}
	else {

		cout << endl;
		cout << "ERROR: Invalid account number or service type. Please enter a number for 'Account Number' and r/R for regular or p/P for premium for 'Service Type'" << endl;
	}

	cout << endl;
	cout << "Thank you for using our telephone company for your calling services!" << endl;
	cout << endl;

	system("PAUSE");
	return 0;

}
