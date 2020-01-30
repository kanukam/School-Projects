//Name:Kennedy Anukam
//Purpose:Working with classes
//Date:2/24/2019
//Class:Cs 202
#include<iostream>
#include "Sensor.h"
#include "Agency.h"
#include "Car.h"
using namespace std;
void printMenu();
int main()
{
	printMenu();
	int cmd;
	cin >> cmd;
	Agency Agency1;
	while(cmd != 5)
	{
		switch(cmd)
		{
			case 1:
				Agency1.readData();
			break;
			case 2:
				Agency1.printData();
			break;
			case 3:
				Agency1.displaySensors();
			break;
			case 4:
				Agency1.mostExpensive();
			break;
		}
		printMenu();
		cin >> cmd;
	}
	return 0;
}
void printMenu()
{
	cout << "1) Enter an input file " << endl;
	cout << "2) Print all data " << endl;
	cout << "3) Print amount of sensors " << endl;
	cout << "4) Most expensive car " << endl;
	cout << "5) Exit " << endl;
	cout << "Please enter your selection: ";
}
