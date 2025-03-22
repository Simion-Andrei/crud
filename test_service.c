#include "test_service.h"
#include "Service.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void testeaza_service_all() {
	testeaza_serv_adauga_plata();
	testeaza_serv_sterge_plata();
	testeaza_serv_modifica_zi();
	testeaza_serv_modifica_suma();
	testeaza_serv_modifica_tip();
	testeaza_serv_plati_ordonat_suma();
	testeaza_serv_plati_ordonat_tip();
	testeaza_serv_plati_filtrat_suma();
}

void testeaza_serv_plati_filtrat_suma() {
	Plati* plati = creeaza_repo();
	serv_adauga_plata(plati, 2, 2, "T1");
	serv_adauga_plata(plati, 2, 3, "T3");
	serv_adauga_plata(plati, 2, 1, "T2");

	Plata** p1 = serv_plati_filtrat_suma(plati, 1);

	assert(p1[0]->suma == 2);
	assert(p1[1]->suma == 3);
	assert(p1[2]->suma == 1);

	Plata** p2 = serv_plati_filtrat_suma(plati, 3);

	assert(p2[0]->suma == 3);
	assert(p2[1] == NULL);

	free(p1);
	free(p2);

	sterge_repo(plati);
}

void testeaza_serv_plati_ordonat_tip() {
	Plati* plati = creeaza_repo();
	serv_adauga_plata(plati, 2, 2, "T1");
	serv_adauga_plata(plati, 2, 3, "T3");
	serv_adauga_plata(plati, 2, 1, "T2");

	Plata** p1 = serv_plati_ordonat_tip(plati, 1);

	assert(p1[0]->suma == 2);
	assert(p1[1]->suma == 1);
	assert(p1[2]->suma == 3);

	Plata** p2 = serv_plati_ordonat_tip(plati, 0);

	assert(p2[0]->suma == 3);
	assert(p2[1]->suma == 1);
	assert(p2[2]->suma == 2);

	free(p1);
	free(p2);

	sterge_repo(plati);
}

void testeaza_serv_plati_ordonat_suma() {
	Plati* plati = creeaza_repo();
	serv_adauga_plata(plati, 2, 2, "T1");
	serv_adauga_plata(plati, 2, 3, "T2");
	serv_adauga_plata(plati, 2, 1, "T3");

	Plata** p1 = serv_plati_ordonat_suma(plati, 1);

	assert(strcmp(p1[0]->tip, "T3") == 0);
	assert(strcmp(p1[1]->tip, "T1") == 0);
	assert(strcmp(p1[2]->tip, "T2") == 0);

	Plata** p2 = serv_plati_ordonat_suma(plati, 0);

	assert(strcmp(p2[0]->tip, "T2") == 0);
	assert(strcmp(p2[1]->tip, "T1") == 0);
	assert(strcmp(p2[2]->tip, "T3") == 0);

	free(p1);
	free(p2);

	sterge_repo(plati);
}

void testeaza_serv_adauga_plata() {
	Plati* plati = creeaza_repo();
	float eps = 0.01f;
	float suma1 = 2.55f;
	float suma2 = 5.55f;

	serv_adauga_plata(plati, 2, suma1, "Ceva");

	assert(plati->content[0]->zi == 2);
	assert(plati->content[0]->suma >= 2.55 - eps && plati->content[0]->suma <= 2.55 + eps);
	assert(strcmp(plati->content[0]->tip, "Ceva") == 0);

	serv_adauga_plata(plati, 0, suma1, "Ceva");
	assert(plati->dimensiune == 1);

	serv_adauga_plata(plati, 2, -suma1, "Ceva");
	assert(plati->dimensiune == 1);

	serv_adauga_plata(plati, 2, suma2, "");
	assert(plati->dimensiune == 1);

	sterge_repo(plati);
}

void testeaza_serv_sterge_plata() {
	Plati* plati = creeaza_repo();
	Plata* p = creeaza_plata(5, 2, "ceva");

	adauga_plata(plati, p);

	assert(plati->dimensiune == 1);

	serv_sterge_plata(plati, p);

	assert(plati->dimensiune == 0);

	serv_sterge_plata(plati, NULL);
	serv_sterge_plata(plati, p);

	assert(plati->dimensiune == 0);

	sterge_repo(plati);
}

void testeaza_serv_modifica_zi() {
	Plata* p = creeaza_plata(5, 2, "ceva");

	serv_modifica_zi(p, 15);
	assert(p->zi == 15);
	serv_modifica_zi(p, 22);
	assert(p->zi == 22);

	serv_modifica_zi(p, 50);
	assert(p->zi == 22);

	distruge_plata(p);
}

void testeaza_serv_modifica_suma() {
	Plata* p = creeaza_plata(5, 2, "ceva");
	float eps = 0.01f;

	serv_modifica_suma(p, 2.32f);
	assert(p->suma >= 2.32 - eps && p->suma <= 2.32f + eps);
	serv_modifica_suma(p, 5.55f);
	assert(p->suma >= 5.55 - eps && p->suma <= 5.55f + eps);

	serv_modifica_suma(p, 0);
	assert(p->suma >= 5.55f - eps && p->suma <= 5.55f + eps);
	serv_modifica_suma(p, -1.254f);
	assert(p->suma >= 5.55f - eps && p->suma <= 5.55f + eps);

	distruge_plata(p);
}

void testeaza_serv_modifica_tip() {
	Plata* p = creeaza_plata(5, 2, "ceva");

	serv_modifica_tip(p, "Altceva");
	assert(strcmp(p->tip, "Altceva") == 0);
	serv_modifica_tip(p, "test");
	assert(strcmp(p->tip, "test") == 0);

	serv_modifica_tip(p, "");
	assert(strcmp(p->tip, "test") == 0);

	distruge_plata(p);
}