#ifndef __STACK__H__
#define __STACK__H__
#include <iostream>

template <class T>
struct Node{
  T data;
  struct Node *next;
  
  Node(T dat){
    data = dat;
    next = nullptr;
  }
};

template <class T>
class Stack{
  protected:
    Node<T>* top;
    int stackSize;
  public:
    //Constructores
    Stack();
    Stack(T data);
    //Destructor
    ~Stack();
    //Métodos
    void push(T data);
    void pop();
    T getTop();
    int size();
    bool isEmpty();
};

#include "Stack.hxx"
#endif // __STACK__H__
