#include <botao.h>
#include <ambiente.h>
#include <SDL/SDL.h>
#include <iostream>
#include <util.h>
#include <torre.h>
#include <hud.h>
#include <ambiente.h>

using namespace std;

int Preco::desenhar()
{
	SDL_BlitSurface(this->imagem, NULL, SDL_GetVideoSurface(), this->rect);
	
	return 0;
}

Preco::Preco(int preco)
{
	this->rect = new SDL_Rect;
	this->rect->x = -1;
	this->rect->y = -1;
	
	char precoString [10];
	sprintf(precoString, "%d", preco);
	this->imagem = Ambiente::carregarTexto(string(precoString), FONTE_PRECO);
	
}

Preco::~Preco()
{
	delete this->rect;
	SDL_FreeSurface(this->imagem);
}

Botao::Botao(string rotulo)
{
	this->rect = new SDL_Rect;
	this->rect->x = -1;
	this->rect->y = -1;

	// Futuramente o width e o height podem ser independentes hehe

	this->imagem = Ambiente::carregarTexto(rotulo, FONTE_HUD);

	this->rect->w = imagem->w; 
	this->rect->h = imagem->h;

	this->clicado = false;
}

Botao::Botao(SDL_Surface * imagem)
{
	this->rect = new SDL_Rect;
	this->rect->x = -1;
	this->rect->y = -1;

	// Futuramente o width e o height podem ser independentes hehe
	this->rect->w = imagem->w; 
	this->rect->h = imagem->h;
	
	this->imagem = imagem;
	this->clicado = false;	
}

Botao::Botao(SDL_Surface * imagem, TipoBotao tipo)
{
	this->rect = new SDL_Rect;
	this->rect->x = 0;
	this->rect->y = 0;

	// Futuramente o width e o height podem ser independentes hehe
	this->rect->w = imagem->w; 
	this->rect->h = imagem->h;
	this->tipo = tipo;
	
	switch (this->tipo)
	{
		case BOTAO_SHURIKEN:	
			this->preco = new Preco(PRECO_SHURIKEN);
			break;
		case BOTAO_KATANA:
			this->preco = new Preco(PRECO_KATANA);
			break;
		case BOTAO_NUNCHAKU:
			this->preco = new Preco(PRECO_NUNCHAKU);
			break;
		case BOTAO_MARIKI:
			this->preco = new Preco(PRECO_MARIKI);
			break;
		case BOTAO_KUNAI:
			this->preco = new Preco(PRECO_KUNAI);
			break;
		case BOTAO_BOMBA:
			this->preco = new Preco(PRECO_BOMBA);
			break;
		case BOTAO_INIT_WAVE:
			this->atrasoPiscaBotao = 1;
		default:
			this->preco = NULL;
	}

	this->imagem = imagem;
	this->clicado = false;
	
	this->frame = 0;
	
	this->clip[0].h = this->clip[1].h = this->imagem->h;
	this->clip[0].w = this->clip[1].w = this->imagem->w/2;
	
	this->clip[0].y = this->clip[1].y = 0;
	this->clip[0].x = 0;
	this->clip[1].x = this->imagem->w/2;
}

Botao::Botao(int x, int y, int w, int h, string rotulo)
{
	this->rect = new SDL_Rect;
	this->rect->x = x;
	this->rect->y = y;

	// duas linhas abaixo soh para tirar warnings
	this->rect->w = w; 
	this->rect->h = h;

	// Futuramente o width e o height podem ser independentes hehe
	this->imagem = Ambiente::carregarTexto(rotulo, FONTE_HUD);
	this->rect->w = imagem->w; 
	this->rect->h = imagem->h;

	this->clicado = false;
}

Botao::Botao(int x, int y, int w, int h, SDL_Surface * imagem)
{
	this->rect = new SDL_Rect;
	this->rect->x = x;
	this->rect->y = y;

	// duas linhas abaixo soh para tirar warnings
	this->rect->w = w; 
	this->rect->h = h;

	// Futuramente o width e o height podem ser independentes hehe
	this->rect->w = imagem->w; 
	this->rect->h = imagem->h;

	this->imagem = imagem;
	this->clicado = false;
}

