#include "alumno.h"
#include "dlist.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void printMenu();
void agregarAlumno(List<Alumno>&);
void imprimirAlumno(Alumno&);
bool eliminarAlumno(List<Alumno>&);
bool buscarAlumno(List<Alumno>&);
void ordenarAlumno(List<Alumno>&);

int main()
{
    List<Alumno> lista;

    while(true)
    {
        printMenu();
        int i = 0;
        cin>>i;

        switch(i)
        {
            case 1:
                system("clear");
                lista.~List();
                break;
            case 2:
                system("clear");
                agregarAlumno(lista);
                break;
            case 3:
                system("clear");
                if(eliminarAlumno(lista))
                    cout<<endl<<"\tEl alumno se ha eliminado..."<<endl;
                else
                    cout<<endl<<"\tNo se han encontrado coincidencias..."<<endl;
                break;
            case 4:
                system("clear");
                if(buscarAlumno(lista))
                {
                    system("clear");
                    cout<<"Los datos del alumno son:"<<endl<<endl;
                    imprimirAlumno(lista.CurrentItem());
                }
                else
                    cout<<endl<<"\tNo se han encontrado coincidencias..."<<endl;
                break;
            case 5:
                system("clear");
                lista.forEach(&imprimirAlumno);
                break;
            case 6:
                system("clear");
                cout<<"El tamanio de la lista es:"<<endl<<"\t"<<lista.count()<<endl<<endl;
                break;
            case 7:
                system("clear");
                cout<<"Hasta luego!"<<endl;
                exit(0);
                break;
            default:
                system("clear");
                cout<<"Opcion no valida..."<<endl<<endl;
                break;
        }
    }
    return 0;
}

void printMenu()
{
    cout<<"¿Que desea hacer?"<<endl<<endl;
    cout<<"\t1) Vaciar la lista"<<endl;
    cout<<"\t2) Insertar un Alumno"<<endl;
    cout<<"\t3) Eliminar un Alumno"<<endl;
    cout<<"\t4) Buscar un Alumno por su nombre"<<endl;
    cout<<"\t5) Imprimir la lista"<<endl;
    cout<<"\t6) Mostrar el tamaño de la lista"<<endl;
    cout<<"\t7) Salir"<<endl<<"> ";
}

void agregarAlumno(List<Alumno>& lista)
{
    string nombre, apellido;
    unsigned int boleta;
    float calif;

    cout<<"Introduzca el nombre del alumno:"<<endl<<"\t>";
    cin>>nombre;
    cout<<"\n\nIntroduzca el apellido del alumno:"<<endl<<"\t>";
    cin>>apellido;
    cout<<"\n\nIntroduzca la boleta del alumno:"<<endl<<"\t>";
    cin>>boleta;
    cout<<"\n\nIntroduzca la calificacion del alumno:"<<endl<<"\t>";
    cin>>calif;

    Alumno al(nombre,apellido,boleta,calif);
    lista.insert(al);

    system("clear");
}

void imprimirAlumno(Alumno& alumno)
{
    cout<<"Nombre: "<<alumno.nombre()<<endl;
    cout<<"Apellido: "<<alumno.apellido()<<endl;
    cout<<"Boleta: "<<alumno.boleta()<<endl;
    cout<<"Calificacion: "<<alumno.calif()<<endl<<endl;
}

bool eliminarAlumno(List<Alumno>& lista)
{
    bool value = false;
    cout<<"Introduzca el nombre del alumno que desea eliminar:\n\t> ";
    string nombre;
    cin>>nombre;
    lista.first();
    while(lista.valid())
    {
        if(nombre == lista.CurrentItem().nombre())
        {
            lista.remove(lista.CurrentItem());
            value = true;
            break;
        }
        lista.next();
    }

    return value;
}

bool buscarAlumno(List<Alumno>& lista)
{
    bool value = false;
    cout<<"Introduzca el nombre del alumno que desea buscar:\n\t> ";
    string nombre;
    cin>>nombre;
    lista.first();
    while(lista.valid())
    {
        if(nombre == lista.CurrentItem().nombre())
        {
            value = true;
            break;
        }
        lista.next();
    }

    return value;
}

void ordenarAlumno(List<Alumno>& lista)
{
    List<Alumno> aux;

    lista.first();
    while(lista.valid())
    {
        aux.insert(lista.CurrentItem());
        lista.next();
    }

    lista.~List();

    aux.first();
    while(aux.valid())
    {
        lista.insert(aux.CurrentItem());
        aux.next();
    }
}
