#include "Validator.h"
#include <string.h>

int valideaza_plata(Plata* p) {
	if (p->zi <= 0 || p->zi > 31) return 0;
	if (p->suma <= 0) return 0;
	if (strcmp(p->tip, "") == 0) return 0;

	return 1;
}