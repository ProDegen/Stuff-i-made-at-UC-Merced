#include <iostream>

using namespace std;  
int main() 
{ //this might look really ugly cus i had a hard time with this one for some reason
    // some simple int's were using
    int count = 0;
    int array[100000];
    int size = 0;
    int checks = 1;
    int bounty = 0;
    //get array size
            cout << "enter the array size: " << endl;
        cin >> size;
        if(size < 1){
            cout << "ERROR that is not a valid size" << endl;
            return 0;
        }
    // Perform a do-while loop
    cout << "enter the numbers for the array: " << endl;
    do {
        
        scanf("%d", &array[count++]);

    } 
    while (getchar() != '\n' && count < 100);
 
    // Resize the array size to count
    array[count];
    //double check for size
    if (count < 0 or count > size){
        cout << "ERROR you typed too many numbers for your array " << endl;
        return 0;
    } //obtaining bounty number
    cout << "Enter a number to serach in the array: " << endl;
    cin >> bounty;
        // finding the number they want and finding the amount of checks
    for (int i = 0; i <= count; i++){
        if (array[i] == bounty){
            cout << "found value: " << bounty << " at index: " << i << " and it took: " << checks << " check(s)" <<endl;
            if (checks == 1){
                cout << "we ran the best case senario " << endl;
            }
            if (checks == count){
                cout << "we ran the worst case senario" << endl;
            }
            return 0;
        }
        if (i == count && array[i] != bounty){
            cout << "the value was not found in the array" << endl;
            return 0;
        }
        checks++;
    }
    return 0;
}