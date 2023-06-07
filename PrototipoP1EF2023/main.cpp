//Nombre: Cristhall Mishell Rodríguez Ortiz
//Carné: 9959 22 8588
//Carrera: Ingeniería en Sistemas
//Curso: Programación 1

#include <iostream>
#include "Usuario.h"

using namespace std;

int main()
{
    Usuario inicio;
    int numero;
    do
    {
    system("cls");
    cout<<"\n\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL   |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\t 1). Iniciar Sesion "<<endl;
	cout<<"\t\t\t 2). Salir del Sistema"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<< " "<<endl;
	cout<<"\t\t\tIngrese Opcion: ";
	cin>>numero;

        switch(numero)
        {
            case 1:
                inicio.iniciarSesion();
                break;
            case 2:
                break;
            default:
                cout<<"\t\t\tIngrese opcion valida"<<endl;
                cin.get();
        }
    } while(numero!=2);
    return 0;
}
