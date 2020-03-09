#include <cstdio>

int main(){
  int i, *vaux ;
  int v[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90 } ;

  vaux = &v[0]; //vaux recebe o endereco de v[0]
  printf("O endereco de v[0] eh (imprime com &v[0]): %d\n", &v[0]);
  printf("O endereco de v[0] eh (imprime com vaux) : %d\n", vaux);
  printf("O valor da variavel apontada por vaux (v[0]) eh: %d\n",*vaux );
  printf("Laco for:\n");

  for (i=0; i<10; i++){
    *vaux = *vaux + 10 ;
    printf("Valor de v[%d](*vaux)= %d e (v[%d])= %d\n",i,*vaux,i,v[i]);
    vaux = vaux + 1 ;
  }

}