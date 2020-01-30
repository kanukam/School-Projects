#include<iostream>
#include "Vehicle.h"
#include "Car.h"
#include<string.h>
#include<cstring>
using namespace std;
Car::Car():
	m_throttle(0)
{
	cout << "Car #" << getVin() << ": " << "Default-ctor"<< endl;
}
Car::Car(char *plates,int vin,float *lla):
	Vehicle(vin, lla),
	m_throttle(0)
{
	strcpy(m_plates,plates);
	cout << "Car #" << getVin() << ": " << "Parametized-ctor"<< endl;
}
Car & Car::operator =(const Car & Car)
{
	m_throttle = Car.m_throttle;
	strcpy(m_plates,Car.m_plates);
	for(int i=0;i<3;i++)
	{
		m_lla[i] = Car.m_lla[i];
			
	}
	cout << "Car #" << getVin() << ": " << "Assignment"<< endl;
	return *this;
}
Car::Car(Car &c):
	Vehicle(c)
{
	m_throttle = c.m_throttle;
	strcpy(m_plates,c.m_plates);
	cout << "Car #" << getVin() << ": " << "Copy-ctor"<< endl;
}
Car::~Car()
{
	cout << "Car #" << getVin() << ": " << "Dtor"<< endl;
}
void Car::drive(int throttle)
{
	m_throttle = throttle;
}
void Car::move(float *lla)
{
	cout << "Car #" << getVin() << ": " << "DRIVE to destination, with throttle @75"<< endl;
	for(int i=0;i<3;i++)
	{
		m_lla[i] = *lla;
		lla++;	
	}
	drive(75);
}
char *Car::getPlates()
{
	return m_plates;
}
int Car::getThrottle()
{
	return m_throttle;
}
ostream & operator <<(ostream &os,Car &c1)
{
	float value1, value2, value3;
	value1 = c1.m_lla[0];
	value2 = c1.m_lla[1];
	value3 = c1.m_lla[2];
	os << "Car #" << c1.getVin() << " Plates: " << c1.getPlates()
	<< ", Throttle: "<< c1.getThrottle() << " throttle @ [" << value1;
	os << ", " << value2 << ", " << value3 << "]" << endl;
	return os;
}
