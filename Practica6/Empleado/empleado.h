#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>

class Empleado
{
    std::string name;
    std::string lastName;
    int age;
    float payment;
public:
    Empleado()
    {
    }
    Empleado(const std::string& nombre, const std::string& apellido, const int& edad, const float& sueldo)
    {
        name = nombre;
        lastName = apellido;
        age = edad;
        payment = sueldo;
    }
    std::string nombre();
    std::string apellido();
    int edad();
    float sueldo();
    void setNombre(const std::string&);
    void setApellido(const std::string&);
    void setEdad(const int&);
    void setSueldo(const float&);
    bool operator <(Empleado emp)
    {
        return (this->nombre() < emp.nombre() ? true : false);
    }
    bool operator >(Empleado emp)
    {
        return (this->nombre() > emp.nombre() ? true : false);
    }
};

#endif // EMPLEADO_H
