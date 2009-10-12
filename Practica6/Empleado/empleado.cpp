#include "empleado.h"
#include <iostream>

using namespace std;

string Empleado::nombre()
{
    return name;
}
string Empleado::apellido()
{
    return lastName;
}
int Empleado::edad()
{
    return age;
}
float Empleado::sueldo()
{
    return payment;
}
void Empleado::setNombre(const string& nombre)
{
    name = nombre;
}
void Empleado::setApellido(const string& apellido)
{
    lastName = apellido;
}
void Empleado::setEdad(const int& edad)
{
    age = edad;
}
void Empleado::setSueldo(const float& sueldo)
{
    payment = sueldo;
}
