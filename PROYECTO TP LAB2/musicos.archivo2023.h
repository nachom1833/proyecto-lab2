#ifndef MUSICOS_ARCHIVO2023_H_INCLUDED
#define MUSICOS_ARCHIVO2023_H_INCLUDED
#include "cls.archivoMusicos.h"
#include "musicos.2023.h"
/*
class Archivo2023 {


private:
 char nombre[30];
        int tamanioRegistro;
    public:
        Archivo2023  (const char *n){
      strcpy(nombre, n);
            tamanioRegistro=sizeof (Musicos);
        }

         //int contarRegistros();
        bool MusicosAarchivo();




};
   Archivo2023 obj(ARCHIVO_MUSICOS2023);


  /*int Archivo2023::contarRegistros(){
    FILE *p;
	p=fopen(nombre,"rb");
	if(p==NULL) return -1;
	fseek(p,0,2);
	int tam=ftell(p);
	fclose(p);
    return tam/sizeof(Musicos);
}*/
/*
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
   pBak=fopen(nombre, "rb+");
    if(pBak==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pMus);
        return false;
    }
for(int i=0;i<nReg;i++){
	fread(&per, sizeof per, 1, pMus);
	if(anio==per.getanioins()&&per.getEstado()==true)
    reg.setDNI(per.getDNI());
    reg.setNombre(per.getNombre());
    reg.setClaustro(per.getClaustro());

        fwrite(&reg, sizeof reg, 1, pBak);

    }
    fclose(pBak);
    cout<<" SE PUDO COPIAR EL REGISTRO"<<endl;


	fclose(pMus);
}
*/

#endif // MUSICOS_ARCHIVO2023_H_INCLUDED
