/*
 * eCliente.h
 *
 *  Created on: 28 oct. 2022
 *      Author: Bahia
 */

#ifndef ECLIENTE_H_
#define ECLIENTE_H_

typedef struct
{
	int id;
	char Nombre[20];
	char sexo [15];
}Cliente;

int buscarClienteporNombre(Cliente *pArray, char* descripcion, int Limite);
int BuscadordeClienteXID( Cliente* pArray, int ID, int Limite);
void HarcodeoCliente(Cliente* clientefinal,int id,char* sexo, char* nombre);

#endif /* ECLIENTE_H_ */
