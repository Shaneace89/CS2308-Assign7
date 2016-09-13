/*File Name: CharStack.cpp
 
 Author: Shane Fleming
 Date: 04/21/16
 Assignment Number: 7
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Match Brackets using a Stack, */

#include "CharStack.h"
#include <assert.h>

CharStack::CharStack()
{
    string stackString = "";
}

void CharStack::push(char car)
{
    assert(!isFull());
    stackString += car;
}

char CharStack::pop()
{
    assert(!isEmpty());
    int last = stackString.size() - 1;
    char car = stackString[last];
    stackString.erase(last, 1);
    return car;
}

bool CharStack::isFull() const
{
    if (!stackString.max_size())
        return 1;
    else
        return 0;
}

bool CharStack::isEmpty() const
{
    if (stackString.empty())
        return 1;
    else
        return 0;
}