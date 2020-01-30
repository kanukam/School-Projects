#include "NodeList.h"
#include<iostream>
using namespace std;
NodeList::NodeList():
	m_head(NULL)
{
	cout << "Node List default ctor" << endl;
}
NodeList::NodeList(size_t count, const DataType& value):
	m_head(NULL)
{
	for(size_t i = 0;i< count;i++)
	{
		try
		{
			Node *temp = new Node(value,NULL);
			temp->m_next = m_head;
			m_head = temp;
		}
		catch(const bad_alloc &e)
		{
			cout << "There was an error during allocation!" << endl;
		}
	}
	cout << "Node List Parametized ctor" << endl;
}
NodeList::NodeList(const NodeList & other):
	m_head(NULL)
{
	int count = 0;
	for(Node *curr = other.m_head;curr != NULL;curr = curr->m_next)
	{
		Node * temp = new Node(other[count],NULL);
		temp->m_next = m_head;
		m_head = temp;
		count++;
	}
	cout << "Node List Copy ctor" << endl;
}
NodeList & NodeList::operator= (const NodeList & rhs)
{
	if(this != &rhs)
	{
		//clearing list
		for(Node *curr = m_head;curr != NULL;)
		{
			Node *next = curr->m_next;
			delete curr;
			curr = next;
		}
		m_head = NULL;
		int count = 0;
		for(Node *curr = rhs.m_head;curr != NULL;curr = curr->m_next)
		{
			Node * temp = new Node(rhs[count],NULL);
			temp->m_next = m_head;
			m_head = temp;
			count ++;
		}
	}
	
	return *this;
}
NodeList::~NodeList()
{
	cout << "Node List Destructor" << endl;
	int count = 0;
	for(Node *curr = m_head;curr != NULL;)
	{
		Node *next = curr->m_next;
		delete curr;
		curr = next;
		count++;
	}
	cout << count << " objects were destroyed from the Node list " << endl;
	m_head = NULL;
}	
size_t NodeList::size() const
{
	size_t count = 0;
	for(Node *curr = m_head;curr != NULL;curr = curr->m_next)
	{
		count++;
	}
	return count;
}
bool NodeList::empty() const
{
	size_t count = 0;
	for(Node *curr = m_head;curr != NULL;curr = curr->m_next)
	{
		count++;
	}
	if(count > 0)
	{
		cout << "The list is not empty" << endl;
		return false;
	}
	else
	{
		cout << "The list is empty" << endl;
		return true;
	}
}
void NodeList::clear()
{
	while(m_head != NULL)
	{
		Node * next = m_head->m_next;
		delete m_head;
		m_head = next;
	}
	m_head = NULL;
	cout << "The Node Linked List has successfully been deleted." << endl;
}
DataType & NodeList::operator[](size_t position)
{
	size_t placement = 0;
	for(Node *curr = m_head;curr != NULL; curr = curr->m_next)
	{
		if(placement == position)
		{
			return curr->data();
		}
		placement++;
	}
}	
const DataType& NodeList::operator[](size_t position) const
{
	size_t placement = 0;
	for(Node *curr = m_head;curr != NULL; curr = curr->m_next)
	{
		if(placement == position)
		{
			return curr->data();
		}
		placement++;
	}
}
ostream & operator<<(ostream & os, const NodeList & nodeList)
{
	size_t count = nodeList.size();
	os << "Printing List:" << endl;
	for(size_t i = 0;i < count; i++)
	{
		DataType obj = nodeList[i];
		os << obj << endl;
		
	}
	return os;
}
Node * NodeList::insertBefore(const DataType & target,const DataType & value)
{
	if(m_head->data() == target)
	{
		try
		{
			Node *temp = new Node(value,NULL);
			temp->m_next = m_head;
			m_head = temp;
			return temp;
		}
		catch(const bad_alloc &e)
		{
			cout << "There was an error during allocation!" << endl;
		}
	}
	for(Node *curr = m_head;curr != NULL;curr = curr->m_next)
	{
		if(curr->m_next->data() == target)
		{
			try
			{
				Node *next = curr->m_next;
				Node *temp2 = new Node(value,NULL);
				temp2->m_next = next;
				curr->m_next = temp2;
				return temp2;
			}
			catch(const bad_alloc &e)
			{
				cout << "There was an error during allocation!" << endl;
			}
		}
	}
	return NULL;			
}			
Node * NodeList::insertAfter(const DataType & target,const DataType & value)
{
	for(Node *curr = m_head;curr != NULL;curr = curr->m_next)
	{
		if(curr->data() == target)
		{
			try
			{
				Node *next = curr->m_next;
				Node *temp2 = new Node(value,NULL);
				temp2->m_next = next;
				curr->m_next = temp2;
				return temp2;
			}
			catch(const bad_alloc &e)
			{
				cout << "There was an error during allocation!" << endl;
			}
		}
	}
	return NULL;		
}			
Node * NodeList::erase(const DataType & target)
{
	if(m_head->data() == target)
	{
		Node *next = m_head->m_next;
		delete m_head;
		m_head = next;
		return m_head;
	}
	for(Node *curr = m_head;curr != NULL;curr = curr->m_next)
	{
		if(curr->m_next->data() == target)
		{
			Node *deletePtr = curr->m_next;
			Node *next = deletePtr->m_next;
			curr->m_next = next;
			delete deletePtr;
			return next;
		}
	}
	return NULL;
}
Node *NodeList::front()
{
	return m_head;
}
Node *NodeList::back()
{
	for(Node *curr = m_head;curr!=NULL;curr = curr-> m_next)
	{
		if(!curr->m_next)
		{
			return curr;
		}
	}
	return NULL;
}
Node * NodeList::find(const DataType & target,Node * & previous)
{
	for(previous = m_head;previous != NULL;previous = previous->m_next)
	{
		if(previous->data() == target)
		{
			return previous;
		}
	}
	return NULL;
}




