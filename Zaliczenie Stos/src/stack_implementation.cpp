#include "stack_implementation.h"
#include <iostream>

#define STACK_OK 0
#define STACK_ERROR 1

/*
function shall contain following methods:
    1. Put data on stack
    2. Pop data from stack
    3. Return data from stack
    4. Return number of actual stack size
*/


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
    if(checkIfFull != STACK_OK)
    {
        std::cout << "Cannot proceed with operation because stack is full "
        << stack_top_pointer << "/" << __STACK_SIZE << std::endl;
        return;
    }
    stack_top_pointer++;
    stArr[stack_top_pointer] = data;

    std::cout << "Successfully added element " << stArr[stack_top_pointer]
    << " to stack!" << std::endl;
}

template <class T>
T StackImplementation<T>::pop()
{
    if(stack_top_pointer >= 0)
    {
        stack_top_pointer--;
    }
}

template <class T>
T StackImplementation<T>::returnTopElement()
{
    if(stack_top_pointer >= 0)
    {
        return stArr[stack_top_pointer];
    }
}

template <class T>
int StackImplementation<T>::returnCurrentStackSize()
{
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
