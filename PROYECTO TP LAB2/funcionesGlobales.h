#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

void cargaCliente(){
    Cliente obj;
    FILE *pCli;
    pCli=fopen("clientes.dat", "ab");///ab: crea el archivo si no existe <= escritura
                                     ///wb: crea siempre un archivo vacío <= escritura
                                     ///rb: no crea archivos <= lectura
    if(pCli==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    obj.Cargar();
	fwrite(&obj, sizeof (Cliente), 1, pCli);
	fclose(pCli);
}

void mostrarClientes(){
    Cliente obj;
    FILE *pCli;
    pCli=fopen("clientes.dat", "rb");
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

Cliente leerCliente(int p){
    Cliente obj;
    if(p<0){
        obj.setDNI(-3);
        return obj;
    }
    FILE *pCli;
    pCli=fopen("clientes.dat", "rb");
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

int buscarCliente(int d){
    Cliente obj;
    int pos=0;
    FILE *pCli;
    pCli=fopen("clientes.dat", "rb");
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

void buscarPorDNI(){
    Cliente obj;
    int DNI;
    cout<<"INGRESE EL DNI A BUSCAR ";
    cin>>DNI;
    int pos=buscarCliente(DNI);
    obj=leerCliente(pos);
    if(obj.getDNI()>0){
        obj.Mostrar();
    }else if(obj.getDNI()==-3 || obj.getDNI()==-1){
        cout<<"EL DNI NO EXISTE EN EL ARCHIVO"<<endl;
    }else{
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
}

void listarPorInicial(){
    Cliente obj;
    bool encontro=false;
    FILE *pCli;
    pCli=fopen("clientes.dat", "rb");
    if(pCli==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    char inicial;
    cout<<"INGRESE LA INICIAL A BUSCAR ";
    cin>>inicial;

	while(fread(&obj, sizeof obj, 1, pCli)==1){
        if(obj.compararInicial(inicial)){
        ///if(tolower(inicial)==tolower(obj.getApellido()[0])){
        ///if(inicial==obj.getInicialApellido()){
            obj.Mostrar();
            cout<<endl;
            encontro=true;
        }
	}
	if(encontro==false){
        cout<<"NO SE ENCONTRO CLIENTE CON ESA INICIAL"<<endl;
	}
	fclose(pCli);
}

bool modificarRegistroCliente(Cliente obj, int pos){
    FILE *pCli;
    pCli = fopen("clientes.dat", "rb+");
    fseek(pCli, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, pCli);
    fclose(pCli);
    return aux;
}

bool bajaLogica(){
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
    bool aux = modificarRegistroCliente(obj, pos);
    return aux;
}

bool modificarEmail(){
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
    bool aux = modificarRegistroCliente(obj, pos);
    return aux;
}

#endif // FUNCIONESGLOBALES_H_INCLUDED
