#ifndef CLSARCHIVOARTICULO_H_INCLUDED
#define CLSARCHIVOARTICULO_H_INCLUDED

class ArchivoArticulo{
    private:
        char nombre[30];
        int tamanioRegistro;
    public:
        ArchivoArticulo(const char *n){
            strcpy(nombre, n);
            tamanioRegistro=sizeof (Articulo);
        }
        ///ALTA
        void agregarRegistro();
        ///BAJA
        int buscarRegistro(int d);
        Articulo leerRegistro(int p);
        bool bajaLogica();
        ///MODIFICACION
        bool modificarRegistro();
        ///LISTADO/S
        bool modificarRegistro(Articulo obj, int p);
        void mostrarRegistros();
        bool grabarRegistro(Articulo obj);
};

bool ArchivoArticulo::grabarRegistro(Articulo obj){
    FILE *pCli;
    pCli=fopen(nombre, "ab");
    if(pCli==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
	fwrite(&obj, tamanioRegistro, 1, pCli);
	fclose(pCli);
}

void ArchivoArticulo::agregarRegistro(){
    Articulo obj;
    obj.Cargar();
    if(grabarRegistro(obj)){
        cout<<"REGISTRO AGREGADO CORRECTAMENTE"<<endl;
    }else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
    }
}

bool ArchivoCliente::bajaLogica(){
    ///SOLICITAR QUE REGISTRO SE QUIERE DAR DE BAJA
    Cliente obj;
    int DNI;
    cout<<"INGRESE EL DNI A DAR DE BAJA: ";
    cin>>DNI;
    ///BUSCAR EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarCliente(DNI);
    if(pos==-1){
        cout<<"NO EXISTE CLIENTE CON ESE DNI"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerCliente(pos);
    if(obj.getEstado()==false){
        cout<<"EL CLIENTE INGRESADO YA ESTA DADO DE BAJA"<<endl;
        return false;
    }
    ///MODIFICAMOS EL CAMPO ESTADO (LO PONEMOS EN FALSE)
    obj.setEstado(false);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
    bool aux = modificarRegistro(obj, pos);
    return aux;
}

Cliente ArchivoCliente::leerCliente(int p){
    Cliente obj;
    if(p<0){
        obj.setDNI(-3);
        return obj;
    }
    FILE *pCli;
    pCli=fopen(nombre, "rb");
    if(pCli==NULL){
        obj.setDNI(-2);
        return obj;
    }
    fseek(pCli, sizeof obj * p, 0); ///0: desde el principio, 1: desde la posicion actual, 2: desde el eof
    int aux=fread(&obj, sizeof obj, 1, pCli);
    fclose(pCli);
    if(aux==0){
        obj.setDNI(-1);
    }
    return obj;
}

int ArchivoCliente::buscarCliente(int d){
    Cliente obj;
    int pos=0;
    FILE *pCli;
    pCli=fopen(nombre, "rb");
    if(pCli==NULL){
        return -2;
    }
    while(fread(&obj, sizeof obj, 1, pCli)==1){
        if(obj.getDNI() == d){
            fclose(pCli);
            return pos;
        }
        pos++;
	}
	fclose(pCli);
	return -1;
}

void ArchivoCliente::mostrarRegistros(){
    Cliente obj;
    FILE *pCli;
    pCli=fopen(nombre, "rb");
    if(pCli==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&obj, sizeof obj, 1, pCli)==1){
        obj.Mostrar();
        if(obj.getEstado()) cout<<endl;
	}
	fclose(pCli);
}

bool ArchivoCliente::modificarEmail(){
    ///SOLICITAR QUE REGISTRO SE QUIERE MODIFICAR EL MAIL
    Cliente obj;
    int DNI;
    cout<<"INGRESE EL DNI DEL CLIENTE A MODIFICAR: ";
    cin>>DNI;
    ///BUSCAR EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarCliente(DNI);
    if(pos==-1){
        cout<<"NO EXISTE CLIENTE CON ESE DNI"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerCliente(pos);
    if(obj.getEstado()==false){
        cout<<"EL CLIENTE INGRESADO ESTA DADO DE BAJA"<<endl;
        return false;
    }
    ///MODIFICAMOS EL CAMPO EMAIL
    char mail[25];
    cout<<"INGRESE EL NUEVO MAIL: ";
    cin>>mail;
    obj.setEmail(mail);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
    bool aux = modificarRegistro(obj, pos);
    return aux;
}

bool ArchivoCliente::modificarRegistro(Cliente obj, int pos){
    FILE *pCli;
    pCli = fopen(nombre, "rb+");
    fseek(pCli, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, pCli);
    fclose(pCli);
    return aux;
}

void ArchivoCliente::buscarPorDNI(){
    Cliente obj;
    int DNI;
    cout<<"INGRESE EL DNI A BUSCAR ";
    cin>>DNI;
    int pos=buscarCliente(DNI);
    obj=leerCliente(pos);
    if(obj.getDNI()=>0){
        obj.Mostrar();
    }else if(obj.getDNI()==-3 || obj.getDNI()==-1){
        cout<<"EL DNI NO EXISTE EN EL ARCHIVO"<<endl;
    }else{
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
}

#endif // CLSARCHIVOCLIENTE_H_INCLUDED
