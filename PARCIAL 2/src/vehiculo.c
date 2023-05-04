#include "vehiculo.h"

void vehiculo_inicializarArray(eVehiculo *vehiculos, int tam) {
	int i;

	if (vehiculos != NULL && tam > 0) {

		for (i = 0; i < tam; i++) {

			(*(vehiculos + i)).estado = VACIO;
		}
	}
}

void vehiculo_mostrarUno(eVehiculo vehiculo, eTipo *tipos, int tam) {

	char descripcionTipo[51];

	if (tipos != NULL && tam > 0) {

		if (tipo_obtenerDescripcion(tipos, tam, vehiculo.tipoId,
				descripcionTipo)) {

			printf("%-10d %-20s %-20d %-20s %-20s\n", vehiculo.idVehiculo,
					vehiculo.descripcion, vehiculo.modelo, vehiculo.color,
					descripcionTipo);

		}
	}
}

void vehiculo_mostrarTodos(eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos,
		int tamTipos) {

	int i;

	if (vehiculos != NULL && tamVehiculos > 0 && tipos != NULL
			&& tamTipos > 0) {

		printf("\nMostrando vehiculos...\n\n"
				"\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DESCRIPCION",
				"MODELO", "COLOR", "TIPO");

		for (i = 0; i < tamVehiculos; i++) {

			if ((*(vehiculos + i)).estado == OCUPADO) {

				vehiculo_mostrarUno(*(vehiculos + i), tipos, tamTipos);
			}
		}
		printf("\n");
	}
}

int vehiculo_buscarEspacioLibre(eVehiculo *vehiculos, int tam) {

	int i;
	int index = -1;

	if (vehiculos != NULL && tam > 0) {

		for (i = 0; i < tam; i++) {

			if ((*(vehiculos + i)).estado == VACIO) {

				index = i;
				break;
			}
		}
	}
	return index;
}

int vehiculo_buscarPorId(eVehiculo *vehiculos, int tam, int id) {

	int i;
	int index = -1;

	if (vehiculos != NULL && tam > 0) {

		for (i = 0; i < tam; i++) {

			if ((*(vehiculos + i)).estado == OCUPADO
					&& (*(vehiculos + i)).idVehiculo == id) {

				index = i;

				break;
			}
		}

	}

	return index;
}

int vehiculo_obtenerId(eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos,
		int tamTipos) {
	int opcion;
	int index = -1;

	if (vehiculos != NULL && tamVehiculos > 0 && tipos != NULL
			&& tamTipos > 0) {
		while (index == -1) {
			vehiculo_mostrarTodos(vehiculos, tamVehiculos, tipos, tamTipos);
			pedirEntero(&opcion, "Ingrese su vehiculo(10000-20000): ",
					"Error. opcion inválida. Reingrese su vehiculo(10000-20000): ",
					10000, 20000);

			if (vehiculo_buscarPorId(vehiculos, tamVehiculos, opcion) != -1) {
				return opcion;
			} else {
				printf(
						"\nError. No se encuentra al vehiculo bajo esa ID (ID: %d)\n",
						opcion);
			}
		}
	}
	return -1;
}

int vehiculo_agregarUno(eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos,
		int tamTipos, int *id) {

	int rtn = -1;
	int nuevoId;
	int index;
	int idTipo;

	if (vehiculos != NULL && tipos != NULL && tamVehiculos > 0
			&& tamTipos > 0) {
		printf("ALTA DE VEHICULO\n");

		index = vehiculo_buscarEspacioLibre(vehiculos, tamVehiculos);

		idTipo = tipo_obtenerId(tipos, tamTipos);

		nuevoId = *id;

		if (index != -1) {

			(*(vehiculos + index)).idVehiculo = nuevoId;

			(*(vehiculos + index)).tipoId = idTipo;

			pedirCadena((*(vehiculos + index)).descripcion,
					"Ingrese descripcion: ",
					"descripcion invalida, reingrese: ", 51);

			pedirEntero(&(*(vehiculos + index)).modelo,
					"Ingrese modelo(2000-2022): ",
					"Modelo invalido, reingrese(2000-2022): ", 2000, 2022);

			pedirCadenaAlfabetica((*(vehiculos + index)).color,
					"Ingrese color: ",
					"color invalido, reingrese(maximo 10 caracteres, solo caracteres alfabeticos): ",
					10);

			printf("\nMostrando nuevo vehiculo...\n\n"
					"\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DESCRIPCION",
					"MODELO", "COLOR", "TIPO");

			vehiculo_mostrarUno(*(vehiculos + index), tipos, tamTipos);

			if (!verificarConfirmacion("\nConfirmar? Ingrese 's': ")) {

				(*(vehiculos + index)).estado = OCUPADO;

				nuevoId++;

				*id = nuevoId;

				printf("\nSe dio de alta un vehiculo!\n");

				rtn = 1;

			} else {

				printf("\nSe canceló el alta del vehiculo...\n");

			}

		} else {

			printf("\nNo pueden cargarse mas vehiculos...\n");

		}
	}

	return rtn;
}

