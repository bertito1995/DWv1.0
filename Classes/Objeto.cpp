#include "Objeto.h"

Objeto::Objeto(int id) {

	Size tamañoPantalla = Director::getInstance()->getVisibleSize();

	if (id == 1)
	{

		tipoObjeto = "coleccionable";
		imagenObjeto = "imagenes/runa.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));
	
		
	}
}