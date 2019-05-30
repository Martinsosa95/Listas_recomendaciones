#include"Pelicula.h"

Pelicula::Pelicula(){

}

Pelicula::Pelicula(string nuevo_nombre_pelicula, string nuevo_genero, string nuevo_director, int nuevo_puntaje, Lista<Actor>* nuevos_actores){
	nombre_pelicula = new string;
	genero = new string;
	director = new string;
	puntaje = new int;
	cout << "Pido Memoria Pelicula" << endl;
	*nombre_pelicula = nuevo_nombre_pelicula;
	*genero = nuevo_genero;
	*director = nuevo_director;
	*puntaje = nuevo_puntaje;
	actores = nuevos_actores;
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

void Pelicula::eliminar_actores(){
	for(int i=0;i<actores -> obtener_tamanio();i++)
		while(!actores -> es_vacia())
			actores -> eliminar(1);
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
	cout << "Borro Peliculas" << endl;
	eliminar_actores();
	delete actores;
	cout << "Borro Lista de Actores" << endl;
}