/*
 * fecha.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
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
#include "utnIngresodeDatos.h"
#include "utn.ordenamiento.h"

int ingresarFecha(struct Fecha *auxFecha)
{
	getNumeroE ("\ningrese dia Por favor","\n ingrese dia Por favor (del 1 al 31)", 0,31,5,auxFecha->dia );
	getNumeroE ("\ningrese mes Por favor","\n ingrese mes Por favor (del 1 al 12)", 0,12,5,auxFecha->mes );
	getNumeroE ("\ningrese anio Por favor","\n ingrese anio Por favor (del 2000 al 2022)", 2000,2022,5,auxFecha->anioo);
	return 1;
}
