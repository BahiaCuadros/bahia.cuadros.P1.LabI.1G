/*
 * tipo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
	int id;
	char descripcion[20];
}Tipo;

int CopiararrayTipo ( Tipo* arrayParacopiar,  Tipo* arrayFinal,int tamano);
int OrdenamientoAlfabeticoTipo ( Tipo* pArray , int limite );
int imprimirArrayTipo (Tipo *pArray , int limite);
int buscarTipoXDescripcion ( Tipo *pArray, char* descripcion, int Limite);
int BuscadordeTipoXID ( Tipo* pArray, int ID, int Limite);
int AltadeTipo ( Tipo* final,int Contador);
#endif /* TIPO_H_ */
