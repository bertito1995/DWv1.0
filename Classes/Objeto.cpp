#include "Objeto.h"

Objeto::Objeto(int id) {

	Size tama�oPantalla = Director::getInstance()->getVisibleSize();

	if (id == 1)
	{

		tipoObjeto = "coleccionable";
		imagenObjeto = "imagenes/runa.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tama�oPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tama�oPantalla.height / (8 * img.height));
	
		
	}
}