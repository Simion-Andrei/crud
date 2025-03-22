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
	Plati* repo = creeaza_repo();
	Service* service = creeaza_service(repo);
	serv_adauga_plata(service, 2, 2, "T1");
	serv_adauga_plata(service, 2, 3, "T3");
	serv_adauga_plata(service, 2, 1, "T2");

	Plata** p1 = serv_plati_filtrat_suma(service, 1);

	assert(p1[0]->suma == 2);
	assert(p1[1]->suma == 3);
	assert(p1[2]->suma == 1);

	Plata** p2 = serv_plati_filtrat_suma(service, 3);

	assert(p2[0]->suma == 3);
	assert(p2[1] == NULL);

	free(p1);
	free(p2);

	distruge_service(service);
}

void testeaza_serv_plati_ordonat_tip() {
	Plati* repo = creeaza_repo();
	Service* service = creeaza_service(repo);
	serv_adauga_plata(service, 2, 2, "T1");
	serv_adauga_plata(service, 2, 3, "T3");
	serv_adauga_plata(service, 2, 1, "T2");

	Plata** p1 = serv_plati_ordonat_tip(service, 1);

	assert(p1[0]->suma == 2);
	assert(p1[1]->suma == 1);
	assert(p1[2]->suma == 3);

	Plata** p2 = serv_plati_ordonat_tip(service, 0);

	assert(p2[0]->suma == 3);
	assert(p2[1]->suma == 1);
	assert(p2[2]->suma == 2);

	free(p1);
	free(p2);

	distruge_service(service);
}

void testeaza_serv_plati_ordonat_suma() {
	Plati* repo = creeaza_repo();
	Service* service = creeaza_service(repo);
	serv_adauga_plata(service, 2, 2, "T1");
	serv_adauga_plata(service, 2, 3, "T2");
	serv_adauga_plata(service, 2, 1, "T3");

	Plata** p1 = serv_plati_ordonat_suma(service, 1);

	assert(strcmp(p1[0]->tip, "T3") == 0);
	assert(strcmp(p1[1]->tip, "T1") == 0);
	assert(strcmp(p1[2]->tip, "T2") == 0);

	Plata** p2 = serv_plati_ordonat_suma(service, 0);

	assert(strcmp(p2[0]->tip, "T2") == 0);
	assert(strcmp(p2[1]->tip, "T1") == 0);
	assert(strcmp(p2[2]->tip, "T3") == 0);

	free(p1);
	free(p2);

	distruge_service(service);
}

void testeaza_serv_adauga_plata() {
	Plati* repo = creeaza_repo();
	Service* service = creeaza_service(repo);
	float eps = 0.01f;
	float suma1 = 2.55f;
	float suma2 = 5.55f;

	serv_adauga_plata(service, 2, suma1, "Ceva");

	assert(((Plata*)repo->v->vector[0])->zi == 2);
	assert(((Plata*)repo->v->vector[0])->suma >= 2.55 - eps && ((Plata*)repo->v->vector[0])->suma <= 2.55 + eps);
	assert(strcmp(((Plata*)repo->v->vector[0])->tip, "Ceva") == 0);

	serv_adauga_plata(service, 0, suma1, "Ceva");
	assert(repo->v->size == 1);

	serv_adauga_plata(service, 2, -suma1, "Ceva");
	assert(repo->v->size == 1);

	serv_adauga_plata(service, 2, suma2, "");
	assert(repo->v->size == 1);

	distruge_service(service);
}

void testeaza_serv_sterge_plata() {
	Plati* repo = creeaza_repo();
	Service* service = creeaza_service(repo);
	Plata* p = creeaza_plata(5, 2, "ceva");

	adauga_plata(repo, p);

	assert(repo->v->size == 1);

	serv_sterge_plata(service, p);

	assert(repo->v->size == 0);

	serv_sterge_plata(service, NULL);
	serv_sterge_plata(service, p);

	assert(repo->v->size == 0);

	distruge_service(service);
}

void testeaza_serv_modifica_zi() {
	Plati* repo = creeaza_repo();
	Service* service = creeaza_service(repo);

	Plata* p = creeaza_plata(5, 2, "ceva");

	serv_modifica_zi(service, p, 15);
	assert(p->zi == 15);
	serv_modifica_zi(service, p, 22);
	assert(p->zi == 22);

	serv_modifica_zi(service, p, 50);
	assert(p->zi == 22);

	distruge_plata(p);
	distruge_service(service);
}

void testeaza_serv_modifica_suma() {
	Plati* repo = creeaza_repo();
	Service* service = creeaza_service(repo);

	Plata* p = creeaza_plata(5, 2, "ceva");
	float eps = 0.01f;

	serv_modifica_suma(service, p, 2.32f);
	assert(p->suma >= 2.32 - eps && p->suma <= 2.32f + eps);
	serv_modifica_suma(service, p, 5.55f);
	assert(p->suma >= 5.55 - eps && p->suma <= 5.55f + eps);

	serv_modifica_suma(service, p, 0);
	assert(p->suma >= 5.55f - eps && p->suma <= 5.55f + eps);
	serv_modifica_suma(service, p, -1.254f);
	assert(p->suma >= 5.55f - eps && p->suma <= 5.55f + eps);

	distruge_plata(p);
	distruge_service(service);
}

void testeaza_serv_modifica_tip() {
	Plati* repo = creeaza_repo();
	Service* service = creeaza_service(repo);

	Plata* p = creeaza_plata(5, 2, "ceva");

	serv_modifica_tip(service, p, "Altceva");
	assert(strcmp(p->tip, "Altceva") == 0);
	serv_modifica_tip(service, p, "test");
	assert(strcmp(p->tip, "test") == 0);

	serv_modifica_tip(service, p, "");
	assert(strcmp(p->tip, "test") == 0);

	distruge_plata(p);
	distruge_service(service);
}