#include "Service.h"
#include "Validator.h"
#include <stdlib.h>
#include <string.h>

Service* creeaza_service(Plati* rep) {
	Service* serv = (Service*)malloc(sizeof(Service));

	if (serv == NULL) return NULL;

	serv->repo = rep;

	return serv;
}

void serv_adauga_plata(Service* service, int zi, float suma, char* tip) {
	Plata* plataNoua = creeaza_plata(zi, suma, tip);

	if (plataNoua == NULL) return;
	if (service == NULL || service->repo == NULL) {
		distruge_plata(plataNoua);
		return;
	}

	if (valideaza_plata(plataNoua) == 1) adauga_plata(service->repo, plataNoua);
	else {
		distruge_plata(plataNoua);
	}
}

int serv_sterge_plata(Service* service, Plata* p) {
	if (service == NULL || service->repo == NULL || p == NULL) return 0;

	return sterge_plata(service->repo, p);
}

int serv_modifica_zi(Service* service, Plata* p, int zi) {
	if (service == NULL) return 0;

	Plata* fictiv = creeaza_plata(zi, 2, "Valid");

	if (valideaza_plata(fictiv) == 1) {
		distruge_plata(fictiv);
		modifica_zi(p, zi);
		return 1;
	}

	distruge_plata(fictiv);
	return 0;
}

int serv_modifica_suma(Service* service, Plata* p, float suma) {
	if (service == NULL) return 0;

	Plata* fictiv = creeaza_plata(5, suma, "Valid");

	if (valideaza_plata(fictiv) == 1) {
		distruge_plata(fictiv);
		modifica_suma(p, suma);
		return 1;
	}

	distruge_plata(fictiv);
	return 0;
}

int serv_modifica_tip(Service* service, Plata* p, char* tip) {
	if (service == NULL) return 0;

	Plata* fictiv = creeaza_plata(5, 5, tip);

	if (valideaza_plata(fictiv) == 1) {
		distruge_plata(fictiv);
		modifica_tip(p, tip);
		return 1;
	}

	distruge_plata(fictiv);
	return 0;
}

Plata** serv_plati_ordonat_suma(Service* service, int ord) {
	if (service == NULL || service->repo == NULL || service->repo->v == NULL || service->repo->v->vector == NULL) return NULL;

	Plata** ordonat = (Plata**)malloc(sizeof(Plata*) * service->repo->v->size);

	if (ordonat == NULL) return NULL;

	for (int i = 0; i < service->repo->v->size; ++i) {
		ordonat[i] = (Plata*)service->repo->v->vector[i];
	}

	for (int i = 0; i < service->repo->v->size - 1; ++i) {
		for (int j = i + 1; j < service->repo->v->size; ++j) {
			if (ord == 1 && ordonat[i]->suma > ordonat[j]->suma) {
				Plata* tmp = ordonat[i];
				ordonat[i] = ordonat[j];
				ordonat[j] = tmp;
			}
			else if (ord == 0 && ordonat[i]->suma < ordonat[j]->suma) {
				Plata* tmp = ordonat[i];
				ordonat[i] = ordonat[j];
				ordonat[j] = tmp;
			}
		}
	}

	return ordonat;
}

Plata** serv_plati_ordonat_tip(Service* service, int ord) {
	if (service == NULL || service->repo == NULL || service->repo->v == NULL || service->repo->v->vector == NULL) return NULL;

	Plata** ordonat = (Plata**)malloc(sizeof(Plata*) * service->repo->v->size);

	if (ordonat == NULL) return NULL;

	for (int i = 0; i < service->repo->v->size; ++i) {
		ordonat[i] = (Plata*)service->repo->v->vector[i];
	}

	for (int i = 0; i < service->repo->v->size - 1; ++i) {
		for (int j = i + 1; j < service->repo->v->size; ++j) {
			if (ord == 1 && strcmp(ordonat[i]->tip, ordonat[j]->tip) > 0) {
				Plata* tmp = ordonat[i];
				ordonat[i] = ordonat[j];
				ordonat[j] = tmp;
			}
			else if (ord == 0 && strcmp(ordonat[i]->tip, ordonat[j]->tip) < 0) {
				Plata* tmp = ordonat[i];
				ordonat[i] = ordonat[j];
				ordonat[j] = tmp;
			}
		}
	}

	return ordonat;
}

Plata** serv_plati_filtrat_suma(Service* service, float suma) {
	if (service == NULL || service->repo == NULL || service->repo->v == NULL || service->repo->v->vector == NULL) return NULL;

	Plata** filtrat = (Plata**)malloc(sizeof(Plata*) * service->repo->v->size);

	if (filtrat == NULL) return NULL;

	float eps = 0.01f;
	int j = 0;
	for (int i = 0; i < service->repo->v->size; ++i) {
		if (((Plata*)service->repo->v->vector[i])->suma >= suma - eps) {
			filtrat[j++] = (Plata*)service->repo->v->vector[i];
		}
	}

	if (j != service->repo->v->size) filtrat[j] = NULL; //Va marca sfarsitul vectorului

	return filtrat;
}

void distruge_service(Service* service) {
	sterge_repo(service->repo);
	free(service);
}