#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

/**
 * @brief pide al usuario que ingrese un numero entero y lo valida
 *
 * @param entero puntero al entero ingresado
 * @param mensaje el mensaje que verá el usuario
 * @param mensajeError el mensaje que verá el usuario en caso de error
 * @param min el numero minimo que puede ingresar
 * @param max el numero maximo que puede ingresar
 * @return -1 en caso de error, 1 en caso de que no lo haya
 */
int pedirEntero(int *entero, char *mensaje, char *mensajeError, int min, int max);

/**
 * @brief valida que el caracter ingresado sea flotante
 *
 * @param caracter el caracter ingresado por el usuario
 * @return 0 para error, 1 si no lo hay
 */
int validarFlotante(char* caracter);

/**
 * @brief pide al usuario que ingrese un numero flotante y lo valida
 *
 * @param flotante puntero al flotante ingresado
 * @param mensaje el mensaje que verá el usuario
 * @param mensajeError el mensaje que verá el usuario en caso de error
 * @param min el numero minimo que puede ingresar
 * @param max el numero maximo que puede ingresar
 * @return -1 en caso de error, 1 en caso de que no lo haya
 */
float pedirFlotante(float *flotante, char *mensaje, char *mensajeError, float min, float max);

/**
 * @brief pide al usuario el ingreso de una cadena y la valida
 *
 * @param cadena puntero a la cadena ingresada
 * @param mensaje el mensaje que verá el usuario
 * @param mensajeError el mensaje que verá el usuario en caso de error
 * @param max el maximo largo de cadena permitido
 * @return -1 en caso de error, 1 en caso de que no lo haya
 */
int pedirCadena(char *cadena, char *mensaje, char *mensajeError, int max);

/**
 * @brief valida que el caracter ingresado sea alfabetico
 *
 * @param letra puntero al caracter ingresado
 * @return -1 en caso de error, 1 en caso de que no lo haya
 */
int validarLetra(char *letra);

/**
 * @brief solicita al usuario una cadena que permite solo caracteres alfabeticos
 *
 * @param cadena puntero a la cadena ingresada
 * @param mensaje el mensaje que verá el usuario
 * @param mensajeError el mensaje que verá el usuario en caso de error
 * @param max el maximo largo de cadena permitido
 * @return -1 en caso de error, 1 en caso de que no lo haya
 */
int pedirCadenaAlfabetica(char *cadena, char *mensaje, char *mensajeError, int max);

/**
 * @brief pide al usuario que ingrese un caracter
 *
 * @param caracter puntero al caracter ingresado
 * @param mensaje el mensaje que verá el usuario
 * @return -1 en caso de error, 1 en caso de que no lo haya
 */
int pedirCaracter(char *caracter, char *mensaje);

/**
 * @brief pide al ususario verificar si quiere realizar una accion
 *
 * @param mensaje el mensaje impreso al usuario
 * @return -1 en caso de error, 0 en caso de que no lo haya
 */
int verificarConfirmacion(char *mensaje);

#endif /* INPUTS_H_ */
