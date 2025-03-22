#include "Repo.h"
#include <stdlib.h>

Plati* creeaza_repo() {
	Plati* p = (Plati*)malloc(sizeof(Plati));

	if (p == NULL) return NULL;

	p->dimensiune = 0;
	p->capacitate = 5;

	p->content = (Plata**)malloc(sizeof(Plata*) * p->capacitate);

	return p;
}

static void redimensioneaza_repo(Plati* p, int capacitateNoua) {
	if (p == NULL) return;

	Plata** temp = (Plata**)malloc(sizeof(Plata*) * capacitateNoua);

	if (temp == NULL) return;

	// Copiem valorile din vectorul vechi in cel nou
	for (int i = 0; i < p->dimensiune; ++i) {
		temp[i] = p->content[i];
	}

	free(p->content); // Eliberam blocul de memorie alocat vectorului precedent
	p->content = temp;
	p->capacitate = capacitateNoua;
}

void adauga_plata(Plati* plati, Plata* plata) {
	if (plati == NULL || plata == NULL) return;

	if (plati->dimensiune == plati->capacitate) redimensioneaza_repo(plati, plati->capacitate * 2);

	plati->content[plati->dimensiune] = plata;
	plati->dimensiune++;
}

void sterge_plata(Plati* plati, Plata* plata) {
	if (plati == NULL || plata == NULL) return;

	if (plati->dimensiune == 0) return;

	short int gasit = 0;
	for (int i = 0; i < plati->dimensiune; ++i) {
		if (plati->content[i] == plata) {
			gasit = 1;
			Plata* deSters = plati->content[i];
			distruge_plata(deSters);
		}

		if (gasit && i < plati->dimensiune - 1) {
			plati->content[i] = plati->content[i + 1];
		}
	}

	plati->dimensiune--;
}

void sterge_repo(Plati* plati) {
	if (plati == NULL || plati->content == NULL) return;

	for (int i = 0; i < plati->dimensiune; ++i) {
		distruge_plata(plati->content[i]);
	}

	free(plati->content);
	free(plati);
}