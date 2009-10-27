#include "suffix.h"
#include "stack.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
/******************************************************************
  Biblioteca set con un ADT que representa un conjunto con sus ope-
  raciones de unión e itersección.
  Creado por:
  Cerón Blanco Monserrat
  Valle Vieyra Alvaro Emmanuel
******************************************************************/

//using namespace std;
//Constructor
Suffix::Suffix()
{
}
//Función que verifica precedencia de operadores.
bool Suffix::precedence(char op1, char op2)
{
    int value1=2, value2=2;

    if(op1 == '+' || op1 == '-')
        value1=1;

    if(op2 == '+' || op2 == '-')
        value2=1;

    return value1 < value2 ? false : true;
}
//Función que recibe una cadena en notacion interfija y devuelve una en notación sufija.
string Suffix::fromInterfix(string& str)
{
    Stack<char> stack(100);
    string suffixStr;
    char symbol;

    for(unsigned int i=0;i<str.size();i++)
    {
        symbol = str[i];

        if(isalnum(symbol))    //si es operador...
        {
            suffixStr += symbol;
        }
        else if(symbol == '(')
            stack.push(symbol);
        else if(symbol == ')')
        {
            while(stack.getTop() != '(')
                suffixStr += stack.pop();

            stack.pop();  //saca el parentesis que abre...
        }
        else
        {
            while(!stack.empty() && (stack.getTop() != '(') && precedence(stack.getTop(), symbol))
            {
                suffixStr += stack.pop();
            }
            stack.push(symbol);
        }
    }
    while(!stack.empty())
    {
        suffixStr += stack.pop();
    }

    return suffixStr;
}
//Función que devuelve el valor que resulta de evaluar una cadena en notación sufija.
double Suffix::evaluate(string& str)
{
    Stack<int> stack(100);
    const char* suffixStr = str.c_str();
    char symbol;

    for(unsigned int i=0;i<str.size();i++)
    {
        symbol = suffixStr[i];

        if(isdigit(symbol))
        {
            char c[1];
            c[0] = symbol;
            int symbInt = atoi(c);
            stack.push(symbInt);
        }
        else
        {
            switch(symbol)
            {
                case '+':
                stack.push(stack.pop() + stack.pop());
                break;
                case '-':
                stack.push(stack.pop() - stack.pop());
                break;
                case '*':
                stack.push(stack.pop() * stack.pop());
                break;
                case '/':
                stack.push(stack.pop() / stack.pop());
                break;
            }
        }
    }

    return stack.pop();
}
