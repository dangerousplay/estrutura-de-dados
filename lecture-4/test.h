#include <catch2/catch.hpp>
#include "list.h"

TEST_CASE( "Linear Linked List", "[LLE]" ) {

  SECTION( "Pushing front" ) {

    SECTION( "Pushing an element on empty list") {
      List list = List();

      int info = 10;

      list.push_front(info);

      Node* actual_node = get(&list, 0);

      REQUIRE( list.size == 1 );
      REQUIRE( list.nodes == actual_node );

      REQUIRE( actual_node != nullptr );
      REQUIRE( actual_node->next == nullptr );
      REQUIRE( actual_node->info == info );
    }

    SECTION( "Pushing an element on non empty list" ) {
      List list = List();

      int info = 10;

      list.push_front(info);

      REQUIRE( list.size == 1 );
      REQUIRE( list.nodes != nullptr );

      Node* actual_node = get(&list, 0);

      REQUIRE( actual_node != nullptr );
      REQUIRE( actual_node->info == info );
      REQUIRE( actual_node->next == nullptr );

      info = 4;

      list.push_front(info);

      REQUIRE( list.size == 2 );
      REQUIRE( list.nodes != nullptr );

      Node* last_node = actual_node;

      actual_node = get(&list, 0);

      REQUIRE( actual_node != nullptr );
      REQUIRE( actual_node->info == info );
      REQUIRE( actual_node->next == last_node );
    }

  }

  SECTION( "Pushing back" ) {

    SECTION( "Pushing an element on empty list" ) {
      List list = List();

      int info = 10;

      list.push_back(info);

      Node* actual_node = get(&list, 0);

      REQUIRE( list.size == 1 );
      REQUIRE( list.nodes == actual_node );

      REQUIRE( actual_node != nullptr );
      REQUIRE( actual_node->next == nullptr );
      REQUIRE( actual_node->info == info );
    }

    SECTION( "Pushing an element on non empty list" ) {
      List list = List();

      int info = 10;

      list.push_back(info);

      REQUIRE( list.size == 1 );
      REQUIRE( list.nodes != nullptr );

      Node* actual_node = list.get(0);

      REQUIRE( actual_node != nullptr );
      REQUIRE( actual_node->info == info );
      REQUIRE( actual_node->next == nullptr );

      info = 4;

      list.push_back(info);

      REQUIRE( list.size == 2 );
      REQUIRE( list.nodes != nullptr );

      Node* last_node = actual_node;

      actual_node = get(&list, 1);

      REQUIRE( actual_node != nullptr );
      REQUIRE( actual_node->info == info );
      REQUIRE( actual_node->next == nullptr );
      REQUIRE( last_node->next == actual_node );
    }
  }

  SECTION( "Insert on index" ) {
    SECTION( "Insert first element on empty list" ) {
      List list = List();

      int info = 10;

      list.insert(0,info);

      Node* actual = list.get(0);

      REQUIRE( actual->info == info );
      REQUIRE( actual->next == nullptr );
      REQUIRE( list.length() == 1 );
    }

    SECTION( "Insert first element on non empty list" ) {
      List list = List();

      int info = 10;
      int info2 = 20;

      list.push_back(info);

      list.insert(0, info2);

      Node* actual = list.get(0);

      REQUIRE( actual->next != nullptr );

      Node* actual_next = actual->next;

      REQUIRE( actual->info == info2 );
      REQUIRE( actual->next == actual_next );

      REQUIRE( actual_next->info == info );
      REQUIRE( actual_next->next == nullptr );

      REQUIRE( list.length() == 2 );
    }

    SECTION( "Insert on middle an element" ) {
      List list = List();

      int info = 20;

      for(int i = 0; i < 10; i++) list.push_front(i);

      bool actual_return = list.insert(3, info);

      REQUIRE(actual_return);

      Node* actual = list.get(3);

      REQUIRE( actual->next == list.get(4) );
      REQUIRE( actual->info == info );
      REQUIRE( list.length() == 11 );
    }

    SECTION( "Insert last element on non empty list" ) {
      List list = List();

      int info = 20;

      for(int i = 0; i < 10; i++) list.push_front(i);

      bool actual_return = list.insert(9, info);

      REQUIRE(actual_return);

      Node* actual = list.get(10);

      REQUIRE( actual->next == nullptr );
      REQUIRE( actual->info == info );
      REQUIRE( list.length() == 11 );
    }
  }

  SECTION( "Remove item" ) {
    SECTION( "Remove item from empty list" ) {
      List list = List();

      Node* actual = list.remove_first();

      REQUIRE( actual == nullptr );
      REQUIRE( list.length() == 0 );
    }

    SECTION( "Remove item from non empty list" ) {
      List list = List();

      for(int i = 0; i < 10; i++) list.push_front(i);

      Node* first = list.get(0);

      Node* actual = list.remove_first();

      REQUIRE( actual == first );
      REQUIRE( actual->info == first->info );
      REQUIRE( list.length() == 9 );
    }
  }
}