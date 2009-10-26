#ifndef SUFFIX_H
#define SUFFIX_H
/******************************************************************
  Biblioteca suffix.
  Creado por:
  Cerón Blanco Monserrat
  Valle Vieyra Alvaro Emmanuel
******************************************************************/

#include <iostream>
//Definición de la clase Suffix
class Suffix {
public:
    Suffix();
    bool precedence(char, char);
    std::string fromInterfix(std::string&);
    double evaluate(std::string&) const;
};

#endif // SUFFIX_H
