//--------------------------------------------------------------------
//
//  StackArray.h
// 
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H
#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <class DataType>
class StackLinked : public Stack<DataType> {

  public:
    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackLinked(const StackLinked& other);
    StackLinked& operator=(const StackLinked& other);
    ~StackLinked();
    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);
    void clear();
    bool isEmpty() const;
    bool isFull() const;
    void showStructure() const;

  private:
	class StackNode 
	{
      		public:
			StackNode(const DataType& nodeData, StackNode* nextPtr);
			DataType m_dataItem;
			StackNode* m_next;
    	};
	StackNode* m_top;
};

template <class DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType & nodeData, StackNode *nextptr):
	m_dataItem(nodeData),
	m_next(nextptr)
{
}
template <class DataType>
StackLinked<DataType>::StackLinked(int maxNumber):
	m_top(NULL)
{
}
template <class DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
	StackNode *origPtr = other.m_top;
	if(origPtr == NULL)
	{
		m_top = NULL;
	}
	else
	{
		m_top = new StackNode;
		m_top->m_dataItem = origPtr->m_dataItem;
		StackNode *newChain = m_top;
		origPtr = origPtr->m_next;
		while(origPtr != NULL)
		{
			DataType nextItem = origPtr->m_dataItem;
			StackNode * newNodePtr = new StackNode(nextItem,NULL);
			newChain->m_next = newNodePtr;
			newChain = newChain->m_next;
			origPtr = origPtr->m_next;
		}
	}
}
template <class DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
	if(this == &other)
	{
		return *this;
	}
	else
	{
		clear();
		StackNode *origPtr = other.m_top;
		if(origPtr == NULL)
		{
			m_top = NULL;
		}
		else
		{
			m_top = new StackNode;
			m_top->m_dataItem = origPtr->m_dataItem;
			StackNode *newChain = m_top;
			origPtr = origPtr->m_next;
			while(origPtr != NULL)
			{
				DataType nextItem = origPtr->m_dataItem;
				StackNode * newNodePtr = new StackNode(nextItem,NULL);
				newChain->m_next = newNodePtr;
				newChain = newChain->m_next;
				origPtr = origPtr->m_next;
			}
		}
	}
		return *this;
}  
template <class DataType>
StackLinked<DataType>::~StackLinked()
{
	clear();
}
template <class DataType>
bool StackLinked<DataType>::isEmpty() const
{
	return m_top == NULL;
}
template <class DataType>
bool StackLinked<DataType>::isFull() const
{
	return false;
}
template <class DataType>
void StackLinked<DataType>::showStructure() const
{
	if(m_top == NULL)
	{
		std::cout << "Empty Stack\n";
	}
	else
	{
		StackNode *current = m_top;
		while(current != NULL)
		{
			std::cout << current->m_dataItem << " ";
			current = current -> m_next;
		}
		std::cout << endl;
	}
}
template <class DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	StackNode *newPtr = new StackNode(newDataItem,m_top);
	m_top = newPtr;
}
template <class DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
	DataType temp;
	if(isEmpty())
	{
		throw logic_error("The Stack is Empty!");
	}
	else
	{
		temp = m_top->m_dataItem;
		StackNode *delPtr = m_top;
		m_top = m_top->m_next;
		delete delPtr;
		return temp;
	}
	return temp;
}
template <class DataType>
void StackLinked<DataType>::clear()
{
	StackNode *current = m_top;
	StackNode *delPtr = current;
	while(current != NULL)
	{
		current = current->m_next;
		delete delPtr;
		delPtr = current;
	}
	m_top = NULL;
}

#endif		

