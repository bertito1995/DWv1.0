#include "Casilla.h"
#include "Enemigo.h"
#include "Objeto.h"


Casilla::Casilla(int id) {

	Size tamañoPantalla = Director::getInstance()->getVisibleSize();
	identificador = id;
	fija = false;
	if (id == 0)
	{
		imagenCasilla = "casillas/nivel_0.png";
		
	}

	if (id == 1)
	{
		imagenCasilla = "casillas/nivel_1.png"; 

		fija = true;

		listaPlataformas = new Objeto*[1];
		numPla = 1;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = 0;
		plataforma->posY = -0.15;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*1);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.06);

		listaPlataformas[0] = plataforma;

		

		//listaObjetos = new Objeto*[1];
		//listaEnemigos = new Enemigo*[1];
		//numObj = 1;
		//numEne = 1;


		/*Objeto *coleccionable = new Objeto(1);
		coleccionable->posX = 0.25;
		coleccionable->posY = 0.25;
		listaObjetos[0] = coleccionable;*/

		/*Enemigo *basico = new Enemigo(1);
		basico->posX = -0.25;
		basico->posY = -0.25;
		listaEnemigos[0] = basico;*/
		
	
	}

	else if (id == 2)
	{
		imagenCasilla = "casillas/nivel_2.png";


		listaPlataformas = new Objeto*[1];
		numPla = 1;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = 0;
		plataforma->posY = -0.15;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*1);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.06);

		listaPlataformas[0] = plataforma;
	
	}

	else if (id == 3)
	{
		imagenCasilla = "casillas/nivel_3.png";

		listaObjetos = new Objeto*[1];
		numObj = 1;

		Objeto *moneda = new Objeto(10);
		moneda->posX = -0.15;
		moneda->posY = 0.35;
		listaObjetos[0] = moneda;

		listaPlataformas = new Objeto*[2];
		numPla = 2;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = 0;
		plataforma->posY = -0.15;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*1);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.06);

		listaPlataformas[0] = plataforma;

		Objeto *plataforma1 = new Objeto(11);
		plataforma1->posX = 0.1;
		plataforma1->posY = 0.32;

		Size img1 = plataforma1->imagenobj->getContentSize();
		plataforma1->imagenobj->setScaleX(tamañoPantalla.width / (6 * img1.width) * 0.4);
		plataforma1->imagenobj->setScaleY(tamañoPantalla.width / (4 * img1.width)*0.02);

		listaPlataformas[1] = plataforma1;

		/*Objeto *plataforma2 = new Objeto(11);
		plataforma2->posX = 0.45;
		plataforma2->posY = 0.4;
		    
		Size img2 = plataforma2->imagenobj->getContentSize();
		plataforma2->imagenobj->setScaleX(tamañoPantalla.width / (6 * img2.width) * 0.1);
		plataforma2->imagenobj->setScaleY(tamañoPantalla.width / (4 * img2.width)*0.15);

		listaPlataformas[2] = plataforma2;*/

		/*Objeto *plataforma3 = new Objeto(11);
		plataforma3->posX = 0.4;
		plataforma3->posY = 0.32;

		Size img3 = plataforma3->imagenobj->getContentSize();
		plataforma3->imagenobj->setScaleX(tamañoPantalla.width / (6 * img3.width) * 0.1);
		plataforma3->imagenobj->setScaleY(tamañoPantalla.width / (4 * img3.width)*0.05);

		listaPlataformas[2] = plataforma3;*/

		/*Objeto *plataforma4 = new Objeto(11);
		plataforma4->posX = -0.2;
		plataforma4->posY = 0.45;

		Size img4 = plataforma4->imagenobj->getContentSize();
		plataforma4->imagenobj->setScaleX(tamañoPantalla.width / (6 * img4.width) * 0.1);
		plataforma4->imagenobj->setScaleY(tamañoPantalla.width / (4 * img4.width)*0.13);

		listaPlataformas[2] = plataforma4;*/
	}

	else if (id == 4)
	{
		imagenCasilla = "casillas/nivel_4.png";

		listaEnemigos = new Enemigo*[1];
		numEne = 1;

		Enemigo *araña = new Enemigo(2);
		araña->posX = 0;
		araña->posY = 0;
		listaEnemigos[0] = araña;


		listaPlataformas = new Objeto*[4];
		numPla = 4;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = -0.1;
		plataforma->posY = -0.15;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.85);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.06);

		listaPlataformas[0] = plataforma;

		Objeto *plataforma2 = new Objeto(11);
		plataforma2->posX = 0.45;
		plataforma2->posY = -0.4;

		Size img2 = plataforma2->imagenobj->getContentSize();
		plataforma2->imagenobj->setScaleX(tamañoPantalla.width / (6 * img2.width) *0.2);
		plataforma2->imagenobj->setScaleY(tamañoPantalla.width / (4 * img2.width)*0.06);

		listaPlataformas[1] = plataforma2;

		Objeto *plataforma3 = new Objeto(11);
		plataforma3->posX = 0.3;
		plataforma3->posY = -0.25;

		Size img3 = plataforma3->imagenobj->getContentSize();
		plataforma3->imagenobj->setScaleX(tamañoPantalla.width / (6 * img3.width) * 0.1);
		plataforma3->imagenobj->setScaleY(tamañoPantalla.width / (4 * img3.width)*0.15);

		listaPlataformas[2] = plataforma3;

		Objeto *plataforma4 = new Objeto(11);
		plataforma4->posX = -0.05;
		plataforma4->posY = 0.45;

		Size img4 = plataforma4->imagenobj->getContentSize();
		plataforma4->imagenobj->setScaleX(tamañoPantalla.width / (6 * img4.width) * 0.8);
		plataforma4->imagenobj->setScaleY(tamañoPantalla.width / (4 * img4.width)*0.02);

		listaPlataformas[3] = plataforma4;
	}

	else if (id == 5)
	{
		imagenCasilla = "casillas/nivel_5.png";


		listaPlataformas = new Objeto*[1];
		numPla = 1;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = 0;
		plataforma->posY = -0.4;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*1);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.06);

		listaPlataformas[0] = plataforma;

		listaObjetos = new Objeto*[1];
		numObj = 1;

		Objeto *mascara = new Objeto(14);
		mascara->posX = 0;
		mascara->posY = -0.3;
		listaObjetos[0] = mascara;
	}

	else if (id == 6)
	{
		imagenCasilla = "casillas/nivel_6.png";

		listaObjetos = new Objeto*[2];
		numObj = 2;

		Objeto *moneda = new Objeto(10);
		moneda->posX = 0;
		moneda->posY = -0.35;
		listaObjetos[0] = moneda;

		Objeto *caja = new Objeto(12);
		caja->posX = 0;
		caja->posY = 0;
		listaObjetos[1] = caja;


		listaPlataformas = new Objeto*[1];
		numPla = 1;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = 0;
		plataforma->posY = -0.4;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*1);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.06);

		listaPlataformas[0] = plataforma;
	}

	else if (id == 7)
	{
		imagenCasilla = "casillas/nivel_7.png";

		listaPlataformas = new Objeto*[1];
		numPla = 1;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = 0.4;
		plataforma->posY = -0.2;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width) * 0.3);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.06);

		listaPlataformas[0] = plataforma;

		listaObjetos = new Objeto*[1];
		numObj = 1;

		Objeto *escalera = new Objeto(15);
		Size img2 = escalera->imagenobj->getContentSize();
		escalera->imagenobj->setScaleX(tamañoPantalla.width / (6 * img2.width) * 0.15);
		escalera->imagenobj->setScaleY(tamañoPantalla.width / (4 * img2.width)*0.4);
		escalera->posX = 0.35;
		escalera->posY = 0.2;
		listaObjetos[0] = escalera;
	}

	else if (id == 8)
	{
		imagenCasilla = "casillas/nivel_8.png";


		listaPlataformas = new Objeto*[1];
		numPla = 1;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = 0;
		plataforma->posY = -0.2;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*1);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.06);

		listaPlataformas[0] = plataforma;
	}

	else if (id == 9)
	{
		imagenCasilla = "casillas/nivel_9.png";

		listaObjetos = new Objeto*[1];
		numObj = 1;

		Objeto *puente = new Objeto(7);
		puente->posX = 0.12;
		puente->posY = -0.38;
		listaObjetos[0] = puente;


		listaPlataformas = new Objeto*[1];
		numPla = 1;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = -0.35;
		plataforma->posY =-0.2;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.38);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.06);

		listaPlataformas[0] = plataforma;

		/*Objeto *plataforma2 = new Objeto(11);
		plataforma2->posX = -0.20;
		plataforma2->posY = -0.30;

		Size img2 = plataforma2->imagenobj->getContentSize();
		plataforma2->imagenobj->setScaleX(tamañoPantalla.width / (6 * img2.width)*0.1);
		plataforma2->imagenobj->setScaleY(tamañoPantalla.width / (4 * img2.width)*0.15);

		listaPlataformas[1] = plataforma2;*/



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

		listaObjetos = new Objeto*[1];
		numObj = 1;

		Objeto *puerta = new Objeto(9);
		puerta->posX = 0.055;
		puerta->posY = -0.14;
		listaObjetos[0] = puerta;
	}

	else if (id == 13)
	{
		imagenCasilla = "casillas/nivel_13.png";

		listaEnemigos = new Enemigo*[1];
		numEne = 1;

		Enemigo *araña = new Enemigo(1);
		araña->posX = -0.4;
		araña->posY = 0.4;
		listaEnemigos[0] = araña;


		listaPlataformas = new Objeto*[1];
		numPla = 1;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = -0.2;
		plataforma->posY = 0.28;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.76);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.02);

		listaPlataformas[0] = plataforma;

		listaObjetos = new Objeto*[1];
		numObj = 1;

		Objeto *escalera = new Objeto(15);
		Size img2 = escalera->imagenobj->getContentSize();
		escalera->imagenobj->setScaleX(tamañoPantalla.width / (6 * img2.width) * 0.15);
		escalera->imagenobj->setScaleY(tamañoPantalla.width / (4 * img2.width)*0.7);
		escalera->posX = 0.35;
		escalera->posY = -0.1;
		listaObjetos[0] = escalera;
	}

	else if (id == 14)
	{
		imagenCasilla = "casillas/nivel_14.png";

		listaEnemigos = new Enemigo*[1];
		numEne = 1;

		Enemigo *abeja = new Enemigo(5);
		abeja->posX = 0.25;
		abeja->posY = 0.2;
		listaEnemigos[0] = abeja;


		listaPlataformas = new Objeto*[1];
		numPla = 1;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = 0.35;
		plataforma->posY = 0.30;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.55);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.02);

		listaPlataformas[0] = plataforma;
	}

	else if (id == 15)
	{
		imagenCasilla = "casillas/nivel_15.png";


		listaPlataformas = new Objeto*[2];
		numPla = 2;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX =-0.35;
		plataforma->posY = 0.30;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.40);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.02);

		listaPlataformas[0] = plataforma;

		Objeto *plataforma2 = new Objeto(11);
		plataforma2->posX = 0.2;
		plataforma2->posY = -0.25;

		Size img2 = plataforma2->imagenobj->getContentSize();
		plataforma2->imagenobj->setScaleX(tamañoPantalla.width / (6 * img2.width)*0.85);
		plataforma2->imagenobj->setScaleY(tamañoPantalla.width / (4 * img2.width)*0.02);

		listaPlataformas[1] = plataforma2;
	}

	else if (id == 16)
	{
		imagenCasilla = "casillas/nivel_16.png";

		listaEnemigos = new Enemigo*[1];
		numEne = 1;

		Enemigo *abeja = new Enemigo(5);
		abeja->posX = -0.25;
		abeja->posY = -0.4;
		listaEnemigos[0] = abeja;

		listaObjetos = new Objeto*[1];
		numObj = 1;


		Objeto *seta = new Objeto(3);
		seta->posX = -0.15;
		seta->posY = -0.08;
		listaObjetos[0] = seta;

		listaPlataformas = new Objeto*[1];
		numPla = 1;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = -0.35;
		plataforma->posY = -0.25;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.7);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.02);

		listaPlataformas[0] = plataforma;
	}

	else if (id == 17)
	{
		imagenCasilla = "casillas/nivel_17.png";

		listaObjetos = new Objeto*[2];
		numObj = 2;


		Objeto *hierba = new Objeto(6);
		hierba->posX = -0.25;
		hierba->posY = -0.2;
		listaObjetos[0] = hierba;

		Objeto *puente = new Objeto(8);
		puente->posX = 0.0;
		puente->posY = 0.4;
		listaObjetos[1] = puente;

		listaPlataformas = new Objeto*[2];
		numPla =2;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = 0.3;
		plataforma->posY = 0.3;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.4);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.02);

		listaPlataformas[0] = plataforma;

		Objeto *plataforma2 = new Objeto(11);
		plataforma2->posX = -0.25;
		plataforma2->posY = -0.1;

		Size img2 = plataforma2->imagenobj->getContentSize();
		plataforma2->imagenobj->setScaleX(tamañoPantalla.width / (6 * img2.width)*0.6);
		plataforma2->imagenobj->setScaleY(tamañoPantalla.width / (4 * img2.width)*0.02);

		listaPlataformas[1] = plataforma2;
	}

	else if (id == 18)
	{
		imagenCasilla = "casillas/nivel_18.png";

		listaEnemigos = new Enemigo*[2];
		numEne = 2;

		Enemigo *basico = new Enemigo(4);
		basico->posX = 0.3;
		basico->posY = 0.3;
		listaEnemigos[0] = basico;

		Enemigo *lagarto = new Enemigo(6);
		lagarto->posX = 0.3;
		lagarto->posY = 0;
		listaEnemigos[1] = lagarto;

		listaPlataformas = new Objeto*[1];
		numPla = 1;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = 0;
		plataforma->posY = 0.3;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*1);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.02);

		listaPlataformas[0] = plataforma;

		
	}


	else if (id == 19)
	{
		imagenCasilla = "casillas/nivel_19.png";

		listaObjetos = new Objeto*[1];
		numObj = 1;


		Objeto *pajaro = new Objeto(2);
		pajaro->posX = -0.05;
		pajaro->posY = -0.1;
		listaObjetos[0] = pajaro;


	}

	else if (id == 20)
	{
		imagenCasilla = "casillas/nivel_20.png";

		fija = true;

		listaObjetos = new Objeto*[2];
		numObj = 2;

		Objeto *moneda = new Objeto(10);
		moneda->posX = -0.35;
		moneda->posY = -0.35;
		listaObjetos[0] = moneda;

		Objeto *columpio = new Objeto(13);
		columpio->posX = -0.35;
		columpio->posY = -0.2;
		listaObjetos[1] = columpio;

		/*listaPlataformas = new Objeto*[1];
		numPla = 1;*/

		/*Objeto *plataforma = new Objeto(11);
		plataforma->posX = 0.45;
		plataforma->posY = -0.25;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.35);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.02);

		listaPlataformas[0] = plataforma;*/

		/*Objeto *plataform2 = new Objeto(11);
		plataform2->posX = -0.38;
		plataform2->posY = -0.5;

		Size img2 = plataform2->imagenobj->getContentSize();
		plataform2->imagenobj->setScaleX(tamañoPantalla.width / (6 * img2.width)*0.15);
		plataform2->imagenobj->setScaleY(tamañoPantalla.width / (4 * img2.width)*0.02);

		listaPlataformas[0] = plataform2;*/
	}

	else if (id == 21)
	{
		imagenCasilla = "casillas/nivel_21.png";

		listaEnemigos = new Enemigo*[1];
		numEne = 1;

		Enemigo *basico = new Enemigo(3);
		basico->posX = -0.4;
		basico->posY = -0.3;
		listaEnemigos[0] = basico;

		/*listaPlataformas = new Objeto*[1];
		numPla = 1;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = 0;
		plataforma->posY = -0.35;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*1);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.02);

		listaPlataformas[0] = plataforma;*/
	}

	else if (id == 22)
	{
		imagenCasilla = "casillas/nivel_22.png";

		listaObjetos = new Objeto*[1];
		numObj = 1;

		Objeto *moneda = new Objeto(10);
		moneda->posX = 0.1;
		moneda->posY = -0.2;
		listaObjetos[0] = moneda;

		/*listaPlataformas = new Objeto*[5];
		numPla = 5;

		Objeto *plataforma = new Objeto(11);
		plataforma->posX = -0.25;
		plataforma->posY = -0.25;

		Size img = plataforma->imagenobj->getContentSize();
		plataforma->imagenobj->setScaleX(tamañoPantalla.width / (6 * img.width)*0.7);
		plataforma->imagenobj->setScaleY(tamañoPantalla.width / (4 * img.width)*0.02);

		listaPlataformas[0] = plataforma;

		Objeto *plataforma2 = new Objeto(11);
		plataforma2->posX = 0;
		plataforma2->posY = 0;

		Size img2 = plataforma2->imagenobj->getContentSize();
		plataforma2->imagenobj->setScaleX(tamañoPantalla.width / (6 * img2.width)*0.4);
		plataforma2->imagenobj->setScaleY(tamañoPantalla.width / (4 * img2.width)*0.02);

		listaPlataformas[1] = plataforma2;

		Objeto *plataforma3 = new Objeto(11);
		plataforma3->posX = 0.2;
		plataforma3->posY = 0.2;

		Size img3 = plataforma3->imagenobj->getContentSize();
		plataforma3->imagenobj->setScaleX(tamañoPantalla.width / (6 * img3.width)*0.6);
		plataforma3->imagenobj->setScaleY(tamañoPantalla.width / (4 * img3.width)*0.02);

		listaPlataformas[2] = plataforma3;

		Objeto *plataforma4 = new Objeto(11);
		plataforma4->posX = -0.3;
		plataforma4->posY = 0;

		Size img4 = plataforma4->imagenobj->getContentSize();
		plataforma4->imagenobj->setScaleX(tamañoPantalla.width / (6 * img4.width)*0.1);
		plataforma4->imagenobj->setScaleY(tamañoPantalla.width / (4 * img4.width)*0.1);

		listaPlataformas[3] = plataforma4;

		Objeto *plataforma5 = new Objeto(11);
		plataforma5->posX = 0.1;
		plataforma5->posY = -0.1;

		Size img5 = plataforma5->imagenobj->getContentSize();
		plataforma5->imagenobj->setScaleX(tamañoPantalla.width / (6 * img5.width)*0.1);
		plataforma5->imagenobj->setScaleY(tamañoPantalla.width / (4 * img5.width)*0.05);

		listaPlataformas[4] = plataforma5;*/

	}

	else if (id == 23)
	{
		imagenCasilla = "casillas/nivel_23.png";

		listaObjetos = new Objeto*[1];
		numObj = 1;


		Objeto *nube = new Objeto(4);
		nube->posX = -0.1;
		nube->posY = -0.1;
		listaObjetos[0] = nube;

		
	}

	else if (id == 24)
	{
		imagenCasilla = "casillas/nivel_24.png";

		listaObjetos = new Objeto*[2];
		//listaEnemigos = new Enemigo*[1];
		numObj = 2;
		//numEne = 1;
	

		Objeto *nube = new Objeto(5);
		nube->posX = -0.4;
		nube->posY = -0.05;
		listaObjetos[0] = nube;

		Objeto *moneda = new Objeto(10);
		moneda->posX = -0.35;
		moneda->posY = 0;
		listaObjetos[1] = moneda;

		/*Enemigo *basico = new Enemigo(2);
		basico->posX = -0.25;
		basico->posY = -0.25;
		listaEnemigos[0] = basico;*/
		



		
	}

	imagencas = Sprite::create(imagenCasilla);
	//escalar(imagencas);


}



void Casilla::escalarPlataforma(Sprite *imagen)
{
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();

	
   
	Size img = imagen->getContentSize();
	imagen->setScaleX(tamañoPantalla.width / (6 * img.width));
	imagen->setScaleY(tamañoPantalla.height / (4 * img.height));
}

void Casilla::escalarPuzzle(Sprite *imagen)
{
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();



	Size img = imagen->getContentSize();
	imagen->setScaleX(tamañoPantalla.width / (9 * img.width));
	imagen->setScaleY(tamañoPantalla.height / (7 * img.height));
}

void Casilla::escalarVector(Sprite *imagen)
{
	Size tamañoPantalla = Director::getInstance()->getVisibleSize();



	Size img = imagen->getContentSize();
	imagen->setScaleX(tamañoPantalla.width / (17 * img.width));
	imagen->setScaleY(tamañoPantalla.height / (12 * img.height));
}


