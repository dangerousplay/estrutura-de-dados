//
// Created by davi on 04/04/2020.
//

#include "../Stack.h"

TEST_CASE("Stack", "[S]" ) {
  SECTION( "Push" ) {
    SECTION("Push on empty stack") {
      Stack s = Stack();

      int info = 10;

      s.push(info);

      Node* actual = s.peek();

      REQUIRE(actual != nullptr);
      REQUIRE(actual->next == nullptr);
      REQUIRE(actual->info == info);
      REQUIRE(s.length() == 1);
      REQUIRE_FALSE(s.is_empty());
    }

    SECTION("Push on non empty stack") {
      Stack s = Stack();

      int info = 10;
      int info2 = 20;

      s.push(info);
      s.push(info2);

      REQUIRE(s.length() == 2);
      REQUIRE_FALSE(s.is_empty());

      Node* actual = s.pop();

      REQUIRE(actual != nullptr);
      REQUIRE(actual->next != nullptr);
      REQUIRE(actual->info == info2);

      actual = s.pop();

      REQUIRE(actual != nullptr);
      REQUIRE(actual->next == nullptr);
      REQUIRE(actual->info == info);


      REQUIRE(s.length() == 0);
      REQUIRE(s.is_empty());
    }

  }

  SECTION("Pop") {
    SECTION("Pop on empty stack") {
      Stack s = Stack();

      Node* actual = s.pop();

      REQUIRE(actual == nullptr);
      REQUIRE(s.length() == 0);
      REQUIRE(s.is_empty());
    }

    SECTION("Pop on non empty stack") {
      Stack s = Stack();

      int info = 20;

      s.push(info);

      for(int i = 0; i < 10; i++) s.push(i);

      for(int i = 9; i >= 0; i--) {
        Node *actual = s.pop();

        REQUIRE(actual != nullptr);
        REQUIRE(actual->next != nullptr);
        REQUIRE(actual->info == i);
        REQUIRE(s.length() == i+1);
        REQUIRE_FALSE(s.is_empty());
      }

      Node* actual = s.pop();

      REQUIRE(actual != nullptr);
      REQUIRE(actual->next == nullptr);
      REQUIRE(actual->info == info);
      REQUIRE(s.length() == 0);
      REQUIRE(s.is_empty());
    }
  }

  SECTION("Length") {
    Stack s = Stack();

    int elements = 100;

    for(int i = 0; i < elements; i++) s.push(i);

    REQUIRE(s.length() == elements);
    REQUIRE_FALSE(s.is_empty());
  }

  SECTION("is_empty") {
    SECTION("is_empty on empty stack") {
      Stack s = Stack();

      REQUIRE(s.length() == 0);
      REQUIRE(s.is_empty());
    }

    SECTION("is_empty on non empty stack") {
      Stack s = Stack();

      int elements = 100;

      for(int i = 0; i < elements; i++) s.push(i);

      REQUIRE(s.length() == elements);
      REQUIRE_FALSE(s.is_empty());
    }

  }

  SECTION("peek") {
    SECTION("Peek on non empty stack") {
      Stack s = Stack();

      int elements = 100;

      for(int i = 0; i < elements; i++) s.push(i);

      Node* actual = s.peek();

      REQUIRE(actual != nullptr);
      REQUIRE(actual->info == elements-1);
      REQUIRE(actual->next != nullptr);

      REQUIRE(s.length() == elements);
      REQUIRE_FALSE(s.is_empty());
    }

    SECTION("Peek on empty stack") {
      Stack s = Stack();

      Node* actual = s.peek();

      REQUIRE(actual == nullptr);
      REQUIRE(s.length() == 0);
      REQUIRE(s.is_empty());
    }
  }

}

