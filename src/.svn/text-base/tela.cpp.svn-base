#include <tela.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <ambiente.h>
#include <iostream>

using namespace std;

Tela::Tela()
{
    // Define a tela do jogo 
    this->canvas = SDL_SetVideoMode(this->WIDTH, this->HEIGHT, this->BPP, this->VIDEO_OPTIONS);
    
    // Define o título da tela do jogo
	SDL_WM_SetCaption("Ninja Siege", "Ninja Siege");
	SDL_WM_SetIcon(Ambiente::carregarIcone("icon.bmp"), NULL);
    cout << "Ninja Siege, by Z-One Team." << endl;
        
	Ambiente::carregarFonte();
}

Tela::~Tela()
{
	SDL_FreeSurface(this->canvas);
}

int Tela::detectarEvento()
{       
    
    return 0;
}

void Tela::aplicarSuperficie(SDL_Surface * superficie, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    
    SDL_BlitSurface(superficie, NULL, this->canvas, &offset);
}

void Tela::renderizar()
{
    SDL_Flip(this->canvas);
}
