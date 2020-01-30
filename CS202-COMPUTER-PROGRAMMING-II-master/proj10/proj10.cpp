#include "ArrayStack.h"
#include "NodeStack.h"
#include<iostream>
using namespace std;
int main()
{
	cout << "ARRAY STACK TESTING" << endl;
	//default ctor
	ArrayStack <int> arrayStack;
	//parameterized ctor
	int data = 10;
	ArrayStack <int> arrayStackTwo(5,data);
	//printing stack
	cout << arrayStackTwo;
	//popping from stack
	arrayStackTwo.pop();
	cout << arrayStackTwo;
	arrayStackTwo.size();
	//pushing onto stack
	int dataTwo = 7;
	arrayStackTwo.push(dataTwo);
	cout << arrayStackTwo;
	//testing top
	cout << "Testing top" << endl;
	int dataThree = arrayStackTwo.top();
	cout << dataThree << endl;
	//clear stack 
	arrayStackTwo.clear();
	//empty?
	arrayStackTwo.empty();
	cout << "That concludes array stack testing" << endl;
	//Node stack testing
	cout << "Beginning Node Stack testing" << endl;
	//default ctor
	NodeStack <int> nodeStack;
	//parametized ctor
	NodeStack <int> nodeStackTwo(5,dataTwo);
	cout << nodeStackTwo;
	//copy ctor
	NodeStack <int> nodeStackThree(nodeStackTwo);
	cout << nodeStackThree;
	//pop
	nodeStackTwo.pop();
	cout << nodeStackTwo;
	//size empty;
	cout <<"Empty: " << boolalpha << nodeStackTwo.empty() << endl;
	nodeStackTwo.size();
	//push
	nodeStackTwo.push(data);
	cout << nodeStackTwo;
	return 0;
}
