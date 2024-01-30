#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <ctime>
class Fecha{///base
    protected:
        int dia, mes, anio;
    public:
        Fecha(){
        time_t t = time(nullptr);
        tm* fS = localtime(&t);
        dia = fS->tm_mday;
        mes = fS->tm_mon + 1;
        anio = fS->tm_year + 1900;
        }
        Fecha(int d, int m, int a){///constructor
            dia=d;
            mes=m;
            anio=a;
        }
        void CargarFecha();
        void MostrarEn1Linea();
        void Mostrar();
        int compararFechas(Fecha f);
        ///sets
        void setDia(int x){if(x>0 && x<32) dia=x;}
        void setMes(int x){if(x>0 && x<13)mes=x;}
        void setAnio(int x){anio=x;}
        ///gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

};

 void Fecha::CargarFecha(){///método o función de la clase
     Fecha obj;
    //do{
    system("cls");
    cout<<"DIA: ";
    cin>>dia;
    while(dia<1||dia>31){system("cls");
    cout<<"dia invalido"<<endl;
    cout<<"DIA: ";
    cin>>dia;
    }
    system("cls");
    cout<<"MES: ";
    cin>>mes;
    while(mes<1||mes>12){system("cls");
    cout<<"mes invalido"<<endl;
    cout<<"MES: ";
    cin>>mes;
    }
    system("cls");
    cout<<"ANIO: ";
    cin>>anio;
    while(anio<1500||anio>obj.getAnio()){system("cls");
    cout<<"anio invalido"<<endl;
    cout<<"ANIO: ";
    cin>>anio;
    }
   //while( compararFechas(obj)==-1){}
}

void Fecha::MostrarEn1Linea(){///método o función de la clase
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

void Fecha::Mostrar(){///método o función de la clase
    cout<<"DIA: "<<dia<<endl;
    cout<<"MES: "<<mes<<endl;
    cout<<"ANIO: "<<anio<<endl;
}
 int Fecha::compararFechas(Fecha f) {
    if (anio < f.anio) return -1;
    if (anio > f.anio) return 1;
    if (mes < f.mes) return -1;
    if (mes > f.mes) return 1;
    if (dia < f.dia) return -1;
    if (dia > f.dia) return 1;
    return 0;
  }

#endif // FECHA_H_INCLUDED
