#include "funciones_main.h"
using namespace std;

int main(){
	Lista<Pelicula>* no_vistas = new Lista<Pelicula>;
	Lista<Pelicula>* vistas = new Lista<Pelicula>;
    
    ifstream arch_vistas;
    ifstream arch_no_vistas ;

    arch_vistas.open("peliculas_vistas.txt");

    if(arch_vistas.fail()){
        cout<< "No se pudo abrir el archivo"<< endl;
        return 0; //CORTO EL PROGRAMA YA QUE NO SE PUDO ABRIR EL ARCHIVO//
    }
    arch_no_vistas.open("peliculas_no_vistas.txt");

    if(arch_no_vistas.fail()){
        cout<< "No se pudo abrir el archivo"<< endl;
        return 0; //CORTO EL PROGRAMA YA QUE NO SE PUDO ABRIR EL ARCHIVO//
    }
    cargar_lista(arch_vistas, vistas);
    cargar_lista(arch_no_vistas, no_vistas);

    char comando;
    bool continuar_operando = true;
    while(continuar_operando){ 
        menu();

        cout<<"Ingrese un comando"<< endl;
        cin>> comando;

        while(comando != 'a' && comando != 'b' && comando != 'c' && comando != 'd'){

            cout<<"Comando invalido"<<endl;
            cout<<"Ingrese un comando"<< endl;
            cin>> comando;
            system("clear");

        }

        continuar_operando = operaciones(comando,vistas,no_vistas);        
    }

    delete vistas;
    delete no_vistas;
	return 0;
}