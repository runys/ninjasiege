#include <jogo.h>
#include <util.h>
#include <ambiente.h>
#include <fading.h>
#include <SDL/SDL.h>
#include <iostream>

using namespace std;

int Jogo::estadoEntradaJogo()
{	
	this->vetorDesenhaveis =  new vector<Desenhavel *>;
	this->vetorEscutaveis =  new vector<Escutavel *>;

	Fading * logoFading = new Fading("z_one_logo_800_600.png", "intro.mp3", 6);	
		
	this->vetorDesenhaveis->push_back(logoFading);
	
	while(Util::estadoJogo == ENTRADA_JOGO)
	{
		
		this->tempo->iniciarTempo();
		this->detectarTodosEventos();
		this->desenharTudo();
		this->tela->renderizar();
		this->tempo->atrasarTempo();
		if(logoFading->terminouFading())
		{
			delete logoFading;
			break;
		}
	}
	if (Util::estadoJogo != SAIDA_APLICATIVO)
		Util::estadoJogo = MENU_PRINCIPAL;
	
	delete this->vetorDesenhaveis;
	
	return 0;
}
