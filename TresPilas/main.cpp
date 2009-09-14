#include "stack.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <sstream>
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
void convtype(void*, void*);

int main()
{
    int i=0,j=0,n=0,opc=0;
    string cad = "";
    vector<Stack<int>*> arreglo;
    system("clear");
    do{
        cout<<"\t*****Operaciones sobre pilas*****\n\n";
        cout<<"\t1) Definir el número de pilas (n actualmente vale: "<<n<<").";
        cout<<"\n\t2) Ingresar (i actualmente vale: "<<i<<" y j: "<<j<<").";
        cout<<"\n\t3) Procesar.";
        cout<<"\n\t4) Salir.";
        cout<<"\n\n\tSelecciona una opción: ";
        cin>>cad;
        convtype(&cad, &opc);
        switch(opc)
        {
            case 1:
                system("clear");
                cout<<"\n\tIngrese el numero de pilas (n) que desea utilizar: ";
                cin>>cad;
                convtype(&cad, &n);
                if(n > 0)
                {
                    arreglo = declaraPilas(n);
                    system("clear");
                }
                else
                {
                    cout<<"\n\tEl numero ingresado no es valido.\n\n";
                    n = 0;
                }
                break;

            case 2:
                system("clear");
                cout<<"\n\tIngrese el valor de i: ";
                cin>>cad;
                convtype(&cad, &i);
                cout<<"\n\tIngrese el valor de j: ";
                cin>>cad;
                convtype(&cad, &j);
                system("clear");
                break;

            case 3:
                system("clear");
                if(n != 0)
                {
                    procesa(i,j,arreglo);
                    if(i != 0)
                        cout<<"\n\tProceso Exitoso!\n\n";
                }
                else
                    cout<<"\n\tDebe introducir un valor para n...\n\n";
                break;
            case 4:
                cout<<"\n\tHasta luego!\n\n";
                break;
            default:
                system("clear");
                cout<<"\n\tOpcion no valida...\n\n";
                break;
        }
    }while(opc!=4); //este es el menu...


    return 0;
}

void procesa(int i, int j, vector<Stack<int>*>& arreglo)
{
    int n = arreglo.size();
    if(0 <= abs(i) <= n) // si el valor absoluto de i es mayor o igual que cero y menor o igual que el numero de pilas...
    {
        if(i>0)
        {
            arreglo[i-1]->push(j);
        } // si i > 0 insertamos j en el elemento señalado por i...
        else if(i<0)
        {
            arreglo[abs(i)-1]->pop();
        } // si i < 0 quitamos el elemento cima de la pila |i|...
        else
        {
            for(unsigned int a=0; a<arreglo.size(); a++)
            {
                if(arreglo[a]->empty())
                    cout<<"La pila "<<a+1<<" esta vacia..."<<endl<<endl;
                else
                {
                    Stack<int> temp(20);
                    Stack<int>::copyStack(*arreglo[a], temp); //copiamos la pila a para no afectar sus elementos
                    cout<<"La pila "<<a+1<<" contiene:"<<endl<<endl;
                    while(!temp.empty())
                    {
                        cout<<temp.pop()<<endl; //mostramos los elementos de la pila copiada
                    }
                }
            }
        } // aqui mostramos los elementos de todas las pilas (i = 0)...
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
}//funcion que declara un total de n pilas e inicializa el arreglo...

void convtype(void* inp, void* out)
{
  istringstream isbuf;

      isbuf.str(*(string*) inp);
      isbuf >> *((int*) out);
}//convierte una cadena a un entero

