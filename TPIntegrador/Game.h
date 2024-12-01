#pragma once
#include "Librerias.h"
#include "MiraJugador.h"
#include "Menus.h"
#include "Enemigo.h"
#include "NPC.h"
#include "Rehen.h"
#include "Escenario1.h"
#include "PantallaFinal.h"


class game
{
	RenderWindow* _ventana;
	MiraJugador* _jugador;
	NPC* _npc;
	Enemigos* _enemigos;
	Rehen* _rehen;
	Menus* _menu;
	Escenario* _escenario;
	PantallaFinal* _pantallaFinal;
	Text puntaje, textVidas, puntajeFinal;
	Font fuente;
	int puntos, vidas;
	bool pantallaMenu, pantallaObjetivo, pantallaJuego, pantallaFinal;
	sf::Clock Reloj;
	
	void actualizarPuntaje(int puntos, int vidas)
	{
		puntaje.setString("Puntaje: " + to_string(puntos));
		textVidas.setString("Vidas: " + to_string(vidas));
	}
public:
	
	game();
	void run();
	void eventos();
	void actualizar();
	void presionarBoton();
	void disparar();
	void perderVida();
	int randomNPC();
	void renderMenu();
	void renderJuego();
	void renderFinal();
	~game()
	{
		delete _pantallaFinal;
		delete _menu;
		delete _rehen;
		delete _enemigos;
		delete _npc;
		delete _jugador;
		delete _ventana;
	}
};