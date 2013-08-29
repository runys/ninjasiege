#include <jogo.h>
#include <ambiente.h>
#include <util.h>
#include <tela.h>
#include <fading.h>
#include <SDL/SDL.h>


int Jogo::estadoFimJogo()
{
	this->vetorDesenhaveis =  new vector<Desenhavel *>;
	this->vetorEscutaveis =  new vector<Escutavel *>;

	Fading * gameOverFading = new Fading("game_over.png", "Without.mp3", 9);	
		
	this->vetorDesenhaveis->push_back(gameOverFading);
	
	while(Util::estadoJogo == FIM_JOGO)
	{
		
		this->tempo->iniciarTempo();
		this->detectarTodosEventos();
		this->desenharTudo();
		this->tela->renderizar();
		this->tempo->atrasarTempo();
		if(gameOverFading->terminouFading())
		{
			delete gameOverFading;
			break;
		}
	}
	if (Util::estadoJogo != SAIDA_APLICATIVO)
		Util::estadoJogo = MENU_PRINCIPAL;
	
	delete this->vetorDesenhaveis;
	
	return 0;
}
