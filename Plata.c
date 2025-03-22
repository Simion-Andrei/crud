#include "Plata.h"
#include <stdlib.h>
#include <string.h>

Plata* creeaza_plata(int zi, float suma, char* tip) {
	Plata* p = (Plata*)malloc(sizeof(Plata));
	if (p == NULL) return NULL;

	p->zi = zi;
	p->suma = suma;
	p->tip = (char*)malloc(sizeof(char) * (strlen(tip) + 1));

	if (p->tip == NULL) return NULL;
	strcpy(p->tip, tip);

	return p;
}

void modifica_zi(Plata* p, int zi) {
	if (p == NULL) return;

	p->zi = zi;
}

void modifica_suma(Plata* p, float suma) {
	if (p == NULL) return;

	p->suma = suma;
}

void modifica_tip(Plata* p, char* tip) {
	if (p == NULL || tip == NULL) return;

	char* tmp = (char*)realloc(p->tip, strlen(tip) + 1); // Realocam memoria sirului de caractere 'tip', cu noua dimensiune

	if (tmp) {
		p->tip = tmp;
		strcpy(p->tip, tip);
	}
}

void distruge_plata(Plata* p) {
	if (p == NULL || p->tip == NULL) return;

	free((p)->tip);
	(p)->tip = NULL;
	free(p);
}