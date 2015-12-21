#ifndef __NIVEL_H__
#define __NIVEL_H__

#include "cocos2d.h"
#include "Casilla.h"

USING_NS_CC;

class Nivel
{
public:

	Nivel();
	Nivel(int);

	bool **puntuacion;
	Casilla **MatrizInicial;
	Casilla **MatrizCorrecta;
	Casilla **MatrizJugador;
	Casilla **VecCasillas;

	int LongVec;
	int LongMat;

	
};
#endif
