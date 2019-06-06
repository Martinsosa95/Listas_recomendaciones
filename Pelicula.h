#ifndef PELICULA_H
#define PELICULA_H
#include "Lista.h"
#include "Actor.h"
#include <iostream>
using namespace std;

class Pelicula{
private:
	string* nombre_pelicula;
	string* genero;
	int* puntaje;
	string* director;
	Lista<Actor>* actores;
	string* actores_s;
	void cargar_actores(string lectura);

public:
	//Descripcion:Constructor sin parametros
	//Pre:---
	//Post:Se crea el objeto pelicula
	Pelicula();

	//Descripcion:Constructor con parametros
	//Pre:---
	//Post:Se crea el objeto pelicula
	Pelicula(string nuevo_nombre_pelicula, string nuevo_genero, string nuevo_director, int nuevo_puntaje, string actores_s_nuevo);

	//Pre:El objeto debe existir
	//Post:Devuelve el nombre de la pelicula
	string obtener_nombre_pelicula();

	//Pre:El objeto debe existir
	//Post:Devuelve el genero de la pelicula	
	string obtener_genero();

	//Pre:El objeto debe existir
	//Post:Devuelve el director de la pelicula
	string obtener_director();

	//Pre:El objeto debe existir
	//Post:Devuelve la linea del archivo de peliculas donde estan los actores
	string obtener_string(); 

	//Pre:El objeto debe existir
	//Post:Devuelve el puntaje de la pelicula
	int obtener_puntaje();

	//Pre:El objeto debe existir
	//Post:Devuelve los actores de la pelicula que fueron cargados
	Lista<Actor>* obtener_actores();

	//Pre:El objeto debe existir
	//Post:Asigna un nuevo nombre a la pelicula
	void asignar_nombre_pelicula(string* nuevo_nombre_pelicula);

	//Pre:El objeto debe existir
	//Post:Asigna un nuevo genero a la pelicula
	void asignar_genero(string* nuevo_genero);

	//Pre:El objeto debe existir
	//Post:Asigna un nuevo director a la pelicula
	void asignar_director(string* nuevo_director);

	//Pre:El objeto debe existir
	//Post:Asigna un nuevo puntaje a la pelicula
	void asignar_puntaje(int* nuevo_puntaje);

	//Pre:El objeto debe existir
	//Post:Asigna un nuevo actor a la pelicula en la posicion pasada por parametro
	void asignar_actor(int pos);

	//Pre:El objeto debe existir
	//Post:Imprime por pantalla la informacion de la pelicula
	void imprimir_informacion();

	//Descripcion:Destructor
	//Pre:El objeto debe existir
	//Post:EL objeto es destruido
	~Pelicula();
};

#endif