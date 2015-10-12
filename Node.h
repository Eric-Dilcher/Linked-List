#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

struct Node{
  private:
    Node(){}

  public:
    int data;
    Node *next;

    Node(int d, Node *n){
      data = d;
      next = n;
    }
};

#endif // NODE_H_INCLUDED
