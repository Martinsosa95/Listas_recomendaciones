#ifndef FUNCIONES_MAIN_H
#define FUNCIONES_MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include "Lista.h"
#include "Pelicula.h"
#include "Actor.h"

//Pre:El archivo debe existir y se tiene que poder leer, el objeto pelicula debe existir
//Post:Se va a cargar todos los datos de las peliculas en la lista pasada por parametro
void cargar_lista(ifstream &archivo,Lista<Pelicula>* lista);

//Pre:Los objetos pelicula deben existir
//Post:Devuelve true en caso de que 2 peliculas coincidan los nombres de los actores sino devuelve false
bool coinciden_actores(Pelicula* pelicula1,Pelicula* pelicula2);

//Pre:Los objetos pelicula deben existir
//Post:Devuelve true en caso de que 2 peliculas coincidan los nombres de los directores sino devuelve false
bool coinciden_directores(Pelicula* pelicula1,Pelicula* pelicula2);

//Pre:Los objetos pelicula deben existir y las listas ,salvo la de recomendadas, deben estar cargadas
//Post:Crea una nueva lista con las peliculas recomendadas
void crear_lista_recomendadas(Lista<Pelicula>* vistas,Lista<Pelicula>* no_vistas,Lista<Pelicula>* recomendadas);

//Pre:------
//Post:Imprime por pantalla el menu de operaciones
void menu();

//Pre:Los objetos pelicula deben existir y las listas ,deben estar cargadas
//Post:Se va a realizar la oparacion dependiendo del comando pasado por parametro
bool operaciones(char comando,Lista<Pelicula>* vistas,Lista<Pelicula>* no_vistas,Lista<Pelicula>* recomendadas);

#endif