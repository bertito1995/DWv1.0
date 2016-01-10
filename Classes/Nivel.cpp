#include "Nivel.h"
#include "Casilla.h"


Nivel::Nivel(int n)
{
	MatrizInicial = new Casilla*[24];
	MatrizJugador = new Casilla*[24];
	MatrizCorrecta = new Casilla*[24];
	VecCasillas = new Casilla*[22];
	
	puntuacion = new bool*[3];

	if (n == 1)
	{
		LongVec = 22;
		LongMat = 24;

		for (int i = 0; i < 24; i++)
		{
			if (i == 0 || i == 17)
			{
				Casilla *cas = new Casilla(i + 1);
				MatrizInicial[i] = cas;
			}
			else
			{
				Casilla *cas = new Casilla(0);
				MatrizInicial[i] = cas;
				
			}
			Casilla *jug = new Casilla(0);
			MatrizJugador[i] = jug;

			Casilla *cor = new Casilla(i + 1);
			MatrizCorrecta[i] = cor;
			
		}

		for (int j = 0; j < 22; j++)
		{
			if (j < 16)
			{
				Casilla *cas = new Casilla(0);
				VecCasillas[j] = cas;
			}
			else
			{
				Casilla *cas = new Casilla(0);
				VecCasillas[j] = cas;
			}
		}

		for (int k = 0; k < 3; k++)
		{
			puntuacion[k] = false;
		}
		
	}
}