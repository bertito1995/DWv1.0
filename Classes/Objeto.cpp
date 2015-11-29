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

	else if (id == 2)
	{

		tipoObjeto = "pajaro";
		imagenObjeto = "imagenes/pulsador pajaro.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}

	else if (id == 3)
	{

		tipoObjeto = "seta";
		imagenObjeto = "imagenes/pulsador seta.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}

	else if (id == 4)
	{

		tipoObjeto = "nube1";
		imagenObjeto = "imagenes/nube1.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}
	else if (id == 5)
	{

		tipoObjeto = "nube2";
		imagenObjeto = "imagenes/nube 2.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}

	else if (id == 6)
	{

		tipoObjeto = "hierba";
		imagenObjeto = "imagenes/plataforma hierba.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}

	else if (id == 7)
	{

		tipoObjeto = "puente1";
		imagenObjeto = "imagenes/puente1.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}

	else if (id == 8)
	{

		tipoObjeto = "puente2";
		imagenObjeto = "imagenes/puente 2.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}


	else if (id == 9)
	{

		tipoObjeto = "puerta";
		imagenObjeto = "imagenes/compuerta arbol.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}

	else if (id == 10)
	{

		tipoObjeto = "moneda";
		imagenObjeto = "imagenes/moneda.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}

	else if (id == 11)
	{

		tipoObjeto = "plataforma";
		imagenObjeto = "provisional/princesa.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}

	else if (id == 12)
	{

		tipoObjeto = "invisible";
		imagenObjeto = "imagenes/invisible.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}

	else if (id == 13)
	{

		tipoObjeto = "columpio";
		imagenObjeto = "imagenes/columpio.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}

	else if (id == 14)
	{

		tipoObjeto = "mascara";
		imagenObjeto = "imagenes/mascara.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}

}