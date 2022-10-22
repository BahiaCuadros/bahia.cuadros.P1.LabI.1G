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

struct Trabajo
{
	int id;
	int idNotebook;
	int idServicio;
	struct Fecha fecha;
	int isEmpty;
};

int altaTrabajo(struct Notebook arrayNotebook[50],int contNote,struct Servicio arrayServicio[50],int contServ, struct Trabajo arrayTrabajo[50],int conTra);
int listarTrabajo (struct Notebook arrayNotebook[50],int contNote,struct Servicio arrayServicio[50],int contServ, struct Trabajo arrayTrabajo[50],int conTra);
#endif /* TRABAJO_H_ */
