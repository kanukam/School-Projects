//Name: Kennedy Anukam
//Class: CS 202
//Purpose: Structures
//Created: 2/2/2019
#include<iostream>
#include<fstream>
using namespace std;
struct rentalCar
{
	int year;
	char make[11];
	char model[11];
	float price;
	bool available;
};
void print_menu();
void buildArray(int pos[]);
void bubbleSort(rentalCar carArray[],rentalCar tempArray[]);
void inputFile(rentalCar carArray[]);
void outputFile(rentalCar carArray[]);
void printStruct(rentalCar carArray[], int pos[]);
void rentCar(rentalCar carArray[],int pos[]);
size_t myStringLength(const char *str);
int myStringCompare(const char *str1, const char *str2);
char *myStringCopy(char *destination, const char *source);
char *myStringCat(char *destination, const char *source);
void checkAvailable(rentalCar carArray[]);
int main()
{
	int cmd;
	rentalCar carArray[5];
	rentalCar tempArray[1];
	//position and function to fill it with index number
	int pos[5];
	buildArray(pos);
	print_menu();
	cin >> cmd;
	while(cmd != 7)
	{
		switch(cmd)
		{
			case 1:
				inputFile(carArray);
			break;
			case 2:
				printStruct(carArray,pos);
			break;
			case 3:
				outputFile(carArray);
			break;
			case 4:
				bubbleSort(carArray,tempArray);
			break;
			case 5:
				rentCar(carArray,pos);
			break;
			case 6:
				checkAvailable(carArray);
			break;
		}
		print_menu();
		cin >> cmd;
	}
	return 0;
}
//Function that prints the menu options for user
void print_menu()
{
	cout << "1) Enter your input file" << endl;
	cout << "2) Print all car data" << endl;
	cout << "3) Print data to an output file" << endl;
	cout << "4) Sort cars by ascending price" << endl;
	cout << "5) Rental cost for amount of days" << endl;
	cout << "6) Which car would you like to rent?" << endl;
	cout << "7) Exit" << endl;
	cout << "Please enter your option: ";
}
//Function to store input file into structure when called	
void inputFile(rentalCar carArray[])
{
	char inputFile[15];
	cout << "Please enter your input file: ";
	cin >> inputFile;
	ifstream inputStream;
	inputStream.open(inputFile);
	int i=0;
	while(i<5)
	{
		inputStream >> carArray[i].year;
		inputStream >> carArray[i].make;
		inputStream >> carArray[i].model;
		inputStream >> carArray[i].price;
		inputStream >> carArray[i].available;
		i++;
	}
	cout << "Results have been stored from the file" << endl;
	inputStream.close();
	cout << endl;
}
//function to print structure to an output file
void outputFile(rentalCar carArray[])
{
	char outputFile[15];
	cout << "Please enter your output file: ";
	cin >> outputFile;
	ofstream outputStream;
	outputStream.open(outputFile);
	int i=0;
	while(i<5)
	{
		outputStream << carArray[i].year << " ";
		outputStream << carArray[i].make << " ";
		outputStream << carArray[i].model <<  " ";
		outputStream << carArray[i].price << " ";
		outputStream << carArray[i].available << " ";
		i++;
		outputStream << endl;
	}
	cout << "Results have been stored to the file" << endl;
	outputStream.close();
	cout << endl;
}
//function to give position array index number
void buildArray(int pos[])
{
	for(int i = 0; i < 5; i++)
	{
		pos[i] = i;
	}
}
//function to print structure with position numbers
void printStruct(rentalCar carArray[], int pos[])
{
	for(int i = 0; i < 5; i++)
	{
		cout << "[" << pos[i] << "]" << ": "<< carArray[i].year << " " 			<<carArray[i].make << " " << carArray[i].model << ", " << "$" << 			carArray[i].price;
 		cout << " per day, "<< "Available: ";
		cout << boolalpha << carArray[i].available << endl;
	}
	cout <<endl;
}
//bubble sort structure with bubble sort method
void bubbleSort(rentalCar carArray[],rentalCar tempArray[])
{
	int k = 0;
	bool inOrder = false;
	int price1;
	int price2;
	while(inOrder == false)
	{
		for(int i = 0;i < 4;i++)
		{
			price1 = carArray[i].price;
			price2 = carArray[i + 1].price;
			if(price1 > price2)
			{
				tempArray[0] = carArray[i];
				carArray[i] = carArray[i+1];
				carArray[i+1] = tempArray[0];
				k++;
			}
	
		}
		if(k == 0)
		{
			inOrder = true;
		}
		else
		{
			k = 0;
		}
	}
	cout << "The cars have been sorted by price" << endl;
	cout << endl;
}
//checks to see if car is available and cost for available cars
void rentCar(rentalCar carArray[],int pos[])
{
	int days;
	int *ptr = pos;
	cout << "How many days would you like to rent a car?: ";
	cin >> days;
	for(int i = 0;i < 5;i++)
	{
		if(carArray[i].available == 1)
		{
			cout << "[" << *ptr << "]" << ": "<< carArray[i].year 				<< " " <<carArray[i].make << " " << carArray[i].model << 				", " << "$" << carArray[i].price * days << endl;
		}
		ptr++;
	}
	cout << endl;	
}
//asks user which car they want to rent
void checkAvailable(rentalCar carArray[])
{
	int car;
	int days;
	cout << "Which car would you like to rent?: ";
	cin >> car;
	if(carArray[car].available == 0)
	{
		cout << "The car is not available" << endl;
	}
	else if(carArray[car].available == 1)
	{
		carArray[car].available = 0;
		cout << "For how many days?: ";
		cin >> days;
		cout << "The car is available" << endl;
		cout << "The cost will be: " << "$" << carArray[car].price * days 			<< endl;
	}
	cout << endl;
}
//return the strings length
size_t myStringLength(const char *str)
{
	int count = 0;
	while(*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}	
//checks to see which string comes first value wise
int myStringCompare(const char *str1, const char *str2)
{
	
	while(*str1 != '\0' || *str2 != '\0')
	{
		if(*str1 < *str2)
		{
			return -1;
		}
		if(*str1 > *str2)
		{
			return 1;
		}
		if(*str1 != '\0')
		{
			str1++;
		}
		if(*str2 != '\0')
		{
			str2++;
		}
	}	
	return 0;
}		
//copies source string to destination
char *myStringCopy(char *destination, const char *source)
{
	char *ptr = destination;
	while(*source != '\0')
	{
		*ptr = *source;
		ptr++;
		source++;
	}
	*ptr = '\0';
	return destination;
}
//function to add source to end of destination string
char *myStringCat(char *destination, const char *source)
{
	char *ptr = destination;
	while(*ptr != '\0')
	{
		ptr++;
	}
	while(*source != '\0')
	{
		*ptr = *source;
		ptr++;
		source++;
	}
	*ptr = '\0';
	return destination;
}	
