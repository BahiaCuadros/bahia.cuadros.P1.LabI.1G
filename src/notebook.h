/*
 * notebook.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

struct Notebook
{
	int id;
	char modelo[20];
	int idMarca;
	int idTipo;
	float precio;
	int isEmpty;
};


int OrdenamientoNumericoNote (struct Notebook* pArray , int limite ,int criterio);

#endif /* NOTEBOOK_H_ */
