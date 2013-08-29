#include <jogo.h>
#include <util.h>
#include <menuprincipal.h>

int Jogo::estadoMenuJogo()
{
	
	this->vetorDesenhaveis =  new vector<Desenhavel *>;
	this->vetorEscutaveis =  new vector<Escutavel *>;
	
	MenuPrincipal * menuPrincipal = new MenuPrincipal();	
		
	this->vetorDesenhaveis->push_back(menuPrincipal);
	this->vetorEscutaveis->push_back(menuPrincipal);

	while(Util::estadoJogo == MENU_PRINCIPAL)
	{
		this->tempo->iniciarTempo();
		
		this->detectarTodosEventos();
		
		this->desenharTudo();
		
		this->tela->renderizar();
		
		this->tempo->atrasarTempo();
	}
	
	delete menuPrincipal;
	delete this->vetorDesenhaveis;
	delete this->vetorEscutaveis;
	
	return 0;	
}
