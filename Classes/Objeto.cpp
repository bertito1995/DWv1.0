#include "Objeto.h"

Objeto::Objeto(int id) {

	Size tamaņoPantalla = Director::getInstance()->getVisibleSize();

	if (id == 1)
	{

		tipoObjeto = "coleccionable";
		imagenObjeto = "imagenes/runa.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamaņoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamaņoPantalla.height / (8 * img.height));
	
		
	}
}