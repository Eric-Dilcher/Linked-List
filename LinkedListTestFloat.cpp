#include <iostream>
#include <UnitTest++.h>
#include "LinkedList.h"

const float EPSILON = 0.0000001;

struct LinkedListSetup{
  LinkedList<float> * ll;
  LinkedListSetup(){
    ll = new LinkedList<float>();
    ll->addLast(1.1);
    ll->addLast(2.2);
    ll->addLast(3.3);
    ll->addLast(4.4);
  }
  ~LinkedListSetup(){
    delete ll;
  }
};

TEST(TestIsEmpty){
  LinkedList<float> ll;
  CHECK(ll.isEmpty());
}

TEST_FIXTURE(LinkedListSetup, TestClearList){
  CHECK_EQUAL(false, ll->isEmpty());
  ll->clearList();
  CHECK_EQUAL(true, ll->isEmpty());
}

TEST_FIXTURE(LinkedListSetup, TestGetAtPos){
  CHECK_CLOSE(1.1, ll->getAtPos(0), EPSILON);
  CHECK_CLOSE(2.2, ll->getAtPos(1), EPSILON);
  CHECK_CLOSE(3.3, ll->getAtPos(2), EPSILON);
}

TEST_FIXTURE(LinkedListSetup, TestAddFirst){
  ll->addFirst(0);
  CHECK_CLOSE(0,ll->getAtPos(0), EPSILON);
  ll->addFirst(-1.1);
  CHECK_CLOSE(-1.1, ll->getAtPos(0), EPSILON);
}

TEST(TestAddLast){
  LinkedList<float> ll;
  ll.addLast(1.1);
  CHECK_CLOSE(1.1, ll.getAtPos(0), EPSILON);
  ll.addLast(2.2);
  CHECK_CLOSE(2.2, ll.getAtPos(1), EPSILON);
}

TEST_FIXTURE(LinkedListSetup, TestAddAtPos){
  ll->addAtPos(0,0);
  CHECK_CLOSE(0,ll->getAtPos(0), EPSILON);
  ll->addAtPos(100, 3);
  CHECK_CLOSE(100, ll->getAtPos(3), EPSILON);
}

TEST_FIXTURE(LinkedListSetup, TestGetFirst){
  CHECK_CLOSE(1.1, ll->getFirst(), EPSILON);
}

TEST_FIXTURE(LinkedListSetup, TestGetLast){
  CHECK_CLOSE(4.4, ll->getLast(), EPSILON);
}

TEST_FIXTURE(LinkedListSetup, TestDeleteAtPos){
  CHECK_CLOSE(2.2, ll->deleteAtPos(1), EPSILON);
  CHECK_CLOSE(3.3, ll->deleteAtPos(1), EPSILON);
  CHECK_CLOSE(4.4, ll->deleteAtPos(1), EPSILON);
  CHECK_CLOSE(1.1, ll->deleteAtPos(0), EPSILON);
  CHECK(ll->isEmpty());
}

TEST_FIXTURE(LinkedListSetup, TestDeleteFirst){
  CHECK_CLOSE(1.1, ll->deleteFirst(), EPSILON);
  CHECK_EQUAL(3, ll->size());
}

TEST_FIXTURE(LinkedListSetup, TestDeleteLast){
  CHECK_CLOSE(4.4, ll->deleteLast(), EPSILON);
  CHECK_EQUAL(3, ll->size());
}

TEST_FIXTURE(LinkedListSetup, TestSize){
  CHECK_EQUAL(4, ll->size());
  ll->addFirst(0.1);
  CHECK_EQUAL(5, ll->size());
  ll->addAtPos(2.3, 2);
  CHECK_EQUAL(6, ll->size());
  ll->addLast(99.99);
  CHECK_EQUAL(7, ll->size());
  ll->deleteFirst();
  CHECK_EQUAL(6, ll->size());
  ll->deleteLast();
  CHECK_EQUAL(5, ll->size());
  ll->deleteAtPos(1);
  CHECK_EQUAL(4, ll->size());
}
