#include "PuzzleEscena.h"
#include "Nivel.h"
#include "Casilla.h"
#include "cocos2d.h"
#include "PlataformasScene.h"
#include "SimpleAudioEngine.h"




USING_NS_CC;



Scene *PuzzleEscena::createScene()
{
	auto scene = Scene::create();
	auto layer = PuzzleEscena::create();
	scene->addChild(layer);
	return scene;
}

bool PuzzleEscena::init()

{

	ayuda = true;
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();

	coloca = Sprite::create("imagenes/gui/bombilla.png");
	coloca->setScaleX(tamañoPantalla.width / coloca->getContentSize().width * 0.1);
	coloca->setScaleY(tamañoPantalla.height / coloca->getContentSize().height * 0.17);
	coloca->setPosition(Point(tamañoPantalla.width/2 +100, tamañoPantalla.height / 10));
	
	cambia = Sprite::create("imagenes/gui/playApagado.png");
	cambia->setScaleX(tamañoPantalla.width / cambia->getContentSize().width * 0.15);
	cambia->setScaleY(tamañoPantalla.height / cambia->getContentSize().height * 0.17);
	cambia->setPosition(Point(tamañoPantalla.width/2 - 100, tamañoPantalla.height / 10));	reset = Sprite::create("imagenes/gui/reset.png");
	reset->setScaleX(tamañoPantalla.width / reset->getContentSize().width * 0.15);
	reset->setScaleY(tamañoPantalla.height / reset->getContentSize().height * 0.17);
	reset->setPosition(Point(tamañoPantalla.width / 2 - 300, tamañoPantalla.height / 10));	Sprite *fondo = Sprite::create("imagenes/gui/interfaz.png");
	fondo->setScaleX(tamañoPantalla.width / fondo->getContentSize().width);
	fondo->setScaleY(tamañoPantalla.height / fondo->getContentSize().height);
	fondo->setPosition(Point((tamañoPantalla.width / 2), (tamañoPantalla.height / 2)));
	addChild(fondo, 0);	addChild(reset, 2);	addChild(coloca, 2);	addChild(cambia, 2);


	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("audio/Music.wav", true);
	


	this->scheduleUpdate();

	uno = new Nivel(1);
	
	//Colocacion aleatoria

	while (quedanPorColocar(uno->VecCasillas, uno->LongVec) == true)
	{
		bool igual = false;
		int a = random() % (25 - 1) + 1;
		for (int i = 0; i < uno->LongVec; i++){
			if (uno->VecCasillas[i]->identificador == a || a == 1 || a == 18 ) {
				igual = true;
			}
		}
		for (int i = 0; i < uno->LongVec; i++) {
			if (uno->VecCasillas[i]->identificador == 0 && igual == false) {
				Casilla *cas = new Casilla(a);
				uno->VecCasillas[i] = cas;
				igual = true;
			}
		}
	
	}

	//dibujado de la matriz
	uno->MatrizJugador = uno->MatrizInicial;
	for (int i = 0; i < 24; i++)
	{
		float columnaImg = tamañoPantalla.width / 25 + (ANCHOINI)  * ((float)(i - ((i / 6) * 6)) + 0.5);
		float filaImg = tamañoPantalla.height/4 + (ALTOINI)  * ((float)(i / 6) + 0.5);

		uno->MatrizJugador[i]->escalarPuzzle(uno->MatrizJugador[i]->imagencas);
		uno->MatrizJugador[i]->imagencas->setPosition(Point(columnaImg, filaImg));
		addChild(uno->MatrizJugador[i]->imagencas, 1);
		
	}

	//dibujado del banco
	for (int i = 0; i < 22; i++)
	{
		float columnaImg = tamañoPantalla.width/1.2 + (ANCHOVEC)* ((float)(i - ((i / 2) * 2)) + 0.5);
		float filaImg = tamañoPantalla.height / 19 + (ALTOVEC)* ((float)(i / 2) + 0.5);

		uno->VecCasillas[i]->escalarVector(uno->VecCasillas[i]->imagencas);
		uno->VecCasillas[i]->imagencas->setPosition(Point(columnaImg, filaImg));
		addChild(uno->VecCasillas[i]->imagencas, 1);

	}

	casillaSeleccionada = -1;

	auto event_listener = EventListenerTouchAllAtOnce::create();
	
	//Cuando pulsas
	event_listener->onTouchesBegan = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		float distancia;
		for (int i = 0; i < uno->LongVec; i++)
		{
			distancia = this->uno->VecCasillas[i]->imagencas->getPosition().getDistance(touch->getLocation());
			if (distancia < 30 && uno->VecCasillas[i]->identificador != 0) 
			{
				banco = true;
				
				casillaSeleccionada = i;
				reorderChild(uno->VecCasillas[i]->imagencas, 2);
				return;
			}
		}

		for (int i = 0; i < uno->LongMat; i++)
		{
			distancia = this->uno->MatrizJugador[i]->imagencas->getPosition().getDistance(touch->getLocation());
			if (distancia < 30 && uno->MatrizJugador[i]->identificador != 0 && uno->MatrizJugador[i]->fija==false)
			{
				
				uno->MatrizJugador[i]->escalarVector(uno->MatrizJugador[i]->imagencas);
				banco = false;
				casillaSeleccionada = i;
				reorderChild(uno->MatrizJugador[i]->imagencas, 2);
				return;
			}
		}
		
		distancia = coloca->getPosition().getDistance(touch->getLocation());
		if (distancia < 30 && ayuda)
		{

			Sprite* aux = Sprite::create("imagenes/gui/bombillaIluminada.png");			coloca->setTexture(aux->getTexture());
			
			//ayuda = true;
			return;
		}
		distancia = cambia->getPosition().getDistance(touch->getLocation());
		if (distancia <30)
		{
			cambio(this);
			return;
		}

		distancia = reset->getPosition().getDistance(touch->getLocation());
		if (distancia < 30)
		{

			Sprite* aux = Sprite::create("imagenes/gui/resetPulsado.png");			reset->setTexture(aux->getTexture());

			//ayuda = true;
			return;
		}
		
	};

	//Cuando sueltas
	event_listener->onTouchesEnded = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		if (casillaSeleccionada != -1)
		{
			auto touch = *pTouches.begin();
			auto openGl_location = touch->getLocation();

			float distancia;

			for (int i = 0; i < uno->LongMat; i++)
			{
				distancia = this->uno->MatrizJugador[i]->imagencas->getPosition().getDistance(touch->getLocation());
				if (distancia < 30 && uno->MatrizJugador[i]->fija == false)
				{
					if (banco == true)
					{
						Casilla *aux = new Casilla(0);
						aux = uno->MatrizJugador[i];
						uno->MatrizJugador[i] = uno->VecCasillas[casillaSeleccionada];
						uno->VecCasillas[casillaSeleccionada] = aux;

						float columnaImg = tamañoPantalla.width / 25 + (ANCHOINI)* ((float)(i - ((i / 6) * 6)) + 0.5);
						float filaImg = tamañoPantalla.height / 4 + (ALTOINI)* ((float)(i / 6) + 0.5);
						uno->MatrizJugador[i]->escalarPuzzle(uno->MatrizJugador[i]->imagencas);
						uno->MatrizJugador[i]->imagencas->setPosition(columnaImg, filaImg);

						columnaImg = tamañoPantalla.width / 1.2 + (ANCHOVEC)* ((float)(casillaSeleccionada - ((casillaSeleccionada / 2) * 2)) + 0.5);
						filaImg = tamañoPantalla.height / 19 + (ALTOVEC)* ((float)(casillaSeleccionada / 2) + 0.5);
						
						uno->VecCasillas[casillaSeleccionada]->escalarVector(uno->VecCasillas[casillaSeleccionada]->imagencas);
						uno->VecCasillas[casillaSeleccionada]->imagencas->setPosition(columnaImg, filaImg);
						reorderChild(uno->MatrizJugador[i]->imagencas, 1);

						casillaSeleccionada = -1;
					}
					else 
					{
						if (i != casillaSeleccionada)
						{
							Casilla *aux = new Casilla(0);
							aux = uno->MatrizJugador[i];
							uno->MatrizJugador[i] = uno->MatrizJugador[casillaSeleccionada];
							uno->MatrizJugador[casillaSeleccionada] = aux;

							float columnaImg = tamañoPantalla.width / 25 + (ANCHOINI)* ((float)(i - ((i / 6) * 6)) + 0.5);
							float filaImg = tamañoPantalla.height / 4 + (ALTOINI)* ((float)(i / 6) + 0.5);
							
							uno->MatrizJugador[i]->escalarPuzzle(uno->MatrizJugador[i]->imagencas);
							uno->MatrizJugador[i]->imagencas->setPosition(columnaImg, filaImg);

							columnaImg = tamañoPantalla.width / 25 + (ANCHOINI)* ((float)(casillaSeleccionada - ((casillaSeleccionada / 6) * 6)) + 0.5);
							filaImg = tamañoPantalla.height / 4 + (ALTOINI)* ((float)(casillaSeleccionada / 6) + 0.5);
							uno->MatrizJugador[casillaSeleccionada]->imagencas->setPosition(columnaImg, filaImg);
							reorderChild(uno->MatrizJugador[i]->imagencas, 1);

							casillaSeleccionada = -1;
						}
						
					}
					
					
				}
				
			}
			if (casillaSeleccionada != -1)
			{
				if (banco == true)
				{
					float columnaImg = tamañoPantalla.width / 1.2 + (ANCHOVEC)* ((float)(casillaSeleccionada - ((casillaSeleccionada / 2) * 2)) + 0.5);
					float filaImg = tamañoPantalla.height / 19 + (ALTOVEC)* ((float)(casillaSeleccionada / 2) + 0.5);
					
					uno->VecCasillas[casillaSeleccionada]->imagencas->setPosition(columnaImg, filaImg);
					reorderChild(uno->VecCasillas[casillaSeleccionada]->imagencas, 1);

					casillaSeleccionada = -1;
				}
				else
				{
					float columnaImg = tamañoPantalla.width / 25 + (ANCHOINI)* ((float)(casillaSeleccionada - ((casillaSeleccionada / 6) * 6)) + 0.5);
					float filaImg = tamañoPantalla.height / 4 + (ALTOINI)* ((float)(casillaSeleccionada / 6) + 0.5);
					
					uno->MatrizJugador[casillaSeleccionada]->escalarPuzzle(uno->MatrizJugador[casillaSeleccionada]->imagencas);
					uno->MatrizJugador[casillaSeleccionada]->imagencas->setPosition(columnaImg, filaImg);
					reorderChild(uno->MatrizJugador[casillaSeleccionada]->imagencas, 1);

					casillaSeleccionada = -1;
				}
			}
		}

		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();
		float distancia;
		distancia = coloca->getPosition().getDistance(touch->getLocation());
		if (distancia < 30 && ayuda)
		{
			colocar();
			ayuda = false;
			//ayuda = true;
			return;
		}

		distancia = reset->getPosition().getDistance(touch->getLocation());
		if (distancia < 30)
		{
			reiniciar();
			
			
			return;
		}

	};
	//Cunado mueves
	event_listener->onTouchesMoved = [=](const std::vector<Touch*>& pTouches, Event* event)
	{
		auto touch = *pTouches.begin();
		auto openGl_location = touch->getLocation();

		if (casillaSeleccionada != -1)
		{
			if (banco == true)
				uno->VecCasillas[casillaSeleccionada]->imagencas->setPosition(touch->getLocation());
			else 
				uno->MatrizJugador[casillaSeleccionada]->imagencas->setPosition(touch->getLocation());
		}
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event_listener, uno->VecCasillas[0]->imagencas);
	return true;
}

