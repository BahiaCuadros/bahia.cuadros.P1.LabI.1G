/*
 * marca.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"
#include "utnIngresodeDatos.h"
#include "utn.ordenamiento.h"
/*
BRIEF: Copia un array del tipo de dato MARCA.
PARAM:  primer parametro: array a copiar, segundo parametro array donde se va a copiar, tercer paramtro, tamaño del primer array ocupado.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int CopiararrayMarca ( Marca* arrayParacopiar,  Marca* arrayFinal,int tamano)

{
	if (arrayParacopiar!=NULL && tamano > 0)
	{
		for (int i = 0 ; i < tamano ;i ++)
		{
			arrayFinal[i]= arrayParacopiar[i];
		}
		return 1;
	}
	return 0;
}
/*
BRIEF: Ordena un array del tipo de dato MARCA por orden alfabetico.
PARAM:  primer parametro: Array a ordenar, tamaño del primer array ocupado.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int OrdenamientoAlfabeticoMarca ( Marca* pArray , int limite)
{
	 Marca auxiliar;
	if(pArray !=  NULL && limite>0 )
	{
		for ( int i = 0; i< limite - 1; i++)
		{
			for (int j = i +1 ; j < limite ; j ++)
			{
				 if ((strcmp(pArray[i].descripcion,pArray[j].descripcion))>0)
						 {
					 	 auxiliar =pArray[i];
					 	 pArray[i]=pArray[j];
					 	 pArray[j]=auxiliar;
						 }
			}
		}
		return 1;
	}
	return -1;
}
/*
BRIEF: Imprime un array del tipo de dato MARCA.
PARAM:  primer parametro: array a imprimir, tamaño del primer array ocupado.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int imprimirArrayMarca ( Marca* pArray , int limite)
{
	if(pArray != NULL && limite > 0)
	{
		for (int i = 0 ; i< limite ; i++)
		{
			printf ("\n Marca: %d\n Id: %d\n Nombre de la marca: %s",i,pArray[i].id,pArray[i].descripcion);
		}
		return 1;
	}
	return -1;
}
void imprimirMarca(Marca Marcaimprimir)
{
	printf ("\n Id: %d\n Nombre de la marca: %s",Marcaimprimir.id,Marcaimprimir.descripcion);
}
/*
BRIEF: Busca en un array del tipo de dato MARCA, un elementro en particular, por DESCRIPCION.
PARAM:  primer parametro: array donde buscar, segundo parametro texto para buscar, tercer paramtro, tamaño del primer array ocupado.
RETURN: Retorna el espacio de memoria en el que esta ocupado, si no se encuentra retorna  -1 .
 */
int BuscadordeMarcaXDescripcion ( Marca * pArray, char* modelo, int Limite)
{
	for (int i=0; i<Limite;i++)
	{
		if (strcmp(pArray[i].descripcion,modelo)==0)
		{
			return i;
		}
	}
	return -1;
}
/*
BRIEF: Busca en un array del tipo de dato MARCA, un elementro en particular, por ID.
PARAM:  primer parametro: array donde buscar, segundo parametro N de ID para buscar, tercer paramtro, tamaño del primer array ocupado.
RETURN: Retorna el espacio de memoria en el que esta ocupado, si no se encuentra retorna  -1 .
 */
int BuscadordeMarcaXID ( Marca* pArray, int ID, int Limite)
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
/*
BRIEF: Alta de una marca.
PARAM:  primer parametro estructura tipo Marca donde se va a guardar la nueva carga, segundo parametro contador de marcas actual.
RETURN:  si todo sale bien retorna 1, sino   -1 .
 */
int AltadeMarca ( Marca* final,int Contador)
{
	if(Contador >=0)
	{
	char auxMarca[20];
	getAlfaNumerica ("\nPor favor ingrese el nombre de la marca","\nPor favor utilice solo letras y numeros", 20, auxMarca, 20);
	strcpy (final->descripcion,auxMarca);
	final->id=1000+Contador;
	return 1;
	}
	return -1;
}
