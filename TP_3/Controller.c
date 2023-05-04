#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "ingresos.h"
#include <string.h>
#include "salidas.h"

/// \fn int controller_cargarIdMaximo(LinkedList*, int*)
/// \brief Abre un archivo que contiene el maximo id y lo pasa por referencia.
///
/// \param pArrayListJugador
/// \param idMaximo
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int controller_cargarIdMaximo(int *idMaximo) {

	int idMax;
	int retorno = -1;

	FILE *pIdMaximo = fopen("id.txt", "r");

	if (pIdMaximo != NULL) {

		fscanf(pIdMaximo, "%d", &idMax);//Leo valores siguiendo un formato
		retorno = 0;
		*idMaximo = idMax;
	}
	fclose(pIdMaximo);

	return retorno;
}

/// \fn int controller_cargarJugadoresDesdeTexto(char *path, LinkedList *pArrayListJugador)
/// \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
/// \param path char*
/// \param pArrayListJugador LinkedList*
/// \return int return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_cargarJugadoresDesdeTexto(char *path, LinkedList *pArrayListJugador) {

	int retorno = -1;
	FILE *pFile = fopen(path, "r");

	if (pFile != NULL) {

		if (parser_JugadorFromText(pFile, pArrayListJugador) != 0) {
			puts("ERROR AL CARGAR EL ARCHIVO");
		} else {
			retorno = 0;
		}
	}
	fclose(pFile);
	return retorno;
}

/// \fn int controller_listarSelecciones(LinkedList*)
/// \brief Se listan selecciones,dentro se llama a imprimir seleccion.
/// \param pArrayListSeleccion
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_listarSelecciones(LinkedList *pArrayListSeleccion) {

	int cantidad;
	int retorno = -1;

	if (pArrayListSeleccion != NULL) {

		printf("+=========================================================+\n");
		printf("|%*s|%*s|%*s|%*s|\n", -4, " ID", -25, "         PAIS", -15,
				" CONFEDERACION", -10, "CONVOCADOS");
		printf("+=========================================================+\n");
		cantidad = ll_len(pArrayListSeleccion);
		for (int i = 0; i < cantidad; i++) {
			if (selec_imprimirSeleccion(pArrayListSeleccion, i) == 0) {
				retorno = 0;
			}
		}
		printf("+=========================================================+\n");
	}
	return retorno;
}

/// \fn int controller_listarJugadores(LinkedList*, LinkedList*)
/// \brief  *Se listan jugadores, se llama a jug_imprimirJugadores pasando como parametro un 1 para mostrar
/// tanto a jugadores convocados como no convocados.
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_listarJugadores(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;

	if (jug_imprimirJugadores(pArrayListJugador, pArrayListSeleccion, 1) == 0) {
		retorno = 0;
	}

	return retorno;
}

/// \fn int controller_cargarJugadoresDesdeBinario(char *path, LinkedList *listaJugadoresBinario, LinkedList *pArrayListSeleccion) {
/// \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
/// \param path char*
/// \param pArrayListJugador LinkedList*
/// \return  return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_cargarJugadoresDesdeBinario(char *path, LinkedList *listaJugadoresBinario, LinkedList *pArrayListSeleccion) {

	int retorno = -1;
	FILE *pArchivo;

	pArchivo = fopen(path, "rb");

	if (listaJugadoresBinario != NULL && ll_clear(listaJugadoresBinario) == 0&& path!=NULL && pArchivo!=NULL) {

		if (parser_JugadorFromBinary(pArchivo, listaJugadoresBinario) == 0) {


			controller_listarJugadores(listaJugadoresBinario, pArrayListSeleccion);
			printf("\nARCHIVO CARGADO CON EXITO\n");

			retorno = 0;
		}
	}
	fclose(pArchivo);
	return retorno;
}

