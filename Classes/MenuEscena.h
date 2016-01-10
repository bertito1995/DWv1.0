#ifndef __MENU_ESCENA_H__
#define __MENU_ESCENA_H__


#include "cocos2d.h"

#include "PuzzleEscena.h"
#include "ControlesEscena.h"

USING_NS_CC;
using namespace std;

class MenuEscena : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	
	void jugar();
	void opciones();

	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(MenuEscena);
};

#endif