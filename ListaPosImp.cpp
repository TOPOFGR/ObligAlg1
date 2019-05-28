#include "ListaPosImp.h"

#ifndef LISTAPOSIMP_CPP
#define LISTAPOSIMP_CPP

template <class T>
inline ostream & operator<<(ostream &out, const ListaPosImp<T> &l){
	l.Imprimir(out);
	return out;
}

template <class T>
ListaPos<T>* ListaPosImp<T>::CrearVacia() const
{
	return new ListaPosImp<T>();
}

template <class T>
ListaPosImp<T>::ListaPosImp(){
	this->largo = 0;
	this->fin = NULL;
	this->ppio = NULL;
	this->pos = 0;

}

template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPos<T> &l){
	this->fin = NULL;
	this->ppio = NULL;
	this->largo = 0;
	this->pos = 0;

	*this = l;
}

template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPosImp<T> &l){
	this->fin = NULL;
	this->ppio = NULL;
	this->largo = 0;
	this->pos;

	*this = l;

}

template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPos<T> &l)
{
	if (this != &l) {
		this->Vaciar();
		
		for (int i = 0; i < largo;i++) {
			AgregarFin(l.ElementoPos(i));
		}
	}
	return *this;
}

template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPosImp<T> &l)
{
	if (this != &l) {
		this->Vaciar();
		for (int i = 0; i < largo; i++) {
			AgregarImp(i++);
		}
	}
	return *this;
}

template <class T>
ListaPosImp<T>::~ListaPosImp()
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaPosImp<T>::AgregarPpio(const T &e) {
	if (EsVacia()){
		this->ppio = new NodoLista<T>();
		this->ppio->dato = e;
		this->ppio->ant = NULL;
		this->ppio->sig = NULL;
		this->fin = this->ppio;
	}else {
		NodoLista<T> * nuevo = new NodoLista<T>();
		nuevo->dato = e;
		nuevo->ant = NULL;
		nuevo->sig = this->ppio;
		this->ppio = nuevo;
	}
}

template <class T>
void ListaPosImp<T>::AgregarFin(const T &e) {
	if (this->fin == NULL) {
		this->ppio = new NodoLista<T>();
		this->ppio->dato = e;
		this->ppio->ant = NULL;
		this->ppio->sig = NULL;
		this->fin = this->ppio;
	}
	else {
		NodoLista<T> * nuevo = new NodoLista<T>();
		nuevo->dato = e;
		nuevo->sig = NULL;
		nuevo->ant = this->fin;
		this->fin = nuevo;
	}
}

template <class T>
void ListaPosImp<T>::AgregarPos(const T &e, unsigned int pos){
	NodoLista<T> *aux = ppio;
	while (pos!=0){
		pos--;
		aux = aux->
	}

}

template <class T>
void ListaPosImp<T>::BorrarPpio(){
	NodoLista * aux = this->ppio;
	this->ppio= this->ppio->sig;
	delete aux;
	aux = NULL;
	this->ppio->ant= NULL;
}

template <class T>
void ListaPosImp<T>::BorrarFin(){
	NodoLista<T> * aux = this->fin;
	this->fin = this->fin->ant;
	delete aux;
	aux = NULL;
	this->fin->sig = NULL;
}

void BorrarAux(NodoLista<T> *&l ) {
	if (l != NULL) {
		NodoLista<T>* aux = l;
		l = l->ant;
		l->sig = l->sig->sig;
		delete aux;
		aux = l->sig;
		aux->ant = l;
	}
}


template <class T>
void ListaPosImp<T>::BorrarPos(unsigned int pos){
	// NO IMPLEMENTADA
	NodoLista<T> *aux = ppio;
	while (pos!=0){
		aux = aux->sig;
		pos--;
	}
	BorrarAux(this);
}

template <class T>
void ListaPosImp<T>::Borrar(const T &e){
	if (this->fin != NULL && Existe(e){
		NodoLista<T> * aux = this->ppio;
		while (aux->dato!=e) {
			aux=aux->sig;	
		}
		if (aux == e) BorrarAux(aux);
	}
}

template <class T>
T& ListaPosImp<T>::ElementoPpio() const
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
T& ListaPosImp<T>::ElementoFin() const
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
T& ListaPosImp<T>::ElementoPos(unsigned int pos) const
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
unsigned int ListaPosImp<T>::Posicion(const T &e) const
{
	// NO IMPLEMENTADA
	return 0;
}

template <class T>
bool ListaPosImp<T>::Existe(const T &e) const
{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
void ListaPosImp<T>::Vaciar(){
	// NO IMPLEMENTADA
	NodoLista<T> * aux = fin;
	while (fin!=NULL) {
		fin = fin->ant;
		delete aux;
		aux = fin;
	}
}

template <class T>
unsigned int ListaPosImp<T>::CantidadElementos() const{ 
	return this->largo; 
}

template <class T>
bool ListaPosImp<T>::EsVacia() const{
	return this->largo==0;
}

template <class T>
bool ListaPosImp<T>::EsLlena() const{
	//IMPLEMENTADA
	return false;
}

template <class T>
ListaPos<T>* ListaPosImp<T>::Clon() const{
	// NO IMPLEMENTADA
	return new ListaPosImp<T>();
}

template <class T>
Iterador<T> ListaPosImp<T>::GetIterador() const
{
	return IteradorListaPosImp<T>(*this);
}

template <class T>
void ListaPosImp<T>::Imprimir(ostream& o) const
{
	// NO IMPLEMENTADA
	// en luegar de hacer cout << ... poner o << ...
}

#endif