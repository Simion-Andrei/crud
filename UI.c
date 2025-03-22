#include "UI.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void run(Service* service) {
	while (1) {
		char s[20];

		printf("<<<");

		if (scanf("%s", s) == 0) {
			printf("\n");
			continue;
		}
		else {
			s[19] = '\0';
			if (strcmp(s, "adauga_plata") == 0) ui_adauga_plata(service);
			else if (strcmp(s, "modifica_zi") == 0) ui_modifica_zi(service);
			else if (strcmp(s, "modifica_suma") == 0) ui_modifica_suma(service);
			else if (strcmp(s, "modifica_tip") == 0) ui_modifica_tip(service);
			else if (strcmp(s, "sterge_plata") == 0) ui_sterge_plata(service);
			else if (strcmp(s, "ordonat_crescator_suma") == 0) ui_plati_ordonat_suma(service, 1);
			else if (strcmp(s, "ordonat_descrescator_suma") == 0) ui_plati_ordonat_suma(service, 0);
			else if (strcmp(s, "ordonat_crescator_tip") == 0) ui_plati_ordonat_tip(service, 1);
			else if (strcmp(s, "ordonat_descrescator_tip") == 0) ui_plati_ordonat_tip(service, 0);
			else if (strcmp(s, "filtrat_suma") == 0) ui_plati_filtrat_suma(service);
			else if (strcmp(s, "end") == 0) return;
			else printf("\n");
		}
	}
}

void ui_plati_ordonat_suma(Service* service, int ord) {
	if (service->repo->v->size == 0) {
		printf("Lista de plati este momental goala!\n");
		return;
	}

	Plata** ordonat = serv_plati_ordonat_suma(service, ord);

	if (ordonat == NULL) {
		printf("Nu s-a putut efectua ordonarea!\n");
		return;
	}

	for (int i = 0; i < service->repo->v->size; ++i) {
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, ordonat[i]->tip, ordonat[i]->suma, ordonat[i]->zi);
	}

	free(ordonat);
}

void ui_plati_ordonat_tip(Service* service, int ord) {
	if (service->repo->v->size == 0) {
		printf("Lista de plati este momental goala!\n");
		return;
	}

	Plata** ordonat = serv_plati_ordonat_tip(service, ord);

	if (ordonat == NULL) {
		printf("Nu s-a putut efectua ordonarea!\n");
		return;
	}

	for (int i = 0; i < service->repo->v->size; ++i) {
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, ordonat[i]->tip, ordonat[i]->suma, ordonat[i]->zi);
	}

	free(ordonat);
}

void ui_plati_filtrat_suma(Service* service) {
	float suma;
	printf("Suma cu care se va face filtrarea: ");
	if (scanf("%f", &suma) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	Plata** filtrat = serv_plati_filtrat_suma(service, suma);

	if (filtrat == NULL) {
		printf("Nu s-a putut efectua filtrarea!\n");
		return;
	}

	for (int i = 0; i < service->repo->v->size && filtrat[i] != NULL; ++i) {
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, filtrat[i]->tip, filtrat[i]->suma, filtrat[i]->zi);
	}

	free(filtrat);
}

void ui_adauga_plata(Service* service) {
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
	serv_adauga_plata(service, zi, suma, tip);
}

void ui_modifica_zi(Service* service) {
	if (service->repo->v->size == 0) {
		printf("Lista de plati este goala, nu poti modifica nimic!\n");
		return;
	}

	for (int i = 0; i < service->repo->v->size; ++i) {
		Plata* p = (Plata*)service->repo->v->vector[i];
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, p->tip, p->suma, p->zi);
	}

	printf("Introdu indexul platii pe care vrei sa o modifici sau 0 daca vrei sa renunti: ");
	
	int idx;
	if (scanf("%d", &idx) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	if (idx == 0) return;

	if (idx < 0 || idx > service->repo->v->size) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	int zi;

	printf("Ziua platii: ");
	if (scanf("%d", &zi) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	int rasp = serv_modifica_zi(service, (Plata*)service->repo->v->vector[idx-1], zi);

	if (rasp == 1) {
		printf("Ziua a fost modificata cu succes!\n");
	}
	else printf("Parametru invalid!");
}

void ui_modifica_suma(Service* service) {
	if (service->repo->v->size == 0) {
		printf("Lista de plati este goala, nu poti modifica nimic!\n");
		return;
	}

	for (int i = 0; i < service->repo->v->size; ++i) {
		Plata* p = (Plata*)service->repo->v->vector[i];
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, p->tip, p->suma, p->zi);
	}

	printf("Introdu indexul platii pe care vrei sa o modifici sau 0 daca vrei sa renunti: ");

	int idx;
	if (scanf("%d", &idx) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	if (idx == 0) return;

	if (idx < 0 || idx > service->repo->v->size) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	float suma;

	printf("Suma platii: ");
	if (scanf("%f", &suma) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	int rasp = serv_modifica_suma(service, (Plata*)service->repo->v->vector[idx - 1], suma);

	if (rasp == 1) {
		printf("Syna a fost modificata cu succes!\n");
	}
	else printf("Parametru invalid!");
}

void ui_modifica_tip(Service* service) {
	if (service->repo->v->size == 0) {
		printf("Lista de plati este goala, nu poti modifica nimic!\n");
		return;
	}

	for (int i = 0; i < service->repo->v->size; ++i) {
		Plata* p = (Plata*)service->repo->v->vector[i];
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, p->tip, p->suma, p->zi);
	}

	printf("Introdu indexul platii pe care vrei sa o modifici sau 0 daca vrei sa renunti: ");

	int idx;
	if (scanf("%d", &idx) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	if (idx == 0) return;

	if (idx < 0 || idx > service->repo->v->size) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	char tip[25];

	printf("Tipul platii: ");
	if (scanf("%s", tip) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	int rasp = serv_modifica_tip(service, (Plata*)service->repo->v->vector[idx - 1], tip);

	if (rasp == 1) {
		printf("Syna a fost modificata cu succes!\n");
	}
	else printf("Parametru invalid!");
}

void ui_sterge_plata(Service* service) {
	if (service->repo->v->size == 0) {
		printf("Lista de plati este goala, nu poti sterge nimic!\n");
		return;
	}

	for (int i = 0; i < service->repo->v->size; ++i) {
		Plata* p = (Plata*)service->repo->v->vector[i];
		printf("%d.TIP: %s SUMA: %f ZIUA: %d\n", i + 1, p->tip, p->suma, p->zi);
	}

	printf("Introdu indexul platii pe care vrei sa o stergi sau 0 daca vrei sa renunti: ");

	int idx;
	if (scanf("%d", &idx) == 0) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	if (idx == 0) return;

	if (idx < 0 || idx > service->repo->v->size) {
		printf("PARAMETRU INVALID\n");
		return;
	}

	int rasp = serv_sterge_plata(service, (Plata*)service->repo->v->vector[idx-1]);

	if (rasp == 1) printf("Plata a fost stearsa cu succes!\n");
	else printf("Nu s-a gasit plata cautata!\n");
}