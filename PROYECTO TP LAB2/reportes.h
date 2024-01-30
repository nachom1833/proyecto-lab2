#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

class MusicosDe2023{
private:
int DNI;
char nombre[25];
int Claustro ;

public:

void setDNI(const int d){DNI=d;}
void setNombre(const char *n){strcpy(nombre,n);}
void setClaustro(int c){Claustro=c;}


int getDNI(){return DNI;}
const char* getNombre(){return nombre;}
int getClaustro(){return Claustro;}

void MostrarReg();
};
void MusicosDe2023::MostrarReg(){

cout<<"Dni: ";
cout<<DNI<<endl;
cout<<"Nombre: ";
cout<<nombre<<endl;
cout<<"Claustro: ";
cout<<Claustro<<endl;

                  }


class Archivo2023 {
private:
 char nombre[30];
        int tamanioRegistro;
    public:
        Archivo2023  (const char *n){
      strcpy(nombre, n);
            tamanioRegistro=sizeof (MusicosDe2023);
        }
         //int contarRegistros();
        bool MusicosAarchivo();
        void MostrarArchivo();
int contarRegistros();

};
int Archivo2023::contarRegistros(){
    FILE *p;
	p=fopen(nombre,"rb");
	if(p==NULL) return -1;
	fseek(p,0,2);
	int tam=ftell(p);
	fclose(p);

    return tam/sizeof(MusicosDe2023);
}
void Archivo2023::MostrarArchivo(){
    MusicosDe2023 obj;
    FILE *pMus;
    int cantReg;
    cantReg=contarRegistros();
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
        obj.MostrarReg();
        cout<<endl;
	}
	fclose(pMus);
}

bool Archivo2023::MusicosAarchivo(){
   archivoMusicos obj(ARCHIVO_MUSICOS);
   Musicos per;
   MusicosDe2023 reg;
   int nReg=obj.contarRegistrosMusicos();
   int anio=2023;
    FILE *pMus,*pBak;
    pMus=fopen("musicos.dat", "rb");
    if(pMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return false;
    }
   pBak=fopen(nombre, "wb");
    if(pBak==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pMus);
        return false;
    }
for(int i=0;i<nReg;i++){
	fread(&per, sizeof per, 1, pMus);
	if(anio==per.getanioins()){
    reg.setDNI(per.getDNI());
    reg.setNombre(per.getNombre());
    reg.setClaustro(per.getClaustro());
        fwrite(&reg, sizeof reg, 1, pBak);
    }}
    fclose(pBak);
	fclose(pMus);
   // cout<<" SE PUDO COPIAR EL REGISTRO"<<endl;
   system("pause");
    return true;
}
void archivoMusicos::buscarPorClaustro(){

    int alumno=2;
    Musicos obj;
    bool encontro=false;
    FILE *pMus;
    pMus=fopen(nombre, "rb");
    if(pMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;

        return;

    }



	while(fread(&obj, sizeof obj, 1, pMus)==1){
        if(alumno==obj.getClaustro()&& obj.getEstado()==true){
        obj.MostrarMusico();
        cout<<endl;
        encontro=true;
        }
	}
    if(encontro==false){
    cout<<"NO SE ENCONTRO MUSICO CON ESE CLAUSTRO"<<endl;
}
	fclose(pMus);
system("pause");
}
int MenuReportes(){
    int opcion;
archivoMusicos obj(ARCHIVO_MUSICOS);
   Archivo2023 arc(ARCHIVO_MUSICOS2023);

    do {
            system("cls");
        std::cout << "==== Menú ====" << std::endl;
        std::cout << "1. ej 1 buscar por claustro 2" << std::endl;
        std::cout << "2. ej 2" << std::endl;
        std::cout << "3. ej 3 crear archivo 2023" << std::endl;
        std::cout << "4. ej 4 mostrar archivo" << std::endl;
        std::cout << "0. Salir" << std::endl;

        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        switch (opcion){
            case 1:
                 obj.buscarPorClaustro();
                break;
            case 2:
                // Ingrese aquí la funcionalidad para la opción 2
                break;
            case 3:
                if(arc.MusicosAarchivo()){cout<<"archivo creado correctamente"<<endl;}
                break;
            case 4:arc.MostrarArchivo();system("pause");
                // Ingrese aquí la funcionalidad para la opción 4
                break;
            case 0:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo." << std::endl;
                break;
        }
    }while (opcion != 0);
return 0;
}

#endif // REPORTES_H_INCLUDED
