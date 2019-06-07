#ifndef FUNCIONES_MAIN_H
#define FUNCIONES_MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include "Lista.h"
#include "Pelicula.h"
#include "Actor.h"


void cargar_lista(ifstream &archivo,Lista<Pelicula>* lista);

bool coinciden_actores(Pelicula* pelicula1,Pelicula* pelicula2);

bool coinciden_directores(Pelicula* pelicula1,Pelicula* pelicula2);

void crear_lista_recomendadas(Lista<Pelicula>* vistas,Lista<Pelicula>* no_vistas,Lista<Pelicula>* recomendadas);

void menu();

bool operaciones(char comando,Lista<Pelicula>* vistas,Lista<Pelicula>* no_vistas,Lista<Pelicula>* recomendadas);

#endif