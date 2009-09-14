/***********************************************************
  Práctica III
  Programa que calcula el resultado de la multiplicación de
  todos los elementos de un arreglo usando recursividad.

  Elaboró:  Cerón Blanco Monserrat
            Valle Vieyra Alvaro Emmanuel
***********************************************************/

#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

void convtype(void*, void*);
long multiplicacion(int*, int, int, long);

int main()
{
    system("clear"); // limpiamos la pantalla

    cout<<"Introduce el numero de elementos del arreglo: ";
    string cad;
    int n;
    int* arreglo;
    cin>>cad;
    convtype(&cad, &n); //convierte la entrada en un entero...
    if(n > 0)
    {
        arreglo = new int[n]; //inicializa el arreglo

        for(int i=0;i<n;i++)
        {
            cout<<"introduzca el valor del elemento "<<i+1<<": ";
            cin>>arreglo[i];
        } //inicializa los valores del arreglo
        for(int i=0;i<n;i++)
        {
            cout<<"arreglo["<<i<<"]: "<<arreglo[i]<<endl;
        }//muestra el contenido del arreglo
        if(&arreglo != NULL)
        {
            cout<<"El resultado es: "<<multiplicacion(arreglo, n, 0, 1)<<endl;
        }//verifica que el arreglo no es nulo y multiplica sus elementos
        else
            cout<<"Error...";
    }
    else
        cout<<"Debe introducir un numero entero positivo...\n\n";

    return 0;
}

void convtype(void* inp, void* out)
{
  istringstream isbuf;

      isbuf.str(*(string*) inp);
      isbuf >> *((int*) out);
}//funcion que convierte cadenas a enteros

long multiplicacion(int * arreglo, int max, int indice, long last)
{
    long value;

    if(indice == max)
    {
        value = last;
    }//su el indice actual es igual a la longitud, se habra llegado al final del arreglo
    else if(arreglo[indice] == 0 || last == 0)
    {
        value = 0;
    }//si el valor actual o el ultimo son 0 entonces se devuelve 0
    else
    {
        value = multiplicacion(arreglo, max, indice+1, arreglo[indice]*last);
    }//llamamos a la misma funcion con el siguiente indice y el resultado del producto del elemento actual y el ultimo resultado.

    return value;
}//multiplica los elementos de un arreglo de enteros; recibe el arreglo, su longitud, el indice actual y el ultimo resultado.
