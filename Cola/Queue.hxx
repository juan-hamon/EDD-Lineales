#include "Queue.h"

/*
  Nombre función: Queue
  Descripción: Crea una cola vacía.
  Parámetros: Ninguno.
  Retorna: Nada.
*/
template <class T>
Queue<T>::Queue(){

  this->start = nullptr;
  this->end = nullptr;
  this->sizeQueue = 0;

}

/*
  Nombre función: Queue
  Descripción: Crea una cola con el elemento enviado por parámetro.
  Parámetros: Elemento a insertar en la cola.
  Retorna: Nada.
*/
template <class T>
Queue<T>::Queue(T data){

  this->start = new Node<T>(data);
  this->end = this->start;
  this->sizeQueue = 1;

}

/*
  Nombre función: ~Queue
  Descripción: Elimina cada uno de los elementos en la cola.
  Parámetros: Ninguno.
  Retorna: Nada.
*/
template <class T>
Queue<T>::~Queue(){

  Node<T>* aux = this->start;
  while(aux != nullptr){
    this->start = this->start->next;
    delete(aux);
    aux = this->start;
  }
  this->sizeQueue = 0;

}


/*
  Nombre función: push
  Descripción: Inserta un elemento en la cola.
  Proceso: 
    *Si la cola estaba vacía antes de insertar, entonces el inicio y el fin son el mismo nodo.
    *En caso contrario solo se inserta al final.
  Parámetros: Elemento a insertar.
  Retorna: Nada.
*/
template <class T>
void Queue<T>::push(T data){

  Node<T>* aux = new Node<T>(data);
  if( this->isEmpty() ){
    this->start = aux;
    this->end = this->start;
  }else{
    this->end->next = aux;
    this->end = aux;
  }
  this->sizeQueue++;

}

/*
  Nombre función: pop
  Descripción: Elimina un elemento en la cola.
  Excepciones:
    *Si la cola está vacía no se puede eliminar nada.
  Proceso: 
    *Si la cola queda vacía luego de eliminar, entonces el inicio y el fin son el mismo nodo (nullptr).
    *En caso contrario solo se elimina el nodo que está al inicio.
  Parámetros: Elemento a insertar.
  Retorna: Nada.
*/
template <class T>
void Queue<T>::pop(){

  if( this->isEmpty() ){
    std::cout<<"The queue is empty"<<std::endl;
  }else{
    Node<T>* aux = this->start;
    this->start = this->start->next;
    delete(aux);
    if( this->isEmpty() ){
      this->end = this->start;
    }
    this->sizeQueue--;
  }

}


/*
  Nombre función: front
  Descripción: Retorna el dato que se encuentra en el inicio de la cola.
  Parámetros: Ninguno.
  Excepciones: 
    *Si el inicio de cola está vacío se genera error por intentar acceder a un nullptr.
  Retorna: Dato que se encuentra en el inicio.
*/
template <class T>
T Queue<T>::front(){

  return this->start->data;

}

/*
  Nombre función: back
  Descripción: Retorna el dato que se encuentra en el final de la cola.
  Parámetros: Ninguno.
  Excepciones: 
    *Si el fin de cola está vacío se genera error por intentar acceder a un nullptr.
  Retorna: Dato que se encuentra en el final.
*/
template <class T>
T Queue<T>::back(){

  return this->end->data;

}

/*
  Nombre función: size
  Descripción: Calcula el tamaño de la cola.
  Parámetros: Ninguno.
  Retorna: Tamaño del la cola.
*/
template <class T>
int Queue<T>::size(){

  return this->sizeQueue;

}

/*
  Nombre función: isEmpty
  Descripción: Determina si la cola está vacía.
  Parámetros: Ninguno.
  Retorna:
    *TRUE si el inicio de la cola es nulo.
    *FALSE si el inicio de la cola no es nulo.
*/
template <class T>
bool Queue<T>::isEmpty(){

  return this->start == nullptr;

}
