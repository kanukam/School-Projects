/** Link-based implementation of the ADT binary search tree.
@file BinarySearchTree.h */
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_
#include "binary_node.h"
#include <memory>
#include <algorithm>
template<class ItemType>
class BinarySearchTree
{
private:
	std::shared_ptr<BinaryNode<ItemType>> m_rootPtr;
protected:
	//------------------------------------------------------------
	//Protected Utility Methods Section:
	//Recursive helper methods for the public methods.
	//------------------------------------------------------------
	// Places a given new node at its proper position in this binary// search tree.

	std::shared_ptr<BinaryNode<ItemType>> placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,std::shared_ptr<BinaryNode<ItemType>> newNode);

	//Helper methods
	void preOrder(std::shared_ptr<BinaryNode<ItemType>>) const;
	void inOrder(std::shared_ptr<BinaryNode<ItemType>>) const;
	void postOrder(std::shared_ptr<BinaryNode<ItemType>>) const;
	std::shared_ptr<BinaryNode<ItemType>> copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;
	void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
	int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
public:
	//------------------------------------------------------------
	// Constructor and Destructor Section.
	//------------------------------------------------------------
	BinarySearchTree();
	BinarySearchTree(const ItemType& rootItem);
	BinarySearchTree(const BinarySearchTree<ItemType>& tree);
	~BinarySearchTree();
	//------------------------------------------------------------
	// Public Methods Section.
	//------------------------------------------------------------
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
	ItemType getRootData() const;
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newEntry);
	void clear();
	//------------------------------------------------------------
	// Public Traversals Section.
	//------------------------------------------------------------
	void preorderTraverse() const; 
	void inorderTraverse() const;
	void postorderTraverse() const; 
	//------------------------------------------------------------
	// Overloaded Operator Section.
	//------------------------------------------------------------
	BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide);
}; // end BinarySearchTree

//Setting root pointer to NULL
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree():
m_rootPtr(NULL)
{
}
template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	clear();
}
//using helper copy method for efficiency
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
	m_rootPtr = copyTree(tree.m_rootPtr);
}
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{
	std::shared_ptr<BinaryNode<ItemType>> newNode = new std::shared_ptr<BinaryNode<ItemType>>;
	newNode->setItem(rootItem);
	m_rootPtr = newNode;
}
template <class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
	if(this != &rightHandSide)
	{
		clear();
		m_rootPtr = copyTree(rightHandSide.m_rootPtr);
	}
	return *this;
}
//add node to tree efficiently with recursion, pass in head of tree, returns head. Allocated memory will need to be passed in
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> 	subTreePtr,std::shared_ptr<BinaryNode<ItemType>> newNode)
{
	std::shared_ptr<BinaryNode<ItemType>> tempPtr;
	//Base Case, can break the recursion flow
	if(subTreePtr == NULL)
	{
		return newNode;
	}
	else if(subTreePtr->getItem() > newNode->getItem())
	{
		tempPtr = placeNode(subTreePtr->getLeftChildPtr(),newNode);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else
	{
		tempPtr = placeNode(subTreePtr->getRightChildPtr(),newNode);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return subTreePtr;
}
//Allocates memory for a new node and adds it to the tree
template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)	
{
	std::shared_ptr<BinaryNode<ItemType>> tempNode(new BinaryNode<ItemType>(newEntry));
	tempNode->setItem(newEntry);
	placeNode(m_rootPtr,tempNode);	
	return true;
}	
//returns data of root nod
template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const
{
	return m_rootPtr->getItem();
}
//creates first node and acquires data, pass in data as parameter
template <class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{
	//create root node, left and right ptrs set to NULL due to default ctor
	std::shared_ptr<BinaryNode<ItemType>> temp(new BinaryNode<ItemType>(newData));
	temp->setItem(newData);
	m_rootPtr = temp;
}
//empty if rootPtr is NULL
template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	return m_rootPtr == NULL;
}
//traversal recursion helper methods
template <class ItemType>
void BinarySearchTree<ItemType>::preOrder(std::shared_ptr<BinaryNode<ItemType>> root) const
{
	if(root == NULL)
	{
		return;
	}
	std::cout << root->getItem() << " ";
	preOrder(root->getLeftChildPtr());
	preOrder(root->getRightChildPtr());
}
template<class ItemType>
void BinarySearchTree<ItemType>::inOrder(std::shared_ptr<BinaryNode<ItemType>> root) const
{
	if(root == NULL)
	{
		return;
	}
	inOrder(root->getLeftChildPtr());
	std::cout << root->getItem() << " ";
	inOrder(root->getRightChildPtr());
}	
template<class ItemType>
void BinarySearchTree<ItemType>::postOrder(std::shared_ptr<BinaryNode<ItemType>>root) const
{
	if(root == NULL)
	{
		return;
	}
	postOrder(root->getLeftChildPtr());
	postOrder(root->getRightChildPtr());
	std::cout << root->getItem() << " ";
}
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const
{
	std::cout << "Preorder Traversal Of Binary Search tree" <<std::endl;
	preOrder(m_rootPtr);
	std::cout << std::endl;
}
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const
{
	std::cout << "Inorder Traversal Of Binary Search tree" <<std::endl;
	inOrder(m_rootPtr);
	std::cout << std::endl;
}	
template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const
{
	std::cout << "Postorder Traversal Of Binary Search tree" <<std::endl;
	postOrder(m_rootPtr);
	std::cout << std::endl;
}	
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{ 
	std::shared_ptr<BinaryNode<ItemType>> newTreePtr;
	// Copy tree nodes during a preorder traversal
	if (oldTreeRootPtr != NULL)
	{
		// Copy node
		newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(), nullptr, nullptr); 
		newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr())); 
		newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
	} // end if
	// Else tree is empty (newTreePtr is nullptr) 
	return newTreePtr;
} // end copyTree
template<class ItemType> 
void BinarySearchTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{ 
	if (subTreePtr != NULL)
	{ 
		destroyTree(subTreePtr->getLeftChildPtr()); 
		destroyTree(subTreePtr->getRightChildPtr());
		subTreePtr.reset(); // Decrement reference count to node 
	} // end if
} // end destroyTree
template <class ItemType>
void BinarySearchTree<ItemType>::clear()
{
	destroyTree(m_rootPtr);
}
template<class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
	if (subTreePtr == NULL)
		return 0;
	else
		return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),getHeightHelper(subTreePtr->getRightChildPtr()));
} // end getHeightHelper
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
	return getHeightHelper(m_rootPtr);
}
template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
	if(subTreePtr == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + getNumberOfNodes(subTreePtr->getLeftChildPtr()) + getNumberOfNodes(subTreePtr->getRightChildPtr());
	}
}
#endif
