/*
 * utnIngresodeDatos.c
 *
 *  Created on: 13 sep. 2022
 *      Author: Bahia
 */
#include "utnVerificaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getInt(int*pResultado);
static int getFloat(float*pResultado);
static int getCharL(char* AuxPalabra,int tamano);
static int getCharLN(char* AuxPalabra,int tamano);
static int getCharTel(char* AuxPalabra,int tamano);
static int myGets(char* cadena, int longitud);
/*
BRIEF: Pide un NUMERO ENTERO al usuario, verifica que cumpla con las condiciones establecidas por parametro.
PARAM:  mensaje, mensaje de error, numero de intentos, maximo y minimo del numero, direccion de memoria donde va a guardarse el numero.
RETURN: Si todos los parametros estan bien  y el usuario ingreso un numero correcto retorna 1,si no retorna 0.
 */
int getNumeroE (char *Mensaje,char *MensajeError, int minimo, int maximo, int intentos, int*pResultado)
{
	setbuf(stdout,NULL);
	int numero;
	int retorno=1;
	if((Mensaje!=NULL)&&(MensajeError!=NULL)&&(maximo>minimo)&&(intentos>0))
	{
		printf("%s",Mensaje);
		if(getInt(&numero)==1)
		{
			if(numero>minimo&&numero<maximo)
			{
			*pResultado=numero;
			retorno = 1;
			}
			else
			{
			while(intentos>0)
				{
				printf("%s",MensajeError);
				if(getInt(&numero)==1)
				{
				*pResultado=numero;
				return 1;
				}
				intentos--;
				}
				retorno= 0;
					}
		}
		else
		{
			while(intentos>0)
			{
				printf("%s",MensajeError);
				if(getInt(&numero)==1)
						{
							*pResultado=numero;
							return 1;
						}
				intentos--;
			}

				retorno= 0;
		}
	}
	else
	{
		retorno=0;
	}
	return retorno;
}
/*
BRIEF: Verifica que la cadena recibida sea NUMERO ENTERO y la pasa a formato INT.
PARAM:  Espacio de memoria INT donde va a devolverse el numero ingresado por el usuario.
RETURN: Si el dato ingresado por el usuario es NUMERO ENTERO, devuelve 1, sino 0.
 */
static int getInt(int*pResultado)
{
	int retorno=0;
	char buffergetInt[4096];
	if((myGets(buffergetInt,sizeof(buffergetInt)))==1)
	{
			if (esNumericoE(buffergetInt)==1)
	{
		*pResultado= atoi(buffergetInt);
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}
	return retorno;
	}
	return retorno;
}

/*
BRIEF: Pide un NUMERO ENTERO O DECIMAL al usuario, verifica que cumpla con las condiciones establecidas por parametro.
PARAM:  mensaje, mensaje de error, numero de intentos, maximo y minimo del numero, direccion de memoria donde va a guardarse el numero.
RETURN: Si todos los parametros estan bien  y el usuario ingreso un numero correcto retorna 1,si no retorna 0.
 */
int getNumeroD (char *Mensaje,char *MensajeError, float minimo, float maximo, int intentos, float*pResultado)
{
	setbuf(stdout,NULL);
	float numero;
	int retorno=1;
	if((Mensaje!=NULL)&&(MensajeError!=NULL)&&(maximo>minimo)&&(intentos>0))
	{
		printf("%s",Mensaje);
		if(getFloat(&numero)==1)
		{
			if(numero>minimo && numero<maximo)
			{
			*pResultado=numero;
			retorno = 1;
			}
			if(numero>minimo&&numero<maximo)
						{
						*pResultado=numero;
						retorno = 1;
						}
						else
						{
						while(intentos>0)
							{
							printf("%s",MensajeError);
							if(getInt(&numero)==1)
							{
							*pResultado=numero;
							return 1;
							}
							intentos--;
							}
							retorno= 0;
								}
		}
		else
		{
			while(intentos>0)
			{
				printf("%s",MensajeError);
				if(getFloat(&numero)==1)
						{
							*pResultado=numero;
							return 1;
						}
				intentos--;
			}

				retorno= 0;
		}
	}
	else
	{
		retorno=0;
	}
	return retorno;
}
/*
BRIEF: Verifica que la cadena recibida sea NUMERO ENTERO O DECIMAL y la pasa a formato Float.
PARAM:  Espacio de memoria INT donde va a devolverse el numero ingresado por el usuario.
RETURN: Si el dato ingresado por el usuario es NUMERO ENTERO O DECIMAL , devuelve 1, sino 0.
 */
