#ifndef WAVE_H
#define WAVE_H

#include <inimigo.h>
#include <desenhavel.h>
#include <mutavel.h>
#include <mapa.h>
#include <mestre.h>
#include <vector>

using namespace std;

class Wave
{
private:
	vector<Inimigo *> * vetorInimigos;
	vector<Desenhavel *> * vetorDesenhaveis;
	vector<Mutavel *> * vetorMutaveis;
	Mapa * mapaAtual;
	Mestre * mestreAtual;
	
	int intervaloCriacaoInimigos;
	int intervaloEntreComboios;
	
	int quantidadeComboios;
	int quantidadeInimigosPorComboio;
	int quantidadeInimigosTipoPorComboio[4];
	int inimigosLancadosNoComboio;
	int quantidadeInimigosWave;
	int comboiosJaLancados;
	
	int atrasoCriacaoInimigos;
	int atrasoEntreComboios;
	
	int indiceVetorInimigo;
	
	int removerInimigosMortos();
	int lancarInimigos();
	
	bool podeConfigurarComboio;
	bool podeLancarInimigos;
		
	int numeroWave;
	
	void configurarWave();
	void configurarComboio();
	void lancarInimigo();
	
public:
	Wave(int numeroWave, vector<Desenhavel *> * vetorDesenhaveis, vector<Mutavel *> * vetorMutaveis, Mapa * mapaAtual, Mestre * mestreAtual);
	~Wave();
	vector<Inimigo *> * pegarVetorInimigos();
	
	bool waveTerminou;
	int fazerLogica();
};

#endif
