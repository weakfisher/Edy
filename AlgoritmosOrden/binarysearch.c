#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




int binarysearhc(int *arr, int len , int v){
    int i = 0;
    while(i<= len-1){
        int med = i+(len-1-i)/2;
        if(arr[med]==v){
            return med;
        }
        if(arr[med]<v){
            i = med+1;
        }
        else{
            len = med-1;
        }

    }
    return -1;

    

}

int main(){
    int arr[] = {1,2,3,4};
    int arr2[] = {10, 20, 30, 40, 50};
    int arr3[] = {3};
    int longi = sizeof(arr3)/sizeof(int);
    printf("%i",binarysearhc(arr3,longi,3));

    return 0;
}