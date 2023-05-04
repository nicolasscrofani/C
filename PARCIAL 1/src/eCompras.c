#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eCompras.h"

eCompra* eCompra_new() {

	eCompra *pCompra = NULL;

	pCompra = (eCompra*) malloc(sizeof(eCompra));

	return pCompra;
}

eCompra* eCompra_newParametros(char *codigoCompraStr, char *descripcionStr,
		char *origenStr, char *precioUnitarioStr, char *cantidadStr,
		char *totalCompraStr) {

	eCompra *pCompra = NULL;
	pCompra = eCompra_new();

	if (pCompra != NULL && codigoCompraStr != NULL && descripcionStr != NULL
			&& origenStr != NULL && precioUnitarioStr != NULL
			&& cantidadStr != NULL && totalCompraStr != NULL) {

		eCompra_setCodigoCompra(pCompra, atoi(codigoCompraStr));
		eCompra_setDescripcion(pCompra, descripcionStr);
		eCompra_setOrigen(pCompra, atoi(origenStr));
		eCompra_setPrecioUnitario(pCompra, atof(precioUnitarioStr));
		eCompra_setCantidad(pCompra, atoi(cantidadStr));
		eCompra_setTotalCompra(pCompra, atof(totalCompraStr));
	}
	return pCompra;

}

void eCompra_delete(eCompra *this) {

	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

int eCompra_setCodigoCompra(eCompra *this, int codigoCompra) {

	if (this != NULL) {
		this->codigoCompra = codigoCompra;
		return 0;
	}
	return 1;

}

int eCompra_getCodigoCompra(eCompra *this, int *codigoCompra) {

	if (this != NULL && codigoCompra != NULL) {

		*codigoCompra = this->codigoCompra;
		return 0;
	}
	return 1;
}

int eCompra_setDescripcion(eCompra *this, char *descripcion) {

	if (this != NULL && descripcion != NULL) {

		strcpy(this->descripcion, descripcion);
		return 0;
	}
	return 1;
}

int eCompra_getDescripcion(eCompra *this, char *descripcion) {

	if (this != NULL && descripcion != NULL) {
		strcpy(descripcion, this->descripcion);
		return 0;
	}
	return 1;
}

int eCompra_setOrigen(eCompra *this, int origen) {

	if (this != NULL) {
		this->origen = origen;
		return 0;
	}
	return 1;

}

int eCompra_getOrigen(eCompra *this, int *origen) {

	if (this != NULL && origen != NULL) {

		*origen = this->origen;
		return 0;
	}
	return 1;
}

int eCompra_setPrecioUnitario(eCompra *this, float precioUnitario) {

	if (this != NULL) {
		this->precioUnitario = precioUnitario;
		return 0;
	}
	return 1;

}

int eCompra_getPrecioUnitario(eCompra *this, float *precioUnitario) {

	if (this != NULL && precioUnitario != NULL) {

		*precioUnitario = this->precioUnitario;
		return 0;
	}
	return 1;
}

int eCompra_setCantidad(eCompra *this, int cantidad) {

	if (this != NULL) {
		this->cantidad = cantidad;
		return 0;
	}
	return 1;

}

int eCompra_getCantidad(eCompra *this, int *cantidad) {

	if (this != NULL && cantidad != NULL) {

		*cantidad = this->cantidad;
		return 0;
	}
	return 1;
}

int eCompra_setTotalCompra(eCompra *this, float totalCompra) {

	if (this != NULL) {
		this->totalCompra = totalCompra;
		return 0;
	}
	return 1;

}

int eCompra_getTotalCompra(eCompra *this, float *totalCompra) {

	if (this != NULL && totalCompra != NULL) {

		*totalCompra = this->totalCompra;
		return 0;
	}
	return 1;
}

void eCompra_listarUna(eCompra *this) {

	int codigoCompra;
	char descripcion[100];
	int origen;
	float precioUnitario;
	int cantidad;
	float totalCompra;

	if (this != NULL) {

		eCompra_getCodigoCompra(this, &codigoCompra);
		eCompra_getDescripcion(this, descripcion);
		eCompra_getOrigen(this, &origen);
		eCompra_getPrecioUnitario(this, &precioUnitario);
		eCompra_getCantidad(this, &cantidad);
		eCompra_getTotalCompra(this, &totalCompra);

		printf("%-30d %-30s %-30d %-30.2f  %-30d  %-30.2f\n", codigoCompra,
				descripcion, origen, precioUnitario, cantidad, totalCompra);
	}

}

void eCompra_totalCompra(void *this) {

	int auxCantidad;
	float auxPrecioUnitario;

	eCompra_getCantidad(this, &auxCantidad);
	eCompra_getPrecioUnitario(this, &auxPrecioUnitario);
	eCompra_setTotalCompra(this, (auxCantidad * auxPrecioUnitario));
}

int eCompra_filtroAdministracion(void *elemento) {

	int retorno = 0;
	eCompra *aux = NULL;

	aux = (eCompra*) elemento;

	if (aux != NULL) {

		if (aux->origen == ADMINISTRACION) {
			retorno = 1;
		}
	}
	return retorno;
}

int eCompra_filtroTaller(void *elemento) {

	int retorno = 0;
	eCompra *aux = NULL;

	aux = (eCompra*) elemento;

	if (aux != NULL) {

		if (aux->origen == TALLER) {
			retorno = 1;
		}
	}
	return retorno;
}

int eCompra_filtroVentas(void *elemento) {

	int retorno = 0;
	eCompra *aux = NULL;

	aux = (eCompra*) elemento;

	if (aux != NULL) {

		if (aux->origen == VENTAS) {
			retorno = 1;
		}
	}
	return retorno;
}


int eCompra_compareDescription(void *a, void *b) {

	int retorno = -1;
	char A[50];
	char B[50];

	if (a != NULL && b != NULL) {

		strcpy(A, ((eCompra*) a)->descripcion);
		strcpy(B, ((eCompra*) b)->descripcion);
		retorno = strcmp(A, B);
	}
	return retorno;
}
