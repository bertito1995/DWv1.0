#include "PlataformasScene.h"
#include "Enemigo.h"
#include "Casilla.h"
#include "Objeto.h"
#include "PuzzleEscena.h"
#include "FinEscena.h"
#include "cocos2d.h"

USING_NS_CC;

int *n;

Scene* PlataformasScene::createScene(int *a)
{
	n = a;
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

	//princesa

	princesa = Sprite::create("imagenes/princesa/animacionCorrerR/1.png");
	Size img = princesa->getContentSize();
	princesa->setScaleX(tamañoPantalla.width / (6 * img.width)*0.22);
	princesa->setScaleY(tamañoPantalla.width / (4 * img.width)*0.12);
	//princesa->setPosition(Point(50, 250))
	princesa->setPosition(Point((tamañoPantalla.width / 6)  *   (0 + 0.5)+ (tamañoPantalla.width / 6) * -0.3, (tamañoPantalla.height / 4)  *  (0 + 0.5)+ (tamañoPantalla.width / 4) * 0.15));
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
	//imagenes escalar princesa

	escalarPrincesaR = Vector <Sprite*>();
	escalarPrincesaL = Vector <Sprite*>();
	for (int i = 0; i < FRAMESESCALAR; i++) {
		string texto = "imagenes/escalar/escalarR/trepar ";
		texto += to_string(i + 1);
		texto = texto + ".png";
		Sprite *aux = Sprite::create(texto);
		aux->setScaleX(0.07f * 805/762);
		aux->setScaleY(0.07f * 1601/1726);
		escalarPrincesaR.pushBack(aux);

		string texto2 = "imagenes/escalar/escalarL/";
		texto2 += to_string(i + 1);
		texto2 = texto2 + ".png";
		Sprite *aux2 = Sprite::create(texto2);
		aux2->setScaleX(0.07f * 805 / 762);
		aux2->setScaleY(0.07f * 1601 / 1726);
		escalarPrincesaL.pushBack(aux2);
	}

	//animacion moneda

	animacionMoneda = Vector <Sprite*>();
	for (int i = 0; i < FRAMESMONEDA; i++)
	{
		if (i + 3 >= 10)
		{
			string texto = "imagenes/moneda/animacion moneda__0";
			texto += to_string(i + 3);
			texto = texto + ".png";
			Sprite *aux = Sprite::create(texto);
			animacionMoneda.pushBack(aux);
		}
		else
		{
			string texto = "imagenes/moneda/animacion moneda__00";
			texto += to_string(i + 3);
			texto = texto + ".png";
			Sprite *aux = Sprite::create(texto);
			animacionMoneda.pushBack(aux);
		}
	}

	//animacion fantasma

	animacionFantasma = Vector <Sprite*>();
	for (int i = 0; i < FRAMESFANTASMA; i++)
	{
		if (i + 1 >= 10)
		{
			string texto = "imagenes/fantasma/fantasma__0";
			texto += to_string(i + 1);
			texto = texto + ".png";
			Sprite *aux = Sprite::create(texto);
			animacionFantasma.pushBack(aux);
		}
		else
		{
			string texto = "imagenes/fantasma/fantasma__00";
			texto += to_string(i + 1);
			texto = texto + ".png";
			Sprite *aux = Sprite::create(texto);
			animacionFantasma.pushBack(aux);
		}
	}

	//animacion abeja
	for (int i = 0; i < 20; i++) {
		string texto = "imagenes/enemigos/abeja/";
		texto += to_string(i + 1);
		texto = texto + ".png";
		Sprite *aux = Sprite::create(texto);
		aux->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
		aux->setScaleY(tamañoPantalla.width / (4 * img.width)*0.1);
		animacionAbeja.pushBack(aux);
	}
	

	//Ver si la 11 tiene encima la 17
	maximoHierba = 58;

	for (int i = 0; i < 24; i++) {
		if (n[i] == 11 && n[i+6] == 17){
			maximoHierba *= 2;
		}
	}


	casillas = new Casilla*[24];
	
	//Modificamos la imagen
	listaPlatform = new Sprite*[19];
	numeroP = 19;

	listaEnem = new Enemigo*[5];
	numeroE = 5;

	listaObj = new Objeto*[19];
	numeroO = 19;

	

	for (int i = 0; i < 24; i++)
	{
		Casilla *cas = new Casilla(n[i]);
		casillas[i] = cas;

		float columnaImg = (tamañoPantalla.width / 6)  * ((float)(i - ((i / 6) * 6)) + 0.5);
		float filaImg = (tamañoPantalla.height / 4)  * ((float)(i / 6) + 0.5);

		cas->escalarPlataforma(cas->imagencas);
		cas->imagencas->setPosition(Point (columnaImg, filaImg) );
		addChild(cas->imagencas, 0);

		for (int j = 0; j < cas->numObj; j++)
		{
			cas->listaObjetos[j]->imagenobj->setPosition(Point(columnaImg + (tamañoPantalla.width / 6) * cas->listaObjetos[j]->posX, (filaImg + (tamañoPantalla.height / 4) * cas->listaObjetos[j]->posY)));

			addChild(cas->listaObjetos[j]->imagenobj, 1);
			contObj += 1;
			listaObj[contObj - 1] = cas->listaObjetos[j];

		}
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

	enemigosAcabados = new Enemigo*[2];
	int j = 0;
	for (int i = 0; i < numeroE; i++) {
		if (listaEnem[i]->tipoMovimiento == "vertical") {
			enemigosAcabados[j] = listaEnem[i];
			j++;
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
	pausa = false;
	movPlataforma = false;
	SPresionada = false;
	movArbol = false;
	fantasmaAnimado = 0;
	contMonedas = 0;
	contAnimacionMoneda = 0;
	TimerMoneda = 0.0f;
	contAnimacionFantasma = 0;
	TimerFantasma = 0.0f;
	mascaraAnimada = 0;
	prinPos.x = princesa->getPositionX();
	prinPos.y = princesa->getPositionY();
	prinPosAnt.x = princesa->getPositionX();
	prinPosAnt.y = princesa->getPositionY();
	contadorHierba = 0.0f;


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
	if (idTecla == EventKeyboard::KeyCode::KEY_A)
	{
		pausa = true;
		volverPuzzle();
	}
	if (idTecla == EventKeyboard::KeyCode::KEY_S)
	{
		SPresionada = true;
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
	if (idTecla == EventKeyboard::KeyCode::KEY_S)
	{
		if (SPresionada)
		{
			SPresionada = false;

		}
	}
}

//Funcion que se repite

void PlataformasScene::update(float dt){

	if (pausa == false) {

		Size tamañoPantalla = Director::getInstance()->getVisibleSize();
		
		//colision enemigos/princesa
		for (int i = 0; i < numeroE; i++) 
		{
			if (colision(princesa, listaEnem[i]->imagenEne))
			{
				reiniciarNivel();
			}

		}

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

			if (listaEnem[i]->tipoMovimiento == "basico")
			{

				listaEnem[i]->mover(listaEnem[i]->imagenEne);
				if (listaEnem[i]->faseMov == 1 && listaEnem[i]->imagenEne->getPositionX() >
					tamañoPantalla.width - listaEnem[i]->imagenEne->getContentSize().width / 2 * listaEnem[i]->imagenEne->getScaleX() 
					|| listaEnem[i]->faseMov == 1 && colisionPlataformas(listaEnem[i]->imagenEne) == false) {
					listaEnem[i]->faseMov = 2;
					listaEnem[i]->mover(listaEnem[i]->imagenEne);
				}

				if (listaEnem[i]->faseMov == 2 && listaEnem[i]->imagenEne->getPositionX() <
					listaEnem[i]->imagenEne->getContentSize().width / 2 * listaEnem[i]->imagenEne->getScaleX()
					|| listaEnem[i]->faseMov == 2 && colisionPlataformas(listaEnem[i]->imagenEne) == false) {
					listaEnem[i]->faseMov = 1;
					listaEnem[i]->mover(listaEnem[i]->imagenEne);
				}
			}

			if (listaEnem[i]->tipoMovimiento == "vertical")
			{
				listaEnem[i]->mover(listaEnem[i]->imagenEne);
				if (listaEnem[i]->imagenEne->getPositionX() + listaEnem[i]->imagenEne->getContentSize().width / 2 + 20 > prinPos.x &&
					listaEnem[i]->imagenEne->getPositionX() - listaEnem[i]->imagenEne->getContentSize().width / 2 - 20 < prinPos.x &&
					listaEnem[i]->imagenEne->getPositionY() > princesa->getPositionY() &&
					PlataformaEntre(listaEnem[i]->imagenEne, princesa) == false &&
					listaEnem[i]->faseMov == 1) 
					{
						listaEnem[i]->faseMov = 2;
					}
				if (colisionPlataformas(listaEnem[i]->imagenEne) == true && listaEnem[i]->faseMov == 2)
				{
					listaEnem[i]->faseMov = 3;
					Enemigo *aux = new Enemigo(1);
					for (int j = i; j < numeroE - 1; j++)
					{
						aux = listaEnem[j];
						listaEnem[j] = listaEnem[j + 1];
						listaEnem[j + 1] = aux;
					}
					numeroE--;
				}
			}
		}
		if (colisionEscaleras(princesa))
		{
			prinEscaleras = true;
			prinCae = false;

		}

		else if (prinMovSalto == false)
		{
			prinEscaleras = false;
			prinCae = true;
		}
		
		if (colisionEscaleras(princesa) == false)
			contAnimacionEscalar = 0;

		if (prinMovArriba)
		{
			prinPosAnt.y = prinPos.y;
			prinPos.y += VELOCIDADPRIN;
			princesa->setPositionY(prinPos.y);
			TimerEscalar += dt;
			if (TimerEscalar > FRESCALAR) {
				if (prinDerecha) {
					contAnimacionEscalar++;
					if (contAnimacionEscalar < FRAMESESCALAR)
					{
						princesa->setTexture(escalarPrincesaR.at(contAnimacionEscalar)->getTexture());
						TimerEscalar = 0.0f;
					}
					else
						contAnimacionEscalar = 0;
				}
				else
				{
					contAnimacionEscalar++;
					if (contAnimacionEscalar < FRAMESESCALAR) {
						princesa->setTexture(escalarPrincesaL.at(contAnimacionEscalar)->getTexture());
						TimerEscalar = 0.0f;
					}
					else
						contAnimacionEscalar = 0;
				}
			}
		}

		if (prinMovAbajo)
		{
			prinPosAnt.y = prinPos.y;
			prinPos.y -= VELOCIDADPRIN;
			princesa->setPositionY(prinPos.y);
			TimerEscalar += dt;
			if (TimerEscalar > FRESCALAR) {
				if (prinDerecha) {

					contAnimacionEscalar--;
					if (contAnimacionEscalar > 0)
					{

						princesa->setTexture(escalarPrincesaR.at(contAnimacionEscalar)->getTexture());
						TimerEscalar = 0.0f;
					}
					else
						contAnimacionEscalar = FRAMESESCALAR-1;
				}
				else
				{
					contAnimacionEscalar--;
					if (contAnimacionEscalar > 0)
					{
					
						princesa->setTexture(escalarPrincesaL.at(contAnimacionEscalar)->getTexture());
						TimerEscalar = 0.0f;
					}
					else
						contAnimacionEscalar = FRAMESESCALAR-1;
				}
			}

		}

		//Colision princesa/plataformas

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
				}
				else
				{
					prinPos.x = prinPosAnt.x;
					prinPos.y = prinPosAnt.y;
					prinMovSalto = false;
					prinSalto = true;
					princesa->setPosition(Point(prinPosAnt.x, prinPosAnt.y));
					prinCae = true;
				}
				/*if (colisionSoloPlataformaArriba() == true) {
					prinPos.y = prinPosAnt.y;
					prinSalto = false;
					prinMovSalto = false;
					prinCae = true;
				}
				else
				{
					prinPos.x = prinPosAnt.x;
					prinPos.y = prinPosAnt.y;
					prinMovSalto = false;
					prinSalto = true;
					princesa->setPosition(Point(prinPosAnt.x, prinPosAnt.y));
					prinCae = true;
				}*/
			}
			else if (prinCae)
			{
				//Cae constante, mejor un contador propio
				prinPosAnt.y = prinPos.y;
				prinPos.y -= (0.5f * FGRAVEDAD*dt*dt * 5);
				princesa->setPositionY(prinPos.y);
				prinSalto = true;

			}
		}

		//colision objetos
		for (int i = 0; i < numeroO; i++)
		{
			//mascara
			if (listaObj[i]->tipoObjeto == "mascara" && colision(princesa, listaObj[i]->imagenobj) && mascaraAnimada == 2)
			{
				princesa->setPosition(Point((tamañoPantalla.width / 6)  * (3 + 0.5) + tamañoPantalla.width / 6 * 0.2, (tamañoPantalla.height / 4)  *  (1 + 0.5) + tamañoPantalla.height / 4 * -0.3));
				//princesa->setPosition(Point(0, 300));
				prinPosAnt.x = princesa->getPositionX();
				prinPosAnt.y = princesa->getPositionY();

				prinPos.x = princesa->getPositionX();
				prinPos.y = princesa->getPositionY();
				prinCae = true;
			}
			//colision moneda
			
			if (listaObj[i]->tipoObjeto == "moneda"){
				
				if (colision(princesa, listaObj[i]->imagenobj))
				{
					removeChild(listaObj[i]->imagenobj, true);
					contMonedas++;
					Objeto *aux = new Objeto(1);
					for (int j = i; j < numeroO - 1; j++)
					{
						aux = listaObj[j];
						listaObj[j] = listaObj[j + 1];
						listaObj[j + 1] = aux;
					}
					numeroO--;
				}
			
			}
			//HitBox máscara

			if (listaObj[i]->tipoObjeto == "invisible" && fantasmaAnimado == 0 && colision(princesa, listaObj[i]->imagenobj)) {
				fantasmaAnimado = 1;
			}
			//colision pajaro
			
			if (movPlataforma == false && listaObj[i]->tipoObjeto == "pajaro" && colision(princesa, listaObj[i]->imagenobj) && SPresionada) {
				Sprite *aux = Sprite::create("imagenes/pulsador pajaro2.png");
				listaObj[i]->imagenobj->setTexture(aux->getTexture());
				movPlataforma = true;
			}
			//colision seta
			if (movArbol == false && listaObj[i]->tipoObjeto == "seta" && colision(princesa, listaObj[i]->imagenobj) && SPresionada) {
				movArbol = true;
			}

			//colision fuente
			if (listaObj[i]->tipoObjeto == "fin" && colision(princesa, listaObj[i]->imagenobj) && SPresionada && contMonedas == 5) {
				finJuego();
				
			}

		}
		
		//animacion moneda	

		TimerMoneda += dt;
		if (TimerMoneda > FRMONEDA)
		{
			if (contAnimacionMoneda >= FRAMESMONEDA - 1)
				contAnimacionMoneda = 0;
			else
				contAnimacionMoneda++;
			for (int i = 0; i < numeroO; i++) {
				if (listaObj[i]->tipoObjeto == "moneda") {
					listaObj[i]->imagenobj->setTexture(animacionMoneda.at(contAnimacionMoneda)->getTexture());
				}
			}
			TimerMoneda = 0.0f;
		}

		//animacion fantasma	
		
		if (fantasmaAnimado == 1)
		{
			TimerFantasma += dt;
			if (TimerFantasma > FRFANTASMA) 
			{
				for (int i = 0; i < numeroO; i++) 
				{
					if (listaObj[i]->tipoObjeto == "fantasma") 
					{
						listaObj[i]->imagenobj->setTexture(animacionFantasma.at(contAnimacionFantasma)->getTexture());
						listaObj[i]->imagenobj->setPositionX(listaObj[i]->imagenobj->getPositionX() + 2.0f);
						if (contAnimacionFantasma == 0) {
							Size img = listaObj[i]->imagenobj->getContentSize();
							listaObj[i]->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width) * 2);
							listaObj[i]->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width) * 2);
						}
					}
				}
				if (contAnimacionFantasma == 45) 
				{
					for (int i = 0; i < numeroO; i++) 
					{
						if (listaObj[i]->tipoObjeto == "mascara")
						{
							for (int j = 0; j < numeroO; j++) 
							{
								if (listaObj[j]->tipoObjeto == "fantasma") 
								{
									listaObj[i]->imagenobj->setPosition(Point(listaObj[j]->imagenobj->getPositionX() - 7.0f, listaObj[j]->imagenobj->getPositionY() - 60.0f));
									Sprite *aux = Sprite::create("imagenes/mascara.png");
									listaObj[i]->imagenobj->setTexture(aux->getTexture());
									Size img = aux->getContentSize();
									listaObj[i]->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
									listaObj[i]->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.2);
									mascaraAnimada = 1;
								}
							}
						}
					}
				}
				if (contAnimacionFantasma >= FRAMESFANTASMA - 1) 
				{
					fantasmaAnimado = 2;
					Sprite *aux = Sprite::create("imagenes/invisible.png");
					for (int i = 0; i < numeroO; i++) 
					{
						if (listaObj[i]->tipoObjeto == "fantasma") 
						{
							listaObj[i]->imagenobj->setTexture(aux->getTexture());
						}
					}
				}
				else
					contAnimacionFantasma++;
				TimerFantasma = 0.0f;
			}
		}

		//animacion Mascara
		if (mascaraAnimada == 1) {
			TimerMascara += dt;
			if (TimerMascara > FRMASCARA) {
				for (int i = 0; i < numeroO; i++) {
					if (listaObj[i]->tipoObjeto == "mascara") {
						listaObj[i]->imagenobj->setPositionY(listaObj[i]->imagenobj->getPositionY() - 3.0f);
						if (colisionPlataformas(listaObj[i]->imagenobj)) {
							mascaraAnimada = 2;
						}
					}

				}
			}
		}

		//movimiento hierba
		if (movPlataforma) {
			TimerHierba += dt;
			if (TimerHierba > FRHIERBA) {
				for (int i = 0; i < 24; i++) {
					if (casillas[i]->identificador == 11) {
						contadorHierba += 1.5f;
						if (contadorHierba < maximoHierba) {
							casillas[i]->listaObjetos[0]->imagenobj->setPositionY(casillas[i]->listaObjetos[0]->imagenobj->getPositionY() + 1.5f);
							casillas[i]->listaPlataformas[0]->imagenobj->setPositionY(casillas[i]->listaPlataformas[0]->imagenobj->getPositionY() + 1.5f);
						}
					}
				}
				TimerHierba = 0;
			}
		}

		//animaciones enemigos
		TimerEnemigos += dt;
		if (TimerEnemigos > FRENEMIGOS) {
			TimerEnemigos = 0;
			for (int i = 0; i < numeroE; i++) {
				listaEnem[i]->cambiarImagen();
			}
		}

		//animacion enemigos verticales
		TimerEnemigosVerticales += dt;
		if (TimerEnemigosVerticales > FRENEMIGOS) {
			TimerEnemigosVerticales = 0;
			for (int i = 0; i < 2; i++) {
				if (enemigosAcabados[i]->faseMov == 3) {
					enemigosAcabados[i]->imagenActual++;
					if (enemigosAcabados[i]->imagenActual < 20) {
						enemigosAcabados[i]->imagenEne->setTexture(animacionAbeja.at(enemigosAcabados[i]->imagenActual)->getTexture());
					}
				}
			}
		}



		//Movimiento princesa en X
		if (prinMovL)
		{
			prinPosAnt.x = prinPos.x;
			prinPos.x -= VELOCIDADPRIN;
		}
		if (prinMovR) {
			prinPosAnt.x = prinPos.x;
			prinPos.x += VELOCIDADPRIN;
		}

		if (prinPos.x > princesa->getContentSize().width / 2 * princesa->getScaleX()
			&& prinPos.x < tamañoPantalla.width - princesa->getContentSize().width / 2 * princesa->getScaleX())
			princesa->setPositionX(prinPos.x);
		else
			prinPos.x = princesa->getPositionX();


	}
		
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
	{		if (listaObj[i]->tipoObjeto == "escalada")		{			if (colision(listaObj[i]->imagenobj, a))				return true;		}	}	return false;}bool PlataformasScene::colisionSoloPlataformaArriba() {	for (int i = 0; i < numeroP; i++) {		if (colision(listaPlatform[i], princesa) &&
			prinPosAnt.y - (princesa->getContentSize().height / 2 * princesa->getScaleY()) <=
			listaPlatform[i]->getPositionY() + (listaPlatform[i]->getContentSize().height / 2 * listaPlatform[i]->getScaleY())) {			return false;		}	}	return true;}bool PlataformasScene::PlataformaEntre(Sprite* a, Sprite* b){	for (int j = 0; j < numeroP; j++)
	{
		if (listaPlatform[j]->getPositionX() + ((listaPlatform[j]->getContentSize().width / 2) * listaPlatform[j]->getScaleX()) > a->getPositionX() - ((a->getContentSize().width / 2)*a->getScaleX()) &&
			listaPlatform[j]->getPositionX() - ((listaPlatform[j]->getContentSize().width / 2) * listaPlatform[j]->getScaleX()) < a->getPositionX() + ((a->getContentSize().width / 2)*a->getScaleX()) &&
			a->getPositionY() > listaPlatform[j]->getPositionY() &&
			b->getPositionY() < listaPlatform[j]->getPositionY())
		{
			return true;
		}
	}	return false;}Sprite* PlataformasScene::ColisionPlataformas(Sprite* a){
	for (int i = 0; i < numeroP; i++)
	{		if (colision(listaPlatform[i], a))			return listaPlatform[i];	}}void PlataformasScene::reiniciarNivel() {
	auto scene = PlataformasScene::createScene(n);

    //Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}void PlataformasScene::volverPuzzle() {
	//auto scene = PuzzleEscena::createScene();
	
	//eliminarPunteros();
	Director::getInstance()->popScene();

	//Director::getInstance()->replaceScene(scene);
}void PlataformasScene::finJuego() {	auto scene = FinEscena::createScene();	Director::getInstance()->replaceScene(scene);}void PlataformasScene::eliminarPunteros() {	int a = numeroP;	int b = numeroO;	int c = numeroE;	pausa = true;	removeChild(princesa, true);	delete[] princesa;	for (int i = 0; i < FRAMESCORRER; i++)	{		delete correrPrincesaR.at(i);		delete correrPrincesaL.at(i);	}	for (int i = 0; i < 24; i++)	{		removeChild(casillas[i], true);		delete[] casillas[i];	}	delete[] casillas;	for (int i = 0; i < a; i++) 	{		removeChild(listaPlatform[i], true);		delete[] listaPlatform[i];	}	delete[] listaPlatform;	for (int i = 0; i < b; i++) 	{		removeChild(listaObj[i]->imagenobj, true);		delete[] listaObj[i];	}	delete[] listaObj;	for (int i = 0; i < c; i++) 	{		removeChild(listaEnem[i]->imagenEne, true);		delete[] listaEnem[i];	}	delete[] listaEnem;}

void PlataformasScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
