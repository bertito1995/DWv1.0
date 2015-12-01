#pragma once
#ifndef __CASILLA_H__
#define __CASILLA_H__


#include "cocos2d.h"
#include "Enemigo.h"
#include "Objeto.h"

USING_NS_CC;

class Casilla : public cocos2d::Layer
{
public:
	CREATE_FUNC(Casilla);

	Casilla();
	char *imagenCasilla;
	Casilla(int);

	void escalar(Sprite *);

	Objeto **listaObjetos;
	int numObj =0;

	Objeto **listaPlataformas;
	int numPla = 0;
	
	Enemigo **listaEnemigos;
	int numEne = 0;

	Sprite *imagencas;
	
	
	//void posicion(Sprite *, Sprite *, float, float);





};
#endif