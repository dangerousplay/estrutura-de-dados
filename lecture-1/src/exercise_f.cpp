//
// Created by davi on 08/03/2020.
//

/*
Faça uma função que aloque um vetor de n posições. O tamanho do vetor é passado por parâmetro. Após
criar o vetor, a função deve preencher este vetor (nos índices pares com 0, nos índices ímpares com o valor
quadrado do índice), imprimindo os mesmos na tela. A função deve retornar 1 se conseguiu alocar o vetor, e
0 em caso contrário.
*/

#include <cstdio>
#include <cstdlib>

int* alloc_vector(int size) {
  int* vector = (int*) malloc(sizeof(int) * size);

  if (vector == NULL) {
    return NULL;
  }

  for(int i = 0; i < size; i++) {
    if (0 == (i & 1)) {
      vector[i] = 0;
    } else {
      vector[i] = i*i;
    }

    printf("Index: %d, Value: %d \n", i, vector[i]);
  }

  return vector;
}

int main() {
  int size = 0;

  printf("Digite o número de posições do vetor: ");
  scanf("%d", &size);

  int* vector = alloc_vector(size);

  return vector == NULL ? 1 : 0;
}



