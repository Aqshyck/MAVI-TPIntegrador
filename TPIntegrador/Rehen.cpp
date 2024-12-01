#include "Rehen.h"
#include "Librerias.h"

Rehen::Rehen()
{
	tex_rehen.loadFromFile("Assets/Inocente.png");
	spr_rehen.setTexture(tex_rehen);
	spr_rehen.setScale(1.0f, 1.0f);
	tex_puerta.loadFromFile("Assets/PuertaA.jpg");
	spr_puerta.setTexture(tex_puerta);
	tex_ventana1.loadFromFile("Assets/Ventana1a.jpg");
	spr_ventana1.setTexture(tex_ventana1);
	tex_ventana2.loadFromFile("Assets/Ventana2a.jpg");
	spr_ventana2.setTexture(tex_ventana2);
	spr_rehen.setPosition(1000, 1000);
	spr_ventana1.setPosition(1000, 1000);
	spr_ventana2.setPosition(1000, 1000);
}

FloatRect Rehen::lugar()
{
	FloatRect bounds = spr_rehen.getGlobalBounds();
	return bounds;
}

void Rehen::Dibujar(RenderWindow* ventana)
{
	ventana->draw(spr_ventana1);
	ventana->draw(spr_ventana2);
	if (estaVivo())
	{
		ventana->draw(spr_rehen);
	}	
}

void Rehen::Actualizar(RenderWindow* ventana, int pos)
{
	{
		Rehen::visibilidad(true);
		if (pos == 0)
		{
			spr_rehen.setPosition(55, 114);
			spr_ventana1.setPosition(75, 84);
			spr_ventana2.setPosition(1000, 1000);
		}
		if (pos == 1)
		{
			spr_rehen.setPosition(505, 114);
			spr_ventana1.setPosition(525, 84);
			spr_ventana2.setPosition(1000, 1000);
		}
		if (pos == 2)
		{
			spr_rehen.setPosition(30, 363);
			spr_ventana1.setPosition(1000, 1000);
			spr_ventana2.setPosition(50, 333);
		}
		if (pos == 3)
		{
			spr_rehen.setPosition(530, 363);
			spr_ventana1.setPosition(1000, 1000);
			spr_ventana2.setPosition(550, 333);
		}
		if (pos == 4)
		{
			spr_rehen.setPosition(277, 327);
			spr_ventana1.setPosition(1000, 1000);
			spr_ventana2.setPosition(1000, 1000);
		}
	}
}
void Rehen::Aparecer(RenderWindow* ventana, int pos, FloatRect coor)
{
	Rehen::visibilidad(true);
	spr_rehen.setPosition(coor.width, coor.height);
	if (pos == 0 || pos == 1)
	{
		spr_ventana1.setPosition(coor.width, coor.height);
		ventana->draw(spr_ventana1);
		ventana->draw(spr_rehen);
	}
	if (pos == 2 || pos == 3)
	{
		spr_ventana2.setPosition(coor.width, coor.height);
		ventana->draw(spr_ventana2);
		ventana->draw(spr_rehen);
	}
	if (pos == 4)
	{
		spr_puerta.setPosition(coor.width, coor.height);
		ventana->draw(spr_puerta);
		ventana->draw(spr_rehen);
	}
}