#pragma once
#include "Service.h"

/*
* Functia care contine loop-ul principal al programului
* Citeste date de la utilizator si apeleaza functiile corespunzatoare acestora
*
* Args:
*	service (Service*) - Service-ul de plati
*/
void run(Service* service);

/*
* Functie care citeste de la utilizator o zi (int), o suma (float) si un tip (char) si creeaza un obiect de tip Plata cu acestea
*
* Args:
*	service (Service*) - Service-ul de plati
*/
void ui_adauga_plata(Service* service);

/*
* Functie care afiseaza platile ordonate, dupa suma acestora
*
* Args:
*	service (Service*) - Service-ul de plati
*	ord (int) - Daca valoarea acestui parametru este 1, platile vor fi ordonate crescator, altfel vor fi ordonate descrescator
*/
void ui_plati_ordonat_suma(Service* service, int ord);

/*
* Functie care afiseaza platile ordonate, dupa tipul acestora
*
* Args:
*	service (Service*) - Service-ul de plati
*	ord (int) - Daca valoarea acestui parametru este 1, platile vor fi ordonate crescator, altfel vor fi ordonate descrescator
*/
void ui_plati_ordonat_tip(Service* service, int ord);

/*
* Functie care afiseaza platile care au suma mai mare decat un numar citit de la utilizator
* 
* Args:
*	service (Service*) - Service-ul de plati
*/
void ui_plati_filtrat_suma(Service* service);

/*
* Functie care afiseaza utilizatorului toate elementele curente, indexate
* Solicita acestuia sa introduca un index si o zi, pentru a schimba ziua platii cu indexul ales in cea introdusa
* Daca dimensiunea vectorului este 0, functia afiseaza un mesaj utilizatorului
*
* Args:
*	service (Service*) - Service-ul de plati
*/
void ui_modifica_zi(Service* service);

/*
* Functie care afiseaza utilizatorului toate elementele curente, indexate
* Solicita acestuia sa introduca un index si o suma, pentru a schimba suma platii cu indexul ales in cea introdusa
* Daca dimensiunea vectorului este 0, functia afiseaza un mesaj utilizatorului
*
* Args:
*	service (Service*) - Service-ul de plati
*/
void ui_modifica_suma(Service* service);

/*
* Functie care afiseaza utilizatorului toate elementele curente, indexate
* Solicita acestuia sa introduca un index si un tip, pentru a schimba tipul platii cu indexul ales in cel introdus
* Daca dimensiunea vectorului este 0, functia afiseaza un mesaj utilizatorului
*
* Args:
*	service (Service*) - Service-ul de plati
*/
void ui_modifica_tip(Service* service);

/*
* Functie care afiseaza utilizatorului toate elementele curente, indexate
* Solicita acestuia sa introduca un index pentru a sterge elementul respectiv
* Daca dimensiunea vectorului este 0, functia afiseaza un mesaj utilizatorului
*
* Args:
*	service (Service*) - Service-ul de plati
*/
void ui_sterge_plata(Service* service);