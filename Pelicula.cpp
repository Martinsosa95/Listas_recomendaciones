#include"Pelicula.h"

Pelicula(string* nuevo_nombre_pelicula, string* nuevo_genero, string* nuevo_director, int* nuevo_puntaje, Lista* nuevos_actores){
	nombre_pelicula = nuevo_nombre_pelicula;
	genero = nuevo_genero;
	director = nuevo_director;
	puntaje = nuevo_puntaje;
	actores = nuevos_actores;
}

string obtener_nombre_pelicula(){
	return *nombre_pelicula;
}

string obtener_genero(){
	return *genero;
}

string obtener_director(){
	return *director;
}

int obtener_puntaje(){
	return *puntaje;
}

string obtener_actor(int pos){

}

void asignar_nombre_pelicula(string* nuevo_nombre_pelicula){
	nombre_pelicula = nuevo_nombre_pelicula;
}

void asignar_genero(string* nuevo_genero){
	genero = nuevo_genero;
}

void asignar_director(string* nuevo_director){
	director = nuevo_director;
}

int* asignar_puntaje(int* nuevo_puntaje){
	puntaje = nuevo_puntaje;
}

void asignar_actor(int pos){

}