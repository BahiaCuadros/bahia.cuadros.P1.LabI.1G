/*
 * fecha.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */

#ifndef FECHA_H_
#define FECHA_H_

struct Fecha
{
	int dia;
	int mes;
	int anioo;
	int isEmpty;
};

int ingresarFecha(struct Fecha *auxFecha);
#endif /* FECHA_H_ */
