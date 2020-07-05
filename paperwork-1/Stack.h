//
// Created by davi on 04/04/2020.
//

#ifndef EXERCISE_F_STACK_H
#define EXERCISE_F_STACK_H

#include "list.h"

class Stack {
private:
  List inner;

public:
  Stack();

  Node* pop();
  void push(int info);
  Node* peek();

  bool is_empty();
  int length();
};


#endif //EXERCISE_F_STACK_H
