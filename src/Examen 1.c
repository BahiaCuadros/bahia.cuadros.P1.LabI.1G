/*
 ============================================================================
 Name        : Examen.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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

int main(void) {
	setbuf(stdout,NULL);
char opcionMenu;
int auxID;
struct Notebook auxNotebook;
struct Notebook auxNotebookordenadoporPrecio[50];
struct Fecha arrayFecha[50];
struct Marca arrayMarca[50];
struct Tipo arrayTipo[50];
struct Notebook arrayNotebook[50];
struct Servicio arrayServicio[50];
struct Trabajo arrayTrabajo[50];
char auxMarca[20];
int contadorNote=0;
int contadorMarca=0;
int contadorTipo=0;
int contadorServicio=0;
int contadorTrabajo=0;
int validacion=0;
char auxTipo [20];
int auxId;
int subMenuB;
int banderaAux;
arrayMarca[contadorMarca].id=1000+contadorMarca;
strcpy(arrayMarca[contadorMarca].descripcion,"Compaq");
contadorMarca++;
arrayMarca[contadorMarca].id=1000+contadorMarca;
strcpy(arrayMarca[contadorMarca].descripcion,"Asus");
contadorMarca++;
arrayMarca[contadorMarca].id=1000+contadorMarca;
strcpy(arrayMarca[contadorMarca].descripcion,"Acer");
contadorMarca++;
arrayMarca[contadorMarca].id=1000+contadorMarca;
strcpy(arrayMarca[contadorMarca].descripcion,"HP");
contadorMarca++;
arrayTipo[contadorTipo].id=5000+contadorTipo;
strcpy(arrayTipo[contadorTipo].descripcion,"Gamer");
contadorTipo++;
arrayTipo[contadorTipo].id=5000+contadorTipo;
strcpy(arrayTipo[contadorTipo].descripcion,"Disenio");
contadorTipo++;
arrayTipo[contadorTipo].id=5000+contadorTipo;
strcpy(arrayTipo[contadorTipo].descripcion,"Ultrabook");
contadorTipo++;
arrayTipo[contadorTipo].id=5000+contadorTipo;
strcpy(arrayTipo[contadorTipo].descripcion,"Normalita");
contadorTipo++;
arrayServicio[contadorServicio].id=2000+contadorServicio;
arrayServicio[contadorServicio].precio=2250;
strcpy(arrayServicio[contadorServicio].descripcion,"Bateria");
contadorServicio++;
arrayServicio[contadorServicio].id=2000+contadorServicio;
arrayServicio[contadorServicio].precio=10300;
strcpy(arrayServicio[contadorServicio].descripcion,"Display");
contadorServicio++;
arrayServicio[contadorServicio].id=2000+contadorServicio;
arrayServicio[contadorServicio].precio=4400;
strcpy(arrayServicio[contadorServicio].descripcion,"Teclado");
contadorServicio++;
arrayServicio[contadorServicio].id=2000+contadorServicio;
arrayServicio[contadorServicio].precio=5600;
strcpy(arrayServicio[contadorServicio].descripcion,"Fuente");
contadorServicio++;

while(opcionMenu!='I')
{
	printf("\n A: ALTA NOTEBOOK \n B: MODIFICAR NOTEBOOK \n C:BAJA NOTEBOOK \n D:LISTAR NOTEBOOK \n E: LISTAR MARCAS \n F: LISTAR TIPOS \n G: LISTAR SERVICIOS \n H: ALTA TRABAJO \n I: LISTAR TRABAJOS \n J:SALIR");
	getPalabra ("\n ingresar letra corrrespondiente a la opcion deseada"," \n ERROR ingresar letra corrrespondiente a la opcion deseada", 5, &opcionMenu,3);
	switch (opcionMenu)
	{
	case 'A':

		auxNotebook.id= 5000+contadorNote;
		getAlfaNumerica ("\n Ingrese Modelo de Notebook","\n ERROR max 20 caracteres de tipo letra y numero", 5,auxNotebook.modelo ,20);
		while (validacion == 0)
		{
		getAlfaNumerica ("\n Ingrese Marca de Notebook","\n ERROR max 20 caracteres de tipo letra y numero", 5,auxMarca ,20);
		for (int i = 0 ; i < contadorMarca ; i++)
		{
			if(strcmp(arrayMarca[i].descripcion,auxMarca)== 0)
			{
				validacion = 1;
				auxNotebook.idMarca=arrayMarca[i].id;
				break;
			}
		}
		printf("\nMarca no encontrada");
		}
		validacion =0 ;
		while(validacion == 0)
		{
				getAlfaNumerica ("\n Ingrese Tipo de Notebook","\n ERROR max 20 caracteres de tipo: letra y numero", 5,auxTipo ,20);
				for (int i = 0 ; i < contadorMarca ; i++)
				{
					if(strcmp(arrayTipo[i].descripcion,auxTipo)== 0)
					{
						validacion = 1;
						auxNotebook.idTipo=arrayTipo[i].id;
						break;
					}
				}
				printf("\nTipo no encontrado");
		}



		getNumeroD ("\n Ingrese Precio por favor: $","\n ERROR Por favor ingrese precio utilizando solo numeros y UN solo punto", 0, 100000000, 5, &auxNotebook.precio);
		auxNotebook.isEmpty=1;
		arrayNotebook[contadorNote]=auxNotebook;
		contadorNote++;
		break;
	case 'B':
		getNumeroE ("\n Ingrese numero de ID del Modelo que desea modificar, por favor","\n ERROR : Ingrese numero de ID del Modelo que desea modificar, por favor", 5000, 9999, 5, &auxId);
		for(int x=0; x<contadorNote; x++)
		{
			if(arrayNotebook[x].id==auxId)
			{
				printf("\n 1: Modificar precio\n 2: Modificar tipo");
				getNumeroE ("\n Ingrese numero de la opcion que desea modificar, por favor","\n ERROR : Ingrese numero de la opcion que desea modificar, por favor", 0,2, 5, &subMenuB);
				switch (subMenuB)
				{
				case 1:
					getNumeroD ("\n Ingrese el nuevo precio por favor: $","\n ERROR Por favor ingrese precio utilizando solo numeros y UN solo punto", 0,2, 5, &arrayNotebook[x].precio);
					break;
				case 2:
					validacion =0 ;
					while(validacion == 0)
					{
							getAlfaNumerica ("\n Ingrese Tipo de Notebook","\n ERROR max 20 caracteres de tipo: letra y numero", 5,auxTipo ,20);
							for (int i = 0 ; i < contadorMarca ; i++)
							{
								if(strcmp(arrayTipo[i].descripcion,auxTipo)== 0)
								{
									validacion = 1;
									arrayNotebook[x].idTipo=arrayTipo[i].id;
									break;
								}
							}
							printf("\nTipo no encontrado");
					}
					break;
				}
			break;
			}
		}
		printf("Elemento invalido");
		break;
	case 'C':
		banderaAux=0;
		getNumeroE ("\n Ingrese numero de ID del Modelo que desea dar de baja","\n ERROR : Ingrese numero de ID del Modelo que desea dar de baja", 5000, 9999, 5, &auxId);
		for(int x=0; x<contadorNote; x++)
		{
			if(arrayNotebook[x].id==auxId)
					{
				arrayNotebook[x].isEmpty=0;
				printf("El modelo %s a sido dado de baja", arrayNotebook[x].modelo);
				banderaAux=1;
				break;
					}
		}
		if(banderaAux==0)
		{
			printf("Elemento no encontrado");
		}
		break;
	case 'D':
		OrdenamientoNumericoNote (auxNotebookordenadoporPrecio, contadorNote ,1);
		for(int c=0;c<contadorNote;c++)
			printf("\n %s",auxNotebookordenadoporPrecio[c].modelo);
		break;
	case 'E':
		for(int e=0;e<contadorMarca;e++)
					printf("\n %s",arrayMarca[e].descripcion);
		break;
	case 'F':
		for(int f=0;f<contadorTipo;f++)
					printf("\n %s",arrayTipo[f].descripcion);
		break;
	case 'G':
		for(int g=0;g<contadorServicio;g++)
					printf("\n %s",arrayServicio[g].descripcion);
		break;
	case 'H':
		altaTrabajo(arrayNotebook,contadorNote,arrayServicio,contadorServicio, arrayTrabajo,contadorTrabajo);
		contadorTrabajo++;
		break;
	case 'I':

		break;
	}

}
}


