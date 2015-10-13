#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "Node.h"
#include <stdexcept>

using namespace std;

template <class T>
class LinkedList{

private:

  int num_elements;

  Node<T> *head;

  Node<T> * getNodeAtPos(int position);

  T delete_node_after(Node<T> * n);

public:

  LinkedList();

  ~LinkedList();

  int size();

  void addFirst(T data);

  void addLast(T data);

  void addAtPos(T data, int position);

  T getFirst();

  T getLast();

  T getAtPos(int position);

  T deleteFirst();

  T deleteLast();

  T deleteAtPos(int position);

  void clearList();

  bool isEmpty();

};

//must include implementation in header file to allow for templates

template <class T>
LinkedList<T>::LinkedList(){
  head = nullptr;
  num_elements = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
  clearList();
}

template <class T>
int LinkedList<T>::size(){
  return num_elements;
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
  num_elements -=1;
  return to_return;
}

template <class T>
void LinkedList<T>::addFirst(T data){
  addAtPos(data, 0);
}

template <class T>
void LinkedList<T>::addLast(T data){
  addAtPos(data, size());
}

template <class T>
void LinkedList<T>::addAtPos(T data, int position){
  if(position == 0){
    Node<T> *new_head = new Node<T>(data, head);
    head = new_head;
  }
  else{
    Node<T> *before = getNodeAtPos(position - 1);
    Node<T> *after = before->next;
    before->next = new Node<T>(data, after);
  }
  num_elements += 1;
}

template <class T>
T LinkedList<T>::getFirst(){
  return getAtPos(0);
}

template <class T>
T LinkedList<T>::getLast(){
  return getAtPos(size() - 1);
}

template <class T>
T LinkedList<T>::getAtPos(int position){
  return getNodeAtPos(position)->data;
}

template <class T>
T LinkedList<T>::deleteFirst(){
  return deleteAtPos(0);
}

template <class T>
T LinkedList<T>::deleteLast(){
  return deleteAtPos(size() - 1);
}

template <class T>
T LinkedList<T>::deleteAtPos(int position){
  if(isEmpty()){
    throw(std::out_of_range("List is empty"));
  }
  else if(position == 0){
    num_elements -= 1;
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
    num_elements = 0;
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
