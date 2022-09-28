#include <stdio.h>

int main() {
    int num,t=0,rem=0,sum=0;
    int place = 1;
    float evenc=0,oddc=0,even=0, odd=0 ;
    float evenavg,oddavg;
    while(num != 0){
        if((place%10) == 1 && (place%100) != 11){
         printf("Enter the %d", place);
         printf("st interger: \n");
         scanf("%d", &num); 
         if(num == 0){
            break;
         }
        }
        if((place%10) == 2 && (place%100) != 12){
         printf("Enter the %d", place); 
         printf("nd interger: \n");
         scanf("%d", &num);  
                  if(num == 0){
            break;
         }
        }
        if((place%10) == 3 && (place%100) != 13){
         printf("Enter the %d", place);
         printf("rd interger: \n");
         scanf("%d", &num); 
            if(num == 0){
            break;
         }
        }
        else {
         printf("Enter the %d", place);
         printf("th interger: \n");
         scanf("%d", &num); 
        }
    if(num == 0){
        break;
         }
         else{
                if(num<0){
                    t=num*-1;
                    while(t>0){
                    rem = t%10;
                    sum=sum+rem;
                    t=t/10;
                    }
                }
                    
                
                
                else if(num>0){
                    t=num;
                    while(t>0){
                    rem = t%10;
                    sum=sum+rem;
                    t=t/10;
                    
                }
                }
                //printf("%d\n",sum);
                if((sum%2)==0 && sum != 0){
                  evenc++;  
                  even=even+num;
                }
                else if(sum!= 0){
                oddc++;
                odd=odd+num;
                //printf("%f\n",odd);

                //printf("%f\n",oddc);

                }   
               
                place++;
                sum=0;  
         }
    }

        if(evenc > 0){
            evenavg=(even/(evenc-1));
            printf("Average of inputs whose digits sum up to an even number: %f\n", evenavg);
        }
        if(oddc > 0){
            oddavg=(odd/oddc);
            printf("Average of inputs whose digits sum up to an odd number: %f\n", oddavg);
        }
  return 0; 
 }