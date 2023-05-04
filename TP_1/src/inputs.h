#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

/**
 * @brief pide un entero y lo valida
 *
 * @param entero Puntero al entero ingresado
 * @param mensaje Mensaje que verá el usuario
 * @param mensajeError Mensaje que verá el usuario en caso de error
 * @param min Valor minimo del numero que puede ingresarse
 * @param max Valor maximo del numero que puede ingresarse
 * @return -1 en caso de error, 1 en caso de que salga todo bien
 */
int pedirEntero(int *entero, char *mensaje, char *mensajeError, int min, int max);

/**
 * @brief pide un flotante y lo valida
 *
 * @param flotante Puntero al flotante ingresado
 * @param mensaje Mensaje que verá el usuario
 * @param mensajeError Mensaje que verá el usuario en caso de error
 * @param min Valor minimo del numero que puede ingresarse
 * @param max Valor maximo del numero que puede ingresarse
 * @return -1 en caso de error, 1 en caso de que salga todo bien
 */
int pedirFlotante(float *flotante, char *mensaje, char *mensajeError, float min, float max);

/**
 * @brief pide un caracter y lo guarda
 *
 * @param caracter Puntero al caracter ingresado
 * @param mensaje El mensaje que verá el usuario
 * @return -1 en caso de error, 1 en caso de que salga todo bien
 */
int pedirCaracter(char *caracter, char *mensaje);

/**
 * @brief pregunta al usuario si desea confirmar la opcion
 *
 * @param mensaje El mensaje que verá el usuario
 * @return -1 en caso de error, 0 en caso de que salga todo bien
 */
int verificarConfirmacion(char *mensaje);

/**
 * @brief Imprime una linea
 *
 */
void printLine();

#endif /* INPUTS_H_ */
