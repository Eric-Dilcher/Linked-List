#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "Node.h"

using namespace std;

class LinkedList{

private:

  Node *head;

  Node * getNodeAtPos(int position);

  int delete_node_after(Node * n);

public:

  LinkedList();

  ~LinkedList();

  void prepend(int data);

  void append(int data);

  void addAtPos(int data, int position);

  int getAtPos(int position);

  int deleteAtPos(int position);

  void clearList();

  bool isEmpty();

  string toString();
};


#endif // LINKEDLIST_H_INCLUDED
