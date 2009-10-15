#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>

class Alumno
{
    std::string _nombre;
    std::string _apellido;
    unsigned int _boleta;
    float _calif;
public:
    Alumno()
    {
    }
    Alumno(std::string& nombre, std::string& apellido, unsigned int& boleta, float& calif)
    {
        _nombre = nombre;
        _apellido = apellido;
        _boleta = boleta;
        _calif = calif;
    }

    std::string nombre();
    std::string apellido();
    unsigned int boleta();
    float calif();
    void setNombre(const std::string&);
    void setApellido(const std::string&);
    void setBoleta(const unsigned int&);
    void setCalif(const float&);
    bool operator <(Alumno al)
    {
        return (this->apellido() < al.apellido() ? true : false);
    }
    bool operator >(Alumno al)
    {
        return (this->apellido() > al.apellido() ? true : false);
    }
    bool operator <=(Alumno al)
    {
        return (this->apellido() <= al.apellido() ? true : false);
    }
    bool operator !=(Alumno al)
    {
        return (this->apellido() != al.apellido() ? true : false);
    }
};

#endif // ALUMNO_H