static int getFloat(float*pResultado)
{
	int retorno=0;
	char buffergetfloat[4096];

	if(myGets(buffergetfloat,sizeof(buffergetfloat))==1)
	{
		if (esNumericoD(buffergetfloat)==1)
	{
		*pResultado= atof(buffergetfloat);
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}
	return retorno;
	}
	return retorno;
}


/*
BRIEF: Pide una PALABRA O FRASE FORMADA POR LETRAS al usuario, verifica que cumpla con las condiciones establecidas por parametro.
PARAM:  mensaje, mensaje de error, numero de intentos, direccion de memoria donde va a guardarse el numero.
RETURN: Si todos los parametros estan bien  y el usuario ingreso PALABRA O FRASE FORMADA POR LETRAS retorna 1,si no retorna 0.
 */
int getPalabra (char *Mensaje,char *MensajeError, int intentos, char *pResultado, int tamano)
{
	setbuf(stdout,NULL);
	char AuxPalabra[tamano];
	if((Mensaje!=NULL)&&(MensajeError!=NULL)&&(tamano>0)&&(intentos>0))
		{

		printf("%s",Mensaje);

		if(getCharL(AuxPalabra,tamano)==1)
		{

			strcpy (pResultado,AuxPalabra);

			return 1;
		}
		else
		{
			while(intentos>0)
			{
				printf("%s",MensajeError);
						if(getCharL(AuxPalabra,tamano)==1)
						{
							strcpy (pResultado,AuxPalabra);
							return 1;
						}
			}
			return 0;
		}

		}
	return 0;
}
/*
BRIEF: Verifica que la cadena recibida sea UNA PALABRA O FRASE FORMADA POR LETRAS y la pasa a formato INT.
PARAM:  Espacio de memoria INT donde va a devolverse el numero ingresado por el usuario.
RETURN: Si el dato ingresado por el usuario es UNA PALABRA O FRASE FORMADA POR LETRAS, devuelve 1, sino 0.
 */
static int getCharL(char* AuxPalabra,int tamano)
{
	char Palabra[tamano];
	int retorno=1;
	if(tamano>0)
	{
		if(myGets(Palabra,tamano)==1)
		{
			if (esPalabra(Palabra)==1)
			{

				strcpy (AuxPalabra,Palabra);
				retorno=1;
			}
			else
			{
				retorno =0;
			}
		}
		else
		{
			retorno=0;
		}
	}
	else
	{
		retorno=0;
	}
	return retorno;
}


/*
BRIEF: Pide una PALABRA O FRASE FORMADA POR LETRAS Y NUMEROS al usuario, verifica que cumpla con las condiciones establecidas por parametro.
PARAM:  mensaje, mensaje de error, numero de intentos, direccion de memoria donde va a guardarse el numero.
RETURN: Si todos los parametros estan bien  y el usuario ingresoPALABRA O FRASE FORMADA POR LETRAS Y NUMEROSretorna 1,si no retorna 0.
 */
