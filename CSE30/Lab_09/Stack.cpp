#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include "Stack.h"
using namespace std;

bool stack::push(int x){
        stk[++top] = x;
        cout << x << " Pushed into stack" << endl;
        return true;
}
int stack::pop(){
    if (top < 0){
        cout << "ERROR -SUF-" << endl;
        return 0;
    }
    else{
        int x = stk[top--];
        return x;
    }
}
int stack::peek(){
    if (top < 0){
        cout << "ERROR -stack is empty-" << endl;
        return 0;
    }
    else{
        int x = stk[top];
        return x;
    }
}
bool stack::isEmpty(){
        return (top < 0);
}
