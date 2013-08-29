#ifndef TELA_H
#define TELA_H

#include <SDL/SDL.h>
#include <desenhavel.h>

class Tela
{
private:
	static const Uint32 VIDEO_OPTIONS = SDL_HWSURFACE | SDL_DOUBLEBUF;
	
public:
	SDL_Surface * canvas;
	static const int WIDTH = 800;
	static const int HEIGHT = 600;
	static const int BPP = 32;
	static const int FPS = 30;
	
	Tela();
	~Tela();
	int detectarEvento();
	void aplicarSuperficie(SDL_Surface * superficie, int x, int y);
	void renderizar();
};
	
#endif
