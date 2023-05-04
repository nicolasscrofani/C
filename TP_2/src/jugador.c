#include "jugador.h"

void jugador_inicializarArray(eJugador *jugadores, int tamJugadores) {

	int i;

	if (jugadores != NULL && tamJugadores > 0) {

		for (i = 0; i < tamJugadores; i++) {

			(*(jugadores + i)).estado = VACIO;
		}
	}
}

void jugador_mostrarUno(eJugador jugador, eConfederacion *confederaciones,
		int tamConfederaciones) {

	char nombreConfederacion[51];

	if (confederaciones != NULL && tamConfederaciones > 0) {

		if (confederacion_obtenerNombre(confederaciones, tamConfederaciones,
				jugador.idConfederacion, nombreConfederacion)) {

			printf("%-10d %-20s %-20s %-20d %-20s %-20.2f %-20d\n", jugador.id,
					jugador.nombre, jugador.posicion, jugador.numeroCamiseta,
					nombreConfederacion, jugador.salario,
					jugador.aniosContrato);

		}
	}
}

void jugador_mostrarTodos(eJugador *jugadores, int tamJugadores,
		eConfederacion *confederaciones, int tamConfederaciones) {

	int i;

	if (jugadores != NULL && tamJugadores > 0 && confederaciones != NULL
			&& tamConfederaciones > 0) {

		printf("\nMostrando jugadores...\n\n"
				"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE",
				"POSICION", "NUMERO DE CAMISETA", "CONFEDERACION", "SALARIO",
				"AÑOS DE CONTRATO");

		for (i = 0; i < tamJugadores; i++) {

			if ((*(jugadores + i)).estado == OCUPADO) {

				jugador_mostrarUno(*(jugadores + i), confederaciones,
						tamConfederaciones);
			}
		}
		printf("\n");
	}
}

int jugador_buscarEspacioLibre(eJugador *jugadores, int tamJugadores) {

	int i;
	int index = -1;

	if (jugadores != NULL && tamJugadores > 0) {

		for (i = 0; i < tamJugadores; i++) {

			if ((*(jugadores + i)).estado == VACIO) {

				index = i;
				break;
			}
		}
	}
	return index;
}

int jugador_buscarPorId(eJugador *jugadores, int tamJugadores, int id) {

	int i;
	int index = -1;

	if (jugadores != NULL && tamJugadores > 0) {

		for (i = 0; i < tamJugadores; i++) {

			if ((*(jugadores + i)).estado == OCUPADO
					&& (*(jugadores + i)).id == id) {

				index = i;

				break;
			}
		}

	}

	return index;
}

int jugador_obtenerId(eJugador *jugadores, int tamJugadores,
		eConfederacion *confederaciones, int tamConfederaciones) {

	int opcion;
	int index = -1;

	if (jugadores != NULL && tamJugadores > 0 && confederaciones != NULL
			&& tamConfederaciones > 0) {

		while (index == -1) {

			jugador_mostrarTodos(jugadores, tamJugadores, confederaciones,
					tamConfederaciones);

			pedirEntero(&opcion, "Ingrese ID del jugador(1-30000): ",
					"Error. opcion inválida. Reingrese ID(1-30000): ", 1, 3000);

			if (jugador_buscarPorId(jugadores, tamJugadores, opcion) != -1) {

				return opcion;

			} else {

				printf(
						"\nError. No se encuentra al jugador bajo esa ID (ID: %d)\n",
						opcion);
			}
		}
	}
	return -1;
}

int jugador_obtenerNombre(eJugador *jugadores, int tamJugadores, int id,
		char *nombre) {

	int rtn = -1;
	int i;

	if (jugadores != NULL && tamJugadores > 0) {

		for (i = 0; i < tamJugadores; i++) {

			if (id == (*(jugadores + i)).id) {
				strcpy(nombre, (*(jugadores + i)).nombre);
				rtn = 1;
			}

		}
	}
	return rtn;
}

int jugador_obtenerCantidad(eJugador *jugadores, int tamJugadores) {

	int rtn = -1;
	int cantidad = 0;
	int i;

	if (jugadores != NULL && tamJugadores > 0) {
		for (i = 0; i < tamJugadores; i++) {
			if ((*(jugadores + i)).estado == OCUPADO) {
				cantidad++;
			}
		}

		rtn = cantidad;
	}
	return rtn;
}

