// Name: series.c
// Purpose: Loops
// Created: September 21 2018
// Author: Kennedy Anukam

#include <stdio.h>

int main()
{

int total=0;
int n=0;
int i;


printf("Enter an integer number: ");
scanf("%d",&n);

	for(i=1;i <= n;i++)
	{
		

		if((i % 2) == (0))
		{
			total -= i * i;
		}
		else
		{
			total += i * i;
		}
	}

	printf("The value of the series is: %d\n",total);

	
	
	
	return 0;

}







