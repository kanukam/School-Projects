#include<iostream>
#include<fstream>
#include "RentalCar.h"
using namespace std;

//function for default constructor
rentalCar::rentalCar()
{
	m_year = 2000;
	myStringCopy(m_make,"UNKNOWN");
	myStringCopy(m_model,"UNKNOWN");
	m_price = -1000;
	m_available = false;
}
//function for parametrized constructor that takes in all inputs and uses set functions
rentalCar::rentalCar(int year,char *make, char *model, float price, bool available)
{
	setYear(year);
	setMake(make);
	setModel(model);
	setPrice(price);
	setAvailable(available);
}
//set functions
void rentalCar::setYear(int year)
{
	m_year = year;
}
void rentalCar::setMake(char *make)
{
	myStringCopy(m_make,make);
}
void rentalCar::setModel(char *model)
{
	myStringCopy(m_model,model);
}
void rentalCar::setPrice(float price)
{
	m_price = price;
}
void rentalCar::setAvailable(bool available)
{
	m_available = available;
}
int rentalCar::getYear()
{
	return m_year;
}
//get functions
char * rentalCar::getMake()
{
	return m_make;
}
char * rentalCar::getModel()
{
	return m_model;
}
float rentalCar::getPrice()
{
	return m_price;
}
bool rentalCar::getAvailable()
{
	return m_available;
}
//print cars
void rentalCar::print()
{
	cout << m_year << " " << m_make << " " << m_model << " "
	     << "," << " " << "$" <<m_price <<" per day , " 
	     <<"Available: " << boolalpha << m_available << endl;
}
//estimate cost
float rentalCar::estimateCost(int days)
{
	return days * m_price;
}
//string copy functions
char *myStringCopy(char *destination, const char *source)
{
	char *ptr = destination;
	while(*source != '\0')
	{
		*ptr = *source;
		ptr++;
		source++;
	}
	*ptr = '\0';
	return destination;
}
