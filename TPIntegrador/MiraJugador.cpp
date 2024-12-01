
#include "MiraJugador.h"
#include "Librerias.h"

MiraJugador::MiraJugador()
{
	tex_mira.loadFromFile("Assets/crosshair.png");
	spr_mira.setTexture(tex_mira);
	spr_mira.setScale(0.4f, 0.4f);
	Vector2u size = tex_mira.getSize();
	spr_mira.setOrigin(size.x / 2.f, size.y / 2.f);
	vidas = 3;
}
void MiraJugador::Dibujar(RenderWindow* ventana)
{
	ventana->draw(spr_mira);
}
void MiraJugador::Posicion(float x, float y)
{
	spr_mira.setPosition(x, y);
}
void MiraJugador::QuitarVidas()
{
	vidas--;
}
int MiraJugador::VidasRestantes()
{
	return vidas;
}
Vector2f MiraJugador::posicionMira()
{
	return spr_mira.getPosition();
}