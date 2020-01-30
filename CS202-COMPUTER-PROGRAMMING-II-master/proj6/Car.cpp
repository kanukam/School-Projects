#include<iostream>
#include "Vehicle.h"
#include "Car.h"
using namespace std;
//default ctor
Car::Car()
{
	cout << "Car: Default-ctor"<<endl;
	m_throttle = 0;
}
//parametized ctor, used vehichle parametized ctor, throttle to 0
Car::Car(float *lla):
	Vehicle(lla)
{
	m_throttle = 0;
	cout << "Car: Parametized-ctor"<<endl;
}
//copy ctor, uses based copy ctor too
Car::Car(const Car & c1):
	Vehicle(c1)
{
	m_throttle = c1.m_throttle;
	cout << "Car: Copy-ctor"<<endl;
}
//virtual dtor, so pointer can destroy derived as well
Car::~Car()
{
	cout << "Car: Dtor"<<endl;
}
//Assignment operator, uses base version too
Car & Car::operator=(Car &c1)
{
	Vehicle::operator=(c1);
	m_throttle = c1.m_throttle;
	cout << "Car: Assignment" << endl;
	return *this;
}
// virtual move functions sets to position, changes throttle to 75
void Car::Move(float *lla)
{
	cout << "Car: DRIVE to destination, with throttle at 75 "<<endl;
	drive(75);
	for(int i = 0;i <3;i++)
	{
		m_lla[i] = *lla;
		lla++;
	}
}
//setter
void Car::drive(int throttle)
{
	m_throttle = throttle;
}
//virtual serialize, outputs proper data
void Car::serialize(ostream &os)
{
	float v1;
	float v2;
	float v3;
	v1 = m_lla[0]; 
	v2 = m_lla[1];
	v3 = m_lla[2];
	os << "Car: Throttle: "<< m_throttle << " @ ["<<v1
	<< " " << v2 << " " << v3 << "]";
}
