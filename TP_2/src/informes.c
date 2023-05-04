#include "informes.h"

int subMenuInformes(eJugador *jugadores, int tamJugadores,
		eConfederacion *confederaciones, int tamConfederaciones) {

	int rtn = -1;
	int opcion;

	if (jugadores != NULL && confederaciones != NULL && tamJugadores > 0
			&& tamConfederaciones > 0) {

		do {

			pedirEntero(&opcion,
					"----------------------------"
							"\nSubMenu informes\n\n"
							"1. Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador\n"
							"2. Listado de confederaciones con sus jugadores\n"
							"3. Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio\n"
							"4. Informar la confederación con mayor cantidad de años de contratos total\n"
							"5. Informar porcentaje de jugadores por cada confederación\n"
							"6. Informar cual es la región con más jugadores y el listado de los mismos\n"
							"7. ATRAS\n"
							"----------------------------\n"
							"Ingrese una opcion (1-7): ",
					"----------------------------"
							"\nSubMenu informes\n\n"
							"1. Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador\n"
							"2. Listado de confederaciones con sus jugadores\n"
							"3. Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio\n"
							"4. Informar la confederación con mayor cantidad de años de contratos total\n"
							"5. Informar porcentaje de jugadores por cada confederación\n"
							"6. Informar cual es la región con más jugadores y el listado de los mismos\n"
							"7. ATRAS\n"
							"----------------------------\n"
							"Opcion invalida, reingrese (1-7): ", 1, 7);

			switch (opcion) {
			case 1:
				for (int i = 0; i < 2; i++) {
					jugador_mostrarTodos(jugadores, TAMJUGADORES,
							confederaciones, TAMCONFEDERACIONES);

					informes_ordenar(jugadores, TAMJUGADORES, confederaciones,
					TAMCONFEDERACIONES, TAMNOMBRECONFEDERACION,
					TAMNOMBREJUGADOR);
				}
				system("pause");
				system("cls");

				break;

			case 2:

				jugador_mostrarTodos(jugadores, TAMJUGADORES, confederaciones,
				TAMCONFEDERACIONES);

				informes_listarPorConfederacion(confederaciones,
				TAMCONFEDERACIONES, jugadores, TAMJUGADORES);

				system("pause");
				system("cls");

				break;

			case 3:

				jugador_mostrarTodos(jugadores, TAMJUGADORES, confederaciones,
				TAMCONFEDERACIONES);

				informes_salarios(jugadores, TAMJUGADORES);

				system("pause");
				system("cls");

				break;

			case 4:

				jugador_mostrarTodos(jugadores, TAMJUGADORES, confederaciones,
				TAMCONFEDERACIONES);

				informes_confederacionConMasAniosDeContrato(jugadores,
				TAMJUGADORES, confederaciones, TAMCONFEDERACIONES);

				system("pause");
				system("cls");

				break;

			case 5:

				jugador_mostrarTodos(jugadores, TAMJUGADORES, confederaciones,
				TAMCONFEDERACIONES);

				informes_porcentajeJugadoresPorConfederacion(jugadores,
				TAMJUGADORES, confederaciones, TAMCONFEDERACIONES);

				system("pause");
				system("cls");

				break;

			case 6:

				jugador_mostrarTodos(jugadores, TAMJUGADORES, confederaciones,
				TAMCONFEDERACIONES);

				informes_regionMasJugadores(jugadores, TAMJUGADORES,
						confederaciones, TAMCONFEDERACIONES);

				system("pause");
				system("cls");

				break;

			case 7:

				if (!verificarConfirmacion("\nVOLVER ATRAS? ('s'): ")) {

				} else {

					opcion = 0;

				}

				break;

			}

		} while (opcion != 7);

		rtn = 1;
	}
	return rtn;
}

