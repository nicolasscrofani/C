#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/// \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
/// \param path char*
/// \param pArrayListJugador LinkedList* lista a parsear
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int parser_JugadorFromText(FILE *pFile, LinkedList *pArrayListJugador) {

	char texto[6][150];
	int cantidad;
	Jugador *jugadorAux = NULL;
	int retorno;

	if (pFile != NULL && pArrayListJugador != NULL) {

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", (*(texto + 0)),
				(*(texto + 1)), (*(texto + 2)), (*(texto + 3)), (*(texto + 4)),
				(*(texto + 5)));

		while (!feof(pFile)) {

			cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					(*(texto + 0)), (*(texto + 1)), (*(texto + 2)),
					(*(texto + 3)), (*(texto + 4)), (*(texto + 5)));//Leo valores siguiendo un formato, devuelvo la cantidad de datos leidos

			if (cantidad > 6) {

				jug_delete(jugadorAux);
				jugadorAux = NULL;
				retorno = -1;
				break;

			} else {

				jugadorAux = jug_newParametros((*(texto + 0)), (*(texto + 1)),
						(*(texto + 2)), (*(texto + 3)), (*(texto + 4)),
						(*(texto + 5)));
				if (jugadorAux != NULL) {
					ll_add(pArrayListJugador, (Jugador*) jugadorAux);
					retorno = 0;
				}
			}
		}

	}
	return retorno;
}

/// \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
/// \param path char*
/// \param pArrayListSeleccion LinkedList* lista a parsear
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int parser_SeleccionFromText(FILE *pFile, LinkedList *pArrayListSeleccion) {

	Seleccion *seleccionAux = NULL;
	int cantidad;
	int retorno = -1;
	char texto[4][50];

	if (pFile != NULL) {

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", (*(texto + 0)),
				(*(texto + 1)), (*(texto + 2)), (*(texto + 3)));

		while (!feof(pFile)) {
			cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",
					(*(texto + 0)), (*(texto + 1)), (*(texto + 2)),
					(*(texto + 3)));//Leo valores siguiendo un formato, devuelvo la cantidad de datos leidos

			if (cantidad > 4) {

				selec_delete(seleccionAux);
				seleccionAux = NULL;
				retorno = -1;
				break;

			} else {
				seleccionAux = selec_newParametros((*(texto + 0)),
						(*(texto + 1)), (*(texto + 2)), (*(texto + 3)));

				if (seleccionAux != NULL) {
					ll_add(pArrayListSeleccion, seleccionAux);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/// \brief Parsea los datos de los selecciones desde el archivo pFile
/// \param pFile char*
/// \param listaJugadoresBinario LinkedList* lista a parsear
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int parser_JugadorFromBinary(FILE *pFile, LinkedList *listaJugadoresBinario) {

	int retorno = -1;
	Jugador *jugadorAux = NULL;
	int cantidad;

	if (pFile != NULL && listaJugadoresBinario != NULL) {

		while (!feof(pFile)) {

			jugadorAux = jug_new();
			cantidad = fread(jugadorAux, sizeof(Jugador), 1, pFile); // 1 cantidad de elementos de longitud tamaño que se van a leer

			if (cantidad == 1) {

				ll_add(listaJugadoresBinario, jugadorAux);
				retorno = 0;
			}
		}
	}
	return retorno;
}

