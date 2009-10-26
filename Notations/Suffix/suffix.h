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
    static bool precedence(char, char);
public:
    Suffix();
    static std::string fromInterfix(std::string&);
    static double evaluate(std::string&);
};

#endif // SUFFIX_H
