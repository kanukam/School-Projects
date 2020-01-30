using namespace std;
#include<iostream>
#include "Vehicle.h"
//default ctor
Vehicle::Vehicle()
{
	cout << "Vehicle: Default-ctor" << endl;
}
//parametized ctor
Vehicle::Vehicle(const float *lla)
{
	for(int i =0;i<3;i++)
	{
		m_lla[i] = *lla;
		lla++;
	}
	cout << "Vehicle: Parametized-ctor" << endl;
}
//setter
void Vehicle::SetLLA(float *lla)
{
	for(int i =0;i<3;i++)
	{
		m_lla[i] = *lla;
		lla++;
	}
}	
//copy ctor
Vehicle::Vehicle(const Vehicle &v1)
{
	for(int i =0;i<3;i++)
	{
		m_lla[i] = v1.m_lla[i];
	}
	cout << "Vehicle: Copy-ctor" << endl;	
}
//virtual dtor
Vehicle::~Vehicle()
{
	cout << "Vehicle: dtor" << endl;
}
//does not need to do anything, will never be used as base object cannot be created
void Vehicle::serialize(ostream & os)
{

}
//uses the virtual serialize method
ostream & operator <<(ostream & os,Vehicle &V)
{
	V.serialize(cout);
	return os;
}
//Assignment operator
Vehicle & Vehicle::operator=(const Vehicle &v1)
{
	for(int i =0;i<3;i++)
	{
		m_lla[i] = v1.m_lla[i];
	}
	cout << "Vehicle: Assignment" << endl;	
	return *this;
}
