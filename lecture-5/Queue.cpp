//
// Created by davi on 04/04/2020.
//

#include "Queue.h"

Queue::Queue() {
  this->inner = List();
}

Node* Queue::peek() {
  return this->inner.last();
}

void Queue::enqueue(int info) {
  this->inner.push_back(info);
}

Node* Queue::dequeue() {
  return this->inner.remove_first();
}

bool Queue::is_empty() {
  return this->inner.is_empty();
}

int Queue::length() {
  return this->inner.length();
}
