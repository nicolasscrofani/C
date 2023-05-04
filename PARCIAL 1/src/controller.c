#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "controller.h"
#include "parser.h"
#include "eCompras.h"
#include "LinkedList.h"
#include "inputs.h"

/**
 * @brief Carga los datos de los servicios desde el archivo data.csv (modo texto)
 *
 * @param path nombre o ruta del archivo
 * @param pArrayListCompra puntero a la lista
 * @return 0 todo ok, 1 error
 */
int controller_loadFromText(char *path, LinkedList *pArrayListCompra) {

	FILE *pFile = fopen(path, "r");

	if (pFile != NULL && pArrayListCompra != NULL) {

		parser_CompraFromText(pFile, pArrayListCompra);
		fclose(pFile);
		pFile = NULL;

		return 0;
	}

	return 1;
}

/**
 * @brief guarda como texto la lista recibida
 *
 * @param path ruta donde se guarda la lista
 * @param pArrayListCompra puntero a la lista
 * @return 0 todo ok, 1 error
 */
int controller_saveAsText(char *path, LinkedList *pArrayListCompra) {

	int len;
	eCompra *auxCompra = NULL;

	FILE *pFile = fopen(path, "w");

	if (path != NULL && pArrayListCompra != NULL) {
		len = ll_len(pArrayListCompra);
		if (pFile != NULL) {
			fprintf(pFile, "%s",
					"codigo, descripcion, origen, precio unitario, cantidad, total\n");
			for (int i = 0; i < len; i++) {
				auxCompra = (eCompra*) ll_get(pArrayListCompra, i);
				fprintf(pFile, "%d, %s, %d, %.2f, %d, %.2f\n",
						(*(auxCompra)).codigoCompra, (*(auxCompra)).descripcion,
						(*(auxCompra)).origen, (*(auxCompra)).precioUnitario,
						(*(auxCompra)).cantidad, (*(auxCompra)).totalCompra);
			}

			fclose(pFile);
			pFile = NULL;
			auxCompra = NULL;
		} else {
			printf("Error.Archivo no creado");
		}

		return 0;
	}

	return 1;
}

/**
 * @brief muestra todos los servicios
 *
 * @param pArrayListCompra puntero a la lista
 * @return 0 todo ok, 1 error
 */
int controller_listarCompras(LinkedList *pArrayListCompra) {

	eCompra *pCompra = NULL;
	int len;
	if (pArrayListCompra != NULL) {
		len = ll_len(pArrayListCompra);
		printLine("LISTA DE COMPRAS");
		printf("%-30s %-30s %-30s %-30s %-30s %-30s\n\n", "CODIGO",
				"DESCRIPCION", "ORIGEN", "PRECIO UNITARIO", "CANTIDAD",
				"TOTAL");
		printLine("");
		for (int i = 0; i < len; i++) {
			pCompra = ll_get(pArrayListCompra, i);
			eCompra_listarUna(pCompra);
		}
		printLine("");
		return 0;
	}
	return 1;
}

/**
 * @brief calcula y carga el campo totalCompras multiplicando la cantidad de comporas * el precio unitario de cada uno
 *
 * @param pArrayListCompra puntero a la lista
 * @return 0 todo ok, -1 error
 */
int controller_totalCompras(LinkedList *pArrayListCompra) {

	int retorno = -1;
	void (*pFunc)(void *element);

	if (pArrayListCompra != NULL) {
		pFunc = eCompra_totalCompra;

		ll_map(pArrayListCompra, pFunc);


		retorno = 0;
	}
	return retorno;
}

/**
 * @brief filtra la linkedlist recibida y crea una nueva filtrada
 *
 * @param pArrayListCompra puntero a la lista
 * @return 0 todo ok, -1 error
 */
int controller_filtroAdministracion(LinkedList *pArrayListCompra) {

	int retorno = -1;
	LinkedList *listaFiltrada = NULL;

	if (pArrayListCompra != NULL) {

		listaFiltrada = ll_filter(pArrayListCompra,
				eCompra_filtroAdministracion);

		controller_listarCompras(listaFiltrada);

		controller_saveAsText("filtroPorAdministracion.csv", listaFiltrada);

		retorno = 0;
	}
	return retorno;
}

/**
 * @brief filtra la linkedlist recibida y crea una nueva filtrada
 *
 * @param pArrayListCompra puntero a la lista
 * @return 0 todo ok, -1 error
 */
int controller_filtroTaller(LinkedList *pArrayListCompra) {

	int retorno = -1;
	LinkedList *listaFiltrada = NULL;

	if (pArrayListCompra != NULL) {

		listaFiltrada = ll_filter(pArrayListCompra, eCompra_filtroTaller);

		controller_listarCompras(listaFiltrada);

		controller_saveAsText("filtroPorTaller.csv", listaFiltrada);

		retorno = 0;
	}
	return retorno;
}

/**
 * @brief filtra la linkedlist recibida y crea una nueva filtrada
 *
 * @param pArrayListCompra puntero a la lista
 * @return 0 todo ok, -1 error
 */
int controller_filtroVentas(LinkedList *pArrayListCompra) {

	int retorno = -1;
	LinkedList *listaFiltrada = NULL;

	if (pArrayListCompra != NULL) {

		listaFiltrada = ll_filter(pArrayListCompra, eCompra_filtroVentas);

		controller_listarCompras(listaFiltrada);

		controller_saveAsText("filtroPorVentas.csv", listaFiltrada);

		retorno = 0;
	}
	return retorno;
}

/**
 * @brief ordena las compras de manera ascendente
 *
 * @param pArrayServicios puntero a la lista
 * @return 0 todo ok, -1 error
 */
int controller_sortCompras(LinkedList *pArrayServicios) { //1 es de menor a mayor, 0 es de mayor a menor en ll_sort

	int retorno = -1;

	if (pArrayServicios != NULL) {

		printf("\n***Compras ordenadas por descripcion de manera ascendente***\n");

		ll_sort(pArrayServicios, eCompra_compareDescription, 1);
		controller_listarCompras(pArrayServicios);

		retorno = 0;
	}
	return retorno;
}


