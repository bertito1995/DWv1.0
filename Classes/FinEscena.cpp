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

	Size tama�oPantalla = Director::getInstance()->getVisibleSize();


	Sprite *volver = Sprite::create("imagenes/gui/volver.png");
	//resetBoton->setScaleX(tama�oPantalla.width / resetBoton->getContentSize().width * 0.1);
	//resetBoton->setScaleY(tama�oPantalla.height / resetBoton->getContentSize().height * 0.1);
	volver->setPosition(Point((volver->getScaleX() * volver->getContentSize().width / 2), (volver->getScaleY() * volver->getContentSize().height) / 2));
	addChild(volver, 1);

	Sprite *fondo = Sprite::create("imagenes/gui/fin.png");
	fondo->setPosition(Point((tama�oPantalla.width / 2), (tama�oPantalla.height / 2)));
	addChild(fondo, 0);

	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		float distancia;
	{
		auto openGl_location = touch->getLocation();

		float distancia;
	return true;
}

void FinEscena::menu()
{
	Director::getInstance()->popToRootScene();
	
}


void FinEscena::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}