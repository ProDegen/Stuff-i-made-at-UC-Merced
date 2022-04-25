#include <iostream>

using namespace std;  
int main() 
{ 
    int count = 0;
    int size = 0;
    int array[100][100];
    int negCheck = 0;
cout << "enter a size for a 2d array: " << endl;
cin >> size;
//checks if the size is valid
if(size < 1){
            cout << "ERROR that is not a valid size" << endl;
            return 0;
        }
if (size > 10){
    cout << "ERROR your size is too large, please enter a size 10 or less" << endl;
    return 0;
}
// Perform a do-while loop multiple times depending on the size
for (int i = 0; i < size; i++){
    count = 0;
    cout << "enter the numbers for array #" << i +1 << endl;

    do {
        scanf("%d", &array[count++][i]);
    } 
    while (getchar() != '\n' && count < 100 && i < size);
}  
// prints the whole array
for (int i = 0; i < size; i++) {
    for (int i2 = 0; i2 < size; i2++) {
         printf("%d ", array[i2][i]);
    }
    cout << "\n" << endl;
    }
for (int i = 0; i < size; i++) {
    for (int i2 = 0; i2 < size; i2++) {
        if (array[i2][i] < 0){
            negCheck++;
        }
    }
}
if (negCheck > 0){
   cout << "you have: " << negCheck << " negatives" << endl; 
}
else {
    cout << "all values are non-negative" << endl;
}
return 0;
}