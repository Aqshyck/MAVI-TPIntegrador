#pragma once
#include "Game.h"

game::game()
{
	_ventana = new RenderWindow(VideoMode(800, 800), "Wild West?");
	_jugador = new MiraJugador();
	_menu = new Menus();
	_npc = new NPC();
	_rehen = new Rehen();
	_enemigos = new Enemigos();
	_escenario = new Escenario();
	_pantallaFinal = new PantallaFinal();
	pantallaMenu = true;
	pantallaObjetivo = false;
	pantallaJuego = false;
	pantallaFinal = false;
	puntos = 0;
	vidas = _jugador->VidasRestantes();
	fuente.loadFromFile("Assets/CHILLER.TTF");
	Reloj.restart();

	puntaje.setFont(fuente);
	puntaje.setPosition(50.f, 650.f);
	puntaje.setCharacterSize(30);
	puntaje.setFillColor(Color::Cyan);
	puntaje.setString("Puntaje: " + to_string(puntos));

	textVidas.setFont(fuente);	
	textVidas.setPosition(50.f, 700.f);	
	textVidas.setCharacterSize(30);	
	textVidas.setFillColor(Color::Cyan);
	textVidas.setString("Vidas: "+ to_string(vidas));

	puntajeFinal.setFont(fuente);
	puntajeFinal.setPosition(300.f, 100.f);
	puntajeFinal.setCharacterSize(50);
	puntajeFinal.setFillColor(Color::Cyan);
	puntajeFinal.setString("Puntaje Final: " + to_string(puntos));

	actualizarPuntaje(puntos,vidas);
	srand(time(NULL));
}
void game::run()
{
	srand(time(NULL));
	while (_ventana->isOpen())
	{
		if (pantallaMenu)
		{
			eventos();
			renderMenu();
		}
		if (pantallaJuego)
		{
			eventos();
			actualizar();
			renderJuego();
		}
		if (pantallaFinal)
		{
			eventos();
			renderFinal();
		}
	}
}
void game::eventos()
{
	Event play;
	_ventana->setMouseCursorVisible(false);
	while (_ventana->pollEvent(play))
	{
		if (pantallaMenu)
		{
			switch (play.type)
			{
			case sf::Event::Closed:
				_ventana->close();
				break;
			case sf::Event::MouseMoved:
				_jugador->Posicion(play.mouseMove.x, play.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
				if (play.mouseButton.button == Mouse::Button::Left)
				{
					presionarBoton();
				}
				break;
			}
		}
		if (pantallaJuego)
		{
			switch (play.type)
			{
			case sf::Event::Closed:
				_ventana->close();
				break;
			case sf::Event::MouseMoved:
				_jugador->Posicion(play.mouseMove.x, play.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
				if (play.mouseButton.button == Mouse::Button::Left)
				{
					disparar();
				}
				break;
			}
		}
		if (pantallaFinal)
		{
			switch (play.type)
			{
			case sf::Event::Closed:
				_ventana->close();
				break;
			case sf::Event::MouseMoved:
				_jugador->Posicion(play.mouseMove.x, play.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
				if (play.mouseButton.button == Mouse::Button::Left)
				{
					presionarBoton();
				}
				break;
			}
		}
	}
}
void game::actualizar()
{
	if (_enemigos->estaActivo())
	{
		if (Reloj.getElapsedTime().asSeconds() > 1.5f)
		{
			perderVida();
			_enemigos->Disparar(_ventana);
			_enemigos->muerte();
			_enemigos->visibilidad(false);
		}
	}
	if (Reloj.getElapsedTime().asSeconds() > 2.0f)
	{		
		int posicion = _npc->randomPos();
		FloatRect coordenadas = _npc->coordenada(posicion);
		int npc = randomNPC();
		if (npc == 0)
		{
			_enemigos->BorrarDisparo();
			_rehen->visibilidad(false);
			_enemigos->Revive();
			_enemigos->Actualizar(_ventana, posicion);
			_escenario->Render(_ventana, posicion);
			
		}
		if (npc == 1)
		{
			_enemigos->BorrarDisparo();
			_enemigos->visibilidad(false);
			_rehen->Revive();			
			_rehen->Actualizar(_ventana, posicion);
			_escenario->Render(_ventana, posicion);					
		}
		Reloj.restart();
	}	
}
void game::presionarBoton()
{
	Vector2f mousePos = _jugador->posicionMira();
	if (_menu->boton1(mousePos.x, mousePos.y))
	{
		pantallaJuego = true;
		pantallaMenu = false;		
	}
	if (_menu->boton2(mousePos.x, mousePos.y))
	{
		pantallaObjetivo = true;
	}
	if (_menu->boton3(mousePos.x, mousePos.y))
	{
		_ventana->close();
	}
	if (_menu->boton4(mousePos.x, mousePos.y))
	{
		pantallaObjetivo = false;
	}
	if (_pantallaFinal->boton(mousePos.x, mousePos.y))
	{
		_ventana->close();
	}
}
void game::disparar()
{
	Vector2f puntoMira = _jugador->posicionMira();

	if (_enemigos->estaActivo() || _rehen->estaActivo())
	{
		if (_enemigos->EnLaMira(puntoMira.x, puntoMira.y, _enemigos->lugar()))
		{
			_enemigos->muerte();
			_enemigos->visibilidad(false);
			puntos++;
		}
		if (_rehen->EnLaMira(puntoMira.x, puntoMira.y, _rehen->lugar()))
		{
			_rehen->muerte();
			_rehen->visibilidad(false);
			puntos = puntos - 2;
			perderVida();
		}
	}
	actualizarPuntaje(puntos, vidas);
	
}
void game::perderVida()
{
	_jugador->QuitarVidas();
	vidas = _jugador->VidasRestantes();
	actualizarPuntaje(puntos, vidas);
}
int game::randomNPC()
{
	int npc = rand() % 2;
	return npc;
}
void game::renderMenu()
{
	if (!pantallaObjetivo)
	{
		_ventana->clear();
		_menu->Dibujar(_ventana);
		_jugador->Dibujar(_ventana);
		_ventana->display();
	}
	else
	{
		_ventana->clear();
		_menu->DibujarObjetivo(_ventana);
		_jugador->Dibujar(_ventana);
		_ventana->display();
	}
	
}
void game::renderJuego()
{
	if (vidas > 0)
	{
		_ventana->clear();
		_enemigos->Dibujar(_ventana);
		_rehen->Dibujar(_ventana);
		_escenario->Dibujar(_ventana);
		_ventana->draw(puntaje);
		_ventana->draw(textVidas);
		_enemigos->DibujarDisparo(_ventana);
		_jugador->Dibujar(_ventana);
		_ventana->display();
	}
	else
	{
		puntajeFinal.setString("Puntaje Final: " + to_string(puntos));
		pantallaFinal = true;
		pantallaJuego = false;
	}
}
void game::renderFinal()
{
	_ventana->clear();
	_pantallaFinal->Dibujar(_ventana);
	_ventana->draw(puntajeFinal);
	_jugador->Dibujar(_ventana);
	_ventana->display();
}