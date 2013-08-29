#include <iostream>
#include <vector>
#include <util.h>
#include <jogo.h>
#include <hud.h>
#include <mapa.h>
#include <tela.h>
#include <ambiente.h>
#include <torre.h>
#include <inimigo.h>

using namespace std;

int Jogo::estadoJogandoPausado()
{	 
	while(SDL_PollEvent(&Escutavel::evento))
	{
		detectarSaidaAplicativo();
		Hud::botaoPausa->detectarEvento();
		if (Hud::botaoPausa->foiClicado())
		{
            //Resume the music
            Mix_ResumeMusic();
            Util::trocarEstadoInterno(Util::ultimoEstadoInterno);
		}
	}

	// Tem que arrumar isso aqui
	SDL_Surface * transparecerTela = SDL_CreateRGBSurface(0, Tela::WIDTH, Tela::HEIGHT, Tela::BPP, 0, 0, 0, 0);
	SDL_Rect rectTransparecerTela = {0, 0, Tela::WIDTH, Tela::HEIGHT};
	SDL_FillRect(transparecerTela,&rectTransparecerTela, SDL_MapRGB(transparecerTela->format,33,83,112));
	SDL_SetAlpha(transparecerTela, SDL_SRCALPHA, 1);
	SDL_BlitSurface(transparecerTela, NULL, SDL_GetVideoSurface(), &rectTransparecerTela);
	
	SDL_FreeSurface(transparecerTela);
	
	Hud::botaoPausa->desenhar();
				
	return 0;	
}

int Jogo::inicioDeFase()
{
	int atraso=0;
	int fimInicioFase = Tela::FPS * 6;
	int fimFading = Tela::FPS * 5;
	int alpha = 1;
	
	SDL_Surface * logo = Ambiente::carregarImagem("Logo.png");
	SDL_Rect logoRect = {145, 140, 0, 0};
	
	SDL_Surface * mensagem;
	SDL_Rect mensagemRect;
	switch (Util::mapaAtual)
	{
		case SALA_TREINAMENTO:
			mensagem = Ambiente::carregarTexto(string("Andar 4: Sala de Treinamento."), FONTE_MENSAGENS);	
			mensagemRect.x = 35;
			mensagemRect.y = 310;
			
			break;
		case JARDIM_EXTERNO:
			mensagem = Ambiente::carregarTexto(string("Andar 1: Jardim Externo."), FONTE_MENSAGENS);	
			mensagemRect.x = 105;
			mensagemRect.y = 310;
			
			break;
		case SALA_ARTES_NEGRAS:
			mensagem = Ambiente::carregarTexto(string("Andar 3: Sala de Artes Negras."), FONTE_MENSAGENS);	
			mensagemRect.x = 12;
			mensagemRect.y = 310;

			break;
		case SALA_GUARDA:
			mensagem = Ambiente::carregarTexto(string("Andar 4: Sala de Guarda."), FONTE_MENSAGENS);	
			mensagemRect.x = 105;
			mensagemRect.y = 310;

			break;
		case SALA_REUNIAO:
			mensagem = Ambiente::carregarTexto(string("Andar 5: Sala de Reuniao."), FONTE_MENSAGENS);	
			mensagemRect.x = 105;
			mensagemRect.y = 310;

			break;
	}
	
	SDL_Surface * fundo = Ambiente::carregarImagem("fundo_inicio_fase.png");
	SDL_Rect fundoRect = {0, 0, Tela::WIDTH, Tela::HEIGHT};
	SDL_BlitSurface(logo, NULL, fundo, &logoRect);
	SDL_BlitSurface(mensagem, NULL, fundo, &mensagemRect);
	
	while (atraso < fimInicioFase && Util::estadoJogo==JOGANDO)
	{
		this->tempo->iniciarTempo();
		
		while(SDL_PollEvent(&Escutavel::evento))
		{
			detectarSaidaAplicativo();
		}

		if (atraso < fimFading)
		{
			SDL_SetAlpha(fundo, SDL_SRCALPHA, alpha);
			alpha+=1;
			if (alpha > 255)	
				alpha = 255;
		}			
	
		SDL_BlitSurface(fundo, NULL, SDL_GetVideoSurface(), &fundoRect);
		
		this->tela->renderizar();
		
		this->tempo->atrasarTempo();
		
		atraso++;
	}
	
	return 0;
}

/*int Jogo::fimDeJogo()
{
	int atraso=0;
	int fimGameOver = Tela::FPS * 7;
	int fimFading = Tela::FPS * 5;
	int alpha = 1;
	
	SDL_Surface * imagemFimJogo = Ambiente::carregarImagem("game_over.png");
	SDL_Rect imagemFimJogoRect = {0, 0, 0, 0};
			
	while (atraso < fimGameOver && Util::estadoJogo==JOGANDO)
	{
		this->tempo->iniciarTempo();
		
		while(SDL_PollEvent(&Escutavel::evento))
		{
			detectarSaidaAplicativo();
		}

		if (atraso < fimFading)
		{
			SDL_SetAlpha(fundo, SDL_SRCALPHA, alpha);
			alpha+=1;
			if (alpha > 255)	
				alpha = 255;
		}			
	
		SDL_BlitSurface(imagemFimJogo, NULL, SDL_GetVideoSurface(), &imagemFimJogoRect);
		
		this->tela->renderizar();
		
		this->tempo->atrasarTempo();
		
		atraso++;
	}
	
	return 0;
}*/
