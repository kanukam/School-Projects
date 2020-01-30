//Authour:Kennedy Anukam
//Date:3/31/19
//Purpose:Dynamic Memory Allocation
#include "MyString.h"
#include <cstring>
#include <string.h>
using namespace std;
//ctor sets char array to NULL, size to 0
MyString::MyString()
{
	m_buffer = NULL;
	m_size = 0;
}
//parameterized ctor try and catch to test if memory allocation succeeded or failed
MyString::MyString(const char * str)
{
	size_t len = strlen(str);
	try
	{
		buffer_allocate(len);
		strcpy(m_buffer,str);
	}
	catch(const bad_alloc &bad)
	{
		cout << "ALLOCATION HAS FAILED" << endl;
	}
}
//Copy ctor
MyString::MyString(const MyString & other_myStr)
{
	size_t len = other_myStr.length();
	buffer_allocate(len);
	strcpy(m_buffer,other_myStr.c_str());
}
//dtor
MyString::~MyString()
{
	delete [] m_buffer;
	m_buffer = NULL;
}
//compares two objects alphabetically
bool MyString::operator== (const MyString & other_myStr) const
{
	if(!strcmp(m_buffer,other_myStr.c_str()))
	{
		return true;
	}
	return false;
}			
//assignment operator
MyString & MyString::operator= (const MyString & other_myStr) 
{
	if(this != &other_myStr)
	{
		size_t len = other_myStr.length();
		buffer_deallocate();
		buffer_allocate(len);   
		strcpy(m_buffer,other_myStr.c_str());
	}
	return *this;
}
//returns a concat oobject
MyString MyString::operator+ (const MyString & other_myStr) const
{
	char str[80];
	strcpy(str,m_buffer);
	return MyString(strcat(str,other_myStr.c_str()));
}
//Prints string
ostream & operator<<(ostream & os, const MyString & myStr)
{
	os << "This string is: "<< myStr.c_str();
	return os;
}
//returns objects' string 
char & MyString::operator[] (size_t index)
{
	return m_buffer[index];
}
//returns constant object string
const char & MyString::operator[] (size_t index) const
{
	return m_buffer[index];
}
//strlen
size_t MyString::length() const
{
	return strlen(m_buffer);
}
//size of allocation
size_t MyString::size() const
{
	return m_size;
}
//returns string
const char * MyString::c_str() const
{
	return m_buffer;
}
//allocates based on passed by size_t value, add one for null char
void MyString::buffer_allocate(size_t size)
{
		m_size = size + 1;
		try
		{
			m_buffer = new char[m_size];
			
		}
		catch(const bad_alloc &e)
		{
			cout << "MEMORY ALLOCATION UNSUCCESFUL" << endl;
		}
}
//delete memory, assign to NULL
void MyString::buffer_deallocate()
{
	delete [] m_buffer;
	m_size = 0;
	m_buffer = NULL;
}
