#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using namespace std;

class Usuario
{
	private:
		string nombre, contrasena;
	public:
		void iniciarSesion();
		void menuSecundario();
		void insertar();
		void desplegar();
		void borrar();
		void modificar();
		void buscar();

};

#endif // USUARIO_H
