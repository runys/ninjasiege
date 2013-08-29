#include <iostream>
#include <vector>
#include <util.h>
#include <jogo.h>
#include <mapa.h>
#include <torre.h>
#include <inimigo.h>

using namespace std;

int Jogo::configurarFaseAtual()
{
	this->inicioDeFase();	
	
	this->vetorDesenhaveis =  new vector<Desenhavel *>;
	this->vetorEscutaveis =  new vector<Escutavel *>;
	this->vetorMutaveis =  new vector<Mutavel *>;
	
	Hud::resetarPontos();
	
	// Coloca o mapa na jogada
	this->mapa = new Mapa(Util::mapaAtual);
	this->vetorDesenhaveis->push_back(this->mapa);
	this->vetorEscutaveis->push_back(this->mapa);
	
	// Coloca o mestre na jogada
	this->mestre = new Mestre(this->mapa);
	this->vetorDesenhaveis->push_back(this->mestre);
	this->vetorMutaveis->push_back(this->mestre);

	// Coloca o hud na jogada
	this->vetorDesenhaveis->push_back(this->hud);
	this->vetorEscutaveis->push_back(this->hud);
	
	// Coloca a wave na jogada
	this->wave = new Wave(Hud::numeradorWave, this->vetorDesenhaveis, this->vetorMutaveis, this->mapa, this->mestre);
}

int Jogo::estadoJogando()
{	
	
	this->configurarFaseAtual();
	
	while(Util::estadoJogo == JOGANDO)
	{
		this->tempo->iniciarTempo();

		if (Util::estadoInterno == PAUSADO)
		{
			this->estadoJogandoPausado();
		} else 
		{
			this->detectarTodosEventos();
			this->fazerTodaLogica();
			this->desenharTudo();
		}
		
		this->tela->renderizar();
		this->tempo->atrasarTempo();
	}
			
	return 0;	
}
