#include "Punto.h"
#include <math.h>

void Punto2D::SetPosicion(float p1, float p2) {
	x = p1;
	y = p2;
}
float Punto2D::GetPosicion() {
	return x, y;
}

float Punto2D::GetX() {
	return x;
}
float Punto2D::GetY() {
	return y;
}

float Punto2D::Trasladar(float temp1, float temp2) {
	x = x + temp1;
	y = y + temp2;
	return x,y;
}

float Punto2D::RotarRespectoAlOrigen(float temp1) {
	float aux1, aux2;
	const float PI = atan(1) * 4;
	temp1 = (temp1 * PI)/180;
	aux1 = x * cos(temp1) - y * sin(temp1);
	aux2 = x * sin(temp1) + y * cos(temp1);
	x = aux1;
	y = aux2;
	return x, y;
}

float Punto2D::Escalar(float temp1, float temp2) {
	x = x * temp1;
	y = y * temp2;
	return x,y;
}