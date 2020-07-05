/*
 * A figura abaixo descreve uma estrutura em árvore, o qual possui a representação de uma
universidade. Esta estrutura em árvore representa os departamentos contidos na instituição e as
pessoas atreladas a esses setores. A árvore possui uma Raiz (Sigla I), a qual não deve possuir
pessoas relacionadas em sua fila, e duas subárvores, uma a Esquerda e outra a Direita.

 A subárvore da Esquerda (Sigla D), possui apontamento para sua "fila de pessoas" e pode ter duas
subárvores (Ex: Siglas A e F ). É importante definir que a lista de pessoas de um departamento é
representada por uma fila.

O objetivo desse trabalho é implementar as funções necessárias para atender as opções exibidas na
tela principal do programa (utilize o código fornecido na sequência deste documento).

 Observação: A soma de um departamento inclui todos os funcionários desse departamento mais a
soma de todos os salários dos funcionários filhos deste departamento.
 * */

/**
 *  @authors Davi Henrique, Moisés Alcides
 */

#include <cstdio>
#include <cstdlib>
#include "main.h"
#include "draw.h"
#include <iostream>
#include <iomanip>

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




//Monta o menu do programa______________________________
void monta_menu() {
  printf("#################################################### \n");
  printf("Manutenção de Departamentos e Funcionários \n");
  printf("Selecione a Opção Desejada: \n");
  printf(" 1 - Incluir Departamento\n");
  printf(" 2 - Incluir funcionário no departamento informado\n");
  printf(" 3 - Apresentar total dos salários no departamento informado \n");
  printf(" 4 - Apresentar a média dos salários no departamento informado \n");
  printf(" 5 - Apresentar total de salários por departamento (todos departamentos)\n");
  printf(" 6 - Apresentar média dos salários por departamento (todos departamentos)\n");
  printf(" 7 - Verificar se o funcionário informado está em algum dos departamentos\n");
  printf(" 8 - Excluir o funcionário\n");
  printf(" 0 - Sair \n");
  printf("#################################################### \n");
  printf("Qual a sua opcao: ");
}


int main() { //__________________________________________
  int op = 1;

  nodo *departments = nullptr;

  do {
    monta_menu();

    fflush(stdin);

    scanf("%d", &op);

    system("cls");

    printf("Estutura dos departamentos: \n");

    draw_tree(departments, 1);

    printf("\n\n");

    switch (op) {
      case 1: {
        const auto sigla = scan_char("Digite a sigla do departamento: ");

        insere_nodo(&departments, sigla);

        break;
      }
      case 2: {
        const auto sigla = scan_char("Digite a sigla do departamento: ");

        const auto employee = scan_employee();

        const auto result = append_employee(departments, sigla, employee);

        if(!result) {
          printf("Departamento não encontrado: %c \n", sigla);
        } else {
          printf("Colaborador inserido com sucesso! \n");
        }

        break;
      }
      case 3: {
        const auto sigla = scan_char("Digite a sigla do departamento: ");

        auto department = find_department(departments, sigla);

        if(department == nullptr) {
          printf("Nenhum departamento encontrado com a sigla: %c \n", sigla);

          break;
        }

        auto nodes = visit_tree(&department);

        double sum = salary_sum(nodes);

        printf("A soma dos salários dos colaboradores deste departamento: %f \n", sum);

        break;
      }
      case 4: {
        const auto sigla = scan_char("Digite a sigla do departamento: ");

        auto department = find_department(departments, sigla);

        if(department == nullptr) {
          printf("Nenhum departamento encontrado com a sigla: %c \n", sigla);

          break;
        }

        auto nodes = visit_tree(&department);

        auto average = salary_average(nodes);

        printf("Média dos salários no departamento '%c': %f \n", sigla, average);

        break;
      }
      case 5: {
        //  printf(" 5 - Apresentar total de salários por departamento (todos departamentos)\n");

        auto nodes = visit_tree(&departments);

        for (auto node: nodes) {
          printf("Departamento '%c': \n\n", node->sigla);

          auto employees = to_vector(node->lista_funcionarios);

          auto children = visit_tree(&node);

          auto sum = salary_sum(children);

          printf("Soma dos salários deste departamento: %f \n", sum);

          for(auto employee: employees) {
            print_employee(employee);
          }
        }

        break;
      }
      case 6: {
        auto nodes = visit_tree(&departments);

        for (auto node: nodes) {
          printf("Departamento '%c': \n\n", node->sigla);

          auto employees = to_vector(node->lista_funcionarios);

          auto children = visit_tree(&node);

          auto average = salary_average(children);

          printf("Média dos salários: %f \n", average);
        }

        break;
      }
      case 7: {
        printf("Digite o nome do colaborador: ");

        auto name = (char*)calloc(20, sizeof(char));

        scanf("%s", name);

        auto nodes = visit_tree(&departments);

        auto found = false;

        for(auto node: nodes) {
          const auto employee = find_employee(node, name);

          if(employee != nullptr) {
            printf("Colaborador encontrado no departamento '%c', salário: '%f' \n", node->sigla, employee->salario);
            found = true;
          }
        }

        if(!found) {
          printf("Não encontrado colaborador com nome: %s \n", name);
        }

        break;
      }
      case 8: {
        printf("Digite o nome do colaborador: ");

        auto name = (char*)calloc(20, sizeof(char));

        scanf("%s", name);

        auto nodes = visit_tree(&departments);

        for(auto node: nodes) {
          const auto employee = remove_employee(node, name);

          if(employee != nullptr) {
            printf("Colaborador encontrado e removido do departamento '%c', salário: '%f' \n", node->sigla, employee->salario);
          }
        }

        break;
      }
    }
  } while (op != 0);
}