int informes_ordenar(eJugador *jugadores, int tamJugadores,
		eConfederacion *confederaciones, int tamConfederaciones,
		int tamNombreConf, int tamNombreJug) {

	int rtn = -1;
	int i;
	int j;
	char nombreJugadorUno[tamNombreJug];
	char nombreJugadorDos[tamNombreJug];
	char nombreConfederacionUno[tamNombreConf];
	char nombreConfederacionDos[tamNombreConf];

	if (jugadores != NULL && confederaciones != NULL && tamJugadores > 0
			&& tamConfederaciones > 0) {

		for (i = 0; i < tamJugadores - 1; i++) {

			for (j = i + 1; j < tamJugadores; j++) {

				if ((*(jugadores + i)).estado == 1
						&& (*(jugadores + j)).estado == 1) {

					confederacion_obtenerNombre(confederaciones,
							tamConfederaciones,
							(*(jugadores + i)).idConfederacion,
							nombreConfederacionUno);
					confederacion_obtenerNombre(confederaciones,
							tamConfederaciones,
							(*(jugadores + j)).idConfederacion,
							nombreConfederacionDos);
					strlwr(nombreConfederacionUno);
					strlwr(nombreConfederacionDos);

					if (strcmp(nombreConfederacionUno, nombreConfederacionDos)
							== 1) {

						jugador_swapear(&(*(jugadores + i)),
								&(*(jugadores + j)));
					}

					if ((*(jugadores + i)).idConfederacion
							== (*(jugadores + j)).idConfederacion) {

						jugador_obtenerNombre(jugadores, tamJugadores,
								(*(jugadores + i)).id, nombreJugadorUno);
						jugador_obtenerNombre(jugadores, tamJugadores,
								(*(jugadores + j)).id, nombreJugadorDos);
						strlwr(nombreJugadorUno);
						strlwr(nombreJugadorDos);

						if (strcmp(nombreJugadorUno, nombreJugadorDos) == 1) {

							jugador_swapear(&(*(jugadores + i)),
									&(*(jugadores + j)));
						}
					}
				}
			}
		}
		rtn = 1;
	}
	return rtn;
}

int informes_listarPorConfederacion(eConfederacion *confederaciones,
		int tamConfederaciones, eJugador *jugadores, int tamJugadores) {

	int rtn = -1;
	int i;
	int j;

	if (jugadores != NULL && tamJugadores > 0 && confederaciones != NULL
			&& tamConfederaciones > 0) {

		for (i = 0; i < tamConfederaciones; i++) {

			if ((*(confederaciones + i)).estado == OCUPADO) {

				printf(
						"\n-------------------------------------------------------------------------\n");
				printf("%s\n", (*(confederaciones + i)).nombre);
				printf(

				"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE",
						"POSICION", "NUMERO DE CAMISETA", "CONFEDERACION",
						"SALARIO", "AÑOS DE CONTRATO");

			}

			for (j = 0; j < tamJugadores; j++) {

				if ((*(jugadores + j)).estado == OCUPADO
						&& (*(confederaciones + i)).id
								== (*(jugadores + j)).idConfederacion) {

					jugador_mostrarUno(*(jugadores + j), confederaciones,
							tamConfederaciones);
					printf("\n");
				}
			}

		}
		rtn = 1;
	}

	return rtn;
}

int informes_salarios(eJugador *jugadores, int tamJugadores) {

	int rtn = -1;
	float acumSalario = 0;
	int cantidadJugadores = jugador_obtenerCantidad(jugadores, tamJugadores);
	float promedio;
	int contJugadoresConSalarioMayorAlPromedio = 0;

	if (jugadores != NULL && tamJugadores > 0) {

		for (int i = 0; i < tamJugadores; i++) {

			if ((*(jugadores + i)).estado == OCUPADO) {

				acumSalario += (*(jugadores + i)).salario;

			}
		}

		promedio = (float) acumSalario / cantidadJugadores;

		for (int i = 0; i < tamJugadores; i++) {

			if ((*(jugadores + i)).estado == OCUPADO
					&& promedio < (*(jugadores + i)).salario) {

				contJugadoresConSalarioMayorAlPromedio++;

			}
		}

		printf(
				"TOTAL DE TODOS LOS SALARIOS: %.2f\n\n"
						"EL SALARIO PROMEDIO ES: $%.2f\n\n"
						"LA CANTIDAD DE JUGADORES CON SUELDO MAYOR AL PROMEDIO ES: %d\n\n",
				acumSalario, promedio, contJugadoresConSalarioMayorAlPromedio);

		rtn = 1;

	}

	return rtn;

}

