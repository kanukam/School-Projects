//Creator: Kennedy Anukam
//Date: 11/18/19
//Purpose:Implement Red Black Tree
//Project 5 (CS 302)
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include "RedBlackTree.h"
#define MAX 500
#define MIN 1
int GenerateRandom();
int main()
{
	srand(time(NULL));
	RedBlackTree<int> test;
	int random = 0;
	int temp = 0;
	for(int i = 0; i < 10;i++)
	{
		random = GenerateRandom();
		test.insert(random);
		std::cout << random << " was inserted to the red black tree" << std::endl;
		if(i == 0)
		{
			std::cout << "The color is black" << std::endl;
		}
		if(i == 3)
		{
			temp = random;
		}
		if(i > 0)
		{
			test.getColor(random); 
		}
		if(i > 0)
		{
			test.isParent(random); 
		}
		std::cout << "________________________________________________" << std::endl;
	}
		std::cout << "Inorder Traversal before 4th element deletion" << std::endl;
		test.inorder();
		std::cout << std::endl;
		std::cout << "Inorder Traversal after 4th element deletion" << std::endl;
		test.deleteNode(temp);
		test.inorder();
		return 0;
}
//function to generate a specified amount of random numbers, takes in amount
int GenerateRandom()
{
	std::ofstream num_file;
	num_file.open("Random.txt");
	int num_random = rand() % (MAX - MIN) + MIN;
	num_file << num_random << std::endl;
	num_file.close();
	return num_random;
}
