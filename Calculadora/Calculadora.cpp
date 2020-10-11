/* Calculadora
	Bruno Arturo López Pacheco
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	float n1, n2, suma, resta, division, multiplicacion, modulo;
	int numero1, numero2;
	string operacion, respuesta;
	cout << "Este programa hace operaciones basicas entre dos numeros" << endl;
	respuesta = "si";
	while (respuesta == "si"){
		cout << "Introduzca el primer numero: ";
		cin >> n1;
		cout << "Introduzca una operacion: ";
		cin >> operacion;
		cout << "Introduzca el segundo numero: ";
		cin >> n2;
		if (operacion == "+") {
			suma = n1 + n2;
			cout << "El resultado es: " << endl;
			cout << n1 << " + " << n2 << " = " << suma << endl;
		}
		else if (operacion == "-") {
			resta = n1 - n2;
			cout << "El resultado es: " << endl;
			cout << n1 << " - " << n2 << " = " << resta << endl;
		}
		else if (operacion == "*") {
			multiplicacion = n1 * n2;
			cout << "El resultado es: " << endl;
			cout << n1 << " * " << n2 << " = " << multiplicacion << endl;
		}
		else if (operacion == "/") {
			if (n2 == 0) {
				cout << "No estan definidas las divisiones entre cero" << endl;
			}
			else {
				division = n1 / n2;
				cout << "El resultado es: " << endl;
				cout << n1 << " / " << n2 << " = " << division << endl;
			}
		}
		else if (operacion == "%"){
			numero1 = n1;
			numero2 = n2;
			modulo = numero1%numero2;
			cout << "El resultado es: " << endl;
			cout << n1 << " % " << n2 << " = " << modulo << endl;
		}
		cout << "¿Desea hacer otra operacion? ";
		cin >> respuesta;
	}
	return 0;
}
