//Author: Kennedy Anukam
//Purpose: To test stack implementation by evaluating postfix expressions
//Date: September 25, 2019
//Assignment: Project 2
#include <iostream>
#include <string>
#include <ctype.h>
#include "StackLinked.h"

float postFix ( const string &expression );
int main()
{
	//Testing Postfix function with 5 test cases
	cout << "POSTFIX TEST CASES" << endl << endl;
	cout << "(2+3)*(4/2) = 23+42/* = " << postFix("23+42/*") << endl;
	cout << "(5^2)*4 = 52^4* = " << postFix("52^4*") << endl;
	cout << "(4^2)*(2+2)-1 = 42^22+*1- = " << postFix("42^22+*1-") << endl;
	cout << "(1/2)*(1/4)*2 = 12/14/*2* = " << postFix("12/14/*2*") << endl;
	cout << "(2*2)/(1*1) = 22*11*/ = " << postFix("22*11*/") << endl;
	cout << endl;
			
    string inputLine;            // Input line
    cout << "This program outputs the result of postfix expressions."
         << endl;

    while( cin )
    {
        cout << "Enter postfix expression (<EOF> to quit) : "
             << endl;
        // Read in one line
        inputLine = "";
		getline(cin,inputLine);
        cout << "The result is: " << postFix(inputLine) << endl;
    }
	
    return 0;
}
//Takes in postfix expression and outputs the result
float postFix( const string &expression )
{
	StackLinked<float> floatStack;
	for(unsigned int i=0;i<expression.length();i++)
	{
		if(isdigit(expression[i]))
		{
			floatStack.push(expression[i] - '0');
		}
		else if(expression[i] != ' ')
		{
			float operandOne = floatStack.pop();
			float operandTwo = floatStack.pop();
			switch(expression[i])
			{
				case '+':
					floatStack.push(operandTwo + operandOne);
					break;
				case '-':
					floatStack.push(operandTwo - operandOne);
					break;
				case '*':
					floatStack.push(operandTwo * operandOne);
					break;
				case '/':
					floatStack.push(operandTwo / operandOne);
					break;
				case '^':
						float temp = operandTwo;
						for(int i = 0;i < operandOne - 1; i++)
						{
							operandTwo *= temp;
						}
						if(operandOne == 0)
						{
							operandTwo = 1;
						}
						floatStack.push(operandTwo);
					break;
			}
		}
	}
	return floatStack.pop();
}


