#ifndef STACK_H
#define STACK_H
/******************************************************************
  Biblioteca stack.h Que implementa pilas.
  Creado por:
  Cerón Blanco Monserrat
  Valle Vieyra Alvaro Emmanuel
******************************************************************/

#include <iostream>

using namespace std;
//Los templates son plantillas que permiten crear código genérico en C++.
template <class T>
        //Definición de la clase stack (pila)
class Stack {
    T *stackList;
    int maxSize;
    int top;
public:
    //Constructor
    Stack(int size)
    {
        maxSize = size;
        stackList = new T[maxSize];
        top = -1;
    }
    //Destructor
    ~Stack()
    {
        delete[] stackList;
    }

    //Definición de las funcines de la pila.
    void push(T const&);
    T pop();
    bool empty();
    bool full();
    T getTop() const;
    int size() const;
    void clean();
    static void copyStack(Stack<T>&, Stack<T>&);
};

//Función push recibe un element tipo T, el tipo de T se especifica como parámetro.
template <class T>
void Stack<T>::push(T const& element)
{
    if(full())
        cout<<endl<<"Lista llena."<<endl;
    else
    {
        top++;
        stackList[top]=element;
    }
}
//Implementación de la función pop del stack
template <class T>
T Stack<T>::pop()
{
    if(empty())
    {
        cout<<endl<<"Lista vacía."<<endl;
        return NULL;
    }
    else
    {
        return (stackList[top--]);
    }
}

//Implementación de la función pila llena. Devuelve true si está llena.
template <class T>
bool Stack<T>::full()
{
    return (top == maxSize-1 ? true : false);
}

//Implementación de la función pila vacía, devuelve true si está vacía.
template <class T>
bool Stack<T>::empty()
{
    return (top == -1 ? true : false);
}

//Implementación de la función cima, devuelve el valor del elemento cima.
template <class T>
T Stack<T>::getTop() const
{
    if(!empty())
        return stackList[top];
    else
    {
        cout<<endl<<"Lista vacía"<<endl;
        return NULL;
    }
}

//Función que devuelve el tamaño de la pila.
template <class T>
int Stack<T>::size() const
{
    return maxSize;
}

//Función que limpia la pila
template <class T>
void Stack<T>::clean()
{
    top=-1;
}

//Mofificación práctica 2. Función que copia los valores de una pila a otra.
template <class T>
void Stack<T>::copyStack(Stack<T>& Src,Stack<T>& Trg)
{
    if(Src.size() <= Trg.size())
    {        
        Stack<T> aux(Src.size());
        int max=Src.top;
        for(int i=0;i<=max;i++)
        {
            T item = Src.pop();
            aux.push(item);
        }
        for(int i=0;i<=max;i++)
        {
            T item = aux.pop();
            Trg.push(item);
            Src.push(item);
        }
    }
    else
        cout<<endl<<"Las pila destino es no es suficientemente grande."<<endl;
}
#endif // STACK_H

