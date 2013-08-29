#ifndef MAPA_H
#define MAPA_H

#include <escutavel.h>
#include <vector>
#include <SDL/SDL_mixer.h>

struct PontoTile
{
	int x;
	int y;
};

#include <inimigo.h>
#include <mestre.h>

using namespace std;

enum Tile
{
	NAO_UTILIZAVEL,
	CAMINHO,
	UTILIZAVEL,
	ENTRADA,
	SAIDA
};

enum TipoMapa
{
	SALA_REUNIAO,
	SALA_ARTES_NEGRAS,
	SALA_GUARDA,
	SALA_TREINAMENTO,
	JARDIM_EXTERNO
};

struct Ponto{
	int x;
	int y;
};

class Mapa : public Escutavel
{	
private:
	PontoTile tileEntrada;
	void configurarMapa();
	void gerarSuperficieEmBranco();
	void gerarSuperficieMapa();
	static const int NUMERO_TOTAL_TILES;
	Mix_Music * musicaFundo;
	SDL_Surface * mascara;
	SDL_Rect clip[5];

public:
	static const int TILE_WIDTH;
	static const int TILE_HEIGHT;
	static const int TILES_POR_LINHA;
	static PontoTile tileSaida;
	
	TipoMapa tipo;
	vector<Tile> * tiles;
	vector<Ponto> tilesOcupados;
	Mapa(TipoMapa tipo);
	~Mapa();
	int desenhar();
	int detectarEvento();
	
	friend class Inimigo;
	friend class Mestre;
};

#endif
