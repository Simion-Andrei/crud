#pragma once
#include "Plata.h"

/*
* Functie care valideaza plata p
* P este valida daca:
*1.Ziua ei este un numar natural intre 1 si 31
*2.Suma ei este un numar rational >= 0
*3.Tipul ei nu este un sir de caractere vid
*
* Arg:
*	p (Plata*) - O plata
*
* Returns:
*	1 - daca plata este valida
*	0 - daca plata nu este valida
*/
int valideaza_plata(Plata* p);