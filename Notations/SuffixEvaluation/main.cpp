#include "suffix.h"
#include <iostream>
#include <cstdlib>
using namespace std;
/******************************************************************
  Programa que evalúa una cadena en notación posfija introdu-
  cida por el usuario y devuelve su el resultado.
  Creado por:
  Cerón Blanco Monserrat
  Valle Vieyra Alvaro Emmanuel
******************************************************************/

int main()
{
    Suffix suffix;
    char charStr[100];
    system("clear");
    cout<<endl<<endl<<"\t* * * Evalua cadena posfija * * *"<<endl<<endl;
    cout<<"\tEscribe una cadena en notacion posfija: "<<endl<<"\t";
    cin.get(charStr,100);
    string str = charStr;
    double res=suffix.evaluate(str);
    cout<<endl<<"\tResultado: "<<endl<<"\t"<<res<<endl<<endl;
    return 0;
}
