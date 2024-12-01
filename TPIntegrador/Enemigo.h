#pragma once
#include "Librerias.h"
#include "NPC.h"
#include "MiraJugador.h"
using namespace sf;

class Enemigos : public NPC {
private:
	Texture tex_enemigos, tex_ventana1, tex_ventana2, tex_puerta, tex_disparo;
	Sprite spr_enemigos, spr_ventana1, spr_ventana2, spr_puerta, spr_disparo;
public:
	Enemigos();
	FloatRect lugar();
	void Dibujar(RenderWindow* ventana);
	void Disparar(RenderWindow* ventana);
	void DibujarDisparo(RenderWindow* ventana);
	void BorrarDisparo();
	void Actualizar(RenderWindow* ventana, int pos);
	void Aparecer(RenderWindow* ventana, int pos, FloatRect coor);
};