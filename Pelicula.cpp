#include"Pelicula.h"

Pelicula::Pelicula(){

}

Pelicula::Pelicula(string* nuevo_nombre_pelicula, string* nuevo_genero, string* nuevo_director, int* nuevo_puntaje, Lista<string>* nuevos_actores){
	*nombre_pelicula = *nuevo_nombre_pelicula;
	*genero = *nuevo_genero;
	*director =* nuevo_director;
	*puntaje = *nuevo_puntaje;
	*actores = *nuevos_actores;
	//Lista<string>* actores = new Lista<string>;
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

string Pelicula::obtener_actor(int pos){

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
Pelicula::~Pelicula(){

}