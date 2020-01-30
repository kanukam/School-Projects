#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H
#include<iostream>
#include<cstdlib>
#include <memory>
//Helper Node Class
template <class ItemType>
class Node
{
	public:
			Node<ItemType> *m_left, *m_right;
			Node(ItemType data);
			ItemType m_data;
			//represent red/black
			bool m_color;
};
//Red Black Tree Class
template <class ItemType>
class RedBlackTree
{
	public:
			RedBlackTree();
			void insert(const ItemType &data);
			void inorder();
			void isParent(ItemType value);
			void getColor(ItemType value); 
			void deleteNode(const ItemType &data);
	protected:
			//helper methods
			bool isRed(Node<ItemType> *myNode);
			void inorderHelper(Node<ItemType> *myNode);
			Node<ItemType>* DeleteRec(Node<ItemType> *myNode, ItemType data);
			Node<ItemType>* DeleteMin(Node<ItemType> *myNode);
			Node<ItemType>* FixUp(Node<ItemType> *myNode);
			Node<ItemType>* MoveRedRight(Node<ItemType> *myNode);
			Node<ItemType>* MoveRedLeft(Node<ItemType> *myNode);
			void ColorFlip(Node<ItemType> *myNode);
			Node<ItemType>* FindMin(Node<ItemType> *myNode);
			Node<ItemType>* insertHelper(Node<ItemType> *myNode, Node<ItemType> *node);
			Node<ItemType>* rotateLeft(Node<ItemType> *myNode);
			Node<ItemType>* rotateRight(Node<ItemType> *myNode);
			Node<ItemType> *searchParent(Node<ItemType>* root, ItemType target);
	private:
			Node<ItemType> *m_root;
};
template <class ItemType>
Node<ItemType>::Node(ItemType data):
m_left(NULL),
m_right(NULL),
m_data(data)
{
	m_color = true;
}
template <class ItemType>
RedBlackTree<ItemType>::RedBlackTree():
m_root(NULL)
{
}
//Check if node is red
template <class ItemType>
bool RedBlackTree<ItemType>::isRed(Node<ItemType> *myNode)
{
	if(myNode == NULL)
	{
		return false;
	}
	return myNode->m_color == true;
}
template<class ItemType>
void RedBlackTree<ItemType>::inorderHelper(Node<ItemType> *myNode)
{
	if(myNode)
	{
		inorderHelper(myNode->m_left);
		std::cout << myNode->m_data << " ";
		inorderHelper(myNode->m_right);
	}
}
template<class ItemType>
void RedBlackTree<ItemType>::inorder()
{
	inorderHelper(m_root);
}
template<class ItemType>
Node<ItemType>* RedBlackTree<ItemType>::searchParent(Node<ItemType>* root, ItemType target)
{
    if(root == NULL)
	{
    	return NULL;
	}
	if((root->m_left != NULL) && (root->m_left->m_data == target))
	{
		return root;
	}
	if((root->m_right != NULL) && (root->m_right->m_data == target))
	{
		return root;
	}
	else if(root->m_data < target)
	{
		Node<ItemType> * tempPtr = searchParent(root->m_right, target);
		return tempPtr;
	}
	else
	{
		Node<ItemType> * tempPtr = searchParent(root->m_left, target);
		return tempPtr;
	}
}
template<class ItemType>
void RedBlackTree<ItemType>::isParent(ItemType value)
{
	Node<ItemType> *temp = searchParent(m_root, value);
	if(temp != NULL)
	{
		std::cout << "The parent of Node " << value << " is " << temp->m_data << std::endl;
		if(temp->m_color == false)
		{
			std::cout << "The parent color is black" << std::endl;
		}
		else
		{
			std::cout << "The parent color is red" << std::endl;
		}	
	}
}

