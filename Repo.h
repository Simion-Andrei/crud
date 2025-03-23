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
* Functie care adauga obiectul plata in repo-ul de plati
*
* Args:
*	plati (Plati*) - Repo-ul de plati
*	plata (Plata*) - Plata ce va fi adaugata la vectorul de plati
*/
void adauga_plata(Plati* plati, Plata* plata);

/*
* Functie care sterge obiectul plata din repo-ul de plati
* Blocul de memorie ocupat de element va fi dealocat
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
* Functie care elibereaza blocul de memoriei alocat repo-ului
*
* Args:
*	plati (Plati*) - Repoul de plati
*/
void sterge_repo(Plati* plati);