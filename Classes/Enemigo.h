#ifndef __ENEMIGO_H__
#define __ENEMIGO_H__

#include "cocos2d.h"


USING_NS_CC;

class Enemigo
{
public:

	Enemigo();
	Enemigo(int);
	void mover(Sprite *);

	char *imagen;
	char *tipoMovimiento;
	bool derecha;
	int velocidad;

};

#endif