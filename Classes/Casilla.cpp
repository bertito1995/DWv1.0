#include "Casilla.h"
#include "Enemigo.h"
#include "Objeto.h"


Casilla::Casilla(int id) {

	Size tamañoPantalla = Director::getInstance()->getVisibleSize();
	
	

	if (id == 1)
	{
		imagenCasilla = "casillas/nivel_1.png"; 

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
		imagenCasilla = "casillas/nivel_2.png";
	
	}

	else if (id == 3)
	{
		imagenCasilla = "casillas/nivel_3.png";

		listaObjetos = new Objeto*[1];
		numObj = 1;

		Objeto *moneda = new Objeto(10);
		moneda->posX = -0.5;
		moneda->posY = -0.5;
		listaObjetos[0] = moneda;
	}

	else if (id == 4)
	{
		imagenCasilla = "casillas/nivel_4.png";
	}

	else if (id == 5)
	{
		imagenCasilla = "casillas/nivel_5.png";
	}

	else if (id == 6)
	{
		imagenCasilla = "casillas/nivel_6.png";

		listaObjetos = new Objeto*[2];
		numObj = 2;

		Objeto *moneda = new Objeto(10);
		moneda->posX = -0.5;
		moneda->posY = -0.5;
		listaObjetos[0] = moneda;

		Objeto *caja = new Objeto(12);
		caja->posX = 0;
		caja->posY = 0;
		listaObjetos[1] = caja;
	}

	else if (id == 7)
	{
		imagenCasilla = "casillas/nivel_7.png";
	}

	else if (id == 8)
	{
		imagenCasilla = "casillas/nivel_8.png";
	}

	else if (id == 9)
	{
		imagenCasilla = "casillas/nivel_9.png";

		listaObjetos = new Objeto*[1];
		numObj = 1;


		Objeto *puente = new Objeto(7);
		puente->posX = 1;
		puente->posY = -0.25;
		listaObjetos[0] = puente;
	}

	else if (id == 10)
	{
		imagenCasilla = "casillas/nivel_10.png";
	}

	else if (id == 11)
	{
		imagenCasilla = "casillas/nivel_11.png";
	}

	else if (id == 12)
	{
		imagenCasilla = "casillas/nivel_12.png";
	}

	else if (id == 13)
	{
		imagenCasilla = "casillas/nivel_13.png";
	}

	else if (id == 14)
	{
		imagenCasilla = "casillas/nivel_14.png";

		listaEnemigos = new Enemigo*[1];
		numEne = 1;

		Enemigo *abeja = new Enemigo(5);
		abeja->posX = 0.25;
		abeja->posY = 0.25;
		listaEnemigos[0] = abeja;
	}

	else if (id == 15)
	{
		imagenCasilla = "casillas/nivel_15.png";
	}

	else if (id == 16)
	{
		imagenCasilla = "casillas/nivel_16.png";

		listaEnemigos = new Enemigo*[1];
		numEne = 1;

		Enemigo *abeja = new Enemigo(5);
		abeja->posX = -0.25;
		abeja->posY = -0.25;
		listaEnemigos[0] = abeja;

		listaObjetos = new Objeto*[1];
		numObj = 1;


		Objeto *seta = new Objeto(3);
		seta->posX = 0.25;
		seta->posY = 0.25;
		listaObjetos[0] = seta;
	}

	else if (id == 17)
	{
		imagenCasilla = "casillas/nivel_17.png";

		listaObjetos = new Objeto*[2];
		numObj = 2;


		Objeto *hierba = new Objeto(6);
		hierba->posX = -0.25;
		hierba->posY = -0.25;
		listaObjetos[0] = hierba;

		Objeto *puente = new Objeto(8);
		puente->posX = 0.5;
		puente->posY = 0.5;
		listaObjetos[1] = puente;
	}

	else if (id == 18)
	{
		imagenCasilla = "casillas/nivel_18.png";

		listaEnemigos = new Enemigo*[2];
		numEne = 2;

		Enemigo *basico = new Enemigo(4);
		basico->posX = 0.25;
		basico->posY = 0.25;
		listaEnemigos[0] = basico;

		Enemigo *lagarto = new Enemigo(6);
		lagarto->posX = 0.25;
		lagarto->posY = 0.25;
		listaEnemigos[1] = lagarto;

		listaObjetos = new Objeto*[1];
		numObj = 1;

		Objeto *puerta = new Objeto(9);
		puerta->posX = 0.5;
		puerta->posY = 0.5;
		listaObjetos[0] = puerta;
	}


	else if (id == 19)
	{
		imagenCasilla = "casillas/nivel_19.png";

		listaObjetos = new Objeto*[1];
		numObj = 1;


		Objeto *pajaro = new Objeto(2);
		pajaro->posX = 0.25;
		pajaro->posY = 0.25;
		listaObjetos[0] = pajaro;
	}

	else if (id == 20)
	{
		imagenCasilla = "casillas/nivel_20.png";

		listaObjetos = new Objeto*[2];
		numObj = 2;

		Objeto *moneda = new Objeto(10);
		moneda->posX = -0.5;
		moneda->posY = -0.5;
		listaObjetos[0] = moneda;

		Objeto *columpio = new Objeto(13);
		columpio->posX = -0.25;
		columpio->posY = 0;
		listaObjetos[1] = columpio;
	}

	else if (id == 21)
	{
		imagenCasilla = "casillas/nivel_21.png";

		listaEnemigos = new Enemigo*[1];
		numEne = 1;

		Enemigo *basico = new Enemigo(3);
		basico->posX = -0.25;
		basico->posY = -0.25;
		listaEnemigos[0] = basico;
	}

	else if (id == 22)
	{
		imagenCasilla = "casillas/nivel_22.png";

		listaObjetos = new Objeto*[1];
		numObj = 1;

		Objeto *moneda = new Objeto(10);
		moneda->posX = -0.5;
		moneda->posY = -0.5;
		listaObjetos[0] = moneda;
	}

	else if (id == 23)
	{
		imagenCasilla = "casillas/nivel_23.png";

		listaObjetos = new Objeto*[2];
		numObj = 2;


		Objeto *nube = new Objeto(4);
		nube->posX = -0.5;
		nube->posY = -0.5;
		listaObjetos[0] = nube;

		Objeto *moneda = new Objeto(10);
		moneda->posX = -0.5;
		moneda->posY = -0.5;
		listaObjetos[1] = moneda;
	}

	else if (id == 24)
	{
		imagenCasilla = "casillas/nivel_24.png";

		listaObjetos = new Objeto*[1];
		listaEnemigos = new Enemigo*[1];
		numObj = 1;
		numEne = 1;
	

		Objeto *nube = new Objeto(5);
		nube->posX = -0.25;
		nube->posY = -0.25;
		listaObjetos[0] = nube;

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


