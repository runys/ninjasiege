#ifndef ATAQUE_H
#define ATAQUE_H

#include <mutavel.h>
#include <inimigo.h>

class Ataque : public Mutavel
{
	static const int WIDTH;
	static const int HEIGHT;
	
public:
	bool cheguei;
	Inimigo * inimigo;
	int fazerLogica();
	int desenhar();
	int detectarColisao();
	Ataque(SDL_Surface * imagem, int x, int y, Inimigo * alvo);
	~Ataque();

};

#endif
