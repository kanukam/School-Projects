#include "Sorting.h"
MergeClass::MergeClass():
m_swaps(0),
m_comparisons(0)
{
}
void MergeClass::merge(int theArray[], int first, int mid, int last)
{
	int tempArray[MAX_SIZE]; // Temporary array
	// Initialize the local indices to indicate the subarrays
	int first1 = first; // Beginning of first subarray
	int last1 = mid; // End of first subarray
	int first2 = mid+1; // Beginning of second subarray
	int last2 = last; // End of second subarray
	// While both subarrays are not empty, copy the smaller item into the
	// temporary array
	int index = first1; // next available location in tempArray
	while ((first1<=last1) && (first2 <=last2))
	{	
		m_comparisons++;
		// At this point, tempArray[first..index-1] is in order
		if (theArray[first1] <= theArray[first2])
		{
			tempArray[index] = theArray[first1];
			first1++;
		}
		else
		{
			tempArray[index] = theArray[first2];
			first2++;
			m_swaps++;
		} // end if
		index++;
	} // end while
	while (first1<=last1)
	{
		// at this point, tempArray[first..index-1] is in order
		tempArray[index] = theArray[first1];
		first1++;
		index++;
	} // end while
	// Finish off the second subarray, if necessary
	while (first2<=last2)
	{
		// at this point, tempArray[first..index-1] is in order
		tempArray[index] = theArray[first2];
		first2++;
		index++;
	} // end for
	// Copy the result back into the original array
	for (index=first; index<=last; index++)
	theArray[index] = tempArray[index];
} // end merge

void MergeClass::mergeSort(int theArray[], int first, int last)
{
	if (first < last)
	{
		int mid = first + (last-first)/2;
		mergeSort(theArray,first,mid);
		mergeSort(theArray,mid+1,last);
		merge(theArray, first, mid, last);
	} // end if
}
int MergeClass::swaps() const
{ 
	return m_swaps;
}
int MergeClass::comparisons() const
{
	return m_comparisons;
}
// Sorts the items in an array into ascending order
void bubbleSort(int theArray[], int n)
{
	bool sorted = false; // False when swaps occur
	int pass = 1;
	int swaps = 0;
	int comparison = 0;
	while (!sorted && (pass < n))
	{
		// At this point, theArray[n+1-pass..n-1] is sorted
		// and all of its entries are > the entries in
		// theArray[0..n-pass]
		sorted = true; // Assume sorted
		for (int index = 0; index < n-pass; index++)
		{
			// At this point, all entries in theArray[0..index-1]
			// are <= theArray[index]
			int nextIndex = index + 1;
			if (theArray[index] > theArray[nextIndex])
			{
				// Exchange entries
				std::swap(theArray[index], theArray[nextIndex]);
				sorted = false; // Signal exchange
				swaps++;
			} // end if
			comparison++;
		} // end for
		// Assertion: theArray[0..n-pass-1] < theArray[n-pass]
		pass++;
	} // end while
	std::cout << "Number of swaps: " << swaps << " " <<"Number of comparisons: " << comparison << std::endl;
} // end bubbleSort
