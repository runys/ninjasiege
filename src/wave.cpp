#include <wave.h>
#include <inimigo.h>
#include <desenhavel.h>
#include <mutavel.h>
#include <tela.h>
#include <util.h>
#include <mapa.h>
#include <hud.h>
#include <vector>
#include <iostream>

using namespace std;

Wave::Wave(int numeroWave, vector<Desenhavel *> * vetorDesenhaveis, vector<Mutavel *> * vetorMutaveis, Mapa * mapaAtual, Mestre *mestreAtual)
{
	this->mapaAtual = mapaAtual;
	this->mestreAtual = mestreAtual;
	this->vetorDesenhaveis = vetorDesenhaveis;
	this->vetorMutaveis = vetorMutaveis;
	this->waveTerminou = false;
	this->atrasoCriacaoInimigos = 0;
	this->indiceVetorInimigo = 0;
	this->podeLancarInimigos = false;	
	this->podeConfigurarComboio = true;
	this->comboiosJaLancados=0;
	this->numeroWave = numeroWave;
		
	this->configurarWave();
}

Wave::~Wave()
{
	delete this->vetorInimigos;
}

void Wave::configurarComboio()
{
	for(int i = 0; i < this->quantidadeInimigosTipoPorComboio[SAQUEADOR]; i++)
		this->vetorInimigos->push_back(new Inimigo(SAQUEADOR, this->mapaAtual));
	
	for(int i = 0; i < this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU]; i++)
		this->vetorInimigos->push_back(new Inimigo(PERNA_DE_PAU, this->mapaAtual));
	
	for(int i = 0; i < this->quantidadeInimigosTipoPorComboio[CORSARIO]; i++)
		this->vetorInimigos->push_back(new Inimigo(CORSARIO, this->mapaAtual));
	
	for(int i = 0; i < this->quantidadeInimigosTipoPorComboio[CAPITAO]; i++)
		this->vetorInimigos->push_back(new Inimigo(CAPITAO, this->mapaAtual));
}

void Wave::lancarInimigo()
{	
	this->vetorInimigos->at(this->indiceVetorInimigo)->estaNoJogo = true;	
	this->vetorDesenhaveis->push_back(this->vetorInimigos->at(this->indiceVetorInimigo));
	this->vetorMutaveis->push_back(this->vetorInimigos->at(this->indiceVetorInimigo));
	this->indiceVetorInimigo++;
	this->inimigosLancadosNoComboio++;
}

int Wave::fazerLogica()
{	
	if (this->quantidadeInimigosWave == 0)
	{
		this->waveTerminou = true;
		return 0;	
	}
	
	if (this->comboiosJaLancados != this->quantidadeComboios)
	{
		if (this->podeConfigurarComboio && this->atrasoEntreComboios == this->intervaloEntreComboios)
		{
			configurarComboio();
			this->comboiosJaLancados++;
			
			this->inimigosLancadosNoComboio = 0;	
			this->atrasoEntreComboios = 0;

			this->podeLancarInimigos = true;
			this->podeConfigurarComboio = false;		
		}
	}
		
	if (this->podeLancarInimigos && (this->atrasoCriacaoInimigos % this->intervaloCriacaoInimigos) == 0)
	{
		lancarInimigo();
		this->atrasoCriacaoInimigos = 0;
		
		if (this->inimigosLancadosNoComboio == this->quantidadeInimigosPorComboio)
		{
			this->podeLancarInimigos = false;
			this->podeConfigurarComboio = true;		
		}
	}
		
	this->removerInimigosMortos();
	
	if (this->podeLancarInimigos)
		this->atrasoCriacaoInimigos++;		
	
	if (this->podeConfigurarComboio)
		this->atrasoEntreComboios++;
	
	return 0;
}

