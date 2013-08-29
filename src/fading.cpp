#include <string>
#include <fading.h>
#include <ambiente.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>


using namespace std;

const int Fading::DELAY_FRAMES_INCREMENTO_ALFA = 3;
const int Fading::DELAY_FRAMES_INICIAR_INCREMENTO_ALFA = 15;

Fading::Fading(string nomeImagem, string nomeMusica, int segundos)
{
	this->alpha = SDL_ALPHA_TRANSPARENT;
	this->incremento = 0;
	this->imagem = Ambiente::carregarImagem(nomeImagem);
	this->rect = new SDL_Rect;
	this->rect->x = 0;
	this->rect->y = 0;
	this->rect->w = Tela::WIDTH;
	this->rect->h = Tela::HEIGHT;
	this->musicaFundo = Ambiente::carregarMusica(nomeMusica);
	this->tocouMusica = false;
	this->quantidadeFramesTerminarFading = (Fading::DELAY_FRAMES_INICIAR_INCREMENTO_ALFA) +  (int) (Tela::FPS * segundos);
	Mix_VolumeMusic(100);
}

Fading::~Fading()
{
	delete this->imagem;
	delete this->rect;
	Mix_HaltMusic();
	Mix_FreeMusic(this->musicaFundo);
}

int Fading::desenhar()
{
	
	
	if ( (this->incremento > Fading::DELAY_FRAMES_INICIAR_INCREMENTO_ALFA) && (this->incremento % Fading::DELAY_FRAMES_INCREMENTO_ALFA == 0))
	{
		SDL_SetAlpha(this->imagem, SDL_SRCALPHA, this->alpha);
		this->alpha++;
		SDL_BlitSurface(this->imagem, NULL, SDL_GetVideoSurface(), this->rect);
		
		if (this->tocouMusica == false)
		{
			Mix_PlayMusic(this->musicaFundo, 1);
			this->tocouMusica = true;
		}
	}

	this->incremento++;
	
	return 0; 	
}

bool Fading::terminouFading()
{
	if(this->incremento >= Fading::quantidadeFramesTerminarFading)
		return true;
	else
		return false;	
}
