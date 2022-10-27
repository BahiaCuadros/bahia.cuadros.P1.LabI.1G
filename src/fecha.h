/*
 * fecha.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */

#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
	int dia;
	int mes;
	int anioo;
}Fecha;

int ingresarFecha( Fecha *auxFecha);
void imprimirFecha( Fecha auxFecha);
#endif /* FECHA_H_ */
