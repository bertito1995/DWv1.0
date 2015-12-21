#include "Enemigo.h"



Enemigo::Enemigo(int id){

	faseMov = 1;
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();

	//Enemigo básico
	if (id == 1)
	{
		velocidad = 3;
		tipoMovimiento = "basico";
		imagen = "imagenes/arana.png";

		imagenEne = Sprite::create(imagen);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
		imagenEne->setScaleY(tamañoPantalla.width / (4 * img.width)*0.1);

		
		

	}
	else if (id == 2)
	{
		velocidad = 3;
		tipoMovimiento = "basico";
		imagen = "imagenes/grande.png";

		imagenEne = Sprite::create(imagen);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
		imagenEne->setScaleY(tamañoPantalla.width / (4 * img.width)*0.1);
	}

	else if (id == 3)
	{
		velocidad = 3;
		tipoMovimiento = "basico";
		imagen = "imagenes/T-rex.png";

		imagenEne = Sprite::create(imagen);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
		imagenEne->setScaleY(tamañoPantalla.width / (4 * img.width)*0.1);

	}

	else if (id == 4)
	{
		velocidad = 3;
		tipoMovimiento = "basico";
		imagen = "imagenes/bicho fuente.png";

		imagenEne = Sprite::create(imagen);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(tamañoPantalla.width / (6 * img.width)*0.25);
		imagenEne->setScaleY(tamañoPantalla.width / (4 * img.width)*0.2);
	}

	else if (id == 5)
	{
		velocidad = 3;
		tipoMovimiento = "vertical";
		imagen = "imagenes/abeja.png";

		imagenEne = Sprite::create(imagen);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
		imagenEne->setScaleY(tamañoPantalla.width / (4 * img.width)*0.1);
	}

	else if (id == 6)
	{
		velocidad = 3;
		tipoMovimiento = "vertical";
		imagen = "imagenes/lagarto 2.png";

		imagenEne = Sprite::create(imagen);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
		imagenEne->setScaleY(tamañoPantalla.width / (4 * img.width)*0.1);
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