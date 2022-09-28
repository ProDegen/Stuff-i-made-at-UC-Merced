#include <stdio.h>

int main() {
    int reps = 0;
    int typo = 0;
    printf("Enter the ammount of repititions: \n");
    scanf("%d", &reps);
    
    while(reps <= 0){
        printf("That value is not valid please enter a new one: \n");
        scanf("%d", &reps);
    }
    printf("Enter where you would like a typo: \n");
    scanf("%d", &typo);
    
    while(typo <= 0 || typo > reps){
        printf("That value is not valid please enter a new one: \n");
        scanf("%d", &typo);
    }
    if(reps > 0){
    for(int i=0;i<reps;i++){
        if(i!= typo-1){
            printf("Coding in C is fun and interesting! \n"); 
        }
        else{
           printf("Cading in C is fun end intreseting! \n"); 
        }
    }
    }
    return 0;
 }