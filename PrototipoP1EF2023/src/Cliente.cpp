#include "Cliente.h"
#include "Bitacora.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
using namespace std;
Bitacora llamarBitacora4;
int monto = 30;
void Cliente::menu(string n)
{
    nombre2 = n;
    int choice;
	do
    {
	system("cls");
    cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	cout<<"\t\t\t---------------------------"<<endl;
	cout<<"\t\t\t |   CRUD CLIENTE - 1200  |"<<endl;
	cout<<"\t\t\t---------------------------"<<endl;
	cout<<"\t\t\t 1. Despliegue Cliente"<<endl;
	cout<<"\t\t\t 2. Modificar aplicacion"<<endl;
	cout<<"\t\t\t 3. Buscar aplicacion"<<endl;
	cout<<"\t\t\t 4. Borrar aplicacion"<<endl;
	cout<<"\t\t\t 5. Regresar a menu anterior"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
	case 1:
		llamarBitacora4.ingresoBitacora(nombre2,"1200", "REA");
		desplegar();
		break;
	case 2:
		llamarBitacora4.ingresoBitacora(nombre2,"1200", "UPD");
		modificar();
		break;
	case 3:
		llamarBitacora4.ingresoBitacora(nombre2,"1200", "SEA");
		buscar();
		break;
	case 4:
		llamarBitacora4.ingresoBitacora(nombre2,"1200", "DEL");
		borrar();
		break;
	case 5:
		return;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 5);
}
void Cliente::insertar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file;
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles de la compra ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa numero de boleto         : ";
	cin>>boleto;
	cout<<"\t\t\tIngresa nombre del cliente       : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa numero de cartelera      : ";
	cin>>cartelera;
	cout<<"\t\t\tIngresa la cantidad de boletos   : ";
	cin>>cantidad;
	compra = cantidad * monto;
	cout<<"\t\t\tCompra: " << compra << endl;
	cout<<"\t\t\tIngresa la fecha de reservación  : ";
	cin>>reserva;
	file.open("Clientes.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< boleto <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< cartelera <<std::left<<std::setw(15)<< cantidad <<std::left<<std::setw(15)<< compra <<std::left<<std::setw(15)<< reserva << "\n";
	file.close();
}
void Cliente::desplegar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles del Cliente -------------------------"<<endl;
	file.open("Clientes.txt",ios::in);
	cout<<"\n\n\tBoleto\tNombre\tCartelera\tCantidad\tCompra\tReserva\n\n";
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> boleto >> nombre >> cartelera >> cantidad >> compra >> reserva;
		while(!file.eof())
		{
			total++;
			cout<<"\t"<<boleto<<"\t"<<nombre<<"\t"<<cartelera<<"\t\t"<<cantidad<<"\t\t"<<compra<<"\t"<<reserva<<endl;
			file >> boleto >> nombre >> cartelera >> cantidad >> compra >> reserva;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
	system("pause");
}
void Cliente::modificar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles de un Cliente-------------------------"<<endl;
	file.open("Clientes.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese boleto del cliente que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> boleto >> nombre >> cartelera >> cantidad >> compra >> reserva;
		while(!file.eof())
		{
			if(participant_id!=boleto)
			{
			 file1<<std::left<<std::setw(15)<< boleto <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< cartelera <<std::left<<std::setw(15)<< cantidad <<std::left<<std::setw(15)<< compra <<std::left<<std::setw(15)<< reserva << "\n";
			}
			else
			{
				cout<<"\t\t\tNumero de Boleto: "<<boleto<<endl;
				cout<<"\t\t\tIngrese Nombre del cliente: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese la cartelera: ";
				cin>>cartelera;
				cout<<"\t\t\tIngrese la cantidad: ";
				cin>>cantidad;
				compra = cantidad * monto;
				cout<<"\t\t\tCompra: " << compra<<endl;
				cout<<"\t\t\tIngrese fecha de reservación: ";
				cin>>reserva;
				file1<<std::left<<std::setw(15)<< boleto <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< cartelera <<std::left<<std::setw(15)<< cantidad <<std::left<<std::setw(15)<< compra <<std::left<<std::setw(15)<< reserva << "\n";
				found++;
			}
			file >> boleto >> nombre >> cartelera >> cantidad >> compra >> reserva;

		}
		file1.close();
		file.close();
		remove("Clientes.txt");
		rename("Record.txt","Clientes.txt");
	}
}
void Cliente::buscar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file;
	int found=0;
	file.open("Clientes.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Cleinte buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del Cliente buscado------------------------"<<endl;
		cout<<"\nIngrese el boleto del cliente que quiere buscar: ";
		cin>>participant_id;
		file >> boleto >> nombre >> cartelera >> cantidad >> compra >> reserva;
		while(!file.eof())
		{
			if(participant_id==boleto)
			{
				cout<<"\n\n\t\t\t Boleto: "<<boleto<<endl;
				cout<<"\t\t\t Nombre: "<<nombre<<endl;
				cout<<"\t\t\t Cartelera: "<<cartelera<<endl;
				cout<<"\t\t\t Cantidad: "<<cantidad<<endl;
				cout<<"\t\t\t Compra: "<<compra<<endl;
				cout<<"\t\t\t Reserva: "<<reserva<<endl;
				found++;
			}
			file >> boleto >> nombre >> cartelera >> cantidad >> compra >> reserva;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Cleinte no encontrado...";
		}
		file.close();
	}
}
void Cliente::borrar()
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles del Cleinte a Borrar-------------------------"<<endl;
	file.open("Clientes.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el boleto del cliente que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> boleto >> nombre >> cartelera >> cantidad >> compra >> reserva;
		while(!file.eof())
		{
			if(participant_id!=boleto)
			{
				file1<<std::left<<std::setw(15)<< boleto <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< cartelera <<std::left<<std::setw(15)<< cantidad <<std::left<<std::setw(15)<< compra <<std::left<<std::setw(15)<< reserva << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de cliente exitoso";
			}
			file >> boleto >> nombre >> cartelera >> cantidad >> compra >> reserva;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Cliente no encontrado...";
		}
		file1.close();
		file.close();
		remove("Clientes.txt");
		rename("Record.txt","Clientes.txt");
	}
	system("pause");
}



