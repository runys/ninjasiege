#ifndef INIMIGO_H
#define INIMIGO_H

#include <mutavel.h>
#include <mapa.h>

enum TipoInimigo
{
	CAPITAO,
	SAQUEADOR,
	CORSARIO,
	PERNA_DE_PAU
};

class Mapa;

class Inimigo : public Mutavel
{
private:
	
	TipoInimigo tipo;
	PontoTile tileAtual;
	PontoTile tileAnterior;
	Mapa * mapaAtual;

	int deltaX;
	int deltaY;
	int velocidade;
	int pixelsAndados;
	bool recemCriado;
	SDL_Rect hp_verde;
	SDL_Rect hp_vermelho;	

	int offset;
	double frame;
	bool direcaoEsquerda;
	SDL_Rect clip[10];
	
	int setarProximaPosicao();
	bool ehCaminho(int posicao);
	void tremer();
	
public:
	Inimigo(int tipo, Mapa * mapaAtual);
	~Inimigo();

	bool estaMorto;
	bool estaNoJogo;
	int pontosVida;
	int pontosVidaTotal;  			// DEPOIS VER ISSO :D
	int pontosExperiencia;

	int desenhar();
	int fazerLogica();
	int detectarColisao();	
	void subtrairVida(int dano);
};

#endif
