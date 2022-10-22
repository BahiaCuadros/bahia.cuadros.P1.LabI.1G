/*
 * notebook.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"

int OrdenamientoNumericoNote (struct Notebook* pArray , int limite ,int criterio)
{
	int retorno =0;
	int flagSwap;
	struct Notebook auxiliar;
	if(pArray !=  NULL && limite>0 && (criterio == 0|| criterio ==1))
	{
		retorno =1;
		if(criterio ==1)
		{

		do
		{
			flagSwap =0;
			for(int I=0;I<limite-1;I++)
			{
				if (pArray[I].precio >pArray[I+1].precio)
				{
					flagSwap =1;
					auxiliar = pArray[I];
					pArray[I]=pArray[I+1];
					pArray[I+1]=auxiliar;

				}
			}
		}while(flagSwap);

		}
		else
		{
			do
			{
				flagSwap =0;
				for(int I=0;I<limite-1;I++)
				{
					if (pArray [I].precio<pArray[I+1].precio)
					{
						flagSwap =1;
						auxiliar = pArray[I];
						pArray[I]=pArray[I+1];
						pArray[I+1]=auxiliar;
					}
				}
			}while(flagSwap);
		}

	}
	return retorno;
}
