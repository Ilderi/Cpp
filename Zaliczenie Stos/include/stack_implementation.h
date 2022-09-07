#ifndef STACK_IMPLEMENTATION_H
#define STACK_IMPLEMENTATION_H

#ifndef __STACK_SIZE
#define __STACK_SIZE 64
#endif // __stack_size

template<class T>
class StackImplementation
{
    public:
        StackImplementation();
        void push(T data);
        void pop();
        int returnCurrentStackSize();
        T returnTopElement();
        virtual ~StackImplementation();

    protected:
    int checkIfFull();
    int checkIfEmpty();

    private:
    int stack_top_pointer;
    T stArr[__STACK_SIZE];
};

#endif // STACK_IMPLEMENTATION_H
