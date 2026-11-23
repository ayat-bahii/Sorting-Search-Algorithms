#include<iostream>
#include "stack.h"

using namespace std;

stack::stack(int size){
    top=0;
    this->size=size;
    arr=new int[size];
}

void stack::push(int data){
    top++;
    arr[top]=data;
}

int stack::pop(){
    int val=arr[top];
    arr[top]=0;
    top--;
    return val;
}