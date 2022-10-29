/*
 * trabajo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#include  "fecha.h"
#include "notebook.h"
#include "servicio.h"
#include "fecha.h"

typedef struct
{
	int id;
	int idNotebook;
	int idServicio;
	Fecha fecha;
	int isEmpty;
}Trabajo;

int altaTrabajo( Notebook *arrayNotebook,int contNote, Servicio *arrayServicio,int contServ,  Trabajo *auxiliarTrabajo,int conTra);
int listarTrabajo ( Notebook* arrayNotebook,int contNote, Servicio* arrayServicio,int contServ,  Trabajo* arrayTrabajo,int conTra);
#endif /* TRABAJO_H_ */
