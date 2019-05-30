#ifndef ACTOR_H
#define ACTOR_H
#include "Lista.h"
#include <iostream>
using namespace std;

class Actor{
	private:
		string* nombre;

	public:
		Actor(string nuevo_nombre);

		string obtener_nombre();

		void asignar_nombre(string* nuevo_nombre);
	
};

#endif