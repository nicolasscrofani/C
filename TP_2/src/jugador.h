#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "inputs.h"
#include "confederacion.h"

//Tamaño del array jugadores
#define TAMJUGADORES 3000

//Tamaño del nombre del jugador
#define TAMNOMBREJUGADOR 51

//Tamaño del string posicion
#define TAMPOSICIONJUGADOR 51

//valores del estado
#define VACIO 0
#define OCUPADO 1

typedef struct {

	int id;
	char nombre[TAMNOMBREJUGADOR];
	char posicion[TAMPOSICIONJUGADOR];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short estado;

} eJugador;


/**
 * @brief pone en estado 0 (vacio) todos los elemntos del array jugadores
 *
 * @param jugadores array jugadores
 * @param tamJugadores tamaño del array jugadores
 */
void jugador_inicializarArray(eJugador *jugadores, int tamJugadores);


/**
 * @brief imprime un jugador por consola
 *
 * @param jugador un jugador
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 */
void jugador_mostrarUno(eJugador jugador, eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief imprime por consola todos los vehiculos con estado 1(ocupado) del array
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tamaño del array jugadoes
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 */
void jugador_mostrarTodos(eJugador *jugadores, int tamJugadores, eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief busca el primer espacio seteado en 0(vacio) dentro del array jugadores
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tamaño del array jugadoes
 * @return si encuentra un espacio libre, ese indice, si no, -1
 */
int jugador_buscarEspacioLibre(eJugador *jugadores, int tamJugadores);


/**
 * @brief busca un jugador cargado por su id
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tamaño del array jugadoes
 * @param id el id a encontrar
 * @return el id buscado si se encuentra, si no, -1
 */
int jugador_buscarPorId(eJugador *jugadores, int tamJugadores, int id);


/**
 * @brief muestra los jugadores del array que tengan estado 1 (ocupado) y le pide al usuario ingresar el id para poder devolverlo
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tamaño del array jugadoes
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 * @return el id ingresado, si no, -1
 */
int jugador_obtenerId(eJugador *jugadores, int tamJugadores, eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief obtiene el nombre de un jugador a partir de su id
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tamaño del array jugadoes
 * @param id el id para buscar el nombre que corresponda
 * @param nombre el nombre de un jugador, segun su id
 * @return -1 si hubo errores, 1 si no los hubo
 */
int jugador_obtenerNombre(eJugador *jugadores, int tamJugadores, int id, char *nombre);


/**
 * @brief obtiene la cantidad de jugadores cargados recorriendo el array
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tamaño del array jugadoes
 * @return -1 en caso de error, si no, la cantidad
 */
int jugador_obtenerCantidad(eJugador *jugadores, int tamJugadores);


/**
 * @brief se pide al usuario el ingreso de datos para el alta de un jugador e incrementa el ultimo id ingresado
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tamaño del array jugadoes
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 * @param id puntero al ultimo id ingresado
 * @return -1 si hubo errores, 1 si no los hubo
 */
int jugador_agregarUno(eJugador *jugadores, int tamJugadores, eConfederacion *confederaciones, int tamConfederaciones, int *id);


/**
 * @brief pide al usuario el ingreso de un ID existente y realiza una baja logica a un jugador cargado
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tamaño del array jugadoes
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 * @return -1 si hubo errores, 1 si no los hubo
 */
int jugador_borrarUno(eJugador *jugadores, int tamJugadores, eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief accede a un menu para que el usuario pueda modificar datos de un jugador cargado
 *
 * @param jugadores array de jugadores
 * @param tamJugadores tamaño del array jugadoes
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 * @return -1 si hubo errores, 1 si no los hubo
 */
int jugador_modificarUno(eJugador *jugadores, int tamJugadores, eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief intercambia los datos de un jugador por otro sin pisar los datos
 *
 * @param jugador1 un jugador
 * @param jugador2 otro jugador
 */
void jugador_swapear(eJugador *jugador1, eJugador *jugador2);


#endif /* JUGADOR_H_ */
