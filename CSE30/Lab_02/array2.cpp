#include <iostream>

using namespace std;  
int main() 
{ 
    //getting the string
string input = "";
cout << "Enter a string: " << endl;
cin >> input; 
    //labeling how long it is for later
int len = input.length();
int n = len-1;
    // loop to swap the letters arounf
for (int i = 0; i <(len/2); i++){
    swap(input[i],input[n]);
    n=n-1;
}
//printing the string
cout << "this is your input in reverse: " << input << endl;
    return 0;
}