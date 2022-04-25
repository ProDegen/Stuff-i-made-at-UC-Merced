#include <iostream>
int asort(int array[], int count);
int dsort(int array[], int count);
using namespace std;  

int main() 
{ //this is just a copy of my code from last lab cus i actually 
//planned to make this program last week but the assignment didnt call for it
    int count = 0;
    int array[100000];
    int size = 0;
    int checks = 1;
    int bounty = 0;
    int choice = -1;
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
    cout << "type 0 for ascending and 1 for descending: " << endl;
    cin >> choice;
    if (choice == 0){
    //sorting the array in ascending order
    int totalSwaps = asort(array, count);   
    cout << "Swaps: " << totalSwaps << endl; 
    // Print the array
    cout << "This is the sorted array in ascending order: " << endl;
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    return 0;  
    }
    if(choice == 1){
    //sorting the array in descending order
    int totalSwaps = dsort(array, count);   
    cout << "Swaps: " << totalSwaps << endl; 
    // Print the array
    cout << "This is the sorted array in descending order: " << endl;
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
   }
   return 0;
    }
    else{
        cout << "ERROR that is not a valid choice!" << endl;
        return 0;
    }

}
//while i already had a way to sort it in the previous excersise i needed a more 
//interactive(if thats the right word to describe it as) way to get the swaps

//this code allows for it to go in ascending order
int asort(int array[], int count){

    int i, j, temp;
    int swaps = 0;
    for(i = 0; i < count-1; ++i){

        for(j=0; j<count-1-i; ++j){

            if(array[j] > array[j+1]){

                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                swaps++;
            }
        }
    }

    return swaps;
}
//this one goes in descending order
int dsort(int array[], int count){

    int i, j, temp = 0;
    int swaps = 0;
    for(i = 0; i < count-1; ++i){

        for(j=count; j>0; --j){

            if(array[j] > array[j-1]){

                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
                swaps++;
            }
        }
    }

    return swaps;
}