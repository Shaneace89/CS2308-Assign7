/*File Name: CharStack.cpp
 
 Author: Shane Fleming
 Date: 04/21/16
 Assignment Number: 7
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Match Brackets using a Stack, Holds definitions for functions in CharStack.h */

#include "CharStack.h"
#include <assert.h>

/******************************************************************
 CharStack: constructs a CharStack with default values (empty string)
 returns: NO RETURN
 ******************************************************************/

CharStack::CharStack()
{
    string stackString = "";            //string to act as stack
}

/******************************************************************
 push: pushes next opening bracket to private string
 char car = holds opening bracket to be pushed
 returns: NO RETURN
 ******************************************************************/

void CharStack::push(char car)
{
    assert(!isFull());
    stackString += car;
}

/******************************************************************
 pop: copies last pushed char into car, and deletes it from stackString
 returns: car, last opening bracket from string
 ******************************************************************/

char CharStack::pop()
{
    assert(!isEmpty());
    int last = stackString.size() - 1;  //hold position of last char
    char car = stackString[last];       //hold char of last char
    stackString.erase(last, 1);
    return car;
}

/******************************************************************
 isFull: checks if string is full
 returns: boolean value, true if full, else false
 ******************************************************************/

bool CharStack::isFull() const
{
    if (!stackString.max_size())
        return 1;
    else
        return 0;
}

/******************************************************************
 isEmpty: check if string is empty
 returns: boolean value, true if empty, else false
 ******************************************************************/

bool CharStack::isEmpty() const
{
    if (stackString.empty())
        return 1;
    else
        return 0;
}