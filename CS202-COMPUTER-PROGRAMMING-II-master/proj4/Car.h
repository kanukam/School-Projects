#include "Sensor.h"
#include<iostream>
#ifndef CAR_H
#define CAR_H
#define MAXSIZE 256
#define SENSORSIZE 3
using namespace std;
class rentalCar
{
	public:
			rentalCar();
			rentalCar(char *make,char *model,int year,float basePrice,Sensor *S1);
			rentalCar(rentalCar &car);
			char *getMake();
			char *getModel();
			int getYear();
			bool getAvailable();
			float getBasePrice();
			void setMake(const char *make);
			void setModel(const char *model);
			void setAvailable(bool available);
			void setYear(int year);
			void setBasePrice(const float price);
			void setOwner(const char *owner);
			void updatePrice();
			void estimateCost(int days);
			rentalCar &operator+(const char *owner);
			rentalCar &operator+(Sensor name);
			friend ostream &operator <<(ostream &os,rentalCar &Car);
			
	private:
			char m_make[MAXSIZE];
			char m_model[MAXSIZE];
			int m_year;
			Sensor m_sensors[SENSORSIZE];
			float m_baseprice;
			float m_finalprice;
			bool m_available;
			char m_owner[MAXSIZE];
};
//return the strings length
size_t myStringLength(const char *str);
#endif
	