#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED

class Cliente: public Persona{
private:
    char CUIT[12];
    Fecha ingreso;

    /*
    int DNI;
    Fecha fechaNacimiento;
    char nombre[25];
    char apellido[25];
    char email[25];
    char telefono[20];
    */
public:

    const char *getCUIT(){return CUIT;}
    Fecha getFechaIngreso(){return ingreso;}
    char getInicialApellido(){return apellido[0];}
    bool compararInicial(char ini){return (tolower(apellido[0])==tolower(ini));}

    void setCUIT(const char *c){strcpy(CUIT,c);}
    void setFechaIngreso(Fecha i){ingreso=i;}
    /*int getDNI(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}

    void setDNI(const int d){DNI=d;}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido, a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    */
    void Cargar(int dni=-1){
        cout<<"CUIT ";
        cin>>CUIT;
        cout<<"FECHA DE LA PRIMERA COMPRA O INGRESO "<<endl;
        ingreso.Cargar();
        Persona::Cargar(dni);
    }
    void Mostrar(){
        if(estado){
            cout<<"CUIT "<<CUIT<<endl;
            cout<<"FECHA DE LA PRIMERA COMPRA O INGRESO "<<endl;
            ingreso.Mostrar();
            Persona::Mostrar();
        }
    }

    void modificarDNI(int d){
        DNI=d;
    }

};


#endif // CLSCLIENTE_H_INCLUDED
