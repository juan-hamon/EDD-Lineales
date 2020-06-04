#ifndef __LIST__H__
#define __LIST__H__
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
class List{
  protected:
    Node<T>* start;
    int listSize;
  public:
    //Constructores
    List();
    List(T data);
    //Destructor
    ~List();
    //Métodos
    void push_back(T data);
    void push_front(T data);
    void insert(T data, int position);
    void pop_back();
    void pop_front();
    void erase(int position);
    void print_list();
    int size();
    bool isEmpty();
    void clear();
    
};

#include "List.hxx"
#endif // __LIST__H__
