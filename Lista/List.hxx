#include "List.h"

/*
  Nombre función: List
  Descripción: Crea una lista vacía.
  Parámetros: Ninguno.
  Retorna: Nada.
*/
template <class T>
List<T>::List(){

  this->start = nullptr;
  this->listSize = 0;

}

/*
  Nombre función: List
  Descripción: Crea una lista con el elemento enviado por parámetro.
  Parámetros: Elemento a insertar al inicio de la lista.
  Retorna: Nada.
*/
template <class T>
List<T>::List(T data){

  this->start = new Node<T>(data);
  this->listSize = 1;
}

/*
  Nombre función: ~List
  Descripción: Elimina cada uno de los elementos en la lista.
  Parámetros: Ninguno.
  Retorna: Nada.
*/
template <class T>
List<T>::~List(){

  Node<T>* aux = this->start;
  while(aux != nullptr){
    this->start = this->start->next;
    delete(aux);
    aux = this->start;
  }
  this->listSize = 0;

}

/*
  Nombre función: push_back
  Descripción: Inserta un elemento al final de la lista.
  Parámetros: Elemento a insertar.
  Retorna: Nada.
*/
template <class T>
void List<T>::push_back(T data){

  if( this->isEmpty() ){
    this->start = new Node<T>(data);
  }else{
    Node<T>* aux = this->start;
    while(aux->next != nullptr){
      aux = aux->next;
    }
    aux->next = new Node<T>(data);
    this->listSize++;
  }

}

/*
  Nombre función: push_front
  Descripción: Inserta un elemento al inicio de la lista.
  Parámetros: Elemento a insertar.
  Retorna: Nada.
*/
template <class T>
void List<T>::push_front(T data){

  Node<T>* newStart = new Node<T>(data);
  newStart->next = this->start;
  this->start = newStart;
  this->listSize++;

}

/*
  Nombre función: insert
  Descripción: Inserta un elemento en la lista en la posicion especificada.
  Excepciones:
    *Si la posición enviada es negativa o mayor al tamaño actual de la lista, el elemento no se inserta.
    *Si la lista está vacía y la posición enviada no es cero, el elemento no se inserta.
  Parámetros: Elemento a insertar, posición en la cual se quiere insertar el elemento.
  Retorna: Nada.
*/
template <class T>
void List<T>::insert(T data, int position){

  int max_size = this->size();
  int cont = 0;
  int i;
  if(position > max_size || position < 0){
    std::cout<<"Position out of range"<<std::endl;
  }else if(position == 0){
    this->push_front(data);
  }else{
    Node<T>* aux = this->start;
    for(i = 1; i < position; i++){
      aux = aux->next;
    }
    Node<T>* toAdd = new Node<T>(data);
    this->listSize++;
    toAdd->next = aux->next;
    aux->next = toAdd;
  }

}

/*
  Nombre función: pop_back
  Descripción: Elimina el elemento al final de la lista.
  Excepciones:
    *Si la lista está vacía, no hay dato que eleminar.
  Parámetros: Ninguno.
  Retorna: Nada.
*/
template <class T>
void List<T>::pop_back(){

  if( this->isEmpty() ){
    std::cout<<"The list is empty"<<std::endl;
  }else{
    Node<T>* aux = this->start;
    Node<T>* aux2 = aux;
    while(aux->next != nullptr){
      aux2 = aux;
      aux = aux->next;
    }
    aux2->next = nullptr;
    delete(aux);
    this->listSize--;
  }

}

/*
  Nombre función: pop_front
  Descripción: Elimina el elemento al inicio de la lista.
  Excepciones:
    *Si la lista está vacía, no hay dato que eleminar.
  Parámetros: Ninguno.
  Retorna: Nada.
*/
template <class T>
void List<T>::pop_front(){

  if( this->isEmpty() ){
    std::cout<<"The list is empty"<<std::endl;
  }else{
    Node<T>* aux = this->start;
    this->start = this->start->next;
    delete(aux);
    this->listSize--;
  }

}

/*
  Nombre función: erase
  Descripción: Elimina un elemento en la lista en la posicion especificada.
  Excepciones:
    *Si la posición enviada es negativa o mayor al tamaño actual de la lista, el elemento no se elimina.
    *Si la lista está vacía y la posición enviada no es cero, el elemento no se elimina.
  Parámetros: Posición en la cual se quiere eliminar el elemento.
  Retorna: Nada.
*/
template <class T>
void List<T>::erase(int position){

  int max_size = this->size();
  int cont = 0;
  int i;
  if(position > max_size || position < 0){
    std::cout<<"Position out of range"<<std::endl;
  }else if(position == 0){
    this->pop_front();
  }else{
    Node<T>* aux = this->start;
    Node<T>* aux2 = aux;
    for(i = 0; i < position; i++){
      aux2 = aux;
      aux = aux->next;
    }
    aux2->next = aux->next;
    delete(aux);
    this->listSize--;
  }

}

/*
  Nombre función: print_list
  Descripción: Imprime en pantalla todos los elementos que estén en la lista.
  Parámetros: Ninguno.
  Retorna: Nada.
*/
template <class T>
void List<T>::print_list(){

  if( this->isEmpty() ){
    std::cout<<"The list has no data"<<std::endl;
  }else{
    Node<T>* aux = this->start;
    while(aux != nullptr){
      std::cout<<aux->data<<std::endl;
      aux = aux->next;
    }
  }

}

/*
  Nombre función: size
  Descripción: Calcula el tamaño de la lista.
  Parámetros: Ninguno.
  Retorna: Tamaño de la lista.
*/
template <class T>
int List<T>::size(){
  return this->listSize;
}

/*
  Nombre función: isEmpty
  Descripción: Determina si la lista está vacía.
  Parámetros: Ninguno.
  Retorna:
    *TRUE si el inicio de la lista es nulo.
    *FALSE si el inicio de la lista no es nulo.
*/
template <class T>
bool List<T>::isEmpty(){
  return this->start == nullptr;
}

/*
  Nombre función: clear
  Descripción: Vacía la lista.
  Parámetros: Ninguno.
  Retorna: Nada.
*/
template <class T>
void List<T>::clear(){

  Node<T>* aux = this->start;
  while(aux != nullptr){
    this->start = this->start->next;
    delete(aux);
    aux = this->start;
  }
  this->start = nullptr;
  this->listSize = 0;

}

/*
  Nombre función: getStart
  Descripción: Entrega el inicio de la lista para poder hacer operaciones externas con la misma.
  Parámetros: Ninguno.
  Retorna: Apuntador al nodo inicial de la lista.
*/
template <class T>
Node<T>* List<T>::getStart(){

  return this->start;

}
