#pragma once
#include "Librerias.h"
#include "Menus.h"


Menus::Menus()
{
	//cargado de fondo menu
	tex_fondo.loadFromFile("Assets/BackgroundMenu.png");
	spr_fondo.setTexture(tex_fondo);
	spr_fondo.setPosition(0, 200);
	tex_fondo.setSmooth(true);
	//cargado de fondo objetivo
	tex_fondoIns.loadFromFile("Assets/Instrucciones.png");
	spr_fondoIns.setTexture(tex_fondoIns);
	spr_fondoIns.setPosition(0, 200);
	tex_fondoIns.setSmooth(true);
	//carga boton 1 Start
	tex_boton1.loadFromFile("Assets/Start.png");
	spr_boton1.setTexture(tex_boton1);
	spr_boton1.setPosition(313, 300);
	spr_boton1.setScale(0.5f, 0.5f);
	//Carga boton 2 Objetivo
	tex_boton2.loadFromFile("Assets/About.png");
	spr_boton2.setTexture(tex_boton2);
	spr_boton2.setPosition(313, 400);
	spr_boton2.setScale(0.5f, 0.5f);
	//carga boton 3 Salir
	tex_boton3.loadFromFile("Assets/Quit.png");
	spr_boton3.setTexture(tex_boton3);
	spr_boton3.setPosition(313, 500);
	spr_boton3.setScale(0.5f, 0.5f);
	//carga boton 4 regresar
	tex_boton4.loadFromFile("Assets/Return.png");
	spr_boton4.setTexture(tex_boton4);
	spr_boton4.setPosition(10, 10);
	spr_boton4.setScale(0.5f, 0.5f);
}
void Menus::Dibujar(RenderWindow* ventana)
{
	ventana->draw(spr_fondo);
	ventana->draw(spr_boton1);
	ventana->draw(spr_boton2);
	ventana->draw(spr_boton3);
}
void Menus::DibujarObjetivo(RenderWindow* ventana)
{
	ventana->draw(spr_fondoIns);
	ventana->draw(spr_boton4);

}
bool Menus::boton1(float x, float y)
{
	FloatRect bounds = spr_boton1.getGlobalBounds();
	return bounds.contains(x, y);
}
bool Menus::boton2(float x, float y)
{
	FloatRect bounds = spr_boton2.getGlobalBounds();
	return bounds.contains(x, y);
}
bool Menus::boton3(float x, float y)
{
	FloatRect bounds = spr_boton3.getGlobalBounds();
	return bounds.contains(x, y);
}
bool Menus::boton4(float x, float y)
{
	FloatRect bounds = spr_boton4.getGlobalBounds();
	return bounds.contains(x, y);
}