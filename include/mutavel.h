#ifndef MUTAVEL_H
#define MUTAVEL_H

#include <desenhavel.h>

class Mutavel : public Desenhavel
{
protected:
	float deltaX;
	float deltaY;
public:
	virtual int fazerLogica() = 0;
	virtual int detectarColisao() = 0;
};

#endif
