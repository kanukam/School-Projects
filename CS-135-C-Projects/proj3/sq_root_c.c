// Name:sq_root.c.c
// Author: Kennedy Anukam
// Created: 9/23/2018
// Purpose: Estimate Square Roots, challenge version
#include <math.h>
#include <stdio.h>

int main()
{
	// variables
	float old_guess=1;
	float new_guess;
	float initial=1;
	float user_value;
	int loopcount=1;
	

	//acquire users value
	printf("Enter a number: ");
	scanf("%f",&user_value);
	
	//print initial value of 1
	if(user_value != initial)
	{
	printf("0\t%10.5f\n",initial);
	}
	else if(user_value == initial)
	{
	printf("Estimated square root of %.5f: %.5f\n",user_value,initial);
	}


	//loop and formula
	while(fabs(old_guess * old_guess - user_value) > 1e-5)
	{
		new_guess = (old_guess + (user_value / old_guess))/(2);
		if(new_guess * new_guess -(2e-4) <= user_value)
		{
			printf("Estimated square root of %.5f: %.5f\n",user_value,new_guess);
			break;
		}
		if(new_guess == old_guess)
		{
			printf("Estimated square root of %.5f: %.5f\n",user_value,new_guess);
			break;
		}
		printf("%d\t%10.5f\n",loopcount,new_guess);
		old_guess = new_guess;
		loopcount++;
	}
	
	
	
return 0;
}




