/*
 * servicio.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
	int id;
	char descripcion[20];
	float precio;
}Servicio;

int CopiararrayServicio ( Servicio* arrayParacopiar,  Servicio* arrayFinal,int tamano);
int OrdenamientoAlfabeticoServicio ( Servicio* pArray , int limite );
int imprimirArrayServicio ( Servicio* pArray , int limite);
int buscarServicioXDescripcion ( Servicio *pArray, char* descripcion, int Limite);
int BuscadordeSerivicioXID ( Servicio* pArray, int ID, int Limite);
#endif /* SERVICIO_H_ */
