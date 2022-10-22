/*
 * utnIngresodeDatos.h
 *
 *  Created on: 13 sep. 2022
 *      Author: Bahia
 */

#ifndef UTNINGRESODEDATOS_H_
#define UTNINGRESODEDATOS_H_
int getNumeroE (char *Mensaje,char *MensajeError, int minimo, int maximo, int intentos, int*pResultado);
int getNumeroD (char *Mensaje,char *MensajeError, float minimo, float maximo, int intentos, float*pResultado);
int getPalabra (char *Mensaje,char *MensajeError, int intentos, char*pResultado,int tamano);
int getAlfaNumerica (char *Mensaje,char *MensajeError, int intentos, char*pResultado, int tamano);
int getTelefono (char *Mensaje,char *MensajeError, int intentos, char*pResultado, int tamano);

#endif /* UTNINGRESODEDATOS_H_ */
