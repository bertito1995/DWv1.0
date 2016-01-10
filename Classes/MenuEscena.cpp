#include "PuzzleEscena.h"
#include "ControlesEscena.h"
#include "cocos2d.h"
#include "MenuEscena.h"

USING_NS_CC;

Scene *MenuEscena::createScene()
{
	auto scene = Scene::create();
	auto layer = MenuEscena::create();
	scene->addChild(layer);
	return scene;
}

bool MenuEscena::init()

{

	Size tama�oPantalla = Director::getInstance()->getVisibleSize();

	Sprite *menuTitulo = Sprite::create("imagenes/titulo.png");
	menuTitulo->setPosition(Point((tama�oPantalla.width / 2), (3* tama�oPantalla.height / 4)));
	addChild(menuTitulo, 1);
		
	Sprite *jugarBoton = Sprite::create("imagenes/gui/jugar.png");
	jugarBoton->setPosition(Point((tama�oPantalla.width / 2), (tama�oPantalla.height / 2-100)));
	addChild(jugarBoton, 1);

	Sprite *controlesBoton = Sprite::create("imagenes/gui/controles.png");
	controlesBoton->setPosition(Point((tama�oPantalla.width / 2), (tama�oPantalla.height / 4)-100));
	addChild(controlesBoton, 1);

	Sprite *fondo = Sprite::create("imagenes/gui/fondo.png");
	fondo->setPosition(Point((tama�oPantalla.width / 2),(tama�oPantalla.height / 2)));
	addChild(fondo, 0);	auto event_listener = EventListenerTouchAllAtOnce::create();

	/*event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		float distancia;		distancia = jugarBoton->getPosition().getDistance(touch->getLocation());				if (distancia < 30) 		{			jugar();			return;		}		distancia = controlesBoton->getPosition().getDistance(touch->getLocation());		if (distancia < 30)		{			opciones();			return;		}	};*/	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		float distancia;		distancia = jugarBoton->getPosition().getDistance(touch->getLocation());		if (distancia < 30)		{						Sprite* aux = Sprite::create("imagenes/gui/jugarPulsado.png");			jugarBoton->setTexture(aux->getTexture());			return;		}		distancia = controlesBoton->getPosition().getDistance(touch->getLocation());		if (distancia < 30)		{			Sprite* aux = Sprite::create("imagenes/gui/controlesPulsado.png");			controlesBoton->setTexture(aux->getTexture());			return;		}	};	event_listener->onTouchesEnded = [=](const std::vector<Touch*>& pTouches, Event* event)
	{		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		float distancia;		distancia = jugarBoton->getPosition().getDistance(touch->getLocation());		if (distancia < 30)		{			Sprite* aux = Sprite::create("imagenes/gui/jugar.png");			jugarBoton->setTexture(aux->getTexture());			jugar();			return;		}		distancia = controlesBoton->getPosition().getDistance(touch->getLocation());		if (distancia < 30)		{			Sprite* aux = Sprite::create("imagenes/gui/controles.png");			controlesBoton->setTexture(aux->getTexture());			opciones();			return;		}	};	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event_listener, menuTitulo);
	return true;
}

void MenuEscena::jugar()
{
	auto scene = PuzzleEscena::createScene();

	Director::getInstance()->replaceScene(scene);

}

void MenuEscena::opciones()
{
	auto scene = ControlesEscena::createScene();

	Director::getInstance()->pushScene(scene);

}

void MenuEscena::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}