#include "confederacion.h"

void confederacion_inicializarArray(eConfederacion *confederaciones,
		int tamConfederaciones) {

	int i;

	if (confederaciones != NULL && tamConfederaciones > 0) {

		for (i = 0; i < tamConfederaciones; i++) {

			(*(confederaciones + i)).estado = VACIO;
		}
	}

}

void confederacion_mostrarUno(eConfederacion confederacion) {

	printf("%-10d %-20s %-20s %-20d\n", confederacion.id, confederacion.nombre,
			confederacion.region, confederacion.anioCreacion);

}

void confederacion_mostrarTodos(eConfederacion *confederaciones,
		int tamConfederaciones) {

	int i;

	if (confederaciones != NULL && tamConfederaciones > 0) {

		printf("\nMostrando Confederaciones...\n\n"
				"\n%-10s %-20s %-20s %-20s\n", "ID", "NOMBRE", "REGION",
				"AÑO DE CREACION");

		for (i = 0; i < tamConfederaciones; i++) {

			if ((*(confederaciones + i)).estado == OCUPADO) {

				confederacion_mostrarUno(*(confederaciones + i));
				printf("\n");
			}
		}
		printf("\n");
	}
}

int confederacion_buscarEspacioLibre(eConfederacion *confederaciones,
		int tamConfederaciones) {

	int i;
	int index = -1;

	if (confederaciones != NULL && tamConfederaciones > 0) {

		for (i = 0; i < tamConfederaciones; i++) {

			if ((*(confederaciones + i)).estado == VACIO) {

				index = i;
				break;
			}
		}
	}
	return index;

}

int confederacion_buscarPorId(eConfederacion *confederaciones,
		int tamConfederaciones, int id) {

	int i;
	int index = -1;

	if (confederaciones != NULL && tamConfederaciones > 0) {

		for (i = 0; i < tamConfederaciones; i++) {

			if ((*(confederaciones + i)).estado == OCUPADO
					&& (*(confederaciones + i)).id == id) {

				index = i;

				break;
			}
		}

	}

	return index;
}

int confederacion_obtenerId(eConfederacion *confederaciones,
		int tamConfederaciones) {
	int opcion;
	int index = -1;

	if (confederaciones != NULL && tamConfederaciones > 0) {
		while (index == -1) {
			confederacion_mostrarTodos(confederaciones, tamConfederaciones);
			pedirEntero(&opcion, "Ingrese id de la confederacion(100-105): ",
					"Error. opcion inválida. Reingrese id de la confederacion(100-105): ",
					100, 105);

			if (confederacion_buscarPorId(confederaciones, tamConfederaciones,
					opcion) != -1) {
				return opcion;
			} else {
				printf(
						"\nError. No se encuentra a la confederacion bajo esa ID (ID: %d)\n",
						opcion);
			}
		}
	}
	return -1;
}

int confederacion_obtenerNombre(eConfederacion *confederaciones,
		int tamConfederaciones, int id, char *descripcion) {

	int rtn = -1;
	int i;

	if (confederaciones != NULL && descripcion != NULL
			&& tamConfederaciones > 0) {

		for (i = 0; i < tamConfederaciones; i++) {

			if (id == (*(confederaciones + i)).id) {

				strcpy(descripcion, (*(confederaciones + i)).nombre);

				rtn = 1;

				break;

			}

		}
	}
	return rtn;
}

