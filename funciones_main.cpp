#include "funciones_main.h"

void menu(){

        cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;

        cout<<"MENU DE COMANDOS"<< endl;

        cout<<"a. Mostrar lista de peliculas vistas"<< endl;
        cout<<"b. Mostrar lista de peliculas NO vistas"<< endl;
        cout<<"c. Mostrar lista de peliculas recomendadas"<< endl;
        cout<<"d. Salir de la aplicacion"<< endl;    

        cout<<"---------------------------------------------------------------------------------------------------------------------------"<< endl;
}

void cargar_lista(ifstream &archivo,Lista<Pelicula>* lista){
    int pos_lista = 1;
    string aux,nombre,genero,nota_s,director,actores;
    int nota;
    while (true){ 
        if(archivo.eof()) break;
        getline(archivo, nombre);
        getline(archivo, genero);
        getline(archivo, nota_s);
        nota = atoi(nota_s.c_str());
        getline(archivo, director);
        getline(archivo, actores);
        Pelicula* Nueva_pelicula = new Pelicula(nombre, genero, director, nota, actores);
        lista -> agregar(Nueva_pelicula, pos_lista);
        getline(archivo, aux);
        pos_lista++;
    }  
}

bool coinciden_actores(Pelicula* pelicula1,Pelicula* pelicula2){
    for (int i = 1; i <= pelicula1->obtener_actores()->obtener_tamanio(); i++){
        for (int j = 1; i <= pelicula2->obtener_actores()->obtener_tamanio(); j++){
            if(pelicula1->obtener_actores()->consultar(i)->obtener_nombre() == pelicula2->obtener_actores()->consultar(j)->obtener_nombre()){
                return true;
            }
        }
    }
    return false;
}

bool coinciden_directores(Pelicula* pelicula1,Pelicula* pelicula2){
    if(pelicula1->obtener_director() == pelicula2->obtener_director())
        return true;
    return false;
}

void crear_lista_recomendadas(Lista<Pelicula>* vistas,Lista<Pelicula>* no_vistas,Lista<Pelicula>* recomendadas){

    for(int i = 1; i <= vistas->obtener_tamanio();i++){
        for(int j = 1 ; j <= no_vistas->obtener_tamanio();j++){
            if(vistas->consultar(i)->obtener_genero() == no_vistas->consultar(j)->obtener_genero() && (no_vistas->consultar(j)->obtener_puntaje() >= 7 || coinciden_directores(vistas->consultar(i),no_vistas->consultar(j)) || coinciden_actores(vistas->consultar(i),no_vistas->consultar(j)))){
                if(!recomendadas->esta(no_vistas->consultar(j))){
                	Pelicula* aux = no_vistas -> consultar(j);
                	Pelicula* nueva = new Pelicula(aux->obtener_nombre_pelicula(),aux->obtener_genero(),aux->obtener_director(),aux->obtener_puntaje(),aux->obtener_string());
                    recomendadas->agregar(nueva,recomendadas->obtener_tamanio() + 1); //AGREGARLO AL FINAL//
                }
            }
        }
    }    
}

bool operaciones(char comando,Lista<Pelicula>* vistas,Lista<Pelicula>* no_vistas,Lista<Pelicula>* recomendadas){

    switch(comando){

        case'a':
            cout<<"Peliculas vistas:"<<endl<<endl;
            for(int i = 1;i <= vistas->obtener_tamanio();i++){
                Pelicula* aux = vistas->consultar(i);
                aux->imprimir_informacion();
            }
            break;

        case'b':
            cout<<"Peliculas NO vistas:"<<endl<<endl;
            for(int i = 1;i <= no_vistas->obtener_tamanio();i++){
                no_vistas->consultar(i)->imprimir_informacion();
            }
            break;

        case'c':{
            cout<<"Peliculas recomendadas:"<<endl<<endl;
            if(recomendadas->es_vacia()){
                cout<<"No hay peliculas que recomendar"<<endl;
            }
            else{
                for(int i = 1;i <= recomendadas->obtener_tamanio();i++){
                    recomendadas->consultar(i)->imprimir_informacion();
                }
            }
            break;
        }
    
        case'd':
            return false;

    }
    return true;
}
