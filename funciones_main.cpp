#include "funciones_main.h"

void cargar_actores(string lectura, Lista<string>* lista){
    int pos_lista = 1;
    int i =0;
    int ant = 0;
    string* actor= new string;
    while(lectura[i]!= '\n'){
        if(lectura[i]==' '){
            *actor = lectura.substr(ant,i);
            lista-> agregar(actor, pos_lista);
            ant = i + 1;
            pos_lista++;
        }
        i++;
    }
    *actor = lectura.substr(ant,i-1);
    lista-> agregar(actor, pos_lista);
}

void cargar_lista(ifstream &archivo,Lista<Pelicula>* lista){
    int pos_lista = 1;
    string* nombre= new string;
    string* genero= new string;
    string* nota= new string;
    string* director= new string;
    string* actores= new string;
    getline(archivo, *nombre);
    while (!archivo.eof()){ 
        getline(archivo, *genero);
        getline(archivo, *nota);
        getline(archivo, *director);
        getline(archivo, *actores);
        Lista<string>* lista_actores = new Lista<string>;
        cargar_actores(*actores, lista_actores);
        Pelicula* Nueva_pelicula = new Pelicula(nombre, genero, director, &atoi(nota->c_str()), lista_actores);
        lista -> agregar(Nueva_pelicula, pos_lista);
        delete lista_actores;
        pos_lista++;
        getline(archivo, *nombre);
    }  
    delete nombre;
    delete genero;
    delete nota;
    delete director;
    delete actores;
}