/*
 * eCliente.c
 *
 *  Created on: 28 oct. 2022
 *      Author: Bahia
 */


#include <string.h>
#include "eCliente.h"

int buscardorClienteporNombre(Cliente *pArray, char* descripcion, int Limite)
{
	if(Limite>0)
	{
	for (int i=0; i<Limite;i++)
	{
		if (strcmp(pArray[i].Nombre,descripcion)==0)
		{
			return i;
		}
	}
	}
	return -1;
}

int BuscadeClienteXID( Cliente* pArray, int ID, int Limite)
{
	{
		for (int i=0; i<Limite;i++)
		{
			if (pArray[i].id==ID)
			{
				return i;
			}
		}
		return -1;
	}
}

void HarcodeoCliente(Cliente* clientefinal,int id,char* sexo, char* nombre)
{
	strcpy(clientefinal->Nombre,nombre);
	clientefinal->id=id;
	strcpy(clientefinal->sexo,sexo);

}
