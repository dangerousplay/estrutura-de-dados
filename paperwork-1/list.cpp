//
// Created by davi on 04/04/2020.
//
#include "list.h"

List::List() {
  this->size = 0;
  this->nodes = nullptr;
  this->tail = nullptr;
}

Node* alloc_node(int info) {
  Node* node = (Node*)calloc(1, sizeof(Node));

  node->info = info;


  return node;
}


void List::push_back(int info) {
  Node* next = alloc_node(info);

  if (this->tail != nullptr) {
    this->tail->next = next;
  }

  this->tail = next;
  this->size++;
  this->nodes = this->nodes == nullptr ? next : this->nodes;
}

void List::push_front(int info) {
  Node* next = alloc_node(info);

  next->next = this->nodes;
  this->tail = this->tail == nullptr ? next : this->tail;
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

  this->tail = this->nodes == nullptr ? this->nodes : this->tail;

  this->size--;

  return removed;
}

bool List::is_empty() {
  return this->size < 1;
}

List::~List() {
  for(Node* node = this->nodes; node != nullptr;) {
    Node* previous = node;
    node = node->next;

    free(previous);
  }

}

Node *List::remove_last() {
  if(this->is_empty()) return nullptr;

  if(this->length() == 1)
    return this->remove_first();

  Node* new_tail = this->get(this->length()-1);

  Node* removed = new_tail->next;

  new_tail->next = nullptr;
  this->tail = new_tail;

  return removed;
}

Node *List::last() {
  return this->tail;
}

void print_elements(List* list) {
  for(Node* node = list->inner_nodes(); node != nullptr; node = node->next) {
    printf("Node: %p Info: %d \n", node, node->info);
  }

  printf("\n");
  printf("Lista possuí tamanho: %d\n\n", list->length());
}
