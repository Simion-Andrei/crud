#include "VectorDinamic.h"
#include <stdio.h>
#include <stdlib.h>

Vector* creeaza_vector() {
	Vector* ref = (Vector*)malloc(sizeof(Vector));

	if (ref == NULL) return NULL;

	ref->capacitate = 10;
	ref->size = 0;

	ref->vector = (TElem*)malloc(sizeof(TElem) * ref->capacitate);

	if (ref->vector == NULL) {
		free(ref);
		return NULL;
	}

	return ref;
}

void add(Vector* v, TElem elem) {
	if (v == NULL) return;

	v->vector[v->size++] = elem;

	if (v->size == v->capacitate) redimensioneaza(v);
}

int del(Vector* v, int idx) {
	if (idx < 0 || idx >= v->size || v == NULL) return 0;

	v->size--;
	for (int i = idx; i < v->size; ++i) {
		v->vector[i] = v->vector[i + 1];
	}
}

void redimensioneaza(Vector* v) {
	if (v == NULL) return;

	TElem* ref = v->vector;

	v->capacitate *= 2;
	v->vector = (TElem*)malloc(sizeof(TElem) * v->capacitate);

	if (v->vector == NULL) {
		v->capacitate /= 2;
		v->vector = ref;
		return;
	}

	memcpy(v->vector, ref, sizeof(TElem) * v->size);
}