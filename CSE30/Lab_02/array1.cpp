#include <iostream>

using namespace std;  
int main() 
{ //this might look really ugly cus i had a hard time with this one for some reason
    // some simple int's were using
    int count = 0;
    int array[100000];
    int size = 0;
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
    // Print the array
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    //chck if it increasing 
    for(int i = 0; i <= size; i++){
        // i check only after the first loop because the first num in the array has nothing to be compared too
        if (i != 0 && array[i-1] > array[i]){
            cout << "this is not an increasing array" << endl;
            return 0;
        }
        if (i == size){
            cout << "this is an increasing array" << endl;
        }
    }
    return 0;
}