#include "Actor.h"


Actor::Actor(string nuevo_nombre){
	nombre = new string;
	*nombre = nuevo_nombre;
	cout << "Creo actor" << endl;
}

string Actor::obtener_nombre(){
	return *nombre;
}

void Actor::asignar_nombre(string* nuevo_nombre){
	nombre = nuevo_nombre;
}

Actor::~Actor(){
	cout << "Borro Actor" << endl;
	delete nombre;
}
