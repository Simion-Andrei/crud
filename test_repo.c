#include "test_repo.h"
#include "Repo.h"
#include <assert.h>
#include <stddef.h>

void testeaza_repo_all() {
	testeaza_creeaza_repo();
	testeaza_adauga_plata();
	testeaza_sterge_plata();
	testeaza_sterge_repo();
}

void testeaza_creeaza_repo() {
	Plati* p = creeaza_repo();

	assert(p->capacitate == 5);
	assert(p->dimensiune == 0);
	assert(p->content != NULL);

	sterge_repo(p);
}

void testeaza_adauga_plata() {
	Plati* plati = creeaza_repo();
	Plata* plata1 = creeaza_plata(1, 22.3f, "Nu stiu");

	adauga_plata(plati, plata1);
	
	assert(plati->dimensiune == 1);
	assert(plati->content[0] == plata1);

	adauga_plata(plati, NULL);

	assert(plati->dimensiune == 1);

	Plata* plata2 = creeaza_plata(7, 53.3f, "Random");

	adauga_plata(plati, plata2);

	assert(plati->dimensiune == 2);
	assert(plati->content[1] == plata2);

	Plata* plata3 = creeaza_plata(7, 53.3f, "Random");
	Plata* plata4 = creeaza_plata(7, 53.3f, "Random");
	Plata* plata5 = creeaza_plata(7, 53.3f, "Random");
	Plata* plata6 = creeaza_plata(7, 53.3f, "Random");
	adauga_plata(plati, plata3);
	adauga_plata(plati, plata4);
	adauga_plata(plati, plata5);
	adauga_plata(plati, plata6);

	assert(plati->dimensiune == 6);
	assert(plati->capacitate == 10);

	sterge_repo(plati);
}

void testeaza_sterge_plata() {
	Plati* plati = creeaza_repo();
	Plata* plata1 = creeaza_plata(1, 22.3f, "Nu stiu");
	Plata* plata2 = creeaza_plata(7, 53.3f, "Random");

	sterge_plata(plati, NULL);
	assert(plati->dimensiune == 0);
	sterge_plata(plati, plata1);
	assert(plati->dimensiune == 0);

	adauga_plata(plati, plata1);
	adauga_plata(plati, plata2);

	assert(plati->dimensiune == 2);

	sterge_plata(plati, plata1);

	assert(plati->dimensiune == 1);
	assert(plati->content[0] == plata2);

	sterge_repo(plati);
}

void testeaza_sterge_repo() {
	Plati* plati = creeaza_repo();
	Plata* plata1 = creeaza_plata(1, 22.3f, "Nu stiu");
	Plata* plata2 = creeaza_plata(7, 53.3f, "Random");

	adauga_plata(plati, plata1);
	adauga_plata(plati, plata2);

	sterge_repo(plati);
}