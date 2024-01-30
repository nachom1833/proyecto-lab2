#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED

class Persona{
protected:
    int DNI;
    Fecha fechaNacimiento;
    char nombre[25];
    char apellido[25];
    char email[25];
    char telefono[20];
    bool estado;
public:

    Fecha getFechaNacimiento(){
        return fechaNacimiento;
    }

    int getDNI(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}
    bool getEstado(){return estado;}

    void setDNI(const int d){DNI=d;}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido, a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    void setEstado(bool e){estado=e;}

    void Cargar(int dni);
    void Mostrar();
};




void Persona::Cargar(int dni=-1){
    if(dni==-1){
        cout<<"DNI: ";
        cin>>DNI;
    }else{
        DNI=dni;
    }
    cout<<"Nombre: ";
    cin>>nombre;
    cout<<"APELLIDO: ";
    cin>>apellido;
    cout<<"EMAIL: ";
    cin>>email;
    cout<<"TELEFONO: ";
    cin>>telefono;
    estado=true;
}

void Persona::Mostrar(){
    cout<<"DNI: ";
    cout<<DNI<<endl;
    cout<<"Nombre: ";
    cout<<nombre<<endl;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"EMAIL: ";
    cout<<email<<endl;
    cout<<"TELEFONO: ";
    cout<<telefono<<endl;

}

#endif // CLSPERSONA_H_INCLUDED
