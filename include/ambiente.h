#ifndef AMBIENTE_H
#define AMBIENTE_H

#include <mapa.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include <vector>

using namespace std;

enum TipoFonte
{
	FONTE_HUD,
	FONTE_PRECO,
	FONTE_MENU_INICIAL,
	FONTE_MENSAGENS
};

class Ambiente
{
private:
	static const string CAMINHO_IMG;
	static const string CAMINHO_MAPAS;
	static const string CAMINHO_AUDIO;
	static const string CAMINHO_FONT;

public:
	static SDL_Surface * carregarImagem(string caminho);
	static Mix_Music * carregarMusica(string caminho);
	static SDL_Surface * carregarTexto(string texto, TipoFonte tipo);
	static SDL_Surface * carregarIcone(string caminho);
	static vector<Tile> * carregarConfiguracaoMapa(string caminho);
	static TTF_Font * fonteHUD;
	static TTF_Font * fontePreco;
	static TTF_Font * fonteMenuInicial;
	static TTF_Font * fonteMensagens;
	static void carregarFonte();
};

#endif
