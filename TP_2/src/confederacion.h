#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#include "inputs.h"

//Tamaño del array confederaciones
#define TAMCONFEDERACIONES 6

//Tamaño del nombre de la confederacion
#define TAMNOMBRECONFEDERACION 51

//Tamaño del string region
#define TAMREGION 51

//valores del estado
#define VACIO 0
#define OCUPADO 1

typedef struct {

	int id;
	char nombre[TAMNOMBRECONFEDERACION];
	char region[TAMREGION];
	int anioCreacion;
	int estado;

} eConfederacion;


/**
 * @brief pone en estado 0 (vacio) todos los elemntos del array confederaciones
 *
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 */
void confederacion_inicializarArray(eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief imprime una confederacion por consola
 *
 * @param confederacion una confederacion
 */
void confederacion_mostrarUno(eConfederacion confederacion);


/**
 * @brief imprime por consola todas las confederaciones con estado 1(ocupado) del array
 *
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 */
void confederacion_mostrarTodos(eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief busca el primer espacio seteado en 0(vacio) dentro del array confederaciones
 *
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 * @return si encuentra un espacio libre, ese indice, si no, -1
 */
int confederacion_buscarEspacioLibre(eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief busca una confederacion cargada por su id
 *
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 * @param id el id a encontrar
 * @return el id buscado si se encuentra, si no, -1
 */
int confederacion_buscarPorId(eConfederacion *confederaciones, int tamConfederaciones, int id);


/**
 * @brief muestra las confederaciones del array que tengan estado 1 (ocupado) y le pide al usuario ingresar el id para poder devolverlo
 *
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 * @return el id ingresado, si no, -1
 */
int confederacion_obtenerId(eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief obtiene el nombre de una confederacion a partir de su id
 *
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 * @param id el id para buscar el nombre que corresponda
 * @param descripcion el nombre de la confederacion segun su id
 * @return -1 si hubo errores, 1 si no los hubo
 */
int confederacion_obtenerNombre(eConfederacion *confederaciones, int tamConfederaciones, int id, char *descripcion);


/**
 * @brief se pide al usuario el ingreso de datos para el alta de una confederacion e incrementa el ultimo id ingresado
 *
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 * @param id puntero al ultimo id ingresado
 * @return -1 si hubo errores, 1 si no los hubo
 */
int confederacion_agregarUno(eConfederacion *confederaciones, int tamConfederaciones, int *id);


/**
 * @brief pide al usuario el ingreso de un ID existente y realiza una baja logica a una confederacion cargada
 *
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 * @return -1 si hubo errores, 1 si no los hubo
 */
int confederacion_borrarUno(eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief accede a un menu para que el usuario pueda modificar datos de una confederacion cargada
 *
 * @param confederaciones array de confederaciones
 * @param tamConfederaciones tamaño del array confederaciones
 * @return -1 si hubo errores, 1 si no los hubo
 */
int confederacion_modificarUno(eConfederacion *confederaciones, int tamConfederaciones);


/**
 * @brief intercambia los datos de una confederacion por otra sin pisar los datos
 *
 * @param confederacion1 una confederacion
 * @param confederacion2 otra confederacion
 */
void confederacion_swapear(eConfederacion *confederacion1, eConfederacion *confederacion2);


#endif /* CONFEDERACION_H_ */
