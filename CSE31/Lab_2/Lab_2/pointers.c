#include <stdio.h> 
 
 int main() { 
  int x=0, y=0, *px, *py;
  px=&x;
  py=&y; 
  int arr[10]={0,1,2,3,4,5,6,7,8,9}; 
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", arr[0]);
    printf("%p\n", &x);
    printf("%p\n", &y);
    printf("%p\n", px);
    printf("%p\n", py);  
    printf("%p\n", &px);
    printf("%p\n", &py);   
    for(int i = 0; i<10;i++){
        printf("%d\n", *(arr + i));
    }
    printf("%p\n", arr);
    printf("%p\n", &arr[0]);  
  return 0; 
}