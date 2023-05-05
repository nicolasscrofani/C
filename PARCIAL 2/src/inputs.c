#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

int getCharacter(char *_char, char *_msg) {
	if (_char != NULL && _msg != NULL) {
		printf("%s", _msg);
		fflush(stdin);
		*_char = getchar();
		return 0;
	}
	return -1;
}

int getInt(char *_msg, char *_errMsg, int _min, int _max) {
	int num;
	int resOperation;

	printf("%s", _msg);
	fflush(stdin);
	resOperation = scanf("%d", &num);

	while (resOperation != 1 || (num < _min || num > _max)) {
		printf("%s", _errMsg);
		fflush(stdin);
		resOperation = scanf("%d", &num);
	}
	return num;
}

int verify(char *_msg) {
	char ver;

	getCharacter(&ver, _msg);
	if (ver == 's' || ver == 'S') {
		return 0;
	}
	return -1;
}

void printLine(char *_msg) {
	printf(
			"\n----------------------------------------------------------------------%s----------------------------------------------------------------------\n",
			_msg);
}

int menuOpcionFiltrarPorOrigen() {
	printf("  				 *** Filtrar por origen ***\n\n");
	int opcion;
	printf("1) Administracion\n");
	printf("2) Taller\n");
	printf("3) Ventas\n");
	printf("4) Volver al menu\n");
	scanf("%d", &opcion);
	return opcion;
}
