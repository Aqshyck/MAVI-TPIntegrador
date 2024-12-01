#pragma once
#include "Librerias.h"
using namespace sf;

class MiraJugador
{
	Texture tex_mira;
	Sprite spr_mira;
	int vidas;

public:
	MiraJugador();
	void Dibujar(RenderWindow* ventana);
	void Posicion(float x, float y);
	void QuitarVidas();
	int VidasRestantes();
	Vector2f posicionMira();
};
