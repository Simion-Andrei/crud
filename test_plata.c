#include "Plata.h"
#include "test_plata.h"
#include <assert.h>
#include <string.h>

void testeaza_plata_all() {
	testeaza_creeaza_plata();
	testeaza_modifica_zi();
	testeaza_modifica_suma();
	testeaza_modifica_tip();
	testeaza_distruge_plata();
}

void testeaza_creeaza_plata() {
	float eps = 0.01f;

	Plata* p1 = creeaza_plata(1, 2.34f, "ceva");
	Plata* p2 = creeaza_plata(4, 5.555f, "altceva");

	assert(p1->zi == 1);
	assert(p1->suma >= 2.34f - eps && p1->suma <= 2.34f + eps);
	assert(strcmp("ceva", p1->tip) == 0);

	assert(p2->zi == 4);
	assert(p2->suma >= 5.555f - eps && p2->suma <= 5.555f + eps);
	assert(strcmp("altceva", p2->tip) == 0);
}

void testeaza_modifica_zi() {
	Plata* p1 = creeaza_plata(1, 2.34f, "ceva");
	Plata* p2 = creeaza_plata(4, 5.555f, "altceva");

	modifica_zi(p1, 2);
	assert(p1->zi == 2);

	modifica_zi(p2, 4);
	assert(p2->zi == 4);
}

void testeaza_modifica_suma() {
	float eps = 0.01f;

	Plata* p1 = creeaza_plata(1, 2.34f, "ceva");
	Plata* p2 = creeaza_plata(4, 5.555f, "altceva");

	modifica_suma(p1, 2.555f);
	assert(p1->suma >= 2.555f - eps && p1->suma <= 2.555f + eps);

	modifica_suma(p2, 15.434f);
	assert(p2->suma >= 15.434f - eps && p2->suma <= 15.434f + eps);
}

void testeaza_modifica_tip() {
	Plata* p1 = creeaza_plata(1, 2.34f, "ceva");
	Plata* p2 = creeaza_plata(4, 5.555f, "altceva");

	modifica_tip(p1, "salut");
	assert(strcmp(p1->tip, "salut") == 0);

	modifica_tip(p2, "testdrivendevelopment");
	assert(strcmp(p2->tip, "testdrivendevelopment") == 0);
}

void testeaza_distruge_plata() {
	Plata* p1 = creeaza_plata(1, 2.34f, "ceva");
	Plata* p2 = creeaza_plata(4, 5.555f, "altceva");

	distruge_plata(p1);
	distruge_plata(p2);
}