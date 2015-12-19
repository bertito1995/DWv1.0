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
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();
	
	if ( !Layer::init() )
        return false;

	//plataformas

	/*Sprite * a = Sprite::create("provisional/princesa.png");
	a->setScaleY(0.03);
	a->setPosition(Point(tamañoPantalla.width / 2, 80));
	plataformas = Vector <Sprite*>();
	plataformas.pushBack(a);
	for (int i = 0; i < plataformas.size(); i++){
		addChild(plataformas.at(i),1);*
	}*/

	//princesa

	princesa = Sprite::create("imagenes/princesa/animacionCorrerR/1.png");
	Size img = princesa->getContentSize();
	princesa->setScaleX(tamañoPantalla.width / (6 * img.width)*0.35);
	princesa->setScaleY(tamañoPantalla.width / (4 * img.width)*0.22);
	//princesa->setPosition(Point(50, 250));
	princesa->setPosition(Point((tamañoPantalla.width / 6)  *   (0 + 0.5)+ (tamañoPantalla.width / 6) * -0.3, (tamañoPantalla.height / 4)  *  (0 + 0.5)+ (tamañoPantalla.width / 4) * 0.3));
	addChild(princesa, 3);

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



	//Creamos enemigo y su imagen, y los añadimos al vector
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

	//Añadimos los enemigos a la escena
	/*for (int i = 0; i < 2; i++)
		addChild(imagenEnemigos[i], 1);*/

	


	//Creamos casilla y su imagen, y los añadimos al vector
	//acordarse de eliminar el contenido del puntero *** delete(enemigoBasico)

	casillas = new Casilla*[24];
	//casillas = new Casilla*[1];
	

	//Modificamos la imagen
	listaPlatform = new Sprite*[21];
	numeroP = 21;

	listaEnem = new Enemigo*[7];
	numeroE = 7;

	listaObj = new Objeto*[13];
	numeroO = 13;


	for (int i = 0; i < 24; i++)
	{
		Casilla *cas = new Casilla(i+1);
		casillas[i] = cas;
		//Sprite *imagencas = Sprite::create(cas->imagenCasilla);

		float columnaImg = (tamañoPantalla.width / 6)  * ((float)(i - ((i / 6) * 6)) + 0.5);
		float filaImg = (tamañoPantalla.height / 4)  * ((float)(i / 6) + 0.5);


		//imagenCasillas[i]->setContentSize(Size(tamañoPantalla.width/6, tamañoPantalla.height/4));
		//Size img = cas->imagencas->getContentSize();
		/*imagenCasillas[i]->setScaleX(tamañoPantalla.width / (6 * img.width));
		imagenCasillas[i]->setScaleY(tamañoPantalla.height / (4 * img.height));*/
		cas->imagencas->setPosition(Point (columnaImg, filaImg) );
		//cas->imagencas->setPosition(Point((tamañoPantalla.width / 6)  *   (2 + 0.5), (tamañoPantalla.height / 4)  *  (1 + 0.5)));
		addChild(cas->imagencas, 0);


		//cas->setPosition(Point((tamañoPantalla.width / 6)  *   (2 + 0.5), (tamañoPantalla.height / 4)  *  (1 + 0.5)));
		//cas->listaObjetos[0]->imagenobj->setPosition(Point((tamañoPantalla.width / 6)  *   (2 + 0.5) + (cas->listaObjetos[0]->posX)*img.width, (tamañoPantalla.height / 4)  *  (1 + 0.5) + (cas->listaObjetos[0]->posY)*img.height));
		//cas->listaObjetos[0]->imagenobj->setPosition(Point((tamañoPantalla.width / 6)  * (2 + 0.5) + tamañoPantalla.width / 6 * cas->listaObjetos[0]->posX, (tamañoPantalla.height / 4)  *  (1 + 0.5) + tamañoPantalla.height / 4 * cas->listaObjetos[0]->posY));
		
		for (int j = 0; j < cas->numObj; j++)
		{
			cas->listaObjetos[j]->imagenobj->setPosition(Point(columnaImg + (tamañoPantalla.width / 6) * cas->listaObjetos[j]->posX, (filaImg + (tamañoPantalla.height / 4) * cas->listaObjetos[j]->posY)));

			addChild(cas->listaObjetos[j]->imagenobj, 1);
			contObj += 1;
			listaObj[contObj - 1] = cas->listaObjetos[j];

		}
		//addChild(casillas[i]->imagenObjetos[0]);
		for (int k = 0; k < cas->numEne; k++)
		{
			cas->listaEnemigos[k]->imagenEne->setPosition(Point(columnaImg + (tamañoPantalla.width / 6) * cas->listaEnemigos[k]->posX, (filaImg + (tamañoPantalla.height / 4) * cas->listaEnemigos[k]->posY)));

			addChild(cas->listaEnemigos[k]->imagenEne, 2);

			contEnem += 1;
			listaEnem[contEnem-1] = cas->listaEnemigos[k];
		}

		for (int l = 0; l < cas->numPla; l++)
		{
			cas->listaPlataformas[l]->imagenobj->setPosition(Point(columnaImg + (tamañoPantalla.width / 6) * cas->listaPlataformas[l]->posX, (filaImg + (tamañoPantalla.height / 4) * cas->listaPlataformas[l]->posY)));

			addChild(cas->listaPlataformas[l]->imagenobj, 1);

			contPlat += 1;
			listaPlatform[contPlat-1] = cas->listaPlataformas[l]->imagenobj;
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
	prinMovAbajo = false;
	prinMovArriba = false;
	prinEscaleras = false;
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
		if (prinDerecha)
		{
			princesa->setTexture(CCTextureCache::sharedTextureCache()->addImage("imagenes/princesa/animacionCorrerL/1.png"));
			prinDerecha = false;
		}
	}

	if (idTecla == EventKeyboard::KeyCode::KEY_RIGHT_ARROW){
		prinPosAnt.x = prinPos.x;
		prinPos.x += VELOCIDADPRIN;
		prinMovR = true;
		if (prinDerecha == false)
		{
			princesa->setTexture(CCTextureCache::sharedTextureCache()->addImage("imagenes/princesa/animacionCorrerR/1.png"));
			prinDerecha = true;
		}
	}
	if (idTecla == EventKeyboard::KeyCode::KEY_UP_ARROW && prinEscaleras == true) 
	{
		
		prinMovArriba = true;
	}

	if (idTecla == EventKeyboard::KeyCode::KEY_DOWN_ARROW && prinEscaleras == true)
	{
		prinPosAnt.y = prinPos.y;
		prinPos.y -= VELOCIDADPRIN;
		princesa->setPositionY(prinPos.y);
		prinMovAbajo = true;
	}

	if (idTecla == EventKeyboard::KeyCode::KEY_SPACE){
		if (prinSalto == false)
		{
			prinSalto = true;
			prinMovSalto = true;
			prinPosIniSalto = prinPos.y;
			tiempoSalto = 0;
		}
	}
}

