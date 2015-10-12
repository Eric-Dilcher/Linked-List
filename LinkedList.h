#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "Node.h"
#include <stdexcept>

using namespace std;

template <class T>
class LinkedList{

private:

  Node<T> *head;

  Node<T> * getNodeAtPos(int position);

  T delete_node_after(Node<T> * n);

public:

  LinkedList();

  ~LinkedList();

  void prepend(T data);

  void append(T data);

  void addAtPos(T data, int position);

  T getAtPos(int position);

  T deleteAtPos(int position);

  void clearList();

  bool isEmpty();

};

//must include implementation in header file to allow for templates

template <class T>
LinkedList<T>::LinkedList(){
  head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList(){
  clearList();
}

template <class T>
Node<T> * LinkedList<T>::getNodeAtPos(int position){
  if(position < 0){
    throw(std::out_of_range("Position must be non-negative"));
  }
  Node<T> *temp = head;
  int counter = 0;
  while(temp != nullptr){
    if(counter == position){
      return temp;
    }
    temp = temp->next;
    counter++;
  }
  throw(std::out_of_range("Position is out of range"));
}

template <class T>
T LinkedList<T>::delete_node_after(Node<T> * n){
    Node<T> * temp = n->next;
    T to_return = temp->data;
    n->next = temp->next;
    delete temp;
    return to_return;
}

template <class T>
void LinkedList<T>::prepend(T data){
  Node<T> *new_head = new Node<T>(data, head);
  head = new_head;
}

template <class T>
void LinkedList<T>::append(T data){
  Node<T> *new_tail = new Node<T>(data, nullptr);
  Node<T> *temp = head;
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

template <class T>
void LinkedList<T>::addAtPos(T data, int position){
  if(position == 0){
    prepend(data);
  }
  else{
    Node<T> *before = getNodeAtPos(position - 1);
    Node<T> *after = before->next;
    before->next = new Node<T>(data, after);
  }
}

template <class T>
T LinkedList<T>::getAtPos(int position){
  return getNodeAtPos(position)->data;
}

template <class T>
T LinkedList<T>::deleteAtPos(int position){
  if(isEmpty()){
    throw(std::out_of_range("List is empty"));
  }
  else if(position == 0){
    Node<T> *temp = head;
    T to_return = temp->data;
    head = temp->next;
    delete temp;
    return to_return;
  }
  else{
    Node<T>  *before = getNodeAtPos(position - 1);
    T to_return = delete_node_after(before);
    return to_return;
  }
}

template <class T>
void LinkedList<T>::clearList(){
  if(isEmpty()){
  //  do nothing
  }
  else{
    Node<T> * temp = head;
    head = nullptr;
    Node<T>  * next = nullptr;

    while(temp != nullptr){
      next = temp->next;
      delete temp;
      temp = next;
    }

  }
}

template <class T>
bool LinkedList<T>::isEmpty(){
  return head == nullptr;
}



#endif // LINKEDLIST_H_INCLUDED