int vehiculo_borrarUno(eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos,
		int tamTipos) {

	int rtn = -1;
	int index = -1;
	int idIngresado;

	if (vehiculos != NULL && tipos != NULL && tamVehiculos > 0
			&& tamTipos > 0) {

		pedirEntero(&idIngresado,
				"Ingrese ID del vehiculo a cancelar (10000-20000): ",
				"Error. Reingrese ID valido (10000-20000): ", 10000, 20000);

		index = vehiculo_buscarPorId(vehiculos, tamVehiculos, idIngresado);

		if (index != -1) {

			printf("\nVehiculo a cancelar\n\n"
					"\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DESCRIPCION",
					"MODELO", "COLOR", "TIPO");

			vehiculo_mostrarUno(*(vehiculos + index), tipos, tamTipos);

			if (!verificarConfirmacion("\nConfirmar baja? Ingrese 's': ")) {

				(*(vehiculos + index)).estado = VACIO;

				printf("vehiculo dado de baja correctamente! (ID: %d)\n\n",
						(*(vehiculos + index)).idVehiculo);

				rtn = 1;
			} else {

				printf("\nSe cancelo la baja del vehiculo\n\n");
			}

		} else {

			printf("\nNo hay vehiculos bajo ese ID\n\n");
		}
	}
	return rtn;
}

int vehiculo_modificarUno(eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos,
		int tamTipos) {

	int rtn = -1;
	int index;
	int idIngresado;
	int opcion;
	eVehiculo auxVehiculo;

	if (vehiculos != NULL && tipos != NULL && tamVehiculos > 0
			&& tamTipos > 0) {

		pedirEntero(&idIngresado, "Ingrese ID del vehiculo a modificar: ",
				"Error. Ingrese ID valido: ", 10000, 20000);

		index = vehiculo_buscarPorId(vehiculos, tamVehiculos, idIngresado);

		if (index != -1) {

			do {
				auxVehiculo = *(vehiculos + index);

				printf("MODIFICAR VEHICULO");
				printf("\nVehiculo a modificar\n\n"
						"\n%-10s %-20s %-20s %-20s %-20s\n", "ID",
						"DESCRIPCION", "MODELO", "COLOR", "TIPO");

				vehiculo_mostrarUno(*(vehiculos + index), tipos, tamTipos);

				pedirEntero(&opcion, "-------------------------------------\n"
						"1. MODIFICAR DESCRIPCION\n"
						"2. MODIFICAR MODELO\n"
						"3. ATRAS\n"
						"-------------------------------------\n"
						"Ingrese una opcion: ",
						"-------------------------------------\n"
								"1. MODIFICAR DESCRIPCION\n"
								"2. MODIFICAR MODELO\n"
								"3. ATRAS\n"
								"-------------------------------------\n"
								"Opcion invalida, reingrese: ", 1, 3);
				switch (opcion) {

				case 1:

					printf("\nVehiculo a modificar\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s\n", "ID",
							"DESCRIPCION", "MODELO", "COLOR", "TIPO");

					vehiculo_mostrarUno(*(vehiculos + index), tipos, tamTipos);

					printf("\n");

					pedirCadena(auxVehiculo.descripcion,
							"Ingrese descripcion: ",
							"Descripcion invalida, reingrese: ", 51);

					printf("\nVehiculo modificado\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s\n", "ID",
							"DESCRIPCION", "MODELO", "COLOR", "TIPO");

					vehiculo_mostrarUno(auxVehiculo, tipos, tamTipos);

					if (!verificarConfirmacion(
							"\nGuardar cambios? Ingresar 's': ")) {

						strcpy((*(vehiculos + index)).descripcion,
								auxVehiculo.descripcion);

						printf("\nDescripcion modificada correctamente!\n");

						rtn = 1;

					} else {

						printf("\nSe canceló la modificacion\n");

					}

					system("pause");
					system("cls");

					break;

				case 2:

					printf("\nVehiculo a modificar\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s\n", "ID",
							"DESCRIPCION", "MODELO", "COLOR", "TIPO");

					vehiculo_mostrarUno(*(vehiculos + index), tipos, tamTipos);

					printf("\n");

					pedirEntero(&auxVehiculo.modelo,
							"Ingrese modelo(2000-2022): ",
							"Modelo invalido, reingrese(2000-2022): ", 2000,
							2022);

					printf("\nVehiculo modificado\n\n"
							"\n%-10s %-20s %-20s %-20s %-20s\n", "ID",
							"DESCRIPCION", "MODELO", "COLOR", "TIPO");

					vehiculo_mostrarUno(auxVehiculo, tipos, tamTipos);

					if (!verificarConfirmacion(
							"\nGuardar cambios? Ingresar 's': ")) {

						(*(vehiculos + index)).modelo = auxVehiculo.modelo;

						printf("\nModelo modificado correctamente\n!");

						rtn = 1;

					} else {

						printf("\nSe canceló la modificacion\n");

					}

					system("pause");
					system("cls");

					break;

				case 3:

					if (!verificarConfirmacion(
							"\nVolver atrás? Ingresar 's': ")) {

						printf("\nVolviendo al menú principal\n\n");

					} else {

						opcion = 0;

					}

					break;
				}

			} while (opcion != 3);

		} else {

			printf("\nError. Vehiculo no encontrada bajo ese id...\n\n");
		}
	}

	return rtn;
}

