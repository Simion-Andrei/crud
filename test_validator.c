#include "test_validator.h"
#include "Validator.h"
#include "Plata.h"
#include <assert.h>

void testeaza_valideaza_plata() {
	Plata* p = creeaza_plata(-1, 1, "ceva");
	
	assert(valideaza_plata(p) == 0);
	distruge_plata(p);

	p = creeaza_plata(1, -1, "ceva");

	assert(valideaza_plata(p) == 0);
	distruge_plata(p);

	p = creeaza_plata(32, 0, "ceva");

	assert(valideaza_plata(p) == 0);
	distruge_plata(p);

	p = creeaza_plata(25, 0, "");

	assert(valideaza_plata(p) == 0);
	distruge_plata(p);

	p = creeaza_plata(25, 0.25, "ceva");

	assert(valideaza_plata(p) == 1);
	distruge_plata(p);
}