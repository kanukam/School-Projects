//Name:complex_calculator_c.c
//Author:Kennedy Anukam
//Created:11/2/2018
//Purpose:Complex Number Arithmetic
#include<stdio.h>
void add(float real_part_1, float imaginary_part_1, float real_part_2,float imaginary_part_2, float *real_result, float *imaginary_result);
void subtract(float real_part_1, float imaginary_part_1, float real_part_2,float imaginary_part_2, float *real_result, float *imaginary_result);
void multiply(float real_part_1, float imaginary_part_1, float real_part_2,float imaginary_part_2, float *real_result, float *imaginary_result);
void divide(float real_part_1, float imaginary_part_1, float real_part_2,float imaginary_part_2, float *real_result, float *imaginary_result);
void read_num(float *real_part, float *imaginary_part);
void read_nums(float *real_part_1,float *imaginary_part_1,float *real_part_2,float *imaginary_part_2);
void print_complex(float real_part, float imaginary_part);
int main()
{
	int cmd;
	float real_1;
	float imaginary_1;
	float real_2;
	float imaginary_2;
	float real_result;
	float imaginary_result;
	printf("Complex Number Arithmetic Program:\n");
	printf("1) Add two complex numbers\n");
	printf("2) Subtract two complex numbers\n");
	printf("3) Multiply two complex numbers\n");
	printf("4) Divide two complex numbers\n");
	printf("5) Quit\n");
	printf("Choose an option (1 - 5): ");
	scanf("%d",&cmd);
	//if bad number entered
	while(cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4)
	{
		printf("Please input a valid menu opition\n");
		printf("1) Add two complex numbers\n");
		printf("2) Subtract two complex numbers\n");
		printf("3) Multiply two complex numbers\n");
		printf("4) Divide two complex numbers\n");
		printf("5) Quit\n");
		printf("Choose an option (1 - 5): ");
		scanf("%d",&cmd);
	}
	//loop with arithmetic
	while(cmd != 5)
	{
		switch(cmd)
		{
		case 1:
				read_nums(&real_1,&imaginary_1,&real_2,&imaginary_2);
				add(real_1,imaginary_1,real_2,imaginary_2,&real_result,&imaginary_result);
				print_complex(real_result,imaginary_result);
		break;
		case 2:
				read_nums(&real_1,&imaginary_1,&real_2,&imaginary_2);
				subtract(real_1,imaginary_1,real_2,imaginary_2,&real_result,&imaginary_result);
				print_complex(real_result,imaginary_result);
		break;
		case 3:
				read_nums(&real_1,&imaginary_1,&real_2,&imaginary_2);
				multiply(real_1,imaginary_1,real_2,imaginary_2,&real_result,&imaginary_result);
				print_complex(real_result,imaginary_result);
		break;
		case 4:
				read_nums(&real_1,&imaginary_1,&real_2,&imaginary_2);
				divide(real_1,imaginary_1,real_2,imaginary_2,&real_result,&imaginary_result);
				print_complex(real_result,imaginary_result);
		break;
		}
		printf("1) Add two complex numbers\n");
		printf("2) Subtract two complex numbers\n");
		printf("3) Multiply two complex numbers\n");
		printf("4) Divide two complex numbers\n");
		printf("5) Quit\n");
		printf("Choose an option (1 - 5): ");
		scanf("%d",&cmd);
		while(cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4 && cmd != 5)
		{
			printf("Please input a valid menu opition\n");
			printf("1) Add two complex numbers\n");
			printf("2) Subtract two complex numbers\n");
			printf("3) Multiply two complex numbers\n");
			printf("4) Divide two complex numbers\n");
			printf("5) Quit\n");
			printf("Choose an option (1 - 5): ");
			scanf("%d",&cmd);
		}
	}
	printf("Bye!\n");
	return 0;
}
void add(float real_part_1, float imaginary_part_1, float real_part_2,float imaginary_part_2, float *real_result, float *imaginary_result)
{
	*real_result = real_part_1 + real_part_2;
	*imaginary_result = imaginary_part_1 + imaginary_part_2;
}
void subtract(float real_part_1, float imaginary_part_1, float real_part_2,float imaginary_part_2, float *real_result, float *imaginary_result)
{
	*real_result = real_part_1 - real_part_2;
	*imaginary_result = imaginary_part_1 - imaginary_part_2;
}
void multiply(float real_part_1, float imaginary_part_1, float real_part_2,float imaginary_part_2, float *real_result, float *imaginary_result)
{
	*real_result = (real_part_1 * real_part_2)-(imaginary_part_1 * imaginary_part_2);
	*imaginary_result = (real_part_1 * imaginary_part_2) + (imaginary_part_1 * real_part_2);
}
void divide(float real_part_1, float imaginary_part_1, float real_part_2,float imaginary_part_2, float *real_result, float *imaginary_result)
{
		*real_result = ((real_part_1 * real_part_2) + (imaginary_part_1 * imaginary_part_2))/((real_part_2 * real_part_2) + (imaginary_part_2 * imaginary_part_2));
		*imaginary_result = ((real_part_1 * -imaginary_part_2)+(imaginary_part_1 * real_part_2)) /((real_part_2 * real_part_2) + (imaginary_part_2 * imaginary_part_2));
}
void read_num(float *real_part, float *imaginary_part)
{
	printf("Please type in the real component: ");
	scanf("%f",real_part);
	printf("Please type in the imaginary component: ");
	scanf("%f",imaginary_part);
}
void read_nums(float *real_part_1,float *imaginary_part_1,float *real_part_2,float *imaginary_part_2)
{
	printf("Reading the first imaginary number...\n");
	read_num(real_part_1,imaginary_part_1);
	printf("Reading the second imaginary number...\n");
	read_num(real_part_2,imaginary_part_2);
}
void print_complex(float real_part, float imaginary_part)
{
	printf("The operation yields %6.3f + %6.3fi\n",real_part,imaginary_part);
}