int informes_confederacionConMasAniosDeContrato(eJugador *jugadores,
		int tamJugadores, eConfederacion *confederaciones,
		int tamConfederaciones) {
	int rtn = -1;
	int acumCONMEBOL = 0;
	int acumUEFA = 0;
	int acumAFC = 0;
	int acumCAF = 0;
	int acumCONCACAF = 0;
	int acumOFC = 0;
	int i;

	if (jugadores != NULL && tamJugadores > 0 && confederaciones != NULL
			&& tamConfederaciones > 0) {

		for (i = 0; i < tamJugadores; i++) {

			if ((*(jugadores + i)).estado == OCUPADO) {

				switch ((*(jugadores + i)).idConfederacion) {

				case 100:
					acumCONMEBOL += (*(jugadores + i)).aniosContrato;

					break;
				case 101:
					acumUEFA += (*(jugadores + i)).aniosContrato;

					break;
				case 102:
					acumAFC += (*(jugadores + i)).aniosContrato;

					break;
				case 103:
					acumCAF += (*(jugadores + i)).aniosContrato;

					break;
				case 104:
					acumCONCACAF += (*(jugadores + i)).aniosContrato;

					break;
				case 105:
					acumOFC += (*(jugadores + i)).aniosContrato;

					break;
				}
			}

		}

		printf(
				"La/s confederación/es con mayor cantidad de años de contratos total es/son:\n\n");

		if (acumCONMEBOL >= acumUEFA && acumCONMEBOL >= acumAFC
				&& acumCONMEBOL >= acumCAF && acumCONMEBOL >= acumCONCACAF
				&& acumCONMEBOL >= acumOFC) {

			printf("-CONMEBOL con %d año/s\n", acumCONMEBOL);

		}
		if (acumUEFA >= acumCONMEBOL && acumUEFA >= acumAFC
				&& acumUEFA >= acumCAF && acumUEFA >= acumCONCACAF
				&& acumUEFA >= acumOFC) {

			printf("-UEFA con %d año/s\n", acumUEFA);

		}
		if (acumAFC >= acumCONMEBOL && acumAFC >= acumUEFA && acumAFC >= acumCAF
				&& acumAFC >= acumCONCACAF && acumAFC >= acumOFC) {

			printf("-AFC con %d año/s\n", acumAFC);

		}
		if (acumCAF >= acumCONMEBOL && acumCAF >= acumUEFA && acumCAF >= acumAFC
				&& acumCAF >= acumCONCACAF && acumCAF >= acumOFC) {

			printf("-CAF con %d año/s\n", acumCAF);

		}
		if (acumCONCACAF >= acumCONMEBOL && acumCONCACAF >= acumUEFA
				&& acumCONCACAF >= acumAFC && acumCONCACAF >= acumCAF
				&& acumCONCACAF >= acumOFC) {

			printf("-CONCACAF con %d año/s\n", acumCONCACAF);

		}
		if (acumOFC >= acumCONMEBOL && acumOFC >= acumUEFA && acumOFC >= acumAFC
				&& acumOFC >= acumCAF && acumOFC >= acumCONCACAF) {

			printf("-OFC con %d año/s\n", acumOFC);

		}

		rtn = 1;
	}

	return rtn;

}

