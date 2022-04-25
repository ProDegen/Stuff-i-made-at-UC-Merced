#include <iostream>
#include <string>
#include "Stack.h"
#include "Stack_char.h"
using namespace std;


int main()
{
    int i = 0;
    class stack s;
    class stack_char c;
    
    while (i <= 10){
        s.push(i);
        i++;
    }
    s.pop();
    s.pop();
    s.pop();
    cout << s.peek() << "" << endl;

    c.push('A');
    c.push('B');
    cout << c.peek() << "" << endl;
    c.pop();
    cout << c.peek() << "" << endl;
     return 0;
}