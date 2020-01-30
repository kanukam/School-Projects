//Name:Kennedy Anukam
//Purpose:String Functions
//Date:12/1/18
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int strlength(char *p);
int strcomp(char *p1, char *p2);
char *strcopy(char *source, char *destination);
char *strconcat(char *source, char *destination);
int main(int argc,char *argv[])
{
	int len = atoi(argv[1]);
	char *str[len];
	int i = 0;
	int size;
	for(i=0;i<len;i++)
	{
		printf("Enter the length of string %d: ",i+1);
		scanf("%d",&size);
		str[i] = (char *)malloc(size + 1);
		printf("Please enter string %d: ",i+1);
		scanf("%s",str[i]);
	}
	printf("Your strings are:\n");
	for(i=0;i<len;i++)
	{
		printf("String number %d - \"%s\"\n",i+1,str[i]);
	}
	int cmd;
	printf("Options:\n1 - Find string length\n2 - Compare strings\n3 - Copy strings\n");
	printf("4 - Concatenate strings\n5 - Quit\n");
	printf("Please enter your option: ");
	scanf("%d",&cmd);
	while(cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4 && cmd !=5)
	{
		printf("Invalid Option.\n");
		printf("Your strings are:\n");
		for(i=0;i<len;i++)
		{
			printf("String number %d - \"%s\"\n",i+1,str[i]);
		}
		printf("Options:\n1 - Find string length\n2 - Compare strings\n3 - Copy strings\n");
		printf("4 - Concatenate strings\n5 - Quit\n");
		printf("Please enter your option: ");
		scanf("%d",&cmd);
	}
	int temp;
	int temp2;
	while(cmd != 5)
	{
		switch(cmd)
		{
			case 1:
					printf("Enter a string number: ");
					scanf("%d",&temp);
					printf("The length of string %d is: %d\n",temp,strlength(str[temp -1]));
					break;
			case 2:
					printf("Enter the number of the first string: ");
					scanf("%d",&temp);
					printf("Enter the number of the second string: ");
					scanf("%d",&temp2);
					if(strcomp(str[temp-1],str[temp2-1]) == 1)
					{
						printf("String %d comes before string %d alphabetically.\n",temp,temp2);
					}
					if(strcomp(str[temp-1],str[temp2-1]) == -1)
					{
						printf("String %d comes before string %d alphabetically.\n",temp2,temp);
					}
					if(strcomp(str[temp-1],str[temp2-1]) == 0)
					{
						printf("The two strings are the same.\n");
					}
					break;
			case 3:
					printf("Enter the number of the source string: ");
					scanf("%d",&temp);
					printf("Enter the number of the destination string: ");
					scanf("%d",&temp2);
					strcopy(str[temp-1],str[temp2-1]);
					break;
			case 4:
					printf("Enter the number of the source string: ");
					scanf("%d",&temp);
					printf("Enter the number of the destination string: ");
					scanf("%d",&temp2);
					strconcat(str[temp-1],str[temp2-1]);
					break;
		}
		for(i=0;i<len;i++)
		{
			printf("String number %d - \"%s\"\n",i+1,str[i]);
		}
		printf("Options:\n1 - Find string length\n2 - Compare strings\n3 - Copy strings\n");
		printf("4 - Concatenate strings\n5 - Quit\n");
		printf("Please enter your option: ");
		scanf("%d",&cmd);
	while(cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4 && cmd !=5)
	{
		printf("Invalid Option.\n");
		printf("Your strings are:\n");
		for(i=0;i<len;i++)
		{
			printf("String number %d - \"%s\"\n",i+1,str[i]);
		}
		printf("Options:\n1 - Find string length\n2 - Compare strings\n3 - Copy strings\n");
		printf("4 - Concatenate strings\n5 - Quit\n");
		printf("Please enter your option: ");
		scanf("%d",&cmd);
	}
	}
	for(i=0;i<len;i++)
	{
		free(str[i]);
	}
	return 0;
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
	while(*p1 != '\0' || *p2 != '\0')
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
		if(*p1 != '\0')
		{
			p1++;
		}
	}
	return 0;
}
char *strcopy(char *source, char *destination)
{
	free(destination);
	int len=strlength(source);
	destination = (char *)realloc(destination,(len +1) * sizeof(char));
	char *z=destination;
	while(*source != '\0')
	{
		*z = *source;
		z++;
		source++;
	}
	*z = '\0';
	return destination;
}
char *strconcat(char *source, char *destination)
{
	destination =(char *)realloc(destination,(strlength(source)+strlength(destination))+1);
	char *p=destination;
	while(*p!= '\0')
	{
		p++;
	}
	
	while(*source != '\0')
	{
		*p=*source;
		source++;
		p++;
	}
		*p= '\0';
		return destination;
}