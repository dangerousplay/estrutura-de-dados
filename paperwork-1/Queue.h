//
// Created by davi on 04/04/2020.
//

#ifndef EXERCISE_F_QUEUE_H
#define EXERCISE_F_QUEUE_H

#include "list.h"

class Queue {
private:
  List inner;

public:
  Queue();

  void  enqueue(int info);
  Node* dequeue();
  Node* peek();

  bool is_empty();
  int length();
};


#endif //EXERCISE_F_QUEUE_H
