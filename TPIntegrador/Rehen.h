#pragma once
#include "Librerias.h"
#include "NPC.h"

class Rehen : public NPC {
private:
	Texture tex_rehen, tex_ventana1, tex_ventana2, tex_puerta;
	Sprite spr_rehen, spr_ventana1, spr_ventana2, spr_puerta;
public:
	Rehen();
	FloatRect lugar();
	void Dibujar(RenderWindow* ventana);
	void Actualizar(RenderWindow* ventana, int pos);
	void Aparecer(RenderWindow* ventana, int pos, FloatRect coor);
};