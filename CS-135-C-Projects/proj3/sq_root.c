// Name:sq_root.c
// Author: Kennedy Anukam
// Created: 9/23/2018
// Purpose: Estimate Square Roots
#include <math.h>
#include <stdio.h>

int main()
{
	// variables
	double old_guess=1;
	double new_guess;
	double initial=1;
	double user_value;
	

	//acquire users value
	printf("Enter a number: ");
	scanf("%lf",&user_value);
	
	//print initial value of 1
	if(user_value != initial)
	{
	printf("%10.5lf\n",initial);
	}
	else if(user_value == initial)
	{
	printf("Estimated square root of %.5lf: %.5lf\n",user_value,initial);
	}

	

	//loop and formula
	while(fabs(old_guess * old_guess - user_value) > 1e-5)
	{
		new_guess = (old_guess + (user_value / old_guess))/(2);
		if(new_guess * new_guess -(2e-4) <= user_value)
		{
			printf("Estimated square root of %.5lf: %.5lf\n",user_value,new_guess);
			break;
		}
		printf("%10.5lf\n",new_guess);
		old_guess = new_guess;
	}
	
	
	
return 0;
}




