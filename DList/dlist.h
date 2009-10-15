#ifndef DLIST_H
#define DLIST_H


//class DList {
//public:
//    DList();
//};

#include <iostream>
using namespace std;

#define ASC 1
#define DESC 0

template<class T> class list;

template<class T>
class node {
   public:
    node(T v, node<T> *nxt = NULL, node<T> *prev = NULL) :
       item(v), next(nxt), previous(prev) {}

   private:
    T item;
    node<T> *next;
    node<T> *previous;

   friend class list<T>;
};

template<class T>
class list {
   public:
    list() : plist(NULL) {}
    ~list();

    void insert(T v);
    void remove(T v);
    bool empty() { return plist == NULL; }
    void getItems(int);
    void next();
    void previous();
    void first();
    void last();
    bool valid() { return plist != NULL; }
    T CurrentItem() { return plist->item; }

   private:
    node<T> *plist;
};

template<class T>
list<T>::~list()
{
   node<T> *aux;

   first();
   while(plist) {
      aux = plist;
      plist = plist->next;
      delete aux;
   }
}

template<class T>
void list<T>::insert(T v)
{
   node<T> *newNode;

   first();
   // Si la list está vacía
   if(empty() || plist->item > v) {
      // Asignamos a list un newNode node de item v y
      // cuyo next elemento es la list actual
      newNode = new node<T>(v, plist);
      if(!plist) plist = newNode;
      else plist->previous = newNode;
   }
   else {
      // Buscar el node de item menor a v
      // Avanzamos hasta el último elemento o hasta que el next tenga
      // un item mayor que v
      while(plist->next && plist->next->item <= v) next();
      // Creamos un newNode node después del node actual
      newNode = new node<T>(v, plist->next, plist);
      plist->next = newNode;
      if(newNode->next) newNode->next->previous = newNode;
   }
}

template<class T>
void list<T>::remove(T v)
{
   node<T> *pnode;

   pnode = plist;
   while(pnode && pnode->item < v) pnode = pnode->next;
   while(pnode && pnode->item > v) pnode = pnode->previous;

   if(!pnode || pnode->item != v) return;
   // remove el node

   if(pnode->previous) // no es el primer elemento
      pnode->previous->next = pnode->next;
   if(pnode->next) // no el el último node
      pnode->next->previous = pnode->previous;
}

template<class T>
void list<T>::getItems(int orden)
{
   node<T> *pnode;
   if(orden == ASC) {
      first();
      pnode = plist;
      while(pnode) {
         cout << pnode->item << "-> ";
         pnode = pnode->next;
      }
   }
   else {
      last();
      pnode = plist;
      while(pnode) {
         cout << pnode->item << "-> ";
         pnode = pnode->previous;
      }
   }
   cout << endl;
}

template<class T>
void list<T>::next()
{
   if(plist) plist = plist->next;
}

template<class T>
void list<T>::previous()
{
   if(plist) plist = plist->previous;
}

template<class T>
void list<T>::first()
{
   while(plist && plist->previous) plist = plist->previous;
}

template<class T>
void list<T>::last()
{
   while(plist && plist->next) plist = plist->next;
}

#endif // DLIST_H
