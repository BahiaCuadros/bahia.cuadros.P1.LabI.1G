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
#include "ecliente.h"
#include "utnIngresodeDatos.h"
#include "utn.ordenamiento.h"
/*
BRIEF: Da de alta un dato tipo  Notebook.
PARAM:  array tipo MArca, espacio de memoria para guardar el nuevo dato, array tipo Tipo, cantidad de elementos Marca, cantidad de elementos Notebook, cantidad de elementos Tipo.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int AltaNotebook ( Marca *arrayMarca,  Notebook *auxNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente*arrayCLientes, int contadorCliente)
{
	char auxMarca[20];
	int auxposicionMarca= -1;
	char auxTipo[20];
	int auxposicionTipo= -1;
	char auxNombre[20];
	int auxposicionCliente=-1;
	 Notebook auxiliar;

	if(contadorMarca>=0 && contadorNote>=0 && contadorTipo >=0)
	{
		auxiliar.id=3000+contadorNote;
		getAlfaNumerica ("\nIngrese modelo de la notebook","\n Solo puede utilizar letras y numeros", 5,auxiliar.modelo,20);
		getNumeroD ("\n ingrese precio de la notebook: $","Utilice solo numeros y hasta un punto", 0, 9999, 5, &auxiliar.precio);
		while(auxposicionMarca ==-1)
		{
		getAlfaNumerica ("\nIngrese el nombre de la Marca","\nPor favor utilice solo letras y numeros", 5, auxMarca,20);
		auxposicionMarca=BuscadordeMarcaXDescripcion (arrayMarca, auxMarca, contadorMarca);
		if (auxposicionMarca==-1)
		{
			printf("Marca no encontrada");
		}
		}
		if(auxposicionMarca>=0)
		{
			auxiliar.idMarca=arrayMarca[auxposicionMarca].id;
		}

		while(auxposicionTipo ==-1)
		{
		getAlfaNumerica ("\nIngrese el Tipo de computadora","\nPor favor utilice solo letras y numeros", 5, auxTipo,20);
		auxposicionTipo=buscarTipoXDescripcion (arrayTipo, auxTipo, contadorTipo);
		if (auxposicionTipo==-1)
		{
			printf("Tipo de computadora no encontrado");
		}
		}
		if(auxposicionTipo>=0)
		{
			auxiliar.idTipo=arrayTipo[auxposicionTipo].id;
		}
		*auxNotebook=auxiliar;
		return 1;
		while(auxposicionCliente==-1)
		{
		getPalabra ("\nIngrese el nombre del Cliente ","\nERROR:\t utilice solo letras", 5,auxNombre,20);
		auxposicionCliente= buscarClienteporNombre ( arrayCLientes,auxNombre,  contadorCliente);
		if(auxposicionCliente==-1)
		{
			printf("\nCliente no encontrado");
		}
		}
		auxiliar.idCliente=arrayCLientes[auxposicionCliente].id;
	}
	return -1;
}
/*
BRIEF: Copia un array del tipo de dato Notebook.
PARAM:  primer parametro: array a copiar, segundo parametro array donde se va a copiar, tercer paramtro, tamaño del primer array ocupado.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int Copiararray ( Notebook* arrayParacopiar,  Notebook* arrayFinal,int tamano)
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
BRIEF: Ordena un array del tipo de dato MARCA por orden numerico.
PARAM:  primer parametro: Array a ordenar, tamaño del primer array ocupado,criterio 1 creciente, 0 decreciente.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int OrdenamientoNumericoNote ( Notebook* pArray , int limite ,int criterio)
{
	int retorno =0;
	int flagSwap;
	 Notebook auxiliar;
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
/*
BRIEF: Imprime un array del tipo de dato Notebook.
PARAM:  array tipo MArca, array a imprimir tipo Notebook, array tipo Tipo, cantidad de elementos Marca, cantidad de elementos Notebook, cantidad de elementos Tipo.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int imprimirArrayNote ( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente)
{
	if( contadorNote > 0&&contadorTipo>0 && contadorMarca>0)
	{
		for (int i = 0 ; i< contadorNote ; i++)
		{
			imprimirNotebook (arrayMarca,   arrayNotebook[i], arrayTipo, contadorMarca,  contadorNote, contadorTipo, arrayCliente,  contadorCliente);
		}
		return 1;
	}
	return -1;
}
/*
BRIEF: Imprime un dato del tipo de dato MARCA.
PARAM:  array tipo MArca, variable a imprimir tipo Notebook, array tipo Tipo, cantidad de elementos Marca, cantidad de elementos Notebook, cantidad de elementos Tipo.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int imprimirNotebook ( Marca *arrayMarca,  Notebook Notebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente)
{
	int auxposicionMarca;
	int auxposicionCliente;
	int auxposicionTipo;
	if( contadorNote > 0&&contadorTipo>0 && contadorMarca>0)
	{
			auxposicionCliente= BuscadeClienteXID( arrayCliente, Notebook.idCliente,contadorCliente);
			auxposicionTipo=BuscadordeTipoXID (arrayTipo, Notebook.idTipo , contadorTipo);
			auxposicionMarca=BuscadordeMarcaXID(arrayMarca,Notebook.idMarca,contadorMarca);
			printf("\nID:%d\nModelo de la NOTEBOOK: %s\nTipo de NOTEBOOK:%s\nMarca:%s\nPrecio: :$%.2f\nCliente: %s",
					Notebook.id,Notebook.modelo,arrayTipo[auxposicionTipo].descripcion,arrayMarca[auxposicionMarca].descripcion,Notebook.precio,arrayCliente[auxposicionCliente].Nombre);
		return 1;
	}
	return -1;
}
/*
BRIEF: Busca en un array del tipo de dato MARCA, un elementro en particular, por ID.
PARAM:  primer parametro: array donde buscar, segundo parametro un numero de ID para buscar, tercer paramtro, tamaño del primer array ocupado.
RETURN: Retorna el espacio de memoria en el que esta ocupado, si no se encuentra retorna  -1 .
 */
