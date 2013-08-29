#include <jogo.h>
#include <tela.h>
#include <tempo.h>
#include <hud.h>
#include <iostream>
#include <escutavel.h>
#include <ambiente.h>
#include <util.h>

using namespace std;

Jogo::Jogo()
{
	// Inicializa todos os componentes do SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    // Inicia a ferramenta pra trabalhar com fontes
    TTF_Init();
    // Inicia a ferramenta para trabalhar com áudio
	Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096);
	
	this->tela =  new Tela;
	this->tempo = new Tempo;
	this->hud =   new Hud;
}

Jogo::~Jogo()
{
	if(this->tela) delete this->tela;
	if(this->tempo) delete this->tempo;
	if(this->hud) delete this->hud;
	if(this->vetorDesenhaveis) delete this->vetorDesenhaveis;
	if(this->vetorEscutaveis) delete this->vetorEscutaveis;
	if(this->vetorMutaveis) delete this->vetorMutaveis;
	
	// Fecha o SDL_mixer
    Mix_CloseAudio();
	// Fecha o SDL_ttf
    TTF_Quit();
    // Libera todas as alocações do SDL
    SDL_Quit();
}

int Jogo::rodar()
{
	do 
	{
		switch(Util::estadoJogo)
		{
			case ENTRADA_JOGO:
				this->estadoEntradaJogo();
				break;
			
			case MENU_PRINCIPAL:
				this->estadoMenuJogo();
				break;
			
			case JOGANDO:
				this->estadoJogando();
				break;
			
			case FIM_JOGO:
				this->estadoFimJogo();
				break;
		
			case CREDITOS:
				break;
				
			case SAIDA_APLICATIVO:
				this->estadoFimJogo();
				break;

		}
	} while(Util::estadoJogo != SAIDA_APLICATIVO);
	
	this->estadoSairAplicativo();
	return 0;	
}

bool Jogo::isTileOcupado(int x, int y){
	for (int i = 0; i < mapa->tilesOcupados.size(); ++i)
	{
		if(mapa->tilesOcupados.at(i).x==x && mapa->tilesOcupados.at(i).y==y)
			return true;
	}
	return false;
}
