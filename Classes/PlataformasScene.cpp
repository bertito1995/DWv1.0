#include "PlataformasScene.h"
#include "Enemigo.h"
#include "Casilla.h"
#include "Objeto.h"

USING_NS_CC;

Scene* PlataformasScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PlataformasScene::create();
    scene->addChild(layer);
    return scene;
}

bool PlataformasScene::init()
{
	Size tama�oPantalla = Director::getInstance()->getVisibleSize();
	
	if ( !Layer::init() )
        return false;

	//plataformas

	Sprite * a = Sprite::create("provisional/princesa.png");
	a->setScaleY(0.03);
	a->setPosition(Point(tama�oPantalla.width / 2, 80));
	plataformas = Vector <Sprite*>();
	plataformas.pushBack(a);
	for (int i = 0; i < plataformas.size(); i++){
		addChild(plataformas.at(i),1);
	}

	//princesa

	princesa = Sprite::create("imagenes/princesa/animacionCorrerR/1.png");
	princesa->setScaleX(0.07f);
	princesa->setScaleY(0.07f);
	princesa->setPosition(Point(tama�oPantalla.width / 2, 280));
	addChild(princesa, 1);

	prinDerecha = true;

	this->scheduleUpdate();
	
	//imagenes correr princesa

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



	//Creamos enemigo y su imagen, y los a�adimos al vector
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
<<<<<<< HEAD
	imagenEnemigos[0]->setPosition(Point(imagenEnemigos[0]->getContentSize().width / 2 * imagenEnemigos[0]->getScaleX(), 40));
	imagenEnemigos[1]->setPosition(Point(imagenEnemigos[1]->getContentSize().width / 2 * imagenEnemigos[1]->getScaleX() + 500, 250));*/
/*=======
	imagenEnemigos[0]->setPosition(Point(imagenEnemigos[0]->getContentSize().width / 2 * imagenEnemigos[0]->getScaleX(), 25));
	imagenEnemigos[1]->setPosition(Point(imagenEnemigos[1]->getContentSize().width / 2 * imagenEnemigos[1]->getScaleX() + 500, 250));
>>>>>>> 67d8f5992ea5ba74dbc4eeca5d86741cea0b6144*/

	//A�adimos los enemigos a la escena
	/*for (int i = 0; i < 2; i++)
		addChild(imagenEnemigos[i], 1);*/

	


	//Creamos casilla y su imagen, y los a�adimos al vector
	//acordarse de eliminar el contenido del puntero *** delete(enemigoBasico)

	casillas = new Casilla*[24];
	//casillas = new Casilla*[1];
	

	//Modificamos la imagen

	for (int i = 0; i < 24; i++)
	{
		Casilla *cas = new Casilla(i+1);
		casillas[i] = cas;
		//Sprite *imagencas = Sprite::create(cas->imagenCasilla);

		float columnaImg = (tama�oPantalla.width / 6)  * ((float)(i - ((i / 6) * 6)) + 0.5);
		float filaImg = (tama�oPantalla.height / 4)  * ((float)(i / 6) + 0.5);


		//imagenCasillas[i]->setContentSize(Size(tama�oPantalla.width/6, tama�oPantalla.height/4));
		//Size img = cas->imagencas->getContentSize();
		/*imagenCasillas[i]->setScaleX(tama�oPantalla.width / (6 * img.width));
		imagenCasillas[i]->setScaleY(tama�oPantalla.height / (4 * img.height));*/
		cas->imagencas->setPosition(Point (columnaImg, filaImg) );
		//cas->imagencas->setPosition(Point((tama�oPantalla.width / 6)  *   (2 + 0.5), (tama�oPantalla.height / 4)  *  (1 + 0.5)));
		addChild(cas->imagencas, 0);


		//cas->setPosition(Point((tama�oPantalla.width / 6)  *   (2 + 0.5), (tama�oPantalla.height / 4)  *  (1 + 0.5)));
		//cas->listaObjetos[0]->imagenobj->setPosition(Point((tama�oPantalla.width / 6)  *   (2 + 0.5) + (cas->listaObjetos[0]->posX)*img.width, (tama�oPantalla.height / 4)  *  (1 + 0.5) + (cas->listaObjetos[0]->posY)*img.height));
		//cas->listaObjetos[0]->imagenobj->setPosition(Point((tama�oPantalla.width / 6)  * (2 + 0.5) + tama�oPantalla.width / 6 * cas->listaObjetos[0]->posX, (tama�oPantalla.height / 4)  *  (1 + 0.5) + tama�oPantalla.height / 4 * cas->listaObjetos[0]->posY));
		
		for (int j = 0; j < cas->numObj; j++)
		{
			cas->listaObjetos[j]->imagenobj->setPosition(Point(columnaImg + (tama�oPantalla.width / 6) * cas->listaObjetos[j]->posX, (filaImg + (tama�oPantalla.height / 4) * cas->listaObjetos[j]->posY)));

			addChild(cas->listaObjetos[j]->imagenobj, 1);
		}
		//addChild(casillas[i]->imagenObjetos[0]);
		for (int k = 0; k < cas->numEne; k++)
		{
			cas->listaEnemigos[k]->imagenEne->setPosition(Point(columnaImg + (tama�oPantalla.width / 6) * cas->listaEnemigos[k]->posX, (filaImg + (tama�oPantalla.height / 4) * cas->listaEnemigos[k]->posY)));

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
	prinCae = true;
	prinMovSalto = false;
	prinPos.x = princesa->getPositionX();
	prinPos.y = princesa->getPositionY();
	prinPosAnt.x = princesa->getPositionX();
	prinPosAnt.y = princesa->getPositionY();


    return true;
}

//Evento de presionado de teclas

void PlataformasScene::teclaPresionada(EventKeyboard::KeyCode idTecla, Event *evento){

	if (idTecla == EventKeyboard::KeyCode::KEY_LEFT_ARROW){
		prinPosAnt.x = prinPos.x;
		prinPos.x -= VELOCIDADPRIN;
		prinMovL = true;
		if (prinDerecha){
			princesa->setTexture(CCTextureCache::sharedTextureCache()->addImage("imagenes/princesa/animacionCorrerL/1.png"));
			prinDerecha = false;
		}
	}

	if (idTecla == EventKeyboard::KeyCode::KEY_RIGHT_ARROW){
		prinPosAnt.x = prinPos.x;
		prinPos.x += VELOCIDADPRIN;
		prinMovR = true;
		if (prinDerecha == false){
			princesa->setTexture(CCTextureCache::sharedTextureCache()->addImage("imagenes/princesa/animacionCorrerR/1.png"));
			prinDerecha = true;
		}
	}

	if (idTecla == EventKeyboard::KeyCode::KEY_SPACE){
		if (prinSalto == false){
			prinSalto = true;
			prinMovSalto = true;
			prinPosIniSalto = prinPos.y;
			tiempoSalto = 0;
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
	
	Size tama�oPantalla = Director::getInstance()->getVisibleSize();


	//movimiento en y princesa
	if (prinMovSalto){
		tiempoSalto += dt;
		prinPosAnt.y = prinPos.y;
		prinPos.y = (FSALTOPRINCESA*tiempoSalto) - (0.5f * FGRAVEDAD*tiempoSalto*tiempoSalto) + prinPosIniSalto;
		princesa->setPositionY(prinPos.y);
		prinCae = false;
		prinSalto = true;
	}

	//Animacion princesa

	contadoCorrer += dt;

	if (contadoCorrer > FRCORRER && prinMovR && prinSalto == false){
		princesa->setTexture(correrPrincesaR.at(indiceCorrer)->getTexture());
		contadoCorrer = 0;
		indiceCorrer++;
		if (indiceCorrer == FRAMESCORRER)
			indiceCorrer = 0;
	}
	if (contadoCorrer > FRCORRER && prinMovL && prinSalto == false){
		princesa->setTexture(correrPrincesaL.at(indiceCorrer)->getTexture());
		contadoCorrer = 0;
		indiceCorrer++;
		if (indiceCorrer == FRAMESCORRER)
			indiceCorrer = 0;
	}
		
	//Movimiento enemigo

	for (int i = 0; i < 24; i++)

	{
		for (int j = 0; j < casillas[i]->numEne; j++)
		{
			casillas[i]->listaEnemigos[j]->mover(casillas[i]->listaEnemigos[j]->imagenEne);

			if (casillas[i]->listaEnemigos[j]->tipoMovimiento == "basico")
			{

				if (casillas[i]->listaEnemigos[j]->faseMov == 1 && casillas[i]->listaEnemigos[j]->imagenEne->getPositionX() >
					tama�oPantalla.width - casillas[i]->listaEnemigos[j]->imagenEne->getContentSize().width / 2 * casillas[i]->listaEnemigos[j]->imagenEne->getScaleX())
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
//<<<<<<< HEAD
	//Movimiento en X
	//if (prinMovL)
//=======

	//colision princesa/enemigos
	/*for (int i = 0; i < 2; i++)
		if (colision(imagenEnemigos[i], princesa))
			reiniciarNivel(this);*/

	//colision princesa/plataforma
	for (int i = 0; i < plataformas.size(); i++)
	{
		if (colisionPlataformas(princesa))
		{
			tiempoSalto = 0;
			if (prinPosAnt.y - (princesa->getContentSize().height/2 * princesa->getScaleY()) > 
				plataformas.at(i)->getPositionY() + (plataformas.at(i)->getContentSize().height/2 * plataformas.at(i)->getScaleY())){
				prinPos.y = prinPosAnt.y;
				prinSalto = false;
				prinMovSalto = false;
				prinCae = true;
			}
			else
			{
				prinPos.x = prinPosAnt.x;
				prinPos.y = prinPosAnt.y;
				princesa->setPosition(Point(prinPosAnt.x, prinPosAnt.y));
				prinMovL = false;
				prinMovR = false;
			}

		}
		else if (prinCae)
		{
			//Cae constante, mejor un contador propio
			prinPosAnt.y = prinPos.y;
			prinPos.y -= (0.5f * FGRAVEDAD*dt*dt*50);
			princesa->setPositionY(prinPos.y);
			prinSalto = true;
		}
	}

	//Movimiento princesa en X
	if (prinMovL){
		prinPosAnt.x = prinPos.x;
//>>>>>>> 67d8f5992ea5ba74dbc4eeca5d86741cea0b6144
		prinPos.x -= VELOCIDADPRIN;
	}
	if (prinMovR){
		prinPosAnt.x = prinPos.x;
		prinPos.x += VELOCIDADPRIN;
	}

	if (prinPos.x > princesa->getContentSize().width / 2 * princesa->getScaleX() 
		&& prinPos.x < tama�oPantalla.width - princesa->getContentSize().width / 2 * princesa->getScaleX())
		princesa->setPositionX(prinPos.x);
	else
		prinPos.x = princesa->getPositionX();
		
}

//Ordenamos la matriz

void PlataformasScene::ordenar(Sprite ***matriz)
{
	Size tama�oPantalla = Director::getInstance()->getVisibleSize();
	float disx = tama�oPantalla.width / 6;
	float disy = tama�oPantalla.height / 4;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			matriz[i][j]->setPositionX(disx * (5 - j));
			matriz[i][j]->setPositionY(disy * (5 - i));
		}
	}
}
//Colision

bool PlataformasScene::colision(Sprite* a, Sprite* b) {
	if (a->getPositionX() + ((a->getContentSize().width / 2) * a->getScaleX()) <
		b->getPositionX() - ((b->getContentSize().width / 2) * b->getScaleX()) ||
		a->getPositionX() - ((a->getContentSize().width / 2) * a->getScaleX()) >
		b->getPositionX() + ((b->getContentSize().width / 2) * b->getScaleX()) ||
		a->getPositionY() + ((a->getContentSize().height / 2) * a->getScaleY()) <
		b->getPositionY() - ((b->getContentSize().height / 2) * b->getScaleY()) ||
		a->getPositionY() - ((a->getContentSize().height / 2) * a->getScaleY()) >
		b->getPositionY() + ((b->getContentSize().height / 2) * b->getScaleY()))
		return false;
	return true;
}bool PlataformasScene::colisionPlataformas(Sprite* a) {	for (int i = 0; i < plataformas.size(); i++){		if (colision(plataformas.at(i), a))			return true;	}	return false;}void PlataformasScene::reiniciarNivel(Ref *pSender) {
	auto scene = PlataformasScene::createScene();

	//Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

void PlataformasScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
