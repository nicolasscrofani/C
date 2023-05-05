#ifndef ECOMPRAS_H_
#define ECOMPRAS_H_

#include "LinkedList.h"

#define ADMINISTRACION 1
#define TALLER 2
#define VENTAS 3

typedef struct {
	int codigoCompra;
	char descripcion[100];
	int origen;
	float precioUnitario;
	int cantidad;
	float totalCompra;

} eCompra;

eCompra* eCompra_new();

eCompra* eCompra_newParametros(char *codigoCompraStr, char *descripcionStr,
		char *origenStr, char *precioUnitarioStr, char *cantidadStr,
		char *totalCompraStr);

void eCompra_delete(eCompra *this);

int eCompra_setCodigoCompra(eCompra *this, int codigoCompra);
int eCompra_getCodigoCompra(eCompra *this, int *codigoCompra);

int eCompra_setDescripcion(eCompra *this, char *descripcion);
int eCompra_getDescripcion(eCompra *this, char *descripcion);

int eCompra_setOrigen(eCompra *this, int origen);
int eCompra_getOrigen(eCompra *this, int *origen);

int eCompra_setPrecioUnitario(eCompra *this, float precioUnitario);
int eCompra_getPrecioUnitario(eCompra *this, float *precioUnitario);

int eCompra_setCantidad(eCompra *this, int cantidad);
int eCompra_getCantidad(eCompra *this, int *cantidad);

int eCompra_setTotalCompra(eCompra *this, float totalCompra);
int eCompra_getTotalCompra(eCompra *this, float *totalCompra);

void eCompra_listarUna(eCompra *this);
void eCompra_totalCompra(void *this);
int eCompra_filtroAdministracion(void *elemento);
int eCompra_filtroTaller(void *elemento);
int eCompra_filtroVentas(void *elemento);
int eCompra_compareDescription(void *a, void *b);
#endif /* ECOMPRAS_H_ */
