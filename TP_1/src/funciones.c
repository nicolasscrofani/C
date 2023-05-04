#include "funciones.h"

void menuPrincipal(float costoHospedaje, float costoComida,
		float costoTransporte, int arqueros, int defensores, int mediocampistas,
		int delanteros) {

	printf("\n\t\tMenu Principal\n\n");
	printf("1. Ingreso de los costos de Mantenimiento. \n");
	printf("\tCosto de Hospedaje-->$%.2f\n", costoHospedaje);
	printf("\tCosto de Comida-->$%.2f\n", costoComida);
	printf("\tCosto de Transporte-->$%.2f\n", costoTransporte);
	printf("\n2. Carga de jugadores: \n");
	printf("\tArqueros-->%d\n", arqueros);
	printf("\tDefensores-->%d\n", defensores);
	printf("\tMediocampistas-->%d\n", mediocampistas);
	printf("\tDelanteros-->%d\n", delanteros);
	printf("\n3. Realizar todos los cálculos. \n");
	printf("\n4. Informar todos los resultados. \n");
	printf("\n5. Salir. \n\n");
}

void imprimirResultados(float uefa, float conmebol, float concacaf, float afc,
		float ofc, float caf, float costo, float aumento, float costoTotal) {

	printf("\n\t\tInformar todos los Resultados.\n\n");
	printf("Promedio UEFA %.2f\n", uefa);
	printf("Promedio CONMEBOL %.2f\n", conmebol);
	printf("Promedio CONCACAF %.2f\n", concacaf);
	printf("Promedio AFC %.2f\n", afc); //
	printf("Promedio OFC %.2f\n", ofc);
	printf("Promedio CAF %.2f\n\n", caf);

	if (aumento == 0) {
		printf(
				"El costo de mantenimiento total es de %.2f, no se recibieron aumentos\n",
				costo);
	} else {
		printf(
				"El costo de mantenimientos era de %.2f y recibio un aumento de %.2f , su nuevo valor es de: %.2f \n",
				costo, aumento, costoTotal);
	}
}

int cargarUnJugador(int *confeUefa, int *confeConmebol, int *confeConcacaf,
		int *confeAfc, int *confeOfc, int *confeCaf) {

	int rtn = -1;
	int camisetaJugador;
	int confederacionJugador;

	if (confeUefa != NULL && confeConmebol != NULL && confeConcacaf != NULL
			&& confeAfc != NULL && confeOfc != NULL && confeCaf != NULL) {

		pedirEntero(&camisetaJugador, "Ingrese numero de camiseta(1-99): \n",
				"Error. Reingrese(1-99): \n", 1, 99);

		pedirEntero(&confederacionJugador,
				"Ingrese confederacion(1-6): \n1- UEFA.\n2- CONMEBOL.\n3- CONCACAF.\n4- AFC.\n5- OFC.\n6- CAF.\n",
				"Error reingrese(1-6): \n", 1, 6);

		guardarConfederacionContar(&confederacionJugador, confeUefa,
				confeConmebol, confeConcacaf, confeAfc, confeOfc, confeCaf);
		rtn = 0;
	}
	return rtn;
}

int guardarConfederacionContar(int *confederacion, int *confeUefa,
		int *confeConmebol, int *confeConcacaf, int *confeAfc, int *confeOfc,
		int *confeCaf) {

	int rtn = -1;
	if (confederacion != NULL && confeUefa != NULL && confeConmebol != NULL
			&& confeConcacaf != NULL && confeAfc != NULL && confeOfc != NULL
			&& confeCaf != NULL) {

		switch (*confederacion) {
		case 1:
			(*confeUefa)++;
			break;
		case 2:
			(*confeConmebol)++;
			break;
		case 3:
			(*confeConcacaf)++;
			break;
		case 4:
			(*confeAfc)++;
			break;
		case 5:
			(*confeOfc)++;
			break;
		case 6:
			(*confeCaf)++;
			break;
		}

		rtn = 0;
	}

	return rtn;

}
int guardarCostos(int opcionCostoMenu, float *costoHospedaje,
		float *costoComida, float *costoTransporte) {

	int rtn = -1;

	if (costoHospedaje != NULL && costoComida != NULL && costoTransporte != NULL) {

		switch (opcionCostoMenu) {
		case 1:
			pedirFlotante(costoHospedaje,
					"\nIngrese el costo del hospedaje(1-1000000):  ",
					"Error, reingrese(1-1000000): \n", 1, 1000000);

			break;
		case 2:
			pedirFlotante(costoComida,
					"\nIngrese el costo de la comida(1-1000000):  ",
					"Error, reingrese(1-1000000): \n", 1, 1000000);

			break;
		case 3:
			pedirFlotante(costoTransporte,
					"\nIngrese el costo del transporte(1-1000000):  ",
					"Error, reingrese(1-1000000): \n", 1, 1000000);

			break;
		}

		rtn = 0;
	}
	return rtn;
}

int calcularPromedio(int num1, int num2, float *promedio) {

	int rtn = -1;

	if (promedio != NULL && num2 != 0) {

		*promedio = (float) num1 / num2;

		rtn = 0;

	} else {

		printf("no se puede dividir por 0");
	}

	return rtn;
}

int calcularAumento(float *costoConAumento, float *costo,
		float *costoDelAumento, float aumento) {

	int rtn = -1;

	if (costoDelAumento != NULL) {

		*costoConAumento = *costo * aumento;
		*costoDelAumento = *costoConAumento + *costo;

		rtn = 0;
	}

	return rtn;
}

int totalJugadoresDeConfederaciones(int contUEFA, int contCONMEBOL,
		int contCONCACAF, int contAFC, int contOFC, int contCAF, int *total) {

	int rtn = -1;

	if (total != NULL) {

		*total = contUEFA + contCONMEBOL + contCONCACAF + contAFC + contOFC
				+ contCAF;

		rtn = 1;
	}

	return rtn;
}

int costoTotalMantenimiento(float costo1, float costo2, float costo3,
		float *costoTotal) {

	int rtn = -1;

	if (costoTotal != NULL) {

		*costoTotal = costo1 + costo2 + costo3;

		rtn = 1;
	}

	return rtn;
}

int mayorPromedio(float promedioUEFA, float promedioCONMEBOL,
		float promedioCONCACAF, float promedioAFC, float promedioOFC,
		float promedioCAF, float *costoMasAumento, float *costoMantenimiento,
		float *costoDelAumento) {

	int rtn = -1;

	if (promedioUEFA > promedioCONMEBOL && promedioUEFA > promedioCONCACAF
			&& promedioUEFA > promedioAFC && promedioUEFA > promedioOFC
			&& promedioUEFA > promedioCAF) {

		calcularAumento(costoMasAumento, costoMantenimiento, costoDelAumento,
				0.35);

		rtn = 1;
	}

	return rtn;
}
