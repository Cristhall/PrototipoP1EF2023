#include "General.h"
#include "Bitacora.h"
#include "Usuario.h"
#include "Cliente.h"
#include <iostream>
#include <iomanip>
using namespace std;
Bitacora llamarBitacora2;
Usuario ingresoUsuario;
Cliente consulta;

void General::menuGeneral(string n)
{
    system("cls");
    int choice1;
    nombre = n;
	do
    {
	system("cls");
	cout <<"\n\t\t\t Alumna: Cristhall Mishell Rodríguez Ortiz" << endl;
	cout <<"\t\t\t Carne: 9959 22 8588" << endl;
	cout <<"\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1). Catalogos "<<endl;
	cout<<"\t\t\t 2). Procesos"<<endl;
	cout<<"\t\t\t 3). Informes"<<endl;
	cout<<"\t\t\t 4). LOG OUT"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger: 1-2-3-4 "<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice1;

    switch(choice1)
    {
    case 1:
        catalogos();
		break;
	case 2:
	    procesos();
		break;
	case 3:
	    informes();
		break;
    case 4:
		return;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
	system("cls");
    }while(choice1!= 4);
}
void General::catalogos()
{
    int choice;
    do {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t----------------------"<<endl;
	cout<<"\t\t\t |   CATALOGOS - 800 |"<<endl;
	cout<<"\t\t\t----------------------"<<endl;
	cout<<"\t\t\t 1. Usuarios "<<endl;
	cout<<"\t\t\t 2. Clientes "<<endl; //No existe el ingreso, eso se hace en el área de procesos.
	cout<<"\t\t\t 3. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger: 1-2-3 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                ingresoUsuario.menuSecundario();
                break;
            case 2:
                consulta.menu(nombre);
                break;
            case 3:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!=3);
}
void General::procesos()
{
    int choice;
    char x;
    do {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t------------------------"<<endl;
	cout<<"\t\t\t |   PROCESOS  -  900  |"<<endl;
	cout<<"\t\t\t------------------------"<<endl;
	cout<<"\t\t\t 1. Venta de Boletos "<<endl;
	cout<<"\t\t\t 2. Bitacora "<<endl;
	cout<<"\t\t\t 3. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger: 1-2-3-4 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                do
                {
                    llamarBitacora2.ingresoBitacora(nombre,"900", "INS");
                    consulta.insertar();
                    cout<<"\n\t\t\t Agregar otra compra(Y,N): ";
                    cin>>x;
                }while(x=='y'||x=='Y');
                break;
            case 2:
                llamarBitacora2.ingresoBitacora(nombre,"900", "REA");
                llamarBitacora2.visualizarBitacora(nombre);
                break;
            case 3:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 3);
}
void General::informes()
{
    int choice;
    do {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t------------------------"<<endl;
	cout<<"\t\t\t |   INFORMES  -  1000 |"<<endl;
	cout<<"\t\t\t------------------------"<<endl;
	cout<<"\t\t\t 1. Bitacora "<<endl;
	cout<<"\t\t\t 2. Usuarios "<<endl;
	cout<<"\t\t\t 3. Clientes "<<endl;
	cout<<"\t\t\t 4. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger: 1-2-3-4 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                llamarBitacora2.ingresoBitacora(nombre,"1000", "REA");
                llamarBitacora2.visualizarBitacora(nombre);
                break;
            case 2:
                llamarBitacora2.ingresoBitacora(nombre,"1000", "REA");
                ingresoUsuario.desplegar();
                break;
            case 3:
                llamarBitacora2.ingresoBitacora(nombre,"1000", "REA");
                consulta.desplegar();
                break;
            case 4:
                return;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!=4);
}
