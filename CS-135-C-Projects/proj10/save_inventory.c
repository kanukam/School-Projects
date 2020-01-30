//Name:Kennedy Anukam
//Project 10
//Created:12/9/2018
//CS 135
#include<stdio.h>
int main()
{
	FILE *ptr = fopen("inventory.txt","wb");
	int part_num;
	int quantity;
	float price;
	printf("This program stores a business inventory.\n");
	printf("Please enter item data (part number, quantity, price): ");
	scanf("%d, %d, %f",&part_num,&quantity,&price);
	while(part_num != 0)
	{
		fwrite(&part_num, sizeof(int), 1, ptr);
		fwrite(&quantity, sizeof(int), 1, ptr);
		fwrite(&price, sizeof(float), 1, ptr);
		printf("Please enter item data (part number, quantity, price): ");
		scanf("%d, %d, %f",&part_num,&quantity,&price);
	}
	printf("Thank you. Inventory stored in file inventory.txt.\n");
	fclose(ptr);
	return 0;
}