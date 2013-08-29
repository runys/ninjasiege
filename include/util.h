#ifndef UTIL_H
#define UTIL_H

#include <mutavel.h>
#include <desenhavel.h>
#include <escutavel.h>
#include <vector>
#include <torre.h>

using namespace std;

enum EstadoJogo
{
	ENTRADA_JOGO,
	MENU_PRINCIPAL,
	JOGANDO,
	FIM_JOGO,
	CREDITOS,
	SAIDA_APLICATIVO
};

enum EstadoInterno{
	COMPRANDO,
	OBSERVANDO,
	PAUSADO,
	TRANSICAO_WAVE
};

class ImagemCompra : public Desenhavel
{
public:
	ImagemCompra();	
	static int configurarImagem(TipoTorre tipo);
	~ImagemCompra();
	int desenhar();
	static int desenharImagemCompra();
	static SDL_Rect clip_compra;
};

class Util
{
public:
	static EstadoJogo estadoJogo;
	static EstadoInterno estadoInterno;
	static EstadoInterno ultimoEstadoInterno;
	static TipoTorre torreCompra;
	static ImagemCompra imagemCompra;
	static TipoMapa mapaAtual;

	static void trocarEstadoInterno(EstadoInterno novoEstado);
	
	template <class C>
	static void removerElementoVetor(vector<C *> * vetor, Desenhavel * desenhavel)
	{
		for(unsigned int i = 0; i < vetor->size(); i++)
			if(vetor->at(i) == desenhavel)
				vetor->erase(vetor->begin() + i);
	}
};

#endif
