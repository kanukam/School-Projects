/*Name: date.c */
/*Purpose: Print Dates */
/*Date: September 6,2018*/
/*Authour: Kennedy Anukam*/

#include<stdio.h>
int main()
{

	int d1, m1, y1;
	int d2, m2, y2;
	int d3, m3, y3;
	int d4, m4, y4;

	/*User Enters Dates*/

	printf("Enter date 1 (dd/mm/yyyy): ");
	scanf("%d/%d/%d",&d1,&m1,&y1);

	printf("Enter date 2 (dd/mm/yyyy): ");
	scanf("%d/%d/%d",&d2,&m2,&y2);

	printf("Enter date 3 (dd/mm/yyyy): ");
	scanf("%d/%d/%d",&d3,&m3,&y3);
	
	printf("Enter date 4 (dd/mm/yyyy): ");
	scanf("%d/%d/%d",&d4,&m4,&y4);
	printf("\n");

	/*Format Of Dates*/

	printf("Year\tMonth\tDay\n");

	printf("%4.4d\t%2.2d\t%-2.2d\n",y1,m1,d1);
	printf("%4.4d\t%2.2d\t%-2.2d\n",y2,m2,d2);
	printf("%4.4d\t%2.2d\t%-2.2d\n",y3,m3,d3);
	printf("%4.4d\t%2.2d\t%-2.2d\n",y4,m4,d4);
	
	return 0;
}