int jugador_agregarUno(eJugador *jugadores, int tamJugadores,
		eConfederacion *confederaciones, int tamConfederaciones, int *id) {

	int rtn = -1;
	int nuevoId;
	int index;
	int idConfederacion;

	if (jugadores != NULL && confederaciones != NULL && tamJugadores > 0
			&& tamConfederaciones > 0) {

		printf("ALTA DE JUGADOR\n");

		index = jugador_buscarEspacioLibre(jugadores, tamJugadores);

		idConfederacion = confederacion_obtenerId(confederaciones,
				tamConfederaciones);

		nuevoId = *id;

		if (index != -1) {

			(*(jugadores + index)).id = nuevoId;

			(*(jugadores + index)).idConfederacion = idConfederacion;

			pedirCadenaAlfabetica((*(jugadores + index)).nombre,
					"Ingrese nombre: ", "nombre invalido, reingrese: ", 50);

			pedirCadenaAlfabetica((*(jugadores + index)).posicion,
					"Ingrese posicion: ", "posicion invalida, reingrese): ",
					50);

			pedirShort(&(*(jugadores + index)).numeroCamiseta,
					"Ingrese numero de la camiseta(1-99): ",
					"Error. Reingrese numero de la camiseta(1-99): ", 1, 99);

			pedirFlotante(&(*(jugadores + index)).salario, "Ingrese salario(1-999999): ",
					"Error. Reingrese salario valido (1-999999): ", 1, 999999);

			pedirShort(&(*(jugadores + index)).aniosContrato,
					"Ingrese años de contrato(1-10): ",
					"Error. Reingrese años de contrato(1-10): ", 1, 10);

			printf("\nMostrando nuevo Jugador...\n\n"
					"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID",
					"NOMBRE", "POSICION", "NUMERO DE CAMISETA", "CONFEDERACION",
					"SALARIO", "AÑOS DE CONTRATO");

			jugador_mostrarUno(*(jugadores + index), confederaciones,
					tamConfederaciones);

			if (!verificarConfirmacion("\nConfirmar? Ingrese 's': ")) {

				(*(jugadores + index)).estado = OCUPADO;

				nuevoId++;

				*id = nuevoId;

				printf("\nSe dio de alta un Jugador!\n");

				rtn = 1;

			} else {

				printf("\nSe canceló el alta del Jugador...\n");

			}

		} else {

			printf("\nNo pueden cargarse mas Jugadores...\n");

		}
	}

	return rtn;
}

int jugador_borrarUno(eJugador *jugadores, int tamJugadores,
		eConfederacion *confederaciones, int tamConfederaciones) {

	int rtn = -1;
	int index = -1;
	int idIngresado;

	if (jugadores != NULL && confederaciones != NULL && tamJugadores > 0
			&& tamConfederaciones > 0) {

		pedirEntero(&idIngresado,
				"Ingrese ID del jugador a cancelar (1-30000): ",
				"Error. Reingrese ID valido (1-30000): ", 1, 30000);

		index = jugador_buscarPorId(jugadores, tamJugadores, idIngresado);

		if (index != -1) {

			printf("\njugador a cancelar\n\n"
					"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID",
					"NOMBRE", "POSICION", "NUMERO DE CAMISETA", "CONFEDERACION",
					"SALARIO", "AÑOS DE CONTRATO");

			jugador_mostrarUno(*(jugadores + index), confederaciones,
					tamConfederaciones);

			if (!verificarConfirmacion("\nConfirmar baja? Ingrese 's': ")) {

				(*(jugadores + index)).estado = VACIO;

				printf("jugador dado de baja correctamente! (ID: %d)\n\n",
						(*(jugadores + index)).id);

				rtn = 1;
			} else {

				printf("\nSe cancelo la baja del jugador\n\n");
			}

		} else {

			printf("\nNo hay jugador bajo ese ID\n\n");
		}
	}
	return rtn;
}

