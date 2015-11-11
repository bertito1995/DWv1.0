#ifndef __ENEMIGO_H__
#define __ENEMIGO_H__

#include "cocos2d.h"


USING_NS_CC;

class Enemigo : public cocos2d::Layer
{
public:
	
	virtual bool init();
	CREATE_FUNC(Enemigo);

	void setTipo(String tipo);
	void setImagen(Sprite *imagen);
	void setDerecha(bool derecha);
	Vec2 getPos();
	void mover();

	Sprite *imagen;
	String tipo;
	bool derecha;
	Vec2 pos;
	int velocidad;
};

#endif