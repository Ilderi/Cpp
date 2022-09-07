#include "stack_implementation.h"
#include <iostream>
// Windows only
#include <windows.h>

#define STACK_ERROR 0
#define STACK_OK 1

/*
function shall contain following methods:
    1. Put data on stack
    2. Pop data from stack
    3. Return data from stack
    4. Return number of actual stack size
*/

//10 - zielony
//12 - czerwony
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//StackImplementation::

template <class T>
StackImplementation<T>::StackImplementation()
{
    stack_top_pointer = -1;
}

template <class T>
StackImplementation<T>::~StackImplementation()
{

}

template <class T>
void StackImplementation<T>::push(T data)
{
    if(checkIfFull() != STACK_OK)
    {
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "[STACK PUSH ERROR]        ";
        std::cout << "Cannot proceed with operation because stack is already full" << std::endl;
        return;
    }
    stack_top_pointer++;
    stArr[stack_top_pointer] = data;
    SetConsoleTextAttribute(hConsole, 2);
    std::cout << "[STACK PUSH SUCCESS]      ";
    std::cout << "Successfully added element to stack!" << std::endl;

}

template <class T>
void StackImplementation<T>::pop()
{
    if(stack_top_pointer >= 0)
    {
        SetConsoleTextAttribute(hConsole, 2);
        std::cout << "[STACK POP SUCCESS]       Successfully deleted element from stack!"
        << std::endl;
        stack_top_pointer--;
        return;
    }
    SetConsoleTextAttribute(hConsole, 12);
    std::cout << "[STACK POP ERROR]         ";
    std::cout << "Cannot proceed with operation because stack is already empty" << std::endl;
    return;
}

template <class T>
T StackImplementation<T>::returnTopElement()
{
    if(stack_top_pointer >= 0)
    {
        SetConsoleTextAttribute(hConsole, 8);
        std::cout << "[STACK TOP STATUS]        Current top element is: \""
        << stArr[stack_top_pointer] << "\""<< std::endl;
        return stArr[stack_top_pointer];
    }
    SetConsoleTextAttribute(hConsole, 8);
    std::cout << "[STACK TOP STATUS         ";
    SetConsoleTextAttribute(hConsole, 3);
    std::cout << "Stack is empty"<< std::endl;
}

template <class T>
int StackImplementation<T>::returnCurrentStackSize()
{
    SetConsoleTextAttribute(hConsole, 8);
    std::cout << "[STACK SIZE STATUS]       Current stack size is: "
    << (stack_top_pointer + 1) << "/" << __STACK_SIZE << std::endl;
    return (stack_top_pointer+1);
}


template <class T>
int StackImplementation<T>::checkIfFull()
{
    if(stack_top_pointer == (__STACK_SIZE-1))
    {
        return STACK_ERROR;
    }
    return STACK_OK;
}

template <class T>
int StackImplementation<T>::checkIfEmpty()
{
    if(stack_top_pointer == -1)
    {
        return STACK_ERROR;
    }
    return STACK_OK;
}
