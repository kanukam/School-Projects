//Authour;Kennedy Ankam
//Strings Assignment
//Created 12/1/2018
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 30
char *interspere(char str1[],char str2[]);
char *widen_stars(char str1[],char str2[]);
int strlength(char *p);
int strcomp(char *p1, char *p2);
int main(int argc,char *argv[])
{
	char str1[SIZE + 1];
	char str2[SIZE + 1];

	printf("Please enter a string of maximum 30 characters: ");
	scanf("%s",str1);
	printf("Please enter a string of maximum 30 characters: ");
	scanf("%s",str2);
	if(strcomp(argv[1],"-i") == 0)
	{
	char *p = interspere(str1,str2);
	printf("The combined string is: ");
	puts(p);
	free(p);
	}
	if(strcomp(argv[1],"-w") == 0)
	{
	char *q = widen_stars(str1,str2);
	printf("The combined string is: ");
	puts(q);
	free(q);
	}
	return 0;
}
char *interspere(char str1[],char str2[])
{
	int len;
	len = strlength(str1) + strlength(str2) + 1;
	char *result = (char *) malloc(len * sizeof(char));
	char *p = str1;
	char *j = str2;
	char *q=result;
	while(*p != '\0' || *j != '\0')
	{
		if(*p != '\0')
		{
			*q = *p;
			q++;
			p++;
		}
		if(*j != '\0')
		{
			*q = *j;
			q++;
			j++;
		}
	}
	*q='\0';
	return result;	
}
char *widen_stars(char str1[],char str2[])
{
	int len;
	len = strlength(str1) + strlength(str2) + 1;
	char *result = (char *) malloc((2*len) * sizeof(char));
	char *p = str1;
	char *j = str2;
	char *q=result;
	while(*p != '\0')
	{
		*q = *p;
		q++;
		p++;
		*q='*';
		q++;
	}
	while(*j != '\0')
	{
		*q = *j;
		q++;
		j++;
		*q='*';
		q++;
	}
	q--;
	*q = '\0';
	return result;	
}
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