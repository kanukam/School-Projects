#ifndef BINARY_NODE_H
#define BINARY_NODE_H
#include<iostream>
#include <memory>

template <class ItemType>
class BinaryNode
{
public:
	BinaryNode();
	BinaryNode(const ItemType& data);
	BinaryNode(const ItemType & data,std::shared_ptr<BinaryNode<ItemType>> left, std::shared_ptr<BinaryNode<ItemType>> right);
	BinaryNode(const BinaryNode<ItemType> & node);

	bool isLeaf() const;

	void setItem(const ItemType & data);
	ItemType getItem() const; 

	void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
	std::shared_ptr<BinaryNode<ItemType>> getLeftChildPtr() const;

	void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);
	std::shared_ptr<BinaryNode<ItemType>> getRightChildPtr() const;

private:
	ItemType m_data;
	std::shared_ptr<BinaryNode<ItemType>> m_left;
	std::shared_ptr<BinaryNode<ItemType>> m_right;

};
template<class ItemType>
BinaryNode<ItemType>::BinaryNode():
m_data(ItemType()),
m_left(NULL),
m_right(NULL)
{
}
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType & data):
m_data(data),
m_left(NULL),
m_right(NULL)
{
}
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType & data,std::shared_ptr<BinaryNode<ItemType>> left, std::shared_ptr<BinaryNode<ItemType>> right):
m_data(data),
m_left(left),
m_right(right)
{
}
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const BinaryNode<ItemType> & node)
{
	if(this != &node)
	{
		m_data = node.m_data;
		m_left = new std::shared_ptr<BinaryNode<ItemType>>(node.getLeftChildPtr.getItem());
		m_right = new std::shared_ptr<BinaryNode<ItemType>>(node.getRightChildPtr.getItem());
	}
}
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType & data)
{
	m_data = data;
}
template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
	return m_data;
}
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getLeftChildPtr() const
{
	return m_left;
}
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getRightChildPtr() const
{
	return m_right;
}
template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
	m_right = rightPtr;
}
template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr)
{
	m_left = leftPtr;
}
template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
	return m_right == NULL && m_left == NULL;
}
#endif
