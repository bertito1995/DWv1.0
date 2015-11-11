#include "PlataformasScene.h"
#include "Enemigo.h"

USING_NS_CC;

Scene* PlataformasScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	auto layer = PlataformasScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}

bool PlataformasScene::init()
{
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();
	
	if ( !Layer::init() )
        return false;

	//Creamos la princesa

	princesa = Sprite::create("imagenes/princesa/1.png");
	princesa->setScaleX(0.07f);
	princesa->setScaleY(0.07f);
	princesa->setPosition(Point(tamañoPantalla.width / 2, 70));
	addChild(princesa, 1);

	prinDerecha = true;
	
	this->scheduleUpdate();

	//Asignamos fisicas a la princesa

	auto cuerpo = PhysicsBody::createCircle(princesa->getBoundingBox().size.width / 2);
	cuerpo->setContactTestBitmask(true);
	cuerpo->setDynamic(true);

	princesa->setPhysicsBody(cuerpo);

	//Creamos enemigo

	Enemigo *enemigoBasico = Enemigo::create();
	Sprite *imagenEn = Sprite::create("provisional/enemigo.png");
	enemigoBasico->imagen = imagenEn;
	//enemigoBasico->setImagen(imagenEn);
	//addChild(enemigoBasico->imagen, 1);
	
	enemigoBasico->setScaleX(0.15f);
	enemigoBasico->setScaleY(0.15f);
	enemigoBasico->setPosition(Point(enemigoBasico->getContentSize().width / 2 * enemigoBasico->getScaleX(), 40));
	enemigoBasico->tipo = "basico";

	addChild(enemigoBasico->imagen, 1);

	//Teclas

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(PlataformasScene::teclaPresionada, this);
	listener->onKeyReleased = CC_CALLBACK_2(PlataformasScene::teclaLevantada, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);	teclaPresioanda = EventKeyboard::KeyCode::KEY_NONE;
	prinMovL = false;
	prinMovR = false;
	prinSalto = false;
	prinPos.x = princesa->getPositionX();
	prinPos.y = princesa->getPositionY();


    return true;
}

//Evento de presionado de teclas

void PlataformasScene::teclaPresionada(EventKeyboard::KeyCode idTecla, Event *evento){

	if (idTecla == EventKeyboard::KeyCode::KEY_LEFT_ARROW){
		prinPos.x -= VELOCIDADPRIN;
		prinMovL = true;
		if (prinDerecha){
			princesa->setTexture(CCTextureCache::sharedTextureCache()->addImage("imagenes/princesa/2.png"));
			prinDerecha = false;
		}
	}

	if (idTecla == EventKeyboard::KeyCode::KEY_RIGHT_ARROW){
		prinPos.x += VELOCIDADPRIN;
		prinMovR = true;
		if (prinDerecha == false){
			princesa->setTexture(CCTextureCache::sharedTextureCache()->addImage("imagenes/princesa/1.png"));
			prinDerecha = true;
		}
	}

	if (idTecla == EventKeyboard::KeyCode::KEY_SPACE){
		if (prinSalto == false){
			auto cuerpo = PhysicsBody::createCircle(princesa->getBoundingBox().size.width / 2);
			cuerpo->applyImpulse(Vec2(0, FSALTOPRINCESA));
			princesa->setPhysicsBody(cuerpo);
			prinSalto = true;
		}
	}
}

//Evento de soltar una tecla

void PlataformasScene::teclaLevantada(EventKeyboard::KeyCode idTecla, Event *evento){
	if (idTecla == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		if (prinMovL)
			prinMovL = false;
	}
	if (idTecla == EventKeyboard::KeyCode::KEY_RIGHT_ARROW){
		if (prinMovR)
			prinMovR = false;
	}
}

//Funcion que se repite

void PlataformasScene::update(float dt){
	
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();

	auto cuerpo = PhysicsBody::createCircle(princesa->getBoundingBox().size.width / 2);

	//Movimiento enemigo

	//Movimiento en X
	if (prinMovL)
		prinPos.x -= VELOCIDADPRIN;
	if (prinMovR)
		prinPos.x += VELOCIDADPRIN;

	if (prinPos.x > princesa->getContentSize().width / 2 * princesa->getScaleX() 
		&& prinPos.x < tamañoPantalla.width - princesa->getContentSize().width / 2 * princesa->getScaleX())
		princesa->setPositionX(prinPos.x);
	else
		prinPos.x = princesa->getPositionX();
		
	//Plataforma princesa
	if (princesa->getPositionY() < 70){
		cuerpo->applyImpulse(Vec2(0, FFLOTAR));
		princesa->setPhysicsBody(cuerpo);
		prinSalto = false;	
	}
}

//Asignamos fisica a la escena

void PlataformasScene::setPhysicsWorld(PhysicsWorld *mundo) {
	fMundo = mundo;
	fMundo->setGravity(Vec2(0, FGRAVEDAD));
}

void PlataformasScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
