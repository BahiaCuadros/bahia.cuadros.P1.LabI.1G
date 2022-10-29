/*
 * tipo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"
#include "utnIngresodeDatos.h"
#include "utn.ordenamiento.h"
/*
BRIEF: Copia un array del tipo de dato Tipo.
PARAM:  primer parametro: array a copiar, segundo parametro array donde se va a copiar, tercer paramtro, tamaño del primer array ocupado.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int CopiararrayTipo ( Tipo* arrayParacopiar,  Tipo* arrayFinal,int tamano)
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
BRIEF: Ordena un array del tipo de dato Tipo por orden alfabetico.
PARAM:  primer parametro: Array a ordenar, tamaño del primer array ocupado.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int OrdenamientoAlfabeticoTipo ( Tipo* pArray , int limite )
{

	 Tipo auxiliar;
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
	return 0;
}
/*
BRIEF: Imprime un array del tipo de dato Tipo.
PARAM:  primer parametro: array a imprimir, tamaño del primer array ocupado.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int imprimirArrayTipo ( Tipo* pArray , int limite)
{
	if(pArray != NULL && limite > 0)
	{
		for (int i = 0 ; i< limite ; i++)
		{
			printf ("\n Tipo: %d\n Id: %d\n Tipo de computadora : %s",i,pArray[i].id,pArray[i].descripcion);
		}
		return 1;
	}
	return -1;
}
void imprimirtipo(Tipo Tipoimpreso)
{
	printf ("\n Id: %d\n Tipo de computadora : %s",Tipoimpreso.id,Tipoimpreso.descripcion);
}
/*
BRIEF: Busca en un array del tipo de dato Tipo, un elementro en particular, por DESCRIPCION.
PARAM:  primer parametro: array donde buscar, segundo parametro texto para buscar, tercer paramtro, tamaño del primer array ocupado.
RETURN: Retorna el espacio de memoria en el que esta ocupado, si no se encuentra retorna  -1 .
 */
int buscarTipoXDescripcion ( Tipo *pArray, char* descripcion, int Limite)
{
	for (int i=0; i<Limite;i++)
	{
		if (strcmp(pArray[i].descripcion,descripcion)==0)
		{
			return i;
		}
	}
	return -1;
}
/*
BRIEF: Busca en un array del tipo de dato Tipo, un elementro en particular, por ID.
PARAM:  primer parametro: array donde buscar, segundo parametro N de ID para buscar, tercer paramtro, tamaño del primer array ocupado.
RETURN: Retorna el espacio de memoria en el que esta ocupado, si no se encuentra retorna  -1 .
 */
int BuscadordeTipoXID ( Tipo* pArray, int ID, int Limite)
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
BRIEF: Alta de una tipo.
PARAM:  primer parametro estructura tipo Tipo donde se va a guardar la nueva carga, segundo parametro contador de tipo actual.
RETURN:  si todo sale bien retorna 1, sino   -1 .
 */
int AltadeTipo ( Tipo* final,int Contador)
{
	if(Contador >=0)
	{
	char auxTipo[20];
	getPalabra ("\nPor favor ingrese el Tipo de computadora","\nPor favor utilice solo letras y numeros", 20, auxTipo, 20);
	strcpy (final->descripcion,auxTipo);
	final->id=5000+Contador;
	return 1;
	}
	return -1;
}
