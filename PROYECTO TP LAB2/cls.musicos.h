#ifndef CLS_MUSICOS_H_INCLUDED
#define CLS_MUSICOS_H_INCLUDED

class Musicos: public Persona{
private:

int Claustro ;//(1: docente; 2 alumno; 3 no docente; 4 graduado)
int InstrumentoPrincipal ;//(número entre 1 y 15)
int TipoDeMusica ;//(número entre 1 y 10)
float Matricula ;
Fecha inscripcion;

public:

void setClaustro(int c){Claustro=c;}
void setInstrumentoPrincipal(int i){InstrumentoPrincipal=i;}
void setTipoDeMusica(int t){TipoDeMusica=t;}
void setMatricula(float m){Matricula=m;}
void setInscripcion(){inscripcion.CargarFecha();}

int getClaustro(){return Claustro;}
int getInstrumentoPrincipal(){return InstrumentoPrincipal;}
int getTipoDeMusica(){return TipoDeMusica;}
float getMatricula(){return Matricula;}
int getanioins(){return inscripcion.getAnio();}

void CargarMusico(int DNI);
void MostrarMusico();
};

void Musicos::CargarMusico(int DNI){
Persona::Cargar(DNI);
cout<<"Claustro: ";
cin>>Claustro;
 system("cls");
while(Claustro<1||Claustro>4){
         system("cls");
        cout<<"tipo de claustro ingresado inexistente"<<endl;
    cout<<"Claustro: ";
cin>>Claustro;
}
cout<<"Instrumento Principal: "<<endl;
cin>>InstrumentoPrincipal;
 system("cls");
while(InstrumentoPrincipal<1||InstrumentoPrincipal>15){
        system("cls");
        cout<<"Instrumento Principal ingresado inexistente"<<endl;
    cout<<"Instrumento Principal: ";
cin>>InstrumentoPrincipal;
}
cout<<"Tipo De Musica: "<<endl;
cin>>TipoDeMusica;
 system("cls");
 while(TipoDeMusica<1||TipoDeMusica>10){
        system("cls");
        cout<<"Tipo De Musica ingresado inexistente"<<endl;
    cout<<"Tipo De Musica: ";
cin>>TipoDeMusica;
}
cout<<"fecha de inscripcion: "<<endl;
inscripcion.CargarFecha();
while( inscripcion.compararFechas(Fecha())>0){
    cout<<"fecha de incripcion invalida"<<endl;
    inscripcion.CargarFecha();
}
cout<<"Matricula: "<<endl;
cin>>Matricula;
while(Matricula<0){
        system("cls");
        cout<<"Matricula invalida"<<endl;
    cout<<"Matricula: ";
cin>>Matricula;
    }
}

void Musicos::MostrarMusico(){
  if(estado==true){
Persona::Mostrar();

cout<<"Claustro: ";
cout<<Claustro<<endl;
cout<<"Instrumento Principal: ";
cout<<InstrumentoPrincipal<<endl;
cout<<"Tipo De Musica: ";
cout<<TipoDeMusica<<endl;
cout<<"fecha de inscripcion: ";
inscripcion.MostrarEn1Linea();
cout<<"Matricula: ";
cout<<Matricula<<endl;
                  }
}

#endif // CLS_MUSICOS_H_INCLUDED
