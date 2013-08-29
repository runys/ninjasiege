#include <logofading.h>
#include <ambiente.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

const int LogoFading::DELAY_FRAMES_INCREMENTO_ALFA = 3;
const int LogoFading::DELAY_FRAMES_INICIAR_INCREMENTO_ALFA = 15;
const int LogoFading::QUANTIDADE_FRAMES_TERMINAR_FADING =(LogoFading::DELAY_FRAMES_INICIAR_INCREMENTO_ALFA) +  (int) (Tela::FPS *  5.5f);

LogoFading::LogoFading()
{
	this->alpha = SDL_ALPHA_TRANSPARENT;
	this->incremento = 0;
	this->imagem = Ambiente::carregarImagem("z_one_logo_800_600.png");
	this->rect = new SDL_Rect;
	this->rect->x = 0;
	this->rect->y = 0;
	this->rect->w = Tela::WIDTH;
	this->rect->h = Tela::HEIGHT;
	this->musicaFundo = Ambiente::carregarMusica("intro.mp3");
	Mix_VolumeMusic(100);
}

LogoFading::~LogoFading()
{
	delete this->imagem;
	delete this->rect;
	Mix_HaltMusic();
	Mix_FreeMusic(this->musicaFundo);
}

int LogoFading::desenhar()
{
	static bool tocouMusica = false;
	
	if ( (this->incremento > LogoFading::DELAY_FRAMES_INICIAR_INCREMENTO_ALFA) && (this->incremento % LogoFading::DELAY_FRAMES_INCREMENTO_ALFA == 0))
	{
		SDL_SetAlpha(this->imagem, SDL_SRCALPHA, this->alpha);
		this->alpha++;
		SDL_BlitSurface(this->imagem, NULL, SDL_GetVideoSurface(), this->rect);
		
		if (tocouMusica == false)
		{
			Mix_PlayMusic(this->musicaFundo, 1);
			tocouMusica = true;
		}
	}

	this->incremento++;
	
	return 0; 	
}

bool LogoFading::terminouFading()
{
	if(this->incremento >= LogoFading::QUANTIDADE_FRAMES_TERMINAR_FADING)
		return true;
	else
		return false;	
}
