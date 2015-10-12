#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <class T>
struct Node{
  private:
    Node(){}

  public:
    T data;
    Node *next;

    Node(T d, Node *n){
      data = d;
      next = n;
    }
};

#endif // NODE_H_INCLUDED
