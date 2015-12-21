#ifndef __OBJETO_H__
#define __OBJETO_H__

#include "cocos2d.h"

USING_NS_CC;

class Objeto
{
public:
	Objeto();
	Objeto(int);

	char *imagenObjeto;
	char *tipoObjeto;

	Sprite *imagenobj;

	float posX;
	float posY;


};
#endif