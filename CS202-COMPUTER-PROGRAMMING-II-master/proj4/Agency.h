#include "Car.h"
#include "Sensor.h"
using namespace std;
#ifndef AGENCY_H
#define AGENCY_H
#define CARS 5
class Agency
{
	public:
			Agency();
			char *getName();
			int getZip();
			void setName(char *name);
			void setZip(int zipCode);
			void readData();
			void printData();
			void printAvailable();
			void mostExpensive();
			void displaySensors();
			rentalCar &operator[](const int index);
	private:
			char m_name[MAXSIZE];
			int m_zipcode;
			rentalCar m_inventory[CARS];
};
#endif