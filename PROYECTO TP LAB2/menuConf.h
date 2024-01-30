#ifndef MENUCONF_H_INCLUDED
#define MENUCONF_H_INCLUDED


int MenuConfiguracion(){
archivoMusicos obj(ARCHIVO_MUSICOS);
ArchivoGenero arc("generosMusicales.dat");
archivoMusicos ini("Musicos.ini");
ArchivoGenero Dini("Genero.ini");
int opc;
    while(true){
        system("cls");
        cout<<"MENU CONFIGURACION"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS"<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS"<<endl;
        cout<<"3) RESTAURAR EL ARCHIVO DE MUSICOS"<<endl;
        cout<<"4) RESTAURAR EL ARCHIVO DE GENEROS "<<endl;
        cout<<"5) ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(obj.Mbackup()){cout<<"el back up se ha realizado correctamente"<<endl;
                     }else{cout<<"el back up no se ha realizado correctamente"<<endl;}
                    break;
            case 2:if(arc.Gbackup()){cout<<"el back up se ha realizado correctamente"<<endl;
                     }else{cout<<"el back up no se ha realizado correctamente"<<endl;}
                    break;
            case 3:if(obj.Mrestaurar()){cout<<"el archivo se ha restaurado correctamente"<<endl;
                     }else{cout<<"el archivo no se ha restaurado correctamente"<<endl;}
                    break;
            case 4:if(arc.Grestaurar()){cout<<"el archivo se ha restaurado correctamente"<<endl;
                     }else{cout<<"el archivo no se ha restaurado correctamente"<<endl;}
                    break;
            case 5:if(arc.GrestaurarDATINI()&&obj.MrestaurarDATINI()){cout<<"Los archivos se han restaurado correctamente"<<endl;
                     }else{cout<<"los archivos no se han restaurado correctamente"<<endl;}
                    break;
            case 6:for(int i=0;i<10;i++){ ini.cargaMusicoINI();}
            for( int i=0;i<10;i++){ Dini.cargarArchivoINI();}
                    break;
            case 0:
                return 0;
                break;
            }
        cout<<endl;
        getch();
    }
    return 0;
}


#endif // MENUCONF_H_INCLUDED
