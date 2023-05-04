#include "inputs.h"

int pedirEntero(int *entero, char *mensaje, char *mensajeError, int min,
		int max) {
	int retorno = -1;
	int numeroIngresado;

	if (entero != NULL && mensaje != NULL && mensajeError != NULL
			&& min < max) {
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while (numeroIngresado < min || numeroIngresado > max) {
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}

		*entero = numeroIngresado;
		retorno = 1;
	}

	return retorno;
}

int pedirFlotante(float *flotante, char *mensaje, char *mensajeError, float min,
		float max) {
	int retorno = -1;
	float numeroIngresado;

	if (flotante != NULL && mensaje != NULL && mensajeError != NULL
			&& min < max) {
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while (numeroIngresado < min || numeroIngresado > max) {
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotante = numeroIngresado;
		retorno = 1;
	}

	return retorno;
}

int pedirCaracter(char *caracter, char *mensaje) {
	int retorno = -1;

	if (caracter != NULL && mensaje != NULL) {
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 1;
	}

	return retorno;
}

int verificarConfirmacion(char *mensaje) {
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if (respuesta == 's' || respuesta == 'S') {
		retorno = 0;
	}

	return retorno;
}

void printLine() {
	printf(
			"\n--------------------------------------------------------------------------------------------------------------------------------------------\n");
}
