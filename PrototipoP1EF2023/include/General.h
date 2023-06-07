#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>
using namespace std;

class General
{
    public:
        void menuGeneral(string n);
        void catalogos();
        void procesos();
        void informes();
    private:
        string nombre;
};

#endif // GENERAL_H
