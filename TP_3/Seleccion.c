#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seleccion.h"
#include "ingresos.h"
#include "Jugador.h"

/// \fn void selec_delete(Seleccion*)
/// \brief Libero espacio de memoria de un puntero a estructura Seleccion recibido.
/// \param this
void selec_delete(Seleccion *this) {

	free(this);
}

/// \fn Seleccion selec_new*()
/// \brief Reserva espacio de memoria para una estructura de tipo Seleccion.
/// \return retorna puntero a estructura de tipo Seleccion
Seleccion* selec_new() {
	Seleccion *pSeleccion;
	pSeleccion = (Seleccion*) calloc(1, sizeof(Seleccion) * 1);
	return pSeleccion;
}

/// \fn Seleccion selec_newParametros*(char*, char*, char*, char*)
/// \brief Recibe por parametro valores para completar los campos de una estructa de tipo Seleccion, habiendo reservado memoria anteriormente.
/// \param idStr
/// \param paisStr
/// \param confederacionStr
/// \param convocadosStr
/// \return retorna puntero a estructura de tipo Seleccion
Seleccion* selec_newParametros(char *idStr, char *paisStr, char *confederacionStr, char *convocadosStr) {

	Seleccion *pSeleccion;
	pSeleccion = selec_new();

	if (pSeleccion != NULL) {

		pSeleccion->convocados = atoi(convocadosStr);
		pSeleccion->id = atoi(idStr);
		strcpy(pSeleccion->confederacion, confederacionStr);
		strcpy(pSeleccion->pais, paisStr);
	}
	return pSeleccion;
}

