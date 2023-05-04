#include "informes.h"

int main(void) {

	setbuf(stdout, NULL);

	eJugador jugadores[TAMJUGADORES] = { { 1, "Lionel Messi", "Delantero", 10,
			101, 200000, 4, OCUPADO }, { 2, "HULK", "Delantero", 7, 102, 100000,
			3, OCUPADO }, { 3, "Franco Armani", "Arquero", 1, 100, 80000, 2,
	OCUPADO } };

	eConfederacion confederaciones[TAMCONFEDERACIONES] = { { 100, "CONMEBOL",
			"Sudamerica", 1916, OCUPADO }, { 101, "UEFA", "Europa", 1954,
	OCUPADO }, { 102, "AFC", "Asia", 1954, OCUPADO }, { 103, "CAF", "Africa",
			1957, OCUPADO }, { 104, "CONCACAF", "Norte y Centro America", 1961,
	OCUPADO }, { 105, "OFC", "Oceania", 1966, OCUPADO } };

	int opcion;
	int ultimoIdIngresado = 4;
	int contadorJugadores = 3;

	//jugador_inicializarArray(jugadores, TAMJUGADORES);
	//confederacion_inicializarArray(jugadores, TAMJUGADORES);

	do {

		pedirEntero(&opcion,
				"----------------------------"
						"\nSubMenu Informes\n\n"
						"1. ALTA JUGADOR\n"
						"2. MODIFICAR JUGADOR\n"
						"3. BAJA JUGADOR\n"
						"4. INFORMES"
						"		\n\t-Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador."
						"		\n\t-Listado de confederaciones con sus jugadores."
						"		\n\t-Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio."
						"		\n\t-Informar la confederación con mayor cantidad de años de contratos total."
						"		\n\t-Informar porcentaje de jugadores por cada confederación."
						"		\n\t-Informar cual es la región con más jugadores y el listado de los mismos.\n"
						"5. SALIR\n"
						"----------------------------\n"
						"Ingrese una opcion (1-5): ",
				"----------------------------"
						"\nSubMenu Informes\n\n"
						"1. ALTA JUGADOR\n"
						"2. MODIFICAR JUGADOR\n"
						"3. BAJA JUGADOR\n"
						"4. INFORMES"
						"		\n\t-Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador."
						"		\n\t-Listado de confederaciones con sus jugadores."
						"		\n\t-Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio."
						"		\n\t-Informar la confederación con mayor cantidad de años de contratos total."
						"		\n\t-Informar porcentaje de jugadores por cada confederación."
						"		\n\t-Informar cual es la región con más jugadores y el listado de los mismos.\n"
						"5. SALIR\n"
						"----------------------------\n"
						"Opcion invalida, reingrese (1-5): ", 1, 5);

		switch (opcion) {
		case 1:

			if (jugador_agregarUno(jugadores, TAMJUGADORES, confederaciones,
			TAMCONFEDERACIONES, &ultimoIdIngresado)) {

				contadorJugadores++;

			}

			system("pause");
			system("cls");

			break;

		case 2:

			if (contadorJugadores > 0) {

				jugador_mostrarTodos(jugadores, TAMJUGADORES, confederaciones,
				TAMCONFEDERACIONES);

				jugador_modificarUno(jugadores, TAMJUGADORES, confederaciones,
				TAMCONFEDERACIONES);

			} else {

				printf("\nNo hay jugadores cargados...\n");

			}

			system("pause");
			system("cls");

			break;

		case 3:

			if (contadorJugadores > 0) {

				jugador_mostrarTodos(jugadores, TAMJUGADORES, confederaciones,
				TAMCONFEDERACIONES);

				if (jugador_borrarUno(jugadores, TAMJUGADORES, confederaciones,
				TAMCONFEDERACIONES)) {

					contadorJugadores--;

				}

			} else {

				printf("\nNo hay jugadores cargados...\n");

			}

			system("pause");
			system("cls");

			break;

		case 4:

			if (contadorJugadores > 0) {

				subMenuInformes(jugadores, TAMJUGADORES, confederaciones,
				TAMCONFEDERACIONES);

			} else {

				printf("\nNo hay empleados cargados...\n");

			}

			system("pause");
			system("cls");

			break;

		case 5:

			if (!verificarConfirmacion("\nDesea salir del programa? ('s'): ")) {

				printf("\nPROGRAMA FINALIZADO");

			} else {

				opcion = 0;

			}

			break;

		}

	} while (opcion != 5);

	return EXIT_SUCCESS;
}
