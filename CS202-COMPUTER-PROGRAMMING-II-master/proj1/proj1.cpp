//Author:Kennedy Anukam
//Purpose:To sort an input file and export to output files
//Course:CS 202
//Date:1/26/2018
#include<iostream>
#include<fstream>
#define ROW 10
#define COLUMN 9
using namespace std;
void buildarray(int arr[],int n);
void print_boundaries();
void myStringCopy(char destination[], const char source []);
int myStringLength(const char str[]);
void bubble_sort(char str1[ROW][COLUMN],int pos[]);
void bubble_sort2(char str1[ROW][COLUMN],int pos[]);
void swap(int arr[],int pos1, int pos2);
int myStringCompare(const char str1[], const char str2[]);
int main()
{
	//keep track of names from input file and the position of number
	char names_from_input[ROW][COLUMN];
	int pos[10];
	buildarray(pos,10);
	//files for input and output files to be entered by user
	char input_file[50];
	char length_file[50];
	char alphabet_file[50];
	//Getting user input
	cout << "Please enter the input file: ";
	cin >> input_file;
	cout << "Please enter the output file to sort by length: ";
	cin >> length_file;
	cout << "Please enter the output file to sort alphabetically: ";
	cin >> alphabet_file;
	//file handling
	ifstream input_stream;
	ofstream length_stream;
	ofstream alpha_stream;
	input_stream.open(input_file);
	length_stream.open(length_file);
	alpha_stream.open(alphabet_file);
	//print to screen
	cout << "Unsorted Data (Original Input Order and Name)" << endl;
	print_boundaries();
	//loop to print out names and order
	for(int i=0;i<10;i++)
	{
		input_stream >> names_from_input[i];
		cout << pos[i] << " " << names_from_input[i] << endl;
	}
	//closing input file
	input_stream.close();
	cout << endl;
	//Sorted by length print out
	cout << "Sorted-by-Length Data (Original Input Order and Name)" << endl;
	print_boundaries();
	bubble_sort(names_from_input,pos);
	//print to console and output file
	for(int i=0;i<10;i++)
	{
		cout << pos[i] << " " << names_from_input[i] << endl;
		length_stream << pos[i] << " " << names_from_input[i] << endl;
	}
	// closing length file
	cout << endl;
	length_stream.close();
	//Sort Alphabetically
	bubble_sort2(names_from_input,pos);
	cout << "Alphabetcally Sorted Data (Original Input Order and Name)" << endl;
	print_boundaries();
	for(int i=0;i<10;i++)
	{
		cout << pos[i] << " " << names_from_input[i] << endl;
		alpha_stream << pos[i] << " " << names_from_input[i] << endl;
	}
	// closing alpha file
	cout << endl;
	alpha_stream.close();
	return 0;
}
//initializes the position number to initial array element
void buildarray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		arr[i] = i;
	}
}
//increments the string until it reaches a null symbol then exits
int myStringLength(const char str[])
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return i;
}
//quicker formatting
void print_boundaries()
{
	cout << "=============================" << endl;
}
//copies a string to another by copying every element until the source reaches a null
void myStringCopy(char destination[], const char source [])
{
	int i = 0;
	while(source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}
//Sorts the two d array by comparing the element and element after, keeps going until
//no more sorts can be made
void bubble_sort(char str1[ROW][COLUMN],int pos[])
{
	int i;
	int temp;
	int k=0;
	char temparr[10];
	bool in_order = false;
	while(in_order == false)
	{
		for(i = 0;i < ROW - 1;i++)
		{
			if(myStringLength(str1[i]) > myStringLength(str1[i + 1]))
			{
				myStringCopy(temparr,str1[i]);
				myStringCopy(str1[i],str1[i + 1]);
				myStringCopy(str1[i+1],temparr);
				swap(pos,i, i+1);
				k++;
			}
		}
		if(k == 0)
		{
			in_order = true;
		}
		else
		{
			k = 0;
		}
	}

}
//Checks to see if the strings are in order
int myStringCompare(const char str1[], const char str2[])
{
	int i = 0;
	int j = 0;
	while(str1[i] != '\0' || str2[j] != '\0')
	{
		if(str1[i] < str2[j])
		{
			return -1;
		}
		if(str1[i] > str2[j])
		{
			return 1;
		}
		if(str1[i] != '\0')
		{
			i++;
		}
		if(str2[j] != '\0')
		{
			j++;
		}
	}	
	return 0;
}
//Sorts the two d array by comparing the element and element after, keeps going until
//no more sorts can be made
void bubble_sort2(char str1[ROW][COLUMN],int pos[])
{
	int i;
	int temp;
	int k=0;
	char temparr[10];
	bool in_order = false;
	while(in_order == false)
	{
		for(i = 0;i < ROW - 1;i++)
		{
			if(myStringCompare(str1[i],str1[i+1]) >= 1)
			{
				myStringCopy(temparr,str1[i]);
				myStringCopy(str1[i],str1[i + 1]);
				myStringCopy(str1[i+1],temparr);
				swap(pos,i, i+1);
				k++;
			}
		}
		if(k == 0)
		{
			in_order = true;
		}
		else
		{
			k = 0;
		}
	}

}
void swap(int arr[],int pos1, int pos2)
{
		int temp = arr[pos1];
		arr[pos1] = arr[pos2];
		arr[pos2] = temp;
}
