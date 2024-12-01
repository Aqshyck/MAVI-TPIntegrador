#pragma once
#include"Librerias.h"
#include "Escenario1.h"

Escenario::Escenario()
{
	//cargado de fondo menu
	tex_fondo.loadFromFile("Assets/Background.png");
	spr_fondo.setTexture(tex_fondo);
	spr_fondo.setPosition(0, 0);
	height_fondo = (float)tex_fondo.getSize().y;
	width_fondo = (float)tex_fondo.getSize().x;
	escalax = 800 / width_fondo;
	escalay = 600 / height_fondo;
	spr_fondo.setScale(escalax, escalay);
	tex_fondo.setSmooth(true);
	//carga texturas
	//tex_ventana_inferior_abierta.loadFromFile("Assets/Ventana2a.jpg");
	tex_ventana_inferior_cerrada.loadFromFile("Assets/Ventana2c.jpg");
	//tex_ventana_superior_abierta.loadFromFile("Assets/Ventana1a.jpg");
	tex_ventana_superior_cerrada.loadFromFile("Assets/Ventana1c.jpg");
	//tex_puerta_abierta.loadFromFile("Assets/PuertaA.jpg");
	tex_puerta_cerrada.loadFromFile("Assets/PuertaC.jpg");
	spr_ventana_inferior1.setTexture(tex_ventana_inferior_cerrada);
	spr_ventana_inferior2.setTexture(tex_ventana_inferior_cerrada);
	spr_ventana_superior1.setTexture(tex_ventana_superior_cerrada);
	spr_ventana_superior2.setTexture(tex_ventana_superior_cerrada);
	spr_puerta.setTexture(tex_puerta_cerrada);
	spr_ventana_inferior1.setPosition(50, 333);
	spr_ventana_inferior2.setPosition(550, 333);
	spr_ventana_superior1.setPosition(75, 84);
	spr_ventana_superior2.setPosition(525, 84);
	spr_puerta.setPosition(337, 327);
	
}
void Escenario::Render(RenderWindow* ventana,int pos)
{
	if (pos == 0)
	{
		spr_ventana_inferior1.setPosition(50, 333);
		spr_ventana_inferior2.setPosition(550, 333);
		spr_ventana_superior1.setPosition(1000, 1000);
		spr_ventana_superior2.setPosition(525, 84);
		spr_puerta.setPosition(337, 327);
	}
	if (pos == 1)
	{
		spr_ventana_inferior1.setPosition(50, 333);
		spr_ventana_inferior2.setPosition(550, 333);
		spr_ventana_superior1.setPosition(75, 84);
		spr_ventana_superior2.setPosition(1000, 1000);
		spr_puerta.setPosition(337, 327);
	}
	if (pos == 2)
	{
		spr_ventana_inferior1.setPosition(1000, 1000);
		spr_ventana_inferior2.setPosition(550, 333);
		spr_ventana_superior1.setPosition(75, 84);
		spr_ventana_superior2.setPosition(525, 84);
		spr_puerta.setPosition(337, 327);
	}
	if (pos == 3)
	{
		spr_ventana_inferior1.setPosition(50, 333);
		spr_ventana_inferior2.setPosition(1000, 1000);
		spr_ventana_superior1.setPosition(75, 84);
		spr_ventana_superior2.setPosition(525, 84);
		spr_puerta.setPosition(337, 327);
	}
	if (pos == 4)
	{
		spr_ventana_inferior1.setPosition(50, 333);
		spr_ventana_inferior2.setPosition(550, 333);
		spr_ventana_superior1.setPosition(75, 84);
		spr_ventana_superior2.setPosition(525, 84);
		spr_puerta.setPosition(1000, 1000);
	}
}
void Escenario::Dibujar(RenderWindow* ventana)
{
	ventana->draw(spr_fondo);
	ventana->draw(spr_ventana_inferior1);
	ventana->draw(spr_ventana_inferior2);
	ventana->draw(spr_ventana_superior1);
	ventana->draw(spr_ventana_superior2);
	ventana->draw(spr_puerta);
}