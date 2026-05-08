#ifndef USUARIOS_H
#define USUARIOS_H
#include<iostream>

using std::string;

class usuarios
{
    public:
        usuarios();
        virtual ~usuarios();
        bool loginUsuarios();
        void menuUsuarios();
        bool buscar(string user, string passw);
        string getNombre();
        string setNombre(string nombre);

    protected:

    private:
		string id;
		string name;
		string pass;

};

#endif // USUARIOS_H
