#include"Pelicula.h"

Pelicula::Pelicula(){

}

Pelicula::Pelicula(string nuevo_nombre_pelicula, string nuevo_genero, string nuevo_director, int nuevo_puntaje, string actores_s_nuevo){
	nombre_pelicula = new string;
	genero = new string;
	director = new string;
	puntaje = new int;
	actores = new Lista<Actor>;
	actores_s = new string;

	cout << "Pido Memoria Pelicula" << endl;

	*nombre_pelicula = nuevo_nombre_pelicula;
	*genero = nuevo_genero;
	*director = nuevo_director;
	*puntaje = nuevo_puntaje;
	*actores_s = actores_s_nuevo;
	cargar_actores(actores_s_nuevo);
}

void Pelicula::cargar_actores(string lectura){
    int pos_lista = 1;
    int i =0;
    int ant = 0;
    string actor;
    while( (char)lectura[i] != 0){
        if(lectura[i]==' ' || (char)lectura[i] == 9){
            actor = lectura.substr(ant,i-ant);
            Actor* Aactor = new Actor(actor);
            actores-> agregar(Aactor, pos_lista);
            ant = i + 1;
            pos_lista++;
        }
        i++;
    }
    actor = lectura.substr(ant,i-ant);
    Actor* Aactor = new Actor(actor);
    actores -> agregar(Aactor, pos_lista);
}

string Pelicula::obtener_nombre_pelicula(){
	return *nombre_pelicula;
}

string Pelicula::obtener_genero(){
	return *genero;
}

string Pelicula::obtener_director(){
	return *director;
}

string Pelicula::obtener_string(){
	return *actores_s;
}

int Pelicula::obtener_puntaje(){
	return *puntaje;
}

Lista<Actor>* Pelicula::obtener_actores(){  
	return actores;
}

void Pelicula::asignar_nombre_pelicula(string* nuevo_nombre_pelicula){
	*nombre_pelicula = *nuevo_nombre_pelicula;
}

void Pelicula::asignar_genero(string* nuevo_genero){
	*genero = *nuevo_genero;
}

void Pelicula::asignar_director(string* nuevo_director){
	*director = *nuevo_director;
}

void Pelicula::asignar_puntaje(int* nuevo_puntaje){
	*puntaje = *nuevo_puntaje;
}

void Pelicula::asignar_actor(int pos){

}


void Pelicula::imprimir_informacion(){
	cout<<"Nombre :"<< *nombre_pelicula<<endl;
	cout<<"Genero :"<< *genero <<endl;
	cout<<"Puntaje :"<< *puntaje<<endl;
	cout<<"Director :"<< *director<<endl;
	cout<<"Actores:";

	for(int i = 1;i <= actores->obtener_tamanio();i++){
		cout<< actores->consultar(i)->obtener_nombre()<<" ";
	}

	cout<<endl<<endl;
}

Pelicula::~Pelicula(){
	delete nombre_pelicula;
	delete genero;
	delete director;
	delete puntaje;
	delete actores_s;
	cout << "Borro Peliculas" << endl;
	delete actores;
	cout << "Borro Lista de Actores" << endl;
}