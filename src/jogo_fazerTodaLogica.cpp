#include <jogo.h>
#include <hud.h>
#include <iostream>
#include <util.h>

using namespace std;

int Jogo::fazerTodaLogica()
{		
	for(unsigned int i = 0; i < this->vetorMutaveis->size(); i++) 
		this->vetorMutaveis->at(i)->fazerLogica();
	
	if (this->mestre && this->mestre->pontosVida == 0)
	{
		Util::removerElementoVetor(this->vetorDesenhaveis, this->mestre);
		Util::removerElementoVetor(this->vetorMutaveis, this->mestre);
		delete this->mestre;
		Util::estadoJogo = FIM_JOGO; // AQUI QUER DIZER GAME-OVER
		Util::trocarEstadoInterno(TRANSICAO_WAVE);
		Mix_HaltMusic();
	}
	
	if(Util::estadoInterno!=TRANSICAO_WAVE && !(Util::estadoInterno==COMPRANDO && Util::ultimoEstadoInterno==TRANSICAO_WAVE) && this->wave) 
		this->wave->fazerLogica();
		
	if(this->hud)
		this->hud->fazerLogica();
		
	if(this->wave && this->wave->waveTerminou)
	{
		delete this->wave;
		
		if (Hud::numeradorWave == Hud::denominadorWave) // 
		{
			// PASSOU DE FASE
			
			if (Util::mapaAtual == JARDIM_EXTERNO)
			{
				Util::estadoJogo = ENTRADA_JOGO;
				Util::trocarEstadoInterno(TRANSICAO_WAVE);
				Util::mapaAtual = (TipoMapa) 0;
			} else
			{
				delete this->vetorDesenhaveis;
				delete this->vetorMutaveis;
				delete this->vetorEscutaveis;
				delete this->mestre;
				delete this->mapa;
				
				Util::mapaAtual = (TipoMapa) (Util::mapaAtual + 1);
				Util::trocarEstadoInterno(TRANSICAO_WAVE);
			
				this->estadoJogando();
			}
				
		} else
		{
			Util::trocarEstadoInterno(TRANSICAO_WAVE);
			Hud::numeradorWave++;
			this->wave = new Wave(Hud::numeradorWave, this->vetorDesenhaveis, this->vetorMutaveis, this->mapa, this->mestre);
		}
	}
	
	return 0;
}
