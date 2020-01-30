//Name:Kennedy Anukam
//Course:Cs 202
//Date:4/5/19
//Purpose:Smart Pointers
#include<iostream>
#include "SmartPtr.h"
using namespace std;
//Default ctor, allocates space to refcnt and the ptr, sets count to 1
SmartPtr::SmartPtr()
{
	try
	{
		m_ptr = new DataType;
		m_refcount = new size_t;
	}
	catch(const bad_alloc &e)
	{
		cout << "THE DATA WAS NOT ALLOCATED PROPERLY" << endl;
	}
	*m_refcount = 1;
	cout << "SmartPtr Default Constructor for new allocation, RefCount = <";
	cout << *m_refcount << ">" << endl;
}
//Parametized ctor,assigns data to ptr and count to 1
SmartPtr::SmartPtr(DataType *data)
{
	m_ptr = data;
	if(m_ptr)
	{
		try
		{
			m_refcount = new size_t;
		}
		catch(const bad_alloc &e)
		{
			cout << "THE DATA WAS NOT ALLOCATED PROPERLY" << endl;
		}
		*m_refcount = 1;
	}
	else
	{
		try
		{
			m_refcount = new size_t;
			*m_refcount = 0;
		}
		catch(const bad_alloc &e)
		{
			cout << "THE DATA WAS NOT ALLOCATED PROPERLY" << endl;
		}
	}
	cout << "SmartPtr Parametized Constructor from data pointer RefCount = <";
	cout << *m_refcount << ">" << endl;
}	
//copy ctor,copies ptr and refcount,increments count by 1 since another obj pointing to allocated data
SmartPtr::SmartPtr( const SmartPtr & other )
{
	m_ptr = other.m_ptr;
	m_refcount = other.m_refcount;
	if(m_ptr)
	{
		m_refcount = other.m_refcount;
		*m_refcount = *m_refcount + 1;
	}
	else
	{
		try
		{
			m_refcount = new size_t;
			*m_refcount = 0;
		}
		catch(const bad_alloc &e)
		{
			cout << "THE DATA WAS NOT ALLOCATED PROPERLY" << endl;
		}
			
	}
	cout << "SmartPtr Copy Constructor, RefCount = <";
	cout << *m_refcount << ">" << endl;
}
//asignment operator,decrements calling refcount by 1,if last obj destroy,if not just assign calling obj to rhs
SmartPtr & SmartPtr::operator=(const SmartPtr & rhs)
{
	if(this != &rhs)
	{	
		if(*m_refcount > 0)
		{
			*m_refcount = *m_refcount - 1;
			if(m_refcount == 0)
			{
				delete m_refcount;
				delete m_ptr;
			}
		}
		m_ptr = rhs.m_ptr;
		if(m_ptr)
		{
			m_refcount = rhs.m_refcount;
			*m_refcount = *m_refcount + 1;
		}
		else
		{
			try
			{
				m_refcount = new size_t;
				*m_refcount = 0;
			}
			catch(const bad_alloc &e)
			{
				cout << "THE DATA WAS NOT ALLOCATED PROPERLY" << endl;
			}
		}
	}
	cout << "SmartPtr Copy Assignment, RefCount = <";
	cout << *m_refcount << ">" << endl;
	return *this;
			
}	
//dtor,destroy fecount if calling obj is null, destroy data if obj refcount goes from 1 to 0
SmartPtr::~SmartPtr( )
{
	cout << "SmartPtr Destructor, RefCount = <";
	cout << *m_refcount << ">" << endl;
	if(*m_refcount == 0)
	{
		delete m_refcount;
	}
	if(*m_refcount > 0)
	{
		*m_refcount = *m_refcount -1;
		if(*m_refcount == 0)
		{
			delete m_refcount;
			delete m_ptr;
		}
	}
}
DataType *SmartPtr::operator->( )
{
	return m_ptr;
}
DataType & SmartPtr::operator*( )
{
	return *m_ptr;
}

	
