#ifndef BOTAO_H
#define BOTAO_H

#include <escutavel.h>
#include <SDL/SDL.h>

#include <string>
#include <torre.h>

using namespace std;

enum TipoBotao
{
	BOTAO_SHURIKEN,
	BOTAO_KATANA,
	BOTAO_NUNCHAKU,
	BOTAO_MARIKI,
	BOTAO_KUNAI,
	BOTAO_BOMBA,
	BOTAO_PAUSE,
	BOTAO_INIT_WAVE,
	BOTAO_AJUDA,
	BOTAO_CONFIGURACOES,
	BOTAO_CONTINUAR,
	BOTAO_CREDITOS,
	BOTAO_SAIR,
	BOTAO_NOVO_JOGO
};

struct Preco : public Desenhavel
{
	int desenhar();
	Preco(int preco);
	~Preco();
};

class Botao : public Escutavel
{
private:
	string rotulo;
	bool clicado;
	TipoBotao tipo;
	SDL_Rect clip[2];
	int frame;
	int atrasoPiscaBotao; // SOMENTE PARA O BOTÃO DE INIT
	bool mouseEstaSobre();
	bool estaHabilitado();
	
public:
	
	// Construtores sem coordenadas: O CRIADOR DO BOTAO SE VIRA PARA POSICIONA-LO
	Botao(string rotulo);
	Botao(SDL_Surface * imagem);
	Botao(SDL_Surface * imagem, TipoBotao tipo);

	// Construtores mais complexos, contemplando as coordenadas do botao
	Botao(int x, int y, int w, int h, string rotulo);
	Botao(int x, int y, int w, int h, SDL_Surface * imagem);
	
	Preco * preco;
	
	~Botao();

	int desenhar();
	int detectarEvento();
	bool foiClicado();
};

#endif
