//Authour:Kennedy Anukam
//Purpose:Strings
//date:11/23/2018
#include<stdio.h>
#include<ctype.h>
#define LEN 20
#define LENTWO 40
int strlength(char *p);
int strcomp(char *p1, char *p2);
char *strconcat(char *source, char *destination);
char *strcopy(char *source, char *destination);
int main()
{
	char str1[LEN + 1];
	char str2[LENTWO + 1];
	printf("Please enter the first string: ");
	scanf("%20s",str1);
	printf("Please enter the second string: ");
	scanf("%20s",str2);
	//Length
	printf("The length of string 1 is: %d\n",strlength(str1));
	printf("The length of string 2 is: %d\n",strlength(str2));
	//Alphabetic function
	if(strcomp(str1, str2) == 1)
	{
		printf("String 1 comes before string 2 alphabetically.\n");
	}
	else if(strcomp(str1, str2) == -1)
	{
		printf("String 2 comes before string 1 alphabetically.\n");
	}
	else if(strcomp(str1, str2) == 0)
	{
		printf("The two strings are the same.\n");
	}
	//adds one to two
	strconcat(str1,str2);
	printf("String 1 after concatenation: %s\n",str1);
	printf("String 2 after concatenation: %s\n",str2);
	//copy 1 into 2
	strcopy(str1,str2);
	printf("String 1 after copying: %s\n",str1);
	printf("String 2 after copying: %s\n",str2);
	return 0;
}
//points to address of str1 and str2
int strlength(char *p)
{
	int len;
	len = 0;
	while(*p != '\0')
	{
		len++;
		p++;
	}
	return len;
}
//points to str1 and str2 and compares which one comes first
int strcomp(char *p1, char *p2)
{
	for(;*p1 != '\0';p1++)
	{
		if(tolower(*p1) < tolower(*p2))
		{
			return 1;
		}
		if(tolower(*p2) < tolower(*p1))
		{
			return -1;
		}
		if(*p2 != '\0')
		{
		p2++;
		}
	}

	return 0;
}
//adds source 
char *strconcat(char *source, char *destination)
{

	while(*destination != '\0')
	{
		destination++;
	}
	
	while(*source != '\0')
	{
		*destination=*source;
		source++;
		destination++;
	}
		*destination= '\0';
		return destination;
}
char *strcopy(char *source, char *destination)
{
	while(*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}