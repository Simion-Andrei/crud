#include <stdio.h>
#include "test_plata.h"
#include "test_repo.h"
#include "test_validator.h"
#include "test_service.h"
#include "UI.h"
#include <crtdbg.h>

int main()
{
	testeaza_plata_all();
	testeaza_repo_all();
	testeaza_valideaza_plata();
	testeaza_service_all();
	Plati* p = creeaza_repo();
	run(p);
	sterge_repo(p);
	_CrtDumpMemoryLeaks();
	return 0;
}