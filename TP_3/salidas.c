#include <stdio.h>
#include <stdlib.h>
#include "Seleccion.h"
#include "Jugador.h"
#include "ingresos.h"

/// \fn void mostrarMenuPrincipal()
/// \brief Se muestran opciones potencialmente elegibles del menu principal.
void mostrarMenuPrincipal() {

	printf("+==================================================+\n|%*s|\n%s",
			-50, "                MENU PRINCIPAL",
			"+==================================================+\n");

	printf(
			"|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n%s\n",
			-50, "1.CARGA DE ARCHIVOS", -50, "2.ALTA DE JUGADOR", -50,
			"3.MODIFICACION DE JUGADOR", -50, "4.BAJA DE JUGADOR", -50,
			"5.LISTADOS", -50, "6.CONVOCAR / QUITAR JUGADORES", -50,
			"7.ORDENAR Y LISTAR", -50, "8.GENERAR ARCHIVO BINARIO", -50,
			"9.CARGAR ARCHIVO BINARIO", -50, "10.GUARDAR ARCHIVOS ", -50,
			"11.SALIR",
			"+==================================================+\n");
}

/// \fn int selec_imprimirSeleccion(LinkedList*, int)
/// \brief Imprime seleccion de un indice especifico en forma ordenada.
///
/// \param pArrayListSeleccion lista de seleccion
/// \param index indice
/// \return
int selec_imprimirSeleccion(LinkedList *pArrayListSeleccion, int index) {

	int retorno = -1;
	int id;
	char pais[50];
	char confederacion[50];
	int convocados;
	Seleccion *seleccionAux;
	seleccionAux = ll_get(pArrayListSeleccion, index);

	if (pArrayListSeleccion != NULL && index > -1) {

		if (selec_getId(seleccionAux, &id) == 0
				&& selec_getPais(seleccionAux, pais) == 0
				&& selec_getConfederacion(seleccionAux, confederacion) == 0
				&& selec_getConvocados(seleccionAux, &convocados) == 0) {

			retorno = 0;
			printf("| %*d|%*s|%*s| %*d|\n", -3, id, -25, pais, -15,
					confederacion, -9, convocados);
		}
	}
	return retorno;
}

/// \fn int jug_imprimirJugadores(LinkedList*, LinkedList*, int)
/// \brief Imprime/lista en forma ordenada los datos de los jugadores, incluyendo si estan o no seleccionados. Se
/// tiene en cuenta una referencia recibida por parametro a la hora de listar.
///
/// \param pArrayListJugador lista de jugadores
/// \param pArrayListSeleccion lista de selecciones
/// \param referenciaDeUso
/// \return
/*
 * referenciaDeUso==1 / SE MUESTRAN TODOS LOS JUGADORES.
 * referenciaDeUso==2 / SE MUESTRAN LOS JUGADORES CONVODADOS.
 * referenciaDeUso==3 / SE MUESTRAN LOS JUGADORES NO CONVOCADOS.
 */
