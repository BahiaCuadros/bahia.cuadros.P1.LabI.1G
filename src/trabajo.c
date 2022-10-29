/*
 * trabajo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"
#include "utnIngresodeDatos.h"
#include "utn.ordenamiento.h"

int altaTrabajo( Notebook *arrayNotebook,int contNote, Servicio *arrayServicio,int contServ,  Trabajo *auxiliarTrabajo,int conTra)
{
char auxModelo[20];
char auxServicio[20];
int memoriaModelo=-1;
int memoriaServicio=-1;
 Fecha auxFecha;
auxiliarTrabajo->id=6000+conTra;
if (arrayNotebook!=NULL && arrayServicio != NULL )
{
	while(memoriaModelo==-1)
	{
	getAlfaNumerica ("\n Por favor ingrese el Modelo de notebook","\n ERROR: Por favor ingrese el Modelo de notebook", 5, auxModelo, 20);
	memoriaModelo=buscarNotebookXModelo (arrayNotebook,  auxModelo, contNote);
	if (memoriaModelo==-1)
	{
		printf("modelo no encontrado");
	}
	}
	auxiliarTrabajo->idNotebook=arrayNotebook[memoriaModelo].id;
	while(memoriaServicio==-1)
	{
	getAlfaNumerica ("\n Por favor ingrese el Servicio de notebook","\n ERROR: Por favor ingrese el Servicio de notebook", 5,auxServicio, 20);
	memoriaServicio=buscarServicioXDescripcion (arrayServicio, auxServicio, contServ);
	if(memoriaServicio==-1)
	{
		printf("Servicio no encontrado");
	}
	}
	auxiliarTrabajo->idServicio=arrayServicio[memoriaServicio].id;
	ingresarFecha(&auxFecha);
	auxiliarTrabajo->fecha=auxFecha;
	return 1;
}
return -1;
}

int listarTrabajo ( Notebook *arrayNotebook,int contNote, Servicio *arrayServicio,int contServ,  Trabajo *arrayTrabajo,int conTra)
{
	int memoriaServicio;
	int memoriaModelo;
	if(arrayNotebook !=NULL && contNote>0 && arrayServicio !=NULL && contServ>0 && arrayTrabajo != NULL && conTra >0)
	{
		for(int x=0;x<conTra;x++)
		{
			memoriaModelo=BuscadordeNotebookXID (arrayNotebook, arrayTrabajo[x].idNotebook, contNote);
			memoriaServicio=BuscadordeSerivicioXID (arrayServicio,arrayTrabajo[x].idServicio , contServ);
			printf("\n Tipo de trabajo %s\n Computadora: %s",arrayServicio[memoriaServicio].descripcion,arrayNotebook[memoriaModelo].modelo);
			imprimirFecha(arrayTrabajo[x].fecha);
		}
	}
	return -1;
}
