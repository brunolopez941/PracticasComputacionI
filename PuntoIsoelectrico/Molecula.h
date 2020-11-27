#pragma once
#include <string>
#include <vector>

#include "Grupo.h"

using namespace std;

class Molecula {
private:
	string nombreMolecula;
	vector<Grupo> grupos;
public:
	Molecula(string nom) { nombreMolecula = nom; };
	void AgregarGrupo(Grupo nuevoGrupo);
	float CalcularPuntoIsoelectrico();
};