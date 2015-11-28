#include "PlataformasScene.h"
#include "Enemigo.h"
#include "Casilla.h"
#include "Objeto.h"

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
	Size tamaņoPantalla = Director::getInstance()->getVisibleSize();
	
	if ( !Layer::init() )
        return false;

	correrPrincesaR = Vector <Sprite*>();
	correrPrincesaL = Vector <Sprite*>();
	for (int i = 0; i < FRAMESCORRER; i++){
		string texto = "imagenes/princesa/animacionCorrerR/";
		texto += to_string(i+1);
		texto = texto + ".png";
		Sprite *aux = Sprite::create(texto);
		aux->setScaleX(0.07f);
		aux->setScaleY(0.07f);
		correrPrincesaR.pushBack(aux);
		
		string texto2 = "imagenes/princesa/animacionCorrerL/";
		texto2 += to_string(i + 1);
		texto2 = texto2 + ".png";
		Sprite *aux2 = Sprite::create(texto2);
		aux2->setScaleX(0.07f);
		aux2->setScaleY(0.07f);
		correrPrincesaL.pushBack(aux2);
	}

	//Creamos la princesa

	princesa = Sprite::create("imagenes/princesa/animacionCorrerR/1.png");
	princesa->setScaleX(0.07f);
	princesa->setScaleY(0.07f);
	princesa->setPosition(Point(tamaņoPantalla.width / 2, 70));
	addChild(princesa, 1);

	prinDerecha = true;
	
	this->scheduleUpdate();

	//Asignamos fisicas a la princesa

	auto cuerpo = PhysicsBody::createCircle(princesa->getBoundingBox().size.width / 2);
	cuerpo->setContactTestBitmask(true);
	cuerpo->setDynamic(true);

	princesa->setPhysicsBody(cuerpo);

	//Creamos enemigo y su imagen, y los aņadimos al vector
	//acordarse de eliminar el contenido del puntero *** delete(enemigoBasico)

	//imagenEnemigos = new Sprite*[2];
	/*enemigos = new Enemigo*[2];
	

	Enemigo *enemigoBasico = new Enemigo(1);
	enemigos[0] = enemigoBasico;
	Enemigo *enemigoVertical = new Enemigo(2);
	enemigos[1] = enemigoVertical;*/
	
	/*Sprite *imagenEn = Sprite::create(enemigoBasico->imagen);
	imagenEnemigos[0] = imagenEn;
	Sprite *imagenEnVertical = Sprite::create(enemigoVertical->imagen);
	imagenEnemigos[1] = imagenEnVertical;*/

	//Modificamos la imagen

	/*for (int i = 0; i < 2; i++)
	{
		imagenEnemigos[i]->setScaleX(0.15f);
		imagenEnemigos[i]->setScaleY(0.15f);
	}
	imagenEnemigos[0]->setPosition(Point(imagenEnemigos[0]->getContentSize().width / 2 * imagenEnemigos[0]->getScaleX(), 40));
	imagenEnemigos[1]->setPosition(Point(imagenEnemigos[1]->getContentSize().width / 2 * imagenEnemigos[1]->getScaleX() + 500, 250));*/

	//Aņadimos los enemigos a la escena
	/*for (int i = 0; i < 2; i++)
		addChild(imagenEnemigos[i], 1);*/

	


	//Creamos casilla y su imagen, y los aņadimos al vector
	//acordarse de eliminar el contenido del puntero *** delete(enemigoBasico)

	casillas = new Casilla*[24];
	//casillas = new Casilla*[1];
	

	//Modificamos la imagen

	for (int i = 0; i < 24; i++)
	{
		Casilla *cas = new Casilla(i+1);
		casillas[i] = cas;
		//Sprite *imagencas = Sprite::create(cas->imagenCasilla);

		float columnaImg = (tamaņoPantalla.width / 6)  * ((float)(i - ((i / 6) * 6)) + 0.5);
		float filaImg = (tamaņoPantalla.height / 4)  * ((float)(i / 6) + 0.5);


		//imagenCasillas[i]->setContentSize(Size(tamaņoPantalla.width/6, tamaņoPantalla.height/4));
		//Size img = cas->imagencas->getContentSize();
		/*imagenCasillas[i]->setScaleX(tamaņoPantalla.width / (6 * img.width));
		imagenCasillas[i]->setScaleY(tamaņoPantalla.height / (4 * img.height));*/
		cas->imagencas->setPosition(Point (columnaImg, filaImg) );
		//cas->imagencas->setPosition(Point((tamaņoPantalla.width / 6)  *   (2 + 0.5), (tamaņoPantalla.height / 4)  *  (1 + 0.5)));
		addChild(cas->imagencas, 0);


		//cas->setPosition(Point((tamaņoPantalla.width / 6)  *   (2 + 0.5), (tamaņoPantalla.height / 4)  *  (1 + 0.5)));
		//cas->listaObjetos[0]->imagenobj->setPosition(Point((tamaņoPantalla.width / 6)  *   (2 + 0.5) + (cas->listaObjetos[0]->posX)*img.width, (tamaņoPantalla.height / 4)  *  (1 + 0.5) + (cas->listaObjetos[0]->posY)*img.height));
		//cas->listaObjetos[0]->imagenobj->setPosition(Point((tamaņoPantalla.width / 6)  * (2 + 0.5) + tamaņoPantalla.width / 6 * cas->listaObjetos[0]->posX, (tamaņoPantalla.height / 4)  *  (1 + 0.5) + tamaņoPantalla.height / 4 * cas->listaObjetos[0]->posY));
		
		for (int j = 0; j < cas->numObj; j++)
		{
			cas->listaObjetos[j]->imagenobj->setPosition(Point(columnaImg + (tamaņoPantalla.width / 6) * cas->listaObjetos[j]->posX, (filaImg + (tamaņoPantalla.height / 4) * cas->listaObjetos[j]->posY)));

			addChild(cas->listaObjetos[j]->imagenobj, 1);
		}
		//addChild(casillas[i]->imagenObjetos[0]);
		for (int k = 0; k < cas->numEne; k++)
		{
			cas->listaEnemigos[k]->imagenEne->setPosition(Point(columnaImg + (tamaņoPantalla.width / 6) * cas->listaEnemigos[k]->posX, (filaImg + (tamaņoPantalla.height / 4) * cas->listaEnemigos[k]->posY)));

			addChild(cas->listaEnemigos[k]->imagenEne, 1);
		}
	}
	

	
	

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

	//imagen fondo

	/*matriz = new (Sprite**)[4];

	for (int i = 0; i < 4; i++)
	{
		matriz[i] = new (Sprite*)[6];
		for (int j = 0; j < 6; j++)
			matriz[i][j] = Sprite::create("imagenes/princesa/1.png");
	}


	matriz[0][0] = Sprite::create("provisional/fondo/0,0.png");
	matriz[0][1] = Sprite::create("provisional/fondo/0,1.png");
	matriz[0][2] = Sprite::create("provisional/fondo/0,2.png");
	matriz[0][3] = Sprite::create("provisional / fondo/ 0,3.png");
	matriz[0][4] = Sprite::create("provisional / fondo/ 0,4.png");
	matriz[0][5] = Sprite::create("provisional / fondo/ 0,5.png");
	matriz[1][0] = Sprite::create("provisional / fondo/ 1,0.png");
	matriz[1][1] = Sprite::create("provisional / fondo/ 1,1.png");
	matriz[1][2] = Sprite::create("provisional / fondo/ 1,2.png");
	matriz[1][3] = Sprite::create("provisional / fondo/ 1,3.png");
	matriz[1][4] = Sprite::create("provisional / fondo/ 1,4.png");
	matriz[1][5] = Sprite::create("provisional / fondo/ 1,5.png");
	matriz[2][0] = Sprite::create("provisional / fondo/ 2,0.png");
	matriz[2][1] = Sprite::create("provisional / fondo/ 2,1.png");
	matriz[2][2] = Sprite::create("provisional / fondo/ 2,2.png");
	matriz[2][3] = Sprite::create("provisional / fondo/ 2,3.png");
	matriz[2][4] = Sprite::create("provisional / fondo/ 2,4.png");
	matriz[2][5] = Sprite::create("provisional / fondo/ 2,5.png");
	matriz[3][0] = Sprite::create("provisional / fondo/ 3,0.png");
	matriz[3][1] = Sprite::create("provisional / fondo/ 3,1.png");
	matriz[3][2] = Sprite::create("provisional / fondo/ 3,2.png");
	matriz[3][3] = Sprite::create("provisional / fondo/ 3,3.png");
	matriz[3][4] = Sprite::create("provisional / fondo/ 3,4.png");
	matriz[3][5] = Sprite::create("provisional / fondo/ 3,5.png");

	//ordenar(matriz);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
			addChild(matriz[i][j], 0);
	}*/

    return true;
}