//Evento de soltar una tecla

void PlataformasScene::teclaLevantada(EventKeyboard::KeyCode idTecla, Event *evento){
	if (idTecla == EventKeyboard::KeyCode::KEY_LEFT_ARROW) 
	{
		if (prinMovL)
		{
			prinMovL = false;
			princesa->setTexture(correrPrincesaL.at(0)->getTexture());
		}
	}
	if (idTecla == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		if (prinMovR)
		{
			prinMovR = false;
			princesa->setTexture(correrPrincesaR.at(0)->getTexture());
		}
	}
	if (idTecla == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		if (prinMovArriba)
		{
			prinMovArriba = false;
			
		}
	}
	if (idTecla == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		if (prinMovAbajo)
		{
			prinMovAbajo = false;
			
		}
	}
}

//Funcion que se repite

void PlataformasScene::update(float dt){
	
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();


	//movimiento en y princesa
	if (prinMovSalto)
	{
		tiempoSalto += dt;
		prinPosAnt.y = prinPos.y;
		prinPos.y = (FSALTOPRINCESA*tiempoSalto) - (0.5f * FGRAVEDAD*tiempoSalto*tiempoSalto) + prinPosIniSalto;
		princesa->setPositionY(prinPos.y);
		prinCae = false;
		prinSalto = true;
	}

	//Animacion princesa

	contadoCorrer += dt;

	if (contadoCorrer > FRCORRER && prinMovR && prinSalto == false)
	{
		princesa->setTexture(correrPrincesaR.at(indiceCorrer)->getTexture());
		contadoCorrer = 0;
		indiceCorrer++;
		if (indiceCorrer == FRAMESCORRER)
			indiceCorrer = 0;
	}
	if (contadoCorrer > FRCORRER && prinMovL && prinSalto == false)
	{
		princesa->setTexture(correrPrincesaL.at(indiceCorrer)->getTexture());
		contadoCorrer = 0;
		indiceCorrer++;
		if (indiceCorrer == FRAMESCORRER)
			indiceCorrer = 0;
	}
		
	//Movimiento enemigo

	
	for (int i = 0; i < numeroE; i++)
	{
		listaEnem[i]->mover(listaEnem[i]->imagenEne);

		if (listaEnem[i]->tipoMovimiento == "basico")
		{

			if (listaEnem[i]->faseMov == 1 && listaEnem[i]->imagenEne->getPositionX() >
				tamañoPantalla.width - listaEnem[i]->imagenEne->getContentSize().width / 2 * listaEnem[i]->imagenEne->getScaleX())
				listaEnem[i]->faseMov = 2;

			if (listaEnem[i]->faseMov == 2 && listaEnem[i]->imagenEne->getPositionX() <
				listaEnem[i]->imagenEne->getContentSize().width / 2 * listaEnem[i]->imagenEne->getScaleX())
				listaEnem[i]->faseMov = 1;
		}

		if (listaEnem[i]->tipoMovimiento == "vertical")
		{
			if (listaEnem[i]->imagenEne->getPositionX() + listaEnem[i]->imagenEne->getContentSize().width / 2 + 20 > prinPos.x &&
				listaEnem[i]->imagenEne->getPositionX() - listaEnem[i]->imagenEne->getContentSize().width / 2 - 20 < prinPos.x &&
				listaEnem[i]->faseMov == 1)
				listaEnem[i]->faseMov = 2;

			if (listaEnem[i]->imagenEne->getPositionY() <= 40 && listaEnem[i]->faseMov == 2)
				listaEnem[i]->faseMov = 3;
		}
	}
	
//<<<<<<< HEAD
	//Movimiento en X
	//if (prinMovL)
//=======

	//colision princesa/enemigos
	/*for (int i = 0; i < numeroE; i++)
	{
		if (colision(listaEnem[i]->imagenEne, princesa))
			reiniciarNivel(); 
	}*/

	//colision princesa/plataforma
	//for (int i = 0; i < numeroO; i++)
	//{
	if (colisionEscaleras(princesa))
	{
		prinEscaleras = true;
		prinCae = false;

	}

	//}
	else if (prinMovSalto == false)
	{
		prinEscaleras = false;
		prinCae = true;
	}

	if (prinMovArriba)
	{
		prinPosAnt.y = prinPos.y;
		prinPos.y += VELOCIDADPRIN;
		princesa->setPositionY(prinPos.y);

	}
	if (prinMovAbajo)
	{
		prinPosAnt.y = prinPos.y;
		prinPos.y -= VELOCIDADPRIN;
		princesa->setPositionY(prinPos.y);

	}
	for (int i = 0; i < numeroP; i++)
	{
		if (colisionPlataformas(princesa))
		{
			Sprite * aux = ColisionPlataformas(princesa);
			tiempoSalto = 0;
			if (prinPosAnt.y - (princesa->getContentSize().height / 2 * princesa->getScaleY()) >
				aux->getPositionY() + (aux->getContentSize().height / 2 * aux->getScaleY()))
			{
				prinPos.y = prinPosAnt.y;
				prinSalto = false;
				prinMovSalto = false;
				prinCae = true;
				//for (int j = 0; j < numeroO; j++)
				//{
				/*if (colisionEscaleras(princesa) == false)
				{
					prinMovArriba = false;
					prinMovAbajo = false;
				}*/
				//}
			}
			else
			{
				prinPos.x = prinPosAnt.x;
				prinPos.y = prinPosAnt.y;
				princesa->setPosition(Point(prinPosAnt.x, prinPosAnt.y));
				prinCae = true;
			}

		}
		else if (prinCae)
		{
			//Cae constante, mejor un contador propio
			prinPosAnt.y = prinPos.y;
			prinPos.y -= (0.5f * FGRAVEDAD*dt*dt*5);
			princesa->setPositionY(prinPos.y);
			prinSalto = true;
		
		}
	}

	//colision mascarprinvesa
	for (int i = 0; i < numeroO; i++)
	{
		if (listaObj[i]->tipoObjeto == "mascara" && colision(princesa, listaObj[i]->imagenobj))
		{
			princesa->setPosition(Point((tamañoPantalla.width / 6)  * (3 + 0.5) + tamañoPantalla.width / 6 * 0.2, (tamañoPantalla.height / 4)  *  (1 + 0.5) + tamañoPantalla.height / 4 * -0.3));
			//princesa->setPosition(Point(0, 300));
			prinPosAnt.x = princesa->getPositionX();
			prinPosAnt.y = princesa->getPositionY();

			prinPos.x= princesa->getPositionX();
			prinPos.y= princesa->getPositionY();
			prinCae = true;
		}
	}
	

	//Movimiento princesa en X
	if (prinMovL)
	{
		prinPosAnt.x = prinPos.x;
//>>>>>>> 67d8f5992ea5ba74dbc4eeca5d86741cea0b6144
		prinPos.x -= VELOCIDADPRIN;
	}
	if (prinMovR){
		prinPosAnt.x = prinPos.x;
		prinPos.x += VELOCIDADPRIN;
	}

	if (prinPos.x > princesa->getContentSize().width / 2 * princesa->getScaleX() 
		&& prinPos.x < tamañoPantalla.width - princesa->getContentSize().width / 2 * princesa->getScaleX())
		princesa->setPositionX(prinPos.x);
	else
		prinPos.x = princesa->getPositionX();
		
}

//Ordenamos la matriz

void PlataformasScene::ordenar(Sprite ***matriz)
{
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();
	float disx = tamañoPantalla.width / 6;
	float disy = tamañoPantalla.height / 4;

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
}bool PlataformasScene::colisionPlataformas(Sprite* a) {	
	for (int i = 0; i < numeroP; i++)
	{		if (colision(listaPlatform[i], a))			return true;	}	return false;}bool PlataformasScene::colisionEscaleras(Sprite* a){
	for (int i = 0; i < numeroO; i++)
	{		if (listaObj[i]->tipoObjeto == "escalada") 		{			if (colision(listaObj[i]->imagenobj, a))				return true;		}	}	return false;}Sprite* PlataformasScene::ColisionPlataformas(Sprite* a){
	for (int i = 0; i < numeroP; i++)
	{		if (colision(listaPlatform[i], a))			return listaPlatform[i];	}}void PlataformasScene::reiniciarNivel() {
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
