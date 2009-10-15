#ifndef DLIST_H
#define DLIST_H

#include <iostream>
using namespace std;

#define ASC 1
#define DESC 0

template<class T> class List;

template<class T>
class Node {
   public:
    Node(T v, Node<T> *nxt = NULL, Node<T> *prev = NULL) :
       item(v), next(nxt), previous(prev) {}

   private:
    T item;
    Node<T> *next;
    Node<T> *previous;

   friend class List<T>;
};

template<class T>
class List {
   public:
    List() : pList(NULL) {}
    ~List();

    void insert(T v);
    void remove(T v);
    bool empty() { return pList == NULL; }
    void getItems(int);
    void next();
    void previous();
    void first();
    void last();
    bool valid() { return pList != NULL; }
    T& CurrentItem() { return pList->item; }
    void forEach(void (*func)(T&));
    int count();

   private:
    Node<T> *pList;
};

template<class T>
List<T>::~List()
{
   Node<T> *aux;

   first();
   while(pList) {
      aux = pList;
      pList = pList->next;
      delete aux;
   }
}

template<class T>
void List<T>::insert(T v)
{
   Node<T> *newNode;

   first();
   // Si la List está vacía
   if(empty() || pList->item > v) {
      // Asignamos a List un newNode Node de item v y
      // cuyo next elemento es la List actual
      newNode = new Node<T>(v, pList);
      if(!pList) pList = newNode;
      else pList->previous = newNode;
   }
   else {
      // Buscar el Node de item menor a v
      // Avanzamos hasta el último elemento o hasta que el next tenga
      // un item mayor que v
      while(pList->next && pList->next->item <= v) next();
      // Creamos un newNode Node después del Node actual
      newNode = new Node<T>(v, pList->next, pList);
      pList->next = newNode;
      if(newNode->next) newNode->next->previous = newNode;
   }
}

template<class T>
void List<T>::remove(T v)
{
   Node<T> *pNode;

   pNode = pList;
   while(pNode && pNode->item < v) pNode = pNode->next;
   while(pNode && pNode->item > v) pNode = pNode->previous;

   if(!pNode || pNode->item != v) return;
   // remove el Node

   if(pNode->previous) // no es el primer elemento
      pNode->previous->next = pNode->next;
   if(pNode->next) // no el el último Node
      pNode->next->previous = pNode->previous;
}

template<class T>
void List<T>::getItems(int orden)
{
   Node<T> *pNode;
   if(orden == ASC) {
      first();
      pNode = pList;
      while(pNode) {
         cout << pNode->item << "-> ";
         pNode = pNode->next;
      }
   }
   else {
      last();
      pNode = pList;
      while(pNode) {
         cout << pNode->item << "-> ";
         pNode = pNode->previous;
      }
   }
   cout << endl;
}

template<class T>
void List<T>::next()
{
   if(pList) pList = pList->next;
}

template<class T>
void List<T>::previous()
{
   if(pList) pList = pList->previous;
}

template<class T>
void List<T>::first()
{
   while(pList && pList->previous) pList = pList->previous;
}

template<class T>
void List<T>::last()
{
   while(pList && pList->next) pList = pList->next;
}

// Aplicar una función a cada nodo de la lista:
template<class T>
void List<T>::forEach(void (*func)(T&)) {
   first();
   Node<T> *temp = pList;

   // Recorrer la lista:
   while(temp) {
      // Aplicar la función:
      func(temp->item);
      temp = temp->next;
   }
}

// La función "func" debe ser una plantilla de una función
// que no retorne valor y que admita un parámetro del mismo
// tipo que la lista:
// template <class T>
// void <funcion>(T d);

template<class T>
int List<T>::count()
{
    int i=0;
    first();
    Node<T> *temp = pList;

    while(temp)
    {
        i++;
        temp = temp->next;
    }

    return i;
}

#endif // DLIST_H
