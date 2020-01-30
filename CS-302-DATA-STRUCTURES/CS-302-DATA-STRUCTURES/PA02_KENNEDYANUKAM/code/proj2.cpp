#include<iostream>
#include<fstream>
#include "Sorting.h"
#include<cstdlib>
#include<chrono>
#define MAXNUM 1000000
using namespace std;
using namespace std::chrono;
void GenerateRandom(int amount);
void timeSort();
int main()
{
	//reading from output file into array
	int amount = 1000;
	int bubble_values[amount];
	int merge_values[amount];
	MergeClass merge_obj;
	GenerateRandom(amount);
	std::ifstream num_file;
	num_file.open("random.txt");
	int current = 0;
	int index = 0;
	while(num_file >> current)
	{
		bubble_values[index] = current;
		merge_values[index] = current;
		index++;
	}
	//unsorted bubble sort
	std::cout << std::endl << "Testing Bubble Sort (" << amount <<" values)" << std::endl;
	auto start = high_resolution_clock::now();
	bubbleSort(bubble_values,amount);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	std::cout << "Time of Bubble Sort: " << duration.count() << " seconds" << std::endl << std::endl;
	//sorted implementation
	std::cout << std::endl << "Testing Bubble Sort (" << amount <<" values)" << " When Sorted" <<std::endl;
	start = high_resolution_clock::now();
	bubbleSort(bubble_values,amount);
	stop = high_resolution_clock::now();
	duration = duration_cast<seconds>(stop - start);
	std::cout << "Time of Bubble Sort: " << duration.count() << " seconds" << std::endl << std::endl;
	//unsorted merge
	std::cout << std::endl << "Testing Merge Sort (" << amount <<" values)" << std::endl;
	start = high_resolution_clock::now();
	merge_obj.mergeSort(merge_values,0,amount - 1);
	std::cout << "Swaps: " << merge_obj.swaps() << " Comparisons: " << merge_obj.comparisons() << std::endl;
	stop = high_resolution_clock::now();
	duration = duration_cast<seconds>(stop - start);
	std::cout << "Time of Merge Sort: " << duration.count() << " seconds" << std::endl << std::endl;
	//sorted
	std::cout << std::endl << "Testing Merge Sort (" << amount <<" values)" << " When Sorted" <<std::endl;
	start = high_resolution_clock::now();
	merge_obj.mergeSort(merge_values,0,amount -1);
	std::cout << "Swaps: " << merge_obj.swaps() << " Comparisons: " << merge_obj.comparisons() << std::endl;
	stop = high_resolution_clock::now();
	duration = duration_cast<seconds>(stop - start);
	std::cout << "Time of Merge Sort: " << duration.count() << " seconds" << std::endl << std::endl;
	
	return 0;
}

//function to generate a specified amount of random numbers, takes in amount
void GenerateRandom(int amount)
{
	srand(time(NULL));
	std::ofstream num_file;
	num_file.open("random.txt");
	for(int i = 0; i < amount; i++)
	{
		num_file << rand() % MAXNUM << std::endl;
	}
	num_file.close();
}
