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

public:
	Pelicula();

	Pelicula(string nuevo_nombre_pelicula, string nuevo_genero, string nuevo_director, int nuevo_puntaje, Lista<Actor>* nuevos_actores);

	string obtener_nombre_pelicula();

	string obtener_genero();

	string obtener_director();

	int obtener_puntaje();

	Lista<Actor>* obtener_actores();

	void asignar_nombre_pelicula(string* nuevo_nombre_pelicula);

	void asignar_genero(string* nuevo_genero);

	void asignar_director(string* nuevo_director);

	void asignar_puntaje(int* nuevo_puntaje);

	void asignar_actor(int pos);

	void imprimir_informacion();

	~Pelicula();
};

#endif