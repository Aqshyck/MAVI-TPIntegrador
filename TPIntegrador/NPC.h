#pragma once
#include "Librerias.h"
using namespace sf;

class NPC
{
	bool conVida;
	bool estaVisible;

public:
	
	Vector2f velocidad;
	int posicion;


	int randomPos();
	FloatRect coordenada(int pos);
	NPC();
	bool estaVivo();
	void Revive();
	bool Visible() const;
	bool estaActivo() const;
	void visibilidad(bool estado);
	bool EnLaMira(float x, float y, FloatRect bounds);
	void muerte();
};