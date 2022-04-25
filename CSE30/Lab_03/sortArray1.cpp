#include <iostream>
#include <algorithm>
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
} 
    //sorting the array
    sort(array, array + count);    
    // Print the array
    cout << "This is the sorted array in ascending order: " << endl;
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    cout << "This is the array selected the minimum for the traverse of the array" << endl;
    return 0;
}