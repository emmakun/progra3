#include "BSTree"
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Converter
{
    Converter()
    {
    }
    ~Converter()
    {
    }

    public:

    static string toString(const T& data)
    {
        stringstream flow;
        flow << data;
        return flow.str();
    }

    static int toInt(const T& data)
    {
        int i;
        istringstream myflow(data);
        myflow >> i;
        return i;
    }

    static unsigned int toUInt(const T& data)
    {
        unsigned int i;
        istringstream myflow(data);
        myflow >> i;
        return i;
    }

    static float toFloat(const T& data)
    {
        float f;
        istringstream myflow(data);
        myflow >> f;
        return f;
    }
};

void permutaciones(vector<int> cad, vector<string>& list, int l=0);
void construyePreorden(int&, string&);
bool contieneCadena(vector<string>&, string);

int main(int argc, char *argv[])
{
    string arg = argv[1];

    int value = Converter<string>::toInt(arg);

    vector<string> lista;
    vector<int> nums;

    for(int i=1;i<=value;i++)
        nums.push_back(i);

    permutaciones(nums, lista);

    for(unsigned i=0;i<lista.size();i++)
        cout<<lista[i]<<endl;

    return 0;
}


void permutaciones(vector<int> cad, vector< string >& list, int l) {
   int c;
   int n = cad.size();

   for(int i = 0; i < n-l; i++)
   {
      if(n-l > 2)
          permutaciones(cad, list, l+1);
      else
      {
          BSTree<int> arbol;

          for(unsigned k=0;k<cad.size();k++)
          {
              arbol.insert(cad[k]);
          }

          string str;
          arbol.preOrder(construyePreorden, str);

          if(!contieneCadena(list,str))
              list.push_back(str);
      }

      c = cad[l];
      cad[l] = cad[l+i+1];
      cad[l+i+1] = c;
      if(l+i == n-1)
      {
         for(int j = l; j < n; j++)
             cad[j] = cad[j+1];
      }
   }
}

void construyePreorden(int& i, string& cadena)
{
    cadena += Converter<int>::toString(i) + " ";
}

bool contieneCadena(vector<string>& list, string cad)
{
    bool value = false;

    for(unsigned i=0;i<list.size();i++)
    {
        if(list[i] == cad)
        {
            value = true;
            break;
        }
    }

    return value;
}
