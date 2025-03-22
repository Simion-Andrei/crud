#include "test_vector.h"
#include "VectorDinamic.h"
#include <assert.h>
#include <string.h>

void testeaza_vector_all() {
	testeaza_creeaza_vector();
	testeaza_add();
	testeaza_del();
}

void testeaza_creeaza_vector() {
	Vector* v = creeaza_vector();

	assert(v->size == 0);
	assert(v->capacitate == 10);
	assert(v->vector != NULL);

	distruge(v);
}

void testeaza_add() {
	Vector* v = creeaza_vector();
	int b = 5;
	void* ptr = &b;

	add(v, ptr);

	assert(*(int*)v->vector[0] == b);
	assert(v->size == 1);

	char* t = "da";
	ptr = t;

	add(v, ptr);

	assert(strcmp((char*)v->vector[1], t) == 0);

	distruge(v);
}

void testeaza_del() {
	Vector* v = creeaza_vector();
	int b = 5;
	void* ptr = &b;
	add(v, ptr);
	char* t = "da";
	ptr = t;
	add(v, ptr);

	assert(*(int*)v->vector[0] == b);
	assert(strcmp((char*)v->vector[1], t) == 0);

	del(v, 0);

	assert(strcmp((char*)v->vector[0], t) == 0);

	del(v, 0);

	assert(v->size == 0);

	distruge(v);
}