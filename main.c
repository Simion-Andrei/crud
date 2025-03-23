#include <stdio.h>
#include "test_plata.h"
#include "test_repo.h"
#include "test_validator.h"
#include "test_service.h"
#include "test_vector.h"
#include "UI.h"
#include <crtdbg.h>
#include <stdlib.h>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	testeaza_vector_all();
	testeaza_plata_all();
	testeaza_repo_all();
	testeaza_valideaza_plata();
	testeaza_service_all();
	Plati* p = creeaza_repo();
	Service* serv = creeaza_service(p);
	//run(serv);
	distruge_service(serv);
	_CrtDumpMemoryLeaks();
}