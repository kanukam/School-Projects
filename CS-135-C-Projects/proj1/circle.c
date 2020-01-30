/* Name: circle.c */
/* Purpose: Program to familiarize with scanf and print f */
/* Authour: Kennedy Anukam */
/* Written: September 6,2018 */

#include<stdio.h>
#define PI_CONSTANT 3.14f

int main(void)
{
	
	/*Variables*/
	int radius,diameter,perimeter,area_of_square;         
	float area_of_circle,circumference,diff_area;
	
	printf("This program computes values related to an inscribed circle.\n");

	/*User Command radius*/
	printf("Enter the value of the radius: ");            
	scanf("%d", &radius);
	
	/*Diameter*/
	diameter= radius * 2;
	printf("The diameter of the circle is: %d\n",diameter);    

	/*Circumference*/
	circumference= (2 * PI_CONSTANT) * radius;
	printf("The circumference of the circle is: %1.3f\n",circumference);  

	/*Area Of Circle*/
	area_of_circle= PI_CONSTANT * (radius*radius);
	printf("The area of the circle is: %1.3f\n",area_of_circle);        

	/*Perimeter*/
	perimeter= 4 * diameter;
	printf("The perimeter of the square is: %d\n",perimeter);         
	
	 /*Area Of Square*/
	area_of_square= diameter * diameter;
	printf("The area of the square is: %d\n",area_of_square);         

	/*Difference In Area*/
	diff_area = (area_of_square)-(area_of_circle);
	printf("The difference between the area of the square and the circle is: %1.3f\n",diff_area);

	return 0;
}
