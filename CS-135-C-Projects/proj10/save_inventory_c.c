//Name:Kennedy Anukam
//Project 10
//CS 135
//Working with Files
#include<stdio.h>
int repeated(FILE *ptr,int part,int quantity,float price);
int main()
{
	FILE *ptr = fopen("inventory.txt","wb+");
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
		rewind(ptr);
		while(repeated(ptr,part_num,quantity,price)== 1)
		{
			printf("This item has been entered before.\n");
			printf("Please enter item data (part number, quantity, price): ");
			scanf("%d, %d, %f",&part_num,&quantity,&price);
		}
		fseek(ptr, 0,SEEK_END);
	}
	printf("Thank you. Inventory stored in file inventory.txt.\n");
	fclose(ptr);
	return 0;
}
int repeated(FILE *ptr,int part,int quantity,float price)
{
	
	int part1;
	int part2;
	float part3;
	while(fread(&part1, sizeof(int), 1, ptr) > 0)
	{
		fread(&part2, sizeof(int), 1, ptr);
		fread(&part3, sizeof(float), 1, ptr);
		if(part == part1)
		{
			return 1;
		}
	}
	return 0;
}


