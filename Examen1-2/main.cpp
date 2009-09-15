#include <iostream>
using namespace std;

void invierte(char);
int main()
{
    cout<<"Ingrese los caracteres que desee:\n";
    invierte(cin.get());
    return 0;
}

void invierte(char c)
{
    if(c == '\n')
        cout<<c;
    else
        invierte(cin.get());
}
