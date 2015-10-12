#include <iostream>
#include <UnitTest++.h>
#include "LinkedList.h"

using namespace std;


struct LinkedListSetup{
  LinkedList * ll;
  LinkedListSetup(){
    ll = new LinkedList();
    ll->append(1);
    ll->append(2);
    ll->append(3);
    ll->append(4);
  }
  ~LinkedListSetup(){
    delete ll;
  }
};

TEST(TestIsEmpty){
  LinkedList ll;
  CHECK(ll.isEmpty());
}

TEST_FIXTURE(LinkedListSetup, TestClearList){
  CHECK_EQUAL(false, ll->isEmpty());
  ll->clearList();
  CHECK_EQUAL(true, ll->isEmpty());
}

TEST(TestAppend){
  LinkedList ll;
  ll.append(1);
  CHECK_EQUAL(1, ll.getAtPos(0));
  ll.append(2);
  CHECK_EQUAL(2, ll.getAtPos(1));
}

TEST_FIXTURE(LinkedListSetup, TestGetAtPos){
  CHECK_EQUAL(1, ll->getAtPos(0));
  CHECK_EQUAL(2, ll->getAtPos(1));
  CHECK_EQUAL(3, ll->getAtPos(2));
}

TEST_FIXTURE(LinkedListSetup, TestPrepend){
  ll->prepend(0);
  CHECK_EQUAL(0,ll->getAtPos(0));
  ll->prepend(-1);
  CHECK_EQUAL(-1, ll->getAtPos(0));
}

TEST_FIXTURE(LinkedListSetup, TestAddAtPos){
  ll->addAtPos(0,0);
  CHECK_EQUAL(0,ll->getAtPos(0));
  ll->addAtPos(100, 3);
  CHECK_EQUAL(100, ll->getAtPos(3));
}

TEST_FIXTURE(LinkedListSetup, TestToString){
  CHECK(ll->toString().compare("1,2,3,4")==0);
}

TEST_FIXTURE(LinkedListSetup, TestDeleteAtPos){
  CHECK_EQUAL(2, ll->deleteAtPos(1));
  CHECK_EQUAL(3, ll->deleteAtPos(1));
  CHECK_EQUAL(4, ll->deleteAtPos(1));
  CHECK_EQUAL(1, ll->deleteAtPos(0));
  CHECK(ll->isEmpty());
}
