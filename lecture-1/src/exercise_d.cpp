#include <cstdio>

int main() {

  char campo, opcao;
  int num, cont;
  float valor, nota;
  double temp, taxa;

  printf("char campo = %p witch is of size %ld byte\n", &campo, sizeof(campo));
  printf("char opcao = %p witch is of size %ld byte\n", &opcao, sizeof(opcao));

  printf("int num = %p witch is of size %ld bytes\n", &num, sizeof(num));
  printf("int cont = %p witch is of size %ld bytes\n", &cont, sizeof(cont));

  printf("float valor = %p witch is of size %ld bytes\n", &valor, sizeof(valor));
  printf("float nota = %p witch is of size %ld bytes\n", &nota, sizeof(nota));

  printf("double temp = %p witch is of size %ld bytes\n", &temp, sizeof(temp));
  printf("double taxa = %p witch is of size %ld bytes\n", &taxa, sizeof(taxa));

}