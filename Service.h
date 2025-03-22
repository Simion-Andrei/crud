#pragma once
#include "Repo.h"

typedef struct {
	Plati* repo;
} Service;

Service* creeaza_service(Plati* rep);

/*
* Functie care creeaza o plata cu informatiile oferite si o adauga vectorului de plati
* 
* Args:
*	plati (Plati*) - Repo-ul de plati
*	zi (int) - Ziua platii
*	suma (float) - Suma platii
*	tip (char) - Tipul platii
*/
void serv_adauga_plata(Service* service, int zi, float suma, char* tip);

/*
* Functie care sterge plata 'p' din vectorul de plati
* 
* Args:
*	plati (Plati*) - Vectorul de plati
*	p (Plata*) - Plata ce va fi stearsa
*/
int serv_sterge_plata(Service* service, Plata* p);

/*
* Functie care modifica ziua platii 'p' in zi
* Functia valideaza valoarea parametrului
* 
* Args:
*	p (Plata*) - Plata a carei zi va fi schimbata
*	zi (int) - Noua val. ce va fi atribuita parametrului 'zi'
*/
int serv_modifica_zi(Service* service, Plata* p, int zi);

/*
* Functie care modifica suma platii 'p' in suma
* Functia valideaza valoarea parametrului
* 
* Args:
*	p (Plata*) - Plata a carei sume va fi schimbata
*	suma (float) - Valoarea in care suma va fi schimbata
*/
int serv_modifica_suma(Service* service, Plata* p, float suma);

/*
* Functie care modifica tipul platii 'p' in tip
* Functia valideaza valoarea parametrului
*
* Args:
*	p (Plata*) - Plata al carei tip va fi schimbat
*	tip (char) - Valoarea in care tipul va fi schimbat
*/
int serv_modifica_tip(Service* service, Plata* p, char* tip);

/*
* Functie care creeaza un vector de plati ordonat dupa suma
*
* Args:
*	p (Plati*) - Vectorul de plati
*	ord (int) - Daca valoarea acestui parametru este 1, vectorul va fi sortat crescator, altfel el va fi sortat descrescator
*
* Returns:
*	ordonat (Plata**) - Un vector ce contine adresele platilor, ordonat dupa suma
*	NULL - daca spatiul pentru acest vector nu a putut fi alocat
*/
Plata** serv_plati_ordonat_suma(Service* service, int ord);

/*
* Functie care creeaza un vector de plati ordonat dupa tip
*
* Args:
*	p (Plati*) - Vectorul de plati
*	ord (int) - Daca valoarea acestui parametru este 1, vectorul va fi sortat crescator, altfel el va fi sortat descrescator
*
* Returns:
*	ordonat (Plata**) - Un vector ce contine adresele platilor, ordonat dupa tip
*	NULL - daca spatiul pentru acest vector nu a putut fi alocat
*/
Plata** serv_plati_ordonat_tip(Service* service, int ord);

/*
* Functie care creeaza un vector ce contine toate platile cu suma mai mare decat parametrul transmis
* 
* Args:
*	p (Plati* p) - Vectorul de plati
*	suma (float) - Valoarea sumei de filtrare
* 
* Returns:
*	filtrat (Plata**) - Un vector ce contine toate platile cu suma mai mare decat parametrul transmis
*	NULL - daca spatiul pentru acest vector nu a putut fi alocat
*/
Plata** serv_plati_filtrat_suma(Service* service, float suma);

void distruge_service(Service* service);