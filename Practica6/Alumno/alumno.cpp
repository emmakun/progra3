#include "alumno.h"
#include <iostream>

using namespace std;

string Alumno::nombre()
{
    return _nombre;
}
string Alumno::apellido()
{
    return _apellido;
}
unsigned int Alumno::boleta()
{
    return _boleta;
}
float Alumno::calif()
{
    return _calif;
}
void Alumno::setNombre(const string& nombre)
{
    _nombre = nombre;
}
void Alumno::setApellido(const string& apellido)
{
    _apellido = apellido;
}
void Alumno::setBoleta(const unsigned int& Boleta)
{
    _boleta = Boleta;
}
void Alumno::setCalif(const float& calif)
{
    _calif = calif;
}
