#include "NPC.h"
#include "Librerias.h"

NPC::NPC()
{
	conVida = true;
	estaVisible = false;
	posicion = 0;
}

int NPC::randomPos()
{
	posicion = rand() % 5;
	return posicion;
}

FloatRect NPC::coordenada(int pos)
{
	int posicion = pos;
	FloatRect random;
	if (posicion == 0)
	{
		Vector2f random(75, 84);
	}
	if (posicion == 1)
	{
		Vector2f random(525, 84);
	}
	if (posicion == 2)
	{
		Vector2f random(50, 333);
	}
	if (posicion == 3)
	{
		Vector2f random(550, 333);
	}
	if (posicion == 4)
	{
		Vector2f random(337, 327);
	}
	return random;
}

bool NPC::estaVivo()
{
	return conVida;
}

void NPC::Revive()
{
	conVida = true;
}

bool NPC::Visible() const
{
	return estaVisible;
}

bool NPC::estaActivo() const
{
	return conVida && estaVisible;
}

void NPC::visibilidad(bool estado)
{
	estaVisible = estado;
}

bool NPC::EnLaMira(float x, float y, FloatRect bounds)
{
	return bounds.contains(x, y);
}

void NPC::muerte()
{
	conVida = false;
}