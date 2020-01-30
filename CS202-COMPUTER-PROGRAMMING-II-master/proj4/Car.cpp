#include "Car.h"
#include<iostream>
using namespace std;
// default ctor
rentalCar::rentalCar()
{
	myStringCopy(m_make,"\0");
	myStringCopy(m_model,"\0");
	m_year = 0;
	m_baseprice = 0;
	m_finalprice = 0;
	m_available = 0;
	myStringCopy(m_owner,"\0");
}
//parametized ctor
rentalCar::rentalCar(char *make,char *model,int year,float basePrice,Sensor *S1)
{
	setMake(make);
	setModel(model);
	setYear(year);
	setBasePrice(basePrice);
	Sensor *s1 = S1;
	Sensor *s2 = m_sensors;
	for(int i = 0;i < 3;i++)
	{
		*s2 = *s1;
		s2++;
		s1++;
	}
}
//copy ctor
rentalCar::rentalCar(rentalCar &car)
{
	setMake(car.m_make);
	setModel(car.m_model);
	setYear(car.m_year);
	setBasePrice(car.m_baseprice);
	Sensor *s1 = car.m_sensors;
	Sensor *s2 = m_sensors;
	for(int i = 0;i < 3;i++)
	{
		*s2 = *s1;
		s2++;
		s1++;
	}
}
// set functions
void rentalCar::setMake(const char *make)
{
	myStringCopy(m_make,make);
}
void rentalCar::setModel(const char *model)
{
	myStringCopy(m_model,model);
}
void rentalCar::setOwner(const char *owner)
{
	myStringCopy(m_owner,owner);
}
void rentalCar::setYear(const int year)
{
	m_year = year;
}
void rentalCar::setBasePrice(float price)
{
	m_baseprice = price;
}
//return functions
char *rentalCar::getMake() 
{
	return m_make;
}
char *rentalCar::getModel() 
{
	return m_model;
}
int rentalCar::getYear() 
{
	return m_year;
}
float rentalCar::getBasePrice()
{
	return m_baseprice;
}
bool rentalCar::getAvailable()
{
	return m_available;
}
void rentalCar::setAvailable(bool available)
{
	m_available = available;
}
//operator overload to print class rentalCarr object
ostream &operator <<(ostream &os,rentalCar &Car)
{
	os << Car.m_year << " " << Car.m_make << " " << Car.m_model << ", " << 		"$" << Car.m_baseprice << " " << "per day, " <<"{";
	Sensor *sensor1 = Car.m_sensors;
	for(int i = 0;i < 3;i++)
	{
		if(myStringCompare(sensor1->getType(),"none")!=0)
		{
			os << sensor1->getType();
			if(i==0 || i==1)
			{
				os << " ";
			}
		}
		sensor1++;
	}
	os << "} " << "Available: " << boolalpha << Car.m_available << " ";
	if(myStringCompare(Car.m_owner,"\0") != 0)
	{
		os << "Owner: " << Car.m_owner;
	}
	return os;
}
void rentalCar::updatePrice()
{
	float extra;
	Sensor *sensor1 = m_sensors;
	for(int i = 0;i < 3;i++)
	{
		extra+=sensor1->getExtraCost();
		sensor1++;
	}	
	m_finalprice = m_baseprice + extra;
}
void rentalCar::estimateCost(int days)
{
	cout << "This car will cost" << "$" << days * m_baseprice << endl;
}
rentalCar & rentalCar::operator+(const char *owner)
{
	myStringCopy(m_owner,owner);
	return *this;
}
//operator overload to add a passed in sensor
rentalCar & rentalCar::operator+(Sensor name)
{
	Sensor *sensor1 = m_sensors;
	char temp[25];
	for(int i = 0;i < 3;i++)
	{
		if(myStringCompare(sensor1->getType(),"none")==0)
		{
			sensor1->setType(name.getType());
			return *this;
		}
		sensor1++;
	}
	return *this;
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
