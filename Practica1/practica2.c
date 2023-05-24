#include <stdio.h>
#include <stdlib.h>

//
// int string len(char* str), que retorne la longitud de la cadena str, excluyendo el car ́acter nulo
// (’\0’).

int string_len(char* cadena){
  int contador = 0;

  while(cadena[contador] != '\0'){
    contador++;
  }
  return contador;
}

int main(){
    char nombre[]="Milton";
    char dni[] = "Milton Pacheco";
    int contar = string_len(dni);
    printf("%i\n",contar );
    return 0;
}