/// \fn int selec_getId(Seleccion*, int*)
/// \brief Asigno valor del campo id de una estructura de tipo Seleccion a una variable.
/// \param this
/// \param id variable a la que se le pasara el valor por referencia.
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_getId(Seleccion *this, int *id) {

	int retorno = -1;

	if (this != NULL) {

		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

/// \fn int selec_getPais(Seleccion*, char*)
/// \brief Asigno valor del campo pais de una estructura de tipo Seleccion a una variable.
/// \param this
/// \param pais variable a la que se le pasara el valor por referencia.
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_getPais(Seleccion *this, char *pais) {

	int retorno = -1;

	if (this != NULL) {

		strcpy(pais, this->pais);
		retorno = 0;

	}
	return retorno;
}

/// \fn int selec_getConfederacion(Seleccion*, char*)
/// \brief  Asigno valor del campo confederacion de una estructura de tipo Seleccion a una variable.
/// \param this
/// \param confederacion variable a la que se le pasara el valor por referencia.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_getConfederacion(Seleccion *this, char *confederacion) {

	int retorno = -1;

	if (this != NULL) {

		strcpy(confederacion, this->confederacion);
		retorno = 0;
	}
	return retorno;
}

/// \fn int selec_setConvocados(Seleccion*, int)
/// \brief Se le asigna  a this el valor que se reciba por parametro en el campo convocados.
/// \param this
/// \param convocados entero que se recibe
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_setConvocados(Seleccion *this, int convocados) {

	int retorno = -1;

	if (this != NULL) {

		this->convocados = convocados;
		retorno = 0;
	}
	return retorno;
}

/// \fn int selec_getConvocados(Seleccion*, int*)
/// \brief Asigno valor del campo convocados de una estructura de tipo Seleccion a una variable.
/// \param this
/// \param convocados
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_getConvocados(Seleccion *this, int *convocados) {

	int retorno = -1;

	if (this != NULL) {

		*convocados = this->convocados;
		retorno = 0;
	}
	return retorno;
}

/// \fn int selec_IngresarConfederacion(char*)
/// \brief Solicita ingresar confederacion por teclado mostrando las disponibles para luego validar lo ingresado.
/// \param opcion Se pasa por referencia el resultado.
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_IngresarConfederacion(char *opcion) {

	int retorno = -1;
	int opcionAux;

	if (opcion != NULL) {

		ingresarIntConRango(&opcionAux,
				"Ingrese confederacion de la que desea guardar listado de jugadores.\n"
						" 1.AFC - 2.CAF - 3.CONCACAF - 4.CONMEBOL - 5.UEFA\n",
				"ERROR,Ingrese conferacion valida.\n", 1, 5);

		switch (opcionAux) {
		case 1:
			strcpy(opcion, "AFC");
			break;
		case 2:
			strcpy(opcion, "CAF");
			break;
		case 3:
			strcpy(opcion, "CONCACAF");
			break;
		case 4:
			strcpy(opcion, "CONMEBOL");
			break;
		case 5:
			strcpy(opcion, "UEFA");
			break;
			retorno = 0;
		}
	}
	return retorno;
}

/// \fn int selec_verificarConvocadosPorconfederacion(char*, LinkedList*)
/// \brief  Se verifica que los paises de la seleccion recibida por parametro tiene convocados
/// \param opcion
/// \param pArrayListSeleccion
/// \return return=0 ESTA TODO OK, HAY AL MENOS UN JUGADOR CONVOCADO EN LA CONFEDERACION.
int selec_verificarConvocadosPorconfederacion(char *opcion, LinkedList *pArrayListSeleccion) {

	int retorno = -1;
	Seleccion *pSeleccion;
	int tam;
	char selecConfederacion[30];
	int selecConvocados;

	tam = ll_len(pArrayListSeleccion);

	if (opcion != NULL) {

		for (int i = 0; i < tam; i++) {

			pSeleccion = ll_get(pArrayListSeleccion, i);

			if (selec_getConfederacion(pSeleccion, selecConfederacion) == 0
					&& selec_getConvocados(pSeleccion, &selecConvocados) == 0) {

				if (strcmp(selecConfederacion, opcion) == 0
						&& selecConvocados > 0) {

					retorno = 0;
					break;
				}
			} else {
				printf(
						"ERROR al intentar acceder a la confederacion o cantidad de convocados.\n");
			}

		}
	}

	return retorno;
}

/// \fn int selec_AsignarDescripcionPais(LinkedList*, LinkedList*, int, char*)
/// \brief Al recibir el indice de un jugador, teniendo en cuenta el campo idSeleccion, busco pasar por referencia
/// el nombre de la seleccion a la que esta convocado.
/// \param pArrayListSeleccion
/// \param pArrayListJugador
/// \param indice
/// \param descripcionPais paso por referencia la descripcion del pais.
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_AsignarDescripcionPais(LinkedList *pArrayListSeleccion, LinkedList *pArrayListJugador, int indice, char *descripcionPais) {

	int retorno = -1;
	Jugador *pJugador;
	int tam;
	Seleccion *pSeleccion;
	int selecId;
	char selecPais[30];
	int jugIdSeleccion;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {

		pJugador = ll_get(pArrayListJugador, indice);
		tam = ll_len(pArrayListSeleccion);

		for (int i = 0; i < tam; i++) {

			pSeleccion = ll_get(pArrayListSeleccion, i);

			if (selec_getId(pSeleccion, &selecId) == 0
					&& jug_getSIdSeleccion(pJugador, &jugIdSeleccion) == 0) {

				if (selecId == jugIdSeleccion) {

					if (selec_getPais(pSeleccion, selecPais) == 0) {
						retorno = 0;

						strcpy(descripcionPais, selecPais);
						break;
					}
				}
			}
		}
	}
	return retorno;
}

/// \fn int selec_Solicitar_Id(LinkedList*, int*)
/// \brief Ya listadas las selecciones, en esta funcion paso a solicitar el id de la seleccion (valido), verifico que aun
/// se mantenga por debajo de los 22 convocados y retorno segun ello.
/// \param pArrayListSeleccion
/// \param indice
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_Solicitar_Id(LinkedList *pArrayListSeleccion, int *indice) {

	int retorno = -1;
	int idPais;
	Seleccion *pSeleccion;
	int selecConvocados;

	if (pArrayListSeleccion != NULL) {

		ingresarIntConRango(&idPais,
				"Ingrese ID del pais para convocar jugadores: \n",
				"ERROR, Ingerse ID valido,\n", 1, 32);

		if (selec_buscarPorId(pArrayListSeleccion, idPais, &(*(indice))) == 0) {

			pSeleccion = ll_get(pArrayListSeleccion, *(indice));

			if (selec_getConvocados(pSeleccion, &selecConvocados) == 0) {

				if (selecConvocados < 22) {

					retorno = 0;
				} else {
					printf(
							"ERROR, La seleccion llego a su maximo de 22 convocados.\n");
				}
			}

		}

	}
	return retorno;
}

/// \fn int selec_buscarPorId(LinkedList*, int, int*)
/// \brief Recibe un id de seleccion y pasa por referencia el indice en el que se encuentra el mismo.
/// \param pArrayListSeleccion
/// \param idBuscado
/// \param indice
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int selec_buscarPorId(LinkedList *pArrayListSeleccion, int idBuscado, int *indice) {

	int retorno = -1;
	int tam;
	Seleccion *pSeleccion = NULL;
	int selecId;
	tam = ll_len(pArrayListSeleccion);

	if (pArrayListSeleccion != NULL) {

		for (int i = 0; i < tam; i++) {

			pSeleccion = ll_get(pArrayListSeleccion, i);

			if (selec_getId(pSeleccion, &selecId) == 0) {

				if (selecId == idBuscado) {

					*indice = i;
					retorno = 0;
					break;
				}
			} else {
				printf("ERROR al obtener el id de la seleccion.\n");
			}
		}
	}
	return retorno;
}

/// \fn int selec_restarConvocado(LinkedList*, int)
/// \brief Recibiendo por parametro el id de la seleccion a operar, obtengo el indice (selec_buscarPorId)en donde se ubica y le resto -1 a su
/// campo de convocodos, luego hago el set del nuevo valor.
/// \param pArrayListSeleccion
/// \param idSeleccion
/// \return
int selec_restarConvocado(LinkedList *pArrayListSeleccion, int idSeleccion) {

	int retorno = -1;
	int selecIndice;
	Seleccion *pSeleccion;
	int selecConvocados;

	if (pArrayListSeleccion != NULL) {

		if (selec_buscarPorId(pArrayListSeleccion, idSeleccion, &selecIndice)
				== 0) {

			pSeleccion = ll_get(pArrayListSeleccion, selecIndice);

			if (selec_getConvocados(pSeleccion, &selecConvocados) == 0) {

				selecConvocados = selecConvocados - 1;

				if (selec_setConvocados(pSeleccion, selecConvocados) == 0) {
					retorno = 0;
					printf("JUGADOR DESCONTADO DE SU SELECCION\n");
				}
			}
		}
	}
	return retorno;
}

/// \fn int selec_ordenarPorConfederacion(void *a, void *b)
/// \brief compara dos confederaciones
/// \param a una confederacion
/// \param b otra confederacion
/// \return
int selec_ordenarPorConfederacion(void *a, void *b) {

	int retorno = 0; //iguales
	char confederacionUno[30];
	char confederacionDos[30];
	int compara;

	selec_getConfederacion(a, confederacionUno);
	selec_getConfederacion(b, confederacionDos);

	compara = strcmp(confederacionUno, confederacionDos);
	if (compara > 0) //primero MAYOR
			{
		retorno = 1;
	} else {
		if (compara < 0) //segundo MAYOR
				{
			retorno = -1;
		}
	}
	return retorno;
}
