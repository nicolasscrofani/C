#ifndef SERVICIO_H_
#define SERVICIO_H_

#include "inputs.h"
#include "vehiculo.h"

//Tamaño del array
#define TAMSERVICIOS 50

//Tamaño de la descripcion
#define TAMDESCRIPCIONSERVICIO 51

//valores del estado
#define VACIO 0
#define OCUPADO 1

typedef struct {

	int dia;
	int mes;
	int anio;

} eFecha;

typedef struct {

	int idHoja;
	int vehiculoId;
	char descripcion[TAMDESCRIPCIONSERVICIO];
	float precioServicio;
	eFecha fecha;
	int estado;

} eHojaServicio;

/**
 * @brief pone en estado 0 (vacio) todos los elemntos del array servicios
 *
 * @param servicios array de servicios
 * @param tam tamaño del array servicios
 */
void hojaServicio_inicializarArray(eHojaServicio *servicios, int tam);

/**
 * @brief imprime un servicio por pantalla
 *
 * @param servicio un servicio
 */
void hojaServicio_mostrarUno(eHojaServicio servicio);

/**
 * @brief imprime por consola todos los servicios con estado 1(ocupado) del array
 *
 * @param servicios array de servicios
 * @param tam tamaño del array servicios
 */
void hojaServicio_mostrarTodos(eHojaServicio *servicios, int tam);

/**
 * @brief busca el primer espacio seteado en 0(vacio) dentro del array servicios
 *
 * @param servicios array de servicios
 * @param tam tamaño del array servicios
 * @return si encuentra un espacio libre, ese indice, si no, -1
 */
int hojaServicio_buscarEspacioLibre(eHojaServicio *servicios, int tam);

/**
 * @brief se pide al usuario el ingreso de datos para el alta de un servicio e incrementa el ultimo id ingresado
 *
 * @param servicios array de hojas de servicio
 * @param tamServicios tamaño del array servicios
 * @param vehiculos array de vehiculos
 * @param tamVehiculos tamaño del array vehiculos
 * @param tipos array de tipos
 * @param tamTipos tamaño del array tipos
 * @param id puntero al ultimo id ingresado
 * @return -1 si hubo errores, 1 si no los hubo
 */
int hojaServicio_agregarUno(eHojaServicio *servicios, int tamServicios, eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos, int *id);

/**
 * @brief muestra todas las hojas de servicio efectuadas en una fecha seleccionada
 *
 * @param servicios array de hojas de servicio
 * @param tamServicios tamaño del array servicios
 * @return -1 si hubo errores, 1 si no los hubo
 */
int hojaServicio_mostrarLasDeUnaFecha(eHojaServicio *servicios, int tamServicios);

/**
 * @brief Informa el importe total de las hojas de servicio realizadas en un vehículo seleccionado por el ususario
 *
 * @param servicios array de hojas de servicio
 * @param tamServicios tamaño del array servicios
 * @param vehiculos array de vehiculos
 * @param tamVehiculos tamaño del array vehiculos
 * @param tipos array de tipos
 * @param tamTipos tamaño del array tipos
 * @return -1 si hubo errores, 1 si no los hubo
 */
int hojaServicio_importeTotalDeUnVehiculo(eHojaServicio *servicios, int tamServicios, eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos);

/**
 * @brief
 *
 * @param servicios
 * @param tamServicios
 * @param vehiculos
 * @param tamVehiculos
 * @param tipos
 * @param tamTipos
 * @return
 */
int hojaServicio_importeTotalDeUnTipoEnUnaFecha(eHojaServicio *servicios, int tamServicios, eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos);

/**
 * @brief pide al usuario el ingreso de una fecha
 *
 * @param mensaje mensaje que se va a mostrar al usuario
 * @return una fecha
 */
eFecha pedirFecha(char *mensaje);

#endif /* SERVICIO_H_ */
