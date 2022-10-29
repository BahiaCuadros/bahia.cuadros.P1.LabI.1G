/*
 * informes.c
 *
 *  Created on: 28 oct. 2022
 *      Author: Bahia
 */
#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"

#include "utnIngresodeDatos.h"
#include "utn.ordenamiento.h"
void ImprimirporMarca( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente)
{
	char Marcaelegido[20];
		int auxposiconMarca=-1;
		while(auxposiconMarca==-1)
		{
			getPalabra ("\n¿Que marca de computadoras desea ver?","\nERROR vuelva a intentar", 2, Marcaelegido,20);
			auxposiconMarca=	BuscadordeMarcaXDescripcion ( arrayMarca,Marcaelegido,contadorMarca);
				if(auxposiconMarca==-1)
				{
					printf("\nTipo no encontrado");
				}
		}



			{
			 for(int i=0;i <contadorNote;i++)
			 {
				 if(arrayMarca[auxposiconMarca].id==arrayNotebook[i].idMarca)
				 {
					 imprimirNotebook (arrayMarca,  arrayNotebook[i],  arrayTipo, contadorMarca, contadorNote, contadorTipo, arrayCliente,contadorCliente);
				 }
			 }
			}
}
void ImprimirporTipo( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente)
{
	char Tipoelegido[20];
		int auxposiconTipo=-1;
		while(auxposiconTipo==-1)
		{
			getPalabra ("\n¿Que tipo de computadoras desea ver?","\nERROR vuelva a intentar", 2, Tipoelegido,20);
			auxposiconTipo=	buscarTipoXDescripcion ( arrayTipo,Tipoelegido,contadorTipo);
				if(auxposiconTipo==-1)
				{
					printf("\nTipo no encontrado");
				}
		}



			{
			 for(int i=0;i <contadorNote;i++)
			 {
				 if(arrayTipo[auxposiconTipo].id==arrayNotebook[i].idTipo)
				 {
					 imprimirNotebook (arrayMarca,  arrayNotebook[i],  arrayTipo, contadorMarca, contadorNote, contadorTipo, arrayCliente,contadorCliente);
				 }
			 }
			}
}
void NotebookmasBaratas( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente)
{
	imprimirArrayOrdenado( arrayMarca,  arrayNotebook, arrayTipo, contadorMarca,  contadorNote, contadorTipo, arrayCliente, contadorCliente);
}
void NotebookporMarca ( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente)
{
	for (int i=0;i<contadorMarca;i++)
	{
		imprimirMarca(arrayMarca[i]);
		for(int x = 0;x<contadorNote;x++)
		{
			if(arrayNotebook[x].idMarca==arrayMarca[i].id)
			{
				imprimirNotebook ( arrayMarca,  arrayNotebook[x], arrayTipo,  contadorMarca,  contadorNote, contadorTipo, arrayCliente,  contadorCliente);
			}
		}
	}
}
void cantidadporMarcayTipo(Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente)
{
	char Marcaelegido[20];
	char Tipoelegido[20];
	int contadorMarcas=0;
	int contadorTipos=0;
	int auxposiconMarca;
	int auxposiconTipo;
	getPalabra ("\n¿Que Marca de computadoras desea calcular?","\nERROR vuelva a intentar", 2, Marcaelegido,20);
	auxposiconMarca=	BuscadordeMarcaXDescripcion ( arrayMarca,Marcaelegido,contadorMarca);
	getPalabra ("\n¿Que tipo de computadoras desea calcular?","\nERROR vuelva a intentar", 2, Tipoelegido,20);
	auxposiconTipo=	buscarTipoXDescripcion ( arrayTipo,Tipoelegido,contadorTipo);
	for(int  i=0;i<contadorNote;i++)
	{
		if(arrayMarca[auxposiconMarca].id==arrayNotebook[i].idMarca)
		{
			contadorMarcas++;
		}
		if(arrayTipo[auxposiconTipo].id==arrayNotebook[i].idTipo)
		{
			contadorTipos++;
		}
	}
	imprimirMarca(arrayMarca[auxposiconMarca]);
	printf("\nTiene %d computadoras cargadas",contadorMarcas);
	imprimirtipo(arrayTipo[auxposiconTipo]);
	printf("\nTiene %d computadoras cargadas",contadorTipos);

}
void marcaMasElegida(Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente)
{
	int contadorMarcas;
	int marcamasElegida;
	int posicionMarcamasElegida;
	int banderaprimerMarca=0;
for(int x=0;x< contadorMarcas;x++)
{
	for(int  i=0;i<contadorNote;i++)
		{
			if(arrayMarca[x].id==arrayNotebook[i].idMarca)
			{
				contadorMarcas++;
			}
		}
	if(banderaprimerMarca==0||marcamasElegida<contadorMarcas)
	{
		marcamasElegida=contadorMarcas;
		posicionMarcamasElegida=x;
				banderaprimerMarca=1;
	}
	printf("La marca mas elegida es:");
	imprimirMarca(arrayMarca[posicionMarcamasElegida]);
}

}
