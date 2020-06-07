#include "Stack.h"

/*
  Nombre función: Stack
  Descripción: Crea una pila vacía.
  Parámetros: Ninguno.
  Retorna: Nada.
*/
template <class T>
Stack<T>::Stack(){
  
  this->top = nullptr;
  this->stackSize = 0;
  
}

/*
  Nombre función: Stack
  Descripción: Crea una pila con el elemento enviado por parámetro.
  Parámetros: Elemento a insertar en la pila.
  Retorna: Nada.
*/
template <class T>
Stack<T>::Stack(T data){
  
  this->top = new Node<T>(data);
  this->stackSize = 1;
  
}

/*
  Nombre función: ~Stack
  Descripción: Elimina cada uno de los elementos en la pila.
  Parámetros: Ninguno.
  Retorna: Nada.
*/
template <class T>
Stack<T>::~Stack(){
  
  Node<T>* aux = this->top;
  while(aux != nullptr){
    this->top = this->top->next;
    delete(aux);
    aux = this->top;
  }
  this->stackSize = 0;
  
}

/*
  Nombre función: push
  Descripción: Inserta un elemento en la pila.
  Parámetros: Elemento a insertar.
  Retorna: Nada.
*/
template <class T>
void Stack<T>::push(T data){
  
  Node<T>* aux = new Node<T>(data);
  aux->next = this->top;
  this->top = aux;
  this->stackSize++;
  
}

/*
  Nombre función: pop
  Descripción: Elimina el elemento que está en el tope de la pila.
  Parámetros: Ninguno.
  Excepciones:
    *Si la pila está vacía no se puede eliminar nada.
  Retorna: Nada.
*/
template <class T>
void Stack<T>::pop(){
  
  if( this->isEmpty() ){
    std::cout<<"The stack has no data"<<std::endl;
  }else{
    Node<T>* aux = this->top;
    this->top = this->top->next;
    delete(aux);
    this->stackSize--;
  }
  
}

/*
  Nombre función: getTop
  Descripción: Retorna el dato que se encuentra en el tope de la pila.
  Parámetros: Ninguno.
  Excepciones: 
    *Si la pila está vacía se genera error por intentar acceder a un nullptr.
  Retorna: Dato que se encuentra en el tope.
*/
template <class T>
T Stack<T>::getTop(){
  
  return this->top->data;
  
}

/*
  Nombre función: size
  Descripción: Calcula el tamaño de la pila.
  Parámetros: Ninguno.
  Retorna: Tamaño del la pila.
*/
template <class T>
int Stack<T>::size(){
  
  return this->stackSize;
  
}

/*
  Nombre función: isEmpty
  Descripción: Determina si la pila está vacía.
  Parámetros: Ninguno.
  Retorna:
    *TRUE si el tope de la pila es nulo.
    *FALSE si el tope de la pila no es nulo.
*/
template <class T>
bool Stack<T>::isEmpty(){
  
  return this->top == nullptr;
  
}
