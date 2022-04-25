#include <iostream>
using namespace std;  
void AselectionSort(int arr[],int n);
void DselectionSort(int arr[],int n);
void printArray(int array[],int size);
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
    AselectionSort(array, count);   
    // Print the array
    cout << "This is the sorted array in ascending order: " << endl;
    printArray(array,size);
    return 0;  
    }
    if(choice == 1){
    //sorting the array in descending order
    DselectionSort(array, count);       
    // Print the array
    cout << "This is the sorted array in descending order: " << endl;
    printArray(array,size);
   return 0;
    }
    else{
        cout << "ERROR that is not a valid choice!" << endl;
        return 0;
    }

}
void swap(int *xp,int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void AselectionSort(int arr[],int n){
    int i,j,minIndx;
    for (i = 0; i<n-1;i++){
        minIndx = i;
        for(j = i+1; j < n;j++){
            if(arr[j] < arr[minIndx])
                minIndx = j;
                swap(&arr[minIndx],&arr[i]);
            
        }
    }
}
void DselectionSort(int arr[],int n){
    int i,j,maxIndx;
    for (i = n-1; i>-1;i--){
        maxIndx = i;
        for(j = n-1; j >-1;j--){
            if(arr[j] > arr[maxIndx])
                maxIndx = j;
                swap(&arr[i],&arr[maxIndx]);
            
    }
    }
}
void printArray(int arr[], int size) { 
    int i; 
    for (i=0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
}
