#include "Objeto.h"

Objeto::Objeto(int id) {

	Size tamañoPantalla = Director::getInstance()->getVisibleSize();

	if (id == 1)
	{

		tipoObjeto = "coleccionable";
		imagenObjeto = "imagenes/runa.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.15);
		imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.1);
	
		
	}

	else if (id == 2)
	{

		tipoObjeto = "pajaro";
		imagenObjeto = "imagenes/pulsador pajaro.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.13);
		imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.08);


	}

	else if (id == 3)
	{

		tipoObjeto = "seta";
		imagenObjeto = "imagenes/pulsador seta.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.32);
		imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.22);



	}

	else if (id == 4)
	{

		tipoObjeto = "nube1";
		imagenObjeto = "imagenes/nube1.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.35);
		imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.35);



	}
	else if (id == 5)
	{

		tipoObjeto = "nube2";
		imagenObjeto = "imagenes/nube 2.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.5);
		imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.5);



	}

	else if (id == 6)
	{

		tipoObjeto = "hierba";
		imagenObjeto = "imagenes/plataforma hierba.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.58);
		imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.58);


	}

	else if (id == 7)
	{

		tipoObjeto = "puente1";
		imagenObjeto = "imagenes/puente1.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.55);
		imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.55);


	}

	else if (id == 8)
	{

		tipoObjeto = "puente2";
		imagenObjeto = "imagenes/puente 2.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.65);
		imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.65);


	}


	else if (id == 9)
	{

		tipoObjeto = "puerta";
		imagenObjeto = "imagenes/compuerta arbol.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.61);
		imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.53);


	}

	else if (id == 10)
	{

		tipoObjeto = "moneda";
		imagenObjeto = "imagenes/moneda.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.09);
		imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.06);


	}

	else if (id == 11)
	{

		tipoObjeto = "plataforma";
		imagenObjeto = "provisional/plataforma.png";

		imagenobj = Sprite::create(imagenObjeto);
		//Size img = imagenobj->getContentSize();
		//imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		//imagenobj->setScaleY(0.03);


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
		imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.18);
		imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.18);


	}

	else if (id == 14)
	{

		tipoObjeto = "mascara";
		imagenObjeto = "imagenes/invisible.png";
		imagenobj = Sprite::create(imagenObjeto);
	}

	else if (id == 15)
	{
		
		tipoObjeto = "escalada";
		imagenObjeto = "provisional/escalera.png";
		imagenobj = Sprite::create(imagenObjeto);
	}
	else if (id == 16)
	{
		tipoObjeto = "fantasma";
		imagenObjeto = "imagenes/invisible.png";
		imagenobj = Sprite::create(imagenObjeto);
	}

	else if (id == 17)
	{

		tipoObjeto = "fin";
		imagenObjeto = "imagenes/invisible.png";

		imagenobj = Sprite::create(imagenObjeto);
		Size img = imagenobj->getContentSize();
		imagenobj->setScaleX(tamañoPantalla.width / (10 * img.width));
		imagenobj->setScaleY(tamañoPantalla.height / (8 * img.height));


	}

	

}