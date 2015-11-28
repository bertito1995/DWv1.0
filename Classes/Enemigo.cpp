#include "Enemigo.h"


Enemigo::Enemigo(int id){

	faseMov = 1;
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();

	//Enemigo básico
	if (id == 1)
	{
		velocidad = 3;
		tipoMovimiento = "basico";
		imagen = "provisional/enemigo.png";

		imagenEne = Sprite::create(imagen);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(0.15f);
		imagenEne->setScaleY(0.15f);

	}
	if (id == 2)
	{
		velocidad = 3;
		tipoMovimiento = "vertical";
		imagen = "provisional/enemigo.png";

		imagenEne = Sprite::create(imagen);
		Size img = imagenEne->getContentSize();
		imagenEne->setScaleX(0.15f);
		imagenEne->setScaleY(0.15f);
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