void Wave::configurarWave()
{
	switch(this->mapaAtual->tipo)
	{
		case SALA_ARTES_NEGRAS:
			this->quantidadeComboios = 3;
			this->intervaloEntreComboios = 3*Tela::FPS;
			this->intervaloCriacaoInimigos = (3*Tela::FPS)/2;
			this->atrasoEntreComboios = this->intervaloEntreComboios - Tela::FPS;
			
			if (this->numeroWave < 2)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 0;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 2;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 2;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 0;
			} else if (this->numeroWave < 3)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 0;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 1;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 3;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 0;
			
			} else if (this->numeroWave < 5)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 0;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 0;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 4;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 2;
			
			} else if (this->numeroWave == 5)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 3;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 0;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 0;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 0;
			}
				
			this->quantidadeInimigosPorComboio =  this->quantidadeInimigosTipoPorComboio[CAPITAO] 
												+ this->quantidadeInimigosTipoPorComboio[SAQUEADOR]
												+ this->quantidadeInimigosTipoPorComboio[CORSARIO]
												+ this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU];
			this->quantidadeInimigosWave = this->quantidadeInimigosPorComboio * this->quantidadeComboios;
			break;
		
		case SALA_GUARDA:
			this->quantidadeComboios = 3;
			this->intervaloEntreComboios = 3*Tela::FPS;
			this->intervaloCriacaoInimigos = (3*Tela::FPS)/2;
			this->atrasoEntreComboios = this->intervaloEntreComboios - Tela::FPS;
			
			if (this->numeroWave < 2)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 0;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 0;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 4;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 2;
			} else if (this->numeroWave < 3)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 0;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 2;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 2;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 1;
			
			} else if (this->numeroWave < 5)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 1;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 4;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 4;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 0;
			
			} else if (this->numeroWave == 5)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 4;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 0;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 0;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 1;			
			}
				
			this->quantidadeInimigosPorComboio =  this->quantidadeInimigosTipoPorComboio[CAPITAO] 
												+ this->quantidadeInimigosTipoPorComboio[SAQUEADOR]
												+ this->quantidadeInimigosTipoPorComboio[CORSARIO]
												+ this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU];
			this->quantidadeInimigosWave = this->quantidadeInimigosPorComboio * this->quantidadeComboios;
			break;
			
		case JARDIM_EXTERNO:
			this->quantidadeComboios = 4;
			this->intervaloEntreComboios = 2*Tela::FPS;
			this->intervaloCriacaoInimigos = (3*Tela::FPS)/2;
			this->atrasoEntreComboios = this->intervaloEntreComboios - Tela::FPS;
			
			if (this->numeroWave < 2)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 1;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 0;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 3;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 0;
			} else if (this->numeroWave < 3)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 1;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 2;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 3;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 2;
			
			} else if (this->numeroWave < 5)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 3;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 2;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 3;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 2;
			
			} else if (this->numeroWave == 5)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 3;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 3;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 3;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 3;			
			}
				
			this->quantidadeInimigosPorComboio =  this->quantidadeInimigosTipoPorComboio[CAPITAO] 
												+ this->quantidadeInimigosTipoPorComboio[SAQUEADOR]
												+ this->quantidadeInimigosTipoPorComboio[CORSARIO]
												+ this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU];
			this->quantidadeInimigosWave = this->quantidadeInimigosPorComboio * this->quantidadeComboios;
			break;
		
		case SALA_TREINAMENTO:
			this->quantidadeComboios = 4;
			this->intervaloEntreComboios = 4*Tela::FPS;
			this->intervaloCriacaoInimigos = (3*Tela::FPS)/2;
			this->atrasoEntreComboios = this->intervaloEntreComboios - Tela::FPS;
			
			if (this->numeroWave < 2)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 1;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 0;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 5;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 0;
			} else if (this->numeroWave < 3)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 1;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 2;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 3;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 4;
			
			} else if (this->numeroWave < 5)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 8;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 2;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 8;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 2;
			
			} else if (this->numeroWave == 5)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 8;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 8;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 8;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 8;			
			}
				
			this->quantidadeInimigosPorComboio =  this->quantidadeInimigosTipoPorComboio[CAPITAO] 
												+ this->quantidadeInimigosTipoPorComboio[SAQUEADOR]
												+ this->quantidadeInimigosTipoPorComboio[CORSARIO]
												+ this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU];
			this->quantidadeInimigosWave = this->quantidadeInimigosPorComboio * this->quantidadeComboios;
			break;

		case SALA_REUNIAO:
			this->quantidadeComboios = 3;
			this->intervaloEntreComboios = 4*Tela::FPS;
			this->intervaloCriacaoInimigos = 1.5*Tela::FPS;
			this->atrasoEntreComboios = this->intervaloEntreComboios - Tela::FPS;
			
			if (this->numeroWave < 2)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 0;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 0;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 3;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 0;
			} else if (this->numeroWave < 3)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 0;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 4;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 0;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 0;
			
			} else if (this->numeroWave < 5)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 0;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 0;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 0;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 5;
			
			} else if (this->numeroWave == 5)
			{
				this->quantidadeInimigosTipoPorComboio[CAPITAO] = 1;
				this->quantidadeInimigosTipoPorComboio[SAQUEADOR] = 0;
				this->quantidadeInimigosTipoPorComboio[CORSARIO] = 0;
				this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU] = 0;			
			}
				
			this->quantidadeInimigosPorComboio =  this->quantidadeInimigosTipoPorComboio[CAPITAO] 
												+ this->quantidadeInimigosTipoPorComboio[SAQUEADOR]
												+ this->quantidadeInimigosTipoPorComboio[CORSARIO]
												+ this->quantidadeInimigosTipoPorComboio[PERNA_DE_PAU];
			this->quantidadeInimigosWave = this->quantidadeInimigosPorComboio * this->quantidadeComboios;
		break;
	}
	
	this->vetorInimigos = new vector<Inimigo *>;
}

vector<Inimigo *> * Wave::pegarVetorInimigos()
{
	return this->vetorInimigos;
}

int Wave::removerInimigosMortos()
{
	for (unsigned int i = 0; i < this->vetorInimigos->size(); i++)
	{
		if(this->vetorInimigos->at(i)->estaMorto)
		{
			Inimigo * inimigoQueSeraDeletado = this->vetorInimigos->at(i);
			Util::removerElementoVetor(this->vetorDesenhaveis, inimigoQueSeraDeletado);
			Util::removerElementoVetor(this->vetorMutaveis, inimigoQueSeraDeletado);
				
			this->vetorInimigos->erase(vetorInimigos->begin() + i);
			
			if(inimigoQueSeraDeletado->pontosVida > 0 && this->mestreAtual)
			{
				this->mestreAtual->pontosVida--;
				Hud::atualizarHP(this->mestreAtual->pontosVida);
				
			} else { // Aqui quer dizer que ele morreu pq alguma torre matou
				Hud::somarXP(inimigoQueSeraDeletado->pontosExperiencia);
			}
			
			this->indiceVetorInimigo--;
			this->quantidadeInimigosWave--;
			
			break;
		}
			
	}
	
	return 0;
}


