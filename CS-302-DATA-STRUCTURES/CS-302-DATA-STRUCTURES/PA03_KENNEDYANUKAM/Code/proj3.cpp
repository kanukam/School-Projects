//Creator: Kennedy Anukam
//Date: 10/23/19
//Purpose:Implement Binary Search Tree
//Project 3 (CS 302)
#include<iostream>
#include<fstream>
#include<cstdlib>
#include "binary_node.h"
#include "binary_search_tree.h"
#define MAX 200
#define MIN 1
void GenerateRandom(BinarySearchTree<int> & tree);
int main()
{
	BinarySearchTree<int> searchTree;
	//Generating 100 integers and adding to tree
	GenerateRandom(searchTree);
	//Traversing Tree
	searchTree.preorderTraverse();
	searchTree.inorderTraverse();
	searchTree.postorderTraverse();
	//Height
	std::cout << "The height of the tree is " << searchTree.getHeight() << std::endl;
	return 0;
}
//function to generate a specified amount of random numbers, takes in amount
void GenerateRandom(BinarySearchTree<int> & tree)
{
	srand(time(NULL));
	std::ofstream num_file;
	num_file.open("Random.txt");
	int num_random = rand() % (MAX - MIN) + MIN;
	num_file << num_random << std::endl;
	tree.setRootData(num_random);
	for(int i = 0; i < 99; i++)
	{
		num_random = rand() % (MAX - MIN) + MIN;
		tree.add(num_random);
		num_file << num_random << std::endl;
	}
	num_file.close();
}
