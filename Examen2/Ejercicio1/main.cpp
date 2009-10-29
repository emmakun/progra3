#include "BSTree"
#include "suffix.h"
#include "stack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void printTreeElement(char&);
string reverseString(string&);
void procesa(string&);
void construyeArbol(BSTree<char>&, Stack<char>&);
bool isOperator(const char&);

int main()
{
    system("clear");
    cout<<"\tIntroduce una expresion en notacion infija:\n\t";
    char charStr[100];
    cin.get(charStr, 100);
    string str = charStr;
    str = Suffix::fromInterfix(str);
    cout<<endl<<endl;
    procesa(str);
    cout<<endl;
    return 0;
}

void printTreeElement(char& item)
{
    cout<<item;
}

string reverseString(string& str)
{
    string value;
    for(int i=str.length()-1;i>=0;i--)
    {
        value += str[i];
    }

    return value;
}

void procesa(string& str)
{
    Stack<char> stack(100);
    for(unsigned int i=0;i<str.length();i++)
        stack.push(str[i]);

    BSTree<char> tree;

    construyeArbol(tree, stack);

    cout<<"El recorrido del arbol en preOrden es:"<<endl;
    tree.preOrder(&printTreeElement);

    cout<<endl<<endl<<"Introduzca el nivel del arbol que quiere imprimir: ";
    int level = 0;
    cin>>level;

    tree.imprimeNivel(level);

//    cout<<"El recorrido del arbol en preOrden es:"<<endl;
//    tree.preOrder(&printTreeElement);
//
//    cout<<endl<<endl<<"El recorrido del arbol en inOrden es:"<<endl;
//    tree.inOrder(&printTreeElement);
//
//    cout<<endl<<endl<<"El recorrido del arbol en postOrden es:"<<endl;
//    tree.postOrder(&printTreeElement);
}

void construyeArbol(BSTree<char>& tree, Stack<char>& stack)
{
    if(!stack.empty())
    {
        if(isOperator(stack.getTop()))
        {
            if(tree.insertRight(stack.getTop()) || tree.insertLeft(stack.getTop()))
            {
                stack.pop();
            }
            else
            {
                tree.goToParent();
            }

            construyeArbol(tree, stack);
        }

        else
        {
            if(tree.insertRight(stack.getTop()) || tree.insertLeft(stack.getTop()))
            {
                stack.pop();
            }

            tree.goToParent();
            construyeArbol(tree, stack);
        }

    }
}

bool isOperator(const char& chr)
{
    if(chr == '+' || chr == '-' || chr == '*' || chr == '/')
        return true;
    else
        return false;
}
