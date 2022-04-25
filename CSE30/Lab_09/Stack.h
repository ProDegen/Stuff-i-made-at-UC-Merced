#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
#define MAX 1000
class stack{
    int top;
    public: 
    
    int stk[MAX];
    stack() {top = -1;}
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

#endif