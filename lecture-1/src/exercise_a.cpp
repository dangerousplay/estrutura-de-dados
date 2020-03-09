#include <cstdio>

int main(){
  int a, b, soma ;
  int *aptr, *bptr ;
  printf(" Digite um numero inteiro:");
  scanf("%d",&a );
  printf(" Digite um numero inteiro:");
  scanf("%d",&b );
  aptr = &a ;
  bptr = &b ;
  printf("\n Endereco de a (&a)= %d \n",&a);
  printf(" Endereco de a via ponteiro (aptr)= %d \n",aptr);
  printf(" Enderece do ponteiro aptr= %d \n",&aptr);
  printf("\n Endereco de b (&b)= %d \n",&b);
  printf(" Endereco de b via ponteiro (bptr)= %d \n",bptr);
  printf(" Endereco do ponteiro bptr= %d \n",&bptr);
  soma = a + b ;
  *aptr = soma ;
  printf("\n A soma de a + b via ponteiro (*aptr) eh: %d\n",*aptr);
  printf(" A soma de a + b que foi para variavel a eh: %d\n",a);
}
