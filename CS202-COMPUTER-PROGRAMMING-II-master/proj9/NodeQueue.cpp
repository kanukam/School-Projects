#include "NodeQueue.h"
using namespace std;
//default ctor, front back to NULL 
NodeQueue::NodeQueue():
m_front(NULL),
m_back(NULL)
{
	cout << "Queue default constructor" << endl;
}
//parameterized ctor, front back to NULL, push amount of data
NodeQueue::NodeQueue(size_t size, const DataType& value):
m_front(NULL),
m_back(NULL)
{
	for(size_t i = 0;i < size;i++)
	{
		push(value);
	}
	cout << "Queue Paramaterized constructor" << endl;
}
//copy ctor
NodeQueue::NodeQueue(const NodeQueue & other):
m_front(NULL),
m_back(NULL)
{
	for(Node *curr = other.m_front;curr != NULL;curr = curr->m_next)
	{
		Node *temp = new(nothrow) Node(other.m_front->m_data,NULL);
		push(temp->m_data);
	}
	cout << "Copy ctor" << endl;
}
//push onto queue, two cases, if empty and if not
void NodeQueue::push(const DataType & value)
{
	Node *newNode = new(nothrow) Node(value,NULL);
	if(!newNode)
	{
		cout << "Allocation Error" <<endl;
	}
	if(m_front == NULL && m_back == NULL)
	{
		cout << "Pushing a node onto the queue" << endl;
		newNode->m_next = NULL;
		m_front = newNode;
		m_back = newNode;
	}
	else
	{
		cout << "Pushing a node onto the queue" << endl;
		m_back->m_next = newNode;
		newNode->m_next = NULL;
		m_back = newNode;
	}
}
//print data helper for << operator overload
void NodeQueue::serialize(ostream & os)const
{
	for(Node *curr = m_front;curr != NULL;curr = curr->m_next)
	{
		os << curr->m_data;
	}
}
//print data
ostream & operator <<(ostream& os,NodeQueue& nodeQueue)
{
	nodeQueue.serialize(os);
	return os;
}
//pop from oldest data
void NodeQueue::pop()
{
	if(m_front != NULL)
	{
		Node *del_pt = m_front;
		m_front = m_front->m_next;
		delete del_pt;
		cout << "Popping a node from Queue" << endl;
	}
}
//traverses list, increments size var then returns it
size_t NodeQueue::size() const
{	
	size_t size = 0;
	for(Node *curr = m_front;curr != NULL;curr = curr->m_next)
	{
		size++;
	}
	cout << "The size of the queue is " << size << endl;
	return size;
}
//returns front of queue
DataType & NodeQueue::front()
{
	if(m_front != NULL)
	{
		return m_front->m_data;
	}
}
//returns front of queue
const DataType & NodeQueue::front() const	
{
	if(m_front != NULL)
	{
		return m_front->m_data;
	}
}
//returns back of queue
DataType & NodeQueue::back()
{
	if(m_front != NULL)
	{
		return m_back->m_data;
	}
}
//returns back of queue
const DataType & NodeQueue::back() const	
{
	if(m_front != NULL)
	{
		return m_back->m_data;
	}
}
//checks if queue is empty
bool NodeQueue::empty() const
{
	if(m_front == NULL && m_back == NULL)
	{
		cout << "The queue is empty" << endl;
		return true;
	}
	cout << "The list is not empty" << endl;
	return false;
}
//checks if queue is full
bool NodeQueue::full() const
{
	cout << "The queue is not full" << endl;
	return false;
}
//dtor, deallocates queue
NodeQueue::~NodeQueue()
{
	for(Node *curr = m_front;curr != NULL;)
	{
		Node *next = curr->m_next;
		delete curr;
		curr = next;
	}
	m_front = NULL;
	m_back = NULL;
	cout << "Node Queue destructor" << endl;
}
//cleears queue
void NodeQueue::clear()
{
	for(Node *curr = m_front;curr != NULL;)
	{
		Node *next = curr->m_next;
		delete curr;
		curr = next;
	}
	m_front = NULL;
	m_back = NULL;
}
//assignment operator
NodeQueue& NodeQueue::operator= (const NodeQueue & rhs)
{
	if(this != &rhs)
	{
		this->clear();
		for(Node *curr = rhs.m_front;curr != NULL;curr = curr->m_next)
		{
			Node *temp = new(nothrow) Node(rhs.m_front->m_data,NULL);
			push(temp->m_data);
		}
	}
	return *this;
}
