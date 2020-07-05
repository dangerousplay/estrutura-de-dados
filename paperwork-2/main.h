//
// Created by davi on 04/07/2020.
//

#ifndef EXERCISE_MAIN_H
#define EXERCISE_MAIN_H
#include <strings.h>

#include <functional>
#include <numeric>
#include <algorithm>
#include <iostream>


//Definição da lista de produtos_______________________
typedef struct No_Funcionario {
  char* nome;
  float salario;
  struct No_Funcionario *prox;
} No_Funcionario;

//Definição da árvore__________________________________
typedef struct nodo {
  struct No_Funcionario *lista_funcionarios;
  struct nodo *esq;
  char sigla;
  struct nodo *dir;
} nodo;


//Criação de um nodo da árvore__________________________
nodo *cria_elemento(char sigla) {
  nodo *novo = static_cast<nodo *>(malloc(sizeof(nodo)));
  novo->sigla = sigla;
  novo->esq = nullptr;
  novo->dir = nullptr;
  novo->lista_funcionarios = nullptr;
  return novo;
}

nodo* new_department_queue(char sigla) {
  return cria_elemento(sigla);
}

//Inclusão de um nodo na árvore_________________________
nodo* insere_nodo(nodo **arv, char sigla) {
  if (*arv == nullptr) {
    *arv = cria_elemento(sigla);
    return *arv;
  } else {
    if (sigla < (*arv)->sigla) {
      printf("Inserindo na Esquerda. \n");
      return insere_nodo(&(*arv)->esq, sigla);
    } else if (sigla > (*arv)->sigla) {
      printf("Inserindo na Direita. \n");
      return insere_nodo(&(*arv)->dir, sigla);
    }
  }

  return nullptr;
}

std::vector<nodo*> visit_tree(nodo** tree) {
  std::vector<nodo*> nodes;

  if(*tree == nullptr) return nodes;

  std::vector<nodo*> nexts;

  nexts.push_back(*tree);

  while(!nexts.empty()) {
    auto next = nexts[0];

    nexts.erase(nexts.begin());

    nodes.push_back(next);

    if(next->dir != nullptr)
      nexts.push_back(next->dir);

    if(next->esq != nullptr)
      nexts.push_back(next->esq);
  }

  return nodes;
}

nodo* find_tree(nodo** tree, const std::function<bool(nodo*)>& predicate) {
  auto nodes = visit_tree(tree);
  auto values = std::find_if(nodes.begin(), nodes.end(), predicate);

  return values.base() != nullptr ? *values : nullptr;
}


nodo* find_department(nodo* root, char sigle) {
  return find_tree(&root, [sigle](nodo* department) {
    return department->sigla == sigle;
  });
}

No_Funcionario* find_employee(No_Funcionario* queue, const std::function<bool(No_Funcionario*)>& predicate) {
  if(queue == nullptr) return nullptr;

  auto next = queue;

  for(next; next != nullptr; next = next->prox) {
    if(predicate(next)) {
      return next;
    }
  }

  return nullptr;
}

void push_back(No_Funcionario** queue, No_Funcionario* employee) {
  if (*queue == nullptr) {
    *queue = employee;

    return;
  }

  for(No_Funcionario* next = *queue; ; (next = next->prox)) {
    if(next->prox == nullptr) {
      next->prox = employee;

      break;
    }
  }

}

bool append_employee(nodo* root, char sigle, No_Funcionario* employee) {
  nodo *department = find_department(root, sigle);

  if(department == nullptr) return false;

  No_Funcionario *queue = department->lista_funcionarios;

  push_back(&queue, employee);

  department->lista_funcionarios = queue;

  return true;
}

No_Funcionario* find_employee(No_Funcionario* queue, char* name) {
  if(queue == nullptr) return nullptr;

  for(No_Funcionario * next = queue; next != nullptr; next = next->prox) {
    if(!strcasecmp(next->nome, name)) {
      return next;
    }
  }

  return nullptr;
}

