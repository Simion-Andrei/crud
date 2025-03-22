#pragma once

typedef void* TElem;

typedef struct {
	TElem* vector;
	int size;
	int capacitate;
} Vector;

/*
* Functie care creeaza un vector dinamic cu capacitatea initiala 10
* 
* Returns:
*	Adresa vectorului - daca a fost creat cu succes
*	NULL - daca nu s-a putut aloca memoria necesara initializarii
*/
Vector* creeaza_vector();

/*
* Functie care adauga elementul 'elem' la vectorul v
* 
* Args:
*	v (Vector*) - Vectorul dinamic
*	elem (TElem) - Elementul ce va fi adaugat vectorului
*/
void add(Vector* v, TElem elem);

/*
* Functie care sterge elementul de pe pozitia idx din vector
* 
* Args:
*	v (Vector*) - Vectorul dinamic
*	idx (int) - Indexul elementul care va fi sters din vector
* 
* Returns:
*	1 - Daca elementul a fost sters
*	0 - Daca elementul nu a fost sters
*/
int del(Vector* v, int idx);

/*
* Functie care dealoca memoria alocata vectorului v
* 
* Args:
*	v (Vector*) - Vectorul dinamic
*/
void distruge(Vector* v);