/// \fn int controller_agregarJugador(LinkedList*, int*)
/// \brief Solicita validando continuamente los datos necesarios para completar cada campo de la estructura de un jugador
/// \param pArrayListJugador
/// \param idMax
/// \return  return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_agregarJugador(LinkedList *pArrayListJugador, int *idMax) {

	int retorno = -1;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion = 0;
	Jugador *pJugador;
	pJugador = jug_new();

	if (pArrayListJugador != NULL && pJugador != NULL) {

		*idMax = *idMax + 1;

		if (ingresarCadenaCaracteres(100, nombreCompleto,
				"Ingrese nombre completo del jugador: \t",
				"ERROR, Ingrese nombre completo valido.\n") == 0
				&& ingresarIntConRango(&edad,
						"Ingrese edad del jugador(16/50): \t",
						"ERROR, Ingrese edad valida(16/50).\n", 16, 50) == 0
				&& jug_IngresarPosicion(posicion) == 0
				&& jug_IngresarNacionalidad(nacionalidad) == 0) {

			if (jug_setId(pJugador, *idMax) == 0
					&& jug_setNombreCompleto(pJugador, nombreCompleto) == 0
					&& jug_setPosicion(pJugador, posicion) == 0
					&& jug_setNacionalidad(pJugador, nacionalidad) == 0
					&& jug_setEdad(pJugador, edad) == 0
					&& jug_setIdSeleccion(pJugador, idSeleccion) == 0) {
				ll_add(pArrayListJugador, pJugador);
				retorno = 0;
				printf("\nALTA EXITOSA\n");
			}
		} else {

			jug_delete(pJugador);
		}
	} else {
		printf("\nERROR AL AGREGAR NUEVO JUGADOR\n");
		jug_delete(pJugador);
	}
	return retorno;

}

/// \fn int controller_listar(LinkedList*, LinkedList*)
/// \brief Muestra menu para que el usuario ingrese opcion segun lo que se desee listar y llama a la funcion que corresponda,
///  se valida el retorno de la funcion llamada.
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_listar(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;
	int opcion;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {

		printf(
				"+==============================+\n|%*s|\n+==============================+\n",
				-30, "          LISTADOS");
		printf("|%*s|\n|%*s|\n|%*s|\n+==============================+\n", -30,
				"1.TODOS LOS JUGADORES ", -30, "2.TODAS LAS SELECCIONES", -30,
				"3.JUGADORES CONVOCADOS");

		ingresarIntConRango(&opcion, "INGRESE OPCION: \t",
				"ERROR, Ingrese opcion valida.\n", 1, 3);

		switch (opcion) {
		case 1:
			if (controller_listarJugadores(pArrayListJugador,
					pArrayListSeleccion) == 0) {
				retorno = 0;
			}
			break;
		case 2:
			if (controller_listarSelecciones(pArrayListSeleccion) == 0) {
				retorno = 0;
			}
			break;
		case 3:
			if (jug_imprimirJugadores(pArrayListJugador, pArrayListSeleccion, 2) == 0) {
				retorno = 0;
			}
			break;
		}
	}
	return retorno;
}

/// \fn int controller_editarJugador(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion)
/// \brief Modificar datos del jugador
/// \param path char*
/// \param pArrayListJugador LinkedList*
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_editarJugador(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;
	int indice;
	int opcion;

	if (pArrayListJugador != NULL) {

		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
		jug_Solicitar_Id(pArrayListJugador, &indice,
				"Ingrese ID del jugador a modificar: \n");

		jug_imprimirJugadores(pArrayListJugador, pArrayListSeleccion, 1);

		printf(
				"+==============================+\n|%*s|\n+==============================+\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n"
						"+==============================+\n", -30,
				"INGRESE SEGUN DESEE MODIFICAR", -30, "1.NOMBRE.", -30,
				"2.EDAD.", -30, "3.POSICION.", -30, "4.NACIONALIDAD.");

		ingresarIntConRango(&opcion, "Ingrese opcion: ",
				"ERROR, Ingrese opcion valida: ", 1, 4);

		switch (opcion) {
		case 1:
			if (jug_Editar_NombreCompleto(pArrayListJugador, indice) == 0) {
				retorno = 0;
			}
			break;
		case 2:
			if (jug_Editar_Edad(pArrayListJugador, indice) == 0) {
				retorno = 0;
			}
			break;
		case 3:
			if (jug_Editar_Posicion(pArrayListJugador, indice) == 0) {
				retorno = 0;
			}
			break;
		case 4:
			if (jug_Editar_Nacionalidad(pArrayListJugador, indice) == 0) {
				retorno = 0;
			}
			break;
		}

	}
	return retorno;
}

