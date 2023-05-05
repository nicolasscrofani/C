#include "servicio.h"
#include "vehiculo.h"

int main(void) {
	setbuf(stdout, NULL);

	eHojaServicio hojasServicio[TAMSERVICIOS] = { { 20000, 10000, "chapa", 2000,
			{ 1, 1, 2022 }, OCUPADO }, { 20001, 10001, "pintura", 1000, { 2, 2,
			2022 }, OCUPADO }, { 20002, 10002, "lavado", 500, { 3, 3, 2022 },
			OCUPADO } };

	eVehiculo vehiculos[TAMVEHICULOS] = { { 10000, "asd", 2000, "rojo", 1000,
			OCUPADO }, { 10001, "qwe", 2010, "blanco", 1001, OCUPADO }, { 10002,
			"zxc", 2022, "negro", 1002, OCUPADO } };

	eTipo tipos[TAMTIPOS] = { { 1000, "SEDAN 3PTAS", OCUPADO }, { 1001,
			"SEDAN 5PTAS",
			OCUPADO }, { 1002, "CAMIONETA", OCUPADO } };

	char opcion;
	char salir;
	int ultimoIdIngresadoVehiculo = 10003;
	int ultimoIdIngresadoServicio = 20003;
	int cantidadVehiculos = 3;
	int cantidadHojas = 3;

	//hojaServicio_inicializarArray(hojasServicio, TAMSERVICIOS);
	//vehiculo_inicializarArray(vehiculos, TAMVEHICULOS);

	do {

		printf("------------------------------"
				"\n\tMenu Principal\n\n"
				"A. ALTA VEHICULO\n"
				"B. MODIFICAR VEHICULO\n"
				"C. BAJA VEHICULO\n"
				"D. LISTAR VEHICULOS\n"
				"E. LISTAR TIPOS\n"
				"F. ALTA HOJA DE SERVICIO\n"
				"G. LISTAR HOJAS DE SERVICIO\n"
				"H. INFORMES\n"
				"I. SALIR\n"
				"------------------------------\n"
				"opcion: \n");

		fflush(stdin);
		scanf("%c", &opcion);
		opcion = toupper(opcion);

		switch (opcion) {

		case 'A':

			if (vehiculo_agregarUno(vehiculos, TAMVEHICULOS, tipos, TAMTIPOS,
					&ultimoIdIngresadoVehiculo)) {

				cantidadVehiculos++;

			}

			break;

		case 'B':

			if (cantidadVehiculos > 0) {

				vehiculo_mostrarTodos(vehiculos, TAMVEHICULOS, tipos, TAMTIPOS);

				vehiculo_modificarUno(vehiculos, TAMVEHICULOS, tipos, TAMTIPOS);

			} else {

				printf("\nNo hay vehiculos cargados...\n");

			}

			break;

		case 'C':

			if (cantidadVehiculos > 0) {

				vehiculo_mostrarTodos(vehiculos, TAMVEHICULOS, tipos, TAMTIPOS);

				if (vehiculo_borrarUno(vehiculos, TAMVEHICULOS, tipos,
				TAMTIPOS)) {

					cantidadVehiculos--;

				}

			} else {

				printf("\nNo hay vehiculos cargados...\n");

			}

			break;

		case 'D':

			if (cantidadVehiculos > 0) {

				vehiculo_mostrarTodos(vehiculos, TAMVEHICULOS, tipos, TAMTIPOS);

			} else {

				printf("\nNo hay vehiculos cargados...\n");

			}

			break;

		case 'E':

			tipo_mostrarTodos(tipos, TAMTIPOS);

			break;

		case 'F':

			if (cantidadVehiculos > 0) {

				if (hojaServicio_agregarUno(hojasServicio, TAMSERVICIOS,
						vehiculos,
						TAMVEHICULOS, tipos, TAMTIPOS,
						&ultimoIdIngresadoServicio)) {

					cantidadHojas++;

				}

			} else {

				printf("\nNo hay vehiculos cargados...\n");

			}

			break;

		case 'G':

			if (cantidadHojas > 0) {

				hojaServicio_mostrarTodos(hojasServicio, TAMSERVICIOS);

			} else {

				printf("\nNo hay Hojas cargadas...\n");

			}

			break;

		case 'H':

			if (cantidadVehiculos > 0) {

				int option;
				do {

					printf("\nINFORMES\n");

					pedirEntero(&option,
							"1. Mostrar vehiculos de un tipo seleccionado\n"
									"2. Mostrar todas las hojas de servicio efectuadas en una fecha seleccionada\n"
									"3. importe total de las hojas de servicio realizadas en un vehículo seleccionado\n"
									"4. importe total de todas las hojas de servicio de un tipo en una fecha seleccionada\n"
									"5. SALIR\n"
									"----------------------------\n"
									"Ingrese una opcion (1-5): ",
							"\n1. Mostrar vehiculos de un tipo seleccionado\n"
									"2. Mostrar todas las hojas de servicio efectuadas en una fecha seleccionada\n"
									"3. importe total de las hojas de servicio realizadas en un vehículo seleccionado\n"
									"4. importe total de todas las hojas de servicio de un tipo en una fecha seleccionada\n"
									"5. SALIR\n"
									"----------------------------\n"
									"Opcion invalida, reingrese (1-5): ", 1, 5);

					switch (option) {
					case 1:

						vehiculo_mostrarDeUnTipo(vehiculos, TAMVEHICULOS, tipos,
						TAMTIPOS);

						system("pause");
						system("cls");

						break;

					case 2:

						hojaServicio_mostrarLasDeUnaFecha(hojasServicio,
						TAMSERVICIOS);

						system("pause");
						system("cls");

						break;

					case 3:
						hojaServicio_importeTotalDeUnVehiculo(hojasServicio,
						TAMSERVICIOS, vehiculos, TAMVEHICULOS, tipos,
						TAMTIPOS);
						system("pause");
						system("cls");

						break;

					case 4:

						hojaServicio_importeTotalDeUnTipoEnUnaFecha(hojasServicio,
						TAMSERVICIOS, vehiculos, TAMVEHICULOS, tipos, TAMTIPOS);

						system("pause");
						system("cls");

						break;

					case 5:

						if (!verificarConfirmacion("\nDesea salir? ('s'): ")) {

						} else {

							option = 0;

						}

						break;

					}

				} while (option != 5);

			} else {

				printf("\nNo hay vehiculos cargados...\n");

			}

			break;

		case 'I':

			if (!verificarConfirmacion("\nDesea salir del programa? ('s'): ")) {

				salir = 'J';

				printf("\nPROGRAMA FINALIZADO");

			} else {

				opcion = 0;

			}

			break;

		default:
			printf("Opcion ingresada invalida, reingrese\n");

		}

	} while (salir != 'J');

	return EXIT_SUCCESS;
}

