#ifndef ARCHIVOGENERO_H_INCLUDED
#define ARCHIVOGENERO_H_INCLUDED

#include "claseGenero.h"
#include "menuGenero.h"

class ArchivoGenero{
private:
    char nombre[25];
public:
    ArchivoGenero(const char *n){strcpy(nombre, n);}

    int cargarArchivo();
    int cantRegistros();
    Genero leerRegistros(int pos);
    int mostrarArchivos();
    Genero listarPorID(int nroId);
    int mostrarPorID();
    int modificarAnnio();
    int bajaLogica();
    int PosPorID(int nroId);
    bool Gbackup();
    bool Grestaurar();
    bool GrestaurarDATINI();
    bool cargarArchivoINI();
    int cantidadDeGenerosPorPais();
};

int ArchivoGenero::cargarArchivo(){
    Genero obj;
    FILE *pGenero;
    pGenero = fopen(nombre, "ab");
    if(pGenero==NULL){
        cout<<"ERROR - NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return -1;
    }else{
        obj.setContadorID(cantRegistros());
        obj.agregarGenero();
        fwrite(&obj, sizeof obj, 1, pGenero);
    }
    fclose(pGenero);
    return 1;
}

int ArchivoGenero::cantRegistros(){//Devuelve la cantidad de registros en un entero
    int tam = 0;
    FILE *pGenero;
    pGenero = fopen(nombre, "rb");
    if(pGenero==NULL){return -1;}
    else{
    fseek(pGenero, 0, 2);
    tam=ftell(pGenero);
    return tam/sizeof(Genero);
    }
}


Genero ArchivoGenero::leerRegistros(int pos){//Lee todos los registros que se encuentran en el archivo
    Genero obj;
    FILE *pArchivo;
    pArchivo = fopen(nombre, "rb");
    if(pArchivo==NULL){
        cout<<"ERROR - NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        obj.setID(-2);
        return obj;
    }else{
        fseek(pArchivo, sizeof obj * pos, 0);
        fread(&obj, sizeof obj, 1, pArchivo);
        fclose(pArchivo);
        return obj;
    }
}

int ArchivoGenero::mostrarArchivos(){//Si no hay registros para mostrar, emitir una leyenda
    Genero obj;
    FILE *pArchivo;
    pArchivo = fopen(nombre, "rb");
    int cantReg = cantRegistros();
    if(pArchivo==NULL){
        cout<<"ERROR - NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        getch();
        return -1;
    }if(cantReg == 0){
        cout<<"ERROR - NO HAY REGISTROS PARA MOSTRAR"<<endl;
        getch();
        return -2;
    }else{
        for(int i=0;i<cantReg;i++){
            obj=leerRegistros(i);
            if(obj.getID()!=-2&&obj.getEstado()){
            obj.mostrarGenero();
            }
        }
        return 1;
    }
    getch();
    fclose(pArchivo);
}

Genero ArchivoGenero::listarPorID(int nroId){//buscar de acuerdo al id
    bool bandera=false;
    Genero obj;
    FILE *pArchivo;
    pArchivo = fopen(nombre, "rb");
    int cantReg = cantRegistros(), i;
    if(pArchivo==NULL){//nose pudo abrir con -1
    obj.setID(-1);
    return obj;}
    else{

        for(i=0;i<cantReg;i++){
                obj=leerRegistros(i);
                if(obj.getID()==nroId&&obj.getEstado()==true){
                getch();
                fclose(pArchivo);
                bandera=true;
            return obj;
                }
            }
            if(bandera == false){//no se encontro un id
            obj.setID(-2);
            fclose(pArchivo);
            return obj;
        }
    }
    return -3;
}

int ArchivoGenero::mostrarPorID(){
    Genero obj;
   // obj.setID(-2);
    int id;
    cout<<"Ingrese el ID a buscar: ";cin>>id;
    obj=listarPorID(id);
    if(obj.getID()== -2){
            cout<<"No se encontro el registro id "<<id<<endl;
            getch();
            return -1;
    }else if(obj.getEstado()){
    obj.mostrarGenero();
    getch();
    }
    return -3;
}

