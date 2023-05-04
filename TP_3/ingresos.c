#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "ingresos.h"

/// \fn int ingresarNumIntConRango(int*, char*, char*, int)
/// \brief Ingreso texto, verifico que sean numeros efectivamente (isDigit), y paso a numeros con "atoi", para luego verificar si se
/// cumple con el minimo.
/// \param resultado ,tipo de dato int (pasa por referencia).
/// \param mensaje ,mensaje utilizado para solicitar el numero.
/// \param mensajeError ,mensaje de error por si el usuario ingresa un numero por debajo del minimo.
/// \param minimo ,limite inferior del rango.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarIntConMinimo(int* resultado, char* mensaje, char* mensajeError, int minimo)
{
	int retorno=-1;
	int flag;
	int tamIngreso;
	char numero[999999];

	do
	{
		flag=0;
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
		{
			printf("%s",mensaje);
			fflush(stdin);
			gets(numero);

            tamIngreso=strlen(numero);

            for(int i=0;i<tamIngreso;i++)
            {
            	if(isdigit((*(numero+i)))==0)
            	{
            		flag=1;
            		printf("ERROR, Ingrese un numero\n");
            		break;
            	}
            }
            if(flag==0)
            {
            	*resultado=atoi(numero);
                if(*resultado>=minimo)
                {
                	retorno=0;
                }
                else
                {
                	printf("%s",mensajeError);
                }
            }
		}

	}while(retorno!=0);

	return retorno;
}

/// \fn int ingresarNumIntConRango(int*, char*, char*, int, int)
/// \brief Ingreso texto, verifico que sean numeros efectivamente (isDigit), y paso a numeros con "atoi", para luego verificar si se
/// cumple con el rango.
///
///
/// \param resultado ,tipo de dato int (pasa por referencia).
/// \param mensaje ,mensaje utilizado para solicitar el numero.
/// \param mensajeError ,mensaje de error por si el usuario ingresa un numero fuera del rango.
/// \param minimo ,limite inferior del rango.
/// \param maximo ,limite superior del rango.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarIntConRango(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno=-1;
	int flag;
	int tamIngreso;
	char numero[999999];

	do
	{
		flag=0;
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
		{
			printf("%s",mensaje);
			fflush(stdin);
			gets(numero);

            tamIngreso=strlen(numero);

            for(int i=0;i<tamIngreso;i++)
            {
            	if(isdigit((*(numero+i)))==0)
            	{
            		flag=1;
            		printf("ERROR, Ingrese un numero\n");
            		break;
            	}
            }
            if(flag==0)
            {
            	*resultado=atoi(numero);
                if(*resultado>=minimo && *resultado<= maximo)
                {
                	retorno=0;
                }
                else
                {
                	printf("%s",mensajeError);
                }
            }
		}

	}while(retorno!=0);

	return retorno;
}

/// \fn int verificarCaracterSN(char)
/// \brief Verifica si se ingreso una s/S o n/N y retorna segun corresponda
///
/// \param letra
/// \return return=0 ingreso s/S n/N/ return=-1 ingreso cualquier otra leta
int verificarCaracterSN(char letra)
{
	int retorno=-1;
	char aux;
	aux=toupper(letra);
	if(aux=='S' || aux=='N')
	{
		retorno=0;
	}
	else
	{
		printf("ERROR, Debe ingresar o 'S' o 'N'\n");
	}
	return retorno;
}

/// \fn int ingresarCadenaCaracteres(int, char*, char*, char*)
/// \brief Ingresar una cadena de caracteres verificando el tamanio, y que no se encuentren numeros.
///
/// \param tam ,tamaño de la cadena
/// \param textoIngresado ,el resultado se pasara por referencia.
/// \param mensaje ,mensaje utilizado para solicitar la cadena.
/// \param mensajeError ,mensaje de error por si el usuario excede la cantidad de caracteres.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarCadenaCaracteres(int tam,char* textoIngresado,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    int tamIngreso;
    int flag;
    if(textoIngresado!=NULL && mensaje!=NULL && mensajeError!=NULL && tam>0)
    {
    	while(retorno==-1)
    	{
    		flag=0;
            printf("%s",mensaje);
            fflush(stdin);
            gets(textoIngresado);

            tamIngreso=strlen(textoIngresado);

            for(int i=0;i<tamIngreso;i++)
            {
            	if(isdigit((*(textoIngresado+i)))!=0)
            	{
            		flag=1;
            		break;
            	}
            }
            if(strlen(textoIngresado)<=tam && flag==0)
            {
            	retorno=0;
            }else
            {
            	printf("%s",mensajeError);
            }
    	}

    }
    return retorno;
}

/// \fn int getCharacter(char *_char, char *_msg)
/// \param _char
/// \param _msg
/// \return
int getCharacter(char *_char, char *_msg) {
	if (_char != NULL && _msg != NULL) {
		printf("%s", _msg);
		fflush(stdin);
		*_char = getchar();
		return 0;
	}
	return -1;
}

/// \fn int verify(char *_msg)
/// \param _msg
/// \return
int verify(char *_msg) {
	char ver;

	getCharacter(&ver, _msg);
	if (ver == 's' || ver == 'S') {
		return 0;
	}
	return -1;
}
