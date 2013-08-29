#include <util.h>
#include <tela.h>
#include <hud.h>
#include <mapa.h>
#include <ambiente.h>
#include <mutavel.h>
#include <desenhavel.h>
#include <escutavel.h>
#include <vector>
#include <jogo.h>

using namespace std;

EstadoJogo Util::estadoJogo = ENTRADA_JOGO; 
EstadoInterno Util::estadoInterno = TRANSICAO_WAVE;
EstadoInterno Util::ultimoEstadoInterno = OBSERVANDO;
TipoMapa Util::mapaAtual = SALA_REUNIAO;
TipoTorre Util::torreCompra;
ImagemCompra Util::imagemCompra;
SDL_Rect ImagemCompra::clip_compra = {0,0,40,40};

int ImagemCompra::desenharImagemCompra()
{
	SDL_BlitSurface(Util::imagemCompra.imagem, &ImagemCompra::clip_compra, SDL_GetVideoSurface(),Util::imagemCompra.rect);
	
	return 0;
}

int ImagemCompra::desenhar()
{	
	return 0;
}

ImagemCompra::~ImagemCompra()
{
	
}

void Util::trocarEstadoInterno(EstadoInterno novoEstado)
{
	Util::ultimoEstadoInterno = Util::estadoInterno;
	Util::estadoInterno = novoEstado;
}

ImagemCompra::ImagemCompra()
{
	Util::imagemCompra.rect = new SDL_Rect;
	Util::imagemCompra.rect->h = 40;
	Util::imagemCompra.rect->w = 40;
}

int ImagemCompra::configurarImagem(TipoTorre tipo)
{
	switch(tipo)
	{
		case KATANA:
			Util::imagemCompra.imagem = Ambiente::carregarImagem("ninja_katana.png");
			SDL_SetAlpha(Util::imagemCompra.imagem, SDL_SRCALPHA, 127);
			Util::imagemCompra.rect->x = Hud::BORDA_DIREITA - 30;
			Util::imagemCompra.rect->y = Tela::HEIGHT - Hud::HEIGHT_PARTE_BAIXO;
			break;
		case NUNCHAKU:
			Util::imagemCompra.imagem = Ambiente::carregarImagem("ninja_nunchaku.png");
			SDL_SetAlpha(Util::imagemCompra.imagem, SDL_SRCALPHA, 127);
			Util::imagemCompra.rect->x = 2*Hud::BORDA_DIREITA + (Mapa::TILE_WIDTH*2) - 30;
			Util::imagemCompra.rect->y = Tela::HEIGHT - Hud::HEIGHT_PARTE_BAIXO;
			break;
		case MARIKI:
			Util::imagemCompra.imagem = Ambiente::carregarImagem("ninja_mariki.png");
			SDL_SetAlpha(Util::imagemCompra.imagem, SDL_SRCALPHA, 127);
			Util::imagemCompra.rect->x = 3*Hud::BORDA_DIREITA + 2*(Mapa::TILE_WIDTH*2) - 30;
			Util::imagemCompra.rect->y = Tela::HEIGHT - Hud::HEIGHT_PARTE_BAIXO;
			break;
		case SHURIKEN:
			Util::imagemCompra.imagem = Ambiente::carregarImagem("ninja_shuriken.png");
			SDL_SetAlpha(Util::imagemCompra.imagem, SDL_SRCALPHA, 127);
			Util::imagemCompra.rect->x = 4*Hud::BORDA_DIREITA + 3*(Mapa::TILE_WIDTH*2) - 30;
			Util::imagemCompra.rect->y = Tela::HEIGHT - Hud::HEIGHT_PARTE_BAIXO;
			break;
		case KUNAI:
			Util::imagemCompra.imagem = Ambiente::carregarImagem("ninja_kunai.png");
			SDL_SetAlpha(Util::imagemCompra.imagem, SDL_SRCALPHA, 127);
			Util::imagemCompra.rect->x = 5*Hud::BORDA_DIREITA + 4*(Mapa::TILE_WIDTH*2) - 30;
			Util::imagemCompra.rect->y = Tela::HEIGHT - Hud::HEIGHT_PARTE_BAIXO;
			break;
		case BOMBA:
			Util::imagemCompra.imagem = Ambiente::carregarImagem("ninja_bomba.png");
			SDL_SetAlpha(Util::imagemCompra.imagem, SDL_SRCALPHA, 127);
			Util::imagemCompra.rect->x = 6*Hud::BORDA_DIREITA + 5*(Mapa::TILE_WIDTH*2) - 30;
			Util::imagemCompra.rect->y = Tela::HEIGHT - Hud::HEIGHT_PARTE_BAIXO;
			break;		
		
	}
	
	return 0;
}