/// \fn int controller_removerJugador(LinkedList*, LinkedList*)
/// \brief Se listad jugadores, se solita id (se valida), se elimina jugador de la lista y en caso que este convocado por alguna
/// seleccion, se descuenta 1 (funcion selec_restarConvocado).
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_removerJugador(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;
	Jugador *pJugador;
	int jugIdSelec;
	char jugNombreCompleto[100];
	int indice;

	if (pArrayListJugador != NULL) {

		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

		jug_Solicitar_Id(pArrayListJugador, &indice,
				" Ingrese ID del jugador a dar de baja: \n");

		pJugador = ll_get(pArrayListJugador, indice);

		if (jug_getNombreCompleto(pJugador, jugNombreCompleto) == 0) {

			if (jug_Confirmar_Baja(pArrayListJugador, indice, jugNombreCompleto) == 0) {

				if (jug_getSIdSeleccion(pJugador, &jugIdSelec) == 0) {

					if (jugIdSelec > 0) {

						if (selec_restarConvocado(pArrayListSeleccion, jugIdSelec) == 0) {

							ll_remove(pArrayListJugador, indice);
							retorno = 0;
						}
					} else {

						ll_remove(pArrayListJugador, indice);
						retorno = 0;
					}
				}
			}
		}
	}
	return retorno;
}

/// \fn int controller_editarSeleccion(LinkedList*, LinkedList*)
/// \brief Se muestra menu, el usuario elige segun desee operar (validacion), se llama a jug_convocar o a jug_Quitar_Convocado segun corresponda.
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_editarSeleccion(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;
	int opcion;
	Seleccion *pSeleccion;
	int tamSeleccion;
	int selecConvocados;
	int flag = 0;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {

		printf("+=========================================+\n");
		printf("|%*s|\n|%*s|\n", -41, "         1.CONVOCAR JUGADOR", -41,
				"         2.QUITAR DE SELECCION");
		printf("+=========================================+\n");

		ingresarIntConRango(&opcion, "Ingrese opcion: \n",
				"ERROR, Ingrese opcion valida.\n", 1, 2);

		switch (opcion) {

		case 1:
			if (jug_convocar(pArrayListJugador, pArrayListSeleccion) == 0) {
				retorno = 0;
			}
			break;
		case 2:

			tamSeleccion = ll_len(pArrayListSeleccion);

			for (int i = 0; i < tamSeleccion; i++) {

				pSeleccion = ll_get(pArrayListSeleccion, i);

				if (selec_getConvocados(pSeleccion, &selecConvocados) == 0) {

					if (selecConvocados != 0) {

						if (jug_Quitar_Convocado(pArrayListJugador, pArrayListSeleccion) == 0) {
							retorno = 0;
							flag = 1;
							break;
						}
					}
				}
			}
			if (flag == 0) {
				printf(
						"ERROR, No se pueden quitar convocados si aun no hay ninguno.\n");
			}
			break;
		}
	}
	return retorno;
}

/// \fn int controller_guardarJugadoresModoTexto(char*, LinkedList*)
/// \brief Se abre un archivo para sobrescribirlo con lo cargado en la lista recibida por parametro, se
/// obtienen valores mediante getters validando, y por ultimo se cierra el archivo.
/// \param path
/// \param pArrayListJugador
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_guardarJugadoresModoTexto(char *path, LinkedList *pArrayListJugador) {

	int retorno = -1;
	int tam = ll_len(pArrayListJugador);
	Jugador *pJugador;
	int edad;
	int id;
	char nacionalidad[30];
	char nombreCompleto[100];
	char posicion[30];
	int idSeleccion;

	FILE *pFile = fopen(path, "w");

	if (pArrayListJugador != NULL && pFile != NULL) {

		fprintf(pFile, "id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n");

		for (int i = 0; i < tam; i++) {

			pJugador = ll_get(pArrayListJugador, i);

			if (jug_getEdad(pJugador, &edad) == 0
					&& jug_getId(pJugador, &id) == 0
					&& jug_getNacionalidad(pJugador, nacionalidad) == 0
					&& jug_getNombreCompleto(pJugador, nombreCompleto) == 0
					&& jug_getPosicion(pJugador, posicion) == 0
					&& jug_getSIdSeleccion(pJugador, &idSeleccion) == 0) {
				fprintf(pFile, "%d,%s,%d,%s,%s,%d\n", id, nombreCompleto, edad,
						posicion, nacionalidad, idSeleccion);//Escribo texto en el archivo siguiendo el formato
				retorno = 0;
			}
		}
		fclose(pFile);
	}
	if (retorno == 0) {
		printf("\nJUGADORES GUARDADOS CORRECTAMENTE\n");
	}
	return retorno;
}

