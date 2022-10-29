/*
 * servicio.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"
#include "utnIngresodeDatos.h"
#include "utn.ordenamiento.h"
/*
BRIEF: Copia un array del tipo de dato Servicio.
PARAM:  primer parametro: array a copiar, segundo parametro array donde se va a copiar, tercer paramtro, tamaño del primer array ocupado.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int CopiararrayServicio ( Servicio* arrayParacopiar,  Servicio* arrayFinal,int tamano)
{

	if (arrayParacopiar!=NULL && tamano > 0)
	{
			printf("\n %s", arrayParacopiar[0].descripcion);
		for (int i = 0 ; i < tamano ;i ++)
		{
			arrayFinal[i]= arrayParacopiar[i];
		}
		return 1;
	}

	return 0;
}
/*
BRIEF: Ordena un array del tipo de dato Servicio por orden alfabetico.
PARAM:  primer parametro: Array a ordenar, tamaño del primer array ocupado.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int OrdenamientoAlfabeticoServicio ( Servicio* pArray , int limite )
{

	 Servicio auxiliar;
	if(pArray !=  NULL && limite>0 )
	{
		for ( int i = 0; i< limite - 1; i++)
		{
			for (int j = i +1 ; j < limite ; j ++)
			{
				 if (strcmp(pArray[i].descripcion,pArray[j].descripcion)>0)
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
BRIEF: Imprime un array del tipo de dato Servicio.
PARAM:  primer parametro: array a imprimir, tamaño del primer array ocupado.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int imprimirArrayServicio ( Servicio* pArray , int limite)
{
	if(pArray != NULL && limite > 0)
	{
		for (int i = 0 ; i< limite ; i++)
		{
			printf ("\n Servicio: %d \n Id: %d \n Tipo de servicio : %s \n Precio: %.2f",i,pArray[i].id,pArray[i].descripcion,pArray[i].precio);
		}
		return 1;
	}
	return -1;
}
/*
BRIEF: Busca en un array del tipo de dato Servicio, un elementro en particular, por DESCRIPCION.
PARAM:  primer parametro: array donde buscar, segundo parametro texto para buscar, tercer paramtro, tamaño del primer array ocupado.
RETURN: Retorna el espacio de memoria en el que esta ocupado, si no se encuentra retorna  -1 .
 */
int buscarServicioXDescripcion ( Servicio *pArray, char* descripcion, int Limite)
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
BRIEF: Busca en un array del tipo de dato Servicio, un elementro en particular, por ID.
PARAM:  primer parametro: array donde buscar, segundo parametro N de ID para buscar, tercer paramtro, tamaño del primer array ocupado.
RETURN: Retorna el espacio de memoria en el que esta ocupado, si no se encuentra retorna  -1 .
 */
int BuscadordeSerivicioXID ( Servicio* pArray, int ID, int Limite)
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
BRIEF: Alta de una Servicio.
PARAM:  primer parametro estructura tipo Servicio donde se va a guardar la nueva carga, segundo parametro contador de Servicio actual.
RETURN:  si todo sale bien retorna 1, sino   -1 .
 */
int AltadeServicio ( Servicio* final,int Contador)
{
	if(Contador >=0)
	{
	float auxPrecio;
	char auxServicio[20];
	getPalabra ("\nPor favor ingrese nombre del servicio","\nPor favor utilice solo letras y numeros", 20, auxServicio, 20);
	strcpy (final->descripcion,auxServicio);
	final->id=2000+Contador;
	getNumeroD ("\n Ingrese precio del servicio por favor : $","\nPor favor utilice solo numeros y hasta un punto",0, 999999, 5, &auxPrecio);
	final->precio=auxPrecio;
	return 1;
	}
	return -1;
}
