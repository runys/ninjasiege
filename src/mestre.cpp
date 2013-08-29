#include <mestre.h>
#include <ambiente.h>
#include <SDL/SDL.h>

Mestre::Mestre(Mapa * mapaAtual)
{
	this->rect = new SDL_Rect;
	this->rect->w = Mapa::TILE_WIDTH * 2;			
	this->rect->h = Mapa::TILE_HEIGHT * 2;
	this->rect->x = mapaAtual->tileSaida.x * (Mapa::TILE_WIDTH);
	this->rect->y = mapaAtual->tileSaida.y * Mapa::TILE_HEIGHT;
	this->imagem = Ambiente::carregarImagem("ninja_gordo.png");
	this->pontosVida = 10;
}

Mestre::~Mestre()
{
	delete this->rect;
	delete this->imagem;
}

int Mestre::fazerLogica()
{
	static bool praCima = true;
	static int atraso = 0;
	
	if(atraso++ > 10)
	{
		if(praCima)
			this->rect->y += -4;
		else
			this->rect->y += 4;
		praCima = !praCima;
		atraso = 0;
	}
	return 0;
}

int Mestre::detectarColisao()
{
	return 0;
}

int Mestre::desenhar()
{
	SDL_BlitSurface(this->imagem, NULL, SDL_GetVideoSurface(), this->rect);
	return 0;
}
