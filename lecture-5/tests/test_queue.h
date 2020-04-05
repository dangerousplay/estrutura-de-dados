//
// Created by davi on 04/04/2020.
//

#include <catch2/catch.hpp>
#include "../Queue.h"

TEST_CASE( "Queue", "[Q]" ) {

  SECTION("Enqueue") {
    SECTION("Enqueue on empty Queue") {
      Queue q = Queue();

      int info = 10;

      q.enqueue(info);

      Node* actual = q.peek();

      REQUIRE(actual != nullptr);
      REQUIRE(actual->info == info);

      REQUIRE(q.length() == 1);
      REQUIRE_FALSE(q.is_empty());
    }

    SECTION("Enqueue on non empty Queue") {
      Queue q = Queue();

      int elements = 100;

      for(int i = 0; i < elements; i++) {
        q.enqueue(i);

        Node* actual = q.peek();

        REQUIRE(actual != nullptr);
        REQUIRE(actual->info == i);
      }

      REQUIRE(q.length() == elements);
      REQUIRE_FALSE(q.is_empty());
    }
  }

  SECTION("Dequeue") {
    SECTION("Dequeue on empty Queue") {
      Queue q = Queue();

      Node* actual = q.dequeue();

      REQUIRE(actual == nullptr);

      REQUIRE(q.is_empty());
      REQUIRE(q.length() == 0);
    }

    SECTION("Dequeue on non empty Queue") {
      Queue q = Queue();

      int elements = 100;

      for(int i = 0; i < elements; i++) q.enqueue(i);

      REQUIRE(q.length() == elements);
      REQUIRE_FALSE(q.is_empty());

      for(int i = 0; i < elements; i++) {
        Node* actual = q.dequeue();

        REQUIRE(actual != nullptr);
        REQUIRE(actual->info == i);
      }

      REQUIRE(q.is_empty());
      REQUIRE(q.length() == 0);
    }
  }

  SECTION("Length") {
    Queue q = Queue();

    int elements = 100;

    for(int i = 0; i < elements; i++) q.enqueue(i);

    REQUIRE(q.length() == elements);
    REQUIRE_FALSE(q.is_empty());
  }

  SECTION("is_empty") {
    SECTION("is_empty on empty Queue") {
      Queue q = Queue();

      REQUIRE(q.length() == 0);
      REQUIRE(q.is_empty());
    }

    SECTION("is_empty on non empty Queue") {
      Queue q = Queue();

      int elements = 100;

      for(int i = 0; i < elements; i++) q.enqueue(i);

      REQUIRE(q.length() == elements);
      REQUIRE_FALSE(q.is_empty());
    }
  }

}
