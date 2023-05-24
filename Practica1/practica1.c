#include <stdio.h>
#include <stdlib.h>





// la mediana de un arreglo ordenado de n n ́umeros se define como el elemento del medio cuando n es
// impar y como el promedio de los dos elementos del medio cuando n es par. Por ejemplo,
// mediana([-1.0, 2.2, 2.9, 3.1, 3.5]) = 2.9
// mediana([-1.0, 2.2, 2.9, 3.1]) = 2.55
// Escriba una funci ́on que reciba un arreglo, no necesariamente ordenado, de n ́umeros y calcule su mediana:
// float mediana(float *arreglo, int longitud);

float mediana(float *arreglo,int longitud){
  float promedio = 0;
  if (longitud % 2 == 0){
    for(int i =0 ;i<longitud;i++){
      promedio += arreglo[i];
    }
    float total = promedio / longitud;
    return total;
  }
  else{
    return arreglo[(longitud/2)];
  }
}


int main(){
  float arreglo[] = {1,2,3,4,5};
  float arreglo2[] = {1,2,3,4,5,6};
  float arreglo3[] = {-1.0, 2.2, 2.9, 3.1};
  int longitud = sizeof(arreglo3)/sizeof(int);
  float medianas = mediana(arreglo3,longitud);
  printf("%f\n",medianas );
}