int jug_imprimirJugadores(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion, int referenciaDeUso) {

	int retorno = -1;
	int id;
	char nombreCompleto[200];
	char posicion[100];
	char nacionalidad[100];
	int edad;
	int idSeleccion;
	char descripcionSeleccion[30];
	int tam;
	Jugador *pJugAux;

	if (pArrayListJugador != NULL) {

		tam = ll_len(pArrayListJugador);

		printf(
				"+================================================================================================================================+\n");
		printf("|%*s|\n", -128,
				"                                                    JUGADORES ");
		printf(
				"+================================================================================================================================+\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n%s\n", -6, "  ID", -40,
				"         NOMBRE COMPLETO", -4, "EDAD", -25, "      POSICION",
				-18, "    NACIONALIDAD", -8, "ID SELEC.", -20,
				"PAIS QUE CONVOCA",
				"+================================================================================================================================+");

		for (int i = 0; i < tam; i++) {

			pJugAux = ll_get(pArrayListJugador, i);

			if (jug_getId(pJugAux, &id) == 0
					&& jug_getNombreCompleto(pJugAux, nombreCompleto) == 0
					&& jug_getPosicion(pJugAux, posicion) == 0
					&& jug_getNacionalidad(pJugAux, nacionalidad) == 0
					&& jug_getEdad(pJugAux, &edad) == 0
					&& jug_getSIdSeleccion(pJugAux, &idSeleccion) == 0) {

				if (idSeleccion > 0 && (referenciaDeUso == 2 || referenciaDeUso == 1)) {

					retorno = 0;

					selec_AsignarDescripcionPais(pArrayListSeleccion, pArrayListJugador, i, descripcionSeleccion);

					printf("|  %*d|%*s| %*d|%*s|%*s|    %*d|%*s|\n", -4, id,
							-40, nombreCompleto, -3, edad, -25, posicion, -18,
							nacionalidad, -5, idSeleccion, -20,
							descripcionSeleccion);

				} else {

					if (idSeleccion == 0 && (referenciaDeUso == 3 || referenciaDeUso == 1)) {
						retorno = 0;
						printf("|  %*d|%*s| %*d|%*s|%*s|    %*d|%*s|\n", -4, id,
								-40, nombreCompleto, -3, edad, -25, posicion,
								-18, nacionalidad, -5, idSeleccion, -20,
								"NO CONVOCADO");
					}
				}
			}
		}
		printf(
				"+================================================================================================================================+\n");
	}
	return retorno;
}

/// \fn void jug_MostrarNacionalidades(void)
/// \brief Lista las nacionalidades de forma ordena.
void jug_MostrarNacionalidades(void) {

	printf("+====================+\n");
	printf(
			"|%*s|\n+====================+\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n"
					"|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n",
			-20, "   NACIONALIDADES", -20, "1.Arabe.", -20, "2.Australiano.",
			-20, "3.Coreano.", -20, "4.Iranie.", -20, "5.Japones.", -20,
			"6.Qatari.", -20, "7.Camerunes.", -20, "8.Ghanes.", -20,
			"9.Marroqui.", -20, "10.Senagales", -20, "11.Tunez", -20,
			"12.Canadiense.", -20, "13.Costarriquense.", -20,
			"14.Estadounidense.", -20, "15.Mexicano", -20, "16.Argentino.", -20,
			"17.Brasilero.", -20, "18.Ecuatoriano.", -20, "19.Uruguayo.", -20,
			"20.Aleman.", -20, "21.Belga.", -20, "22.Croata", -20,
			"23.Dinamarques.", -20, "24.Espaniol.", -20, "25.Frances.", -20,
			"26.Gales", -20, "27.Holandes.", -20, "28.Ingles.", -20,
			"29.Polaco.", -20, "30.Portugues.", -20, "31.Serbio.", -20,
			"32.Suizo.");
	printf("+====================+\n");
}


/// \fn int menuOpcionFiltrar()
/// \brief Imprime un submenu para el ordenamiento
/// \return la opcion
int menuOpcionFiltrar() {
	printf("  				 *** Filtrar por ***\n\n");
	int opcion;
	printf("1) JUGADORES POR NACIONALIDAD ASCENDENTE\n");
	printf("2) JUGADORES POR NACIONALIDAD DESCENDENTE\n");
	printf("3) SELECCIONES POR CONFEDERACION ASCENDENTE\n");
	printf("4) SELECCIONES POR CONFEDERACION DESCENDENTE\n");
	printf("5) JUGADORES POR EDAD ASCENDENTE\n");
	printf("6) JUGADORES POR EDAD DESCENDENTE\n");
	printf("7) JUGADORES POR NOMBRE ASCENDENTE\n");
	printf("8) JUGADORES POR NOMBRE DESCENDENTE\n");
	printf("9) Volver al menu\n");
	ingresarIntConRango(&opcion, "INGRESE OPCION: ",
			"ERROR, Ingrese opcion valida.\n", 1, 9);
	return opcion;
}
