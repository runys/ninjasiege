#include <menuprincipal.h>
#include <botao.h>
#include <jogo.h>
#include <util.h>
#include <ambiente.h>
#include <SDL/SDL_mixer.h>
#include <iostream>

using namespace std;

MenuPrincipal::MenuPrincipal()
{
	this->botaoNovoJogo = new Botao(Ambiente::carregarImagem("botao_novo_jogo.png"), BOTAO_NOVO_JOGO);
	this->botaoNovoJogo->rect->x = 590;
	this->botaoNovoJogo->rect->y = 180;
	
	this->botaoContinuar = new Botao(Ambiente::carregarImagem("botao_continue.png"), BOTAO_CONTINUAR);
	this->botaoContinuar->rect->x = 590;
	this->botaoContinuar->rect->y = 280;
	
	this->botaoConfiguracoes = new Botao(Ambiente::carregarImagem("botao_configuracao.png"), BOTAO_CONFIGURACOES);
	this->botaoConfiguracoes->rect->x = 590;
	this->botaoConfiguracoes->rect->y = 400;
	
	this->botaoAjuda = new Botao(Ambiente::carregarImagem("botao_tutorial.png"), BOTAO_AJUDA);
	this->botaoAjuda->rect->x = 710;
	this->botaoAjuda->rect->y = 400;

	this->botaoSair = new Botao(Ambiente::carregarImagem("botao_sair.png"), BOTAO_SAIR);
	this->botaoSair->rect->x = 743;
	this->botaoSair->rect->y = 10;

	this->botaoCreditos = new Botao(Ambiente::carregarImagem("botao_creditos.png"), BOTAO_CREDITOS);
	this->botaoCreditos->rect->x = 590;
	this->botaoCreditos->rect->y = 500;
	
	this->logo = Ambiente::carregarImagem("Logo.png");
	this->logoRect.x = 30;
	this->logoRect.y = 35;
	
	this->desenho = Ambiente::carregarImagem("menu_principal2.png");
	this->desenhoRect.x = 0;
	this->desenhoRect.y = 0;
	
	this->rodape = Ambiente::carregarTexto(string("Ninja Siege, by Z-one Team. 2013."), FONTE_MENU_INICIAL);
	this->rodapeRect.x = 240;
	this->rodapeRect.y = 560;
	
	this->musicaFundo = Ambiente::carregarMusica("Theme Menu.mp3");
	Mix_VolumeMusic(80);
	Mix_PlayMusic(this->musicaFundo, -1);
}

MenuPrincipal::~MenuPrincipal()
{
	delete this->botaoNovoJogo;
	delete this->botaoContinuar;
	delete this->botaoConfiguracoes;
	delete this->botaoSair;
	delete this->botaoCreditos;
	delete this->botaoAjuda;
	SDL_FreeSurface(this->logo);
	SDL_FreeSurface(this->desenho);
	SDL_FreeSurface(this->rodape);
	Mix_HaltMusic();
	Mix_FreeMusic(this->musicaFundo);
}

int MenuPrincipal::detectarEvento()
{
	this->botaoNovoJogo->detectarEvento();
	if (this->botaoNovoJogo->foiClicado())
		Util::estadoJogo = JOGANDO;
	
	this->botaoContinuar->detectarEvento();
	
	this->botaoConfiguracoes->detectarEvento();
	
	this->botaoSair->detectarEvento();
	if (this->botaoSair->foiClicado())
		Util::estadoJogo = SAIDA_APLICATIVO;

	this->botaoCreditos->detectarEvento();

	this->botaoAjuda->detectarEvento();
	
	return 0;
}

int MenuPrincipal::desenhar()
{
	SDL_BlitSurface(this->desenho, NULL, SDL_GetVideoSurface(), &this->desenhoRect);	
	
	this->botaoNovoJogo->desenhar();
	
	// this->botaoContinuar->desenhar();
	
	// this->botaoConfiguracoes->desenhar();
	
	this->botaoSair->desenhar();
	
	// this->botaoCreditos->desenhar();
	
	// this->botaoAjuda->desenhar();
	
	SDL_BlitSurface(this->logo, NULL, SDL_GetVideoSurface(), &this->logoRect);
	
	SDL_BlitSurface(this->rodape, NULL, SDL_GetVideoSurface(), &this->rodapeRect);
		
	return 0;
}
