#include "Enemigo.h"
#include "Librerias.h"

Enemigos::Enemigos()
{
	tex_enemigos.loadFromFile("Assets/Enemigo.png");
	spr_enemigos.setTexture(tex_enemigos);
	spr_enemigos.setScale(2.5f, 2.5f);
	tex_puerta.loadFromFile("Assets/PuertaA.jpg");
	spr_puerta.setTexture(tex_puerta);
	tex_ventana1.loadFromFile("Assets/Ventana1a.jpg");
	spr_ventana1.setTexture(tex_ventana1);
	tex_ventana2.loadFromFile("Assets/Ventana2a.jpg");
	spr_ventana2.setTexture(tex_ventana2);
	tex_disparo.loadFromFile("Assets/Bang.png");
	spr_disparo.setTexture(tex_disparo);
	spr_enemigos.setPosition(1000, 1000);
	spr_ventana1.setPosition(1000, 1000);
	spr_ventana2.setPosition(1000, 1000);
	spr_disparo.setPosition(1000, 1000);
}

FloatRect Enemigos::lugar()
{
	FloatRect bounds = spr_enemigos.getGlobalBounds();
	return bounds;
}

void Enemigos::Dibujar(RenderWindow* ventana)
{
	ventana->draw(spr_ventana1);
	ventana->draw(spr_ventana2);
	if (estaVivo())
	{
		ventana->draw(spr_enemigos);
	}
	
}

void Enemigos::Disparar(RenderWindow* ventana)
{
	spr_disparo.setPosition(250, 250);
}

void Enemigos::DibujarDisparo(RenderWindow* ventana)
{
	ventana->draw(spr_disparo);
}

void Enemigos::BorrarDisparo()
{
	spr_disparo.setPosition(1000, 1000);
}

void Enemigos::Actualizar(RenderWindow* ventana,int pos)
{
	Enemigos::visibilidad(true);
	if (pos == 0)
	{
		spr_enemigos.setPosition(135, 114);
		spr_ventana1.setPosition(75, 84);
		spr_ventana2.setPosition(1000, 1000);
	}
	if (pos == 1)
	{
		spr_enemigos.setPosition(585, 114);
		spr_ventana1.setPosition(525, 84);
		spr_ventana2.setPosition(1000, 1000);
	}
	if (pos == 2)
	{
		spr_enemigos.setPosition(110, 383);
		spr_ventana1.setPosition(1000, 1000);
		spr_ventana2.setPosition(50, 333);
	}
	if (pos == 3)
	{
		spr_enemigos.setPosition(610, 383);
		spr_ventana1.setPosition(1000, 1000);
		spr_ventana2.setPosition(550, 333);
	}
	if (pos == 4)
	{
		spr_enemigos.setPosition(357, 377);
		spr_ventana1.setPosition(1000, 1000);
		spr_ventana2.setPosition(1000, 1000);
	}
}
void Enemigos::Aparecer(RenderWindow* ventana, int pos, FloatRect coor)
{
	Enemigos::visibilidad(true);
	spr_enemigos.setPosition(coor.width, coor.height);
	if (pos == 0 || pos == 1)
	{
		spr_ventana1.setPosition(coor.width, coor.height);
	}
	if (pos == 2 || pos == 3)
	{
		spr_ventana2.setPosition(coor.width, coor.height);
	}
	if (pos == 4)
	{
		spr_puerta.setPosition(coor.width, coor.height);
	}
}