#include <iostream>
using namespace std;  
int main() 
{ 
int repeats;
cout << "Enter the number of lines for the punishment" << endl;
cin >> repeats;
for (int i = 0;i <= repeats; i++)
{
cout << "I will always use object oriented programming." << endl;
}  
if (repeats < 1)
{
    cout << "You entered an incorrect value for the number of lines!" << endl;
}
return 0; 
} 
 