#include "ControlesEscena.h"
#include "cocos2d.h"
#include "MenuEscena.h"

USING_NS_CC;

Scene *ControlesEscena::createScene()
{
	auto scene = Scene::create();
	auto layer = ControlesEscena::create();
	scene->addChild(layer);
	return scene;
}

bool ControlesEscena::init()

{

	Size tamañoPantalla = Director::getInstance()->getVisibleSize();


	Sprite *resetBoton = Sprite::create("imagenes/gui/reset.png");
	resetBoton->setScaleX(tamañoPantalla.width / resetBoton->getContentSize().width * 0.1);
	resetBoton->setScaleY(tamañoPantalla.height / resetBoton->getContentSize().height * 0.1);
	resetBoton->setPosition(Point((tamañoPantalla.width - (resetBoton->getScaleX() * resetBoton->getContentSize().width / 2)), (resetBoton->getScaleY() * resetBoton->getContentSize().height) / 2));
	addChild(resetBoton, 1);

	Sprite *fondo = Sprite::create("imagenes/gui/controlesScene.png");
	fondo->setPosition(Point((tamañoPantalla.width / 2), (tamañoPantalla.height / 2)));
	addChild(fondo, 0);	auto event_listener = EventListenerTouchAllAtOnce::create();

	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		float distancia;		distancia = resetBoton->getPosition().getDistance(touch->getLocation());		if (distancia < 30)		{			Sprite* aux = Sprite::create("imagenes/gui/resetPulsado.png");			resetBoton->setTexture(aux->getTexture());			return;		}	};	event_listener->onTouchesEnded = [=](const std::vector<Touch*>& pTouches, Event* event)
	{		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		float distancia;		distancia = resetBoton->getPosition().getDistance(touch->getLocation());		if (distancia < 30)		{			menu();			return;		}	};	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event_listener, fondo);
	return true;
}

void ControlesEscena::menu()
{
	Director::getInstance()->popScene();
}


void ControlesEscena::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}