//Name:Kennedy Anukam
//CS 202
//Stacks
#include <iostream>
#ifndef NODE_STACK_H
#define NODE_STACK_H

using namespace std;
template <class T> class NodeStack;
template <class T> ostream & operator <<(ostream &os,const NodeStack<T> & nodeStack);

template <class T>
class Node
{
	friend class NodeStack<T>;
	public:
		Node()
		{
			m_next = NULL;
		}
		Node(const T & data, Node *next = NULL)
		{
			m_next = next;
			m_data = data;
		}	
		T & data()
		{
			return m_data;
		}
		const T & data() const
		{
			return m_data;
		}
	private:
		Node<T> * m_next;
		T m_data;
		
};
template <class T>
class NodeStack
{
	friend ostream & operator<< <>(ostream & os,const NodeStack<T> & nodeStack); 					//(i)
	public:
		NodeStack();																		//(1)
		NodeStack(size_t count, const T & value);									//(2)
		NodeStack(const NodeStack<T> & other);													//(3)
		~NodeStack();																		//(4)
		NodeStack<T> & operator= (const NodeStack<T> & other);      									//(5)
		T & top();																		//(6a)	
		const T &top() const;															//(6b)
		void push(const T & value);														//(7)
		void pop();                  														//(8)
		size_t size() const;																	//(9)
	    	bool empty() const;																	//(10)
		bool full() const;																	//(11)
		void clear();																		//(12)
		void serialize(ostream & os) const;												//(13)
	private:
		Node<T> *m_top;
};
//default constructor top set to NULL
template <class T>
NodeStack<T>::NodeStack()
{
	m_top = NULL;
	cout <<"Node Stack default constructor" << endl;
}
//parametized constructor
template <class T>
NodeStack<T>::NodeStack(size_t count, const T & value)
{
	m_top = NULL;
	cout << "Node Stack Parameterized Constructor" << endl;
	for(size_t i =0;i < count;i++)
	{
		push(value);
	}
}
//copy ctor
template <class T>
NodeStack<T>::NodeStack(const NodeStack<T> & other)
{
	m_top = NULL;
	cout << "Node stack copy constructor" << endl;
	for(Node<T> * curr = other.m_top;curr != NULL;curr = curr = curr->m_next)
	{
		Node<T> *temp = new Node<T>(curr->m_data);
		temp->m_next = m_top;
		m_top = temp;
	}
}	
//assignment operator
template <class T>
NodeStack<T> & NodeStack<T>::operator= (const NodeStack<T> & other)
{
	if(this != &other)
	{
		clear();
		for(Node<T> * curr = other.m_top;curr != NULL;curr = curr = curr->m_next)
		{
			Node<T> *temp = new Node<T>(curr->m_data);
			temp->m_next = m_top;
			m_top = temp;
		}
	}
	return *this;
}
//dtor
template <class T>
NodeStack<T>::~NodeStack()
{
	cout << "Node stack destructor" << endl;
	clear();
}
//aid for << operator overload
template <class T>
void NodeStack<T>::serialize(ostream & os) const
{
	os <<"Printing Node Stack:" << endl;
	for(Node<T> *curr = m_top;curr != NULL;curr = curr->m_next)
	{
		os << curr->m_data << endl;
	}
}
//print stack	
template <class T>
ostream & operator<<(ostream & os,const NodeStack<T> & nodeStack)
{
	nodeStack.serialize(os);
	return os;
}
//pop head from stack
template <class T>
void NodeStack<T>::pop()
{
	if(m_top)
	{
		cout << "Removing top element from node stack" << endl;
		Node<T> *temp = m_top;
		m_top = m_top->m_next;
		delete temp;
	}
}
//return stack size
template<class T>
size_t NodeStack<T>::size() const
{
	size_t size = 0;
	for(Node<T> *curr = m_top;curr != NULL;curr = curr->m_next)
	{
		size++;
	}
	cout << "The Node stack has " << size << " members " << endl;
	return size;
}
//check if empty
template <class T>
bool NodeStack<T>::empty() const
{
	if(m_top)
	{
		return false;
	}
	return true;
}
//never full
template <class T>
bool NodeStack<T>::full() const
{
	return false;
}			
//clear stack		
template <class T>												
void NodeStack<T>::clear()
{
	if(!empty())
	{
		cout << "Clearing Node Stack" << endl;
		while(m_top != NULL)
		{
			Node<T> *del_pt = m_top;
			m_top = m_top->m_next;
			delete del_pt;
		}
	}
	m_top = NULL;
}
//return top pointer
template <class T>
T & NodeStack<T>::top()
{
	return m_top;
}
template <class T>
const T & NodeStack<T>::top() const
{
	return m_top;
}
//add onto stack
template <class T>
void NodeStack<T>::push(const T & value)
{
		Node<T> *temp = new Node<T>(value);
		temp->m_next = m_top;
		m_top = temp;
		cout << "Pushing onto Node Stack" << endl;
}
#endif
