#ifndef ALIADO_H
#define ALIADO_H

#include <escutavel.h>
#include <mutavel.h>

class Aliado : public Mutavel
{
protected:
	int alcance;
	int dano;
public:
	virtual int realizarUpgrade() = 0;
};

#endif
