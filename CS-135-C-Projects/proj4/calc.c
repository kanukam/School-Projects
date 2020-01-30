f//Name:Kennedy Anukam
//Program:calc.c
//Created:10/06/2018
//Purpose:Calculator

#include<stdio.h>
#include<stdbool.h>
int main()
{
	double a;
	double b;
	int cmd =0;
	bool is_int = false; //false = double, true=int
	
	

	printf("This program implements a calculator.\n");

	//user options
	printf("Options:\n1 - addition\n2 - subtraction\n3 - multiplication\n");
	printf("4 - division\n5 - toggle calculator type\n6 - exit program\n");

	//Initial User Input
	
	printf("Please enter your option: ");
	scanf("%d",&cmd);

	//While loop and Switch
	while(cmd != 6)
	{
		if(cmd == 1 || cmd == 2 || cmd == 3 || cmd ==4)
		{
			printf("Enter first term: ");
			scanf("%lf",&a);
			printf("Enter second term: ");
			scanf("%lf",&b);
		}
					//addition
			switch(cmd)
			{
					case 1:
							if(is_int == false)
							{
								printf("The sum is: %.15lf\n",a+b);
							}
							else
							{
								printf("The sum is: %d\n",(int)a+(int)b);
							}
							//user enter values again	
					break;
							
					//subtraction
					case 2:
							if(is_int == false)
							{
								printf("The difference is: %.15lf\n",a-b);
							}
							else
							{
								printf("The difference is: %d\n",(int)a-(int)b);
							}
					break;
					//product
					case 3:
							if(is_int == false)
							{
								printf("The product is: %.15lf\n",a*b);
							}
							else
							{
								printf("The product is: %d\n",(int)a*(int)b);
							}
					break;
					//division
					case 4:
							if(is_int == false)
							{
								if(b>0)
								{
									printf("The quotient is: %.15lf\n",a/b);
								}
								else
								{
									printf("Cannot divide by zero!\n");
								}
							}
							else
							{
								if(b>0)
								{
									printf("The quotient is: %d\n",(int)a/(int)b);
								}
								else
								{
									printf("Cannot divide by zero!\n");
								}
							}			
					break;		
					case 5:
							if(is_int == false)
							{
								is_int=true;
								printf("Calculator now works with integers.\n");
							}
							else
							{
								is_int = false;
								printf("Calculator now works with doubles.\n");
							}
					break;		
					default:
							printf("Invalid Option.\n");
					break;			
				}
					printf("Options:\n1 - addition\n2 - subtraction\n3 - multiplication\n");
					printf("4 - division\n5 - toggle calculator type\n6 - exit program\n");
					//scan for values
					printf("Please enter your option: ");
					scanf("%d",&cmd);
		}

	return 0;

}