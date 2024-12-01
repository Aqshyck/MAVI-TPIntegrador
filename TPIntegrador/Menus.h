#pragma once
#include "Librerias.h"
using namespace sf;

class Menus {
private:
	Texture tex_fondo, tex_fondoIns, tex_boton1, tex_boton2, tex_boton3, tex_boton4;
	Sprite spr_fondo, spr_fondoIns, spr_boton1, spr_boton2, spr_boton3, spr_boton4;
	
public:
	Menus();
	void Dibujar(RenderWindow* ventana);
	void DibujarObjetivo(RenderWindow* ventana);
	bool boton1(float x, float y);
	bool boton2(float x, float y);
	bool boton3(float x, float y);
	bool boton4(float x, float y);
};