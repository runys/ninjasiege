#include <jogo.h>
#include <util.h>
#include <SDL/SDL.h>

int Jogo::detectarSaidaAplicativo()
{
	if(Escutavel::evento.type == SDL_QUIT)
		Util::estadoJogo = SAIDA_APLICATIVO;
	return 0;	
}
