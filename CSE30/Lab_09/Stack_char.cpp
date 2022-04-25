#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include "Stack_char.h"
using namespace std;

char stack_char::push(char x){
        stk[++top] = x;
        cout << x << " Pushed into stack" << endl;
        return true;
}
char stack_char::pop(){
    if (top < 0){
        cout << "ERROR -SUF-" << endl;
        return 0;
    }
    else{
        char x = stk[top--];
        return x;
    }
}
char stack_char::peek(){
    if (top < 0){
        cout << "ERROR -stack is empty-" << endl;
        return 0;
    }
    else{
        char x = stk[top];
        return x;
    }
}
bool stack_char::isEmpty(){
        return (stk[top]);
}
