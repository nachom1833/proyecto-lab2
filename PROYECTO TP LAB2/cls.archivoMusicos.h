#ifndef CLS_ARCHIVOMUSICOS_H_INCLUDED
#define CLS_ARCHIVOMUSICOS_H_INCLUDED

#include "conio.h"
#include "rlutil.h"

class archivoMusicos {
private:
 char nombre[30];
        int tamanioRegistro;
    public:
        archivoMusicos  (const char *n){
      strcpy(nombre, n);
            tamanioRegistro=sizeof (Musicos);
        }
  //ALTA
void cargaMusico();
  //BAJA
bool BajaLogica();
bool bajaFisica();
  //MODIFICACIOM
bool modificarFechaInscripcion();
void  sobreEscribirRegistro(const Musicos reg, int p);

  //LISTADO
int MenuMusicos();
void MostrarMusicos();
void buscarPorDNI();
void buscarPorClaustro();
///
int contarRegistrosMusicos();
int buscarMusicoPorDNI(int dni);
Musicos leerRegistro(int p);
bool Mbackup();
bool Mrestaurar();
bool MrestaurarDATINI();
void cargaMusicoINI();
};
void archivoMusicos::cargaMusico(){
    Musicos obj;
    FILE *pMus;
    pMus=fopen(nombre, "ab");
    if(pMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    int DNI;
   cout<<"DNI: ";
        cin>>DNI;
        if(buscarMusicoPorDNI(DNI)==-1){
    obj.CargarMusico(DNI);
	fwrite(&obj, sizeof obj, 1, pMus);
	fclose(pMus);
        }else {cout<<"YA EXISTE ESE DNI EN EL ARCHIVO"<<endl;
        fclose(pMus);}
}

void archivoMusicos::MostrarMusicos(){
   Musicos obj;
    FILE *pMus;
    int cantReg;
    cantReg=contarRegistrosMusicos();
    if(cantReg==0){
        cout<<"EL ARCHIVO NO TIENE REGISTRO"<<endl;
        system("pause");
        return;
    }
    else{
            if(cantReg==-1){
                cout<<"EL ARCHIVO NO EXISTE O NO SE PUDO ABRIR"<<endl;
               system("pause");
                return;
        }
}
    pMus=fopen(nombre, "rb");
    if(pMus==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
        return;
    }
	while(fread(&obj, sizeof obj, 1, pMus)==1){
        obj.MostrarMusico();
        cout<<endl;
	}
	fclose(pMus);
}

int archivoMusicos::contarRegistrosMusicos(){
    FILE *p;
	p=fopen(nombre,"rb");
	if(p==NULL) return -1;
	fseek(p,0,2);
	int tam=ftell(p);
	fclose(p);
  /*cout<<"CANTIDAD DE BYTES DEL ARCHIVO ";
	cout<<tam<<endl<<endl;	///muestra la cantidad de bytes totales del archivo
    cout<<"CANTIDAD DE REGISTROS DEL ARCHIVO ";
	cout<<tam/sizeof(Musicos)<<endl<<endl;//divide el total del archivo por el tamaño de un registro.*/
    return tam/sizeof(Musicos);
}

int archivoMusicos::buscarMusicoPorDNI(int dni){
    Musicos obj;
    int pos=0;
    FILE *pMus;
    pMus=fopen(nombre, "rb");
    if(pMus==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return -2;
    }
	while(fread(&obj, sizeof obj, 1, pMus)==1){
        if(dni==obj.getDNI()&&obj.getEstado()==true){
            fclose(pMus);
            return pos;
        }
        pos++;
	}
	fclose(pMus);
	return -1;
}

void archivoMusicos::buscarPorDNI(){
    Musicos obj;
    bool encontro=false;
    FILE *pMus;
    pMus=fopen(nombre, "rb");
    if(pMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    int DNI;
    cout<<"INGRESE EL DNI A BUSCAR ";
    cin>>DNI;

	while(fread(&obj, sizeof obj, 1, pMus)==1){
        if(DNI==obj.getDNI()&& obj.getEstado()==true){
            obj.MostrarMusico();
            cout<<endl;
            encontro=true;
        }
	}
	if(encontro==false){
        cout<<"NO SE ENCONTRO MUSICO CON ESE DNI"<<endl;
	}
	fclose(pMus);
}

Musicos archivoMusicos::leerRegistro(int p){
    Musicos obj;
    obj.setDNI(-1);
    ///int pos=0;cout<<"CANTIDAD DE REGISTROS DEL ARCHIVO ";
    FILE *pMus;
    pMus=fopen(nombre, "rb");
    if(pMus==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return obj;
    }
    fseek(pMus, sizeof obj*p, 0);
    fread(&obj, sizeof obj, 1, pMus);
if( obj.getEstado()==false){ obj.setDNI(-1);}
	fclose(pMus);
	return obj;
}

void  archivoMusicos::sobreEscribirRegistro(const Musicos reg, int p){

    FILE *pMus;
    Musicos obj;
    pMus=fopen(nombre, "rb+");///+ agrega al modo lo que le falta
    if(pMus==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }
    fseek(pMus, p*sizeof reg, 0);
    fwrite(&reg, sizeof reg, 1, pMus);

	fclose(pMus);
}

bool archivoMusicos::modificarFechaInscripcion(){
    Musicos obj;
    int DNI;
    cout<<"INGRESE EL DNI DEL CLIENTE A MODIFICAR: ";
    cin>>DNI;
///Buscar el registro que se quiere eliminar.
    int pos=buscarMusicoPorDNI(DNI);
    if(pos==-1){
        cout<<"NO EXISTE UN REGISTRO CON ESE DNI"<<endl;
        system("pause");
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO DE CLIENTES"<<endl;
        system("pause");
        return false;
    }
///Leer el registro (escribirlo en una variable de memoria)
    obj=leerRegistro(pos);
    if(obj.getDNI()==-1){cout<<"Musico inexistente"<<endl;
    return false;}
///Pedir el nuevo fecha y cambiarlo

    cout<<"INGRESE EL NUEVA FECHA DE INSCRIPCION ";
    obj.setInscripcion();
    //cin>>fecha;
    //obj.setFechaNacimiento(fecha);
///Sobrescribir el registro en la misma posición del archivo en que se encontraba.
    sobreEscribirRegistro(obj, pos);
    return true;

}

bool archivoMusicos::BajaLogica(){
    Musicos obj;
    int DNI;
    cout<<"INGRESE EL DNI DEL CLIENTE A ELIMINAR: ";
    cin>>DNI;
///Buscar el registro que se quiere eliminar.
    int pos=buscarMusicoPorDNI(DNI);
    if(pos==-1){
        cout<<"NO EXISTE UN REGISTRO CON ESE DNI"<<endl;
        system("pause");
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO DE CLIENTES"<<endl;
        system("pause");
        return false;
    }
///Leer el registro (escribirlo en una variable de memoria)
    obj=leerRegistro(pos);
///cambiar el estado a false.
    obj.setEstado(false);
///Sobrescribir el registro en la misma posición del archivo en que se encontraba.
    sobreEscribirRegistro(obj, pos);
    return true;
}

bool archivoMusicos::bajaFisica(){
    Musicos obj;
    FILE *pMus, *pBak;
    pMus=fopen(nombre, "rb");
    if(pMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    pBak=fopen("Musicos.bak", "wb");
    if(pBak==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pMus);
        return false;
    }

	while(fread(&obj, sizeof obj, 1, pMus)==1){
        fwrite(&obj, sizeof obj, 1, pBak);
	}
	fclose(pBak);
	fclose(pMus);

	pMus=fopen(nombre, "wb");
	if(pMus==NULL)return false;

	pBak=fopen("Musicos.bak", "rb");
	if(pBak==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pMus);
        return false;
    }

    while(fread(&obj, sizeof obj,1,pBak)==1){
        if(obj.getEstado()==true){
            fwrite(&obj, sizeof obj, 1, pMus);
        }
    }
    fclose(pBak);
	fclose(pMus);
	return true;
}
bool archivoMusicos::Mbackup(){
    Musicos obj;
    FILE *pMus, *pbkp;
    pMus=fopen(nombre, "rb");
    if(pMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    pbkp=fopen("Musicos.bkp", "wb");
    if(pbkp==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pMus);
        return false;
    }

	while(fread(&obj, sizeof obj, 1, pMus)==1){
        fwrite(&obj, sizeof obj, 1, pbkp);
	}
	fclose(pbkp);
	fclose(pMus);
	return true;
}
bool archivoMusicos::Mrestaurar(){
    Musicos obj;
    FILE *pMus, *pbkp;
    pbkp=fopen("Musicos.bkp", "rb");
    if(pbkp==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    pMus=fopen(nombre, "wb");
    if(pMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pMus);
        return false;
    }

	while(fread(&obj, sizeof obj, 1, pbkp)==1){
        fwrite(&obj, sizeof obj, 1, pMus);
	}
	fclose(pMus);
	fclose(pbkp);
	return true;
}
bool archivoMusicos::MrestaurarDATINI(){
    Musicos obj;
    FILE *pMus, *pbkp;
    pbkp=fopen("Musicos.ini", "rb");
    if(pbkp==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
    pMus=fopen(nombre, "wb");
    if(pMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pMus);
        return false;
    }

	while(fread(&obj, sizeof obj, 1, pbkp)==1){
        fwrite(&obj, sizeof obj, 1, pMus);
	}
	fclose(pMus);
	fclose(pbkp);
	return true;
}
int MenuMusicos(){
archivoMusicos obj(ARCHIVO_MUSICOS);
int x=49, y=7;
        system("cls");
    while(true){
        rlutil::hidecursor();
        rlutil::locate(x, y);
        cout<<char(175);
        rlutil::locate(50, 5);
        cout<<"           MENU MUSICOS            "<<endl;
        rlutil::locate(50, 6);
        cout<<"-----------------------------------"<<endl;
        rlutil::locate(50, 7);
        cout<<"          AGREGAR MUSICOS          "<<endl;
        rlutil::locate(50, 8);
        cout<<"      LISTAR MUSICO POR DNI        "<<endl;
        rlutil::locate(50, 9);
        cout<<"      LISTAR TODOS LOS MUSICOS     "<<endl;
        rlutil::locate(50, 10);
        cout<<"   MODIFICAR FECHA DE INSCRIPCION  "<<endl;
        rlutil::locate(50, 11);
        cout<<"    ELIMINAR REGISTRO DE MUSICO    "<<endl;
        rlutil::locate(50, 12);
        cout<<"              SALIR                "<<endl;
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
                        rlutil::cls();
                        obj.cargaMusico();
                            break;
                    case 8:
                        rlutil::cls();
                        obj.buscarPorDNI();
                        getch();
                        rlutil::cls();
                            break;
                    case 9:
                        rlutil::cls();
                        obj.MostrarMusicos();
                        getch();
                        rlutil::cls();
                            break;
                    case 10:
                        rlutil::cls();
                        if(obj.modificarFechaInscripcion())cout<<"FECHA DE INSCRIPCION MODIFICADA"<<endl;
                            else cout<<"NO SE PUDO REALIZAR LA MODIFICACION"<<endl;
                        getch();
                        rlutil::cls();
                            break;
                    case 11:
                    rlutil::cls();
                    if(obj.BajaLogica())cout<<"REGISTRO ELIMINADO CORRECTAMENTE"<<endl;
                            else cout<<"EL REGISTRO NO SE ELIMINO DE FORMA CORRECTA"<<endl;
                        getch();
                        rlutil::cls();
                            break;
                    /*case 12:if(obj.bajaFisica())cout<<"BAJA FISICA TERMINADA CORRECTAMENTE"<<endl;
                            else cout<<"LA BAJA FISICA NO AH SIDO POSIBLE"<<endl;
                            break;*/
                    case 12:
                        rlutil::cls();
                        return 0;
                        break;
            }
        }
    }
    return 0;
}
void archivoMusicos::cargaMusicoINI(){
    Musicos obj;
    FILE *pMus;
    pMus=fopen("Musicos.ini", "ab");
    if(pMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    int DNI;
   cout<<"DNI: ";
        cin>>DNI;
        if(buscarMusicoPorDNI(DNI)==-1){
    obj.CargarMusico(DNI);
	fwrite(&obj, sizeof obj, 1, pMus);
	fclose(pMus);
        }else {cout<<"YA EXISTE ESE DNI EN EL ARCHIVO"<<endl;
        fclose(pMus);}
}

#endif // CLS_ARCHIVOMUSICOS_H_INCLUDED
