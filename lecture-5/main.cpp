#include <cstdio>
#include <cstdlib>

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

#include "list.h"

int scan_int(const char* message) {
  int value = 0;

  printf(message);

  scanf("%d", &value);

  return value;
}

int get_info() {
  return scan_int("Digite o valor do info: ");
}

int main() {
  int choice = 0;
  List* list = (List*) malloc(sizeof(List));

  do {
    printf("\nEntre com a opcao:\n");
    printf(" 1 - Exibir a lista\n");
    printf(" 2 - Inserir info no fim da lista\n");
    printf(" 3 - Consultar info\n");
    printf(" 4 - Remover info do inicio\n");
    printf(" 5 - Insere info no inicio da lista\n");
    printf(" 6 - Insere na posicao desejada\n");
    printf(" 7 - Sair\n");

    scanf("%d", &choice);

    fflush(stdin);

    switch (choice) {
      case 1: {
        print_elements(list);
        break;
      }

      case 2: {
        int info = get_info();

        list->push_back(info);
        break;
      }

      case 3: {
        int info = get_info();

        Node* found = list->find(info);

        if (found != nullptr) {
          printf("Encontrado info: %p\n", found);
        } else {
          printf("Info não encontrado pelo valor: %d\n", info);
        }

        break;
      }

      case 4: {
        printf("Removendo primeiro item da lista...\n");

        Node* removed = list->remove_first();

        if(removed != nullptr) {
          printf("Item removido da lista: %p\n", removed);
        } else {
          printf("Lista vazia, nenhum item foi removido\n");
        }
        break;
      }

      case 5: {
        int info = get_info();

        list->push_front(info);

        break;
      }

      case 6: {
        int info = get_info();
        int position = scan_int("Digite a posição: ");

        bool result = list->insert(info, position);

        if(!result) {
          printf("Posição inválida, não é possível inserir um elemento em: %d\n", position);
        }
        break;
      }

      case 7: exit(0);

      default: {
        printf("\tATENCAO - Opção invalida, tente novamente!: %d\n", choice);
      }
    }

  } while (true);
}
