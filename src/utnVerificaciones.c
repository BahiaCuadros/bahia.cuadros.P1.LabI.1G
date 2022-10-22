/*
 * utn.c
 *
 *  Created on: 13 sep. 2022
 *      Author: Bahia
 */
#include <stdio.h>
#include <stdlib.h>
/*
BRIEF: Verifica que el valor recibido SOLO NUMEROS ENTEROS.
PARAM: str Array con la cadena a ser analizada
RETURN: devuelve 1 si es SOLO NUMEROS ENTEROS 0 si no lo es.
 */
int esNumericoE(char str[])
{
	int i=0;
	while (str[i]!='\0')
	{
		if (str[i]<'0'||str[i]>'9')
		{
			return 0;
		}
		i++;

	}
	return 1;
}

/*
BRIEF: Verifica que el valor recibido SOLO NUMEROS ENTEROS O DECIMALES.
PARAM: str Array con la cadena a ser analizada
RETURN: devuelve 1 si es SOLO NUMEROS ENTEROS O DECIMALES 0 si no lo es.
 */
int esNumericoD(char str[])
{
	int i=0;
	int banderaComa=0;
	while (str[i]!='\0')
	{
		if ((str[i]!='.')&&(str[i]<'0'||str[i]>'9'))
		{
			return 0;
		}
		if (str[i]=='.')
		{
			if(banderaComa==0)
			{
					banderaComa=1;
			}
			else{
				return 0;
			}
		}
		i++;

	}
	return 1;
}
/*
BRIEF: Verifica que el valor recibido sea SOLO LETRAS Y ESPACIO.
PARAM: str Array con la cadena a ser analizada
RETURN: devuelve 1 si es SOLO LETRAS Y ESPACIO 0 si no lo es.
 */
int esPalabra(char str[])
{
	int i=0;
	while (str[i]!='\0')
	{
		if ((str[i]!=' ')&&(str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z'))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

/*
BRIEF: Verifica que el valor recibido sea SOLO LETRAS, NUMEROS Y ESPACIO.
PARAM: str Array con la cadena a ser analizada
RETURN: devuelve 1 si es SOLO LETRAS, NUMEROS  Y ESPACIO 0 si no lo es.
 */
int esAlfaNumerico (char str[])
{
	int i=0;
		while (str[i]!='\0')
		{
			if ((str[i]!=' ')&&(str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z')&& (str[i]<'0'||str[i]>'9'))
			{
				return 0;
			}
			i++;
		}
		return 1;
}

/*
BRIEF: Verifica que el valor recibido sea NUMEROS, ESPACIO Y '-'.
PARAM: str Array con la cadena a ser analizada
RETURN: devuelve 1 si es NUMEROS, ESPACIO Y '-' 0 si no lo es.
 */
int esTelefono (char str[])
{
	int i=0;
	int banderaGuion=0;
			while (str[i]!='\0')
			{
				if ((str[i]!=' ')&&(str[i]<'0'||str[i]>'9')&&(str[i]!='-'))

			{
					return 0;
			}
				if(str[i]=='-')
					{
						if(banderaGuion==0)
						{
							banderaGuion=1;
						}
						else
						{
							return 0;
						}
					}
			i++;
			}
			return 1;
}
