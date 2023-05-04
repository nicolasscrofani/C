#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "inputs.h"

#define MAXIMOARQUEROS 2
#define MAXIMODEFENSORES 8
#define MAXIMOMEDIOCAMPISTAS 8
#define MAXIMODELANTEROS 4


/**
 * @brief Imprime el menu Principal
 *
 * @param costoHospedaje Costo del Hospedaje
 * @param costoComida Costo de la comida
 * @param costoTransporte Costo del transporte
 * @param arqueros Cantidad de arqueros actualizado hasta el momento
 * @param defensores Cantidad de defensores actualizado hasta el momento
 * @param mediocampistas Cantidad de mediocampistas actualizado hasta el momento
 * @param delanteros Cantidad de delanteros actualizado hasta el momento
 */
void menuPrincipal(float costoHospedaje, float costoComida,
		float costoTransporte, int arqueros, int defensores, int mediocampistas,
		int delanteros);

/**
 * @brief Imprime los resultados (Promedios y costos)
 *
 * @param uefa Promedio de jugadores de esa confederacion UEFA
 * @param conmebol Promedio de jugadores de la confederacion CONMEBOL
 * @param concacaf Promedio de jugadores de la confederacion CONCACAF
 * @param afc Promedio de jugadores de la confederacion AFC
 * @param ofc Promedio de jugadores de la confederacion OFC
 * @param caf Promedio de jugadores de la confederacion CAF
 * @param costo Costo total del mantenimiento sin el aumento
 * @param aumento Costo del aumento del 35% sobre el total anterior en caso de tenerlo
 * @param costoTotal Costo total del mantenimiento con el aumento en caso de tenerlo
 */
void imprimirResultados(float uefa, float conmebol, float concacaf, float afc,
		float ofc, float caf, float costo, float aumento, float costoTotal);

/**
 * @brief Carga un jugador validando  la camiseta y la confederacion
 *
 * @param confeUefa	contador para la confederacion
 * @param confeConmebol contador para la confederacion
 * @param confeConcacaf contador para la confederacion
 * @param confeAfc contador para la confederacion
 * @param confeOfc contador para la confederacion
 * @param confeCaf contador para la confederacion
 * @return	Retorna -1 si el usuario acabo sus intentos para ingresar el dato, o 0 si todo se guardo correctamente
 */
int cargarUnJugador(int *confeUefa, int *confeConmebol, int *confeConcacaf,
		int *confeAfc, int *confeOfc, int *confeCaf);

/**
 * @brief guarda la cantidad que hay de cada confederacion
 *
 * @param confederacion la opcion ingresada para la confederacion
 * @param confeUefa contador UEFA
 * @param confeConmebol contador CONMEBOL
 * @param confeConcacaf contador CONCACAF
 * @param confeAfc contador AFC
 * @param confeOfc contador OFC
 * @param confeCaf contador CAF
 * @return 0 todo ok, -1 error
 */
int guardarConfederacionContar(int *confederacion, int *confeUefa,
		int *confeConmebol, int *confeConcacaf, int *confeAfc, int *confeOfc,
		int *confeCaf);

/**
 * @brief	Guarda el costo de mantemiento segun la opcion que recibe como parametro ingresada por el usuario
 *
 * @param opcionCostoMenu Parametro por valor para guardar el costo segun el valor ingresado
 * @param costoHospedaje Es un puntero a la direccion de memoria donde se guardara el costo de Hospedaje
 * @param costoComida Es un puntero a la direccion de memoria donde se guardara el costo de la Comida
 * @param costoTransporte Es un puntero a la direccion de memoria donde se guardara el costo de Transporte
 * @return retorna -1 si algo salio mal, o 0 si todo OK
 */
int guardarCostos(int opcionCostoMenu, float *costoHospedaje,
		float *costoComida, float *costoTransporte);

/**
 * @brief calcula un promedio
 *
 * @param num1 un numero
 * @param num2 otro numero
 * @param promedio el promedio entre los dos
 * @return 0 todo ok, -1 error
 */
int calcularPromedio(int num1, int num2, float *promedio);

/**
 * @brief calcula un valor con un aumento indicado
 *
 * @param costoConAumento el costo con el aumento aplicado
 * @param costo el costo original
 * @param costoDelAumento el valor final
 * @param aumento el porcentaje a aumentar
 * @return 0 todo ok, -1 error
 */
int calcularAumento(float *costoConAumento, float *costo,
		float *costoDelAumento, float aumento);

/**
 * @brief contador de jugadores para cada confederacion
 *
 * @param contUEFA contador UEFA
 * @param contCONMEBOL contador CONMEBOL
 * @param contCONCACAF contador CONCACAF
 * @param contAFC contador AFC
 * @param contOFC contador OFC
 * @param contCAF contador CAF
 * @param total el total de los jugadores
 * @return
 */
int totalJugadoresDeConfederaciones(int contUEFA, int contCONMEBOL, int contCONCACAF, int contAFC, int contOFC, int contCAF, int *total);

/**
 * @brief calcula el costo total del mantenimiento
 *
 * @param costo1 un costo
 * @param costo2 otro costo
 * @param costo3 otro costo
 * @param costoTotal la suma de los costos
 * @return -1 error, 1 todo ok
 */
int costoTotalMantenimiento(float costo1, float costo2, float costo3, float *costoTotal);

/**
 * @brief chequea que el promedio de UEFA sea mayor al resto
 *
 * @param promedioUEFA promedio de UEFA
 * @param promedioCONMEBOL promedio de CONMEBOL
 * @param promedioCONCACAF promedio de CONCACAF
 * @param promedioAFC promedio de AFC
 * @param promedioOFC promedio de OFC
 * @param promedioCAF promedio de CAF
 * @param costoMasAumento el costo mas el aumento
 * @param costoMantenimiento el costo del mantenimiento
 * @param costoDelAumento el costo con el aumento
 * @return -1 error, 1 todo ok
 */
int mayorPromedio(float promedioUEFA, float promedioCONMEBOL,
		float promedioCONCACAF, float promedioAFC, float promedioOFC,
		float promedioCAF, float *costoMasAumento, float *costoMantenimiento,
		float *costoDelAumento);

#endif /* FUNCIONES_H_ */
