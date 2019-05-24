#ifndef PELICULA_H
#define PELICULA_H
#include "Lista.h"
#include <iostream>
using namespace std;

class Pelicula{
private:
	string* nombre_pelicula;
	string* genero;
	int* puntaje;
	string* director;
	Lista* actores;

public:
	Pelicula();

	Pelicula(string* nuevo_nombre_pelicula, string* nuevo_genero, string* nuevo_director, int* nuevo_puntaje, Lista* nuevos_actores);

	string obtener_nombre_pelicula();

	string obtener_genero();

	string obtener_director();

	int obtener_puntaje();

	string obtener_actor(int pos);

	void asignar_nombre_pelicula();

	void asignar_genero();

	void asignar_director();

	void asignar_puntaje();

	void asignar_actor(int pos);

	~Pelicula();
};

#endif