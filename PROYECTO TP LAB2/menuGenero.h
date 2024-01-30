#ifndef MENUGENERO_H_INCLUDED
#define MENUGENERO_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <conio.h>
#include <string.h>
#include <cstdlib>

using namespace std;

const char *GENEROS_MUSICALES = "generosMusicales.dat";

#include "claseGenero.h"
#include "archivoGenero.h"

int menuGenero(){
    int x=49, y=7;
    rlutil::cls();
    ArchivoGenero objGenero(GENEROS_MUSICALES);
    while(true){
        rlutil::hidecursor();
        rlutil::locate(x, y);
        cout<<char(175);
        rlutil::locate(50, 5);
        cout<<"         MENU GENEROS         "<<endl;
        rlutil::locate(50, 6);
        cout<<"------------------------------"<<endl;
        rlutil::locate(50, 7);
        cout<<"        AGREGAR GENERO        "<<endl;
        rlutil::locate(50, 8);
        cout<<"     LISTAR GENERO POR ID     "<<endl;
        rlutil::locate(50, 9);
        cout<<"         LISTAR TODO          "<<endl;
        rlutil::locate(50, 10);
        cout<<" MODIFICAR ANNIO DE ORIGEN    "<<endl;
        rlutil::locate(50, 11);
        cout<<"       ELIMINAR REGISTRO      "<<endl;
        rlutil::locate(50, 12);
        cout<<"     VOLVER AL MENU ANTERIOR  "<<endl;
        rlutil::anykey();
        int tecla = rlutil::getkey();
        switch(tecla){
            case 72://arriba
                if(y<=7){y=7;}else{y--;}
                rlutil::locate(x,(y+1));
                cout<<" ";
                break;
            case 80://abajo
                if(y>=11){y=12;}else{y++;}
                rlutil::locate(x,(y-1));
                cout<<" ";
                break;
            case 1:
                switch(y){
                case 7:
                    //llamado a la funcion agregar genero
                    rlutil::cls();
                    objGenero.cargarArchivo();
                break;
                case 8:
                    //llamado a la funcion listar por genero id
                    rlutil::cls();
                    objGenero.mostrarPorID();
                    getch();
                    rlutil::cls();
                break;
                case 9:
                    //llamado a la funcion listar todo
                    rlutil::cls();
                    objGenero.mostrarArchivos();
                    getch();
                break;
                case 10:
                    //llamado a la funcion modificar anio de origen
                    rlutil::cls();
                    objGenero.modificarAnnio();
                    getch();
                    rlutil::cls();
                break;
                case 11:
                    //llamado a la funcion eliminar registro
                   rlutil::cls();
                   objGenero.bajaLogica();
                break;
                case 12:
                    rlutil::cls();
                    return 0;
                break;
            }
        }
    }
}

#endif // MENUGENERO_H_INCLUDED
