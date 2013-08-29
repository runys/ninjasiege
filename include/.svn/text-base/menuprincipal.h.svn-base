#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include <escutavel.h>
#include <botao.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

class MenuPrincipal : public Escutavel
{
private:
	Botao * botaoNovoJogo;
	Botao * botaoContinuar;
	Botao * botaoAjuda;
	Botao * botaoConfiguracoes;
	Botao * botaoCreditos;
	Botao * botaoSair;
	
	SDL_Surface * desenho;
	SDL_Rect desenhoRect;
	SDL_Surface * logo;
	SDL_Rect logoRect;
	SDL_Surface * rodape;
	SDL_Rect rodapeRect;
	Mix_Music * musicaFundo;
	
public:
	MenuPrincipal();
	~MenuPrincipal();
	int desenhar();
	int detectarEvento();
};

#endif