int jugador_modificarUno(eJugador *jugadores, int tamJugadores,
		eConfederacion *confederaciones, int tamConfederaciones) {

	int rtn = -1;
	int index;
	int idIngresado;
	int opcion;
	eJugador auxJugador;

	if (jugadores != NULL && confederaciones != NULL && tamJugadores > 0
			&& tamConfederaciones > 0) {

		pedirEntero(&idIngresado, "Ingrese ID del jugador a modificar(1-3000): ",
				"Error. Ingrese ID valido(1-3000): ", 1, 30000);

		index = jugador_buscarPorId(jugadores, tamJugadores, idIngresado);

		if (index != -1) {

			do {
				auxJugador = *(jugadores + index);

				printf("MODIFICAR JUGADOR");
				printf("\nJugador a modificar\n\n"
						"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID",
						"NOMBRE", "POSICION", "NUMERO DE CAMISETA",
						"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

				jugador_mostrarUno(*(jugadores + index), confederaciones,
						tamConfederaciones);

				pedirEntero(&opcion, "-------------------------------------\n"
						"1. MODIFICAR NOMBRE\n"
						"2. MODIFICAR POSICION\n"
						"3. MODIFICAR NUMERO DE CAMISETA\n"
						"4. MODIFICAR CONFEDERACION\n"
						"5. MODIFICAR SALARIO\n"
						"6. MODIFICAR AÑOS DE CONTRATO\n"
						"7. ATRAS\n"
						"-------------------------------------\n"
						"Ingrese una opcion: ",
						"-------------------------------------\n"
								"1. MODIFICAR NOMBRE\n"
								"2. MODIFICAR POSICION\n"
								"3. MODIFICAR NUMERO DE CAMISETA\n"
								"4. MODIFICAR CONFEDERACION\n"
								"5. MODIFICAR SALARIO\n"
								"6. MODIFICAR AÑOS DE CONTRATO\n"
								"7. ATRAS\n"
								"-------------------------------------\n"
								"Opcion invalida, reingrese: ", 1, 7);
				switch (opcion) {

				case 1:

					printf("\nJugador a modificar\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n",
							"ID", "NOMBRE", "POSICION", "NUMERO DE CAMISETA",
							"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

					jugador_mostrarUno(*(jugadores + index), confederaciones,
							tamConfederaciones);

					printf("\n");

					pedirCadenaAlfabetica(auxJugador.nombre, "Ingrese nombre: ",
							"nombre invalido, reingrese: ", 50);

					printf("\nJugador modificado\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n",
							"ID", "NOMBRE", "POSICION", "NUMERO DE CAMISETA",
							"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

					jugador_mostrarUno(auxJugador, confederaciones,
							tamConfederaciones);

					if (!verificarConfirmacion(
							"\nGuardar cambios? Ingresar 's': ")) {

						strcpy((*(jugadores + index)).nombre,
								auxJugador.nombre);

						printf("\nNombre modificado correctamente!\n");

						rtn = 1;

					} else {

						printf("\nSe canceló la modificacion\n");

					}

					system("pause");
					system("cls");

					break;

				case 2:

					printf("\nJugador a modificar\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n",
							"ID", "NOMBRE", "POSICION", "NUMERO DE CAMISETA",
							"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

					jugador_mostrarUno(*(jugadores + index), confederaciones,
							tamConfederaciones);

					printf("\n");

					pedirCadenaAlfabetica(auxJugador.posicion,
							"Ingrese posicion: ",
							"posicion invalida, reingrese: ", 50);

					printf("\nJugador modificado\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n",
							"ID", "NOMBRE", "POSICION", "NUMERO DE CAMISETA",
							"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

					jugador_mostrarUno(auxJugador, confederaciones,
							tamConfederaciones);

					if (!verificarConfirmacion(
							"\nGuardar cambios? Ingresar 's': ")) {

						strcpy((*(jugadores + index)).posicion,
								auxJugador.posicion);

						printf("\nPosicion modificada correctamente\n!");

						rtn = 1;

					} else {

						printf("\nSe canceló la modificacion\n");

					}

					system("pause");
					system("cls");

					break;

				case 3:

					printf("\nJugador a modificar\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n",
							"ID", "NOMBRE", "POSICION", "NUMERO DE CAMISETA",
							"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

					jugador_mostrarUno(*(jugadores + index), confederaciones,
							tamConfederaciones);

					printf("\n");

					pedirShort(&auxJugador.numeroCamiseta,
							"Ingrese numero de camiseta (1-99): ",
							"Error. Ingrese numero de camiseta valido(1-99): ",
							1, 99);

					printf("\nJugador modificado\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n",
							"ID", "NOMBRE", "POSICION", "NUMERO DE CAMISETA",
							"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

					jugador_mostrarUno(auxJugador, confederaciones,
							tamConfederaciones);

					if (!verificarConfirmacion(
							"\nGuardar cambios? Ingresar 's': ")) {

						(*(jugadores + index)).numeroCamiseta =
								auxJugador.numeroCamiseta;

						printf(
								"\nNumero de camiseta modificado correctamente\n!");

						rtn = 1;

					} else {

						printf("\nSe canceló la modificacion\n");

					}

					system("pause");
					system("cls");

					break;

				case 4:

					printf("\nJugador a modificar\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n",
							"ID", "NOMBRE", "POSICION", "NUMERO DE CAMISETA",
							"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

					jugador_mostrarUno(*(jugadores + index), confederaciones,
							tamConfederaciones);

					printf("\n");

					confederacion_mostrarTodos(confederaciones, tamConfederaciones);

					pedirEntero(&auxJugador.idConfederacion, "Ingrese id de la nueva confederacion(100-105): ",
							"Error. opcion inválida. Reingrese id valido de la nueva confederacion(100-105): ",
							100, 105);


					printf("\nJugador modificado\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n",
							"ID", "NOMBRE", "POSICION", "NUMERO DE CAMISETA",
							"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

					jugador_mostrarUno(auxJugador, confederaciones,
							tamConfederaciones);

					if (!verificarConfirmacion(
							"\nGuardar cambios? Ingresar 's': ")) {

						(*(jugadores + index)).idConfederacion =
								auxJugador.idConfederacion;

						printf("\nConfederacion modificada correctamente\n!");

						rtn = 1;

					} else {

						printf("\nSe canceló la modificacion\n");

					}

					system("pause");
					system("cls");

					break;

				case 5:

					printf("\nJugador a modificar\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n",
							"ID", "NOMBRE", "POSICION", "NUMERO DE CAMISETA",
							"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

					jugador_mostrarUno(*(jugadores + index), confederaciones,
							tamConfederaciones);

					printf("\n");

					pedirFlotante(&auxJugador.salario, "Ingrese salario(1-999999): ",
							"Error. Ingrese salario valido(1-999999): ", 1, 999999);

					printf("\nJugador modificado\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n",
							"ID", "NOMBRE", "POSICION", "NUMERO DE CAMISETA",
							"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

					jugador_mostrarUno(auxJugador, confederaciones,
							tamConfederaciones);

					if (!verificarConfirmacion(
							"\nGuardar cambios? Ingresar 's': ")) {

						(*(jugadores + index)).salario = auxJugador.salario;

						printf("\nSalario modificado correctamente\n!");

						rtn = 1;

					} else {

						printf("\nSe canceló la modificacion\n");

					}

					system("pause");
					system("cls");

					break;

				case 6:

					printf("\nJugador a modificar\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n",
							"ID", "NOMBRE", "POSICION", "NUMERO DE CAMISETA",
							"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

					jugador_mostrarUno(*(jugadores + index), confederaciones,
							tamConfederaciones);

					printf("\n");

					pedirShort(&auxJugador.aniosContrato,
							"Ingrese años de contrato(1-10): ",
							"Error. Ingrese numero valido(1-10): ", 1, 99);

					printf("\nJugador modificado\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n",
							"ID", "NOMBRE", "POSICION", "NUMERO DE CAMISETA",
							"CONFEDERACION", "SALARIO", "AÑOS DE CONTRATO");

					jugador_mostrarUno(auxJugador, confederaciones,
							tamConfederaciones);

					if (!verificarConfirmacion(
							"\nGuardar cambios? Ingresar 's': ")) {

						(*(jugadores + index)).aniosContrato =
								auxJugador.aniosContrato;

						printf(
								"\nAños de contrato modificado correctamente\n!");

						rtn = 1;

					} else {

						printf("\nSe canceló la modificacion\n");

					}

					system("pause");
					system("cls");

					break;

				case 7:

					if (!verificarConfirmacion(
							"\nVolver atrás? Ingresar 's': ")) {

						printf("\nVolviendo al menú principal\n\n");

					} else {

						opcion = 0;

					}

					break;
				}

			} while (opcion != 7);

		} else {

			printf("\nError. Jugador no encontrado bajo ese id...\n\n");
		}
	}

	return rtn;
}

void jugador_swapear(eJugador *jugador1, eJugador *jugador2) {
	eJugador auxJugador;

	auxJugador = *jugador1;
	*jugador1 = *jugador2;
	*jugador2 = auxJugador;
}
