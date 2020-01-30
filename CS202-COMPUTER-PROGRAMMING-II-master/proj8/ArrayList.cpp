#include "ArrayList.h"
#include <iostream>
using namespace std;
ArrayList::ArrayList():
	m_array(NULL)
{
	m_size = 0;
	m_maxsize = 0;
	cout << "Array List Default Ctor." << endl;
}
ArrayList::ArrayList(size_t count,const DataType & value):
	m_size(count),
	m_maxsize(count)
{
	m_array = new DataType[count];
	for(size_t i = 0;i < count;i++)
	{
		m_array[i] = value;
	}
	cout << "Array List Parametized Ctor." << endl;
}
ArrayList::ArrayList(const ArrayList & other)
{
	m_array = new DataType[other.m_size];
	for(size_t i = 0;i < other.m_size;i++)
	{
		m_array[i] = other.m_array[i];
	}
	cout << "Array List Copy Ctor." << endl;
	m_size = other.m_size;	
	m_maxsize = other.m_maxsize;
}
ArrayList & ArrayList::operator= (const ArrayList & rhs)
{
	if(this != &rhs)
	{
		if(m_maxsize > 0)
		{
			delete []m_array;
		}
		m_array = new DataType[rhs.m_size];
		for(size_t i = 0;i < rhs.m_size;i++)
		{
			m_array[i] = rhs.m_array[i];
		}
		cout << "Array List Copy Ctor." << endl;
		m_size = rhs.m_size;	
		m_maxsize = rhs.m_maxsize;
	}
	cout << "Assignment Operator" << endl;
	return *this;
}
ostream & operator<<(ostream & os,const ArrayList & arrayList)
{
	cout << "Printing Array Based List" << endl;
	for(size_t i=0; i < arrayList.m_size;i++)
	{
		cout << arrayList.m_array[i];
	}
	return os;
}
bool ArrayList::empty() const
{
	if(m_size == 0)
	{
		cout << "The list is empty" << endl;
		return true;
	}
	else
	{
		cout << "The list is not empty" << endl;
		return true;
	}
}
size_t ArrayList::size() const
{
	cout << "The list has "<< m_size << " members" << endl;
	return m_size;
}
ArrayList::~ArrayList()
{
	cout << "Array Based destructor" << endl;
	if(m_maxsize > 0)
	{
		delete [] m_array;
	}
	cout << m_maxsize << " Members of the Array Based list were destroyed" << endl;
}
DataType & ArrayList::operator[] (size_t position)
{
	return m_array[position];
}
void ArrayList::clear()
{
	cout << "clearing the list" << endl;
	m_size = 0;
}
DataType * ArrayList::front()
{
	if(m_size == 0)
	{
		return NULL;
	}
	else
	{
		return &m_array[0];
	}
}
DataType * ArrayList::back()
{
	return &m_array[m_size-1];
}
DataType * ArrayList::find(const DataType & target,DataType * & previous)
{
	for(size_t i = 0;i < m_size;i++)
	{
		previous = &m_array[i];
		if(*previous == target)
		{
			return previous;
		}
	}
	previous = NULL;
	return NULL;
}
DataType * ArrayList::insertAfter(const DataType & target,const DataType & value)
{
	resize(m_size + 1);
	for(size_t i=0;i<m_size;i++)
	{
			if(m_array[i] == target)
			{
				i++;
				size_t temp = i;
				while(i < m_size)
				{
					m_array[i+1] = m_array[i];
					i++;
				}
				m_array[temp] = value;
				return &m_array[temp];
			}
	}
	return NULL;
}
DataType * ArrayList::insertBefore(const DataType & target,const DataType & value)
{
	resize(m_size + 1);
	for(size_t i=0;i<m_size;i++)
	{
			if(m_array[i] == target)
			{
				size_t temp = i;
				while(i < m_size)
				{
					m_array[i+1] = m_array[i];
					i++;
				}
				m_array[temp] = value;
				return &m_array[temp];
			}
	}
	return NULL;
}
void ArrayList::resize(size_t count)
{
	size_t size = m_size;
	if(m_size > 0)
	{
		DataType * temp = new DataType[count];
		for(size_t i = 0;i < size;i++)
		{
			temp[i] = m_array[i];
		}
		delete [] m_array;
		m_array = new DataType[count];
		for(size_t i = 0;i < size;i++)
		{
			m_array[i] = temp[i];
		}
		m_maxsize = count;
		m_size++;
	}
	else
	{
		m_array = new DataType[count];
		m_maxsize = count;
		m_size++;
	}
}
DataType * ArrayList::erase(const DataType & target)
{
	for(size_t i = 0;i < m_size;i++)
	{
		if(m_array[i] == target)
		{
			m_array[i] = m_array[m_size-1];
			m_size--;
			if(i+1 < m_size)
			{
				return &m_array[i+1];
			}
			else
			{
				return NULL;
			}
		}
	}
	return NULL;
}
