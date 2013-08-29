#include <jogo.h>
#include <util.h>
#include <iostream>

using namespace std;

int Jogo::desenharTudo()
{	
	for(unsigned int i = 0; i < this->vetorDesenhaveis->size(); i++)
		this->vetorDesenhaveis->at(i)->desenhar();

	if (Util::estadoInterno == COMPRANDO)
	{	
		Util::imagemCompra.desenharImagemCompra();
	}
		
	
	return 0;
}
