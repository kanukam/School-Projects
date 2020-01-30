#ifndef RENTALCAR_H
#define RENTALCAR_H
#include<iostream>
using namespace std;
class rentalCar 
{
	public:
		rentalCar();
		rentalCar(int year,char *make, char *model, float price, bool available);
		//Set Functions
		void setYear(int year);
		void setMake(char *make);
		void setModel(char *model);
		void setPrice(float price);
		void setAvailable(bool available);
		//Get functions
		int getYear();
		char *getMake();
		char *getModel();
		float getPrice();
		bool getAvailable();
		void print();
		float estimateCost(int days);

	private:
		int m_year;
		char m_make[256];
		char m_model[256];
		float m_price;
		bool m_available;
};
char *myStringCopy(char *destination, const char *source);
#endif