int confederacion_agregarUno(eConfederacion *confederaciones,
		int tamConfederaciones, int *id) {

	int rtn = -1;
	int nuevoId;
	int index;


	if (confederaciones != NULL && tamConfederaciones > 0) {

		printf("ALTA DE CONFEDERACION\n");

		index = confederacion_buscarEspacioLibre(confederaciones,
				tamConfederaciones);

		nuevoId = *id;

		if (index != -1) {

			(*(confederaciones + index)).id = nuevoId;

			pedirCadenaAlfabetica((*(confederaciones + index)).nombre,
					"Ingrese nombre: ", "nombre invalido, reingrese: ", 50);

			pedirCadenaAlfabetica((*(confederaciones + index)).region,
					"Ingrese region: ", "region invalida, reingrese): ", 50);

			pedirEntero(&(*(confederaciones + index)).anioCreacion,
					"Ingrese año de creacion: ",
					"Error. Reingrese año de creacion: ", 1900, 2022);

			printf("\nMostrando nueva confederacion...\n\n"
					"\n%-10s %-20s %-20s %-20s\n", "ID", "NOMBRE", "REGION",
					"AÑO DE CREACION");

			confederacion_mostrarUno(*(confederaciones + index));

			if (!verificarConfirmacion("\nConfirmar? Ingrese 's': ")) {

				(*(confederaciones + index)).estado = OCUPADO;

				nuevoId++;

				*id = nuevoId;

				printf("\nSe dio de alta una confederacion!\n");

				rtn = 1;

			} else {

				printf("\nSe canceló el alta de la confederacion...\n");

			}

		} else {

			printf("\nNo pueden cargarse mas Jugadores...\n");

		}
	}

	return rtn;
}

int confederacion_borrarUno(eConfederacion *confederaciones,
		int tamConfederaciones) {

	int rtn = -1;
	int index = -1;
	int idIngresado;

	if (confederaciones != NULL && tamConfederaciones > 0) {

		pedirEntero(&idIngresado,
				"Ingrese ID de la confederacion a cancelar (100-105): ",
				"Error. Reingrese ID valido (100-105): ", 100, 105);

		index = confederacion_buscarPorId(confederaciones, tamConfederaciones,
				idIngresado);

		if (index != -1) {

			printf("\nconfederacion a cancelar\n\n"
					"\n%-10s %-20s %-20s %-20s\n", "ID", "NOMBRE", "REGION",
					"AÑO DE CREACION");

			confederacion_mostrarUno(*(confederaciones + index));
			if (!verificarConfirmacion("\nConfirmar baja? Ingrese 's': ")) {

				(*(confederaciones + index)).estado = VACIO;

				printf("confederacion dada de baja correctamente! (ID: %d)\n\n",
						(*(confederaciones + index)).id);

				rtn = 1;
			} else {

				printf("\nSe cancelo la baja de la confederacion\n\n");
			}

		} else {

			printf("\nNo hay confederaciones bajo ese ID\n\n");
		}
	}
	return rtn;
}

