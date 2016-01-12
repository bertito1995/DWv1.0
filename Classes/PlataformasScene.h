#ifndef __PLATAFORMAS_SCENE_H__
#define __PLATAFORMAS_SCENE_H__


#include "cocos2d.h"
#include "Enemigo.h"
#include "Casilla.h"
#include "Objeto.h"
#include "PuzzleEscena.h"
#include "FinEscena.h"

USING_NS_CC;
using namespace std;

const int VELOCIDADPRIN = 3;
const float FSALTOPRINCESA = 230;
const float FGRAVEDAD = 300;

const int FRAMESCORRER = 14;
const float FRCORRER = 0.07f;
const int FRAMESESCALAR = 42;
const float FRESCALAR = 0.07f;
const float FRMONEDA = 0.01f;
const int FRAMESMONEDA = 60;
const float FRFANTASMA = 0.1f;
const int FRAMESFANTASMA = 68;
const float FRMASCARA = 0.2f;
const float FRHIERBA = 0.01f;
const float FRENEMIGOS = 0.1f;

//***** y = v*sen(alpha)*t -1/2gt^2

class PlataformasScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene(int * a);
	
	Vector <Sprite*> correrPrincesaR;
	Vector <Sprite*> correrPrincesaL;
	Vector <Sprite*> escalarPrincesaR;
	Vector <Sprite*> escalarPrincesaL;
	Vector <Sprite*> animacionMoneda;
	Vector <Sprite*> animacionAbeja;
	int contAnimacionEscalar;
	float TimerEscalar; 
	int contAnimacionMoneda;
	float TimerMoneda;
	Vector <Sprite*> animacionFantasma;
	int contAnimacionFantasma;
	float TimerFantasma;
	int fantasmaAnimado;
	int mascaraAnimada;
	float TimerMascara;
	float TimerHierba;
	Sprite *princesa;
	float TimerEnemigos;
	Enemigo **enemigosAcabados;
	float TimerEnemigosVerticales;
	//Enemigo **enemigos;
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

	



	//Objeto *objeto;
//=======
	//Sprite **imagenEnemigos;
	//Vector <Sprite*> plataformas;
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
	bool pausa;
	int contMonedas;
	bool movPlataforma;
	int maximoHierba;
	float contadorHierba;
	bool SPresionada;
	bool movArbol;

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
	bool PlataformaEntre(Sprite*, Sprite*);
	bool colisionSoloPlataformaArriba();
	Sprite* ColisionPlataformas(Sprite*);

	//reiniciar nivel

	void reiniciarNivel();
	void volverPuzzle();
	void finJuego();

	//ordenar escena
	void ordenar(Sprite ***);

	//eliminar punteros
	void eliminarPunteros();
    
    // implement the "static create()" method manually
	CREATE_FUNC(PlataformasScene);
};

#endif
