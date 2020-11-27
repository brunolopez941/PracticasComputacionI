#include "Molecula.h"
using namespace std;
void Molecula::AgregarGrupo(Grupo nuevoGrupo) {
	grupos.push_back(nuevoGrupo);
}
float Molecula::CalcularPuntoIsoelectrico() {
	float puntoIsoelectrico=0;
	int numgrupos = grupos.size();
	if (numgrupos == 2) {
		puntoIsoelectrico = (grupos[0].GetPkGrupo() + grupos[1].GetPkGrupo())/2;
	}
	if (numgrupos == 3) {
		puntoIsoelectrico = (grupos[1].GetPkGrupo() + grupos[2].GetPkGrupo())/2;
	}
	return puntoIsoelectrico;
}