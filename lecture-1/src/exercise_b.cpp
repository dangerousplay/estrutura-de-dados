#include <cstdio>

int main(){
  int a=2, b=3, c=4;
  int v[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90 } ;
  int *pt1, *pt2, *pt3, *vaux ;
  pt1 = &a ; // pt1 recebe o endereco de a
  pt2 = &b ; // pt2 recebe o endereco de b
  pt3 = &c ; // pt3 recebe o endereco de c
  printf("Endereco da var a: %d\n", &a);
  printf("O valor de pt1 eh: %d\n", pt1);
  *pt1 = *pt1 + *pt2 + *pt3 ;
  printf("O valor da variavel apontada por pt1 (imprime com a) eh: %d\n", a);
  printf("O valor da var apontada por pt1 (imprime com *pt1) eh: %d\n",*pt1);
}

