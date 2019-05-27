#include <iostream>
#include <fstream>
#include <string>
#include "Lista.h"
#include "Pelicula.h"

void cargar_actores(string lectura, Lista<string>* lista);

void cargar_lista(ifstream &archivo,Lista<Pelicula>* lista);
