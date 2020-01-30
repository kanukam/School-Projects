//Name:Kennedy Anukam
//CS 202
//Stacks
#include <iostream>
#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
using namespace std;
const size_t MAX_STACKSIZE= 1000;

template <class T> class ArrayStack;
template <class T> ostream & operator<<(ostream & os,const ArrayStack<T> & arrayStack);

template <class T>
class ArrayStack
{
	friend ostream & operator<< <> (ostream & os,const ArrayStack<T> & arrayStack); //(i)
	public:
		//Copy ctor,dtor and assignment operator do not need to be implemented, no dynamic memory
		ArrayStack();														//(1)
		ArrayStack(size_t count, const T & value);					//(2)
		//ArrayStack(const ArrayStack & other);								//(3)
		//~ArrayStack();														//(4)
		//ArrayStack &operator = (const ArrayStack& rhs);					//(5)
		T & top();															//(6a)
		const T &top() const;												//(6b)
		void push(const T &value);									//(7)
		void pop();                  										//(8)
		size_t size() const;												//(9)
		bool empty() const;													//(10)
		bool full() const;													//(11)
	  	void clear();														//(12)
		void serialize(ostream & os) const;								//(13)
	private:
		T m_container[MAX_STACKSIZE];
		size_t m_top;
};
//top index set to 0
template <class T>
ArrayStack<T>::ArrayStack():
m_top(0)
{
	cout << "Array Stack Default constructor" << endl;
}
//top index set to 0,data pushed onto stack
template <class T>
ArrayStack<T>::ArrayStack(size_t count, const T & value):
m_top(0)
{
	cout << "Array Stack Parameterized constructor" << endl;
	for(size_t i=0;i < count;i++)
	{
		push(value);
	}
}
//print stack
template <class T>
ostream & operator<<(ostream & os,const ArrayStack<T> & arrayStack)
{
	os << "Printing Stack" << endl;
	arrayStack.serialize(os);
	return os;
}
//aid for printing stack
template <class T>
void ArrayStack<T>::serialize(ostream & os) const
{
	for(size_t i = 0;i < m_top;i++)
	{
		os << m_container[i] << endl;
	}
}
//check if full
template <class T>
bool ArrayStack<T>::full() const
{
	if(m_top == MAX_STACKSIZE -1)
	{
		cout << "The stack is full" << endl;
		return true;
	}
	return false;
}
//clear stack by moving index to 0
template <class T>
void ArrayStack<T>::clear()
{
	cout << "Clearing the stack" << endl;
	m_top = 0;
}
//check if empty
template <class T>
bool ArrayStack<T>::empty() const
{
	if(m_top == 0)
	{
		cout << "The stack is empty" << endl;
		return true;
	}
	return false;
}
//push onto stack by incrementing index
template <class T>
void ArrayStack<T>::push(const T &value)	
{
	if(m_top == 0)
	{
		m_container[m_top] = value;
		m_top++;
		cout << "Pushing onto the stack" << endl;
	}
	else
	{
		if(!full())
		{
			cout << "Pushing onto the stack" << endl;
			m_container[m_top] = value;
			m_top++;
		}
	}
}
//return top
template <typename T>
const T & ArrayStack<T>::top() const
{
	return m_container[m_top - 1];
}
template <class T>									
T & ArrayStack<T>::top()
{
	return m_container[m_top - 1];
}
//decrement stack
template <class T>
void ArrayStack<T>::pop()
{      
	if(!empty())
	{
		cout << "Removing from stack" << endl;
		m_top--;
	}
}     
//return index number
template <class T>  									
size_t ArrayStack<T>::size() const
{
	cout << "The size of the stack is: " << m_top << endl;
	return m_top;
}

#endif