int getAlfaNumerica (char *Mensaje,char *MensajeError, int intentos, char *pResultado, int tamano)
{
	setbuf(stdout,NULL);
	char AuxPalabra[tamano];
	if((Mensaje!=NULL)&&(MensajeError!=NULL)&&(tamano>0)&&(intentos>0))
		{
		printf("%s",Mensaje);
		if(getCharLN(AuxPalabra,tamano)==1)
		{
			strcpy (pResultado,AuxPalabra);
			return 1;
		}
		else
		{
			while(intentos>0)
			{
				printf("%s",MensajeError);
						if(getCharLN(AuxPalabra,tamano)==1)
						{
							strcpy (pResultado,AuxPalabra);
							return 1;
						}
			}
			return 0;
		}

		}
	return 0;
}
/*
BRIEF: Verifica que la cadena recibida sea UNA PALABRA O FRASE FORMADA POR LETRAS Y NUMEROS y la pasa a formato INT.
PARAM:  Espacio de memoria INT donde va a devolverse el numero ingresado por el usuario.
RETURN: Si el dato ingresado por el usuario es UNA PALABRA O FRASE FORMADA POR LETRAS Y NUMEROS, devuelve 1, sino 0.
 */
static int getCharLN(char* AuxPalabra,int tamano)
{
	char Palabra[tamano];
	int retorno=1;
	if(tamano>0)
	{
		if(myGets(Palabra,tamano)==1)
		{
			if (esAlfaNumerico(Palabra)==1)
			{
				strcpy (AuxPalabra,Palabra);
				retorno=1;
			}
			else
			{
				retorno =0;
			}
		}
		else
		{
			retorno=0;
		}
	}
	else
	{
		retorno=0;
	}
	return retorno;
}

/*
BRIEF: Pide un NUMERO DE TELEFONO, CONFORMADO POR NUMEROS Y UN SOLO GUION al usuario, verifica que cumpla con las condiciones establecidas por parametro.
PARAM:  mensaje, mensaje de error, numero de intentos, direccion de memoria donde va a guardarse el numero.
RETURN: Si todos los parametros estan bien  y el usuario ingreso NUMERO DE TELEFONO, CONFORMADO POR NUMEROS Y UN SOLO GUION retorna 1,si no retorna 0.
 */
int getTelefono (char *Mensaje,char *MensajeError, int intentos, char*pResultado, int tamano)
{
	setbuf(stdout,NULL);
	char AuxPalabra[tamano];
	if((Mensaje!=NULL)&&(MensajeError!=NULL)&&(tamano>0)&&(intentos>0))
		{
		printf("%s",Mensaje);
		if(getCharTel(AuxPalabra,tamano)==1)
		{
			strcpy (pResultado,AuxPalabra);
			return 1;
		}
		else
		{
			while(intentos>0)
			{
				printf("%s",MensajeError);
						if(getCharTel(AuxPalabra,tamano)==1)
						{
							strcpy (AuxPalabra,pResultado);
							return 1;
						}
			}
			return 0;
		}

		}
	return 0;
}
/*
BRIEF: Verifica que la cadena recibida sea UNA PALABRA O FRASE FORMADA POR LETRAS Y NUMEROS y la pasa a formato INT.
PARAM:  Espacio de memoria INT donde va a devolverse el numero ingresado por el usuario.
RETURN: Si el dato ingresado por el usuario es UNA PALABRA O FRASE FORMADA POR LETRAS Y NUMEROS, devuelve 1, sino 0.
 */
static int getCharTel(char* AuxPalabra,int tamano)
{
	char Palabra[tamano];
	int retorno=1;
	if(tamano>0)
	{
		if(myGets(Palabra,tamano)==1)
		{
			if (esTelefono(Palabra)==1)
			{
				strcpy (AuxPalabra,Palabra);
				retorno=1;
			}
			else
			{
				retorno =0;
			}
		}
		else
		{
			retorno=0;
		}
	}
	else
	{
		retorno=0;
	}
	return retorno;
}
/*
BRIEF: Toma la cadena recibida en la consola, y la copia a una variable de formato char.
PARAM:  Espacio de memoria char, y tamaño asignado para la cadena
RETURN: Retorna 1 si todo sale bien, 0 si los parametros fueron mal enviados.
 */
static int myGets(char* cadena, int longitud)
{
	setbuf(stdout,NULL);
	if(longitud>0)
	{
	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 1;
	}
	return 0;
}
