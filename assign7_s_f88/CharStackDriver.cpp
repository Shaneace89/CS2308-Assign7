/*File Name: CharStackDriver.cpp
 
 Author: Shane Fleming
 Date: 04/21/16
 Assignment Number: 7
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Match Brackets using a Stack, */

#include "CharStack.h"
#include <iostream>
#include <fstream>

/******************************************************************
 missing: checks at end of file if any opening are left in stack
 CHECK ERROR 1/3: missing } : if you reach the end of the file, and there is an
 opening { that was never matched
 char charCheck = holds bracket to be checked
 CharStack stack = Stack to be popped
 returns: NO RETURN
 ******************************************************************/

void missing(char charCheck, CharStack stack)
{
    charCheck = stack.pop();
    if (charCheck == '{')
        cout << "Missing '}'" << endl;
    else if (charCheck == '(')
        cout << "Missing ')'" << endl;
    else if (charCheck == '[')
        cout << "Missing ']'" << endl;
    
    cout << endl;
}

/******************************************************************
 expected: checks for wrong closing bracket
 CHECK ERROR 2/3: expected } but found ) : this is a wrong closing bracket
 char charCheck = holds bracket to be checked
 CharStack stack = Stack to be popped
 returns: returns true if all was as expected, else false
 ******************************************************************/

bool expected(char charCheck, CharStack stack)
{
    char old;
    
    if(charCheck == '}')
    {
        old = stack.pop();
        if (old == '{')
            return 1;
        else
        {
            cout << "Expected other bracket" << endl << endl;
            stack.push(old);
            return 0;
        }
    }
    else if (charCheck == ')')
    {
        old = stack.pop();
        if (old == '(')
        {
            return 1;;
        }
        else
        {
            cout << "Expected other bracket" << endl << endl;
            stack.push(old);
            return 0;
        }
    }
    else if (charCheck == ']')
    {
        old = stack.pop();
        if (old == '[')
            return 1;
        else
        {
            cout << endl << "Expected other bracket" << endl;
            stack.push(old);
            return 0;
        }
    }
    return 0;
}

/******************************************************************
 main: takes input for desired file, calls functions to check file
 returns: '0', ends program
 ******************************************************************/

int main()
{
    CharStack stack;        //creates instance of class CharStack
    ifstream fin;           //file to be opened
    string fileName;        //hold file name from user input
    char charCheck;         //holds bracket to be checked
    int count = 0;          //number of chars (brackets) in string
    bool booExpected = 0;   //holds value returned by expected()
    
    cout << endl;
    cout << "Please enter file name with file extension to be checked:" << endl;
    cin >> fileName;
    cout << endl;
    
    fin.open(fileName.c_str());
    
    if (!fin.is_open())
    {
        cout << "File not found, please try again" << endl << endl;
    }
    else
    {
        while(fin >> charCheck)
            if (charCheck == '{' || charCheck == '(' || charCheck == '[')
            {
                stack.push(charCheck);
                count++;
            }
        
            else if(charCheck == '}' || charCheck == ')' || charCheck == ']')
            {
/*CHECK ERROR 3/3: unmatched } : this occurs if there is a closing bracket
     but not an opening bracket (not even one of the wrong kind)*/
                if (stack.isEmpty())
                {
                    cout << "Unmatched opening bracket" << endl << endl;
                    return 0;
                }
                else
                {
                    booExpected = expected(charCheck, stack);
                    
                    if (booExpected == 1)
                    {
                        stack.pop();
                        count--;
                    }
                    else
                        return 0;
                }
            }
        
        
        if (stack.isEmpty() || count == 0)
        {
            cout << "No missing Brackets!" << endl << endl;
            return 0;
        }
        else
            missing(charCheck, stack);
        
        return 0;
    }
}