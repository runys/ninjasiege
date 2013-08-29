#ifndef TORRE_H
#define TORRE_H

#include <aliado.h>
#include <inimigo.h>
#include <ataque.h>
#include <wave.h>
#include <tempo.h>
#include <vector>

using namespace std;

enum TipoTorre
{
	SHURIKEN,
	KATANA,
	NUNCHAKU,
	MARIKI,
	KUNAI,
	BOMBA
};

const int PRECO_SHURIKEN=20;
const int PRECO_KATANA=15;
const int PRECO_NUNCHAKU=30;
const int PRECO_MARIKI=60;
const int PRECO_KUNAI=50;
const int PRECO_BOMBA=60;

enum EstadoTorre
{
	VIGIANDO,
	ATACANDO
};

class Torre : public Aliado
{
private:

	int ataquePorSegundo;
	TipoTorre tipo;
	SDL_Surface * ataque;
	static const int WIDTH;
	static const int HEIGHT;
	EstadoTorre estado;
	bool atirei;
	SDL_Rect alcance; //area de percepcao da torre

	SDL_Rect clip[6];
	double frame;
	bool ataquei;
	
	float DPS; //tiros por segundo
	float velocidadeTiro; // velocidade do tiro

	Uint32 comecaAtacar;
	Inimigo *alvo;
	void configurarTorre(TipoTorre tipo);
	bool isInimigoProximo(Inimigo * inimigo);
	int removerAtaquesTerminados();
	bool estaMaisProximo(Inimigo * candidatoAlvo, Inimigo * alvoAtual);

public:

	vector<Ataque *> * vetorAtaques;
	vector<Inimigo *> * vetorInimigos;
	vector<Desenhavel *> * vetorDesenhaveis;
	vector<Mutavel *> * vetorMutaveis;

	Torre(TipoTorre tipo, int x, int y, Wave * waveAtual, vector<Desenhavel *> * vetorDesenhaveis, vector<Mutavel *> * vetorMutaveis);
	~Torre();

	int fazerLogica();
	int realizarUpgrade();
	int detectarEvento();
	int desenhar();
	int detectarColisao();
	
};

#endif
