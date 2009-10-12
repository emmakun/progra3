#include "empleado.h"
#include "list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void printMenu();
void agregarEmpleado(List<Empleado>&);
void imprimirEmpleado(Empleado&);
bool eliminarEmpleado(List<Empleado>&);
bool buscarEmpleado(List<Empleado>&);

int main()
{
    List<Empleado> lista;

    while(true)
    {
        printMenu();
        int i = 0;
        cin>>i;

        switch(i)
        {
            case 1:
                system("clear");
                agregarEmpleado(lista);
                break;
            case 2:
                system("clear");
                lista.forEach(&imprimirEmpleado);
                break;
            case 3:
                system("clear");
                if(eliminarEmpleado(lista))
                    cout<<endl<<"\tEl empleado se ha eliminado..."<<endl;
                else
                    cout<<endl<<"\tNo se han encontrado coincidencias..."<<endl;
                break;
            case 4:
                system("clear");
                if(buscarEmpleado(lista))
                {
                    system("clear");
                    cout<<"Los datos del empleado son:"<<endl<<endl;
                    imprimirEmpleado(lista.getThis());
                }
                else
                    cout<<endl<<"\tNo se han encontrado coincidencias..."<<endl;
                break;
            case 5:
                system("clear");
                break;
            case 6:
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
    cout<<"Que desea hacer?"<<endl<<endl;
    cout<<"\t1) Ingresar un empleado"<<endl;
    cout<<"\t2) Mostrar los datos de todos los empleados"<<endl;
    cout<<"\t3) Eliminar un empleado"<<endl;
    cout<<"\t4) Buscar un empleado por su nombre"<<endl;
    cout<<"\t5) Ordenar los empleados por el nombre"<<endl;
    cout<<"\t6) Salir"<<endl<<"> ";
}

void agregarEmpleado(List<Empleado>& lista)
{
    string nombre, apellido;
    int edad;
    float sueldo;

    cout<<"Introduzca el nombre del empleado:"<<endl<<"\t>";
    cin>>nombre;
    cout<<"\n\nIntroduzca el apellido del empleado:"<<endl<<"\t>";
    cin>>apellido;
    cout<<"\n\nIntroduzca la edad del empleado:"<<endl<<"\t>";
    cin>>edad;
    cout<<"\n\nIntroduzca el sueldo del empleado:"<<endl<<"\t>";
    cin>>sueldo;

    Empleado emp(nombre,apellido,edad,sueldo);
    lista.insertAtBegin(emp);

    system("clear");
}

void imprimirEmpleado(Empleado& empleado)
{
    cout<<"Nombre: "<<empleado.nombre()<<endl;
    cout<<"Apellido: "<<empleado.apellido()<<endl;
    cout<<"Edad: "<<empleado.edad()<<endl;
    cout<<"Sueldo: "<<empleado.sueldo()<<endl<<endl;
}

bool eliminarEmpleado(List<Empleado>& lista)
{
    bool value = false;
    cout<<"Introduzca el nombre del empleado que desea eliminar:\n\t> ";
    string nombre;
    cin>>nombre;
    lista.getFirst();
    while(lista.isValid())
    {
        if(nombre == lista.getThis().nombre())
        {
            lista.deleteThis();
            value = true;
            break;
        }
        lista.forward();
    }

    return value;
}

bool buscarEmpleado(List<Empleado>& lista)
{
    bool value = false;
    cout<<"Introduzca el nombre del empleado que desea buscar:\n\t> ";
    string nombre;
    cin>>nombre;
    lista.getFirst();
    while(lista.isValid())
    {
        if(nombre == lista.getThis().nombre())
        {
            value = true;
            break;
        }
        lista++;
    }

    return value;
}
