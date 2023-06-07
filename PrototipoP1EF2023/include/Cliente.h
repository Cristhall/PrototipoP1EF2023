#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using namespace std;

class Cliente
{
    public:
        void menu(string n);
        void insertar();
        void desplegar();
		void modificar();
		void buscar();
		void borrar();
    private:
        string nombre2;
        string boleto, nombre, cartelera, reserva;
        int cantidad, compra;
};

#endif // CLIENTE_H
