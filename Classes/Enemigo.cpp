#include "Enemigo.h"


Enemigo::Enemigo(int id){

	derecha = true;
	
	//Enemigo básico
	if (id == 1)
	{
		velocidad = 3;
		tipoMovimiento = "basico";
		imagen = "provisional/enemigo.png";
	}
}

void Enemigo::mover(Sprite * sprite){

	if (tipoMovimiento == "basico")
	{
		if (derecha)
			sprite->setPositionX(sprite->getPositionX() + velocidad);
		else
			sprite->setPositionX(sprite->getPositionX() - velocidad);
	}
}