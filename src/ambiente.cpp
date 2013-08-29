#include <mapa.h>
#include <stdlib.h>
#include <ambiente.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const string Ambiente::CAMINHO_IMG = "media/image/";
const string Ambiente::CAMINHO_MAPAS = "media/maps/";
const string Ambiente::CAMINHO_AUDIO = "media/audio/";
const string Ambiente::CAMINHO_FONT = "media/font/";
TTF_Font * Ambiente::fonteHUD = NULL;
TTF_Font * Ambiente::fontePreco = NULL;
TTF_Font * Ambiente::fonteMenuInicial = NULL;
TTF_Font * Ambiente::fonteMensagens = NULL;

void Ambiente::carregarFonte()
{
	string caminho = Ambiente::CAMINHO_FONT + "lastninja.ttf";
	Ambiente::fonteHUD = TTF_OpenFont(caminho.c_str(), 20);
	if (!Ambiente::fonteHUD)
		cout << "Erro na hora de carregar a fonte: " << TTF_GetError() << endl;
		
	Ambiente::fontePreco = TTF_OpenFont(caminho.c_str(), 10);
	if (!Ambiente::fontePreco)
		cout << "Erro na hora de carregar a fonte: " << TTF_GetError() << endl;
		
	Ambiente::fonteMenuInicial = TTF_OpenFont(caminho.c_str(), 12);
	if (!Ambiente::fonteMenuInicial)
		cout << "Erro na hora de carregar a fonte: " << TTF_GetError() << endl;
		
	Ambiente::fonteMensagens = TTF_OpenFont(caminho.c_str(), 30);
	if (!Ambiente::fonteMensagens)
		cout << "Erro na hora de carregar a fonte: " << TTF_GetError() << endl;
}

SDL_Surface * Ambiente::carregarTexto(string texto, TipoFonte tipo)
{
	SDL_Color colorFonte = {0, 0, 0}; // um cinza qualquer, soh pra funfar
	
	TTF_Font * fonte;
	
	switch(tipo)
	{
		case FONTE_HUD:
			fonte = Ambiente::fonteHUD;
			break;
		case FONTE_PRECO:
			fonte = Ambiente::fontePreco;
			break;
		case FONTE_MENU_INICIAL:
			fonte = Ambiente::fonteMenuInicial;
			break;
		case FONTE_MENSAGENS:
			fonte = Ambiente::fonteMensagens;
			colorFonte.r=225;
			colorFonte.g=211;
			colorFonte.b=185;
			break;
	}
	
	SDL_Surface * retorno = TTF_RenderText_Blended(fonte, texto.c_str(), colorFonte);
	
	if(!retorno)
	{
		cout << "Erro ao renderizar fonte: " << SDL_GetError() << endl;
		return NULL;
	}
	
	return retorno;
}

SDL_Surface * Ambiente::carregarImagem(string caminho)
{
	caminho = Ambiente::CAMINHO_IMG + caminho;

	SDL_Surface * loadedImage = NULL;
	SDL_Surface * optimizedImage =  NULL;
	loadedImage = IMG_Load(caminho.c_str());

	if(!loadedImage)
	{
		cout << "Erro ao abrir musica: " << SDL_GetError() << endl;
		return NULL;
	}

    optimizedImage = SDL_DisplayFormat(loadedImage);
    if( optimizedImage != NULL ) 
    { 
    	//Map the color key 
    	Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0xFF, 0, 0xFF );
    	//Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent 
    	SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey ); 
 	}
    
    SDL_FreeSurface(loadedImage);

    return optimizedImage;
}

SDL_Surface * Ambiente::carregarIcone(string caminho)
{
	caminho = Ambiente::CAMINHO_IMG + caminho;

	SDL_Surface * loadedImage = NULL;
	loadedImage = SDL_LoadBMP(caminho.c_str());
	
	if(!loadedImage)
	{
		cout << "Erro ao abrir icone: " << SDL_GetError() << endl;
		return NULL;
	}      
    
    return loadedImage;
}

Mix_Music * Ambiente::carregarMusica(string caminho)
{
	caminho = Ambiente::CAMINHO_AUDIO + caminho;
	Mix_Music * musica = NULL;
	musica = Mix_LoadMUS(caminho.c_str());
	
	if(!musica)
	{
		cout << "Erro ao abrir musica: " << Mix_GetError << endl;
		return NULL;
	}      
    
    return musica;
}


vector<Tile> * Ambiente::carregarConfiguracaoMapa(string caminho)
{
	caminho = Ambiente::CAMINHO_MAPAS + caminho;
	vector<Tile> * vetorCodigosTiles = new vector<Tile>;
  	ifstream arquivo(caminho.c_str()); // ifstream = padrão ios:in
	if (arquivo.is_open())
	{
		string codigoString;
		Tile codigo;
		while (arquivo >> codigoString)
		{
			codigo = (Tile) atoi(codigoString.c_str());
			vetorCodigosTiles->push_back(codigo);
		}
		arquivo.close();
	}
	
	return vetorCodigosTiles;
}
