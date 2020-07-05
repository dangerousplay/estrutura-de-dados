#include<stdio.h>
#include<stdlib.h>

int main(){
  int size;

  printf("digite o tamanho do vetor");
  scanf("%d", &size);

  int* vector = vetorAlocado(size);
  return vector = 0? 1: 0;
}



int* vetorAlocado(int size){

  int* vector = (int*) malloc(sizeof(int) * size);
  if (vector== 0) {
    return 0;
  }

  for(int i=0 ; i<size; i++){

    if(0==(i&1)){
      vector[i] = 0;
    }
    else{
      vector[i] = ii;
    }
    printf("indice %d valor %d , i,vector[i]");
  }
  return vector;
}