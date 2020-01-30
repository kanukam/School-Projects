//Name: Kennedy Anukam
//Class: CS 302
//Project: Project 5
//Purpose: Familarize myself with stl heap
//Date: 11/3/19
#define MAX 1000
#define MIN 0
#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
void GenerateRandom(std::vector<int> & heapVector);
void PrintVector(std::vector<int> & heapVector, int n);
int MeanVector(std::vector<int> & heapVector, int n);
int main()
{
	std::vector<int> heapVector;
	//pushing 100 random values onto vector
	GenerateRandom(heapVector);
	//turning vector into a heap
	make_heap(heapVector.begin(),heapVector.end());
	std::cout << "The maximuum element of the heap is " << heapVector.front() << std::endl;
	PrintVector(heapVector,100);
	//Inserting mean into the heap
	std::cout << "Inserting the mean of the vector into the heap" << std::endl;
	int mean = MeanVector(heapVector,100);
	heapVector.push_back(mean);
	push_heap(heapVector.begin(), heapVector.end());
	PrintVector(heapVector,101);
	//deleting max element
	std::cout << "Deleting the max element in the heap" << std::endl;
	pop_heap(heapVector.begin(), heapVector.end());
	heapVector.pop_back();
	PrintVector(heapVector,100);
	//Soring the heap
	std::cout << "Sorting the heap" << std::endl;
	std::sort_heap(heapVector.begin(), heapVector.end());
	PrintVector(heapVector,100);
}
//function to generate random numbers into 
void GenerateRandom(std::vector<int> & heapVector)
{
	srand(time(NULL));
	std::ofstream num_file;
	num_file.open("Random.txt");
	int num_random;
	for(int i = 0; i < 100; i++)
	{
		num_random = rand() % (MAX - MIN) + MIN;
		heapVector.push_back(num_random);
		num_file << num_random << std::endl;
	}
	num_file.close();
}
void PrintVector(std::vector<int> & heapVector, int n)
{
	std::cout << "Printing Vector" << std::endl;
	for(int i = 0; i < n; i++)
	{
		std::cout << heapVector.at(i) << ' ';
	}
	std::cout << std::endl;
}
int MeanVector(std::vector<int> & heapVector, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += heapVector[i];
	}
	return sum / n;
}
