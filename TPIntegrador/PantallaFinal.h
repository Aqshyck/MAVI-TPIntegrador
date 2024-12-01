#pragma once
#include "Librerias.h"

class PantallaFinal {
private:
	Texture tex_fondo, tex_boton;
	Sprite spr_fondo, spr_boton;

public:
	PantallaFinal();
	void Dibujar(RenderWindow* ventana);
	bool boton(float x, float y);
};