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

int main()
{
    CharStack stack;
    ifstream fin;
    string fileName;
    char charCheck;
    int count = 0;
    
    cout << endl;
    cout << "Please enter file name with file extension to be checked:" << endl;
    cin >> fileName;
    cout << endl;
    
    fin.open(fileName);
    
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
                stack.pop();
                count--;
            }
        
        
        if (stack.isEmpty() || count == 0)
        {
            cout << "No missing Brackets!" << endl << endl;
            return 0;
        }
        else
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
        
        return 0;
    }
}