int ArchivoGenero::modificarAnnio(){
    Genero obj;
    FILE *pArchivo;
    pArchivo = fopen(nombre, "rb+");
    if(pArchivo==NULL){return -2;}
    else{
    int id, nuevoAnnio;
    cout<<"Ingrese el id a buscar: ";
    cin>>id;
    obj=listarPorID(id);
    if(obj.getID()!=-2){
    cout<<"Ingrese el annio a modificar: ";cin>>nuevoAnnio;
    obj.setAnnioDeOrigen(nuevoAnnio);
    int pos=PosPorID(id);
    fseek(pArchivo,sizeof obj*pos,0);
    fwrite(&obj, sizeof obj, 1, pArchivo);
    fclose(pArchivo);
    return 1;
    }else {cout<<"no se encontro registro con ese id"<<endl;system("pause");}
    fclose(pArchivo);
    return -2;
    }
}

int ArchivoGenero::bajaLogica(){
    Genero obj;
    FILE *pArchivo;
    pArchivo = fopen(nombre, "rb+");
    int id, pos;
    if(pArchivo==NULL){
        cout<<"ERROR - NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        getch();
        return -1;
    }else{
    cout<<"Ingrese el ID a borrar: ";cin>>id;
    obj = listarPorID(id);
    pos = PosPorID(id);
    obj.setEstado(false);
    fseek(pArchivo, sizeof obj * pos, 0);
    fwrite(&obj, sizeof obj, 1, pArchivo);
    cout<<"ID BORADO"<<endl;
    getch();
    fclose(pArchivo);
    }
    return -4;
}

int ArchivoGenero::PosPorID(int nroId){//buscar de acuerdo al id
    bool bandera=false;
    Genero obj;
    FILE *pArchivo;
    pArchivo = fopen(nombre, "rb");
    int cantReg = cantRegistros(), i;
    if(pArchivo==NULL){return -1;}
    else{

       for(i=0;i<cantReg;i++){
                obj=leerRegistros(i);
               if(obj.getID()==nroId&&obj.getEstado()==true){
                getch();
                fclose(pArchivo);
                bandera=true;
            return i;
                }
            }
            if(bandera == false){
             obj.setID(-2);
            fclose(pArchivo);
            return -2;
        }
    }
    return -5;
}

bool ArchivoGenero::Gbackup(){
    Genero obj;
    FILE *pGen, *pbkp;
    pGen=fopen(nombre, "rb");
    if(pGen==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    pbkp=fopen("Genero.bkp", "wb");
    if(pbkp==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pGen);
        return false;
    }

	while(fread(&obj, sizeof obj, 1, pGen)==1){
        fwrite(&obj, sizeof obj, 1, pbkp);
	}
	fclose(pbkp);
	fclose(pGen);
	return true;
}

bool ArchivoGenero::Grestaurar(){
    Genero obj;
    FILE *pGen, *pbkp;
    pbkp=fopen("Genero.bkp", "rb");
    if(pbkp==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    pGen=fopen(nombre, "wb");
    if(pGen==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pGen);
        return false;
    }

	while(fread(&obj, sizeof obj, 1, pbkp)==1){
        fwrite(&obj, sizeof obj, 1, pGen);
	}
	fclose(pGen);
	fclose(pbkp);
	return true;
}
bool ArchivoGenero::GrestaurarDATINI(){
    Genero obj;
    FILE *pGen, *pIni;
    pIni=fopen("Genero.ini", "rb");
    if(pIni==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    pGen=fopen(nombre, "wb");
    if(pGen==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pGen);
        return false;
    }

	while(fread(&obj, sizeof obj, 1, pIni)==1){
        fwrite(&obj, sizeof obj, 1, pGen);
	}
	fclose(pGen);
	fclose(pIni);
	return true;
}
bool ArchivoGenero::cargarArchivoINI(){
    Genero obj;
    FILE *pGenero;
    pGenero = fopen("Genero.ini", "ab");
    if(pGenero==NULL){
        cout<<"ERROR - NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }else{
        obj.agregarGenero();
        fwrite(&obj, sizeof obj, 1, pGenero);
    }
    fclose(pGenero);
    return true;
}


#endif // ARCHIVOGENERO_H_INCLUDED