int BuscadordeNotebookXID ( Notebook* pArray, int ID, int Limite)
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
BRIEF: Busca en un array del tipo de dato Notebook, un elementro en particular, por DESCRIPCION.
PARAM:  primer parametro: array donde buscar, segundo parametro texto para buscar, tercer paramtro, tamaño del primer array ocupado.
RETURN: Retorna el espacio de memoria en el que esta ocupado, si no se encuentra retorna  -1 .
 */
int buscarNotebookXModelo ( Notebook *pArray, char* descripcion, int Limite)
{
	if(Limite>0)
	{
	for (int i=0; i<Limite;i++)
	{
		if (strcmp(pArray[i].modelo,descripcion)==0)
		{
			return i;
		}
	}
	}
	return -1;
}
/*
BRIEF: Modifica precio o tipo de un dato tipo Notebook, en un array.
PARAM:  array tipo MArca, array en donde buscar tipo Notebook, array tipo Tipo, cantidad de elementos Marca, cantidad de elementos Notebook, cantidad de elementos Tipo.
RETURN: si todos lo parametros estasn bien retorna 1 .
 */
int ModificarNotebook ( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente*arrayCliente,int contadorCliente)
{
	char auxModelo[20];
	int auxPosicionNotebook=-1;
	int Confirmacion=2;
	int menu=3;
	int auxposicionTipo=-1;
	char auxTipo[20];
	if(contadorMarca>=0 && contadorNote>=0 && contadorTipo >=0)
		{
		while(Confirmacion==2)
		{

		while(auxPosicionNotebook==-1)
		{	getAlfaNumerica ("\nIngrese modelo de la notebook","\n Solo puede utilizar letras y numeros", 5,auxModelo,20);
			auxPosicionNotebook=buscarNotebookXModelo(arrayNotebook,auxModelo,contadorNote);
			if(auxPosicionNotebook==-1)
			{
				printf("\nModelo no encontrado");
			}
		}
		printf("\n El modelo que desea modificar es:\n");
		imprimirNotebook (arrayMarca, arrayNotebook[auxPosicionNotebook], arrayTipo,contadorMarca,  contadorNote, contadorTipo,arrayCliente,contadorCliente);
		getNumeroE ("\n 1) SI\n 2) NO","\nERROR\n 1) SI\n 2) NO", 1, 2, 5, &Confirmacion);
		}
		getNumeroE ("\nModificar\n 1)Precio\n 2) Tipo\n 3)Volver al menu anterior","\nERROR\nModificar 1)Tipo \n 2) Precio\n 3)Volver al menu anterior", 1, 3, 5, &menu);
		switch(menu)
		{
		case 1:
			getNumeroD ("\nIngrese nuevo precio :$","\nPor favor utilice solo numeros y hasta un punto", 0, 999999, 5, &arrayNotebook[auxPosicionNotebook].precio);

			break;
		case 2:
			while(auxposicionTipo ==-1)
					{
					getAlfaNumerica ("\nIngrese el Tipo de computadora","\nPor favor utilice solo letras y numeros", 5, auxTipo,20);
					auxposicionTipo=buscarTipoXDescripcion (arrayTipo, auxTipo, contadorTipo);
					if (auxposicionTipo==-1)
					{
						printf("Tipo de computadora no encontrado");
					}
					}
					if(auxposicionTipo>=0)
					{
						arrayNotebook[auxPosicionNotebook].idTipo=arrayTipo[auxposicionTipo].id;
					}
					break;
		case 3:
			return -1;
		}
		return 1;
		}
	return -1;
}
int BajaNotebook( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente)
{

	int id=-1;
	int memoriaNotebook;
	if(contadorNote>0&&contadorTipo>0&&contadorMarca>0)
	{
		while(memoriaNotebook==-1)
		{
		getNumeroE("ingrese ID de la Notebook que desea dar de baja","\nERROR\ningrese ID de la Notebook que desea dar de baja,usando solo numeros", 3000, 4000, 5,&id);
		memoriaNotebook=BuscadordeNotebookXID (arrayNotebook, id, contadorNote);
		if(memoriaNotebook==-1)
		{
			printf("\nNotebook no encontrada, por favor vuelva a ingresar:");
		}
		}
		printf("La siguiente marca fue dada de Baja:");
		arrayNotebook[memoriaNotebook].isEmpty=0;
		imprimirNotebook (arrayMarca, arrayNotebook[memoriaNotebook],arrayTipo, contadorMarca,contadorNote, contadorTipo,arrayCliente,contadorCliente);
		return 1;
	}
	return -1;
}
void imprimirArrayOrdenado( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente)
{
	Notebook arrayOrdenado[50];
	Copiararray(arrayOrdenado,arrayNotebook,contadorNote);
	OrdenamientoNumericoNote(arrayOrdenado,contadorNote,0);
	imprimirArrayNote( arrayMarca, arrayOrdenado,  arrayTipo, contadorMarca,  contadorNote,contadorTipo,arrayCliente, contadorCliente);
}
void Hardcodeo(Notebook* NoteFinal,int id,char modelo[20],int idCliente,int idMarca,int idTipo,float precio)
{
	NoteFinal->id=id;
	NoteFinal->idCliente=idCliente;
	NoteFinal->idMarca=idMarca;
	NoteFinal->idTipo=idTipo;
	NoteFinal->isEmpty=1;
	strcpy(NoteFinal->modelo,modelo);
	NoteFinal->precio=precio;
}
