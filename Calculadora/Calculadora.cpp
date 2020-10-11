/* Calculadora
	Bruno Arturo López Pacheco
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	double n1, n2, suma, resta, division, multiplicacion;
	string operacion, respuesta;
	cout << "¡Hola! Bienvenido a la calculadora" << endl;
	respuesta = "si";
	while (respuesta == "si"){
		cout << "Introduzca un numero: ";
		cin >> n1;
		cout << "Introduzca una operacion: ";
		cin >> operacion;
		cout << "Introduzca el segundo numero: ";
		cin >> n2;
		if (operacion == "+") {
			suma = n1 + n2;
			cout << "El resultado es: " << suma << endl;
		}
		else if (operacion == "-") {
			resta = n1 - n2;
			cout << "El resultado es: " << resta << endl;
		}
		else if (operacion == "*") {
			multiplicacion = n1 * n2;
			cout << "El resultado es: " << multiplicacion << endl;
		}
		else if (operacion == "/") {
			if (n2 == 0) {
				cout << "No estan definidas las divisiones entre cero" << endl;
			}
			else {
				division = n1 / n2;
				cout << "El resultado es: " << division << endl;
			}
		}
		cout << "¿Desea hacer otra operacion? ";
		cin >> respuesta;
	}
	return 0;
}
