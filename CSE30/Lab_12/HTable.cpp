#include "HTable.h"
#include <iostream>
using namespace std;

HTable::HTable(){
    max_size = 23;
    dt = new data[max_size];
    for (int i = 0; i < max_size; i++){
        dt[i].value = "N/A";
        dt[i].key = -1;
        numel = 0;
    }

}
HTable::HTable (int t_size){
    max_size = t_size;
    dt = new data[max_size];
    for (int i = 0; i < max_size; i++){
        dt[i].value = "N/A";
        dt[i].key = -1;
        numel = 0;
    }
}
int HTable::hash(int &k){
    return k % max_size;
    
}
int HTable::rehash(int &k){
    return (k+1) % max_size;
    
}
int HTable::add(data &d){
    if(numel == max_size){
        return -1;
    }
    int index = hash(d.key);
    
    if(dt[index].key == -1 ){
        dt[index].value = d.value;
        dt[index].key = d.key;
        numel++;
        return 0;
    }
    else{      
        int loop = 0;
        int indexCheck = index;
        for (int i = index; i < max_size; i++){
            index = rehash(index); 
            if(dt[index].key == -1){
                dt[index].value = d.value;
                dt[index].key = d.key;
                numel++;
                return 0;
            }
        }
        
        return 0;
    }
    
}
int HTable::remove(data &d){
     for (int i = 0; i < max_size; i++){
         if(dt[i].key==d.key){
            dt[i].value = "N/A";
            dt[i].key = -1;
            numel--; 
            return 0;
         }
     }
return -1;
}
void HTable::output(){
    for (int i = 0; i < max_size;i++){
        cout << i << "-> " << dt[i].key << " " << dt[i].value << endl;
    }
}