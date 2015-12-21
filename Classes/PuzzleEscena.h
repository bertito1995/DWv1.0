#ifndef __PUZZLE_ESCENA_H__
#define __PUZZLE_ESCENA_H__


#include "Nivel.h"
#include "Casilla.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "PlataformasScene.h"

USING_NS_CC;
using namespace std;



const float ANCHOINI = 1024/ 9;
const float ALTOINI = 768/ 7;

const float ANCHOVEC = 1024 / 17;
const float ALTOVEC = 768 / 12;

class PuzzleEscena : public cocos2d::Layer
{

public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	
	Nivel *uno;

	int casillaSeleccionada;
	bool banco;

	void cambio(Ref *pSender);
	void colocar();
	bool quedan(Casilla **, int );
	
	Sprite *coloca;
	Sprite *cambia;

	bool ayuda;

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(PuzzleEscena);
};
#endif
