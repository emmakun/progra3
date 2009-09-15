//Valle Vieyra Alvaro Emmanuel
//2007630534
//Grupo: 3CV1
//Escribir una función reemplazar que tenga como argumentos una pila de enteros
//y dos valores enteros: nuevo y viejo, de tal manera que si el valor viejo aparece
//en la pila, será reemplazado por el nuevo elemento.

#include "stack.h"
#include <iostream>
using namespace std;

void reemplaza(Stack<int>&, int, int);

int main()
{
    int opc = 0, viejo, nuevo;
    Stack<int> pila(5), temp(5);
    do
    {
        cout<<"Seleccione la opcion que desea:\n\n";
        cout<<"\tIngresar numeros: 1"<<endl;
        cout<<"\tReemplazar: 2"<<endl;
        cout<<"\tImprimir: 3"<<endl;
        cout<<"\tSalir: 4"<<endl<<endl<<"\t>";

        cin>>opc;

        switch(opc)
        {
            case 1:
                system("clear");
                cout<<"Ingrese los numeros que almacenara la pila (5 elementos):"<<endl;
                for(int i=0;i<5;i++)
                {
                    int a;
                    cout<<"\nValor del elemento "<<i+1<<": ";
                    cin>>a;
                    pila.push(a);
                }
                break;
            case 2:
                cout<<"\n\tIntroduzca el valor viejo: ";
                cin>>viejo;
                cout<<"\n\tIntroduzca el valor nuevo: ";
                cin>>nuevo;
                reemplaza(pila, viejo, nuevo);
                break;
            case 3:
                Stack<int>::copyStack(pila,temp);
                if(!temp.empty())
                {
                    cout<<"\n\tLos elementos de la pila son:\n";
                    while(!temp.empty())
                    {
                        cout<<temp.pop()<<endl;
                    }
                }
                else
                    cout<<"La pila esta vacia..."<<endl;
                break;
            case 4:
                cout<<"\Hasta luego!"<<endl<<endl;
                break;
            default:
                cout<<"\Opcion invalida..."<<endl<<endl;
                break;
        }
    }
    while(opc != 4);
    return 0;
}

void reemplaza(Stack<int>& pila, int viejo, int nuevo)
{
    Stack<int> temp(5);

    while(!pila.empty())
    {
        int a = pila.pop();
        if(a == viejo)
            a = nuevo;

        temp.push(a);
    }

    while(!temp.empty())
    {
        pila.push(temp.pop());
    }
}
