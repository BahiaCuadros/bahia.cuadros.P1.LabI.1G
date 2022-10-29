/*
 * notebook.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_
#include "fecha.h"
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "fecha.h"
#include "eCliente.h"

typedef struct
{
	int id;
	char modelo[20];
	int idCliente;
	int idMarca;
	int idTipo;
	float precio;
	int isEmpty;
}Notebook;

int AltaNotebook ( Marca *arrayMarca,  Notebook *auxNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente*arrayCLientes, int contadorCliente);
int OrdenamientoNumericoNote ( Notebook* pArray , int limite ,int criterio);
int Copiararray ( Notebook* arrayParacopiar,  Notebook* arrayFinal,int tamano);
int imprimirArrayNote ( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente);
int buscarNotebookXModelo ( Notebook *pArray, char* descripcion, int Limite);
int BuscadordeNotebookXID ( Notebook* pArray, int ID, int Limite);
int ModificarNotebook ( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente*arrayCliente,int contadorCliente);
int imprimirNotebook ( Marca *arrayMarca,  Notebook Notebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente);
int BajaNotebook( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente);
void imprimirArrayOrdenado( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente);
void Hardcodeo(Notebook* NoteFinal,int id,char modelo[20],int idCliente,int idMarca,int idTipo,float precio);
#endif /* NOTEBOOK_H_ */
