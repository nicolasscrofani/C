#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eCompras.h"

/**
 * @brief Parsea los datos los datos de la compra desde el archivo data.csv (modo texto).
 *
 * @param pFile puntero al archivo
 * @param pArrayListCompra puntero a la lista
 * @return 0 todo ok, -1 error
 */
int parser_CompraFromText(FILE *pFile, LinkedList *pArrayListCompra) {

	char codigoCompra[50];
	char descripcion[50];
	char origen[50];
	char precioUnitario[50];
	char cantidad[50];
	char totalCompra[50];
	eCompra *pCompra;

	if (pFile != NULL && pArrayListCompra != NULL) {

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", codigoCompra,
				descripcion, origen, precioUnitario, cantidad, totalCompra);

		while (!feof(pFile)) {
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", codigoCompra,
					descripcion, origen, precioUnitario, cantidad, totalCompra);

			if (feof(pFile)) {
				break;
			}

			pCompra = eCompra_newParametros(codigoCompra, descripcion, origen,
					precioUnitario, cantidad, totalCompra);
			ll_add(pArrayListCompra, pCompra);
		}

		eCompra_delete(pCompra);

		fclose(pFile);
		pFile = NULL;
		return 0;
	}

	return 1;
}