int informes_porcentajeJugadoresPorConfederacion(eJugador *jugadores,
		int tamJugadores, eConfederacion *confederaciones,
		int tamConfederaciones) {

	int rtn = -1;
	float contCONMEBOL = 0;
	float contUEFA = 0;
	float contAFC = 0;
	float contCAF = 0;
	float contCONCACAF = 0;
	float contOFC = 0;
	float contJugadores = 0;
	int i;

	if (jugadores != NULL && tamJugadores > 0 && confederaciones != NULL
			&& tamConfederaciones > 0) {

		for (i = 0; i < tamJugadores; i++) {

			if ((*(jugadores + i)).estado == OCUPADO) {

				switch ((*(jugadores + i)).idConfederacion) {

				case 100:
					contCONMEBOL++;
					contJugadores++;
					break;
				case 101:
					contUEFA++;
					contJugadores++;
					break;
				case 102:
					contAFC++;
					contJugadores++;
					break;
				case 103:
					contCAF++;
					contJugadores++;
					break;
				case 104:
					contCONCACAF++;
					contJugadores++;
					break;
				case 105:
					contOFC++;
					contJugadores++;
					break;
				}
			}

		}

		contCONMEBOL *= 100 / contJugadores;
		contUEFA *= 100 / contJugadores;
		contAFC *= 100 / contJugadores;
		contCAF *= 100 / contJugadores;
		contCONCACAF *= 100 / contJugadores;
		contOFC *= 100 / contJugadores;

		printf("Porcentaje de jugadores CONMEBOL: %.2f\n", contCONMEBOL);
		printf("Porcentaje de jugadores UEFA: %.2f\n", contUEFA);
		printf("Porcentaje de jugadores AFC: %.2f\n", contAFC);
		printf("Porcentaje de jugadores CAF: %.2f\n", contCAF);
		printf("Porcentaje de jugadores CONCACAF: %.2f\n", contCONCACAF);
		printf("Porcentaje de jugadores OFC: %.2f\n", contOFC);

		rtn = 1;
	}

	return rtn;

}

