#include <iostream>
#include <UnitTest++.h>
#include "LinkedList.h"

const float EPSILON = 0.0000001;

struct LinkedListSetup{
  LinkedList<float> * ll;
  LinkedListSetup(){
    ll = new LinkedList<float>();
    ll->append(1.1);
    ll->append(2.2);
    ll->append(3.3);
    ll->append(4.4);
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

TEST(TestAppend){
  LinkedList<float> ll;
  ll.append(1.1);
  CHECK_CLOSE(1.1, ll.getAtPos(0), EPSILON);
  ll.append(2.2);
  CHECK_CLOSE(2.2, ll.getAtPos(1), EPSILON);
}

TEST_FIXTURE(LinkedListSetup, TestGetAtPos){
  CHECK_CLOSE(1.1, ll->getAtPos(0), EPSILON);
  CHECK_CLOSE(2.2, ll->getAtPos(1), EPSILON);
  CHECK_CLOSE(3.3, ll->getAtPos(2), EPSILON);
}

TEST_FIXTURE(LinkedListSetup, TestPrepend){
  ll->prepend(0);
  CHECK_CLOSE(0,ll->getAtPos(0), EPSILON);
  ll->prepend(-1.1);
  CHECK_CLOSE(-1.1, ll->getAtPos(0), EPSILON);
}

TEST_FIXTURE(LinkedListSetup, TestAddAtPos){
  ll->addAtPos(0,0);
  CHECK_CLOSE(0,ll->getAtPos(0), EPSILON);
  ll->addAtPos(100, 3);
  CHECK_CLOSE(100, ll->getAtPos(3), EPSILON);
}

TEST_FIXTURE(LinkedListSetup, TestDeleteAtPos){
  CHECK_CLOSE(2.2, ll->deleteAtPos(1), EPSILON);
  CHECK_CLOSE(3.3, ll->deleteAtPos(1), EPSILON);
  CHECK_CLOSE(4.4, ll->deleteAtPos(1), EPSILON);
  CHECK_CLOSE(1.1, ll->deleteAtPos(0), EPSILON);
  CHECK(ll->isEmpty());
}
