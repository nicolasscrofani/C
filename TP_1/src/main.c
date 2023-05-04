#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	int opcionCostoMenu;
	int posicionJugador;
	int totalConfe;
	float costoDelAumento;
	float costoMasAumento;

	//costos
	float costoMantenimiento = 0;
	float costoTransporte = 0;
	float costoHospedaje = 0;
	float costoComida = 0;

	//contadortes posiciones
	int cantArqueros = 0;
	int cantDefensores = 0;
	int cantDelanteros = 0;
	int cantMediocampistas = 0;

	//contadores confederaciones
	int contUEFA = 0;
	int contCONMEBOL = 0;
	int contCONCACAF = 0;
	int contAFC = 0;
	int contOFC = 0;
	int contCAF = 0;

	//promedios
	float promedioUEFA = 0;
	float promedioCONMEBOL = 0;
	float promedioCONCACAF = 0;
	float promedioAFC = 0;
	float promedioOFC = 0;
	float promedioCAF = 0;

	//flags
	int flagJugadores = 0;
	int flagCostos = 0;
	int flagCalculos = 0;
	int flagInformes = 0;

	do {
		printLine();
		menuPrincipal(costoHospedaje, costoComida, costoTransporte,
				cantArqueros, cantDefensores, cantMediocampistas,
				cantDelanteros);
		printLine();
		pedirEntero(&opcionMenu, "Ingrese una opcion: ",
				"Opcion invalida. reingrese: \n", 1, 5);

		switch (opcionMenu) {
		case 1:

			pedirEntero(&opcionCostoMenu,
					"\n1-Costo de Hospedaje.\n2-Costo de comida.\n3-Costo de transporte.\n4-Salir\n",
					"Error. reingrese(1-4)\n", 1, 4);

			if (!guardarCostos(opcionCostoMenu, &costoHospedaje, &costoComida,
					&costoTransporte)) {

				printf("\nCosto guardado correctamente.\n");

			} else {
				printf("El costo no se pudo cargar, vuelva a intentarlo.\n");
			}

			if (costoComida != 0 && costoHospedaje != 0
					&& costoTransporte != 0) {
				flagCostos = 1;
			}

			system("pause");
			break;

		case 2:

			pedirEntero(&posicionJugador,
					"\nElija la posicion del jugador:\n1-Arquero.\n2-Defensor.\n3-Mediocampista.\n4-Delantero.\n5-Salir.\n",
					"Posicion inexistente. Reingrese(1-5): \n", 1, 5);
			switch (posicionJugador) {
			case 1:
				if (cantArqueros < MAXIMOARQUEROS
						&& cargarUnJugador(&contUEFA, &contCONMEBOL,
								&contCONCACAF, &contAFC, &contOFC, &contCAF)
								== 0) {
					cantArqueros++;
					flagJugadores = 1;
					printf("Jugador guardado correctamente.\n");
				} else {
					printf(
							"No puede cargar mas jugadores en esa posicion o se alcanzo el maximo(22).\n");
				}
				system("pause");
				break;
			case 2:
				if (cantDefensores < MAXIMODEFENSORES
						&& cargarUnJugador(&contUEFA, &contCONMEBOL,
								&contCONCACAF, &contAFC, &contOFC, &contCAF)
								== 0) {
					cantDefensores++;
					flagJugadores = 1;
					printf("Jugador guardado correctamente.\n");
				} else {
					printf(
							"No puede cargar mas jugadores en esa posicion o se alcanzo el maximo(22).\n");
				}
				break;
			case 3:
				if (cantMediocampistas < MAXIMOMEDIOCAMPISTAS
						&& cargarUnJugador(&contUEFA, &contCONMEBOL,
								&contCONCACAF, &contAFC, &contOFC, &contCAF)
								== 0) {
					cantMediocampistas++;
					flagJugadores = 1;
					printf("Jugador guardado correctamente.\n");
				} else {
					printf(
							"No puede cargar mas jugadores en esa posicion o se alcanzo el maximo(22).\n");
				}
				break;
			case 4:
				if (cantDelanteros < MAXIMODELANTEROS
						&& cargarUnJugador(&contUEFA, &contCONMEBOL,
								&contCONCACAF, &contAFC, &contOFC, &contCAF)
								== 0) {
					cantDelanteros++;
					flagJugadores = 1;
					printf("Jugador guardado correctamente.\n");
				} else {
					printf(
							"No puede cargar mas jugadores en esa posicion o se alcanzo el maximo(22).\n");
				}
				break;
			}

			system("pause");
			break;

		case 3:
			if (flagCostos == 1 && flagJugadores == 1) {

				costoMasAumento = 0;
				costoDelAumento = 0;

				totalJugadoresDeConfederaciones(contUEFA, contCONMEBOL,
						contCONCACAF, contAFC, contOFC, contCAF, &totalConfe);

				calcularPromedio(contUEFA, totalConfe, &promedioUEFA);
				calcularPromedio(contCONMEBOL, totalConfe, &promedioCONMEBOL);
				calcularPromedio(contCONCACAF, totalConfe, &promedioCONCACAF);
				calcularPromedio(contAFC, totalConfe, &promedioAFC);
				calcularPromedio(contOFC, totalConfe, &promedioOFC);
				calcularPromedio(contCAF, totalConfe, &promedioCAF);

				costoTotalMantenimiento(costoHospedaje, costoComida,
						costoTransporte, &costoMantenimiento);

				mayorPromedio(promedioUEFA, promedioCONMEBOL, promedioCONCACAF,
						promedioAFC, promedioOFC, promedioCAF, &costoMasAumento,
						&costoMantenimiento, &costoDelAumento);

				printf("\nCostos calculados correctamente. \n");
				flagCalculos = 1;
				flagInformes = 0;
			} else {
				if (flagCostos == 1) {
					printf(
							"Debe cargar al menos un jugador (Opcion 2) para poder realizar los calculos.\n");
				} else {
					printf(
							"Debe terminar de realizar la carga de costos de Mantenimiento (Opcion 1) para realizar los calculos.\n ");
				}
			}

			system("pause");
			break;
		case 4:
			if (flagCalculos == 1) {

				if (flagInformes == 0) {

					imprimirResultados(promedioUEFA, promedioCONMEBOL,
							promedioCONCACAF, promedioAFC, promedioOFC,
							promedioCAF, costoMantenimiento, costoMasAumento,
							costoDelAumento);
					flagInformes = 1;

				} else {

					printf(
							"Usted agregó datos. Vuelva a realizar las cuentas(opcion 3)\n");
				}
			} else {
				printf(
						"Debe realizar los calculos (Opcion 3) antes de poder imprimir los resultados.\n");
			}
			system("pause");
			break;

		case 5:

			if (verificarConfirmacion("Seguro que desea salir? Ingrese 's': ")
					== 0) {
				printf("PROGRAMA FINALIZADO.\n");

			} else {
				opcionMenu = 0;

			}

			break;
		}

	} while (opcionMenu != 5);

	return EXIT_SUCCESS;
}
