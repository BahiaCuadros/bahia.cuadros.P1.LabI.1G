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
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"
#include "utnIngresodeDatos.h"
#include "utn.ordenamiento.h"

int altaTrabajo(struct Notebook arrayNotebook[50],int contNote,struct Servicio arrayServicio[50],int contServ, struct Trabajo arrayTrabajo[50],int conTra)
{
int retorno = 0 ;
char auxModelo[20];
char auxServicio[20];
struct Fecha auxFecha;
arrayTrabajo[conTra].id=6000+conTra;
if (arrayNotebook!=NULL && arrayServicio != NULL && arrayTrabajo != NULL )
{
	getAlfaNumerica ("\n Por favor ingrese el Modelo de notebook","\n ERROR: Por favor ingrese el Modelo de notebook", 5, &auxModelo, 20);
	for(int i=0;i<contNote;i++)
	{
		if(strcmp(arrayNotebook[i].modelo,auxModelo)==0)
		{
			arrayTrabajo[conTra].idNotebook=arrayNotebook[i].id;
		}

	}
	getAlfaNumerica ("\n Por favor ingrese el Servicio de notebook","\n ERROR: Por favor ingrese el Servicio de notebook", 5, &auxServicio, 20);
		for(int i=0;i<contServ;i++)
		{
			if(strcmp(arrayServicio[i].descripcion,auxServicio)==0)
			{
				arrayTrabajo[conTra].idServicio=arrayServicio[i].id;
			}

		}
}
	ingresarFecha(&auxFecha);
	arrayTrabajo[conTra].fecha=auxFecha;
}

int listarTrabajo (struct Notebook arrayNotebook[50],int contNote,struct Servicio arrayServicio[50],int contServ, struct Trabajo arrayTrabajo[50],int conTra)
{
	for (int a=0;a<conTra; a++)
	{
		for(int b = 0; b <contNote; b++)
		{
			if (arrayNotebook[b].id==arrayTrabajo[a].idNotebook)
			{
				printf("\n Modelo de computadora: %s",arrayNotebook[b].modelo);
			}
		}
		for(int b = 0; b <contServ; b++)
				{
					if (arrayServicio[b].id==arrayTrabajo[a].idServicio)
					{
						printf("\n Modelo de computadora: %s",arrayServicio[b].descripcion);
						printf("\El precio es: $%f",arrayServicio[b].precio);
					}
				}
		printf("\n Fecha: %d-%d-%d",arrayTrabajo[a].fecha.dia,arrayTrabajo[a].fecha.mes,arrayTrabajo[a].fecha.anioo);
	}
}
