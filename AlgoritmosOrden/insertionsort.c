#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void insertio_sort(int* arr,int longi){
    for(int i = 1;i<longi;i++){
        for(int j=i; j>0;j--){
            if(arr[j]<arr[j-1]){
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1]= tmp;
            }
        }

    }
}


void imprimir(int *arr, int longi){
      for(int i= 0 ; i<longi;i++){
        printf(" %i",arr[i]);
    }
}

int main(){
    int arr[5]= {5,4,1,3,9};
    int longi = sizeof(arr)/sizeof(int);

    insertio_sort(arr,longi);
    
    imprimir(arr,longi);
    return 0;
}