int informes_regionMasJugadores(eJugador *jugadores, int tamJugadores,
		eConfederacion *confederaciones, int tamConfederaciones) {

	int rtn = -1;
	int contCONMEBOL = 0;
	int contUEFA = 0;
	int contAFC = 0;
	int contCAF = 0;
	int contCONCACAF = 0;
	int contOFC = 0;
	int i;
	int j;

	if (jugadores != NULL && tamJugadores > 0 && confederaciones != NULL
			&& tamConfederaciones > 0) {

		for (i = 0; i < tamJugadores; i++) {

			if ((*(jugadores + i)).estado == OCUPADO) {

				switch ((*(jugadores + i)).idConfederacion) {

				case 100:
					contCONMEBOL++;

					break;
				case 101:
					contUEFA++;

					break;
				case 102:
					contAFC++;

					break;
				case 103:
					contCAF++;

					break;
				case 104:
					contCONCACAF++;

					break;
				case 105:
					contOFC++;

					break;
				}
			}

		}

		printf("La/s region/es con mayor cantidad de jugadores es/son:\n\n");

		if (contCONMEBOL >= contUEFA && contCONMEBOL >= contAFC
				&& contCONMEBOL >= contCAF && contCONMEBOL >= contCONCACAF
				&& contCONMEBOL >= contOFC) {

			printf("-SUDAMERICA con %d jugador/es\n", contCONMEBOL);
			printf(

			"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE",
					"POSICION", "NUMERO DE CAMISETA", "CONFEDERACION",
					"SALARIO", "AÑOS DE CONTRATO");
			for (i = 0; i < tamConfederaciones; i++) {
				for (j = 0; j < tamJugadores; j++) {

					if ((*(jugadores + j)).estado == OCUPADO
							&& (*(confederaciones + i)).id
									== (*(jugadores + j)).idConfederacion
							&& (*(jugadores + j)).idConfederacion == 100) {

						jugador_mostrarUno(*(jugadores + j), confederaciones,
								tamConfederaciones);

						printf("\n");
					}
				}
			}

		}
		if (contUEFA >= contCONMEBOL && contUEFA >= contAFC
				&& contUEFA >= contCAF && contUEFA >= contCONCACAF
				&& contUEFA >= contOFC) {

			printf("-EUROPA con %d jugador/es\n", contUEFA);

			printf(

			"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE",
					"POSICION", "NUMERO DE CAMISETA", "CONFEDERACION",
					"SALARIO", "AÑOS DE CONTRATO");
			for (i = 0; i < tamConfederaciones; i++) {
				for (j = 0; j < tamJugadores; j++) {

					if ((*(jugadores + j)).estado == OCUPADO
							&& (*(confederaciones + i)).id
									== (*(jugadores + j)).idConfederacion
							&& (*(jugadores + j)).idConfederacion == 101) {

						jugador_mostrarUno(*(jugadores + j), confederaciones,
								tamConfederaciones);

						printf("\n");
					}
				}
			}

		}
		if (contAFC >= contCONMEBOL && contAFC >= contUEFA && contAFC >= contCAF
				&& contAFC >= contCONCACAF && contAFC >= contOFC) {

			printf("-ASIA con %d jugador/es\n", contAFC);
			printf(

			"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE",
					"POSICION", "NUMERO DE CAMISETA", "CONFEDERACION",
					"SALARIO", "AÑOS DE CONTRATO");
			for (i = 0; i < tamConfederaciones; i++) {
				for (j = 0; j < tamJugadores; j++) {

					if ((*(jugadores + j)).estado == OCUPADO
							&& (*(confederaciones + i)).id
									== (*(jugadores + j)).idConfederacion
							&& (*(jugadores + j)).idConfederacion == 102) {

						jugador_mostrarUno(*(jugadores + j), confederaciones,
								tamConfederaciones);

						printf("\n");
					}
				}
			}

		}
		if (contCAF >= contCONMEBOL && contCAF >= contUEFA && contCAF >= contAFC
				&& contCAF >= contCONCACAF && contCAF >= contOFC) {

			printf("-AFRICA con %d jugador/es\n", contCAF);
			printf(

			"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE",
					"POSICION", "NUMERO DE CAMISETA", "CONFEDERACION",
					"SALARIO", "AÑOS DE CONTRATO");
			for (i = 0; i < tamConfederaciones; i++) {
				for (j = 0; j < tamJugadores; j++) {

					if ((*(jugadores + j)).estado == OCUPADO
							&& (*(confederaciones + i)).id
									== (*(jugadores + j)).idConfederacion
							&& (*(jugadores + j)).idConfederacion == 103) {

						jugador_mostrarUno(*(jugadores + j), confederaciones,
								tamConfederaciones);

						printf("\n");
					}
				}
			}

		}
		if (contCONCACAF >= contCONMEBOL && contCONCACAF >= contUEFA
				&& contCONCACAF >= contAFC && contCONCACAF >= contCAF
				&& contCONCACAF >= contOFC) {

			printf("-NORTE Y CENTRO AMERICA con %d jugador/es\n", contCONCACAF);
			printf(

			"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE",
					"POSICION", "NUMERO DE CAMISETA", "CONFEDERACION",
					"SALARIO", "AÑOS DE CONTRATO");
			for (i = 0; i < tamConfederaciones; i++) {
				for (j = 0; j < tamJugadores; j++) {

					if ((*(jugadores + j)).estado == OCUPADO
							&& (*(confederaciones + i)).id
									== (*(jugadores + j)).idConfederacion
							&& (*(jugadores + j)).idConfederacion == 104) {

						jugador_mostrarUno(*(jugadores + j), confederaciones,
								tamConfederaciones);

						printf("\n");
					}
				}
			}

		}
		if (contOFC >= contCONMEBOL && contOFC >= contUEFA && contOFC >= contAFC
				&& contOFC >= contCAF && contOFC >= contCONCACAF) {

			printf("-OCEANIA con %d jugador/es\n", contOFC);
			printf(

			"\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "NOMBRE",
					"POSICION", "NUMERO DE CAMISETA", "CONFEDERACION",
					"SALARIO", "AÑOS DE CONTRATO");
			for (i = 0; i < tamConfederaciones; i++) {
				for (j = 0; j < tamJugadores; j++) {

					if ((*(jugadores + j)).estado == OCUPADO
							&& (*(confederaciones + i)).id
									== (*(jugadores + j)).idConfederacion
							&& (*(jugadores + j)).idConfederacion == 105) {

						jugador_mostrarUno(*(jugadores + j), confederaciones,
								tamConfederaciones);

						printf("\n");
					}
				}
			}

		}

		rtn = 1;
	}

	return rtn;

}
