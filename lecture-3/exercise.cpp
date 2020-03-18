#include <cstdio>
#include <cstdlib>
#include <stdio.h>

#define DIM 30

#ifdef TARGET_OS_MAC
#define flush_stdin() fpurge(stdin);
#elif defined __linux__

#define flush_stdin() fflush(stdin);

#elif defined _WIN32 || defined _WIN64
#define flush_stdin() fflush(stdin);

#else
#error "unknown platform"
#endif

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  // pode haver outros campos
} REGISTRO;

typedef struct {
  REGISTRO A[DIM];
  int nroElem;
} LISTA;

//*********************************************************
void inicalizarLLS(LISTA * LLS){
  LLS->nroElem = 0;
}

//*********************************************************
int tamanhoLLS(LISTA * LLS){
  return LLS->nroElem;
}

//*********************************************************
void mostraLLS(LISTA * LLS){
  int i;
  printf("LISTA: < ");
  for (i=0; i< LLS->nroElem; i++){
    printf("%i, ", LLS->A[i].chave);
  }

  printf(" >\n Digite <enter> para voltar");
  getchar();

}

//*********************************************************
//retorna a posição do elemento na LLS
int buscaSequencialLLS(LISTA * LLS, TIPOCHAVE ch){
  int i = 0;
  while (i < LLS->nroElem){
    if(ch == LLS->A[i].chave)
      return i;
    else i++;
  }
  return -1;
}

//*********************************************************
int insereFimLLS(LISTA * LLS, REGISTRO valor){
  int i = 0;
  if(LLS->nroElem < DIM){
    LLS->A[LLS->nroElem] = valor;
    LLS->nroElem++;
    return 1;
  }
  return 0;
}

//*********************************************************
int inserirElemPosicaoLLS(LISTA* LLS, REGISTRO valor, int pos){
  int i;
  if ((LLS->nroElem == DIM) || (pos < 0) || (pos > LLS->nroElem))
    return 0;
  for (i = LLS->nroElem; i > pos; i--)
    LLS->A[i] = LLS->A[i-1];
  LLS->A[pos] = valor;
  LLS->nroElem++;
  return 1;
}

//*********************************************************
int excluirElemLLS(TIPOCHAVE ch, LISTA* LLS) {
  int pos, j;
  pos = buscaSequencialLLS(LLS,ch);
  if(pos == -1)
    return 0;
  for(j = pos; j < LLS->nroElem-1; j++)
    LLS->A[j] = LLS->A[j+1];
  LLS->nroElem--;
  return 1;
}

//*********************************************************
void reinicializarLLS(LISTA* LLS) {
  LLS->nroElem = 0;
}

//*********************************************************
int main(){
  int x = 0, opcao;

  LISTA LLS;
  inicalizarLLS(&LLS);

//incializar a lista
  REGISTRO valor;
  do {
    system("clear"); //no windows system("cls");
    printf("\nEntre com a opcao:\n");
    printf(" 1 - Mostrar toda LLS\n");
    printf(" 2 - Inserir nodo no fim\n");
    printf(" 3 - Inserir nodo na i-esima pos\n");
    printf(" 4 - Consultar posicao do valor\n");
    printf(" 5 - Remover valor\n");
    printf(" 6 - Zerar lista\n");
    printf(" 7 - Verificar tamanho lista\n");
    printf(" 8 - Sair\n");
    scanf("%d",&opcao);
    fflush(stdin);

    TIPOCHAVE chave;

    switch (opcao){
      case 1: mostraLLS(&LLS);
        break;
      case 2: {
        printf("Digite o valor para inserir:\n");
        scanf("%d", &valor);
        insereFimLLS(&LLS, valor);
        break;
      }

      case 3: {
        printf("Digite o valor para inserir: ");
        flush_stdin()

        scanf("%d", &valor);

        int posicao = -1;

        printf("Digite a posição: ");

        scanf("%d", &posicao);

        inserirElemPosicaoLLS(&LLS, valor, posicao);

        printf("Digite <enter> para voltar");
        getchar();
        break;
      }

      case 4: {
        printf("Digite a chave: ");
        flush_stdin()

        scanf("%d", &chave);

        int posicao = buscaSequencialLLS(&LLS, chave);

        if (posicao != -1) {
          printf("Valor encontrado na posição %d \n", posicao);
        } else {
          printf("Valor não encontrado pela chave: %d \n", chave);
        }

        printf("Digite <enter> para voltar");
        getchar();
        break;
      }

      case 5: {
        printf("Digite a chave: ");
        flush_stdin()


        scanf("%d", &chave);

        excluirElemLLS(chave, &LLS);

        printf("Digite <enter> para voltar");
        getchar();
        break;
      }
      case 6: reinicializarLLS(&LLS);
        break;
      case 7: {
        printf("A lista possui %d elementos\n", tamanhoLLS(&LLS));
        flush_stdin()

        printf("Digite <enter> para voltar");
        getchar();
        break;
      }

      case 8: {
        printf("\nSolicitou a opcao - sair!\n");
        exit(0);
      }

      default: printf("ATENCAO - Opcao invalida! Digite: \n");
    }
  } while(x == 0);
}