//Evento de presionado de teclas

void PlataformasScene::teclaPresionada(EventKeyboard::KeyCode idTecla, Event *evento){

	if (idTecla == EventKeyboard::KeyCode::KEY_LEFT_ARROW){
		prinPos.x -= VELOCIDADPRIN;
		prinMovL = true;
		if (prinDerecha){
			princesa->setTexture(CCTextureCache::sharedTextureCache()->addImage("imagenes/princesa/animacionCorrerL/1.png"));
			prinDerecha = false;
		}
	}

	if (idTecla == EventKeyboard::KeyCode::KEY_RIGHT_ARROW){
		prinPos.x += VELOCIDADPRIN;
		prinMovR = true;
		if (prinDerecha == false){
			princesa->setTexture(CCTextureCache::sharedTextureCache()->addImage("imagenes/princesa/animacionCorrerR/1.png"));
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
		if (prinMovL){
			prinMovL = false;
			princesa->setTexture(correrPrincesaL.at(0)->getTexture());
		}
	}
	if (idTecla == EventKeyboard::KeyCode::KEY_RIGHT_ARROW){
		if (prinMovR){
			prinMovR = false;
			princesa->setTexture(correrPrincesaR.at(0)->getTexture());
		}
	}
}

//Funcion que se repite

void PlataformasScene::update(float dt){
	
	Size tamaņoPantalla = Director::getInstance()->getVisibleSize();

	auto cuerpo = PhysicsBody::createCircle(princesa->getBoundingBox().size.width / 2);

	contadoCorrer += dt;

	//Animacion princesa
	if (contadoCorrer > FRCORRER && prinMovR){
		princesa->setTexture(correrPrincesaR.at(indiceCorrer)->getTexture());
		contadoCorrer = 0;
		indiceCorrer++;
		if (indiceCorrer == FRAMESCORRER)
			indiceCorrer = 0;
	}
	if (contadoCorrer > FRCORRER && prinMovL){
		princesa->setTexture(correrPrincesaL.at(indiceCorrer)->getTexture());
		contadoCorrer = 0;
		indiceCorrer++;
		if (indiceCorrer == FRAMESCORRER)
			indiceCorrer = 0;
	}
	/*if (prinMovL == false){
		indiceCorrer = 0;
		princesa->setTexture(correrPrincesaR.at(indiceCorrer)->getTexture());
	}
	if (prinMovR == false){
		indiceCorrer = 0;
		princesa->setTexture(correrPrincesaL.at(indiceCorrer)->getTexture());
	}*/
		

	//Movimiento enemigo
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < casillas[i]->numEne; j++)
		{
			casillas[i]->listaEnemigos[j]->mover(casillas[i]->listaEnemigos[j]->imagenEne);

			if (casillas[i]->listaEnemigos[j]->tipoMovimiento == "basico")
			{

				if (casillas[i]->listaEnemigos[j]->faseMov == 1 && casillas[i]->listaEnemigos[j]->imagenEne->getPositionX() >
					tamaņoPantalla.width - casillas[i]->listaEnemigos[j]->imagenEne->getContentSize().width / 2 * casillas[i]->listaEnemigos[j]->imagenEne->getScaleX())
					casillas[i]->listaEnemigos[j]->faseMov = 2;

				if (casillas[i]->listaEnemigos[j]->faseMov == 2 && casillas[i]->listaEnemigos[j]->imagenEne->getPositionX() <
					casillas[i]->listaEnemigos[j]->imagenEne->getContentSize().width / 2 * casillas[i]->listaEnemigos[j]->imagenEne->getScaleX())
					casillas[i]->listaEnemigos[j]->faseMov = 1;
			}

			if (casillas[i]->listaEnemigos[j]->tipoMovimiento == "vertical")
			{
				if (casillas[i]->listaEnemigos[j]->imagenEne->getPositionX() + casillas[i]->listaEnemigos[j]->imagenEne->getContentSize().width / 2 + 20 > prinPos.x &&
					casillas[i]->listaEnemigos[j]->imagenEne->getPositionX() - casillas[i]->listaEnemigos[j]->imagenEne->getContentSize().width / 2 - 20 < prinPos.x &&
					casillas[i]->listaEnemigos[j]->faseMov == 1)
					casillas[i]->listaEnemigos[j]->faseMov = 2;

				if (casillas[i]->listaEnemigos[j]->imagenEne->getPositionY() <= 40 && casillas[i]->listaEnemigos[j]->faseMov == 2)
					casillas[i]->listaEnemigos[j]->faseMov = 3;
			}
		}
	}
	//Movimiento en X
	if (prinMovL)
		prinPos.x -= VELOCIDADPRIN;
	if (prinMovR)
		prinPos.x += VELOCIDADPRIN;

	if (prinPos.x > princesa->getContentSize().width / 2 * princesa->getScaleX() 
		&& prinPos.x < tamaņoPantalla.width - princesa->getContentSize().width / 2 * princesa->getScaleX())
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

//Ordenamos la matriz

void PlataformasScene::ordenar(Sprite ***matriz)
{
	Size tamaņoPantalla = Director::getInstance()->getVisibleSize();
	float disx = tamaņoPantalla.width / 6;
	float disy = tamaņoPantalla.height / 4;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			matriz[i][j]->setPositionX(disx * (5 - j));
			matriz[i][j]->setPositionY(disy * (5 - i));
		}
	}
}

void PlataformasScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
