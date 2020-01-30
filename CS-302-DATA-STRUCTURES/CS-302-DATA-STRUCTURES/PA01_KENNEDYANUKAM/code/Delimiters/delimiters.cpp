//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>
#include<string>
#include "StackLinked.h"


//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main()
{
	//Implementation of testing 5 delimiter test cases
	cout << "Delimiters Test Cases" << endl << endl;
	cout << "[()] " << (delimitersOk("[()]") ? "Valid" : "Invalid") << endl;
	cout << "{(4*4+2)} " << (delimitersOk("{(4*4+2)}") ? "Valid" : "Invalid") << endl;
	cout << "[()]] " << (delimitersOk("[()]]") ? "Valid" : "Invalid") << endl;
	cout << "(4*4)} " << (delimitersOk("(4*4)}") ? "Valid" : "Invalid") << endl;
	cout << "[(4*4)] " << (delimitersOk("[(4*4)]") ? "Valid" : "Invalid") << endl << endl;

    string inputLine;           // Input line
    char ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;
    	
        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }
	
    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below
bool delimitersOk ( const string &expression )
{
	int stringLength = expression.length();
	char single = ' ';
	StackLinked<char> charStack;
	char temp = ' ';
//looks for matching delimiter, if it sees closing bracket and the popped bracket doesnt match the other returns false
	try
	{
		for(int i=0;i<stringLength;i++)
		{
			single = expression[i];
			switch(single)
			{
				case '(':
						charStack.push(single);
						break;
				case '{':
						charStack.push(single);
						break;
				case '[':
						charStack.push(single);
						break;
				case ')':
						temp = charStack.pop();
						if(temp != '(')
						{
							return false;
						}
						break;
				case '}':
						temp = charStack.pop();
						if(temp != '{')
						{
							return false;
						}
						break;
				case ']':
						temp = charStack.pop();
						if(temp != '[')
						{
							return false;
						}
						break;
				}
			}
		}
		catch(logic_error)
		{
			return false;
		}
//If it is empty then all delimiters had a matching pair and that means the expression is legitimate
		if(charStack.isEmpty())
		{
			return true;
		}
		else
		{
			return false;
		}
}


