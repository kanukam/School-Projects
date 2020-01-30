//Name:Kennedy Anukam
//File: arrays.c
//Created: 10/12/2018
//Pupose:Get familiar with arrays

#include<stdio.h>
int main()
{
	int row;
	int column;
	int temp;
	int r;
	int c;
	int arr2[10]={0};

	printf("This program counts occurences of digits 0 through 9 in an NxM array.\n");

	//User determined row and column size
	printf("Enter the size of the array (Row Column): ");
	scanf("%d %d",&row, &column);

	//User Entered value gets implemeted to determine array length
	int arr[row][column];

	//Array to get users values
	for(r=0;r<row;r++)
	{
		printf("Enter row %d: ",r);
			for(c=0;c<column;c++)
			{
				//temp is for each digit, temp initializes the digits 0-9 and adds 1 to it
				//temp gives a value to an element in 2D array.
				scanf("%d",&temp);
				arr[r][c]=temp;
				arr2[temp]=arr2[temp]+1;
			}
	}

	//Print counts for each digit
	printf("Total counts for each digit: ");
	printf("\n");
	for(int i=0;i<10;i++)
	{
		printf("Digit %d occurs %d times\n",i,arr2[i]);
	}
	
	//Print the Counting Array
	printf("The digit counts directly from the 1D array:");
	printf("\n");
	for(int j=0;j<10;j++)
	{
		printf("%-2d",arr2[j]);
	}
	printf("\n");

	//Prints the users OG values
	printf("The original 2D array entered by the user: \n");
	for(r=0;r<row;r++)
	{
			for(c=0;c<column;c++)
			{
				printf("%-2d",arr[r][c]);
			}
	printf("\n");
	
	}
}