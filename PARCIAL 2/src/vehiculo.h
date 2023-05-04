#ifndef VEHICULO_H_
#define VEHICULO_H_

#include "inputs.h"

//Tamaño del array vehiculos
#define TAMVEHICULOS 50

//Tamaño de la descripcion del vehiculo
#define TAMDESCRIPCIONVEHICULO 51

//Tamaño del string color
#define TAMCOLOR 11

//Tamaño del array tipos
#define TAMTIPOS 50

//Tamaño de la descripcion del tipo
#define TAMDESCRIPCIONTIPO 31

//valores del estado
#define VACIO 0
#define OCUPADO 1

typedef struct {

	int idTipo;
	char descripcionTipo[TAMDESCRIPCIONTIPO];
	int estado;

} eTipo;

typedef struct {

	int idVehiculo;
	char descripcion[TAMDESCRIPCIONVEHICULO];
	int modelo;
	char color[TAMCOLOR];
	int tipoId;
	int estado;

} eVehiculo;

/**
 * @brief pone en estado 0 (vacio) todos los elemntos del array vehiculos
 *
 * @param vehiculos array vehiculos
 * @param tam tamaño del array vehiculos
 */
void vehiculo_inicializarArray(eVehiculo *vehiculos, int tam);

/**
 * @brief imprime un vehiculo por consola
 *
 * @param vehiculo un vehiculo
 * @param tipos array de tipos
 * @param tam tamaño del array tipos
 */
void vehiculo_mostrarUno(eVehiculo vehiculo, eTipo *tipos, int tam);

/**
 * @brief imprime por consola todos los vehiculos con estado 1(ocupado) del array
 *
 * @param vehiculos array de vehiculos
 * @param tamVehiculos tamaño del array vehiculos
 * @param tipos array de tipos
 * @param tamTipos tamaño del array tipos
 */
void vehiculo_mostrarTodos(eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos);

/**
 * @brief busca el primer espacio seteado en 0(vacio) dentro del array vehiculos
 *
 * @param vehiculos array de vehiculos
 * @param tam tamaño del array vehiculos
 * @return si encuentra un espacio libre, ese indice, si no, -1
 */
int vehiculo_buscarEspacioLibre(eVehiculo *vehiculos, int tam);

/**
 * @brief busca un vehiculo cargado por su id
 *
 * @param vehiculos array de vehiculos
 * @param tam tamaño del array vehiculos
 * @param id el id a encontrar
 * @return el id buscado si se encuentra, si no, -1
 */
int vehiculo_buscarPorId(eVehiculo *vehiculos, int tam, int id);

/**
 * @brief muestra los vehiculos del array que tengan estado 1 (ocupado) y le pide al usuario ingresar el id para poder devolverlo
 *
 * @param vehiculos array de vehiculos
 * @param tamVehiculos tamaño del array vehiculos
 * @param tipos array de tipos
 * @param tamTipos tamaño del array tipos
 * @return el id ingresado, si no, -1
 */
int vehiculo_obtenerId(eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos);

/**
 * @brief se pide al usuario el ingreso de datos para el alta de un vehiculo e incrementa el ultimo id ingresado
 *
 * @param vehiculos array de vehiculos
 * @param tamVehiculos tamaño del array vehiculos
 * @param tipos array de tipos
 * @param tamTipos tamaño del array tipos
 * @param id puntero al ultimo id ingresado
 * @return -1 si hubo errores, 1 si no los hubo
 */
int vehiculo_agregarUno(eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos, int *id);

/**
 * @brief pide al usuario el ingreso de un ID existente y realiza una baja logica a un vehiculo cargado
 *
 * @param vehiculos array de vehiculos
 * @param tamVehiculos tamaño del array vehiculos
 * @param tipos array de tipos
 * @param tamTipos tamaño del array tipos
 * @return -1 si hubo errores, 1 si no los hubo
 */
int vehiculo_borrarUno(eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos);

/**
 * @brief accede a un menu para que el usuario pueda modificar datos de un vehiculo cargado
 *
 * @param vehiculos array de vehiculos
 * @param tamVehiculos tamaño del array vehiculos
 * @param tipos array de tipos
 * @param tamTipos tamaño del array tipos
 * @return -1 si hubo errores, 1 si no los hubo
 */
int vehiculo_modificarUno(eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos);

/**
 * @brief Muestra los vehículos de un tipo seleccionado por el usuario
 *
 * @param vehiculos array de vehiculos
 * @param tamVehiculos tamaño del array vehiculos
 * @param tipos array de tipos
 * @param tamTipos tamaño del array tipos
 * @return -1 si hubo errores, 1 si no los hubo
 */
int vehiculo_mostrarDeUnTipo(eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos);

/**
 * @brief imprime por consola un tipo de vehiculo
 *
 * @param tipo un tipo de vehiculo
 */
void tipo_mostrarUno(eTipo tipo);

/**
 * @brief imprime por consola todos los tipos con estado 1(ocupado) del array
 *
 * @param tipos
 * @param tam
 */
void tipo_mostrarTodos(eTipo *tipos, int tam);

/**
 * @brief busca un tipo cargado por su id
 *
 * @param tipos array de tipos
 * @param tam tamaño del array tipos
 * @param id el id a encontrar
 * @return el id buscado si se encuentra, si no, -1
 */
int tipo_buscarPorId(eTipo *tipos, int tam, int id);

/**
 * @brief muestra los tipos del array que tengan estado 1 (ocupado) y le pide al usuario ingresar el id para poder devolverlo
 *
 * @param tipos array de tipos
 * @param tamTipos el tamaño del array tipos
 * @return el id ingresado, si no, -1
 */
int tipo_obtenerId(eTipo *tipos, int tamTipos);

/**
 * @brief obtiene la descripcion de un tipo a partir de su id
 *
 * @param tipos array de tipos
 * @param tam tamaño del array tipos
 * @param id el id para buscar la descripcion que corresponda
 * @param descripcion la descripcion de un tipo, segun su id
 * @return -1 si hubo errores, 1 si no los hubo
 */
int tipo_obtenerDescripcion(eTipo *tipos, int tam, int id, char *descripcion);

#endif /* VEHICULO_H_ */
