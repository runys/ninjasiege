#ifndef LOGOFADING_H
#define LOGOFADING_H

#include <tela.h>
#include <string>
#include <desenhavel.h>
#include <SDL/SDL_mixer.h>

using namespace std;

class Fading : public Desenhavel
{
private:
	static const int DELAY_FRAMES_INCREMENTO_ALFA;
	static const int DELAY_FRAMES_INICIAR_INCREMENTO_ALFA;
	int quantidadeFramesTerminarFading;
	int alpha;
	int incremento;
	bool tocouMusica;
	Mix_Music * musicaFundo;

public:	
	Fading(string nomeImagem, string nomeMusica, int segundos);
	~Fading();
	int desenhar();
	bool terminouFading();
};

#endif
