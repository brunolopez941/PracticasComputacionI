#pragma once
class Punto2D {
public:
	void SetPosicion(float p1, float p2);
	float GetPosicion();

	float GetX();
	float GetY();
	
	float Trasladar(float temp1, float temp2);
	float RotarRespectoAlOrigen(float temp1);
	float Escalar(float temp1, float temp2);
private:
	float x{0}, y{0}, temp1{0}, temp2{0};
};