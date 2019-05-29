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

void cargar_actores(string lectura, Lista<Actor>* lista){
    int pos_lista = 1;
    int i =0;
    int ant = 0;
    string actor;
    while( (char)lectura[i] != 0){
        if(lectura[i]==' '){
            actor = lectura.substr(ant,i-ant);
            Actor* Aactor = new Actor(actor);
            lista-> agregar(Aactor, pos_lista);
            ant = i + 1;
            pos_lista++;
        }
        i++;
    }
    actor = lectura.substr(ant,i-ant);
    Actor* Aactor = new Actor(actor);
    lista-> agregar(Aactor, pos_lista);

}

void cargar_lista(ifstream &archivo,Lista<Pelicula>* lista){
    int pos_lista = 1;
    string aux;
    string nombre;
    string genero;
    int nota;
    string nota_s;
    string director;
    string actores;
    while (true){ 
        if(archivo.eof()) break;
        getline(archivo, nombre);
        getline(archivo, genero);
        getline(archivo, nota_s);
        nota = atoi(nota_s.c_str());
        getline(archivo, director);
        getline(archivo, actores);
        Lista<Actor>* lista_actores = new Lista<Actor>;
        cargar_actores(actores, lista_actores);
        Pelicula* Nueva_pelicula = new Pelicula(nombre, genero, director, nota, lista_actores);
        lista -> agregar(Nueva_pelicula, pos_lista);
        getline(archivo, aux);
        pos_lista++;
    }  
    //delete nombre;
    //delete genero;
    //delete nota;
    //delete director;
    //delete actores;
}

bool coinciden_actores(Pelicula* pelicula1,Pelicula* pelicula2){
    for (int i = 1; i <= pelicula1->obtener_actores()->obtener_tamanio(); i++){
        for (int j = 1; i <= pelicula2->obtener_actores()->obtener_tamanio(); j++){
            if(pelicula1->obtener_actores()->consultar(i) == pelicula2->obtener_actores()->consultar(j)){
                return true;
            }
        }
    }
   
    return false;
}

bool coinciden_directores(Pelicula* pelicula1,Pelicula* pelicula2){

    if(pelicula1->obtener_director() == pelicula2->obtener_director()){
        return true;
    }

    return false;
}

Lista<Pelicula>* crear_lista_recomendadas(Lista<Pelicula>* vistas,Lista<Pelicula>* no_vistas){

    Lista<Pelicula>* recomendadas = new Lista<Pelicula>;

    for(int i = 1; i <= vistas->obtener_tamanio();i++){
        for(int j = 1 ; j <= no_vistas->obtener_tamanio();j++){
            if(vistas->consultar(i)->obtener_genero() == no_vistas->consultar(j)->obtener_genero() && (no_vistas->consultar(j)->obtener_puntaje() >= 7 || coinciden_directores(vistas->consultar(i),no_vistas->consultar(j)) || coinciden_actores(vistas->consultar(i),no_vistas->consultar(j)))){
                if(!recomendadas->esta(no_vistas->consultar(j))){
                    recomendadas->agregar(no_vistas->consultar(j),recomendadas->obtener_tamanio() + 1); //AGREGARLO AL FINAL//
                }
            }
        }
    }    

    return recomendadas;
}

bool operaciones(char comando,Lista<Pelicula>* vistas,Lista<Pelicula>* no_vistas){

    switch(comando){

        case'a':
            for(int i = 1;i <= vistas->obtener_tamanio();i++){
                Pelicula* aux = vistas->consultar(i);
                aux->imprimir_informacion();
            }
            break;

        case'b':
            for(int i = 1;i <= no_vistas->obtener_tamanio();i++){
                no_vistas->consultar(i)->imprimir_informacion();
            }
            break;

        case'c':{
            Lista<Pelicula>* recomendadas = crear_lista_recomendadas(vistas,no_vistas);
            for(int i = 1;i <= recomendadas->obtener_tamanio();i++){
                recomendadas->consultar(i)->imprimir_informacion();
            }
            break;
        }
    
        case'd':
            return false;

    }

    return true;
}
