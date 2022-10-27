/*
 * notebook.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

typedef struct
{
	int id;
	char modelo[20];
	int idMarca;
	int idTipo;
	float precio;
	int isEmpty;
}Notebook;

int AltaNotebook ( Marca *arrayMarca,  Notebook *auxNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo);
int OrdenamientoNumericoNote ( Notebook* pArray , int limite ,int criterio);
int Copiararray ( Notebook* arrayParacopiar,  Notebook* arrayFinal,int tamano);
int imprimirArrayNote ( Marca *arrayMarca,  Notebook *rrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo);
int buscarNotebookXModelo ( Notebook *pArray, char* descripcion, int Limite);
int BuscadordeNotebookXID ( Notebook* pArray, int ID, int Limite);
int ModificarNotebook ( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo);
int imprimirNotebook ( Marca *arrayMarca,  Notebook Notebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo);
int BajaNotebook( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo);
#endif /* NOTEBOOK_H_ */
