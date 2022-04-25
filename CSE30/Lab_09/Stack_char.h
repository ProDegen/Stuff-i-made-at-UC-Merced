#ifndef STACKCHAR_H
#define STACKCHAR_H
#include <iostream>
using namespace std;
#define MAX 1000
class stack_char{
    int top;
    public: 
    
    char stk[MAX];
    stack_char() {top = -1;}
    char push(char x);
    char pop();
    char peek();
    bool isEmpty();
};

#endif