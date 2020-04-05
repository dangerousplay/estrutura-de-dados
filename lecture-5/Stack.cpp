//
// Created by davi on 04/04/2020.
//

#include "Stack.h"

Stack::Stack() {
  this->inner = List();
}

int Stack::length() {
  return this->inner.length();
}

Node *Stack::pop() {
  return this->inner.remove_first();
}

void Stack::push(int info) {
  this->inner.push_front(info);
}

Node *Stack::peek() {
  return this->inner.get(0);
}

bool Stack::is_empty() {
  return this->inner.is_empty();
}
