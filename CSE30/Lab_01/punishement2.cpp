#include <iostream>
using namespace std;  
int main() 
{ 
int repeats;
int typo;
cout << "Enter the number of lines for the punishment: " << endl;
cin >> repeats;
cout << "what line should i make a typo on: " << endl;
cin >> typo;
if (repeats < 1 or typo < 1 or typo > repeats)
{
    cout << "You entered an incorrect value for the number of lines!" << endl;
    return 0;
}
for (int i = 0;i <= repeats; i++)
{
if (i == typo)
{
cout << "I will always use object oriented programing." << endl;
}
else {
    cout << "I will always use object oriented programming." << endl;
}
} 


return 0; 
} 
 