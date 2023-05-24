#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubblesort(int *arr,int longi){
    bool hicealgo = true;
    while(hicealgo){
        hicealgo = false;
        for(int i= 0 ; i <longi-1;i++){
            if (arr[i]>arr[i+1]){
                int tmp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i]= tmp;
                hicealgo = true;
            }
        }
    }
     
}


int main(){
    int arr[5]= {1,4,9,2,8};
    int longi = sizeof(arr)/sizeof(int);
 
    bubblesort(arr,longi);
    for(int i= 0 ; i<longi;i++){
        printf(" %i",arr[i]);
    }
    return 0;
}