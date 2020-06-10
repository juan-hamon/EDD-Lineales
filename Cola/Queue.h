#ifndef __QUEUE__H__
#define __QUEUE__H__
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
class Queue{
  protected:
    Node<T>* start;
    Node<T>* end;
    int sizeQueue;
  public:
    //Constructores
    Queue();
    Queue(T data);
    //Destructor
    ~Queue();
    //Métodos
    void push(T data);
    void pop();
    T front();
    T back();
    int size();
    bool isEmpty();

};

#include "Queue.hxx"
#endif // __QUEUE__H__
