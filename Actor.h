#ifndef ACTOR_H
#define ACTOR_H
#include "Lista.h"
#include <iostream>
using namespace std;

class Actor{
	private:
		string* nombre;

	public:
		//Descripcion:Constructor
		//Pre:---
		//Post:Se crea el objeto actor
		Actor(string nuevo_nombre);

		//Pre:El objeto debe existir
		//Post:Devuelve el nombre del actor
		string obtener_nombre();

		//Pre:El objeto debe existir
		//Post:Asigna un nuevo nombre al actor
		void asignar_nombre(string* nuevo_nombre);

		//Descripcion:Destructor
		//Pre:El objeto debe existir
		//Post:EL objeto es destruido
		~Actor();
	
};

#endif