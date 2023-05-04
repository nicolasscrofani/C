#ifndef INFORMES_H_
#define INFORMES_H_

#include "jugador.h"

/**
 * @brief imprime un submenu para que el usuario eliga el informe que quiere ver.
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tama�o del array jugadoes
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tama�o del array confederaciones
 * @return -1 si hubo errores, 1 si no los hubo
 */
int subMenuInformes(eJugador *jugadores, int tamJugadores, eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief lista a los jugadores ordenados alfab�ticamente por nombre de confederaci�n y nombre de jugador.
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tama�o del array jugadoes
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tama�o del array confederaciones
 * @param tamNombreConf
 * @param tamNombreJug
 * @return -1 si hubo errores, 1 si no los hubo
 */
int informes_ordenar(eJugador *jugadores, int tamJugadores, eConfederacion *confederaciones, int tamConfederaciones, int tamNombreConf, int tamNombreJug);


/**
 * @brief lista las confederaciones los jugadores de cada una.
 *
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tama�o del array confederaciones
 * @param jugadores array de jugadores
 * @param tamJugadores tama�o del array jugadoes
 * @return -1 si hubo errores, 1 si no los hubo
 */
int informes_listarPorConfederacion(eConfederacion *confederaciones, int tamConfederaciones, eJugador *jugadores, int tamJugadores);


/**
 * @brief informa el total y promedio de todos los salarios y cu�ntos jugadores cobran m�s del salario promedio.
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tama�o del array jugadoes
 * @return -1 si hubo errores, 1 si no los hubo
 */
int informes_salarios(eJugador *jugadores, int tamJugadores);


/**
 * @brief Informa la confederaci�n con mayor cantidad de a�os de contratos total.
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tama�o del array jugadoes
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tama�o del array confederaciones
 * @return -1 si hubo errores, 1 si no los hubo
 */
int informes_confederacionConMasAniosDeContrato(eJugador *jugadores, int tamJugadores, eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief Informa porcentaje de jugadores por cada confederaci�n.
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tama�o del array jugadoes
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tama�o del array confederaciones
 * @return -1 si hubo errores, 1 si no los hubo
 */
int informes_porcentajeJugadoresPorConfederacion(eJugador *jugadores, int tamJugadores, eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief Informa cual es la regi�n con m�s jugadores y el listado de los mismos.
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tama�o del array jugadoes
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tama�o del array confederaciones
 * @return -1 si hubo errores, 1 si no los hubo
 */
int informes_regionMasJugadores(eJugador *jugadores, int tamJugadores, eConfederacion *confederaciones, int tamConfederaciones);


#endif /* INFORMES_H_ */
