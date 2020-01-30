//Name:Kennedy Anukam
//Class:CS 202
//Project 8
#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main()
{
	cout <<"NODE TESTING" << endl;
	//datatype obj for list parametized ctor
	DataType dataObj(10,10);
	//Parametized ctor
	NodeList listOne(5,dataObj);
	//Printing List
	cout << listOne;
	//determine size of list
	cout << "The list has " << listOne.size() << " members" << endl;
	//testing add before
	DataType objInsertBefore(5,5);
	cout << "Testing insertion before Node " << endl;
	listOne.insertBefore(dataObj,objInsertBefore);
	cout << listOne;
	//testing insert after
	cout << "Testing insert after Node" << endl;
	DataType objInsertAfter(7,7);
	listOne.insertAfter(objInsertBefore,objInsertAfter);
	cout << listOne;
	//Testing deleting a node
	cout << "Testing deleting a node" << endl;
	listOne.erase(objInsertAfter);
	cout << listOne;
	//testing returning back and front elements of list
	cout << "Testing front and back functions" << endl;
	Node *front = listOne.front();
	Node *back = listOne.back();
	DataType front2 = front->data();
	DataType back2 = back->data();
	cout << front2;
	cout << back2;
	//testing find 
	int num = 0;
	cout << "press 5 to search for two numbers in the list" << endl;
	cin >> num;
	while(num != 1)
	{
		cout << "Enter two numbers to search the Node list" << endl;
		int integer;
		double doub;
		cin >> integer;
		cin >> doub;
		DataType userData(integer,doub);
		Node * previous = NULL;
		Node *test = listOne.find(userData,previous);
		if(test != NULL)
		{
			cout << "These numbers are in the list" << endl;
		}
		else
		{
			cout << "These numbers are not in the list" << endl;
		}
		cout << "press 5 to search the list,press 1 to exit selection" << endl;
		cin >> num;
	}
	//testing assignment operator
	NodeList listTwo;
	listTwo = listOne;
	cout << "Testing assignment operator\nPrinting list Two\n";
	cout << listTwo;
	//testing copy ctor
	NodeList listThree(listTwo);
	cout << "Testing copy ctor\nPrinting list Three\n";
	cout << listThree;
	//testing operator[]
	cout << "Testing bracket operator overload" << endl;
	DataType dataObjTest = listOne[1];
	cout << dataObjTest;
	//check if empty
	listOne.empty();
	//clear list	
	listOne.clear();
	//confirm that the list was succesfully cleared
	listOne.empty();

	cout << "That concludes the node based testing" << endl;
	cout << "ARRAY LIST TESTING" << endl;
	ArrayList arrList;
	DataType arrData(3,3);
	ArrayList arrList2(6,arrData);
	cout << arrList2;
	//copy ctor
	ArrayList arrList3(arrList2);
	cout << arrList3;
	//checking if empty
	arrList2.empty();
	//checking size
	arrList2.size();
	//clearing list checking size
	arrList3.clear();
	arrList3.size();
	//testing front and back
	cout << "Testing front and back functions" << endl;
	DataType *arrData2 = arrList2.front();
	DataType *arrData3 = arrList2.back();
	cout << *arrData2;
	cout << *arrData3;
	//assignment operator array list based
	cout << "Testing assignment operator" << endl;
	arrList = arrList2;
	cout << arrList;
	//testing find for array based list
	//testing find 
	int num2 = 0;
	cout << "press 5 to search for two numbers in the array based list" << endl;
	cin >> num2;
	while(num2 != 1)
	{
		cout << "Enter two numbers to search the Array Based list" << endl;
		int integer;
		double doub;
		cin >> integer;
		cin >> doub;
		DataType userData(integer,doub);
		DataType * previous = NULL;
		DataType *test = arrList.find(userData,previous);
		if(test != NULL)
		{
			cout << "These numbers are in the list" << endl;
		}
		else
		{
			cout << "These numbers are not in the list" << endl;
		}
		cout << "press 5 to search the Array Based list,press 1 to exit selection" << endl;
		cin >> num2;
	}
	//erasing an item
	cout << "Testing erasing a list item" << endl;
	arrList2.erase(arrData);
	cout << arrList2;
	//testing inserting after
	cout << "Testing insert after" << endl;
	DataType random(9,9);
	arrList.insertAfter(arrData,random);
	cout << arrList;
	cout << "Testing insert before" << endl;
	arrList.insertBefore(arrData,random);
	cout << arrList;
	return 0;
}
