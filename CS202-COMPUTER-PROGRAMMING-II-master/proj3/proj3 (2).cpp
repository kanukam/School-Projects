//Name: Kennedy Anukam
//Course: CS 202
//Project 3
//Purpose: Use structs and classes to take in data from a car file
#include <iostream>
#include <fstream>
#include "RentalCar.h"
#define AMOUNT_OF_RENTAL_AGENCIES 3
#define MAXSIZE 256
#define ZIPCODE 5
struct rentalAgency
{
	char name[MAXSIZE];
	int zipCode[ZIPCODE];
	rentalCar inventory[5];
};
using namespace std;
void inputFile(rentalAgency *p_agency);
void printCars(rentalAgency *p_agency);
rentalCar readCars(ifstream &file);
void readAgency(ifstream &file,rentalAgency *p_agency);
void estimateCost(rentalAgency *p_agency);
void mostExpensive(rentalAgency *p_agency);
void printToOuput(rentalAgency *p_agency);
void getZip(int zipCode,int *p_ptr);
void printZip(int *p_ptr);
void menu();
int myStringCompare(const char *str1, const char *str2);
size_t myStringLength(const char *str);
char *myStringCat(char *destination, const char *source);
int main()
{
	//array of structs with 3 agencies
	rentalAgency companies[AMOUNT_OF_RENTAL_AGENCIES];
	menu();
	int cmd;
	cin >> cmd;
	while(cmd != 6)
	{
		switch(cmd)
		{
			case 1:
				inputFile(companies);
			break;
			case 2:
				printCars(companies);	
			break;
			case 3:
				estimateCost(companies);
			break;
			case 4:
				mostExpensive(companies);
			break;
			case 5:
				printToOuput(companies);
			break;
		}
		cout << endl;
		menu();
		cin >> cmd;
	}	
	return 0;
}
void menu()
{
	cout << "[1] Enter an input file" << endl
	     << "[2] Print out all data from agencies" << endl
	     << "[3] Estimate car rental cost" << endl
             << "[4] Print most expensive car" << endl
	     << "[5] Print available cars to output file" << endl
	     << "[6] Exit program" << endl
	     << "Please enter your selection : ";
}
//takes in the agency, inputs with input functions for agencys and cars
void inputFile(rentalAgency *p_agency)
{
	//pointer that points to inventory in agency[0] for cars
	ifstream file;
	char arr[25];
	cout << "Please enter a file name: ";
	cin >> arr;
	file.open(arr);
	for(int j = 0;j < 3;j++)
	{
		rentalCar *p_inventory = p_agency->inventory;
		readAgency(file,p_agency);
		for(int i=0;i<5;i++)
		{
			*p_inventory = readCars(file);
			//increments to next car, each agency has 5 cars
			p_inventory++;
		}
		//increments to next agency 3 agencies
		p_agency++;
	}
	cout << "The data has been saved" << endl;
	file.close();			
}
//uses class print function and manually prints zipcode and agency name
void printCars(rentalAgency *p_agency)	
{
	for(int j = 0;j<3;j++)
	{
		rentalCar *p_inventory = p_agency->inventory;
		cout << p_agency->name << " ";
		printZip(p_agency->zipCode);
		for(int i=0;i < 5;i++)
		{
			p_inventory->print();
			p_inventory++;
		}
		p_agency++;
	}
}
//function just to read from file into cars
rentalCar readCars(ifstream &file)
{ 
	int year;
	char make[25];
	char model[25];
	float price;
	bool available;
	char temp[256];
	file >> year;
 	file >> make;
	file>> model;
	file >> price;
	file >> available;
	rentalCar car(year,make,model,price,available);
	return car;
}
//Estimates cost by ascending through the loop to find the car then prints the //specs
void estimateCost(rentalAgency *p_agency)
{
	int company;
	int car;
	int days;
	rentalCar *p_inventory = p_agency->inventory;
	cout << "Which company would you like to rent a car from: ";
	cin >> company;
	cout << "Which car number would you like: ";
	cin >> car;
	cout << "How many days would you like to rent the car: ";
	cin >> days;
	int j = 0;
	int i = 0;
	while(i < company)
	{
		p_agency++;
		i++;

		for(int k = 0;k < 5; k++)
		{
			p_inventory++;
		}
	}
	while(j < car)
	{
		p_inventory++;
		j++;
	}
	cout << "The estimated cost of car "<< car << " from company "<<company 
	     << " is $"<<p_inventory->estimateCost(days) << endl;
}
//Ascends through classes to find most expensive car,
//max becomes previous inventory highest
void mostExpensive(rentalAgency *p_agency)
{
	
	rentalCar *p_expense;
	float max = 0;
	for(int j = 0;j < 3;j++)
	{
		rentalCar *p_inventory = p_agency->inventory;
		for(int i=0;i< 5;i++)
		{
			if(p_inventory->getPrice() > max)
			{
				max = p_inventory->getPrice();
				p_expense = p_inventory;
				p_inventory++;
			}
		}
		//increments to next agency 3 agencies
		p_agency++;
	}
	cout << "The most expensive car is the ";
	cout << p_expense->getYear() << " ";
	cout << p_expense->getMake() << " " << p_expense->getModel() << " at $";
	cout << p_expense->getPrice() << endl;
}
//outputs data to chosen file
void printToOuput(rentalAgency *p_agency)
{
	ofstream file;
	char temp[25];
	cout << "Enter a file name to print available cars to ";
	cin >> temp;
	file.open(temp);
	for(int j = 0;j< 3;j++)
	{
		rentalCar *p_inventory = p_agency->inventory;
		for(int i = 0;i<5;i++)
		{
			if(p_inventory->getAvailable() == 1)
			{
				file << p_inventory->getYear() << " " << 					p_inventory->getMake() << " " << 					p_inventory->getModel() << " " << "," << " " 					<<"$" << p_inventory->getPrice() <<" per day , " 					<<"Available: " << boolalpha << 				p_inventory->getAvailable() << endl;
			}
			p_inventory++;
		}
		p_agency++;
	}
	cout << "The data has been stored "<<endl;
	file.close(); 
}
//takes in pointer and uses another pointer to traverse array
void getZip(int zipCode,int *ptr)
{
	int var;
	int *p_tail = ptr + 4;
	while(zipCode >=10)
	{
		var = zipCode % 10;
		*p_tail = var;
		p_tail--;
		zipCode /= 10;
	}
	*p_tail = zipCode;
}
//prints passed in values zipcode
void printZip(int *p_ptr)
{
	for(int i = 0;i < 5;i++)
	{
		cout << *p_ptr;
		p_ptr++;
	}
	cout << endl;
}
//Reads struct agency data
void readAgency(ifstream &file,rentalAgency *p_agency)
{
	char arr[256];
	int zip;
	file >> arr;
	file >> zip;
	myStringCopy(p_agency->name,arr);
	getZip(zip,p_agency->zipCode);	
}	
//function to add source to end of destination string
char *myStringCat(char *destination, const char *source)
{
	char *ptr = destination;
	while(*ptr != '\0')
	{
		ptr++;
	}
	while(*source != '\0')
	{
		*ptr = *source;
		ptr++;
		source++;
	}
	*ptr = '\0';
	return destination;
}	
//return the strings length
size_t myStringLength(const char *str)
{
	int count = 0;
	while(*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}	
//checks to see which string comes first value wise
int myStringCompare(const char *str1, const char *str2)
{
	
	while(*str1 != '\0' || *str2 != '\0')
	{
		if(*str1 < *str2)
		{
			return -1;
		}
		if(*str1 > *str2)
		{
			return 1;
		}
		if(*str1 != '\0')
		{
			str1++;
		}
		if(*str2 != '\0')
		{
			str2++;
		}
	}	
	return 0;
}		
