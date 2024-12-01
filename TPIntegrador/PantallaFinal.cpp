#pragma once
#include "Librerias.h"
#include "PantallaFinal.h"


PantallaFinal::PantallaFinal()
{
	//cargado de fondo
	tex_fondo.loadFromFile("Assets/BackgroundMenu.png");
	spr_fondo.setTexture(tex_fondo);
	spr_fondo.setPosition(0, 200);
	tex_fondo.setSmooth(true);
	//carga boton 3 Salir
	tex_boton.loadFromFile("Assets/Quit.png");
	spr_boton.setTexture(tex_boton);
	spr_boton.setPosition(313, 500);
	spr_boton.setScale(0.5f, 0.5f);
}
void PantallaFinal::Dibujar(RenderWindow* ventana)
{
	ventana->draw(spr_fondo);
	ventana->draw(spr_boton);
}
bool PantallaFinal::boton(float x, float y)
{
	FloatRect bounds = spr_boton.getGlobalBounds();
	return bounds.contains(x, y);
}