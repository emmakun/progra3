#include "suffix.h"
#include <iostream>
#include <cstdlib>
using namespace std;
/******************************************************************
  Programa que convierte una cadena en notación interfija introdu-
  cida por el usuario y devuelve su equivalente en posfija.
  Creado por:
  Cerón Blanco Monserrat
  Valle Vieyra Alvaro Emmanuel
******************************************************************/

int main()
{
    Suffix suffix;
    char charStr[100];
    system("clear");
    cout<<endl<<endl<<"\t* * * Conviete de interfija a posfija * * *"<<endl<<endl;
    cout<<"\tEscribe una cadena en notacion interfija: "<<endl<<"\t";
    cin.get(charStr,100);
    string str = charStr;
    string res=suffix.fromInterfix(str);
    cout<<endl<<"\tResultado: "<<endl<<"\t"<<res<<endl<<endl;
    return 0;
}
