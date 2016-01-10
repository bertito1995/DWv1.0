#include "FinEscena.h"
#include "cocos2d.h"

USING_NS_CC;

Scene *FinEscena::createScene()
{
	auto scene = Scene::create();
	auto layer = FinEscena::create();
	scene->addChild(layer);
	return scene;
}

bool FinEscena::init()

{

	Size tamañoPantalla = Director::getInstance()->getVisibleSize();


	Sprite *volver = Sprite::create("imagenes/gui/volver.png");
	//resetBoton->setScaleX(tamañoPantalla.width / resetBoton->getContentSize().width * 0.1);
	//resetBoton->setScaleY(tamañoPantalla.height / resetBoton->getContentSize().height * 0.1);
	volver->setPosition(Point((volver->getScaleX() * volver->getContentSize().width / 2), (volver->getScaleY() * volver->getContentSize().height) / 2));
	addChild(volver, 1);

	Sprite *fondo = Sprite::create("imagenes/gui/fin.png");
	fondo->setPosition(Point((tamañoPantalla.width / 2), (tamañoPantalla.height / 2)));
	addChild(fondo, 0);	auto event_listener = EventListenerTouchAllAtOnce::create();

	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		float distancia;		distancia = volver->getPosition().getDistance(touch->getLocation());		if (distancia < 30)		{			Sprite* aux = Sprite::create("imagenes/gui/volverPulsado.png");			volver->setTexture(aux->getTexture());			return;		}	};	event_listener->onTouchesEnded = [=](const std::vector<Touch*>& pTouches, Event* event)
	{		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		float distancia;		distancia = volver->getPosition().getDistance(touch->getLocation());		if (distancia < 30)		{			menu();			return;		}	};	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event_listener, fondo);
	return true;
}

void FinEscena::menu()
{
	Director::getInstance()->popScene();
	Director::getInstance()->popScene();
}


void FinEscena::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}