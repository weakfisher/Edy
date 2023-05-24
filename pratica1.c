#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int dato;
    struct Node * sig;
}nodo;
int noSeEncuentra(char* ar1,char x){
    for (int i =0;i<strlen(ar1);i++){
        if (ar1[i] == x){
            return 0;
        }
    }
    return 1;
}
    
char* caracteresEnComun(char* ar1,char* ar2){
    if(strlen(ar1)==0  || strlen(ar2)==0){
        return '\0';
    }
    int maxCharR;
    if (strlen(ar1)>=strlen(ar2)){
        maxCharR = strlen(ar1);
    }
    else{
        maxCharR = strlen(ar2);
    }
    char* charRepes = calloc(maxCharR, sizeof(char));
    
    int contador=0;
    for(int i = 0;i<strlen(ar1);i++){
        for(int j = 0;j<strlen(ar2);j++){
            if (ar1[i]==ar2[j] && (noSeEncuentra(charRepes,ar1[i])==1)){
                charRepes[contador] =ar1[i];
                contador++;
            }
        }
    }
    //char * cadena = malloc(sizeof(char)*strlen(charRepes));
    // printf("la cdena es %s",charRepes);
   // cadena = charRepes;
    return charRepes;
}

int main(){
   char cadena1[] = "holaholab";
   char cadena2[]= "chauchaub";
   printf("%s ", caracteresEnComun(cadena1,cadena2));
}