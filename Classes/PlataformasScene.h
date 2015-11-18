#ifndef __PLATAFORMAS_SCENE_H__
#define __PLATAFORMAS_SCENE_H__


#include "cocos2d.h"
#include "Enemigo.h"

USING_NS_CC;

const int VELOCIDADPRIN = 3;
const int FSALTOPRINCESA = 90000;
const int FGRAVEDAD = -100;
const int FFLOTAR = 30000;

class PlataformasScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
	
	Sprite *princesa;
	Enemigo **enemigos;
	Sprite **imagenEnemigos;

	EventKeyboard::KeyCode teclaPresioanda;
	bool prinMovL;
	bool prinMovR;
	bool prinSalto;
	bool prinDerecha;
	Vec2 prinPos;

	PhysicsWorld *fMundo;

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	//teclas
	void teclaPresionada(EventKeyboard::KeyCode idTecla, Event *evento);
	void teclaLevantada(EventKeyboard::KeyCode idTecla, Event *evento);
	
	void update(float dt);

	//Fisicas

	void setPhysicsWorld(PhysicsWorld *mundo);
	bool onContactBegin(PhysicsContact &contacto);
    
    // implement the "static create()" method manually
	CREATE_FUNC(PlataformasScene);
};

#endif
