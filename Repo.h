#pragma once
#include "Plata.h"
#include "VectorDinamic.h"

typedef struct{
	Vector* v;
} Plati;

/*
* Functie care creaza un nou repository de plati
*
* Returns:
*	Un pointer catre tipul de date creat
*	NULL, daca memoria nu a putut fi alocata
*/
Plati* creeaza_repo();

/*
* Functie care adauga obiectul plata la vectorul de plati
* Daca capacitatea vectorului curent este depasita, dimensiunea acestuia va fi realocata apeland functia redimensioneaza_repo
*
* Args:
*	plati (Plati*) - Vectorul dinamic de plati
*	plata (Plata*) - Plata ce va fi adaugata la vectorul de plati
*/
void adauga_plata(Plati* plati, Plata* plata);

/*
* Functie care sterge obiectul plata din vectorul de plati
* Blocul de memorie ocupat de element va fi dealocat
* Elementele vor fi rearanjate dupa stergerea obiectului
* Dimensiunea vectorului va fi redusa cu 1
*
* Args:
*	plati (Plati*) - Vectorul dinamic de plati
*	plata (Plata*) - Plata ce va fi stearsa din vectorul de plati
* 
* Returns:
*	1 - Daca elementul a fost gasit si sters
*	0 - Daca elementul nu a fost gasit
*/
int sterge_plata(Plati* plati, Plata* plata);

/*
* Functie care elibereaza blocul de memoriei alocat obiectului referit de 'plati'
* Dupa efectuarea functiei, pointerul va deveni nul
*
* Args:
*	plati (Plati*) - Repoul de plati
*/
void sterge_repo(Plati* plati);