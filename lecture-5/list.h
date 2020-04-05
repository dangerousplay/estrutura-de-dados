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
  Node* tail;

public:
  List();

  void push_back(int info);
  void push_front(int info);
  bool insert(int index, int info);

  Node* get(int index);

  Node* inner_nodes() {
    return this->nodes;
  }

  Node *find(int info);

  Node* remove_first();
  Node* remove_last();

  bool is_empty();
  int length();

  ~List();

  Node *last();
} List;

#endif //EXERCISE_F_LIST_H
