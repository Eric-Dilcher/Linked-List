#include <iostream>
#include <stdexcept>

#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList(){
  head = nullptr;
}

LinkedList::~LinkedList(){
  clearList();
}

Node * LinkedList::getNodeAtPos(int position){
  if(position < 0){
    throw(out_of_range("Position must be non-negative"));
  }
  Node *temp = head;
  int counter = 0;
  while(temp != nullptr){
    if(counter == position){
      return temp;
    }
    temp = temp->next;
    counter++;
  }
  throw(out_of_range("Position is out of range"));
}


int LinkedList::delete_node_after(Node * n){
    Node * temp = n->next;
    int to_return = temp->data;
    n->next = temp->next;
    delete temp;
    return to_return;
}

void LinkedList::prepend(int data){
  Node *new_head = new Node(data, head);
  head = new_head;
}

void LinkedList::append(int data){
  Node *new_tail = new Node(data, nullptr);
  Node *temp = head;
  if(isEmpty()){
    head = new_tail;
  }
  else{
    while(temp->next != nullptr){
      temp = temp->next;
    }
    temp->next = new_tail;
  }
}

void LinkedList::addAtPos(int data, int position){
  if(position == 0){
    prepend(data);
  }
  else{
    Node *before = getNodeAtPos(position - 1);
    Node *after = before->next;
    before->next = new Node(data, after);
  }
}

int LinkedList::getAtPos(int position){
  return getNodeAtPos(position)->data;
}

int LinkedList::deleteAtPos(int position){
  if(isEmpty()){
    throw(out_of_range("List is empty"));
  }
  else if(position == 0){
    Node *temp = head;
    int to_return = temp->data;
    head = temp->next;
    delete temp;
    return to_return;
  }
  else{
    Node *before = getNodeAtPos(position - 1);
    int to_return = delete_node_after(before);
    return to_return;
  }
}

void LinkedList::clearList(){
  if(isEmpty()){
  //  do nothing
  }
  else{
    Node * temp = head;
    head = nullptr;
    Node * next = nullptr;

    while(temp != nullptr){
      next = temp->next;
      delete temp;
      temp = next;
    }

  }
}

bool LinkedList::isEmpty(){
  return head == nullptr;
}

string LinkedList::toString(){
  Node *temp = head;
  string returnString("");
  while(temp != nullptr){
    returnString += to_string(temp->data) + ",";
    temp = temp->next;
  }
  returnString.pop_back();
  return returnString;
}


