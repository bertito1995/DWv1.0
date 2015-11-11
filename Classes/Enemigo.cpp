#include "Enemigo.h"

USING_NS_CC;

bool Enemigo::init(){

	if (!Layer::init())
		return false;
	
	tipo = "ninguno";
	derecha = true;
	return true;
}

void Enemigo::setTipo(String Tipo){
	tipo = Tipo;
	if (tipo.compare("basico")){
		velocidad = 5;
	}
}

void Enemigo::setImagen(Sprite *Imagen){
	imagen = Imagen;
	pos.x = imagen->getPositionX();
	pos.y = imagen->getPositionY();

}

void Enemigo::setDerecha(bool Derecha){
	derecha = Derecha;
}

Vec2 Enemigo::getPos(){
	return pos;
}

void Enemigo::mover(){

	if (tipo.compare("basico"))
	{
		if (derecha)
			this->setPositionX(this->getPositionX() + velocidad);
		else
			this->setPositionX(this->getPositionX() - velocidad);
		//pos.x = imagen->getPositionX();
	}
}

