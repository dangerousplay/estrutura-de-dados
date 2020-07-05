//
// Created by davi on 30/03/2020.
//

#ifndef EXERCISE_F_TEST_MAIN_CPP
#define EXERCISE_F_TEST_MAIN_CPP

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../main.h"
#include "../draw.h"

TEST_CASE( "Departments", "[DE]" ) {

  SECTION( "Find department" ) {

    SECTION( "No department exists" ) {
      nodo* departments = nullptr;

      REQUIRE( find_department(departments, 'A') == nullptr );
    }

    SECTION( "Existing departments but not informed" ) {
      nodo* departments = nullptr;

      insere_nodo(&departments, 'B');

      REQUIRE( find_department(departments, 'A') == nullptr );
    }

    SECTION( "Existing departments" ) {
      nodo* departments = nullptr;

      insere_nodo(&departments, 'B');
      insere_nodo(&departments, 'C');
      insere_nodo(&departments, 'D');
      insere_nodo(&departments, 'A');

      REQUIRE( find_department(departments, 'A') != nullptr );
    }

  }
  
  SECTION("Department append Employee") {
    
    SECTION("Append one") {
      nodo* departments = nullptr;
      char sigle = 'B';
      char* employee_name = "NAME";
      nodo *department = insere_nodo(&departments, sigle);

      No_Funcionario *employee = new_employee(employee_name, 150.0);

      bool result = append_employee(departments, sigle, employee);

      REQUIRE(result);

      No_Funcionario *actual = find_employee(department->lista_funcionarios, employee_name);

      REQUIRE(actual == employee);
      
    }

    SECTION("Append Multiples") {
      nodo* departments = nullptr;
      char sigle = 'B';
      char* employee_name = "NAME";
      char* employees_name = "NNN";
      int size = 10;

      nodo *department = insere_nodo(&departments, sigle);

      for(int i = 0; i < size; i ++) {
        No_Funcionario *employee = new_employee(employees_name, 150.0);

        bool result = append_employee(departments, sigle, employee);

        REQUIRE(result);
      }

      No_Funcionario *employee = new_employee(employee_name, 150.0);

      bool result = append_employee(departments, sigle, employee);

      REQUIRE(result);

      No_Funcionario *actual = find_employee(department->lista_funcionarios, employee_name);

      REQUIRE(actual == employee);

    }
    
  }

  SECTION("Department salaries sum") {

    SECTION("Department without employees") {
      nodo* departments = nullptr;

      insere_nodo(&departments, 'B');

      std::vector<nodo*> de = { departments };

      auto actual = salary_sum(de);

      REQUIRE(actual == 0.0);
    }

    SECTION("Department with employees") {
      nodo* departments = nullptr;
      char sigle = 'B';
      float salary = 151.0;

      insere_nodo(&departments, sigle);

      int size = 10;

      for(int i = 0; i < size; i++) {
        No_Funcionario *employee = new_employee("NAME1", salary);

        append_employee(departments, sigle, employee);
      }

      std::vector<nodo*> de = visit_tree(&departments);

      auto actual = salary_sum(de);

      REQUIRE(actual == salary * size);
    }

  }

  SECTION("Department salaries average") {

    SECTION("Department without employees") {
      nodo* departments = nullptr;

      insere_nodo(&departments, 'B');

      auto de = visit_tree(&departments);

      auto actual = salary_average(de);

      REQUIRE(actual == 0.0);
    }

    SECTION("Department with employees") {
      nodo* departments = nullptr;
      char sigle = 'B';
      float salary = 151.0;

      insere_nodo(&departments, sigle);

      int size = 10;

      for(int i = 0; i < size; i++) {
        No_Funcionario *employee = new_employee("NAME1", salary);

        append_employee(departments, sigle, employee);
      }

      auto de = visit_tree(&departments);

      auto actual = salary_average(de);

      REQUIRE(actual == salary);
    }

    SECTION("Multiple departments with employees") {
      nodo* departments = nullptr;
      char sigle = 'B';
      char sigle_second = 'A';
      float salary = 151.0;
      float second_salary = 100.0;

      insere_nodo(&departments, sigle);
      auto second = insere_nodo(&departments, sigle_second);

      int size = 10;

      for(int i = 0; i < size; i++) {
        No_Funcionario *employee = new_employee("NAME1", salary);
        No_Funcionario *second_employee = new_employee("NAME1", second_salary);

        append_employee(departments, sigle, employee);
        append_employee(departments, sigle_second, second_employee);
      }

      auto de = visit_tree(&departments);

      auto actual = salary_average(de);

      REQUIRE(actual == 125.5); // 1000 + 1510 / 20

      de = visit_tree(&second);

      actual = salary_average(de);

      REQUIRE(actual == second_salary);
    }

  }

  SECTION( "Queue" ) {
    
    SECTION("Append") {
      
      SECTION("Append one") {
        No_Funcionario *queue = nullptr;
        No_Funcionario *employee = new_employee("NAME", 150.0);
        
        push_back(&queue, employee);

        const No_Funcionario *actual = queue;
        
        REQUIRE( queue == employee);
        REQUIRE( actual->nome == employee->nome);
        REQUIRE( actual->salario == employee->salario);
      }

      SECTION("Append multiples") {
        No_Funcionario *queue = nullptr;
        No_Funcionario *employee = new_employee("NAME", 150.0);
        int size = 10;
        
        for(int i = 0; i < size; i++) {
          No_Funcionario *employee = new_employee("NAME1", 151.0);
          
          push_back(&queue, employee);
        }

        push_back(&queue, employee);

        No_Funcionario *actual = queue;

        for(int i = 0; i < size; i++) {
          actual = actual->prox;
        }

        REQUIRE( actual == employee);
        REQUIRE( actual->nome == employee->nome);
        REQUIRE( actual->salario == employee->salario);
      }
      
    }

    SECTION("Remove") {

      SECTION("Remove one") {
        No_Funcionario *queue = nullptr;
        No_Funcionario *employee = new_employee("NAME", 150.0);
        int size = 10;

        for(int i = 0; i < size; i++) {
          No_Funcionario *employee = new_employee("NAME1", 151.0);

          push_back(&queue, employee);
        }

        push_back(&queue, employee);

        auto actual = remove_employee(queue, employee->nome);

        REQUIRE( actual == employee );

        actual = find_employee(queue, employee->nome);

        REQUIRE( actual == nullptr );
      }

    }
    
  }

}

#endif //EXERCISE_F_TEST_MAIN_CPP
