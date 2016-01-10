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
	void cambiarImagen();

	char *imagenL;
	char *imagenL2;
	char *imagenR;
	char *imagenR2;
	int imagenActual;
	char *tipoMovimiento;
	int identificador;

	Sprite *imagenEne;

	float posX;
	float posY;

	int faseMov;
	int velocidad;

};

#endif