#include<iostream>
#include "Vehicle.h"
using namespace std;
//sets static to 0 initially
int Vehicle:: s_idgen = 0;
//sets the const with initializer list, increments static, states default ctor
Vehicle::Vehicle():
		m_vin(s_idgen)
{
		incrementStatic();
		cout << "Vehicle #" << getVin() << ": " << "Default-ctor"<< endl;
}
//sets the const with initializer list, sets vin, states parametized ctor
Vehicle::Vehicle(const int vinNumber, const float *lla):
	m_vin(vinNumber)
{
	for(int i=0;i<3;i++)
	{
		m_lla[i] = *lla;
		lla++;	
	}
	cout << "Vehicle #" << getVin() << ": " << "Parametized-ctor"<< endl;
}
//simply increments the static when called		
void Vehicle::incrementStatic()
{
	s_idgen++;
}
//return vin number
const int Vehicle::getVin() const
{
	return m_vin;
}
//copy ctor
Vehicle::Vehicle(const Vehicle & vehicle_1):
		m_vin(s_idgen)
{
	incrementStatic();
	for(int i=0;i<3;i++)
	{
		m_lla[i] = vehicle_1.m_lla[i];
	}
	cout << "Vehicle #" << getVin() << ": " << "Copy-ctor"<< endl;
}
//assignment operator
Vehicle & Vehicle::operator=(const Vehicle & vehicle_1)
{
	for(int i=0;i<3;i++)
	{
		m_lla[i] = vehicle_1.m_lla[i];
	}
	cout << "Vehicle #" << getVin() << ": " << "Assignment"<< endl;
	return *this;
}
//dtor
Vehicle::~Vehicle()
{
	cout << "Vehicle #" << getVin() << ": " << "Dtor"<< endl;
}
//returns current vin number not yet assigned
int Vehicle::getIdgen() 
{
	return s_idgen;
}
//default output, practicing overloading
void Vehicle::move(const float *lla)
{
	cout << "Vehicle #" << getVin() << ": " << "CANNOT MOVE - I DON'T KNOW HOW"<< endl;
}
//insertion operator which prints data
ostream & operator <<(ostream &os,const Vehicle &V)
{
	float value1, value2, value3;
	value1 = V.m_lla[0];
	value2 = V.m_lla[1];
	value3 = V.m_lla[2];
	os << "Vehicle #" << V.getVin() << " @ [" << value1;
	os << ", " << value2 << ", " << value3 << "]" << endl;
	return os;
}