No_Funcionario* find_employee(nodo* root, char* name) {
  if(root == nullptr) return nullptr;

  return find_employee(root->lista_funcionarios, name);
}

No_Funcionario* new_employee(char* name, float salary) {
  auto* employee = (No_Funcionario*)calloc(1, sizeof(No_Funcionario));
  employee->nome = name;
  employee->salario = salary;

  return employee;
}


No_Funcionario* remove_employee(No_Funcionario* queue, const std::function<bool(No_Funcionario*)>& predicate) {
  if(queue == nullptr) return nullptr;

  auto previous = queue;

  for(No_Funcionario* next = queue; next != nullptr; next = next->prox) {
    if(predicate(next)) {
      previous->prox = next->prox ? next->prox : nullptr;

      return next;
    }

    previous = next;
  }

  return nullptr;
}

No_Funcionario* remove_employee(No_Funcionario* queue, const char* name) {
  return remove_employee(queue, [name](No_Funcionario* employee) {
    return !strcasecmp(employee->nome, name);
  });
}

No_Funcionario* remove_employee(nodo* tree, const char* name) {
  if(tree->lista_funcionarios == nullptr) return nullptr;

  return remove_employee(tree->lista_funcionarios, name);
}

std::vector<No_Funcionario*> to_vector(No_Funcionario* employees) {
  std::vector<No_Funcionario*> vector;

  if(employees == nullptr) return vector;

  for(No_Funcionario * next = employees; next != nullptr; next = next->prox) {
    vector.push_back(next);
  }

  return vector;
}

double salary_sum(std::vector<nodo*> departments) {
  return std::accumulate(departments.begin(), departments.end(), 0, [](float initial, nodo* department) {
    auto left = to_vector(department->lista_funcionarios);
    std::vector<float> salaries(left.size());

    std::transform(left.begin(), left.end(), salaries.begin(), [](No_Funcionario* employee) { return employee->salario; });

    return initial + std::accumulate(salaries.begin(), salaries.end(), 0.0);
  });
}

double salary_average(std::vector<nodo*> departments) {
  std::vector<No_Funcionario*> employees;
  std::vector<float> salaries(employees.size());

  std::for_each(departments.begin(), departments.end(), [&employees](nodo* department) {
    std::vector<No_Funcionario*> empty;

    auto left = to_vector(department->lista_funcionarios);

    employees.insert(employees.end(), left.begin(), left.end());
  });

  for(auto employee: employees) {
    salaries.push_back(employee->salario);
  }

  auto average = std::accumulate(salaries.begin(), salaries.end(), 0.0) / salaries.size();

  return salaries.empty() ? 0.0 : average;
}

std::string to_string(No_Funcionario* employees) {
  auto collected = to_vector(employees);
  std::string result = "";

  result += std::accumulate(collected.begin(), collected.end(), result, [](std::string a, No_Funcionario* b) {
    return a + ", " + b->nome;
  });

  result += "]";

  return result;
}

void print_employee(No_Funcionario* employee) {
  if(employee == nullptr) return;

  printf("Colaborador '%s' \n", employee->nome);
  printf("Salário: %f \n", employee->salario);
}

int scan_int(const char *message) {
  int value = 0;

  std::cout << message;

  fflush(stdin);

  std::cin >> value;

  return value;
}

char scan_char(const char *message) {
  char value = 0;

  std::cout << message;

  fflush(stdin);
  fflush(stdout);

  std::cin >> value;

  return value;
}

No_Funcionario* scan_employee() {
  char* name = (char*)calloc(20, sizeof(char));

  printf("Digite o nome do colaborador: ");

  scanf("%s", name);

  printf("Digite o salário: ");

  float salary = 0.0;

  std::cin >> salary;

  return new_employee(name, salary);
}

#endif //EXERCISE_MAIN_H
