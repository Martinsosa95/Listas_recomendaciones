#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

//template <class Dato>
template <typename Dato>
class Nodo{

private:
	Dato* elemento;
	Nodo* psig;
public:
	//Descripcion:Constructor con un parametro
	//Pre:---
	//Post:El objeto es creado con los el valor d para elemento y le asigna a psig el valor por defecto
	
	Nodo(Dato* d);
	//Descripcion:Constructor con parametros
	//Pre:---
	//Post:Crea un objeto Nodo
	Nodo(Dato* d, Nodo* psig);
	
	//Pre:El objeto debe existir
	//Post:Se modifico el valor de elemento
	void asignar_elemento(Dato* d);
	
	//Pre:El objeto debe existir
	//Post:Se modifico el valor de psig
	void asignar_siguiente(Nodo* psig);
	
	//Pre:El objeto debe existir
	//Post:Devuelve el valor de elemento
	Dato* obtener_elemento();
	
	//Pre:El objeto debe existir
	//Post:Devuelve el valor de siguiente
	Nodo* obtener_siguiente();
	
	//Descripcion:Destructor
	//Pre:El objeto debe existir
	//Post:El objeto es destruido
	~Nodo();

};

template <typename Dato>
Nodo<Dato>::Nodo(Dato* d){
	elemento = d;
	psig=NULL;
}

template <typename Dato>
Nodo<Dato>::Nodo(Dato* d, Nodo* sig){
	elemento = d;
	psig = sig;
}

template <typename Dato>
void Nodo<Dato>::asignar_elemento(Dato* d){
	elemento = d;
}

template <typename Dato>
void Nodo<Dato>::asignar_siguiente(Nodo* sig){
	psig = sig;
}

template <typename Dato>
Dato* Nodo<Dato>::obtener_elemento(){
	return elemento;
}

template <typename Dato>
Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){
	return psig;
}
template <typename Dato>
Nodo<Dato>::~Nodo(){
	delete elemento;
	
}
#endif