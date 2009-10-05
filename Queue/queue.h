#ifndef QUEUE_H
#define QUEUE_H

/******************************************************************
  Biblioteca queue.h Que implementa colas.
  Creado por:
  Cerón Blanco Monserrat
  Valle Vieyra Alvaro Emmanuel
******************************************************************/

#include <iostream>
#include <vector>

using namespace std;
//Los templates son plantillas que permiten crear código genérico en C++.
template <class T>
        //Definición de la clase Queue (cola)
class Queue {
    vector<T> queueList;
    int maxSize;
    //int start;
    //int end;
public:
    Queue(int size)
    {
        maxSize = size;
        //start = 0;
        //end = -1;
    }
    ~Queue()
    {

    }

    bool empty()
    {
        if(queueList.empty())
            return true;
        else
            return false;
    }
    bool full()
    {
        if(queueList.size() == maxSize)
            return true;
        else
            return false;
    }
    T& front()
    {
        T value = NULL;

        if(!empty())
            value = queueList.front();
        else
            cout<<endl<<"The Queue is empty"<<endl;

        return value;
    }
    T& dequeue()
    {
        T value = NULL;
        if(!empty())
        {
            value = queueList.front();
            queueList.front()++;
        }
        else
            cout<<endl<<"The Queue is empty"<<endl;

        return value;
    }
    void enqueue(const T& item)
    {
        if(!full())
            queueList.push_back(item);
        else
            cout<<endl<<"The stack is full"<<endl;
    }
    int size()
    {
        return queueList.size();
    }
};

#endif // QUEUE_H
