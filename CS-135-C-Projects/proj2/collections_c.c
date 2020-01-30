// Name:collections_c.c
// Author: Kennedy Anukam
// Purpose: Evaluate logic
// Created: September 14,2018


#include<stdio.h>

int main()
{

	//Variables
	int cv1;
	int cp1;
	int total_1;
	int cv2;
	int cp2;
	int total_2;
	int cv3;
	int cp3;
	int total_3;
	int budget;

	// User Enter
	printf("Enter volumes and price per volume for collection 1: ");
	scanf("%d%d",&cv1,&cp1);
	total_1= (cv1 * cp1);

	printf("Enter volumes and price per volume for collection 2: ");
	scanf("%d%d",&cv2,&cp2);
	total_2= (cv2 * cp2);

	printf("Enter volumes and price per volume for collection 3: ");
	scanf("%d%d",&cv3,&cp3);
	total_3= (cv3 * cp3);

	printf("Enter Bob's budget: ");
	scanf("%d", &budget);

	//(logic 1) Can Bob buy anything

	
	if(budget>0)
	{
		printf("(1) Bob has some money to buy collections.\n");
	}
	
	else 
	{
		printf("(1) Bob does not have money to buy anything.\n");
	}
	
	

	//(logic 2) two collections bigger than budget, or two cheaper or =

	
	if((budget < total_1) && (budget < total_2))
	{
		printf("(2) At least two collections are more expenisve than Bob's budget.\n");
	}
	else if ((budget < total_1) && (budget < total_3))
	{
		printf("(2) At least two collections are more expenisve than Bob's budget.\n");
	}
	else if ((budget < total_2) && (budget < total_3))
	{
		printf("(2) At least two collections are more expenisve than Bob's budget.\n");
	}
	else
	{
		printf("(2) At least two collections are cheaper than or equal to Bob's budget.\n");
	}	
	

	//(logic 3) collections cost the same, two are = , or none are =

	
	if((total_1 == total_2) && (total_1 == total_3))
	{
		printf("(3) All the collections cost the same.\n");
	}
	else if((total_1 == total_2) && (total_3 != total_1))
	{
		printf("(3) Only two collections cost the same amount of money.\n");
	}
	else if((total_2 == total_3) && (total_1 != total_2))
	{
		printf("(3) Only two collections cost the same amount of money.\n");
	}
	else if((total_3 == total_1) && (total_2 != total_3))
	{
		printf("(3) Only two collections cost the same amount of money.\n");
	}
	else
	{
		printf("(3) No collections have the same price.\n");
	}
	

	//logic 4
	
	
	if((budget >= total_1) && (budget < total_2) && (budget < total_3))
	{
		printf("(4) Only one collection is cheaper than or equal to Bob's budget.\n");
	}
	else if((budget >= total_2) && (budget < total_1) && (budget < total_3))
	{
		printf("(4) Only one collection is cheaper than or equal to Bob's budget.\n");
	}
	else if((budget >= total_3) && (budget < total_2) && (budget < total_1))
	{
		printf("(4) Only one collection is cheaper than or equal to Bob's budget.\n");
	}
	else
	{
		printf("(4) More than one collection is cheaper than or equal to Bob's budget or they are all more expensive.\n");
	}
	

	//logic 5
	
	if((total_1 + total_2 + total_3) <= (budget))
	{
		printf("(5) Bob can buy all three collections.\n");
	}
	else if((total_1 + total_2 <= budget) && (total_1 + total_2 + total_3 >= budget))
	{
		printf("(5) Bob can only buy two of the collections.\n");
	}
	else if((total_1 + total_3 <= budget) && (total_1 + total_2 + total_3 >= budget))
	{
		printf("(5) Bob can only buy two of the collections.\n");
	}
	else if((total_2 + total_3 <= budget) && (total_1 + total_2 + total_3 >= budget))
	{
		printf("(5) Bob can only buy two of the collections.\n");
	}
	else if((total_1 <= budget) && (total_1 + total_2 > budget) && (total_1 + total_3 > budget))
	{
		printf("(5) Bob can only buy one collection.\n");
	}
	else if((total_2 <= budget) && (total_1 + total_2 > budget) && (total_2 + total_3 > budget))
	{
		printf("(5) Bob can only buy one collection.\n");
	}
	else if((total_3 <= budget) && (total_3 + total_2 > budget) && (total_3 + total_1 > budget))
	{
		printf("(5) Bob can only buy one collection.\n");
	}
	else
	{
		printf("(5) Bob cannot buy any collection.\n");
	}
	

	// logic 6
	
	if((budget >= total_1) && (budget >= total_2) && (budget >= total_3))
	{
		printf("(6) Bob has enough money to buy any one of the three collections.\n");
	}
	else
	{
		printf("(6) Bob does not have enough money to buy any one of the three collections.\n");
	}
	

	// logic 7
	
	if((budget < total_1) && (budget < total_2) && (budget < total_3))
	{
		printf("(7) Bob does not have enough money to buy any collection.\n");
	}
	else
	{
		printf("(7) Bob can buy at least one collection.\n");
	}
	

return 0;
}