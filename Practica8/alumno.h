#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>

class Alumno
{
    std::string _nombre;
    int _edad;
    unsigned int _boleta;
    float _calif;
public:
    Alumno()
    {
    }
    Alumno(std::string& nombre, int& edad, unsigned int& boleta, float& calif)
    {
        _nombre = nombre;
        _edad = edad;
        _boleta = boleta;
        _calif = calif;
    }

    std::string nombre() const;
    int edad();
    unsigned int boleta();
    float calif();
    void setNombre(const std::string&);
    void setEdad(const int&);
    void setBoleta(const unsigned int&);
    void setCalif(const float&);
    bool operator <(Alumno al) const
    {
        return (this->nombre() < al.nombre() ? true : false);
    }
    bool operator >(Alumno al) const
    {
        return (this->nombre() > al.nombre() ? true : false);
    }
    bool operator <=(Alumno al) const
    {
        return (this->nombre() <= al.nombre() ? true : false);
    }
    bool operator !=(Alumno al) const
    {
        return (this->nombre() != al.nombre() ? true : false);
    }
};

#endif // ALUMNO_H
