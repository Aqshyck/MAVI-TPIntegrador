#pragma once
#include "Librerias.h"
using namespace sf;



class Escenario {
private:
	Texture tex_fondo, tex_ventana_superior_cerrada, tex_ventana_superior_abierta, tex_ventana_inferior_cerrada, tex_ventana_inferior_abierta,tex_puerta_abierta,tex_puerta_cerrada;
	Sprite spr_fondo, spr_ventana_superior1, spr_ventana_superior2,spr_ventana_inferior1,spr_ventana_inferior2,spr_puerta;
	
	float height_fondo, width_fondo;
	float escalax, escalay;

public:
	Escenario();
	void Render(RenderWindow* ventana, int pos);
	void Dibujar(RenderWindow* ventana);
};