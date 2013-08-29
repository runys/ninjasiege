#include <jogo.h>
# include <iostream>
/* Let the magic begin! */
using namespace std;
int main()
{
	Jogo * jogo;
	
	jogo = new Jogo();
	jogo->rodar();
	return 0;
}
