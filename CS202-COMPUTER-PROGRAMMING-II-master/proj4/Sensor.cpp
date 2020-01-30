#include<iostream>
#include<fstream>
#include "Sensor.h"
using namespace std;
int Sensor:: gps_cnt = 0;
int Sensor:: camera_cnt = 0;
int Sensor:: lidar_cnt = 0;
int Sensor:: radar_cnt = 0;
int myStringCompare(const char *str1, const char *str2)
{
	
	while(*str1 != '\0' || *str2 != '\0')
	{
		if(*str1 < *str2)
		{
			return -1;
		}
		if(*str1 > *str2)
		{
			return 1;
		}
		if(*str1 != '\0')
		{
			str1++;
		}
		if(*str2 != '\0')
		{
			str2++;
		}
	}	
	return 0;
}	
char *myStringCat(char *destination, const char *source)
{
	char *ptr = destination;
	while(*ptr != '\0')
	{
		ptr++;
	}
	while(*source != '\0')
	{
		*ptr = *source;
		ptr++;
		source++;
	}
	*ptr = '\0';
	return destination;
}	
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
//Sets type based on sensor type passed into it
void Sensor::setType(char *type)
{
	if(myStringCompare(type,"gps")== 0)
	{
		gps_cnt++;
		m_extracost = 5;
	}
	if(myStringCompare(type,"camera")== 0)
	{
		camera_cnt++;
		m_extracost = 10;
	}
	if(myStringCompare(type,"lidar")== 0)
	{
		lidar_cnt++;
		m_extracost = 15;
	}
	if(myStringCompare(type,"radar")== 0)
	{
		radar_cnt++;
		m_extracost = 20;
	}
	else
	{
		m_extracost = 0;
	}
	myStringCopy(m_type,type);
}
//default ctor sets type to none when object is created
Sensor::Sensor()
{
	char arr[5] = "none";
	setType(arr);
}
//sets type to sensor based on char array passed into it
Sensor::Sensor(char *type)
{
	setType(type);
}
//copy ctor, copies sensor
Sensor::Sensor(Sensor &s)
{
	setType(s.m_type);
}
//functions that returns sensor variables in class
char *Sensor::getType()
{
	return m_type;
}
int Sensor::getGpsCnt()
{
	return gps_cnt;
}
int Sensor::getCamCnt()
{
	return camera_cnt;
}
int Sensor::getLidarCnt()
{
	return lidar_cnt;
}
int Sensor::getRadarCnt()
{
	return radar_cnt;
}
void Sensor::resetGpsCnt()
{
	gps_cnt = 0;
}
void Sensor::resetCamCnt()
{
	camera_cnt = 0;
}
void Sensor::resetLidarCnt()
{
	lidar_cnt = 0;
}
void Sensor::resetRadarCnt()
{
	radar_cnt = 0;
}
float Sensor::getExtraCost()
{
	return m_extracost;
}
// compares two sensors
bool operator==(Sensor &s1,Sensor &s2)
{
	if(myStringCompare(s1.getType(),s2.getType())==0)
	{
		return true;
	}
	return false;
}