int vehiculo_mostrarDeUnTipo(eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos) {

	int rtn = -1;
	int index = -1;
	int idIngresado;
	int i;

	if (tipos != NULL && vehiculos != NULL && tamVehiculos > 0 && tamTipos > 0) {

		tipo_mostrarTodos(tipos, tamTipos);

		pedirEntero(&idIngresado, "Ingrese ID del tipo a mostrar (1000-1002): ",
				"Error. Reingrese ID del tipo a mostrar (1000-1002): ", 1000,
				1002);

		index = tipo_buscarPorId(tipos, tamTipos, idIngresado);

		if (index != -1) {

			printf("\nMOSTRANDO VEHICULOS\n\n"
					"\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DESCRIPCION",
					"MODELO", "COLOR", "TIPO");

			for (i = 0; i < tamVehiculos; i++) {

				if ((*(vehiculos + i)).estado == OCUPADO
						&& idIngresado == (*(vehiculos + i)).tipoId) {

					vehiculo_mostrarUno(*(vehiculos + i), tipos, tamTipos);

				}
			}

		}

		rtn = 1;
	}

	return rtn;
}

void tipo_mostrarUno(eTipo tipo) {

	printf("%-10d %-20s", tipo.idTipo, tipo.descripcionTipo);

}

void tipo_mostrarTodos(eTipo *tipos, int tam) {

	int i;

	if (tipos != NULL && tam > 0) {

		printf("\nMostrando tipos...\n\n"
				"\n%-10s %-20s\n", "ID", "DESCRIPCION");

		for (i = 0; i < tam; i++) {

			if ((*(tipos + i)).estado == OCUPADO) {

				tipo_mostrarUno(*(tipos + i));
				printf("\n");
			}
		}
		printf("\n");
	}
}

int tipo_buscarPorId(eTipo *tipos, int tam, int id) {

	int i;
	int index = -1;

	if (tipos != NULL && tam > 0) {

		for (i = 0; i < tam; i++) {

			if ((*(tipos + i)).estado == OCUPADO
					&& (*(tipos + i)).idTipo == id) {

				index = i;

				break;
			}
		}

	}

	return index;
}

int tipo_obtenerId(eTipo *tipos, int tamTipos) {
	int opcion;
	int index = -1;

	if (tipos != NULL && tamTipos > 0) {
		while (index == -1) {
			tipo_mostrarTodos(tipos, tamTipos);
			pedirEntero(&opcion, "Ingrese id del tipo(1000-1002): ",
					"Error. opcion inválida. Reingrese id del tipo(1000-1002): ",
					1000, 1002);

			if (tipo_buscarPorId(tipos, tamTipos, opcion) != -1) {
				return opcion;
			} else {
				printf(
						"\nError. No se encuentra al tipo bajo esa ID (ID: %d)\n",
						opcion);
			}
		}
	}
	return -1;
}

int tipo_obtenerDescripcion(eTipo *tipos, int tam, int id, char *descripcion) {

	int rtn = -1;
	int i;

	if (tipos != NULL && descripcion != NULL && tam > 0) {

		for (i = 0; i < tam; i++) {

			if (id == (*(tipos + i)).idTipo) {

				strcpy(descripcion, (*(tipos + i)).descripcionTipo);

				rtn = 1;

				break;

			}

		}
	}
	return rtn;
}
