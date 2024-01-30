#ifndef CLASEGENERO_H_INCLUDED
#define CLASEGENERO_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <conio.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>

int validarRango(int, int, int&);

class Genero{
private://EL SER
    int id=1;
    char nombre[30];
    int paisOrigen;
    int annioDeOrigen;
    bool estado;
public:
    Genero(bool estado = true ){};//ACCIONES DEL SER
    //metodos cargar y mostrar
    void agregarGenero();
    void mostrarGenero();
    //sets
    void setID(int d){id = d;}
    void setNombre(char *n){strcpy(nombre, n);}
    void setPaisOrigen(int pais){paisOrigen = pais;}
    void setAnnioDeOrigen(int annio){annioDeOrigen = annio;}
    void setEstado(bool e){estado = e;}
    void setContadorID(int _id){
    id+=_id;};
    //gets
    int getID(){return id;};

    int getNombre(){return *(nombre);};
    int getPaisOrigen(){return paisOrigen;};
    int getAnnioDeOrigen(){return annioDeOrigen;};
    bool getEstado(){return estado;};

};

void Genero::agregarGenero(){
    fflush(stdin);
    cout<<"Ingrese nombre: ";cin.getline(nombre, 30, '\n');
    fflush(stdin);
    cout<<"Ingrese codigo de pais: ";cin>>paisOrigen;
    paisOrigen = validarRango(1, 100, paisOrigen);
    cout<<"Ingrese Annio de origen: ";cin>>annioDeOrigen;
    annioDeOrigen = validarRango(1500, 2023, annioDeOrigen);
    estado=true;
}

void Genero::mostrarGenero(){
    cout<<"ID: "<<id<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Codigo de pais: "<<paisOrigen<<endl;
    cout<<"Annio de origen: "<<annioDeOrigen<<endl;
    //cout<<"Estado: "<<estado<<endl;
    cout<<endl;
}

#endif // CLASEGENERO_H_INCLUDED
