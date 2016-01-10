#ifndef __CONTROLES_ESCENA_H__
#define __CONTROLES_ESCENA_H__


#include "cocos2d.h"
#include "MenuEscena.h"

USING_NS_CC;
using namespace std;

class ControlesEscena : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);

	void menu();

	CREATE_FUNC(ControlesEscena);
};

#endif