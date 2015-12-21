#ifndef __PLATAFORMAS_SCENE_H__
#define __PLATAFORMAS_SCENE_H__


#include "cocos2d.h"
#include "Enemigo.h"
#include "Casilla.h"
#include "Objeto.h"
#include "PuzzleEscena.h"

USING_NS_CC;
using namespace std;

const int VELOCIDADPRIN = 3;
const float FSALTOPRINCESA = 230;
const float FGRAVEDAD = 300;

const int FRAMESCORRER = 14;
const float FRCORRER = 0.07f;

//***** y = v*sen(alpha)*t -1/2gt^2

class PlataformasScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene(int * a);
	
	Vector <Sprite*> correrPrincesaR;
	Vector <Sprite*> correrPrincesaL;
	Sprite *princesa;
	Enemigo **enemigos;
//<<<<<<< HEAD
	//Sprite **imagenEnemigos;

	Casilla **casillas;
	//Sprite **imagenCasillas;
	//char **imagenprueba;

	Sprite **listaPlatform;
	int numeroP = 0;
	int contPlat = 0;

	Objeto **listaObj;
	int numeroO = 0;
	int contObj = 0;


    Enemigo **listaEnem;
	int numeroE = 0;
	int contEnem =0 ;

	



	Objeto *objeto;
//=======
	//Sprite **imagenEnemigos;
	Vector <Sprite*> plataformas;
//>>>>>>> 67d8f5992ea5ba74dbc4eeca5d86741cea0b6144

	float tiempoSalto = 0;
	float contadoCorrer = 0;
	int indiceCorrer = 1;

	EventKeyboard::KeyCode teclaPresioanda;
	bool prinMovL;
	bool prinMovR;
	bool prinSalto;
	bool prinDerecha;
	bool prinCae;
	bool prinMovSalto;
	bool prinMovArriba;
	bool prinMovAbajo;
	int prinPosIniSalto;
	bool prinEscaleras;
	Vec2 prinPos;
	Vec2 prinPosAnt;

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	//teclas
	void teclaPresionada(EventKeyboard::KeyCode idTecla, Event *evento);
	void teclaLevantada(EventKeyboard::KeyCode idTecla, Event *evento);
	
	void update(float dt);

	//colision

	bool colision(Sprite*, Sprite*); 
	bool colisionPlataformas(Sprite*);
	bool colisionEscaleras(Sprite*);
	Sprite* ColisionPlataformas(Sprite*);

	//reiniciar nivel

	void reiniciarNivel();
	void volverPuzzle();

	//ordenar escena
	void ordenar(Sprite ***);
    
    // implement the "static create()" method manually
	CREATE_FUNC(PlataformasScene);
};

#endif
