#include "Repo.h"
#include <stdlib.h>

Plati* creeaza_repo() {
	Plati* p = (Plati*)malloc(sizeof(Plati));

	if (p == NULL) return NULL;

	p->v = creeaza_vector();

	if (p->v == NULL) {
		free(p);
		return NULL;
	}

	return p;
}

void adauga_plata(Plati* plati, Plata* plata) {
	if (plati == NULL || plata == NULL || plati->v == NULL) return;

	add(plati->v, plata);
}

int sterge_plata(Plati* plati, Plata* plata) {
	if (plati == NULL || plata == NULL || plati->v == NULL) return 0;

	for (int i = 0; i < plati->v->size; ++i) {
		if (plata == (Plata*)plati->v->vector[i]) {
			del(plati->v, i);
			distruge_plata(plata);
			return 1;
		}
	}

	return 0;
}

void sterge_repo(Plati* plati) {
	if (plati == NULL || plati->v == NULL) return;

	for (int i = 0; i < plati->v->size; ++i) {
		distruge_plata(plati->v->vector[i]);
	}

	distruge(plati->v);
	free(plati);
}