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
#include "fecha.h"
#include "informes.h"
#include "eCliente.h"
#include "utnIngresodeDatos.h"
#include "utn.ordenamiento.h"
int main(void) {
setbuf(stdout,NULL);
char opcionMenu;
 Notebook auxNotebook;
 Notebook auxNotebookordenadoporPrecio[50];
 Marca arrayMarca[50];
 Tipo arrayTipo[50];
 Notebook arrayNotebook[50];
 Servicio arrayServicio[50];
 Trabajo arrayTrabajo[50];
 Marca auxMarcaordenadoporNombre[50];
 Tipo auxTipoodenadoporNombre[50];
 Servicio auxServicioordenadoNombre[50];
 Trabajo auxiliarTrabajo;
 Cliente arrayCliente[50];
int contadorCliente=0;
int contadorNote=0;
int contadorMarca=0;
int contadorTipo=0;
int contadorServicio=0;
int contadorTrabajo=0;
int menuJ;

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

HarcodeoCliente(&arrayCliente[contadorCliente],100+contadorCliente,"mujer", "Esteban");
contadorCliente++;
HarcodeoCliente(&arrayCliente[contadorCliente],100+contadorCliente,"mujer", "Maria");
contadorCliente++;
HarcodeoCliente(&arrayCliente[contadorCliente],100+contadorCliente,"mujer", "Carla");
contadorCliente++;
HarcodeoCliente(&arrayCliente[contadorCliente],100+contadorCliente,"mujer", "Gladis");
contadorCliente++;
HarcodeoCliente(&arrayCliente[contadorCliente],100+contadorCliente,"mujer", "Bahia");
contadorCliente++;
HarcodeoCliente(&arrayCliente[contadorCliente],100+contadorCliente,"mujer", "Jorge");
contadorCliente++;


Hardcodeo(&arrayNotebook[contadorNote], 3000+contadorNote,"x120", arrayCliente[1].id, arrayMarca[0].id, arrayTipo[0].id, 500);
contadorNote++;
Hardcodeo(&arrayNotebook[contadorNote],  3000+contadorNote, "f50",  arrayCliente[3].id, arrayMarca[1].id,  arrayTipo[0].id, 100);
contadorNote++;
Hardcodeo(&arrayNotebook[contadorNote],  3000+contadorNote, "ba50",  arrayCliente[4].id, arrayMarca[2].id,  arrayTipo[0].id, 5000);
contadorNote++;
Hardcodeo(&arrayNotebook[contadorNote],  3000+contadorNote, "l000",  arrayCliente[0].id, arrayMarca[0].id,  arrayTipo[0].id, 200);
contadorNote++;
Hardcodeo(&arrayNotebook[contadorNote],  3000+contadorNote, "ss200",  arrayCliente[2].id, arrayMarca[1].id,  arrayTipo[0].id, 150);
contadorNote++;
Hardcodeo(&arrayNotebook[contadorNote],  3000+contadorNote, "tre999",  arrayCliente[6].id,  arrayMarca[1].id,  arrayTipo[0].id, 120);
 contadorNote++;
while(opcionMenu!='K')
{
	printf("\n\nA:ALTA NOTEBOOK \nB:MODIFICAR NOTEBOOK \nC:BAJA NOTEBOOK \nD:LISTAR NOTEBOOK \nE:LISTAR MARCAS \nF:LISTAR TIPOS \nG:LISTAR SERVICIOS \nH:ALTA TRABAJO \nI:LISTAR TRABAJOS \nJ:Listas\nK:SALIR");
	getPalabra ("\n ingresar letra corrrespondiente a la opcion deseada"," \n ERROR ingresar letra corrrespondiente a la opcion deseada", 5, &opcionMenu,3);
	switch (opcionMenu)
	{
	case 'A':
		AltaNotebook (arrayMarca, &auxNotebook, arrayTipo,contadorMarca, contadorNote,contadorTipo,arrayCliente,contadorCliente);
		arrayNotebook[contadorNote]=auxNotebook;
		contadorNote++;
		break;
	case 'B':
		if(contadorNote>0)
		{
		imprimirArrayNote ( arrayMarca,  arrayNotebook, arrayTipo,  contadorMarca,  contadorNote, contadorTipo,arrayCliente,contadorCliente);
		ModificarNotebook(arrayMarca, arrayNotebook, arrayTipo, contadorMarca,contadorNote, contadorTipo,arrayCliente,contadorCliente);
		}
		else
		{
			printf("\n\nNo hay notebook cargadas por el momento");
		}
		break;
	case 'C':
		if(contadorNote>0)
		{
		imprimirArrayNote ( arrayMarca,  arrayNotebook, arrayTipo,  contadorMarca,  contadorNote, contadorTipo,arrayCliente,contadorCliente);
		BajaNotebook(arrayMarca, arrayNotebook,arrayTipo, contadorMarca,contadorNote, contadorTipo,arrayCliente,contadorCliente);
		}
		else
		{
			printf("\n\nNo hay notebook cargadas por el momento");
		}
		break;
	case 'D':
		if(contadorNote>0)
		{
		Copiararray (arrayNotebook, auxNotebookordenadoporPrecio,contadorNote);
		OrdenamientoNumericoNote (auxNotebookordenadoporPrecio, contadorNote ,1);
		imprimirArrayNote (arrayMarca,arrayNotebook,arrayTipo, contadorMarca, contadorNote, contadorTipo,arrayCliente,contadorCliente);
		}
		else
		{
			printf("\n\nNo hay notebook cargadas por el momento");
		}
		break;
	case 'E':
		if(contadorMarca>0)
		{
		CopiararrayMarca (arrayMarca,auxMarcaordenadoporNombre,contadorMarca);
		OrdenamientoAlfabeticoMarca (auxMarcaordenadoporNombre,contadorMarca);
		imprimirArrayMarca(auxMarcaordenadoporNombre,contadorMarca);
		}
		else
		{
			printf("\n\nNo hay marcas cargadas por el momento");
		}
		break;
	case 'F':
		if(contadorTipo>0)
		{
		CopiararrayTipo (arrayTipo, auxTipoodenadoporNombre,contadorTipo);
		OrdenamientoAlfabeticoTipo (auxTipoodenadoporNombre, contadorTipo );
		imprimirArrayTipo(auxTipoodenadoporNombre,contadorTipo);

		}
		else
		{
			printf("\n\nNo hay Tipos cargadas por el momento");
		}
		break;
	case 'G':
		if(contadorServicio>0)
		{
		CopiararrayServicio (arrayServicio, auxServicioordenadoNombre,contadorServicio);
		OrdenamientoAlfabeticoServicio (auxServicioordenadoNombre, contadorServicio);
		imprimirArrayServicio (auxServicioordenadoNombre, contadorServicio);

		}
		else
		{
			printf("\n\nNo hay Servicios cargadas por el momento");
		}
		break;
	case 'H':
		if(contadorTrabajo>0)
		{
		altaTrabajo(arrayNotebook,contadorNote,arrayServicio,contadorServicio, &auxiliarTrabajo,contadorTrabajo);
		arrayTrabajo[contadorTrabajo]=auxiliarTrabajo;
		contadorTrabajo++;
		}
		else
		{
			printf("\n\nNo hay Trabajos cargadas por el momento");
		}
		break;
	case 'I':
		if(contadorTrabajo>0)
		{
		 listarTrabajo (arrayNotebook,contadorNote,arrayServicio,contadorServicio, arrayTrabajo,contadorTrabajo);
		}
		else
		{
			printf("\n\nNo hay Trabajos cargadas por el momento");

		}
		break;
	case 'J':
		printf("\1)Mostrar las notebooks del tipo seleccionado por el usuario."
				"\n2)Mostrar notebooks de una marca seleccionada."
				"\n3)Informar la o las notebooks más baratas."
				"\n4)Mostrar un listado de las notebooks separadas por marca"
				"\n5)Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca"
				"\n6)Mostrar la o las marcas más elegidas por los clientes.");
		getNumeroE ("\nIngrese el numero de la opcion que elije ","\nERROR: utilice solo numeros",1, 6,3, &menuJ);
		switch (menuJ)
		{
		case 1:
			ImprimirporTipo( arrayMarca, &auxNotebook, arrayTipo,contadorMarca, contadorNote,contadorTipo,arrayCliente,contadorCliente);
			break;
		case 2:
			ImprimirporMarca( arrayMarca, &auxNotebook, arrayTipo,contadorMarca, contadorNote,contadorTipo,arrayCliente,contadorCliente);
			break;
		case 3:
			 NotebookmasBaratas( arrayMarca, &auxNotebook, arrayTipo,contadorMarca, contadorNote,contadorTipo,arrayCliente,contadorCliente);
			 break;
		case 4:
			NotebookporMarca ( arrayMarca, &auxNotebook, arrayTipo,contadorMarca, contadorNote,contadorTipo,arrayCliente,contadorCliente);
			break;
		case 5:
			cantidadporMarcayTipo( arrayMarca, &auxNotebook, arrayTipo,contadorMarca, contadorNote,contadorTipo,arrayCliente,contadorCliente);
			break;
		case 6:
			 marcaMasElegida( arrayMarca, &auxNotebook, arrayTipo,contadorMarca, contadorNote,contadorTipo,arrayCliente,contadorCliente);
			break;


		}
		break;
	}

}
}


