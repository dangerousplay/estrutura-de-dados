//
// Created by davi on 05/07/2020.
//

#ifndef EXERCISE_DRAW_H
#define EXERCISE_DRAW_H

#include "main.h"
#include <iostream>
#include <iomanip>

void draw_tree(nodo* tree, int indent)
{
  if(tree != NULL) {
    if(tree->esq) {
      draw_tree(tree->esq, indent+4);
    }

    if (indent) {
      std::cout << std::setw(indent) << ' ';
    }

    if (tree->esq) {
      std::cout << " /\n" << std::setw(indent) << ' ';
    }

    std::cout << tree->sigla;

    if(tree->lista_funcionarios != nullptr) {
      std::cout << " Colaboradores: " << to_string(tree->lista_funcionarios);
    }

    std::cout << "\n ";

    if(tree->dir) {
      std::cout << std::setw(indent) << ' ' <<" \\\n";
      draw_tree(tree->dir, indent+4);
    }
  }
}


#endif //EXERCISE_DRAW_H
