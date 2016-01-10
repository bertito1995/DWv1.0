#include "Enemigo.h"



Enemigo::Enemigo(int id){

	faseMov = 1;
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();
	identificador = id;

	//Enemigo básico
	if (id == 1)
	{
		velocidad = 1;
		faseMov = 2;
		tipoMovimiento = "basico";
		imagenL = "imagenes/enemigos/aranaR.png";
		imagenActual = 1;

		imagenEne = Sprite::create(imagenL);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
		imagenEne->setScaleY(tamañoPantalla.width / (4 * img.width)*0.1);

		
		

	}
	else if (id == 2)
	{
		velocidad = 3;
		faseMov = 2;
		tipoMovimiento = "basico";
		imagenL = "imagenes/enemigos/grandeR.png";
		imagenActual = 1;

		imagenEne = Sprite::create(imagenL);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
		imagenEne->setScaleY(tamañoPantalla.width / (4 * img.width)*0.1);
	}

	else if (id == 3)
	{
		velocidad = 3;
		tipoMovimiento = "basico";
		imagenL = "imagenes/T-rex.png";

		imagenEne = Sprite::create(imagenL);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
		imagenEne->setScaleY(tamañoPantalla.width / (4 * img.width)*0.1);

	}

	else if (id == 4)
	{
		velocidad = 2;
		tipoMovimiento = "basico";
		imagenL = "imagenes/enemigos/bicho fuenteL.png";

		imagenEne = Sprite::create(imagenL);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(tamañoPantalla.width / (6 * img.width)*0.25);
		imagenEne->setScaleY(tamañoPantalla.width / (4 * img.width)*0.2);
	}

	else if (id == 5)
	{
		velocidad = 5;
		tipoMovimiento = "vertical";
		imagenL = "imagenes/enemigos/abeja/0.png";
		imagenActual = 0;

		imagenEne = Sprite::create(imagenL);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
		imagenEne->setScaleY(tamañoPantalla.width / (4 * img.width)*0.1);


	}

	else if (id == 6)
	{
		velocidad = 3;
		tipoMovimiento = "basico";
		imagenL = "imagenes/lagarto 2.png";

		imagenEne = Sprite::create(imagenL);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
		imagenEne->setScaleY(tamañoPantalla.width / (4 * img.width)*0.1);
	}
}

void Enemigo::cambiarImagen() {
	Sprite* aux;
	if (tipoMovimiento == "basico" && identificador == 1) {
		if (faseMov == 1 && imagenActual == 1) {
			imagenActual = 2;
			aux = Sprite::create("imagenes/enemigos/aranaR2.png");
			imagenEne->setTexture(aux->getTexture());
		}
		else if (faseMov == 1 && imagenActual == 2) {
			aux = Sprite::create("imagenes/enemigos/aranaR.png");
			imagenEne->setTexture(aux->getTexture());
			imagenActual = 1;
		}
		else if (faseMov == 2 && imagenActual == 1) {
			aux = Sprite::create("imagenes/enemigos/aranaL2.png");
			imagenEne->setTexture(aux->getTexture());
			imagenActual = 2;
		}
		else if (faseMov == 2 && imagenActual == 2) {
			aux = Sprite::create("imagenes/enemigos/aranaL.png");
			imagenEne->setTexture(aux->getTexture());
			imagenActual = 1;
		}
	}
	else if (tipoMovimiento == "basico" && identificador == 2) {
		if (faseMov == 1 && imagenActual == 1) {
			imagenActual = 2;
			aux = Sprite::create("imagenes/enemigos/grandeR2.png");
			imagenEne->setTexture(aux->getTexture());
		}
		else if (faseMov == 1 && imagenActual == 2) {
			aux = Sprite::create("imagenes/enemigos/grandeR.png");
			imagenEne->setTexture(aux->getTexture());
			imagenActual = 1;
		}
		else if (faseMov == 2 && imagenActual == 1) {
			aux = Sprite::create("imagenes/enemigos/grandeL2.png");
			imagenEne->setTexture(aux->getTexture());
			imagenActual = 2;
		}
		else if (faseMov == 2 && imagenActual == 2) {
			aux = Sprite::create("imagenes/enemigos/grandeL.png");
			imagenEne->setTexture(aux->getTexture());
			imagenActual = 1;
		}
	}
	else if (tipoMovimiento == "basico" && identificador == 4) {
		if (faseMov == 1) 
		{
			aux = Sprite::create("imagenes/enemigos/bicho fuenteR.png");
			imagenEne->setTexture(aux->getTexture());
		}

		else 
		{
			aux = Sprite::create("imagenes/enemigos/bicho fuenteL.png");
			imagenEne->setTexture(aux->getTexture());
		}
	}
}

void Enemigo::mover(Sprite * sprite){

	//FaseMov en basico:
	//1->derecha**2->izquierda

	if (tipoMovimiento == "basico")
	{
		if (faseMov == 1)
			sprite->setPositionX(sprite->getPositionX() + velocidad);
		if (faseMov == 2)
			sprite->setPositionX(sprite->getPositionX() - velocidad);
	}
	
	//FaseMov en vertical:
	//1->parado, esperando interaccio**2->movimiento**3->fin interaccion

	if (tipoMovimiento == "vertical")
	{
		if (faseMov == 2)
			sprite->setPositionY(sprite->getPositionY() - velocidad);
	}
}