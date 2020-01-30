#include "ArrayQueue.h"
using namespace std;

//default ctor, front and back values set to random number of 9999
ArrayQueue::ArrayQueue()
{
	m_front = 9999;
	m_back = 9999;
	m_size = 0;
	cout << "Array queue default ctor" << endl;
}
//parameterized ctor, set front and back to 9999, pushes data into queue
ArrayQueue::ArrayQueue(size_t count, const DataType & value):
m_front(9999),
m_back(9999)
{
	for(size_t i = 0;i < count;i++)
	{
		push(value);
	}
	m_size = m_back - m_front;
	cout << "Array queue parameterized ctor" << endl;
}
//dtor, no dynamic data to destroy
ArrayQueue::~ArrayQueue()
{
	cout <<"Array Queue Destructor, no dynamic memorey deleted" << endl;
}
//three cses, if both 9999, empty queue, if size 1000, queue is full, or add in data and increment m_back
void ArrayQueue::push(const DataType & value)
{
	if(m_front == 9999 && m_back == 9999)
	{
		m_front = 0;
		m_back  = 0;
		m_array[m_back] = value;
		m_back++;
		m_size = m_back - m_front;
	}
	else if(m_size == 1000)
	{
		cout << "The queue is full" << endl;
	}
	else
	{
		m_array[m_back] = value;
		m_back++;
		m_size = m_back - m_front;
	}
}
//checks if empty
bool ArrayQueue::empty() const
{
	if(m_size == 0)
	{
		cout << "The queue is empty" << endl;
		return true;
	}
	cout << "The queue is not empty" << endl;
	return false;
}
//if full every array member full and equals ARRAY_MAX
bool ArrayQueue::full() const
{
	if(m_size == ARRAY_MAX)
	{
		cout << "The queue is full" << endl;
		return true;
	}
	cout << "The queue is not full" << endl;
	return false;
}
//clears by setting to a default constant
void ArrayQueue::clear()
{
	m_front = 9999;
	m_back = 9999;
}
//pop only if an element to pop
void ArrayQueue::pop()
{
	if(m_front == 9999)
	{
		cout << "Cannot pop, the list is empty" << endl;
	}
	else if(m_front == m_back)
	{
		cout << "Popped the last queue member" << endl;
		m_front = 9999;
		m_back = 9999;
	}
	else
	{
		m_front++;
		m_size = m_back - m_front;
	}
}
//returns front queue member
DataType & ArrayQueue::front()	
{
	return m_array[m_front];
}			
const DataType & ArrayQueue::front() const	
{
	return m_array[m_front];
}		
//returns back queue members	
DataType & ArrayQueue::back()
{
	return m_array[m_back-1];		
}	
const DataType & ArrayQueue::back() const	
{
	return m_array[m_back-1];
}
//returns the size of the queue
size_t ArrayQueue::size() const
{
	size_t size = m_back - m_front;
	cout << "The queue has " << size << " members" << endl;
	return size;
}
//helper function for << overload
void ArrayQueue::serialize(ostream & os)const
{
	for(size_t i = m_front;i < m_back;i++)
	{
		os << m_array[i];
	}
}
ostream & operator<<(ostream & os,const ArrayQueue & arrayQueue)
{
	arrayQueue.serialize(os);
	return os;
}
