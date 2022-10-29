/*
 * marca.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Bahia
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct {
	int id;
	char descripcion[20];
}Marca;

int imprimirArrayMarca ( Marca* pArray , int limite);
int OrdenamientoAlfabeticoMarca ( Marca* pArray , int limite );
int CopiararrayMarca ( Marca* arrayParacopiar,  Marca* arrayFinal,int tamano);
int BuscadordeMarcaXDescripcion ( Marca * pArray, char* modelo, int Limite);
int BuscadordeMarcaXID ( Marca* pArray, int ID, int Limite);
int AltadeMarca ( Marca* final,int Contador);
void imprimirMarca(Marca Marcaimprimir);
#endif /* MARCA_H_ */
