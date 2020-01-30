#ifndef SORTING_H_
#define SORTING_H_
#include<iostream>
void bubbleSort(int theArray[], int n);
class MergeClass
{
	public:
		MergeClass();
		void mergeSort(int theArray[], int first, int last);
		void merge(int theArray[], int first, int mid, int last);
		int swaps() const;
		int comparisons() const;
	private:
		unsigned int m_swaps;
		unsigned int m_comparisons;
		static const int MAX_SIZE = 100000; // maximum number of items in array
};
#endif
