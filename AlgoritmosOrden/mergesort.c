#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void mergesort(int *arr, int in, int fin){
    if (in<fin){
        int m = (in + (fin-in))/2;
        mergesort(arr,in,m);
        mergesort(arr,m+1,fin);
    }
}
void merge(int *arr,int in,int m,int fin){
    int i,j,k;
    int tam1 = m-in+1;
    int tam2= fin-m;
    int left[tam1];
    int right[tam2];
    for(i=0;i<tam1;i++){
        left[i] = arr[in+i];
    }
    for(j= 0; j<tam2;j++){
        right[i]=arr[m+j+1];
    }
    i = 0;
    j=0;
    k = fin;
    while(i<tam1 && j,tam2){
        if(left[i]<right[j]){
            arr[k]= left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<tam1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<tam2){
        arr[k]= right[j];
        j++;
        k++;
    }
}


int main(){
    int arr[] = {12,5,6,1,7,3,51,5,2};
    int longitud = sizeof(arr)/sizeof(int);
    mergesort(arr,0,longitud);
    for(int i = 0 ; i<longitud; i++){
        printf("%i",arr[i]);
    }
    return 0;
}