#include "alumno.h"
#include <iostream>

using namespace std;

string Alumno::nombre() const
{
    return _nombre;
}
int Alumno::edad()
{
    return _edad;
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
void Alumno::setEdad(const int& edad)
{
    _edad = edad;
}
void Alumno::setBoleta(const unsigned int& Boleta)
{
    _boleta = Boleta;
}
void Alumno::setCalif(const float& calif)
{
    _calif = calif;
}
