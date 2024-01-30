#ifndef FUNCIONESADICIONALES_H_INCLUDED
#define FUNCIONESADICIONALES_H_INCLUDED

void cargarCadena(char *pal,int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

int validarRango(int inicio, int fin, int &valor){
  while((valor>fin)||(valor<inicio)){
        cout<<"Ingrese un valor dentro del rango indicado"<<endl;
        cin>>valor;
    }
    return valor;
}
/*
int cursor(int _x, int _y){
    rlutil::locate(_x,_y);
    cout<<char(175);
}
*/
#endif // FUNCIONESADICIONALES_H_INCLUDED
