#pragma once
#include <string>

using namespace std;

class Grupo {
private:
	string nombreGrupo;
	float pkGrupo;
	int cargaGrupo;
public:
	Grupo() { nombreGrupo = ""; pkGrupo = 0; cargaGrupo = 0; };
	Grupo(string nom, float pk, int carga) { nombreGrupo = nom; pkGrupo = pk; cargaGrupo = carga; }
	float GetCarga();
};