//Update
void PuzzleEscena::update(float dt) {
	if (quedan(uno->VecCasillas, uno->LongVec) == false) {
		Sprite* aux = Sprite::create("imagenes/gui/play.png");
		cambia->setTexture(aux->getTexture());
	}
}

void PuzzleEscena::cambio(Ref *pSender) 
{
	
	int * a;
	a = new int[24];
	for (int i = 0; i < uno->LongMat; i++)
	{
		a[i] = uno->MatrizJugador[i]->identificador;
		if (a[i] == 0)
		{
			return;
		}

	}
	auto scene = PlataformasScene::createScene(a);
	Director::getInstance()->pushScene(scene);
	
}

void PuzzleEscena::reiniciar() 
{
	auto scene = PuzzleEscena::createScene();
	Director::getInstance()->replaceScene(scene);
}

void PuzzleEscena::colocar()
{
	Sprite * a = Sprite::create("imagenes/gui/bombillaApagada.png");
	coloca->setTexture(a->getTexture());
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();

	Casilla * aux;
	int posicion;
	if (quedan(uno->VecCasillas, uno->LongVec))
	{
		for (int i = 0; i < uno->LongVec; i++)
		{
			if (uno->VecCasillas[i]->identificador != 0)
			{
				posicion = i;
				break;
			}
		}

		for (int i = 0; i < uno->LongMat; i++)
		{
			if (uno->MatrizCorrecta[i]->identificador == uno->VecCasillas[posicion]->identificador)
			{
			
				aux = uno->MatrizJugador[i];
				uno->MatrizJugador[i] = uno->VecCasillas[posicion];
				uno->VecCasillas[posicion] = aux;
				uno->MatrizJugador[i]->fija = true;

				float columnaImg = tamañoPantalla.width / 25 + (ANCHOINI)* ((float)(i - ((i / 6) * 6)) + 0.5);
				float filaImg = tamañoPantalla.height / 4 + (ALTOINI)* ((float)(i / 6) + 0.5);
				uno->MatrizJugador[i]->escalarPuzzle(uno->MatrizJugador[i]->imagencas);
				uno->MatrizJugador[i]->imagencas->setPosition(columnaImg, filaImg);

				columnaImg = tamañoPantalla.width / 1.2 + (ANCHOVEC)* ((float)(posicion - ((posicion / 2) * 2)) + 0.5);
				filaImg = tamañoPantalla.height / 19 + (ALTOVEC)* ((float)(posicion / 2) + 0.5);
				uno->VecCasillas[posicion]->escalarVector(uno->VecCasillas[posicion]->imagencas);
				uno->VecCasillas[posicion]->imagencas->setPosition(columnaImg, filaImg);

				return;

		
			}

		}
	}
	else
	{
		if (puzzleCorrecto(uno)) {
			return;
		}
		for (int i = 0; i < uno->LongMat; i++)
		{
			if (uno->MatrizJugador[i]->identificador != uno->MatrizCorrecta[i]->identificador)
			{
				posicion = i;
				break;
			}
		}
		for (int i = 0; i < uno->LongMat; i++)
		{
			if (uno->MatrizCorrecta[i]->identificador == uno->MatrizJugador[posicion]->identificador)
			{
				aux = uno->MatrizJugador[i];
				uno->MatrizJugador[i] = uno->MatrizJugador[posicion];
				uno->MatrizJugador[posicion] = aux;
				uno->MatrizJugador[i]->fija = true;

				float columnaImg = tamañoPantalla.width / 25 + (ANCHOINI)* ((float)(i - ((i / 6) * 6)) + 0.5);
				float filaImg = tamañoPantalla.height / 4 + (ALTOINI)* ((float)(i / 6) + 0.5);
				uno->MatrizJugador[i]->escalarPuzzle(uno->MatrizJugador[i]->imagencas);
				uno->MatrizJugador[i]->imagencas->setPosition(columnaImg, filaImg);

				columnaImg = tamañoPantalla.width / 25 + (ANCHOINI)* ((float)(posicion - ((posicion / 6) * 6)) + 0.5);
				filaImg = tamañoPantalla.height / 4 + (ALTOINI)* ((float)(posicion / 6) + 0.5);
				uno->MatrizJugador[posicion]->imagencas->setPosition(columnaImg, filaImg);

				return;
			}
		}
	}
	
}

bool PuzzleEscena::puzzleCorrecto(Nivel* a) {
	for (int i = 0; i < a->LongMat; i++) {
		if (a->MatrizJugador[i]->identificador != a->MatrizCorrecta[i]->identificador) {
			return false;
		}
	}
	return true;
}

bool PuzzleEscena::quedan(Casilla ** Matriz, int longitud)
{
	for (int i = 0; i < longitud; i++)
	{
		if (Matriz[i]->identificador != 0)
		{
			return true;
		}
	}
	return false;

}

bool PuzzleEscena::quedanPorColocar(Casilla ** Matriz, int longitud)
{
	for (int i = 0; i < longitud; i++)
	{
		if (Matriz[i]->identificador == 0)
		{
			return true;
		}
	}
	return false;

}

void PuzzleEscena::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}