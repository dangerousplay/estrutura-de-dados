//
// Created by davi on 30/03/2020.
//
#include <cstdlib>
#include <cstdio>

#ifndef EXERCISE_F_LIST_H
#define EXERCISE_F_LIST_H

typedef struct Node {
  Node* next;
  int info;
} Node;

typedef struct List {
  int size;
  Node* nodes;

public:
  List();

  void push_back(int info);
  void push_front(int info);
  bool insert(int index, int info);

  Node* get(int index);

  int length();


  Node *find(int info);

  Node* remove_first();
} List;

List::List() {
  this->size = 0;
  this->nodes = nullptr;
}

Node* alloc_node(int info) {
  Node* node = (Node*)calloc(1, sizeof(Node));

  node->info = info;


  return node;
}


void List::push_back(int info) {
  Node* next = alloc_node(info);

  Node* tail = this->nodes;

  if (tail == nullptr) {
    this->nodes = next;

    goto increment;
  }

  while (tail->next != nullptr) {
    tail = tail->next;
  }

  tail->next = next;

  increment:
  this->size++;
}

void List::push_front(int info) {
  Node* next = alloc_node(info);

  next->next = this->nodes;

  this->nodes = next;
  this->size++;
}

int List::length() {
  return this->size;
}

Node *List::get(int index) {
  int i = 0;

  for(Node* node = this->nodes; node != nullptr; node = node->next, i++) {
    if (i == index) {
      return node;
    }
  }

  return nullptr;
}

bool List::insert(int index, int info) {
  if(this->size > 0 && this->size-1 < index) return false;
  if(index < 0) return false;

  if(index == 0) {
    this->push_front(info);

    return true;
  }

  if(index == (this->size)-1) {
    this->push_back(info);

    return true;
  }

  Node* target = this->get(index-1);

  Node* node = alloc_node(info);
  Node* next_node = target->next;

  target->next = node;
  node->next = next_node;
  this->size++;

  return true;
}

Node *List::find(int info) {
  int i = 0;

  for(Node* node = this->nodes; node != nullptr; node = node->next, i++) {
    if (node->info == info) {
      return node;
    }
  }

  return nullptr;
}

Node* List::remove_first() {
  if (this->nodes == nullptr) return nullptr;

  Node* removed = this->nodes;

  this->nodes = this->nodes->next;
  this->size--;

  return removed;
}


void print_elements(List* list) {
  for(Node* node = list->nodes; node != nullptr; node = node->next) {
    printf("Node: %p Info: %d \n", node, node->info);
  }

  printf("\n");
  printf("Lista possuí tamanho: %d\n\n", list->length());
}

Node* get(List* list, int index) {
  int i = 0;

  for(Node* node = list->nodes; node != nullptr; node = node->next, i++) {
    if (i == index) {
      return node;
    }
  }

  return nullptr;
}

void free_list(List* list) {
  for(Node* node = list->nodes; node != nullptr; node = node->next) {
    free(node);
  }
}

#endif //EXERCISE_F_LIST_H
