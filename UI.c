#include "UI.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void run(Plati* p) {
	while (1) {
		char s[20];

		printf("<<<");

		if (scanf("%s", s) == 0) {
			printf("\n");
			continue;
		}
		else {
			s[19] = '\0';
			if (strcmp(s, "adauga_plata") == 0) ui_adauga_plata(p);
			else if (strcmp(s, "modifica_zi") == 0) ui_modifica_zi(p);
			else if (strcmp(s, "modifica_suma") == 0) ui_modifica_suma(p);
			else if (strcmp(s, "modifica_tip") == 0) ui_modifica_tip(p);
			else if (strcmp(s, "sterge_plata") == 0) ui_sterge_plata(p);
			else if (strcmp(s, "ordonat_crescator_suma") == 0) ui_plati_ordonat_suma(p, 1);
			else if (strcmp(s, "ordonat_descrescator_suma") == 0) ui_plati_ordonat_suma(p, 0);
			else if (strcmp(s, "ordonat_crescator_tip") == 0) ui_plati_ordonat_tip(p, 1);
			else if (strcmp(s, "ordonat_descrescator_tip") == 0) ui_plati_ordonat_tip(p, 0);
			else if (strcmp(s, "filtrat_suma") == 0) ui_plati_filtrat_suma(p);
			else if (strcmp(s, "end") == 0) return;
			else printf("\n");
		}
	}
}

void ui_plati_ordonat_suma(Plati* p, int ord) {
	if (p->dimensiune == 0) {
		printf("Lista de plati este momental goala!\n");
		return;
	}

	Plata** ordonat = serv_plati_ordonat_suma(p, ord);

	if (ordonat == NULL) {
		printf("Nu s-a putut efectua ordonarea!\n");
		return;
	}

	for (int i = 0; i < p->dimensiune; ++i) {
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, ordonat[i]->tip, ordonat[i]->suma, ordonat[i]->zi);
	}

	free(ordonat);
}

void ui_plati_ordonat_tip(Plati* p, int ord) {
	if (p->dimensiune == 0) {
		printf("Lista de plati este momental goala!\n");
		return;
	}

	Plata** ordonat = serv_plati_ordonat_tip(p, ord);

	if (ordonat == NULL) {
		printf("Nu s-a putut efectua ordonarea!\n");
		return;
	}

	for (int i = 0; i < p->dimensiune; ++i) {
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, ordonat[i]->tip, ordonat[i]->suma, ordonat[i]->zi);
	}

	free(ordonat);
}

void ui_plati_filtrat_suma(Plati* p) {
	float suma;
	printf("Suma cu care se va face filtrarea: ");
	if (scanf("%f", &suma) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	Plata** filtrat = serv_plati_filtrat_suma(p, suma);

	if (filtrat == NULL) {
		printf("Nu s-a putut efectua filtrarea!\n");
		return;
	}

	for (int i = 0; i < p->dimensiune && filtrat[i] != NULL; ++i) {
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, filtrat[i]->tip, filtrat[i]->suma, filtrat[i]->zi);
	}

	free(filtrat);
}

void ui_adauga_plata(Plati* p) {
	int zi;
	float suma;
	char tip[25];

	printf("Ziua platii: ");
	if (scanf("%d", &zi) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	printf("Suma platii: ");
	if (scanf("%f", &suma) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	printf("Tipul platii: ");
	if (scanf("%s", tip) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}
	
	tip[24] = '\0';
	serv_adauga_plata(p, zi, suma, tip);
}

void ui_modifica_zi(Plati* p) {
	if (p->dimensiune == 0) {
		printf("Lista de plati este goala, nu poti modifica nimic!\n");
		return;
	}

	for (int i = 0; i < p->dimensiune; ++i) {
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, p->content[i]->tip, p->content[i]->suma, p->content[i]->zi);
	}

	printf("Introdu indexul platii pe care vrei sa o modifici sau 0 daca vrei sa renunti: ");
	
	int idx;
	if (scanf("%d", &idx) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	if (idx == 0) return;

	if (idx < 0 || idx > p->dimensiune) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	int zi;

	printf("Ziua platii: ");
	if (scanf("%d", &zi) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	serv_modifica_zi(p->content[idx-1], zi);
}

void ui_modifica_suma(Plati* p) {
	if (p->dimensiune == 0) {
		printf("Lista de plati este goala, nu poti modifica nimic!\n");
		return;
	}

	for (int i = 0; i < p->dimensiune; ++i) {
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, p->content[i]->tip, p->content[i]->suma, p->content[i]->zi);
	}

	printf("Introdu indexul platii pe care vrei sa o modifici sau 0 daca vrei sa renunti: ");

	int idx;
	if (scanf("%d", &idx) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	if (idx == 0) return;

	if (idx < 0 || idx > p->dimensiune) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	float suma;

	printf("Suma platii: ");
	if (scanf("%f", &suma) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	serv_modifica_suma(p->content[idx - 1], suma);
}

void ui_modifica_tip(Plati* p) {
	if (p->dimensiune == 0) {
		printf("Lista de plati este goala, nu poti modifica nimic!\n");
		return;
	}

	for (int i = 0; i < p->dimensiune; ++i) {
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, p->content[i]->tip, p->content[i]->suma, p->content[i]->zi);
	}

	printf("Introdu indexul platii pe care vrei sa o modifici sau 0 daca vrei sa renunti: ");

	int idx;
	if (scanf("%d", &idx) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	if (idx == 0) return;

	if (idx < 0 || idx > p->dimensiune) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	char tip[25];

	printf("Tipul platii: ");
	if (scanf("%s", tip) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	serv_modifica_tip(p->content[idx - 1], tip);
}

void ui_sterge_plata(Plati* p) {
	if (p->dimensiune == 0) {
		printf("Lista de plati este goala, nu poti sterge nimic!\n");
		return;
	}

	for (int i = 0; i < p->dimensiune; ++i) {
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, p->content[i]->tip, p->content[i]->suma, p->content[i]->zi);
	}

	printf("Introdu indexul platii pe care vrei sa o stergi sau 0 daca vrei sa renunti: ");

	int idx;
	if (scanf("%d", &idx) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	if (idx == 0) return;

	if (idx < 0 || idx > p->dimensiune) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	sterge_plata(p, p->content[idx - 1]);
}