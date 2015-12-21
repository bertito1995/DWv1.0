#include "PuzzleEscena.h"
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

	Size tamañoPantalla = Director::getInstance()->getVisibleSize();

	auto menuTitulo = MenuItemImage::create("imagenes/titulo.png",
		"imagenes/titulo.png");
	auto jugarBoton = MenuItemImage::create("imagenes/cuadrado.png",
		"imagenes/cuadrado.png",
		CC_CALLBACK_1(MenuEscena::jugar,
			this));

	auto menu = Menu::create(menuTitulo, jugarBoton, NULL);

	menu->alignItemsVerticallyWithPadding(tamañoPantalla.height / 32);
	addChild(menu, 1);

	return true;
}

void MenuEscena::jugar(Ref *pSender)
{
	auto scene = PuzzleEscena::createScene();


	Director::getInstance()->replaceScene(scene);

}

void MenuEscena::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}