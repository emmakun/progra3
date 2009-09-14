#include "stack.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
/***********************************************************
  Práctica III
  Programa que maneja un total de n=3 pilas P1,P2,P3.
  La entrada es en pares enteros (i,j) y hace operaciones
  sobre las pilas dependiendo del valor de i.

  Elaboró:  Cerón Blanco Monserrat
            Valle Vieyra Alvaro Emmanuel
***********************************************************/
using namespace std;
void procesa(int, int, vector<Stack<int>*>&);
vector<Stack<int>*> declaraPilas(int);
bool isNumeric(char*);

int main()
{
    int i,j,n,opc;
    string cad;
    do{
        cout<<"\t*****Operaciones sobre pilas*****\n\n";
        cout<<"\t1) Definir el número de pilas.";
        cout<<"\n\t2) Ingresar (i,j).";
        cout<<"\n\t3) Salir.";
        cout<<"\n\n\tSelecciona una opción: ";
        cin>>opc;
        switch(opc)
        {
            case 1:
                system("clear");
                cout<<"\n\tIngrese el numero de pilas (n) que desea utilizar.";
                //cin>>

        }
    }while(opc!=9);


    return 0;
}

void procesa(int i, int j, vector<Stack<int>*>& arreglo)
{
    int n = arreglo.size();
    if(0 <= abs(i) <= n)
    {
        if(i>0)
        {
            arreglo[i-1]->push(j);
        }
        else if(i<0)
        {
            arreglo[abs(i)-1]->pop();
        }
        else
        {
            for(unsigned int a=0; a<arreglo.size(); a++)
            {
                if(arreglo[a]->empty())
                    cout<<"La pila "<<a+1<<" esta vacia..."<<endl<<endl;
                else
                {
                    Stack<int> temp(20);
                    Stack<int>::copyStack(*arreglo[a], temp);
                    cout<<"La pila "<<a+1<<" contiene:"<<endl<<endl;
                    while(!temp.empty())
                    {
                        cout<<temp.pop()<<endl;
                    }
                }
            }
        }
    }
    else
    {
        cout<<"Error: i es mayor que n..."<<endl;
        exit(1);
    }
}

vector<Stack<int>*> declaraPilas(int n)
{
    vector<Stack<int>*> arreglo;

    if(n != 0)
    {
        for(int a=0;a<n;a++)
        {
            Stack<int>* pila = new Stack<int>(20);
            arreglo.push_back(pila);
        }
    }

    return arreglo;
}

bool isNumeric(char* cStr)
{
    bool value;
    int n = 0;

    if(cStr[0] == '-')
        n = 1;

    while(cStr[n] != NULL)
    {
        if(!isdigit(cStr[n]))
        {
            value = false;
            break;
        }
    }

    return value;
}
