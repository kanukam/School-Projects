#include<iostream>
#include<fstream>
#include "Agency.h"
#include "Sensor.h"
#include "Car.h"
using namespace std;
Agency::Agency()
{
	myStringCopy(m_name,"\0");
	m_zipcode = 0;
}
//get and set functions	
char *Agency::getName()
{
	return m_name;
}
int Agency::getZip()
{
	return m_zipcode;
}
void Agency::setName(char *name)
{
	myStringCopy(m_name,name);
}
void Agency::setZip(int zipCode)
{
	m_zipcode = zipCode;
}
//Reads all data from a structure file 
void Agency::readData()
{
	cout << "Enter a file name: ";
	rentalCar *Cars = m_inventory;
	char temp[50];
	cin >> temp;
	ifstream inputFile;
	inputFile.open(temp);
	if(inputFile.fail())
	{
		cout << "Your file does not exist" << endl;
		return;
	}
	char tempName[30];
	int tempZip;
	int tempYear;
	char tempMake[30];
	char tempModel[30];
	char tempOwner[30];
	char tempSensorName[30];
	float tempPrice;
	bool tempAvailable;
	inputFile >> tempName >> tempZip;
	setName(tempName);
	setZip(tempZip);
	Sensor tempSensor;
	char tempSensor2[30];
	char *ptr = tempSensor2;
	char base[2] = "\0";
	for(int i = 0;i<5;i++)
	{
		inputFile >>tempYear >>tempMake >> tempModel >> tempPrice;
		Cars->setYear(tempYear);
		Cars->setMake(tempMake);
		Cars->setModel(tempModel);
		Cars->setBasePrice(tempPrice);
		int j = 0;
		inputFile.get();
		inputFile.get();
		char ch;
		while(inputFile >> noskipws >> ch )
		{
			if(ch != '}' && ch != ' ')
			{
				*ptr = ch;
				ptr++;
			}
			else
			{
				*ptr++ = '\0';
				ptr= tempSensor2;
				tempSensor.setType(tempSensor2);
				m_inventory[i] + tempSensor;
				if(ch == '}')
				{
					break;
				}
				myStringCopy(tempSensor2,base);
				ptr = tempSensor2;
			}
		}
		inputFile >> skipws >> tempAvailable;
		Cars->setAvailable(tempAvailable);
		if(Cars->getAvailable() == false)
		{
			inputFile >> skipws >> tempOwner;
			Cars->setOwner(tempOwner);
		}
		Cars++;
	}	
	inputFile.close();
	cout << "The data has been stored." << endl;
}
//operator overload
rentalCar &Agency::operator[](const int index)
{
	return m_inventory[index];
}
//uses operator overload for rental car and prints agency info
void Agency::printData()
{
	cout << m_name << " " << m_zipcode << endl;
	for(int i = 0;i < 5;i++)
	{
		cout << m_inventory[i] << endl;
	}
}
//traverses through inventory and fins most expensive array address
void Agency::mostExpensive()
{
	float counter = 0;
	rentalCar temp;
	char name[25];
	char response[25];
	for(int i = 0;i<5;i++)
	{
		if(m_inventory[i].getBasePrice() > counter)
		{
			counter = m_inventory[i].getBasePrice();
			temp = m_inventory[i];
		}
	}
	cout << "The most expensive car is the: " << temp.getYear() << " "
	     << temp.getMake() << " " << temp.getModel() << " for $" 
	     << temp.getBasePrice() << endl;
	cout << "What is your name: ";
	cin >> name;
	cout << "Would you like to rent this car (YES or NO): ";
	cin >> response;
	if(myStringCompare(response,"YES") == 0)
	{
		if(temp.getAvailable() == 0)
		{
			cout << "Sorry this vehicle is not available." << endl;
		}
		else
		{
			for(int i=0;i<5;i++)
			{
				if(temp.getBasePrice() == 
	  			m_inventory[i].getBasePrice())
				{
					m_inventory[i] + name;
					m_inventory[i].setAvailable(0);
				}
			}
			cout << "You have been added to this vehicle." << endl;
		}
	}
}
//displays sensor count
void Agency::displaySensors()
{
	int gps = Sensor::getGpsCnt()/3;
	int cam = Sensor::getCamCnt()/3;
	int lidar = Sensor::getLidarCnt()/3;
	int radar = Sensor::getRadarCnt()/3;
	cout << "The total number of gps sensors is: " << gps 
	     << endl;
	cout << "The total number of camera sensors is: " 		
             << cam << endl;
	cout << "The total number of radar sensors is: " 
	     << radar << endl;
	cout << "The total number of lidar sensors is: " 
	     << lidar << endl;
}	

