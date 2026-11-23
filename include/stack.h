#ifndef STACK_H
#define STACK_H

class stack{
    int top;
    int size;
    int* arr;
    public:
    stack(int size);
    void push(int data);
    int pop();

};

#endif