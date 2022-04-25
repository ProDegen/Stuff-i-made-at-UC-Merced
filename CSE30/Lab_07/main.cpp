#include <iostream>
#include <string>
using namespace std;
#include "time.h"

int main()
{
    string input = "",input2 = "";
    int h=0,m=0,s=0;
    cout << "Enter tha start time for your lecture: " << endl;
    cin >> input;
    cout << "Enter tha end time for your lecture: " << endl;
    cin >> input2;
    cout << "Your lecture begins at :";
    timeStrip ts1(input,h,m,s);
    cout << "and ends at : ";
    timeStrip ts2(input2,h,m,s);
   
     return 0;
}