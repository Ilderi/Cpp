#include <iostream>
#include <string>
// dodawana jest biblioteka klasy stosu
//#include "stack_implementation.h"
// poni¿ej mo¿na zmieniæ rozmiar stack-u
#define __STACK_SIZE 10
#define test_count 14
//stack overflow 15579172
#include "stack_implementation.cpp"

using namespace std;



int main()
{
    StackImplementation<double> double_stack;
    StackImplementation<string> string_stack;
    SetConsoleTextAttribute(hConsole, 7);

    cout << "\nTesting \"double\" stack\n" << endl;

    double_stack.returnCurrentStackSize();
    double_stack.pop();
    double_stack.push(3.141);
    double_stack.returnCurrentStackSize();
    double_stack.returnTopElement();
    double_stack.pop();
    double_stack.pop();
    SetConsoleTextAttribute(hConsole, 7);

    cout << "\nPushing to \"double\" stack\n" << endl;

    double_stack.returnCurrentStackSize();
    for(int i = 0; i < test_count; i++)
    {
        double_stack.push(i);
        double_stack.returnCurrentStackSize();
    }
    SetConsoleTextAttribute(hConsole, 7);

    cout << "\nReading from \"double\" stack\n" << endl;

    double_stack.returnCurrentStackSize();
    for(int i = 0; i < test_count; i++)
    {
        double_stack.returnTopElement();
        double_stack.pop();
        double_stack.returnCurrentStackSize();
    }
    SetConsoleTextAttribute(hConsole, 7);

    cout << "\nTesting \"string\" stack\n" << endl;

    string_stack.returnCurrentStackSize();
    string_stack.pop();
    // compiler error, works as expected
    // string_stack.push(3.141);
    string_stack.push("Programowanie w C++ jest do d00py");
    string_stack.returnCurrentStackSize();
    string_stack.returnTopElement();
    string_stack.pop();
    string_stack.pop();
    SetConsoleTextAttribute(hConsole, 7);

    cout << "\nPushing to \"string\" stack\n" << endl;

    string_stack.returnCurrentStackSize();
    for(int i = 0; i < test_count; i++)
    {
        string_stack.push(("test " + to_string(i)));
        string_stack.returnCurrentStackSize();
    }
    SetConsoleTextAttribute(hConsole, 7);

    cout << "\nReading from \"string\" stack\n" << endl;

    string_stack.returnCurrentStackSize();
    for(int i = 0; i < test_count; i++)
    {
        string_stack.returnTopElement();
        string_stack.pop();
        string_stack.returnCurrentStackSize();
    }
    SetConsoleTextAttribute(hConsole, 7);
    return 0;
}
