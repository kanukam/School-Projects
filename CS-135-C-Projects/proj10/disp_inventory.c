//Name:Kennedy Anukam
//Project 10
//Created:12/9/2018
//CS 135
#include<stdio.h>
int main()
{
	FILE *ptr = fopen("inventory.txt","rb");
	int part_num;
	int quantity;
	float price;
	printf("Below are the items in your inventory.\n");
	printf("Part#\tQuantity\tItem Price\n");
	while(fread(&part_num, sizeof(int), 1, ptr) > 0)
	{
		fread(&quantity, sizeof(int), 1, ptr);
		fread(&price, sizeof(float), 1, ptr);
		printf("%5d\t%8d\t$%9.2f\t\n",part_num,quantity,price);
	}
	fclose(ptr);
	return 0;
}
