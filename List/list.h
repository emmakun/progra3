// ListAb.h: Plantilla para lista abierta ordenada
// C con Clase. (C) Marzo de 2002
// Plantilla para lista abierta
// Posibles mejoras:
// * Implementar constructor copia.

#ifndef _LIST_
#define _LIST_

template<class T>
class List {
  private:
   //// Clase local de List para Node de List:
   template<class T_Node>
   class Node {
     public:
      // Constructor:
      Node(const T_Node data, Node<T_Node> *nxt) : item(data), next(nxt) {}
      // Miembros:
      T_Node item;
      Node<T_Node> *next;
   };

   // Punteros de la lista, para cabeza y nodo current:
   Node<T> *first;
   Node<T> *current;

  public:
   // Constructor y destructor básicos:
   List() : first(NULL), current(NULL) {}
   ~List();
   // Funciones de inserción:
   void insertAtEnd(const T data);
   void insertAtBegin(const T data);
   bool insertAtThis(const T data);
   void insert(const T data);
   // Funciones de borrado:
   void deleteThis();
   bool deleteFirst(const T data);
   // Función de búsqueda:
   bool findFirst(const T data);
   // Comprobar si la lista está vacía:
   bool empty() { return first==NULL; }
   // Devolver referencia al item del nodo current:
   T &getThis() { return current->item; }
   // Hacer que el nodo current sea el first:
   void getFirst() { current = first; }
   // Comprobar si el nodo current es válido:
   bool isValid() { return current != NULL; }
   // Moverse al next nodo de la lista:
   void forward() { if(current) current = current->next; }
   // Sobrecargar operator++ en forma sufija para los mismo:
   void operator++(int) { forward(); }
   // Aplicar una función a cada elemento de la lista:
   void forEach(void (*func)(T&));
};

//////// Implementación:

// Destructor
template<class T>
List<T>::~List() {
   while(!empty()) {
      current = first;
      first = first->next;
      delete current;
   }
}

template<class T>
void List<T>::insertAtEnd(const T data) {
   Node<T> *last;

   // Si la lista está vacía, insertar al principio:
   if(empty()) insertAtBegin(data);
   else { // Si no lo está:
      // Buscar el último nodo:
      last = first;
      while(last->next) last = last->next;
      // insert a continuación:
      last->next = new Node<T>(data, NULL);
   }
}

template<class T>
void List<T>::insertAtBegin(const T data) {
   first = new Node<T>(data, first);
}

template<class T>
bool List<T>::insertAtThis(const T data) {
   // Sólo si la lista no está vacía y current es válido:
   if(!empty() && current) {
      current->next = new Node<T>(data, current->next);
      return true;
   }
   // Si no se puede insertar, retornar con false:
   return false;
}

// insert ordenadamente:
template<class T>
void List<T>::insert(const T data) {
   Node<T> *temp = first;
   Node<T> *previous = NULL;

   // Si la lista está vacía, insertar al principio:
   if(empty()) insertAtBegin(data);
   else {
      // Buscar el nodo previous al primer nodo con un item mayor qur 'data'
      while(temp && temp->item < data) {
         previous = temp;
         temp = temp->next;
      }
      // Si no hay previous, insertar al principio,
      // nuestro valor es el menor de la lista:
      if(!previous)
         insertAtBegin(data);
      else // insert:
         previous->next = new Node<T>(data, temp);
   }
}

template<class T>
void List<T>::deleteThis() {
   Node<T> *previous;

   // Si el nodo current es el first:
   if(current && current == first) {
      // El primer nodo será ahora el segundo:
      // Sacar el nodo current de la lista:
      first = current->next;
      // Borrarlo:
      delete current;
      current = NULL;
   } else
   if(current && !empty()) {
      // Buscar el nodo previous al current:
      previous = first;
      while(previous && previous->next != current)
         previous = previous->next;
      // Sacar el nodo current de la lista:
      previous->next = current->next;
      // Borrarlo:
      delete current;
      current = NULL;
   }
}

// Borrar el primer nodo cuyo item sea igual a 'data':
template<class T>
bool List<T>::deleteFirst(const T data) {
   Node<T> *previous = NULL;
   Node<T> *temp = first;

   if(!empty()) {
      // Si la lista no está vacía, buscar el nodo a borrar (temp)
      // y el nodo previous a ese (previous):
      while(temp && temp->item != data) {
         previous = temp;
         temp = temp->next;
      }
      // Si el valor está en la lista:
      if(temp) {
         // Si previous es válido, no es el primer valor de la lista
         if(previous) // Sacar nodo temp de la lista
            previous->next = temp->next;
         else         // Ahora el first es el segundo:
           first = temp->next;  // Borrar primer elemento
         // Borrar nodo:
         delete temp;
         return true; // Se ha encontrado y borrado data
      }
   }
   return false; // valor no encontrado
}

// Busca el primer nodo con valor 'data':
template<class T>
bool List<T>::findFirst(const T data) {
   current = first;

   // Si la lista no está vacía:
   if(!empty()) {
      while(current && current->item != data) {
         current = current->next;
      }
   }
   // Si el nodo es válido, se ha encontrado el valor:
   return current != NULL;
}

// Aplicar una función a cada nodo de la lista:
template<class T>
void List<T>::forEach(void (*func)(T&)) {
   Node<T> *temp = first;

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

#endif
