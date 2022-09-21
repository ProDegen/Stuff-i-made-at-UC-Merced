#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printArr(int *a, int size, char *name){
	//Your code here
    printf("%s array's contents: ", name);
    for(int i =0; i < size;i++){
        printf("%d ", *(a + i));
    }
    printf("\n");
}

int* arrCopy(int *a, int size){
	//Your code here
    int *pointer1 = a,
 
        // pointer2 pointing at end of the array
        *pointer2 = a + size ;
    while (pointer1 < pointer2) {
        //swap(pointer1, pointer2);
        int temp = *pointer1;
        *pointer1 = *pointer2;
        *pointer2 = temp;
        pointer1++;
        pointer2--;
    }
    
}

 
int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i;
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &n);

    //Dynamically create an int array of n items
    //Your code here
    //for(int j = 0; j< n; j++){
    //    arr + j; 
    //}
    arr = (int*) malloc(sizeof(int) * n);
    //Ask user to input content of array
	//Your code here
        for(int j = 0; j< n;  j++){
        printf("Enter Array element #%d: ", j+1);
        scanf("%d", (arr+j));

       
    }     
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n, "Original");
    
	//Copy array with contents in reverse order
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n, "Copied");

    printf("\n");

    return 0;
}