/*
 * informes.h
 *
 *  Created on: 28 oct. 2022
 *      Author: Bahia
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"
void ImprimirporMarca( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente);
void ImprimirporTipo( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente);
void NotebookmasBaratas( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente);
void NotebookporMarca ( Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente);
void cantidadporMarcayTipo(Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente);
void marcaMasElegida(Marca *arrayMarca,  Notebook *arrayNotebook,  Tipo *arrayTipo, int contadorMarca, int contadorNote,int contadorTipo,Cliente* arrayCliente, int contadorCliente);

#endif /* INFORMES_H_ */
