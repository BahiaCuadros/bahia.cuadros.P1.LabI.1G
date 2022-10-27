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
int contadorNote=0;
int contadorMarca=0;
int contadorTipo=0;
int contadorServicio=0;
int contadorTrabajo=0;

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
	printf("\nA:ALTA NOTEBOOK \nB:MODIFICAR NOTEBOOK \nC:BAJA NOTEBOOK \nD:LISTAR NOTEBOOK \nE:LISTAR MARCAS \nF:LISTAR TIPOS \nG:LISTAR SERVICIOS \nH:ALTA TRABAJO \nI:LISTAR TRABAJOS \nJ:SALIR");
	getPalabra ("\n ingresar letra corrrespondiente a la opcion deseada"," \n ERROR ingresar letra corrrespondiente a la opcion deseada", 5, &opcionMenu,3);
	switch (opcionMenu)
	{
	case 'A':
		AltaNotebook (arrayMarca, &auxNotebook, arrayTipo,contadorMarca, contadorNote,contadorTipo);
		arrayNotebook[contadorNote]=auxNotebook;
		contadorNote++;
		break;
	case 'B':
		ModificarNotebook(arrayMarca, arrayNotebook, arrayTipo, contadorMarca,contadorNote, contadorTipo);
		break;
	case 'C':
		BajaNotebook(arrayMarca, arrayNotebook,arrayTipo, contadorMarca,contadorNote, contadorTipo);
		break;
	case 'D':
		Copiararray (arrayNotebook, auxNotebookordenadoporPrecio,contadorNote);
		OrdenamientoNumericoNote (auxNotebookordenadoporPrecio, contadorNote ,1);
		imprimirArrayNote (arrayMarca,arrayNotebook,arrayTipo, contadorMarca, contadorNote, contadorTipo);
		break;
	case 'E':
		CopiararrayMarca (arrayMarca,auxMarcaordenadoporNombre,contadorMarca);
		OrdenamientoAlfabeticoMarca (auxMarcaordenadoporNombre,contadorMarca);
		imprimirArrayMarca(auxMarcaordenadoporNombre,contadorMarca);
		break;
	case 'F':
		CopiararrayTipo (arrayTipo, auxTipoodenadoporNombre,contadorTipo);
		OrdenamientoAlfabeticoTipo (auxTipoodenadoporNombre, contadorTipo );
		imprimirArrayTipo(auxTipoodenadoporNombre, contadorTipo);
		break;
	case 'G':
		CopiararrayServicio (arrayServicio, auxServicioordenadoNombre,contadorServicio);
		OrdenamientoAlfabeticoServicio (auxServicioordenadoNombre, contadorServicio);
		imprimirArrayServicio (auxServicioordenadoNombre, contadorServicio);
		break;
	case 'H':
		altaTrabajo(arrayNotebook,contadorNote,arrayServicio,contadorServicio, &auxiliarTrabajo,contadorTrabajo);
		arrayTrabajo[contadorTrabajo]=auxiliarTrabajo;
		contadorTrabajo++;
		break;
	case 'I':
		 listarTrabajo (arrayNotebook,contadorNote,arrayServicio,contadorServicio, arrayTrabajo,contadorTrabajo);
		break;
	}

}
}


