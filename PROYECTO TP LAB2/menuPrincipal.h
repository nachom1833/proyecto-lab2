#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include "funcionesAdicionales.h"

int menuPrincipal(){
    int x=49, y=7;
    while(true){
        rlutil::hidecursor();
        rlutil::locate(x, y);
        cout<<char(175);
        rlutil::locate(50, 5);
        cout<<"     MENU PRINCIPAL     "<<endl;
        rlutil::locate(50, 6);
        cout<<" -----------------------"<<endl;
        rlutil::locate(50, 7);
        cout<<"      MENU MUSICOS      "<<endl;//opc 7
        rlutil::locate(50, 8);
        cout<<"      MENU GENEROS      "<<endl;//opc 8
        rlutil::locate(50, 9);
        cout<<"      MENU REPORTES     "<<endl;//opc 9
        rlutil::locate(50, 10);
        cout<<"   MENU CONFIGURACION   "<<endl;//opc 10
        rlutil::locate(50, 11);
        cout<<"   SALIR DEL PROGRAMA   "<<endl;//opc 11
            //tecla 75 es izquierda
            //tecla 77 es derecha
            //tecla 72 es arriba
            //tecla 80 es abajo
            //tecla 1 es enter
            //tecla 0 es escape

        rlutil::anykey();
        int tecla = rlutil::getkey();
            switch(tecla){
            case 72://arriba
                if(y<=7){y=7;}else{y--;}
                rlutil::locate(x,(y+1));
                cout<<" ";
                break;
            case 80://abajo
                if(y>=10){y=11;}else{y++;}
                rlutil::locate(x,(y-1));
                cout<<" ";
                break;
            case 1:
                switch(y){
                case 7:
                    MenuMusicos();
                break;
                case 8:
                    menuGenero();
                break;
                case 9:
                    MenuReportes();
                break;
                case 10:
                    MenuConfiguracion();
                break;
                case 11:
                    rlutil::cls();
                    return 0;
                break;
            }
        }
    }
}



#endif // MENUPRINCIPAL_H_INCLUDED