Botao::~Botao()
{
	//if(this->imagem) delete this->imagem;
	//if(this->rect) 	 delete this->rect;
}

bool Botao::estaHabilitado()
{
	bool estaHabilitado = false;
	
	switch (this->tipo)
	{
		case BOTAO_SHURIKEN:
			if (Hud::pontosXP >= PRECO_SHURIKEN)
				estaHabilitado = true;
			
			break;
		case BOTAO_KATANA:
			if (Hud::pontosXP >= PRECO_KATANA)
				estaHabilitado = true;
			
			break;
		case BOTAO_NUNCHAKU:
			if (Hud::pontosXP >= PRECO_NUNCHAKU)
				estaHabilitado = true;
			
			break;
		case BOTAO_MARIKI:
			if (Hud::pontosXP >= PRECO_MARIKI)
				estaHabilitado = true;
			
			break;
		case BOTAO_KUNAI:
			if (Hud::pontosXP >= PRECO_KUNAI)
				estaHabilitado = true;
			
			break;
		case BOTAO_BOMBA:
			if (Hud::pontosXP >= PRECO_BOMBA)
				estaHabilitado = true;
			
			break;
		case BOTAO_INIT_WAVE:
			if (Util::estadoInterno == TRANSICAO_WAVE || (Util::estadoInterno == COMPRANDO && Util::ultimoEstadoInterno == TRANSICAO_WAVE))
				estaHabilitado = true;
			
			break;
		default:
			estaHabilitado =  true;
	}
	
	return estaHabilitado;
}

int Botao::desenhar()
{
	int alpha =  255;

	if (!estaHabilitado())
		alpha = 120;
		
	if(!mouseEstaSobre() && estaHabilitado() && this->tipo == BOTAO_INIT_WAVE)
	{	
		if (this->atrasoPiscaBotao == 0.5*Tela::FPS)
		{
			if(this->frame)
				this->frame = 0;
			else
				this->frame = 1;

			this->atrasoPiscaBotao=1;
		}
		this->atrasoPiscaBotao++;
	} else
	{
		if (this->preco)
		{
			SDL_BlitSurface(this->preco->imagem, NULL, SDL_GetVideoSurface(), this->preco->rect);	
		}		
	}
	
	SDL_SetAlpha(this->imagem, SDL_SRCALPHA, alpha);
	SDL_BlitSurface(this->imagem, &this->clip[frame], SDL_GetVideoSurface(), this->rect);
	
	return 0;
}

bool Botao::mouseEstaSobre()
{
	if(Escutavel::evento.type == SDL_MOUSEMOTION && !Escutavel::evento.active.gain)
	{
		int x = Escutavel::evento.motion.x;
		int y = Escutavel::evento.motion.y;
		
		if(this->rect->x <= x && x <= this->rect->x + this->rect->w &&
				this->rect->y <= y && y <= this->rect->y + this->rect->h)
			return true;
		else 
			return false;
		
	}
	
	return false;
}

int Botao::detectarEvento()
{
	if(Escutavel::evento.type == SDL_MOUSEBUTTONDOWN)
	{
		if(Escutavel::evento.button.button == SDL_BUTTON_LEFT)
		{
			int x = Escutavel::evento.button.x;
			int y = Escutavel::evento.button.y;

			// Verifica se o clique foi em cima desse botao em especifico
			if(this->rect->x <= x && x <= this->rect->x + this->rect->w &&
				this->rect->y <= y && y <= this->rect->y + this->rect->h)
			{
				this->clicado = true;
			}
		}
	}
	
	if (mouseEstaSobre())
		this->frame = 1;
	else
		this->frame = 0;
	
	return 0;
}

bool Botao::foiClicado()
{
	bool temp = this->clicado;
	this->clicado = false;
	return temp;
}
