#include "inputs.h"

int pedirEntero(int *entero, char *mensaje, char *mensajeError, int min, int max) {
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

int validarFlotante(char* caracter){
	int countSigno = 0;
	int rtn = 1;

	if(strlen(caracter) > 0){
		for(int i = 0; i < strlen(caracter); i++){

			if(caracter[i] == '.'|| caracter[i] == ','){
				countSigno++;
			}
			else{
				if(isdigit(caracter[i]) == 0){
					rtn = 0;
					break;
				}
			}
		}

		if(countSigno > 1){
			rtn = 0;
		}
	}else{
		rtn = 0;
	}

	return rtn;
}


float pedirFlotante(float *flotante, char *mensaje, char *mensajeError, float min, float max) {
	int retorno = -1;
	char numeroIngresado[51];
	float numFloatAux;

	if (flotante != NULL && mensaje != NULL && mensajeError != NULL
			&& min < max) {
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]",numeroIngresado);
		numFloatAux=atof(numeroIngresado);

		while (validarFlotante(numeroIngresado) == 0 ||(numFloatAux < min || numFloatAux > max)) {
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]",numeroIngresado);
			numFloatAux=atof(numeroIngresado);
		}

		*flotante = atof(numeroIngresado);
		retorno = 1;
	}

	return retorno;
}

int pedirCadena(char *cadena, char *mensaje, char *mensajeError, int max) {
	int retorno = -1;
	char buffer[256];
	int tam;

	if (cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0) {
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam = strlen(buffer);

		while (tam > max) {
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
		}

		strcpy(cadena, buffer);
		retorno = 1;
	}

	return retorno;
}

int validarLetra(char *letra) {

	int rtn = -1;

	if (letra != NULL && strlen(letra) > 0) {
		for (int i = 0; i < strlen(letra); i++) {
			if (isalpha(*(letra+i)) == 0) {
				rtn = 1;
				break;
			}
		}
	}

	return rtn;
}

int pedirCadenaAlfabetica(char *cadena, char *mensaje, char *mensajeError, int max) {
	char buffer[11];
	int rtn = -1;

	if (cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0) {
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);

		while (strlen(buffer) > max || strlen(buffer) == 0
				|| validarLetra(buffer) == 1) {

			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
		}

		strcpy(cadena, buffer);

		rtn = 1;
	}
	return rtn;
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
	int rtn = -1;
	char respuesta;

	if (mensaje != NULL) {
		pedirCaracter(&respuesta, mensaje);
		if (respuesta == 's' || respuesta == 'S') {

			rtn = 0;
		}

	}
	return rtn;
}
