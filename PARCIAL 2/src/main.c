#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "inputs.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcion = 0;
	int flagListaCargada = 0;

	LinkedList *listaCompras = ll_newLinkedList();

	do {
		printLine("MENU");

		printf("1) Cargar archivo\n");
		printf("2) Imprimir lista\n");
		printf("3) Asignar totales\n");
		printf("4) Filtrar por origen\n");
		printf("5) Mostrar compras\n");
		printf("6) Guardar compras\n");
		printf("7) Salir.\n");
		printLine("");

		opcion = getInt("\nIngrese una opcion (1-7): ",
				"\nError. Ingrese una opcion (1-7): ", 1, 7);

		switch (opcion) {
		case 1:

			if (flagListaCargada == 0) {

				if (listaCompras != NULL
						&& controller_loadFromText("data.csv", listaCompras)
								== 0) {

					printf("\nSe han cargado los datos exitosamente...\n");
					flagListaCargada = 1;

				} else {
					printf("\nError al cargar los datos...\n");
				}
			} else {
				printf("\nLa lista ya ha sido cargada...\n");
			}

			system("pause");
			break;

		case 2:

			if (flagListaCargada == 1) {
				if (controller_listarCompras(listaCompras) == 0) {

				} else {
					printf("\nError al listar los datos...\n");
				}
			} else {
				printf("Primero hay que cargar la lista (opcion 1)...\n");
			}
			system("pause");
			break;

		case 3:

			if (flagListaCargada == 1) {
				if (controller_totalCompras(listaCompras) == 0) {

					controller_listarCompras(listaCompras);

					printf("\nTOTALES ASIGNADOS CON EXITO\n");
				}
			} else {
				printf("Primero hay que cargar la lista (opcion 1)...\n");
			}
			system("pause");
			break;

		case 4:

			if (flagListaCargada == 1) {

				switch (menuOpcionFiltrarPorOrigen()) {

				case 1:
					controller_filtroAdministracion(listaCompras);
					break;
				case 2:
					controller_filtroTaller(listaCompras);
					break;
				case 3:
					controller_filtroVentas(listaCompras);
					break;
				case 4:
					printf("Volviendo al menu...\n");
					break;
				}
			} else {
				printf("Primero hay que cargar la lista (opcion 1)...\n");
			}
			system("pause");
			break;

		case 5:

			if (flagListaCargada == 1) {

				printf("\nEspere mientras se ordena la lista...\n");

				if (controller_sortCompras(listaCompras) == 0) {

				}

			} else {
				printf("Primero hay que cargar la lista (opcion 1)...\n");
			}
			system("pause");
			break;

		case 6:

			if (flagListaCargada == 1) {

				printf("\nEspere mientras se ordena la lista...\n");

				if (controller_sortCompras(listaCompras) == 0) {

					controller_saveAsText("comprasOrdenadas.csv", listaCompras);

					printf("\nLAS COMPRAS FUERON GUARDADAS CON EXITO\n");
				}

			} else {
				printf("Primero hay que cargar la lista (opcion 1)...\n");
			}
			system("pause");
			break;

		case 7:

			ll_deleteLinkedList(listaCompras);

			printLine("PROGRAMA FINALIZADO");

			break;
		}
	} while (opcion != 7);

	return EXIT_SUCCESS;
}