int confederacion_modificarUno(eConfederacion *confederaciones,
		int tamConfederaciones) {

	int rtn = -1;
	int index;
	int idIngresado;
	int opcion;
	eConfederacion auxConfederacion;

	if (confederaciones != NULL && tamConfederaciones > 0) {

		pedirEntero(&idIngresado,
				"Ingrese ID de la confederacion a modificar (100-105): ",
				"Error. Reingrese ID valido (100-105): ", 100, 105);

		index = confederacion_buscarPorId(confederaciones, tamConfederaciones,
				idIngresado);

		if (index != -1) {

			do {
				auxConfederacion = *(confederaciones + index);

				printf("MODIFICAR JUGADOR");
				printf("\nconfederacion a modificar\n\n"
						"\n%-10s %-20s %-20s %-20s\n", "ID", "NOMBRE", "REGION",
						"AÑO DE CREACION");

				confederacion_mostrarUno(*(confederaciones + index));

				pedirEntero(&opcion, "-------------------------------------\n"
						"1. MODIFICAR NOMBRE\n"
						"2. MODIFICAR REGION\n"
						"3. MODIFICAR AÑO DE CREACION\n"
						"4. ATRAS\n"
						"-------------------------------------\n"
						"Ingrese una opcion: ",
						"-------------------------------------\n"
								"1. MODIFICAR NOMBRE\n"
								"2. MODIFICAR REGION\n"
								"3. MODIFICAR AÑO DE CREACION\n"
								"4. ATRAS\n"
								"-------------------------------------\n"
								"Opcion invalida, reingrese: ", 1, 4);
				switch (opcion) {

				case 1:

					printf("\nconfederacion a modificar\n\n"
							"\n%-10s %-20s %-20s %-20s\n", "ID", "NOMBRE", "REGION",
							"AÑO DE CREACION");

					confederacion_mostrarUno(*(confederaciones + index));

					printf("\n");

					pedirCadenaAlfabetica(auxConfederacion.nombre,
							"Ingrese nombre: ", "nombre invalido, reingrese: ",
							50);

					printf("\nconfederacion modificada\n\n"
							"\n%-10s %-20s %-20s %-20s\n", "ID", "NOMBRE", "REGION",
							"AÑO DE CREACION");

					confederacion_mostrarUno(auxConfederacion);

					if (!verificarConfirmacion(
							"\nGuardar cambios? Ingresar 's': ")) {

						strcpy((*(confederaciones + index)).nombre,
								auxConfederacion.nombre);

						printf("\nNombre modificado correctamente!\n");

						rtn = 1;

					} else {

						printf("\nSe canceló la modificacion\n");

					}

					system("pause");
					system("cls");

					break;

				case 2:

					printf("\nconfederacion a modificar\n\n"
							"\n%-10s %-20s %-20s %-20s\n", "ID", "NOMBRE", "REGION",
							"AÑO DE CREACION");

					confederacion_mostrarUno(*(confederaciones + index));

					printf("\n");

					pedirCadenaAlfabetica(auxConfederacion.region,
							"Ingrese region: ",
							"region invalida, reingrese: ", 50);

					printf("\nconfederacion modificada\n\n"
							"\n%-10s %-20s %-20s %-20s\n", "ID", "NOMBRE", "REGION",
							"AÑO DE CREACION");

					confederacion_mostrarUno(auxConfederacion);

					if (!verificarConfirmacion(
							"\nGuardar cambios? Ingresar 's': ")) {

						strcpy((*(confederaciones + index)).region,
								auxConfederacion.region);

						printf("\nregion modificada correctamente\n!");

						rtn = 1;

					} else {

						printf("\nSe canceló la modificacion\n");

					}

					system("pause");
					system("cls");

					break;

				case 3:

					printf("\nconfederacion a modificar\n\n"
							"\n%-10s %-20s %-20s %-20s\n", "ID", "NOMBRE", "REGION",
							"AÑO DE CREACION");

					confederacion_mostrarUno(*(confederaciones + index));

					printf("\n");

					pedirEntero(&auxConfederacion.anioCreacion,
							"Ingrese año: ",
							"Error. Ingrese año valido: ",
							1900, 2022);

					printf("\nconfederacion modificada\n\n"
							"\n%-10s %-20s %-20s %-20s\n", "ID", "NOMBRE", "REGION",
							"AÑO DE CREACION");

					confederacion_mostrarUno(auxConfederacion);

					if (!verificarConfirmacion(
							"\nGuardar cambios? Ingresar 's': ")) {

						(*(confederaciones + index)).anioCreacion =
								auxConfederacion.anioCreacion;

						printf(
								"\nAño de creacion modificado correctamente\n!");

						rtn = 1;

					} else {

						printf("\nSe canceló la modificacion\n");

					}

					system("pause");
					system("cls");

					break;

				case 4:

					if (!verificarConfirmacion(
							"\nVolver atrás? Ingresar 's': ")) {

						printf("\nVolviendo al menú principal\n\n");

					} else {

						opcion = 0;

					}

					break;
				}

			} while (opcion != 4);

		} else {

			printf("\nError. Confederacion no encontrada bajo ese id...\n\n");
		}
	}

	return rtn;
}

void confederacion_swapear(eConfederacion *confederacion1,
		eConfederacion *confederacion2) {
	eConfederacion auxConfederacion;

	auxConfederacion = *confederacion1;
	*confederacion1 = *confederacion2;
	*confederacion2 = auxConfederacion;
}

