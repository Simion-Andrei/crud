#include "Service.h"
#include "Validator.h"
#include <stdlib.h>
#include <string.h>

void serv_adauga_plata(Plati* plati, int zi, float suma, char* tip) {
	Plata* plataNoua = creeaza_plata(zi, suma, tip);

	if (plataNoua == NULL) return;
	if (plati == NULL) {
		distruge_plata(plataNoua);
		return;
	}

	if (valideaza_plata(plataNoua) == 1) adauga_plata(plati, plataNoua);
}

void serv_sterge_plata(Plati* plati, Plata* p) {
	if (plati == NULL || p == NULL) return;

	sterge_plata(plati, p);
}

void serv_modifica_zi(Plata* p, int zi) {
	Plata* fictiv = creeaza_plata(zi, 2, "Valid");

	if (valideaza_plata(fictiv) == 1) modifica_zi(p, zi);

	distruge_plata(fictiv);
}

void serv_modifica_suma(Plata* p, float suma) {
	Plata* fictiv = creeaza_plata(5, suma, "Valid");

	if (valideaza_plata(fictiv) == 1) modifica_suma(p, suma);

	distruge_plata(fictiv);
}

void serv_modifica_tip(Plata* p, char* tip) {
	Plata* fictiv = creeaza_plata(5, 5, tip);

	if (valideaza_plata(fictiv) == 1) modifica_tip(p, tip);

	distruge_plata(fictiv);
}

Plata** serv_plati_ordonat_suma(Plati* p, int ord) {
	Plata** ordonat = (Plata**)malloc(sizeof(Plata*) * p->dimensiune);

	if (ordonat == NULL) return NULL;

	for (int i = 0; i < p->dimensiune; ++i) {
		ordonat[i] = p->content[i];
	}

	for (int i = 0; i < p->dimensiune - 1; ++i) {
		for (int j = i + 1; j < p->dimensiune; ++j) {
			if (ord == 1 && ordonat[i]->suma > ordonat[j]->suma) {
				Plata* tmp = ordonat[i];
				ordonat[i] = ordonat[j];
				ordonat[j] = tmp;
			}
			else if (ord == 0 && ordonat[i]->suma < ordonat[j]->suma) {
				Plata* tmp = ordonat[i];
				ordonat[i] = ordonat[j];
				ordonat[j] = tmp;
			}
		}
	}

	return ordonat;
}

Plata** serv_plati_ordonat_tip(Plati* p, int ord) {
	Plata** ordonat = (Plata**)malloc(sizeof(Plata*) * p->dimensiune);

	if (ordonat == NULL) return NULL;

	for (int i = 0; i < p->dimensiune; ++i) {
		ordonat[i] = p->content[i];
	}

	for (int i = 0; i < p->dimensiune - 1; ++i) {
		for (int j = i + 1; j < p->dimensiune; ++j) {
			if (ord == 1 && strcmp(ordonat[i]->tip, ordonat[j]->tip) > 0) {
				Plata* tmp = ordonat[i];
				ordonat[i] = ordonat[j];
				ordonat[j] = tmp;
			}
			else if (ord == 0 && strcmp(ordonat[i]->tip, ordonat[j]->tip) < 0) {
				Plata* tmp = ordonat[i];
				ordonat[i] = ordonat[j];
				ordonat[j] = tmp;
			}
		}
	}

	return ordonat;
}

Plata** serv_plati_filtrat_suma(Plati* p, float suma) {
	Plata** filtrat = (Plata**)malloc(sizeof(Plata*) * p->dimensiune);

	if (filtrat == NULL) return NULL;

	float eps = 0.01f;
	int j = 0;
	for (int i = 0; i < p->dimensiune; ++i) {
		if (p->content[i]->suma >= suma - eps) {
			filtrat[j++] = p->content[i];
		}
		
	}

	if (j != p->dimensiune) filtrat[j] = NULL; //Va marca sfarsitul vectorului

	return filtrat;
}