/// \fn int controller_guardarMaxId(char*, int)
/// \brief Abre un archivo y obtiene el unico dato que contiene, el mismo corresponde al id maximo operado hasta el momento.
/// \param path
/// \param maxId
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_guardarMaxId(char *path, int maxId) {
	int retorno = -1;
	FILE *pArchivo = fopen("id.txt", "w");
	if (path != NULL) {
		fprintf(pArchivo, "%d", maxId);//Escribo texto en el archivo siguiendo el formato
		retorno = 0;

		printf("\nULTIMO ID GUARDADO CORRECTAMENTE\n");
	}
	fclose(pArchivo);
	return retorno;
}

/// \fn int controller_guardarJugadoresModoBinario(char *path, LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion)
/// \brief Guarda los datos de los jugadores convocados en un archivo binario de una confederacion especifica validando que la misma tenga convocados.
/// \param path char*
/// \param pArrayListJugador LinkedList*
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_guardarJugadoresModoBinario(char *path, LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;
	char confederacion[30];

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {

		selec_IngresarConfederacion(confederacion);

		if (selec_verificarConvocadosPorconfederacion(confederacion, pArrayListSeleccion) == 0) {

			if (jug_guardarJugadores(pArrayListSeleccion, confederacion, pArrayListJugador, path) == 0) {
				printf(
						"ARCHIVO BINARIO CREADO CON EXITO\n");
				retorno = 0;
			}
		} else {
			printf(
					"ERROR,la confederacion %s, no tiene convocados.\n",
					confederacion);
		}
	}
	return retorno;
}

/// \fn int controller_cargarSeleccionesDesdeTexto(char *path, LinkedList *pArrayListSeleccion)
/// \brief Carga los datos de las selecciones desde el archivo selecciones.csv (modo texto).
/// \param path char*
/// \param pArrayListSeleccion LinkedList*
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_cargarSeleccionesDesdeTexto(char *path, LinkedList *pArrayListSeleccion) {

	FILE *pFile = fopen(path, "r");
	int retorno = -1;

	if (pFile != NULL) {
		if (parser_SeleccionFromText(pFile, pArrayListSeleccion) == 0) {

			retorno = 0;
		} else {
			printf("ERROR, Al abrir archivo de selecciones");
		}
	}
	fclose(pFile);
	return retorno;
}

/// \fn int controller_guardarSeleccionesModoTexto(char *path, LinkedList *pArrayListSeleccion)
/// \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
/// \param path char*
/// \param pArrayListSeleccion LinkedList*
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int controller_guardarSeleccionesModoTexto(char *path, LinkedList *pArrayListSeleccion) {

	int retorno = -1;
	Seleccion *pSeleccion;
	char confederacion[30];
	int convocados;
	int id;
	int tam = ll_len(pArrayListSeleccion);
	char pais[30];

	FILE *pFile = fopen(path, "w");

	if (pArrayListSeleccion != NULL && pFile != NULL) {

		fprintf(pFile, "id,pais,confederacion,convocados\n");

		for (int i = 0; i < tam; i++) {

			pSeleccion = ll_get(pArrayListSeleccion, i);

			if (selec_getConfederacion(pSeleccion, confederacion) == 0
					&& selec_getConvocados(pSeleccion, &convocados) == 0
					&& selec_getId(pSeleccion, &id) == 0
					&& selec_getPais(pSeleccion, pais) == 0) {
				fprintf(pFile, "%d,%s,%s,%d\n", id, pais, confederacion,
						convocados);//Escribo texto en el archivo siguiendo el formato
				retorno = 0;
			}
		}
		fclose(pFile);
	}
	if (retorno == 0) {
		printf("\nSELECCIONES GUARDADAS CORRECTAMENTE\n");
	}
	return retorno;
}

/// \fn int controller_ordenarJugadoresPorNacionalidadAscendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion)
/// \brief ordena jugadores por nacionalidad ascendente
/// \param pArrayListJugador puntero a la lista de jugadores
/// \param pArrayListSeleccion puntero a la lista de selecciones
/// \return 0 todo ok, -1 error
int controller_ordenarJugadoresPorNacionalidadAscendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;

	if (pArrayListJugador != NULL) {

		ll_sort(pArrayListJugador, jug_ordenarPorNacionalidad, 1);
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

		retorno = 0;
	}
	return retorno;
}

/// \fn int controller_ordenarJugadoresPorNombreAscendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion)
/// \brief ordena jugadores por nombre ascendente
/// \param pArrayListJugador puntero a la lista de jugadores
/// \param pArrayListSeleccion puntero a la lista de selecciones
/// \return 0 todo ok, -1 error
int controller_ordenarJugadoresPorNombreAscendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;

	if (pArrayListJugador != NULL) {

		ll_sort(pArrayListJugador, jug_ordenarPorNombre, 1);
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

		retorno = 0;
	}
	return retorno;
}

