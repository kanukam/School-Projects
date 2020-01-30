//Name:Kennedy Anukam
//Class:CS 202
//Project 9
#include <iostream>
#include "NodeQueue.h"
#include "ArrayQueue.h"
using namespace std;

int main()
{
	//Testing node Queue default ctor
	cout << "Testing node queue default ctor" << endl;
	NodeQueue queueOne;
	queueOne.empty();
	//Testing node Queue parameterized ctor
	DataType dataObjOne(1,1);
	cout << "Testing node queue parameterized ctor" << endl;
	NodeQueue queueTwo(10,dataObjOne);
	//testing operator <<
	cout << "PRINTING QUEUE" << endl;
	cout << queueTwo;
	cout << "Testing popping last element" << endl;
	//testing pop
	queueTwo.pop();
	cout << queueTwo;
	//testing size
	cout << "Testing size function" << endl;
	queueTwo.size();
	//testing size
	cout << "Testing front and back queue functions" << endl;
	DataType temp1 = queueTwo.front();
	DataType temp2 = queueTwo.back();
	cout << temp1 << temp2;
	//testing empty and full
	cout << "Testing empty and full queue functions" << endl;
	queueTwo.empty();
	queueTwo.full();
	//testing copy ctor
	cout << "Testing copy ctor" << endl;
	NodeQueue queueThree(queueTwo);
	cout << queueThree;
	cout << "Testing clear function" << endl;
	queueTwo.clear();
	queueTwo.size();
	cout << "END OF NODE QUEUE TESTING" << endl;

	cout << "STARTING ARRAY QUEUE TESTING" << endl;
	//parameterized ctor
	DataType objArrQueue(50,50);
	ArrayQueue arrQueueOne(10,objArrQueue);
	cout << arrQueueOne;
	//pop function
	cout << "Testing pop function" << endl;
	arrQueueOne.pop();
	cout << arrQueueOne;
	DataType objArrQueue2(30,50);
	//push function
	cout << "Testing push function" << endl;
	arrQueueOne.push(objArrQueue2);
	cout << arrQueueOne;
	//size function
	arrQueueOne.size();
	//testing if empty
	arrQueueOne.empty();
	//testing if full
	arrQueueOne.full();
	//front and back of queue
	cout << "Testing front and back of queue" << endl;
	DataType temp3 = arrQueueOne.front();
	DataType temp4 = arrQueueOne.back();
	cout << temp3;
	cout << temp4;
	//copy ctor
	cout << "Copy ctor" << endl;
	ArrayQueue arrQueueTwo(arrQueueOne);
	cout << arrQueueTwo;
	//clear
	cout << "Clearing list" << endl;
	arrQueueOne.clear();
	arrQueueOne.size();
	return 0;
}