template<class ItemType>
void RedBlackTree<ItemType>::getColor(ItemType value)
{
	Node<ItemType> *temp = searchParent(m_root, value);
	if(temp != NULL)
	{
		Node<ItemType> *left = temp->m_left;
		Node<ItemType> *right = temp->m_right;
		if(right != NULL)
		{
			if(right->m_data == value)
			{
				if(right->m_color == false)
				{
					std::cout << "The color is black" << std::endl;
				}
				else
				{
					std::cout << "The color is red" << std::endl;
				}
			}
		}
		if(left != NULL)
		{
			if(left->m_data == value)
			{
				if(left->m_color == false)
				{
					std::cout << "The color is black" << std::endl;
				}
				else
				{
					std::cout << "The color is red" << std::endl;
				}
			}
		}
	}
}
template<class ItemType>
Node<ItemType>* RedBlackTree<ItemType>::DeleteRec(Node<ItemType> *myNode, ItemType data)
{
	if (data < myNode->m_data) 
	{
		if (NULL != myNode->m_left) 
		{
			if(!isRed(myNode->m_left) && !isRed(myNode->m_left->m_left))
			{
				myNode = MoveRedLeft(myNode);
			}
			myNode->m_left = DeleteRec(myNode->m_left, data);
		}
	}
	else 
	{
		if(isRed(myNode->m_left)) 
		{
			myNode = rotateRight(myNode);
		}
		if ((data == myNode->m_data) &&(NULL == myNode->m_right))
		{
			delete myNode;
			return NULL;
		}
		if (NULL != myNode->m_right)
		{
			if (!isRed(myNode->m_right) && !isRed(myNode->m_right->m_left))
			{
				myNode = MoveRedRight(myNode);
			}
			if (data == myNode->m_data) 
			{
				myNode->m_data = FindMin(myNode->m_right)->m_data;
				myNode->m_right = DeleteMin(myNode->m_right);
			}

			else 
			{
				myNode->m_right = DeleteRec(myNode->m_right, data);
			}
		}
	}
		return FixUp(myNode);
}
template<class ItemType>
Node<ItemType>* RedBlackTree<ItemType>::DeleteMin(Node<ItemType> *myNode)
{
	if(NULL == myNode->m_left) {
		delete myNode;
		return NULL;
	}
	if((false == isRed(myNode->m_left)) &&(false == isRed(myNode->m_left->m_left)))
	{
		myNode = MoveRedLeft(myNode);
	}
	myNode->m_left = DeleteMin(myNode->m_left);
	return FixUp(myNode);
}
template<class ItemType>
Node<ItemType>*RedBlackTree<ItemType>::FixUp(Node<ItemType> *myNode)
{
	if (isRed(myNode->m_right)) {
		myNode = rotateLeft(myNode);
	}
	if (isRed(myNode->m_left) &&isRed(myNode->m_left->m_left))
	{
		myNode = rotateRight(myNode);
	}
	// Split 4-nodes.
	if(isRed(myNode->m_left) && isRed(myNode->m_right))
	{
		ColorFlip(myNode);
	}
	return myNode;
}
template<class ItemType>
Node<ItemType>* RedBlackTree<ItemType>::MoveRedRight(Node<ItemType> *myNode)
{
	ColorFlip(myNode);
	if((NULL != myNode->m_left) && isRed(myNode->m_left->m_left))
	{
		myNode = rotateRight(myNode);
		ColorFlip(myNode);
	}
	return myNode;
}
template<class ItemType>
Node<ItemType>* RedBlackTree<ItemType>::MoveRedLeft(Node<ItemType> *myNode)
{
	ColorFlip(myNode);
	if ((NULL != myNode->m_right) && isRed(myNode->m_right->m_left))
	{
		myNode->m_right = rotateRight(myNode->m_right);
		myNode = rotateLeft(myNode);
		ColorFlip(myNode);
	}
	return myNode;
}
template<class ItemType>
void RedBlackTree<ItemType>::ColorFlip(Node<ItemType> *myNode)
{
	myNode->m_color = !myNode->m_color;

	if(NULL != myNode->m_left) {
		myNode->m_left->m_color  = !myNode->m_left->m_color;
	}

	if(NULL != myNode->m_right) {
		myNode->m_right->m_color = !myNode->m_right->m_color;
	}
}
template<class ItemType>
Node<ItemType>* RedBlackTree<ItemType>::FindMin(Node<ItemType> *myNode)
{
	while (NULL != myNode->m_left) {
		myNode = myNode->m_left;
	}
	return myNode;
}
template<class ItemType>
Node<ItemType>* RedBlackTree<ItemType>::insertHelper(Node<ItemType> *myNode, Node<ItemType> *node)
{
	if (myNode == nullptr) 
	{
		return node;
	}
	if (node->m_data < myNode->m_data) {
		myNode->m_left = insertHelper(myNode->m_left, node);
	} else {
		myNode->m_right =insertHelper(myNode->m_right, node);
	}

	if (isRed(myNode->m_right) && !isRed(myNode->m_left)) 
	{
		myNode = rotateLeft(myNode);
	}
	if (isRed(myNode->m_left) && isRed(myNode->m_left->m_left)) {
		myNode = rotateRight(myNode);
	}

	if (isRed(myNode->m_left) && isRed(myNode->m_right)) {
		ColorFlip(myNode);
	}
	return myNode;
}
template<class ItemType>
void RedBlackTree<ItemType>::insert(const ItemType &data) 
{
	Node<ItemType> *newNode = new Node<ItemType>(data);
	m_root = insertHelper(m_root, newNode);
	m_root->m_color = false;
}
template<class ItemType>
void RedBlackTree<ItemType>::deleteNode(const ItemType &data) {
	m_root = DeleteRec(m_root,data);
}
template<class ItemType>
Node<ItemType>* RedBlackTree<ItemType>::rotateLeft(Node<ItemType> *myNode) {
	Node<ItemType>* temp = myNode->m_right;
	myNode->m_right = temp->m_left;
	temp->m_left = myNode;
	temp->m_color = myNode->m_color;
	myNode->m_color = true;
	return temp;
}
template<class ItemType> Node<ItemType>* RedBlackTree<ItemType>::rotateRight(Node<ItemType> *node) 
{
	Node<ItemType>* temp = node->m_left;
	node->m_left = temp->m_right;
	temp->m_right = node;
	temp->m_color = node->m_color;
	node->m_color = true;
	return temp;
}
#endif
