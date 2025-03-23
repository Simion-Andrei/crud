#pragma once
#include "Repo.h"

typedef struct {
	Plati* repo;
} Service;

Service* creeaza_service(Plati* rep);

/*
* Functie care creeaza o plata cu informatiile oferite si o adauga in repo-ul de plati
* 
* Args:
*	service (Service*) - Service-ul de plati
*	zi (int) - Ziua platii
*	suma (float) - Suma platii
*	tip (char) - Tipul platii
* 
* Returns:
*	1 - daca datele sunt valide si plata a fost creata cu succes
*	0 - daca datele sunt invalide
*/
int serv_adauga_plata(Service* service, int zi, float suma, char* tip);

/*
* Functie care sterge plata 'p' din vectorul de plati
* 
* Args:
*	service (Service*) - Service-ul de plati
*	p (Plata*) - Plata ce va fi stearsa
* 
* Returns:
*	1 - daca obiectul a fost sters cu succes
*	0 - daca obiectul nu a fost gasit si nu a putut fi sters
*/
int serv_sterge_plata(Service* service, Plata* p);

/*
* Functie care modifica ziua platii 'p' in zi
* Functia valideaza valoarea parametrului
* 
* Args:
*	service (Service*) - Service-ul de plati
*	zi (int) - Noua val. ce va fi atribuita parametrului 'zi'
* 
* Returns:
*	1 - daca ziua a fost valida iar plata a fost modificata
*	0 - daca ziua a fost invalida iar plata nu a fost modificata
*/
int serv_modifica_zi(Service* service, Plata* p, int zi);

/*
* Functie care modifica suma platii 'p' in suma
* Functia valideaza valoarea parametrului
* 
* Args:
*	service (Service*) - Service-ul de plati
*	suma (float) - Valoarea in care suma va fi schimbata
* Returns:
*	1 - daca suma a fost valida iar plata a fost modificata
*	0 - daca suma a fost invalida iar plata nu a fost modificata
*/
int serv_modifica_suma(Service* service, Plata* p, float suma);

/*
* Functie care modifica tipul platii 'p' in tip
* Functia valideaza valoarea parametrului
*
* Args:
*	service (Service*) - Service-ul de plati
*	tip (char) - Valoarea in care tipul va fi schimbat
* 
* Returns:
*	1 - daca tipul a fost valid iar plata a fost modificata
*	0 - daca tipul a fost invalid iar plata nu a fost modificata
*/
int serv_modifica_tip(Service* service, Plata* p, char* tip);

/*
* Functie care creeaza un vector de plati ordonat dupa suma
*
* Args:
*	service (Service*) - Service-ul de plati
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
*	service (Service*) - Service-ul de plati
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
*	service (Service*) - Service-ul de plati
*	suma (float) - Valoarea sumei de filtrare
* 
* Returns:
*	filtrat (Plata**) - Un vector ce contine toate platile cu suma mai mare decat parametrul transmis
*	NULL - daca spatiul pentru acest vector nu a putut fi alocat
*/
Plata** serv_plati_filtrat_suma(Service* service, float suma);

/*
* Functie care elibereaza blocul de memorie alocat service-ului
* 
* Args:
*	service (Service*) - Service-ul de plati
*/
void distruge_service(Service* service);