#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "ingresos.h"
#include "salidas.h"
#include "Seleccion.h"

int main() {
	setbuf(stdout, NULL);
	int opcion = 0;
	LinkedList *listaJugadores = ll_newLinkedList();
	LinkedList *listaSelecciones = ll_newLinkedList();
	LinkedList *listaJugadoresBinario = ll_newLinkedList();
	int idMax;
	char path[30];
	strcpy(path, "jugadoresBinario.bin");


	do {
		mostrarMenuPrincipal();
		ingresarIntConRango(&opcion, "INGRESE OPCION: ",
				"ERROR, Ingrese opcion valida.\n", 1, 11);

		switch (opcion) {

		case 1:
			if (ll_isEmpty(listaJugadores) && ll_isEmpty(listaSelecciones)) {

				if (!controller_cargarJugadoresDesdeTexto("jugadores.csv",
						listaJugadores)
						&& !controller_cargarSeleccionesDesdeTexto(
								"selecciones.csv", listaSelecciones)) {

					printf("\nARCHIVO CARGADO EXITOSAMENTE\n");
					controller_cargarIdMaximo(&idMax);

				} else {
					printf("ERROR al cargar los archivos\n");
				}

			} else {
				printf("Los archivos ya fueron cargados.\n ");
			}
			break;
		case 2:
			if (!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) {

				if (controller_agregarJugador(listaJugadores, &idMax) != 0) {
					printf("\nERROR AL AGREGAR NUEVO JUGADOR\n");
				}
			} else {
				printf("ERROR. Primero debe cargar los archivos (opcion 1).\n");
			}
			break;
		case 3:
			if (!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) {

				if (controller_editarJugador(listaJugadores, listaSelecciones)
						!= 0) {
					printf("\nERROR AL EDITAR JUGADOR\n");
				}
			} else {
				printf("ERROR. Primero debe cargar los archivos (opcion 1).\n");
			}
			break;
		case 4:
			if (!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) {

				if (controller_removerJugador(listaJugadores, listaSelecciones)
						!= 0) {
					printf("\nERROR AL REMOVER JUGADOR\n");
				}
			} else {
				printf("ERROR. Primero debe cargar los archivos (opcion 1).\n");
			}
			break;
		case 5:
			if (!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) {

				if (controller_listar(listaJugadores, listaSelecciones) != 0) {

					printf("ERROR AL LISTAR\n");
					printf(
							"RECUERDE QUE PARA LISTAR CONVOCADOS PRIMERO DEBE CONVOCAR AL MENOS 1 JUGADOR\n");
				}
			} else {
				printf("ERROR. Primero debe cargar los archivos (opcion 1).\n");
			}

			break;
		case 6:
			if (!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) {

				if (controller_editarSeleccion(listaJugadores, listaSelecciones)
						!= 0) {
					printf("ERROR al convocar o quitar jugador.\n");
				}
			} else {
				printf("ERROR. Primero debe cargar los archivos (opcion 1).\n");
			}

			break;
		case 7:
			if (!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) {

				switch (menuOpcionFiltrar()) {

				case 1:
					controller_ordenarJugadoresPorNacionalidadAscendente(
							listaJugadores, listaSelecciones);
					break;
				case 2:
					controller_ordenarJugadoresPorNacionalidadDescendente(
							listaJugadores, listaSelecciones);
					break;
				case 3:
					controller_ordenarSeleccionesPorConfederacionAscendente(
							listaSelecciones);

					break;
				case 4:
					controller_ordenarSeleccionesPorConfederacionDescendente(
							listaSelecciones);

					break;
				case 5:
					controller_ordenarJugadoresPorEdadAscendente(listaJugadores,
							listaSelecciones);

					break;
				case 6:
					controller_ordenarJugadoresPorEdadDescendente(
							listaJugadores, listaSelecciones);

					break;
				case 7:
					controller_ordenarJugadoresPorNombreAscendente(
							listaJugadores, listaSelecciones);
					break;
				case 8:
					controller_ordenarJugadoresPorNombreDescendente(
							listaJugadores, listaSelecciones);
					break;

				case 9:
					printf("Volviendo al menu...\n");
					break;
				}

			} else {
				printf("ERROR. Primero debe cargar los archivos (opcion 1).\n");
			}
			break;
		case 8:
			if (!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) {

				if (controller_guardarJugadoresModoBinario(path, listaJugadores,
						listaSelecciones) != 0) {

					printf("ERROR al intentar crear el archivo binario\n");
				}
			} else {
				printf("ERROR. Primero debe cargar los archivos (opcion 1).\n");
			}
			break;
		case 9:
			if (!ll_isEmpty(listaJugadores) && !ll_isEmpty(listaSelecciones)) {

				if (controller_cargarJugadoresDesdeBinario(path,
						listaJugadoresBinario, listaSelecciones) != 0) {

					printf(
							"ERROR, al cargar archivo binario, primero debe generar el archivo (opcion 8).\n");
				}
			} else {
				printf("ERROR. Primero debe cargar los archivos (opcion 1).\n");
			}
			break;
		case 10:
			if (!ll_isEmpty(listaJugadores)
					&& ll_isEmpty(listaSelecciones) == 0) {

				controller_ordenarJugadoresPorIdAscendente(listaJugadores, listaSelecciones);

				if (controller_guardarJugadoresModoTexto("jugadores.csv",
						listaJugadores) != 0
						|| controller_guardarSeleccionesModoTexto(
								"selecciones.csv", listaSelecciones) != 0
						|| controller_guardarMaxId("id.txt", idMax) != 0) {
					printf("\nERROR AL GUARDAR ARCHIVOS\n");
				}
			} else {
				printf("ERROR. Primero debe cargar los archivos (opcion 1).\n");
			}

			break;
		case 11:
			if (verify("\nSi no guardó los cambios(opcion 10), se perderan los datos\nDesea salir del programa? ('s'): ") == 0) {
				if (listaJugadores != NULL) {
					ll_deleteLinkedList(listaJugadores);
				}
				printf("\nPROGRAMA FINALIZADO...\n");

			} else {

				opcion = 0;
			}

			break;
		}
	} while (opcion != 11);

	return 0;
}

