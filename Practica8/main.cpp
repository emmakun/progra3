#include <iostream>
#include <fstream>
#include <sstream>
#include "yaml.h"
#include "BSTree"
#include "alumno.h"

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

bool writeYaml(BSTree<Alumno>&);
void writeStudent(Alumno&, YAML::Emitter&);
void readYaml(BSTree<Alumno>&);

void operator >> (const YAML::Node& node, Alumno& s)
{
    string name, age, reg, grade;

    node["name"] >> name;
    node["age"] >> age;
    node["registration"] >> reg;
    node["grade"] >> grade;

    s.setNombre(name);
    s.setEdad(Converter<string>::toInt(age));
    s.setBoleta(Converter<string>::toUInt(reg));
    s.setCalif(Converter<string>::toFloat(grade));
}


int main(int argc, char *argv[])
{
    argc = 2;
    argv[1] = "insert";
    if(argc > 1)
    {
        string action = argv[1];

        if(action == "search")
        {
            if(argc == 3)
            {

            }
            else
            {
                cout<<"Erroneous number of arguments..."<<endl<<endl;
                cout<<"Use: Practica8 search <Student's Name>"<<endl;
                cout<<"     Practica8 insert"<<endl;
                cout<<"     Practica8 delete <Student's Name>"<<endl;
            }
        }
        else if(action == "insert")
        {
            if(argc == 2)
            {
//                char namechr[100];
//                cout<<"\n\tName: ";
//                cin.getline(namechr,100);
//                string name = namechr;
//                int age;
//                cout<<"\n\tAge: ";
//                cin>>age;
//                unsigned int reg;
//                cout<<"\n\tRegistration Number: ";
//                cin>>reg;
//                float grade;
//                cout<<"\n\tGrade: ";
//                cin>>grade;
//
//                Alumno nuevo(name,age,reg,grade);

                Alumno nuevo;
                nuevo.setNombre("Daniel Valle");
                nuevo.setEdad(40);
                nuevo.setBoleta(245574);
                nuevo.setCalif(4);

                BSTree<Alumno> arbol;
                readYaml(arbol);
                arbol.insert(nuevo);

                if(writeYaml(arbol))
                    cout<<"\nThe Student's info was written successfully :)..."<<endl<<endl;
                else
                    cout<<"\nSorry, there were some problems :S..."<<endl<<endl;
            }
            else
            {
                cout<<"Erroneous number of arguments..."<<endl<<endl;
                cout<<"Use: Practica8 search <Student's Name>"<<endl;
                cout<<"     Practica8 insert"<<endl;
                cout<<"     Practica8 delete <Student's Name>"<<endl;
            }
        }
        else if(action == "delete")
        {
            if(argc == 3)
            {
            }
            else
            {
                cout<<"Erroneous number of arguments..."<<endl<<endl;
                cout<<"Use: Practica8 search <Student's Name>"<<endl;
                cout<<"     Practica8 insert"<<endl;
                cout<<"     Practica8 delete <Student's Name>"<<endl;
            }
        }
        else
        {
            cout<<"Error: Unknown option..."<<endl<<endl;
            cout<<"Use: Practica8 search <Student's Name>"<<endl;
            cout<<"     Practica8 insert"<<endl;
            cout<<"     Practica8 delete <Student's Name>"<<endl;
        }
    }
    else
    {
        cout<<"Use: Practica8 search <Student's Name>"<<endl;
        cout<<"     Practica8 insert"<<endl;
        cout<<"     Practica8 delete <Student's Name>"<<endl;
    }
    return 0;
}

bool writeYaml(BSTree<Alumno>& tree)
{
    YAML::Emitter out;

    out<<YAML::BeginSeq;
        tree.inOrder(&writeStudent, out);
    out<<YAML::EndSeq;

    ofstream fs("students.yml");
    fs<<out.c_str();
    fs.close();

    return true;
}

void writeStudent(Alumno& s, YAML::Emitter& out)
{
    out<<YAML::BeginMap;
        out<<YAML::Key<<"name";
        out<<YAML::Value<<s.nombre();
        out<<YAML::Key<<"registration";
        out<<YAML::Value<<Converter<unsigned int>::toString(s.boleta());
        out<<YAML::Key<<"age";
        out<<YAML::Value<<Converter<int>::toString(s.edad());
        out<<YAML::Key<<"grade";
        out<<YAML::Value<<Converter<float>::toString(s.calif());
    out<<YAML::EndMap;
}

void readYaml(BSTree<Alumno>& tree)
{
    ifstream fin("students.yml");
    YAML::Parser parser(fin);
    YAML::Node doc;
    parser.GetNextDocument(doc);

    for(unsigned i=0;i<doc.size();i++)
    {
        Alumno student;
        doc[i] >> student;
        tree.insert(student);
    }
    fin.close();
}
