#ifndef __PLATAFORMAS_SCENE_H__
#define __PLATAFORMAS_SCENE_H__


#include "cocos2d.h"
#include "Enemigo.h"

USING_NS_CC;
using namespace std;

const int VELOCIDADPRIN = 3;
const int FSALTOPRINCESA = 90000;
const int FGRAVEDAD = -100;
//const int FFLOTAR = 30000;
const int FFLOTAR = 0;

const int FRAMESCORRER = 14;
const float FRCORRER = 0.07f;

class PlataformasScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
	
	Vector <Sprite*> correrPrincesaR;
	Vector <Sprite*> correrPrincesaL;
	Sprite *princesa;
	Enemigo **enemigos;
	Sprite **imagenEnemigos;

	float contadoCorrer = 0;
	int indiceCorrer = 1;

	EventKeyboard::KeyCode teclaPresioanda;
	bool prinMovL;
	bool prinMovR;
	bool prinSalto;
	bool prinDerecha;
	Vec2 prinPos;

	//Sprite** matriz;

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

	//ordenar escena
	void ordenar(Sprite ***);
    
    // implement the "static create()" method manually
	CREATE_FUNC(PlataformasScene);
};

#endif