/// \fn int controller_ordenarJugadoresPorEdadAscendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion)
/// \brief ordena jugadores por edad ascendente
/// \param pArrayListJugador puntero a la lista de jugadores
/// \param pArrayListSeleccion puntero a la lista de selecciones
/// \return 0 todo ok, -1 error
int controller_ordenarJugadoresPorEdadAscendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;

	if (pArrayListJugador != NULL) {

		ll_sort(pArrayListJugador, jug_ordenarPorEdad, 1);
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

		retorno = 0;
	}
	return retorno;
}

/// \fn int controller_ordenarSeleccionesPorConfederacionAscendente(LinkedList *pArrayListSeleccion)
/// \brief ordena jugadores por confederacion ascendente
/// \param pArrayListJugador puntero a la lista de jugadores
/// \param pArrayListSeleccion puntero a la lista de selecciones
/// \return 0 todo ok, -1 error
int controller_ordenarSeleccionesPorConfederacionAscendente(LinkedList *pArrayListSeleccion) {

	int retorno = -1;

	if (pArrayListSeleccion != NULL) {

		ll_sort(pArrayListSeleccion, selec_ordenarPorConfederacion, 1);
		controller_listarSelecciones(pArrayListSeleccion);

		retorno = 0;
	}
	return retorno;
}

/// \fn int controller_ordenarJugadoresPorNacionalidadDescendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion)
/// \brief ordena jugadores por nacionalidad descendente
/// \param pArrayListJugador puntero a la lista de jugadores
/// \param pArrayListSeleccion puntero a la lista de selecciones
/// \return 0 todo ok, -1 error
int controller_ordenarJugadoresPorNacionalidadDescendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;

	if (pArrayListJugador != NULL) {

		ll_sort(pArrayListJugador, jug_ordenarPorNacionalidad, 0);
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

		retorno = 0;
	}
	return retorno;
}

/// \fn int controller_ordenarJugadoresPorNombreDescendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion)
/// \brief ordena jugadores por nombre descendente
/// \param pArrayListJugador puntero a la lista de jugadores
/// \param pArrayListSeleccion puntero a la lista de selecciones
/// \return 0 todo ok, -1 error
int controller_ordenarJugadoresPorNombreDescendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;

	if (pArrayListJugador != NULL) {

		ll_sort(pArrayListJugador, jug_ordenarPorNombre, 0);
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

		retorno = 0;
	}
	return retorno;
}

/// \fn int controller_ordenarJugadoresPorEdadDescendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion)
/// \brief ordena jugadores por edad descendente
/// \param pArrayListJugador puntero a la lista de jugadores
/// \param pArrayListSeleccion puntero a la lista de selecciones
/// \return 0 todo ok, -1 error
int controller_ordenarJugadoresPorEdadDescendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;

	if (pArrayListJugador != NULL) {

		ll_sort(pArrayListJugador, jug_ordenarPorEdad, 0);
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

		retorno = 0;
	}
	return retorno;
}

/// \fn int controller_ordenarSeleccionesPorConfederacionDescendente(LinkedList *pArrayListSeleccion)
/// \brief ordena selecciones por confederacion descendente
/// \param pArrayListJugador puntero a la lista de jugadores
/// \param pArrayListSeleccion puntero a la lista de selecciones
/// \return 0 todo ok, -1 error
int controller_ordenarSeleccionesPorConfederacionDescendente(LinkedList *pArrayListSeleccion) {

	int retorno = -1;

	if (pArrayListSeleccion != NULL) {

		ll_sort(pArrayListSeleccion, selec_ordenarPorConfederacion, 0);
		controller_listarSelecciones(pArrayListSeleccion);

		retorno = 0;
	}
	return retorno;
}

/// \fn int controller_ordenarJugadoresPorIdAscendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion)
/// \brief ordena jugadores por id ascendente
/// \param pArrayListJugador puntero a la lista de jugadores
/// \param pArrayListSeleccion puntero a la lista de selecciones
/// \return 0 todo ok, -1 error
int controller_ordenarJugadoresPorIdAscendente(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion) {

	int retorno = -1;

	if (pArrayListJugador != NULL) {

		ll_sort(pArrayListJugador, jug_ordenarPorId, 1);


		retorno = 0;
	}
	return retorno;
}
