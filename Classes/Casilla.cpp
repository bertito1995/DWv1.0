#include "Casilla.h"
#include "Enemigo.h"
#include "Objeto.h"


Casilla::Casilla(int id) {

	Size tamañoPantalla = Director::getInstance()->getVisibleSize();
	
	

	if (id == 1)
	{
		imagenCasilla = "provisional/cas1.jpg"; 

		//listaObjetos = new Objeto*[1];
		listaEnemigos = new Enemigo*[1];
		//numObj = 1;
		numEne = 1;


		/*Objeto *coleccionable = new Objeto(1);
		coleccionable->posX = 0.25;
		coleccionable->posY = 0.25;
		listaObjetos[0] = coleccionable;*/

		Enemigo *basico = new Enemigo(1);
		basico->posX = -0.25;
		basico->posY = -0.25;
		listaEnemigos[0] = basico;
		
	
	}

	else if (id == 2)
	{
		imagenCasilla = "provisional/cas2.jpg";
	
	}

	else if (id == 3)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 4)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 5)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 6)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 7)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 8)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 9)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 10)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 11)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 12)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 13)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 14)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 15)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 16)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 17)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 18)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 19)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 20)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 21)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 22)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 23)
	{
		imagenCasilla = "provisional/cas2.jpg";
	}

	else if (id == 24)
	{
		imagenCasilla = "provisional/cas2.jpg";

		listaObjetos = new Objeto*[1];
		listaEnemigos = new Enemigo*[1];
		numObj = 1;
		numEne = 1;
	

		Objeto *coleccionable = new Objeto(1);
		coleccionable->posX = 0.25;
		coleccionable->posY = 0.25;
		listaObjetos[0] = coleccionable;

		Enemigo *basico = new Enemigo(2);
		basico->posX = -0.25;
		basico->posY = -0.25;
		listaEnemigos[0] = basico;
		



		
	}

	imagencas = Sprite::create(imagenCasilla);
	escalar(imagencas);


}



void Casilla::escalar(Sprite *imagen)
{
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();

	
   
	Size img = imagen->getContentSize();
	imagen->setScaleX(tamañoPantalla.width / (6 * img.width));
	imagen->setScaleY(tamañoPantalla.height / (4 * img.height));
}


