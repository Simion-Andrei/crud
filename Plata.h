#pragma once

typedef struct{
	int zi;
	float suma;
	char* tip;
} Plata;

/*
* Functie care creeaza un obiect de tip plata cu parametrii primiti
*
* Args:
*	zi (int) - Ziua in care s-a efectuat plata
*	suma (float) - Suma platii
*	tip (char*) - Tipul platii (ex. : Mancare, utilitati, etc.)
*
* Returns:
*	Adresa obiectului creat (Plata*) daca acesta a fost creat cu succes
*	NULL - daca acesta nu a putut fi creat
*/
Plata* creeaza_plata(int zi, float suma, char* tip);

/*
* Functie care modifica ziua obiectului de tip plata p
*
* Args:
*	p (Plata*) - Plata a carei zi trebuie modificata (p != NULL)
*	zi (int) - Valoare zilei noi
*/
void modifica_zi(Plata* p, int zi);

/*
* Functie care modifica suma obiectului de tip plata p
*
* Args:
*	p (Plata*) - Plata a carei zi trebuie modificata (p != NULL)
*	suma (float) - Valoare sumei noi
*/
void modifica_suma(Plata* p, float suma);

/*
* Functie care modifica tipul obiectului de tip plata p
*
* Args:
*	p (Plata*) - Plata a carei zi trebuie modificata (p != NULL)
*	tip (char*) - Tipul nou (tip != NULL)
*/
void modifica_tip(Plata* p, char* tip);

/*
* Functie care elibereaza memoria ocupata de obiectul p
*
* Args:
*	p (Plata*) - Plata care va fi stearsa
*/
void distruge_plata(Plata* p);